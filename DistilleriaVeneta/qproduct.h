#ifndef QPRODUCT_H
#define QPRODUCT_H

#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

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

 public:
  explicit QProduct(const deep_ptr<product>&, QWidget* parent = nullptr);
};

#endif  // QPRODUCT_H
