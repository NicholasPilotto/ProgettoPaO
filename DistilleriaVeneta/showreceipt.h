#ifndef SHOWRECEIPT_H
#define SHOWRECEIPT_H

#include <QHeaderView>
#include <QIcon>
#include <QMessageBox>
#include <QSpinBox>
#include <QTableWidget>
#include <QTableWidgetItem>

#include "controller.h"
#include "model.h"

class showreceipt : public QWidget {
  Q_OBJECT
 private:
  QTableWidget* table;

  void addTable(QVBoxLayout*);
  //void refreshtable(u_vector<pair<deep_ptr<product>, int>> items) const;
  void showdeleteline();


 public:
  explicit showreceipt(QWidget* = nullptr);
  void refreshtable(u_vector<pair<deep_ptr<product>, int>> items) const;
};

#endif  // SHOWRECEIPT_H
