#include "qproduct.h"

QProduct::QProduct(deep_ptr<product> p, QWidget* parent) : QWidget(parent) {
  QVBoxLayout* mainlayout = new QVBoxLayout;
  QHBoxLayout* image_layout = new QHBoxLayout;
  left_widget_image = new QFrame;
  left_widget_image->setStyleSheet("background-color: rgb(50,50,50)");
  QLabel* img = new QLabel();
  const QString* label_path = new QString(QString::fromStdString(p->get_image_path()));
  QPixmap* pix = new QPixmap(*label_path);
  img->setPixmap(*pix);
  image_layout->addWidget(img);
  left_widget_image->setLayout(image_layout);
  // left_widget_image->layout()->setMargin(0);
  left_widget_image->layout()->setSpacing(0);
  left_widget_image->layout()->setAlignment(Qt::AlignCenter);
  left_widget_image->setMinimumSize(100, 178);
  left_widget_image->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  mainlayout->addWidget(left_widget_image, Qt::AlignCenter);
  const QString* label_name = new QString(QString::fromStdString(p->get_name()));
  left_widget_name = new QLabel(*label_name);  // getname p->getname() left_widget_name = new QLabel(p->get_name().data());
  left_widget_name->setAlignment(Qt::AlignCenter);
  mainlayout->addWidget(left_widget_name, Qt::AlignCenter);
  const QString* label_price = new QString(QString::number(p->get_price(), 'f', 2));
  left_widget_price = new QLabel(*label_price);
  left_widget_price->setAlignment((Qt::AlignCenter));
  mainlayout->addWidget(left_widget_price, Qt::AlignCenter);
  setLayout(mainlayout);
}
