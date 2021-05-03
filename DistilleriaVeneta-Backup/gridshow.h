#ifndef GRIDSHOW_H
#define GRIDSHOW_H
#include <QWidget>
#include <QScrollArea>
#include <QFrame>
#include <QGridLayout>
#include <QStackedWidget>

#include "qproduct.h"
#include "overlay.h"
#include "grid_element.h"
#include "Hierarchy/product.h"
#include "Utilities/u_vector.hpp"
#include "Utilities/deep_ptr.hpp"

class gridshow : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* main_layout;
    QScrollArea *product_area;
    QFrame *contenitore;
    QGridLayout* grid;
    grid_element* stack;

public:
    gridshow(const u_vector<deep_ptr<product>>&, QWidget* parent = nullptr);
};

#endif // GRIDSHOW_H
