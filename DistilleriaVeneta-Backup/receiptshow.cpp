#include "receiptshow.h"

receiptshow::receiptshow(QWidget* parent) : QWidget(parent)
{
    addTable();
}

void receiptshow::addTable() {
  table_layout = new QVBoxLayout();
  table = new QTableWidget(this);
  table->setMinimumSize(500,500);
  table->setColumnCount(4);
  QStringList names_columns;
  names_columns << "Nome Prodotto"
                << "Dimensione"
                << "Quantità"
                << "Prezzo";
  table->setHorizontalHeaderLabels(names_columns);
  table->setRowCount(4);

  for(int i=0; i<4; i++)
  table->setRowHeight(i,50);

  // Non rende visibile una selezione

  table->setEditTriggers(QAbstractItemView::NoEditTriggers);
  table->setFocusPolicy(Qt::NoFocus);
  table->setSelectionMode(QAbstractItemView::NoSelection);
  //Cestini
  int i = 0;
  const QIcon* icon = new QIcon("../Grafica/Immagini/delete.png");
  QTableWidgetItem* item = new QTableWidgetItem(*icon,"");
  for(; i<4; i++){
    table->setVerticalHeaderItem(i,item);
  }

  table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

  table_layout->addWidget(table);
  setLayout(table_layout);
}
