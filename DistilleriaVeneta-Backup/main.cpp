#include <QApplication>

#include "controller.h"
#include "model.h"
#include "view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  model m(":/data/data.json");
  controller c;
  view w;

  c.set_model(&m);
  c.set_view(&w);
  w.set_controller(&c);
  std::cout << &c << std::endl;
  w.show();

  w.setWindowIcon(QIcon(":/icon/icon.png"));

  return a.exec();
}
