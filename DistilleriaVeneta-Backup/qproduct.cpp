#include "qproduct.h"
#include <QDebug>

QProduct::QProduct(const deep_ptr<product>& _product, QWidget *parent) : QWidget(parent)
{

    QVBoxLayout *mainlayout = new QVBoxLayout;
    QHBoxLayout *image_layout = new QHBoxLayout;
    left_widget_image = new QFrame;
    left_widget_image->setStyleSheet("background-color: rgb(239,235,231)");
    QLabel* img = new QLabel();
    QPixmap* pix = new QPixmap("../Grafica/Immagini/herbal-liquor.png");
    img->setPixmap(*pix);
    image_layout->addWidget(img);
    left_widget_image->setLayout(image_layout);
    left_widget_image->layout()->setMargin(0);
    left_widget_image->layout()->setSpacing(0);
    left_widget_image->layout()->setAlignment(Qt::AlignCenter);
    left_widget_image->setMinimumSize(100, 125);
    left_widget_image->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    mainlayout->addWidget(left_widget_image, Qt::AlignCenter);
    left_widget_name = new QLabel(_product->get_name().data());
    left_widget_name->setAlignment(Qt::AlignCenter);
    mainlayout->addWidget(left_widget_name, Qt::AlignCenter);
    left_widget_price = new QLabel(QString::number(_product->get_price(), 'f', 2) + " €");
    left_widget_price->setAlignment((Qt::AlignCenter));
    mainlayout->addWidget(left_widget_price, Qt::AlignHCenter);

    setLayout(mainlayout);
}
