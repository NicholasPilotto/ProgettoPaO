#ifndef SHOWGRID_H
#define SHOWGRID_H

#include <QFrame>
#include <QGridLayout>
#include <QScrollArea>

#include "controller.h"
#include "qproduct.h"

class showgrid : public QWidget {
  Q_OBJECT
 private:
  QScrollArea *product_area;
  QFrame *contenitore;
  QGridLayout *layout;
  controller *presenter;

 public:
  showgrid(QWidget * = nullptr);
  void setcontroller(controller *);
};

#endif  // SHOWGRID_H
