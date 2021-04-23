#ifndef QPRODUCT_H
#define QPRODUCT_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "controller.h"
#include "Utilities/deep_ptr.hpp"

class QProduct : public QWidget {
    Q_OBJECT
private:
    QFrame* left_widget_image;
    QLabel* left_widget_name;
    QLabel* left_widget_price;
    controller* presenter;
public:
    explicit QProduct(QWidget* parent = nullptr, deep_ptr<product> = nullptr);
};
#endif // QPRODUCT_H
