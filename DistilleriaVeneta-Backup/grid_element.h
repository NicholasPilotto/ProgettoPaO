#ifndef GRID_ELEMENT_H
#define GRID_ELEMENT_H

#include <QStackedWidget>

#include "overlay.h"
#include "qproduct.h"

class grid_element : public QStackedWidget {
 public:
  grid_element(QProduct*, overlay*, QStackedWidget* = nullptr);
};

#endif  // GRID_ELEMENT_H
