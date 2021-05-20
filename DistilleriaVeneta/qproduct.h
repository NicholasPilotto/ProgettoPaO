#ifndef QPRODUCT_H
#define QPRODUCT_H

#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <functional>

#include "Hierarchy/product.h"
#include "Utilities/deep_ptr.hpp"

class QProduct : public QWidget {
  Q_OBJECT
 private:
  QVBoxLayout* mainlayout;
  QHBoxLayout* image_layout;
  QLabel* img;
  QPixmap* pix;
  QFrame* left_widget_image;
  QLabel* left_widget_name;
  QLabel* left_widget_price;
  QLabel* left_widget_code;
  deep_ptr<product> item;
  std::function<void(deep_ptr<product>)> product_callback;

 public:
  explicit QProduct(const deep_ptr<product>&,std::function<void(const deep_ptr<product>&)>, QWidget* = nullptr);

public slots:
  void insert_small();
  void insert_medium();
  void insert_big();
};

#endif  // QPRODUCT_H
