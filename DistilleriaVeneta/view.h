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
class showreceipt;

class view : public QWidget {
  Q_OBJECT
 private:
  QMenuBar* menu_bar;               // Used
  QVBoxLayout* main_layout;         // Used
  QHBoxLayout* main_object_layout;  // Used
  QLabel* name_label;
  QGridLayout* product_grid;
  QPushButton* grappa_button;
  QPushButton* liquor_button;
  QPushButton* cream_button;
  QPushButton* delete_receipt;
  QPushButton* pay_button;
  controller* presenter;

  showreceipt* showrec;

  void add_menu_bar(QVBoxLayout*);     // OK
  void add_title(QVBoxLayout*);        // OK
  void add_grid(QHBoxLayout*);         // OK
  QHBoxLayout* add_filter_buttons();   // OK
  void add_receipt(QHBoxLayout*);      // OK
  QHBoxLayout* add_receipt_buttons();  // OK
  unsigned int number_items();         // DA FARE
  double calc_total_per_item();        // DA FARE
  void show_alert(QDialog*);           // NON FATTO
  //u_vector<deep_ptr<product>> load_products(const std::string& = ":/data/data.json") const;
  u_vector<deep_ptr<product>> loading_products() const;

 public:
  view(QWidget* = nullptr);           // OK
  void set_controller(controller*);   // NON FATTO
  void show_warning(const QString&);  // OK
  double calc_total();                // DA FARE
  void pay_banner(QDialog*);          // NON FATTO
  void refresh_receipt(u_vector<pair<deep_ptr<product>, int>> items) const;
};

#endif  // VIEW_H_
