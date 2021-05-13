#ifndef VIEW_H_
#define VIEW_H_

#include <QDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMenuBar>
#include <QPushButton>
#include <QScrollArea>
#include <QString>
#include <QTableView>
#include <QVBoxLayout>

#include "./Utilities/deep_ptr.hpp"
#include "./Utilities/u_vector.hpp"
#include "controller.h"
#include "gridshow.h"
#include "qproduct.h"
#include "receiptshow.h"

class controller;

class view : public QWidget {
  Q_OBJECT
 private:
  QVBoxLayout* main_layout;    // Used
  QHBoxLayout* object_layout;  // Used
  QMenuBar* menu_bar;          // Used
  QMenu* file;
  QAction* close_action;
  QMenu* filters;
  QMenu* alcohols;
  QAction* cresc;
  QAction* desc;
  QMenu* colors;
  QMenu* flavors;
  QLabel* title;
  QHBoxLayout* filter_buttons;
  QPushButton* grappa_button;  // Used
  QPushButton* liquor_button;  // Used
  QPushButton* cream_button;   // Used
  QVBoxLayout* left_app;
  QGridShow* product_area;
  QHBoxLayout* receipt_buttons;
  QGridLayout* resoconto;
  QPushButton* delete_receipt;  // Used
  QPushButton* pay_button;      // Used
  QVBoxLayout* right_app;
  QReceiptShow* receipt_area;
  controller* presenter;

  QDialog* pay_dialog;

  void add_menu_bar(QVBoxLayout*);               // OK
  void add_title(QVBoxLayout*, const QString&);  // OK
  QHBoxLayout* add_filter_buttons();             // OK
  void add_grid(QHBoxLayout*);                   // OK
  QHBoxLayout* add_receipt_buttons();            // OK
  QGridLayout* add_total();                      // OK
  void add_receipt(QHBoxLayout*);                // OK
  void update_json();

 public:
  view(QWidget* = nullptr);
  void set_controller(controller*);   // DA FARE
  void show_warning(const QString&);  // OK

 public slots:
  void pay_banner();
};

#endif  // VIEW_H_
