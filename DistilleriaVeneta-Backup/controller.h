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

 public:
  explicit controller(model* = nullptr, QObject* = nullptr);
  void link_model(const deep_ptr<model>&);
  void link_view(const deep_ptr<view>&);
  void add_item(const deep_ptr<product>&);
  void save_receipt() const;
  void delete_receipt();
  void decrement_item(const deep_ptr<product>&);
  void increment_item(const deep_ptr<product>&);
  void remove_item(const deep_ptr<product>&);
  double total_taxes();
  double total_price_line(int) const;
  double total_price();
  unsigned int total_number_items();
  u_vector<deep_ptr<product>> load_from_file(const std::string& path) const;
  u_vector<pair<deep_ptr<product>, int>> get_receipt_items();
  virtual ~controller();

 public slots:
  void pay();
};

#endif  // CONTROLLER_H
