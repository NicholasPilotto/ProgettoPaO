#ifndef VIEW_H_
#define VIEW_H_

#include <QBoxLayout>
#include <QDialog>
#include <QFileDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMenuBar>
#include <QPushButton>
#include <QScrollArea>
#include <QScrollBar>
#include <QString>
#include <QTableView>
#include <QVBoxLayout>

#include "./Utilities/u_vector.hpp"
#include "qproduct.h"
#include "showgrid.h"
#include "showreceipt.h"

class controller;

class view : public QWidget {
  Q_OBJECT
 private:
  QMenuBar* menu_bar; //Used
  QVBoxLayout* main_layout; //Used
  QHBoxLayout* main_object_layout; //Used
  QLabel* name_label;
  QGridLayout* product_grid;
  QPushButton* grappa_button;
  QPushButton* liquor_button;
  QPushButton* cream_button;
  QPushButton* delete_receipt;
  QPushButton* pay_button;
  controller* presenter;
  void add_menu_bar(QVBoxLayout*);          // OK
  void add_title(QVBoxLayout*);             // OK
  void add_grid(QHBoxLayout*);              // OK
  QHBoxLayout* add_filter_buttons();        // OK
  void add_receipt(QHBoxLayout*);           // OK
  QHBoxLayout* add_receipt_buttons();       // OK
  unsigned int number_items();              // DA FARE
  double calc_total_per_item();             // DA FARE
  void show_alert(QDialog*);                // NON FATTO

 public:
  view(QWidget* = nullptr);                 // OK
  void set_controller(controller*);         // NON FATTO
  void upload_grid_item();                  // 1/2
  void modify_grid_item();                  // NON FATTO
  void remove_grid_item();                  // NON FATTO
  QString add_dialog_choice();              // OK
  void show_warning(const QString&);        // OK
  double calc_total();                      // DA FARE
  void pay_banner(QDialog*);                // NON FATTO
};

#endif  // VIEW_H_
