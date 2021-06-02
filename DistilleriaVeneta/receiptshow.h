#ifndef RECEIPTSHOW_H
#define RECEIPTSHOW_H

#include <QHeaderView>
#include <QIcon>
#include <QLabel>
#include <QMessageBox>
#include <QSpinBox>
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
  QLabel* n_items;
  QPushButton* elimina_prodotto;
  controller* presenter;
  int latest_value;
  QList<QSpinBox*> list_spin;

  QDialog* remove_line;

 public:
  explicit QReceiptShow(QWidget* = nullptr);
  void setpresenter(controller*);
  void addTable(QVBoxLayout*);
  void refreshTable(const u_vector<std::pair<deep_ptr<product>, int>>&);
  QGridLayout* add_total();
  void refresh_totali();
  void elimina_prodotto_dialog();

 private slots:
  //  void remove_row(int);
 public slots:
  void EliminaButtonSlot();
  void CancellaProdottoSlot();
  void refresh_spinbox(int);
};

#endif  // RECEIPTSHOW_H
