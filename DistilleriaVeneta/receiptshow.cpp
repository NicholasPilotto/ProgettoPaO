#include "receiptshow.h"
#include "controller.h"

QReceiptShow::QReceiptShow(QWidget* parent) : QWidget(parent) {
  QVBoxLayout* table_layout = new QVBoxLayout();
  addTable(table_layout);
  setLayout(table_layout);
}

void QReceiptShow::setpresenter(controller * c)
{
    presenter = c;
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
  table->selectionModel()->selectedRows();

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
  tablerow* new_line = new tablerow(this);
  new_line->set_row((*cit).first, (*cit).second, table, i);

    refresh_totale += (*cit).first->get_price()*(*cit).second;
    refresh_tasse += (*cit).first->taxes()*(*cit).second;
  }

  connect(table->verticalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(remove_row(int))); // così con hiderow va bene, con remove row NON SI ELIMINA NEL VETTORE E POI RICOMPAINO (GIUSTAMENTE)
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
    prezzo_finale = new QLabel("€ -.--");
    resoconto->addWidget(prezzo_finale, 0, 1, 1, 1, Qt::AlignRight);
    resoconto->addWidget(new QLabel("Tasse:"), 1, 0, 1, 1, Qt::AlignLeft);
    tasse_finale = new QLabel("€ -.--");
    resoconto->addWidget(tasse_finale, 1, 1, 1, 1, Qt::AlignRight);

    resoconto->setContentsMargins(10,10,10,10);

    return resoconto;
}

void QReceiptShow::remove_row(int i)
{
//    std::cout << i << std::endl;
    auto s = table->selectedRanges().first();
    int a = s.topRow() + s.bottomRow() - 1;
    for(; a > s.topRow() - 1; a--) {
        qDebug() << a;
       table->removeRow(a);
    }
    std::cout << "a" << std::endl;
    presenter->remove_row(a);
    //table->selectionModel()->clearCurrentIndex();
    //refreshTable(presenter->get_receipt());
}
