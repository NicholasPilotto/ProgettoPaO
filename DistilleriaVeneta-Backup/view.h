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

#include "./Utilities/u_vector.hpp"
#include "controller.h"
#include "gridshow.h"
#include "qproduct.h"
#include "receiptshow.h"

class controller;

class view : public QWidget {
  Q_OBJECT
 private:
  QMenuBar* menu_bar;               // Used
  QVBoxLayout* main_layout;         // Used
  QHBoxLayout* main_object_layout;  // Used
  QPushButton* grappa_button;       // Used
  QPushButton* liquor_button;       // Used
  QPushButton* cream_button;        // Used
  QPushButton* delete_receipt;      // Used
  QPushButton* pay_button;          // Used
  controller* presenter;

  void add_menu_bar(QVBoxLayout*);               // OK
  void add_title(QVBoxLayout*, const QString&);  // OK
  void add_grid(QHBoxLayout*);                   // OK
  QHBoxLayout* add_filter_buttons();             // OK
  void add_receipt(QHBoxLayout*);                // OK
  QHBoxLayout* add_receipt_buttons();            // OK
  void show_alert(QDialog*);                     // NON FATTO

 public:
  view(QWidget* = nullptr);           // OK
  void set_controller(controller*);   // DA FARE
  void show_warning(const QString&);  // OK
  unsigned int number_items();        // DA FARE
  double calc_total_per_item();       // DA FARE
  double calc_total();                // DA FARE
  void pay_banner();                  // NON FATTO
  void add_elements();
};

#endif  // VIEW_H_
