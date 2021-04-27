#ifndef GRIDSHOW_H
#define GRIDSHOW_H
#include <QWidget>
#include <QScrollArea>
#include <QFrame>
#include <QGridLayout>

#include "qproduct.h"
#include "Hierarchy/product.h"
#include "Utilities/u_vector.hpp"
#include "Utilities/deep_ptr.hpp"

class gridshow : public QWidget
{
    Q_OBJECT
private:
QScrollArea *product_area;
QFrame *contenitore;

public:
    gridshow(const u_vector<deep_ptr<product>>&, QWidget* parent = nullptr);
};

#endif // GRIDSHOW_H
