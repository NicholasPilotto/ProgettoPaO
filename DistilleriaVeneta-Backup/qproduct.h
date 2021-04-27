#ifndef QPRODUCT_H
#define QPRODUCT_H

#include <QWidget>
#include <QLabel>
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "Utilities/deep_ptr.hpp"
#include "Hierarchy/product.h"

class QProduct : public QWidget {
    Q_OBJECT
private:
    QFrame* left_widget_image;
    QLabel* left_widget_name;
    QLabel* left_widget_price;
public:
    explicit QProduct(const deep_ptr<product>&, QWidget* parent = nullptr);
};

#endif // QPRODUCT_H
