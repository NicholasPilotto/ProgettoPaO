#ifndef GRIDSHOW_H
#define GRIDSHOW_H
#include <QFrame>
#include <QGridLayout>
#include <QScrollArea>
#include <QStackedWidget>
#include <QWidget>

#include "Hierarchy/product.h"
#include "Utilities/deep_ptr.hpp"
#include "Utilities/u_vector.hpp"
#include "overlay.h"
#include "qproduct.h"

class QGridShow : public QWidget {
  Q_OBJECT
 private:
  QVBoxLayout* main_layout;
  QScrollArea* product_area;
  QFrame* contenitore;
  QGridLayout* grid;
  QStackedWidget* stack;

 public:
  QGridShow(QWidget* parent = nullptr);
  void refresh_grid(const u_vector<deep_ptr<product>>& _products);

signals:
  void mouseMoveEvent();

public slots:
  void change_overlay();
};

#endif  // GRIDSHOW_H
