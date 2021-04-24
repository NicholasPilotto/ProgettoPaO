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
  explicit controller(QObject* = nullptr);
  void link_model(model*);
  void link_view(view*);
  //aggiunto dopo
  u_vector<deep_ptr<product> > load_products() const;
  void save_receipt() const;
  //  void add_package()
  //  void remove_packege()
  //  u_vector<std::pair<package, int>> get_package() const

  void pay();
  // non serve perchè nel main vengono già distrutti...
  virtual ~controller();



 public slots:
    void decrement_item(product*);
    //void delete_receipt();
    void increment_item(product*);
    void refresh_receipt();
    void add_item(product*);
      void remove_item(product*);
};

#endif  // CONTROLLER_H
