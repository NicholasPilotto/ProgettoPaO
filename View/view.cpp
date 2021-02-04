#include "view.h"

void view::add_menu_bar(QVBoxLayout* main_layout) {
  QMenuBar* menu_bar = new QMenuBar(this);
  QMenu* file;
  QMenu* filters;
  QMenu* colours;
  QMenu* alcohols;
  QMenu* codes;
  QMenu* flavors;  //taste(s) già utilizzato che facciamo?
  file = new Qmenu("File", menu_bar);
  filters = new QMenu("Filters", menu_bar);

  menu_bar->addMenu(file);
  menu_bar->addMenu(filters);
  filters->addMenu(colours);
  filters->addMenu(alcohols);
  filters->addMenu(codes);
  filters->addMenu(flavors);

  file->addAction(new QAction("Add product", file));
  /*    file->addAction(new QAction("Modify product", file));
    file->addAction(new QAction("Remove product", file));*/
  file->addAction(new QAction("Chiudi", file));

  // Colours incompleto
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();

  /*
  Alcohols incompleto
  filters->addAction();
  */

  /*
  Codes oncompleto
  filters->addAction();
  */

  //Flavors incompleto
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();
  filters->addAction();

  main_layout->addWidget(menu_bar);
}

//SetEnabled enable-disable
//SetShotcut
