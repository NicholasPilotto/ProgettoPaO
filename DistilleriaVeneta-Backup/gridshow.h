#ifndef GRIDSHOW_H
#define GRIDSHOW_H
#include <QFrame>
#include <QGridLayout>
#include <QScrollArea>
#include <QStackedWidget>
#include <QWidget>
#include <functional>

#include "Hierarchy/product.h"
#include "Utilities/deep_ptr.hpp"
#include "Utilities/u_vector.hpp"
#include "overlay.h"
#include "qproduct.h"
#include "qstackedwidgethover.h"

class QGridShow : public QWidget {
  Q_OBJECT
 private:
  QVBoxLayout* main_layout;
  QScrollArea* product_area;
  QFrame* contenitore;
  QGridLayout* grid;
  QList<QStackedWidgetHover*> lista_prodotti;
  void clear_grid();

 public:
  QGridShow(QWidget* parent = nullptr);
  void refresh_grid(const u_vector<deep_ptr<product>>& _products, std::function<void(const deep_ptr<product>&)>);
  void add_product(QStackedWidgetHover*, int, int);
};

#endif  // GRIDSHOW_H
