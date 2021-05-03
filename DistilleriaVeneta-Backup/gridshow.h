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
#include "grid_element.h"
#include "overlay.h"
#include "qproduct.h"

class gridshow : public QWidget {
  Q_OBJECT
 private:
  QVBoxLayout* main_layout;
  QScrollArea* product_area;
  QFrame* contenitore;
  QGridLayout* grid;
  grid_element* stack;

 public:
  gridshow(const u_vector<deep_ptr<product>>&, QWidget* parent = nullptr);
};

#endif  // GRIDSHOW_H
