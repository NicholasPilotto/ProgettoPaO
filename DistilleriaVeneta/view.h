#ifndef VIEW_H_
#define VIEW_H_

#include <QDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QMenuBar>
#include <QPushButton>
#include <QScrollBar>
#include <QString>
#include <QVBoxLayout>

class controller;

class view : public QWidget {
  Q_OBJECT
 private:
  QMenuBar* menu_bar;
  QVBoxLayout* main_layout;
  QHBoxLayout* main_object_layout;
  QLabel* name_label;
  QGridLayout* product_grid;
  QListWidget* receipt_list;
  QPushButton* grappa_button;  //serve per forza scrivere button?
  QPushButton* liquor_button;
  QPushButton* cream_button;
  QPushButton* add_item;
  QPushButton* remove_item;
  QPushButton* remove_line;
  QPushButton* delete_receipt;
  QPushButton* pay_button;
  QScrollBar* grid_scroll;
  QScrollBar* receipt_scroll;
  void add_menu_bar(QVBoxLayout*); // OK 1/2
  void add_title(QVBoxLayout*);
  void flavor_actions();
  void add_grid(QVBoxLayout*);
  void add_filter_buttons(QVBoxLayout*);
  void add_receipt();
  void add_receipt_buttons(QVBoxLayout*);
  unsigned int number_items();
  double calc_total_per_item();
  void show_alert(QDialog*); //OK

 public:
  view(QWidget* = nullptr);
  void set_controller(controller*);
  void upload_grid_item();
  void show_warning(const QString&);
  double calc_total();
};

#endif  // VIEW_H_
