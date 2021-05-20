#include "receiptshow.h"

QReceiptShow::QReceiptShow(QWidget* parent) : QWidget(parent) {
  QVBoxLayout* table_layout = new QVBoxLayout();
  addTable(table_layout);
  setLayout(table_layout);
}

void QReceiptShow::addTable(QVBoxLayout* table_layout) {
  table = new QTableWidget(this);
  table->setMinimumSize(500, 500);
  table->setColumnCount(4);

  // Inizializzazione Horizontal Headers

  QStringList names_columns;
  names_columns << "Nome Prodotto"
                << "Dimensione"
                << "Quantità"
                << "Prezzo";

  table->setHorizontalHeaderLabels(names_columns);

  table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

  // Non rende visibile una selezione
  // Momentaneamente disabilitati
  // table->setEditTriggers(QAbstractItemView::NoEditTriggers);
  // table->setFocusPolicy(Qt::NoFocus);
  // table->setSelectionMode(QAbstractItemView::NoSelection);

  table_layout->addWidget(table);
  table_layout->addLayout(add_total());
}

void QReceiptShow::refreshTable(const u_vector<std::pair<deep_ptr<product>, int>>& _products) {
  // Inserimento prodotti

  int rows = _products.size();

  table->setRowCount(rows);

  auto cit = _products.const_begin();
  auto end = _products.const_end();

  for (int i = 0; cit != end; cit++, i++) {
    table->setRowHeight(i, 50);

    // Inserimento icona cestino

    const QIcon* icon = new QIcon("../Grafica/Immagini/delete.png");
    QTableWidgetItem* bin_item = new QTableWidgetItem(*icon, "");
    table->setVerticalHeaderItem(i, bin_item);

    // Inserimento nome

    QTableWidgetItem* name_item = new QTableWidgetItem();
    name_item->setText((*cit).first->get_name().data());
    name_item->setTextAlignment(Qt::AlignCenter);
    table->setItem(i, 0, name_item);

    // Inserimento grandezza bottiglia

    QTableWidgetItem* dim_item = new QTableWidgetItem();
    // TODO: questa cosa fa abbastanza schifo e non funziona, da rivedere
    dim_item->setText(QString::fromStdString((*cit).first->fromKindToStdString((*cit).first->get_kind())));
    dim_item->setTextAlignment(Qt::AlignCenter);
    table->setItem(i, 1, dim_item);

    // Inserimento SpinBox

    QSpinBox* num_item = new QSpinBox();
    num_item->setRange(1, 2147483647);
    table->setCellWidget(i, 2, num_item);

    // Inserimento totale per linea

    QTableWidgetItem* price_item = new QTableWidgetItem();
    price_item->setText(QString::number((*cit).first->get_price()*(*cit).second, 'f', 2) + " €");
    price_item->setTextAlignment(Qt::AlignCenter);
    table->setItem(i, 3, price_item);

    refresh_totale += (*cit).first->get_price()*(*cit).second;
    refresh_tasse += (*cit).first->taxes()*(*cit).second;
  }

  table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

  // Non rende visibile una selezione

  // table->setEditTriggers(QAbstractItemView::NoEditTriggers);
  // table->setFocusPolicy(Qt::NoFocus);
  // table->setSelectionMode(QAbstractItemView::NoSelection);
  // table->setStyleSheet("gridline-color: white");  // rende bianche le linee poi gli oggetti che inseriamo mettiamo i bordi alti e bassi così da avere solo linee
}

QGridLayout* QReceiptShow::add_total() {
    resoconto = new QGridLayout();

    resoconto->addWidget(new QLabel("TOTALE:"), 0, 0, 1, 1, Qt::AlignLeft);
    prezzo_totale = new QLabel("€ -.--");
    resoconto->addWidget(prezzo_totale, 0, 1, 1, 1, Qt::AlignRight);
    resoconto->addWidget(new QLabel("Tasse:"), 1, 0, 1, 1, Qt::AlignLeft);
    tasse_totale = new QLabel("€ -.--");
    resoconto->addWidget(tasse_totale, 1, 1, 1, 1, Qt::AlignRight);

    resoconto->setContentsMargins(10,10,10,10);

    return resoconto;
}
