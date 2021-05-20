#ifndef RECEIPTSHOW_H
#define RECEIPTSHOW_H

#include <QHeaderView>
#include <QIcon>
#include <QSpinBox>
#include <QLabel>
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
  QGridLayout* resoconto;
  QLabel* prezzo_totale;
  QLabel* tasse_totale;
  double refresh_totale;
  double refresh_tasse;

 public:
  explicit QReceiptShow(QWidget* = nullptr);
  void addTable(QVBoxLayout*);
  void refreshTable(const u_vector<std::pair<deep_ptr<product>, int>>&);
  QGridLayout* add_total();
};

#endif  // RECEIPTSHOW_H
