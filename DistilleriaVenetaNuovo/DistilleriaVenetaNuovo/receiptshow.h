#ifndef RECEIPTSHOW_H
#define RECEIPTSHOW_H

#include <QHeaderView>
#include <QIcon>
#include <QSpinBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QWidget>

#include "Hierarchy/product.h"
#include "Utilities/deep_ptr.hpp"
#include "Utilities/u_vector.hpp"
using std::pair;

class QReceiptShow : public QWidget {
  Q_OBJECT
 private:
  QTableWidget* table;

 public:
  explicit QReceiptShow(QWidget* = nullptr);
  void addTable(QVBoxLayout*);
  void refreshTable(const u_vector<std::pair<deep_ptr<product>, int>>&);
};

#endif  // RECEIPTSHOW_H
