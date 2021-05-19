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

void QGridShow::refresh_grid(const u_vector<deep_ptr<product>>& _products) {
  clear_grid();
  int r = 1;
  int c = 1;
  const int n_ele = 3;
  u_vector<deep_ptr<product>>::const_iterator it = _products.const_begin();
  u_vector<deep_ptr<product>>::const_iterator end = _products.const_end();

  for (; it != end; it++) {
    QProduct* p = new QProduct(*it);
    QOverlay* o = new QOverlay();
    stack = new QStackedWidgetHover(p, o);

    grid->addWidget(stack, r, c);

    if (c == n_ele) {
      r++;
      c = 1;
    } else {
      c++;
    }
  }
}
