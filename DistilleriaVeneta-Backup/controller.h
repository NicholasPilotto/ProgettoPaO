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
  void link_model(model*);
  void link_view(view*);
  void add_item(product*);
  void save_receipt() const;
  void delete_receipt();
  void pay();
  void decrement_item(product*);
  void increment_item(product*);
  void remove_item(product*);
  u_vector<deep_ptr<product>> load_from_file(const std::string& path) const;
  u_vector<pair<deep_ptr<product>, int>> get_receipt_items();
  virtual ~controller();

 public slots:
};

#endif  // CONTROLLER_H
