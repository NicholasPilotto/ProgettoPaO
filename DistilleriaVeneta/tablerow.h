#ifndef TABLEROW_H
#define TABLEROW_H

#include <QList>
#include <QObject>
#include <QSpinBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QWidget>

#include "receiptshow.h"

class tablerow : public QWidget {
  Q_OBJECT
 private:
  QTableWidgetItem* bin_item;
  QTableWidgetItem* name_item;
  QTableWidgetItem* dim_item;
  QSpinBox* num_item;
  QTableWidgetItem* price_item;
  QTableWidget* table;

 public:
  tablerow(QTableWidget*&);
  void set_row(const deep_ptr<product>&, int, int);
  QSpinBox*& get_spin();
};

#endif  // TABLEROW_H
