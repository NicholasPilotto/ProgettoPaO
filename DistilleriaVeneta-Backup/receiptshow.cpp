#include "receiptshow.h"

#include <QDebug>

receiptshow::receiptshow(const u_vector<std::pair<deep_ptr<product>, int>>& _products, QWidget* parent) : QWidget(parent) {
  QVBoxLayout* table_layout = new QVBoxLayout();
  addTable(table_layout);
  refreshTable(_products);

  setLayout(table_layout);
}

receiptshow::~receiptshow() { delete table; }

void receiptshow::addTable(QVBoxLayout* table_layout) {
  table = new QTableWidget(this);
  table->setMinimumSize(500, 500);
  table->setColumnCount(4);

  QStringList names_columns;
  names_columns << "Nome Prodotto"
                << "Dimensione"
                << "Quantità"
                << "Prezzo";

  table->setHorizontalHeaderLabels(names_columns);

  table_layout->addWidget(table);
}

void receiptshow::refreshTable(const u_vector<std::pair<deep_ptr<product>, int>>& _products) {
  int rows = _products.size();

  table->setRowCount(rows);

  auto cit = _products.const_begin();
  auto end = _products.const_end();

  for (int i = 0; cit != end; cit++, i++) {
    table->setRowHeight(i, 50);

    const QIcon* icon = new QIcon("../Grafica/Immagini/delete.png");
    QTableWidgetItem* bin_item = new QTableWidgetItem(*icon, "");
    table->setVerticalHeaderItem(i, bin_item);

    QTableWidgetItem* name_item = new QTableWidgetItem();
    name_item->setText((*cit).first->get_name().data());
    name_item->setTextAlignment(Qt::AlignCenter);
    table->setItem(i, 0, name_item);

    QTableWidgetItem* dim_item = new QTableWidgetItem();
    dim_item->setText((*cit).first->get_name().data());
    dim_item->setTextAlignment(Qt::AlignCenter);
    table->setItem(i, 1, dim_item);

    QTableWidgetItem* num_item = new QTableWidgetItem();
    num_item->setText((*cit).first->get_name().data());
    num_item->setTextAlignment(Qt::AlignCenter);
    table->setItem(i, 2, num_item);

    QTableWidgetItem* price_item = new QTableWidgetItem();
    price_item->setText((*cit).first->get_name().data());
    price_item->setTextAlignment(Qt::AlignCenter);
    table->setItem(i, 3, price_item);
  }

  // Cestini

  table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  // Non rende visibile una selezione

  table->setEditTriggers(QAbstractItemView::NoEditTriggers);
  table->setFocusPolicy(Qt::NoFocus);
  table->setSelectionMode(QAbstractItemView::NoSelection);
  // table->setStyleSheet("gridline-color: white");  // rende bianche le linee poi gli oggetti che inseriamo mettiamo i bordi alti e bassi così da avere solo linee
}
