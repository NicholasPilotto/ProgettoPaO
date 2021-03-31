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

class controller;

class view : public QWidget {
  Q_OBJECT
 private:
  QMenuBar* menu_bar; //Used
  QVBoxLayout* main_layout; //Used
  QHBoxLayout* main_object_layout; //Used
  QLabel* name_label;
  QGridLayout* product_grid;
  //QListWidget* receipt_list;
  QPushButton* grappa_button;  //serve per forza scrivere button?
  QPushButton* liquor_button;
  QPushButton* cream_button;
  QPushButton* delete_receipt;
  QPushButton* pay_button;
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


class QProduct : public QWidget {
    Q_OBJECT
private:
    QFrame* left_widget_image;
    QLabel* left_widget_name;
    QLabel* left_widget_price;
public:
    explicit QProduct(QWidget* parent = nullptr);
};

/*
class product : public QFrame {
    Q_OBJECT
private:
    QLabel* img;
    QLabel* left_widget_name;
    QLabel* left_widget_price;
public:
    explicit product(QFrame* parent = nullptr);
};
*/


class QReceiptitem : public QWidget{
    Q_OBJECT
private:
    QLabel* left_widget_name;
    QLabel* left_widget_dim;
    QLabel* left_widget_n_items;
    QLabel* left_widget_line_price;
public:
    explicit QReceiptitem(QWidget* parent = nullptr);
};

#endif  // VIEW_H_
