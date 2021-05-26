#include "gridshow.h"

QGridShow::QGridShow(QWidget* parent) : QWidget(parent) {
  main_layout = new QVBoxLayout(this);

  // ScrollArea

  product_area = new QScrollArea();
  product_area->setMinimumSize(550, 500);
  product_area->setWidgetResizable(true);
  product_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

  // Mettere la griglia sul contenitore e settare il widget sulla ScrollArea

  contenitore = new QFrame();
  grid = new QGridLayout();

  contenitore->setLayout(grid);
  product_area->setWidget(contenitore);

  // Aggiunta ScrollArea vuota

  main_layout->addWidget(product_area);
  setLayout(main_layout);
}

void QGridShow::clear_grid() {
  while (auto item = grid->takeAt(0)) {
    delete item->widget();
    item++;
  }
}

void QGridShow::refresh_grid(const u_vector<deep_ptr<product>>& _products, std::function<void(const deep_ptr<product>&)> bind) {
  clear_grid();
  int r = 1;
  int c = 1;
  const int n_ele = 3;
  u_vector<deep_ptr<product>>::const_iterator it = _products.const_begin();
  u_vector<deep_ptr<product>>::const_iterator end = _products.const_end();
  lista_prodotti.clear();

  for (; it != end; it++) {
    QProduct* p = new QProduct(*it,bind);
    p->setMaximumSize(160,240);
    QOverlay* o = new QOverlay();
    o->setMaximumSize(160,240);
    QStackedWidgetHover* stack = new QStackedWidgetHover(p,o);
    add_product(stack,r,c);

    connect(o->get_small_button(), SIGNAL(clicked()), p, SLOT(insert_small()));
    connect(o->get_medium_button(), SIGNAL(clicked()), p, SLOT(insert_medium()));
    connect(o->get_large_button(), SIGNAL(clicked()), p, SLOT(insert_big()));

    if (c == n_ele) {
      r++;
      c = 1;
    } else {
      c++;
    }
  }
}

void QGridShow::add_product(QStackedWidgetHover *stack, int r, int c)
{
    lista_prodotti.append(stack);
    grid->addWidget(stack, r, c);
}
