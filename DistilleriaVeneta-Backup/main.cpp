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
  controller c;
  view w;

  c.link_view(&w);
  c.link_model(&m);
  w.set_controller(&c);
  w.show();
  w.add_elements();

  return a.exec();
}
