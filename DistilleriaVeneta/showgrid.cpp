#include "showgrid.h"

showgrid::showgrid( u_vector<deep_ptr<product>> prodotti, QWidget* parent) : QWidget(parent) {
  QVBoxLayout* main = new QVBoxLayout;
  product_area = new QScrollArea;
  product_area->setMinimumSize(QSize(500, 500));
  product_area->setWidgetResizable(true);
  product_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

  contenitore = new QFrame();

  layout = new QGridLayout();

  contenitore->setLayout(layout);

  product_area->setWidget(contenitore);

  int r = 1, c = 1, n_ele = 3;
  for (auto it = prodotti.begin(); it != prodotti.end(); it++)
  {
    QProduct* p = new QProduct(*it);

    layout->addWidget(p, r, c);

    if (!(c % n_ele)) {
      r++;
      c = 1;
    } else
      c++;
  }
  main->addWidget(product_area);
  setLayout(main);
}
