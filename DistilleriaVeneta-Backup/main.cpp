#include <QApplication>
#include <QDebug>

#include "./Utilities/deep_ptr.hpp"
#include "./Utilities/u_vector.hpp"
#include "controller.h"
#include "model.h"
#include "view.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  model m;
  controller c(&m);

  view w(&c);
  c.link_view(&w);

  w.show();
  return a.exec();
}
