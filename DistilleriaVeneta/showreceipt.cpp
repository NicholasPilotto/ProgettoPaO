#include "showreceipt.h"

showreceipt::showreceipt(QWidget* parent) : QWidget(parent) {
  QVBoxLayout* main_receipt = new QVBoxLayout();
  main_receipt->setContentsMargins(0, 0, 0, 0);
  addTable(main_receipt);
  refreshtable();
}

void showreceipt::refreshtable() const {
  unsigned int rows = 4;  // numero di elementi dello scontrino
  table->setRowCount(rows);

  unsigned int r = rows - 1;
  QTableWidgetItem* item;

  for (;;) {
    item = new QTableWidgetItem();
    QIcon* bin = new QIcon("../Grafica/Immagini/delete@x2");

    item->setIcon(*bin);
    item->setTextAlignment(Qt::AlignCenter);
    table->setItem(r, 0, item);

    item = new QTableWidgetItem();
    item->setText(QString::fromStdString(""));  // nome prodotto
    item->setTextAlignment(Qt::AlignCenter);
    table->setItem(r, 1, item);

    item = new QTableWidgetItem();
    item->setText(QString::fromStdString(presenter->));  // dimensione
    item->setTextAlignment(Qt::AlignCenter);
    table->setItem(r, 2, item);

    // Serve l'item?
    //            item=new QTableWidgetItem();
    QSpinBox* spin = new QSpinBox;
    table->setCellWidget(r, 3, spin);  // spinbox personalizzato con CSS??
    //            item->setTextAlignment(Qt::AlignCenter);
    //            table->setItem(r,3,item);

    item = new QTableWidgetItem();
    item->setText(QString::number(70.20) + QString::fromStdString(" €"));  // prezzo * numero elementi
    item->setTextAlignment(Qt::AlignCenter);
    table->setItem(r, 4, item);
  }
  QHeaderView* header = table->horizontalHeader();
  header->setSectionResizeMode(QHeaderView::Stretch);
}

void showreceipt::addTable(QVBoxLayout* main_receipt) {
  table = new QTableWidget(this);
  table->setColumnCount(5);

  QStringList names_columns;
  names_columns << " "
                << "Nome Prodotto"
                << "Dimensione"
                << "Quantità"
                << "Prezzo";
  table->setHorizontalHeaderLabels(names_columns);

  // Non rende visibile una selezione
  table->setEditTriggers(QAbstractItemView::NoEditTriggers);
  table->setFocusPolicy(Qt::NoFocus);
  table->setSelectionMode(QAbstractItemView::NoSelection);

  main_receipt->addWidget(table);
}

void showreceipt::showdeleteline() {
  QMessageBox* dialog = new QMessageBox();
  dialog->setMinimumSize(250, 110);
  dialog->setIcon(QMessageBox::Warning);
  dialog->setText("Sei sicuro di voler eliminare il prodotto dal carrello?");
  QPushButton* YesButton = new QPushButton("Si");
  QPushButton* NoButton = new QPushButton("No");
  dialog->addButton(YesButton, QMessageBox::YesRole);
  dialog->addButton(NoButton, QMessageBox::NoRole);
}

void showreceipt::setcontroller(controller* c) { presenter = c; }
