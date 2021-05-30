#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "Hierarchy/product.h"
#include "model.h"
#include "view.h"

class view;

class controller : public QObject {
  Q_OBJECT
 private:
  view* _view;
  model* _model;
  QAction* previous_sender;

 public:
  explicit controller(QObject* = nullptr);
  void set_model(model*);
  void set_view(view*);
  void add_item(const deep_ptr<product>&);
  void remove_item(std::string, std::string);
  void refresh_quantity(std::string, std::string, int);
  bool presenza(const deep_ptr<product>&) const;
  double total_taxes() const;
  double total_price_line(pair<deep_ptr<product>, int>) const;
  double total_price() const;
  unsigned int total_number_items() const;
  u_vector<deep_ptr<product>> get_products_json() const;
  u_vector<pair<deep_ptr<product>, int>> get_receipt() const;

 public slots:
  void delete_all();
  void filter_by_products() const;
  void filter_by_color();
  void filter_by_taste();
};

#endif  // CONTROLLER_H
