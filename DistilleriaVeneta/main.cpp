#include <QApplication>

#include "./Utilities/deep_ptr.hpp"
#include "./Utilities/u_vector.hpp"
#include "view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  controller c;
  model m;


  view w;

  c.link_view(&w);
  c.link_model(&m);
  w.set_controller(&c);

  w.show();

  return a.exec();
}
