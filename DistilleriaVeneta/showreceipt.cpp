#include "showreceipt.h"

showreceipt::showreceipt(QWidget* parent) : QWidget(parent) {
  QVBoxLayout* main_receipt = new QVBoxLayout();
  main_receipt->setContentsMargins(0, 0, 0, 0);
  addTable(main_receipt);
  //refreshtable();
}

void showreceipt::refreshtable(u_vector<pair<deep_ptr<product>, int>> items) const {
  unsigned int rows = items.size();  // numero di elementi dello scontrino
  table->setRowCount(rows);

  unsigned int r = rows - 1;
  QTableWidgetItem* item;

auto it = items.begin();
auto end = items.end();
  for (;it != end; it++) {
    item = new QTableWidgetItem();
    const QIcon* bin = new QIcon("../Grafica/Immagini/delete@x2");
    QPushButton* cestino = new QPushButton(*bin,"");
    table->setCellWidget(r, 0, cestino);

    item = new QTableWidgetItem();
    item->setText(QString::fromStdString((*it).first->get_name()));  // nome prodotto
    item->setTextAlignment(Qt::AlignCenter);
    table->setItem(r, 1, item);

    /* spinbox di un prodotto -> premo il -/+ -> spinbox emette segnale valueModified()
     * (devo aver prima collegato questo a segnale al corrispondente slot che si occupa di modificare nel model quel valore)
     *
     * segnale viene catturato dal controller -> controller (nel suo slot) invoca il medoto del model per aggiornare il valore del prodotto
     */

    item = new QTableWidgetItem();
    item->setText(QString::fromStdString(""));  // dimensione
    item->setTextAlignment(Qt::AlignCenter);
    table->setItem(r, 2, item);

    // Serve l'item?
    //            item=new QTableWidgetItem();
    QSpinBox* spin = new QSpinBox;
    table->setCellWidget(r, 3, spin);  // spinbox personalizzato con CSS??
    //            item->setTextAlignment(Qt::AlignCenter);
    //            table->setItem(r,3,item);

    item = new QTableWidgetItem();
    item->setText(QString::number((*it).first->get_price() * (*it).second, 'f', 2) + QString::fromStdString(" €"));  // prezzo * numero elementi
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

