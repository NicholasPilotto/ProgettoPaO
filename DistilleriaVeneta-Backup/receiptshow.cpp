#include "receiptshow.h"

receiptshow::receiptshow(QWidget* parent) : QWidget(parent)
{
    QVBoxLayout* table_layout = new QVBoxLayout();
    addTable(table_layout);
    refreshTable();

    setLayout(table_layout);
}

void receiptshow::addTable(QVBoxLayout* table_layout) {

  table = new QTableWidget(this);
  table->setMinimumSize(500,500);
  table->setColumnCount(4);

  QStringList names_columns;
  names_columns << "Nome Prodotto"
                << "Dimensione"
                << "Quantità"
                << "Prezzo";

  table->setHorizontalHeaderLabels(names_columns);

  table_layout->addWidget(table);
}

void receiptshow::refreshTable()
{
    table->setRowCount(20);

    for(int i=0; i<20; i++)
    table->setRowHeight(i,50);

    //Cestini
    const QIcon* icon = new QIcon("../Grafica/Immagini/delete.png");
    QTableWidgetItem* item = new QTableWidgetItem(*icon,"");
    for(int i = 0; i < 20; i++){
      table->setVerticalHeaderItem(i,item);
    }

    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // Non rende visibile una selezione

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setFocusPolicy(Qt::NoFocus);
    table->setSelectionMode(QAbstractItemView::NoSelection);
    //table->setStyleSheet("gridline-color: white");  // rende bianche le linee poi gli oggetti che inseriamo mettiamo i bordi alti e bassi così da avere solo linee
}
