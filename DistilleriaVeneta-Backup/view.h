#ifndef VIEW_H_
#define VIEW_H_

#include <QBoxLayout>
#include <QDialog>
#include <QFileDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QInputDialog>  // per pay_banner
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
  QMenu* file;
  QMenu* filters;
  QMenu* alcohols;
  // QAction* codes;
  QMenu* colors;
  QMenu* flavors;
  QMenuBar* menu_bar;               // Used
  QVBoxLayout* main_layout;         // Used
  QHBoxLayout* main_object_layout;  // Used
  QPushButton* grappa_button;       // Used
  QPushButton* liquor_button;       // Used
  QPushButton* cream_button;        // Used
  QPushButton* delete_receipt;      // Used
  QPushButton* pay_button;          // Used
  controller* presenter;
  QAction* cresc;
  QAction* desc;
  QAction* close_action;
  QLabel* title;
  QGridLayout* resoconto;
  QHBoxLayout* filter_buttons;
  QHBoxLayout* receipt_buttons;
  receiptshow* receipt_area;
  QLabel* receipt_title;
  QVBoxLayout* right_app;
  QVBoxLayout* left_app;
  gridshow* product_area;
  QLabel* products_title;
  QDialog* pay_dialog;

  void add_menu_bar(QVBoxLayout*);               // OK
  void add_title(QVBoxLayout*, const QString&);  // OK
  void add_grid(QHBoxLayout*);                   // OK
  QHBoxLayout* add_filter_buttons();             // OK
  void add_receipt(QHBoxLayout*);                // OK
  QHBoxLayout* add_receipt_buttons();            // OK
  void show_alert(QDialog*);                     // NON FATTO

 public:
  view(QWidget* = nullptr);  // OK
  ~view();
  void set_controller(const deep_ptr<controller>&);  // DA FARE
  void show_warning(const QString&);                 // OK
  unsigned int total_number_items();                 // DA RICHIAMARE
  double calc_total();                               // DA FARE
  void add_elements();
  void create_connections();
 public slots:
  void pay_banner();  // FATTO
};

#endif  // VIEW_H_
