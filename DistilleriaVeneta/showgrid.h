#ifndef SHOWGRID_H
#define SHOWGRID_H

#include <QFrame>
#include <QGridLayout>
#include <QScrollArea>

#include "controller.h"
#include "model.h"
#include "qproduct.h"

class showgrid : public QWidget {
  Q_OBJECT
 private:
  QScrollArea *product_area;
  QFrame *contenitore;
  QGridLayout *layout;

  // u_vector<deep_ptr<product>> products;

 public:
  showgrid(u_vector<deep_ptr<product>>, QWidget * = nullptr);
};

#endif  // SHOWGRID_H
