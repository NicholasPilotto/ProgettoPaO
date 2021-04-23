#ifndef SHOWRECEIPT_H
#define SHOWRECEIPT_H

#include <QHeaderView>
#include <QIcon>
#include <QMessageBox>
#include <QSpinBox>
#include <QTableWidget>
#include <QTableWidgetItem>

#include "controller.h"

class showreceipt : public QWidget {
  Q_OBJECT
 private:
  controller* presenter;
  QTableWidget* table;

  void addTable(QVBoxLayout*);
  void refreshtable() const;
  void showdeleteline();
  void setcontroller(controller* c);

 public:
  explicit showreceipt(QWidget* = nullptr);
};

#endif  // SHOWRECEIPT_H
