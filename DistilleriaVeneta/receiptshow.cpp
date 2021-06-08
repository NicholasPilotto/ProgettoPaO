#include "receiptshow.h"

#include "controller.h"

QReceiptShow::QReceiptShow(QWidget* parent) : QWidget(parent) {
  QVBoxLayout* table_layout = new QVBoxLayout(this);
  addTable(table_layout);
  setLayout(table_layout);
}

void QReceiptShow::setpresenter(controller* c) { presenter = c; }

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
  table->setEditTriggers(QAbstractItemView::NoEditTriggers);
  table->setFocusPolicy(Qt::NoFocus);

  table_layout->addWidget(table);

  elimina_prodotto = new QPushButton("Elimina Prodotto", table);
  table_layout->addWidget(elimina_prodotto);
  connect(elimina_prodotto, SIGNAL(clicked()), this, SLOT(EliminaButtonSlot()));

  table_layout->addLayout(add_total());
}

void QReceiptShow::refreshTable(const u_vector<std::pair<deep_ptr<product>, int>>& _products) {
  // Inserimento prodotti
  int rows = _products.size();

  table->setRowCount(rows);

  auto cit = _products.const_begin();
  auto end = _products.const_end();

  for (int i = rows - 1; cit != end; cit++, i--) {
    tablerow* new_line = new tablerow(table);
    new_line->set_row((*cit).first, (*cit).second, i);
    list_spin.append(new_line->get_spin());
    connect(new_line->get_spin(), SIGNAL(valueChanged(int)), this, SLOT(refresh_spinbox(int)));
  }
  refresh_totali();

  table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  // Non rende visibile una selezione

  table->setEditTriggers(QAbstractItemView::NoEditTriggers);
  table->setFocusPolicy(Qt::NoFocus);
  //   table->setSelectionMode(QAbstractItemView::NoSelection);
  // table->setStyleSheet("gridline-color: white");  // rende bianche le linee poi gli oggetti che inseriamo mettiamo i bordi alti e bassi così da avere solo linee
}

QGridLayout* QReceiptShow::add_total() {
  resoconto = new QGridLayout(this);

  resoconto->addWidget(new QLabel("TOTALE:"), 0, 0, 1, 1, Qt::AlignLeft);
  prezzo_finale = new QLabel("€ 0.00");
  resoconto->addWidget(prezzo_finale, 0, 1, 1, 1, Qt::AlignRight);
  resoconto->addWidget(new QLabel("Tasse:"), 1, 0, 1, 1, Qt::AlignLeft);
  tasse_finale = new QLabel("€ 0.00");
  resoconto->addWidget(tasse_finale, 1, 1, 1, 1, Qt::AlignRight);
  resoconto->addWidget(new QLabel("Numero di prodotti:"), 2, 0, 1, 1, Qt::AlignLeft);
  n_items = new QLabel("0");
  resoconto->addWidget(n_items, 2, 1, 1, 1, Qt::AlignRight);

  resoconto->setContentsMargins(10, 10, 10, 10);

  return resoconto;
}

void QReceiptShow::refresh_totali() {
  delete prezzo_finale;
  prezzo_finale = new QLabel("€ " + QString::number(presenter->total_price(), 'f', 2));
  resoconto->addWidget(prezzo_finale, 0, 1, 1, 1, Qt::AlignRight);
  delete tasse_finale;
  tasse_finale = new QLabel("€ " + QString::number(presenter->total_taxes(), 'f', 2));
  resoconto->addWidget(tasse_finale, 1, 1, 1, 1, Qt::AlignRight);
  delete n_items;
  n_items = new QLabel(QString::number(presenter->total_number_items()));
  resoconto->addWidget(n_items, 2, 1, 1, 1, Qt::AlignRight);
}

void QReceiptShow::elimina_prodotto_dialog() {
  QMessageBox* dialog = new QMessageBox();
  if (table->rowCount() > 0) {
    if (table->currentRow() + 1 > 0) {
      dialog->setIcon(QMessageBox::Warning);
      dialog->setText("Sei sicuro di voler eliminare questo prodotto?");
      QPushButton* SiButton = new QPushButton("Si", dialog);
      QPushButton* NoButton = new QPushButton("No", dialog);
      dialog->addButton(SiButton, QMessageBox::YesRole);
      connect(SiButton, SIGNAL(pressed()), this, SLOT(CancellaProdottoSlot()));
      dialog->addButton(NoButton, QMessageBox::NoRole);
    } else {
      dialog->setText("Non hai selezionato nessun prodotto da eliminare!");
      dialog->setIcon(QMessageBox::Information);
    }
  } else {
    dialog->setIcon(QMessageBox::Information);
    dialog->setText("Nessun prodotto presente\n           nel carrello!");
  }
  dialog->show();
}

void QReceiptShow::EliminaButtonSlot() { elimina_prodotto_dialog(); }

void QReceiptShow::CancellaProdottoSlot() {
  QTableWidgetItem* item_name = table->item(table->currentRow(), 0);
  QTableWidgetItem* item_dim = table->item(table->currentRow(), 1);
  presenter->remove_item(item_name->text().toStdString(), item_dim->text().toStdString());
  refreshTable(presenter->get_receipt());
}

void QReceiptShow::refresh_spinbox(int v) {
  QTableWidgetItem* item_name = table->item(qobject_cast<QSpinBox*>(sender())->objectName().toInt(), 0);
  QTableWidgetItem* item_dim = table->item(qobject_cast<QSpinBox*>(sender())->objectName().toInt(), 1);
  presenter->refresh_quantity(item_name->text().toStdString(), item_dim->text().toStdString(), v);
  refreshTable(presenter->get_receipt());
}
