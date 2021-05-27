#include "qproduct.h"

#include <QDebug>

QProduct::QProduct(const deep_ptr<product>& _product, std::function<void(const deep_ptr<product>&)> callback, QWidget* parent) : QWidget(parent), item(_product), product_callback(callback) {

    item = _product;
  // Dichiarazione layout principale e dell'immagine

  mainlayout = new QVBoxLayout();
  image_layout = new QHBoxLayout();

  // Creazione dell'immagine e

  img = new QLabel();
  pix = new QPixmap(_product->get_image_path().data());
  img->setPixmap(*pix);

  // Immagine inserita nel suo layout e widget + set layout + grafica

  left_widget_image = new QFrame();
  left_widget_image->setStyleSheet("background-color: rgb(239,235,231)");
  image_layout->addWidget(img);
  left_widget_image->setLayout(image_layout);
  left_widget_image->layout()->setMargin(0);
  left_widget_image->layout()->setSpacing(0);
  left_widget_image->layout()->setAlignment(Qt::AlignCenter);
  left_widget_image->setMinimumSize(100, 125);
  left_widget_image->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  // Widget immagine aggiunto al layout principale

  mainlayout->addWidget(left_widget_image, Qt::AlignCenter);

  // Aggiunta del nome della bottiglia

  left_widget_name = new QLabel(_product->get_name().data());
  left_widget_name->setAlignment(Qt::AlignCenter);
  mainlayout->addWidget(left_widget_name, Qt::AlignCenter);

  // Aggiunta del prezzo base della bottiglia

  left_widget_price = new QLabel(QString::number(_product->get_price(), 'f', 2) + " €");
  left_widget_price->setAlignment((Qt::AlignCenter));
  mainlayout->addWidget(left_widget_price, Qt::AlignCenter);

  // Aggiunta del codice della bottiglia

  left_widget_code = new QLabel("Codice:\n" + QString::fromStdString(_product->code()));
  left_widget_code->setStyleSheet("font: 11px");
  left_widget_code->setAlignment((Qt::AlignRight));
  mainlayout->addWidget(left_widget_code, Qt::AlignRight);

  // Set layout principale

  setLayout(mainlayout);
}

void QProduct::insert_small()
{
    item->set_kind_bottle(small);
    product_callback(item);
}

void QProduct::insert_medium()
{
    item->set_kind_bottle(medium);
    product_callback(item);
}

void QProduct::insert_big()
{
    item->set_kind_bottle(big);
    product_callback(item);
}
