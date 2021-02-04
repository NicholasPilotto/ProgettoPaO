#ifndef VIEW_H_
#define VIEW_H_

//#include "controller.h"
#include <QAlert>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QMenuBar>
#include <QPushButton>
#include <QScrollBar>
#include <QString>
#include <QVBoxLayout>

class view {
 private:
  QMenuBar* menu_bar;
  QVBoxLayout* main_layout;
  QHBoxLayout* main_object_layout;
  QLabel* name_label;
  QGridLayout* product_grid;
  QListWidget* receipt_list;
  QPushbutton* grappa_button;  //serve per forza scrivere button?
  QPushbutton* liquor_button;
  QPushbutton* cream_button;
  QPushbutton* add_item;
  QPushbutton* remove_item;
  QPushbutton* remove_line;
  QPushbutton* delete_receipt;
  QPushbutton* pay_button;
  QScrollBar* grid_scroll;
  QScrollBar* receipt_scroll;
  void add_menu_bar();
  void add_grid();
  void add_filter_buttons();
  void add_receipt();
  void add_receipt_buttons();
  unsigned int number_items();
  double calc_total_per_item();
  void show_alert(QAlert*);

 public:
  void view(QWidget *= nullptr);
  void set_controller(controller*);
  void upload_grid_item();
  void show_warning(Qstring);
  double calc_total();
};

#endif  // VIEW_H_