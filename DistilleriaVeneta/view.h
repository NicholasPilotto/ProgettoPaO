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
#include <QFileDialog>
#include <QLineEdit>
#include <QString>
#include "./Utilities/u_vector.hpp"

class controller;

class view : public QWidget {
  Q_OBJECT
 private:
  QMenuBar* menu_bar; //Used
  QVBoxLayout* main_layout; //Used
  QHBoxLayout* main_object_layout; //Used
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
  void add_menu_bar(QVBoxLayout*);          // OK
  void add_title(QVBoxLayout*);             // OK
  void add_grid(QHBoxLayout*);              // OK
  QHBoxLayout* add_filter_buttons();        // OK
  void add_receipt(QHBoxLayout*);           // OK
  QHBoxLayout* add_receipt_buttons();       // OK
  unsigned int number_items();
  double calc_total_per_item();
  void show_alert(QDialog*);                //OK

 public:
  view(QWidget* = nullptr);
  void set_controller(controller*);
  void upload_grid_item();
  QString add_dialog_choice();
  void show_warning(const QString&);
  double calc_total();
};




class QProduct : public QWidget{
    Q_OBJECT
private:
    QFrame* left_widget_image;
    QLabel* left_widget_name;
    QLabel* left_widget_code;
    QPushButton* add;
public:
    explicit QProduct(QWidget* parent = nullptr);
};

#endif  // VIEW_H_
