#ifndef GRID_ELEMENT_H
#define GRID_ELEMENT_H

#include <QStackedWidget>

#include "qproduct.h"
#include "overlay.h"

class grid_element : public QStackedWidget
{
public:
    grid_element(QProduct*, overlay*, QStackedWidget* = nullptr);
};

#endif // GRID_ELEMENT_H
