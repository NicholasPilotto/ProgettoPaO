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
#include "tablerow.h"
using std::pair;

class controller;

class QReceiptShow : public QWidget {
  Q_OBJECT
 private:
  QTableWidget* table;
  QGridLayout* resoconto;
  QLabel* prezzo_finale;
  QLabel* tasse_finale;
  double refresh_totale;
  double refresh_tasse;
  controller* presenter;

  QDialog* remove_line;

 public:
  explicit QReceiptShow(QWidget* = nullptr);
  void setpresenter(controller*);
  void addTable(QVBoxLayout*);
  void refreshTable(const u_vector<std::pair<deep_ptr<product>, int>>&);
  QGridLayout* add_total();

private slots:
  void remove_row(int);
};

#endif  // RECEIPTSHOW_H
