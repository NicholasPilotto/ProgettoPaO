#include "qproduct.h"

QProduct::QProduct(QWidget* parent, deep_ptr<product> p) : QWidget(parent)
{

    QVBoxLayout *mainlayout = new QVBoxLayout;
    QHBoxLayout *image_layout = new QHBoxLayout;
    left_widget_image = new QFrame;
    left_widget_image->setStyleSheet("background-color: rgb(50,50,50)");
    QLabel* img = new QLabel();
    QPixmap* pix = new QPixmap(p->get_image_path().data()); // getpath
    img->setPixmap(*pix);
    image_layout->addWidget(img);
    left_widget_image->setLayout(image_layout);
    //left_widget_image->layout()->setMargin(0);
    left_widget_image->layout()->setSpacing(0);
    left_widget_image->layout()->setAlignment(Qt::AlignCenter);
    left_widget_image->setMinimumSize(100, 178);
    left_widget_image->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    mainlayout->addWidget(left_widget_image, Qt::AlignCenter);
    left_widget_name = new QLabel("Liquirizia"); //getname p->getname()
    left_widget_name->setAlignment(Qt::AlignCenter);
    mainlayout->addWidget(left_widget_name, Qt::AlignCenter);
    left_widget_price = new QLabel("10.50");
    left_widget_price->setAlignment((Qt::AlignCenter));
    mainlayout->addWidget(left_widget_price, Qt::AlignCenter);

    setLayout(mainlayout);
}
