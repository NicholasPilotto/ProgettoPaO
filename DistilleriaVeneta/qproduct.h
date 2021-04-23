#ifndef QPRODUCT_H
#define QPRODUCT_H

#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

#include "Utilities/deep_ptr.hpp"
#include "controller.h"

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
#endif  // QPRODUCT_H
