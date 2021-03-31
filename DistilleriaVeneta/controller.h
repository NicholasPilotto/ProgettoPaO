#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "Hierarchy/product.h"
#include "model.h"
#include "view.h"

class controller : public QObject {
  Q_OBJECT
 private:
  view* _view;
  model* _model;

 public:
  explicit controller(QObject* = nullptr);
  void link_model(model*);
  void link_view(view*);
  void add_item(product*);
  void save_receipt() const;
  //  void add_package()
  //  void remove_packege()
  //  u_vector<std::pair<package, int>> get_package() const
  void delete_receipt();
  void pay();
  void decrement_item(product*);
  void increment_item(product*);
  void remove_item(product*);
  virtual ~controller();

 public slots:
};

#endif // CONTROLLER_H
