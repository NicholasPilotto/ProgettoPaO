#include "tablerow.h"

tablerow::tablerow(QTableWidget*& t) : QWidget(t), table(t), icon(new QIcon(":/icon/delete.png")) {}

tablerow::~tablerow() { delete icon; }

void tablerow::set_row(const deep_ptr<product>& p, int value_spin, int riga) {
  table->setRowHeight(riga, 50);

  // Inserimento icona cestino

  bin_item = new QTableWidgetItem(*icon, "");
  table->setVerticalHeaderItem(riga, bin_item);

  // Inserimento nome

  name_item = new QTableWidgetItem();
  name_item->setText(p->get_name().data());
  name_item->setTextAlignment(Qt::AlignCenter);
  table->setItem(riga, 0, name_item);

  // Inserimento grandezza bottiglia

  dim_item = new QTableWidgetItem();
  dim_item->setText(QString::fromStdString(p->fromKindToStdString(p->get_kind())));
  dim_item->setTextAlignment(Qt::AlignCenter);
  table->setItem(riga, 1, dim_item);

  // Inserimento SpinBox

  num_item = new QSpinBox(this);
  num_item->setRange(1, 2147483647);
  num_item->setValue(value_spin);
  num_item->setObjectName(QString::number(riga));
  table->setCellWidget(riga, 2, num_item);

  // Inserimento totale per linea

  price_item = new QTableWidgetItem();
  price_item->setText(QString::number(p->get_price() * value_spin, 'f', 2) + " €");
  price_item->setTextAlignment(Qt::AlignCenter);
  table->setItem(riga, 3, price_item);
}

QSpinBox*& tablerow::get_spin() { return num_item; }
