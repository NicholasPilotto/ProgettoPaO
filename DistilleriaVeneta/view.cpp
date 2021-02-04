#include "view.h"

void view::add_menu_bar(QVBoxLayout* main_layout) {
  QMenuBar* menu_bar = new QMenuBar(this);
  QMenu* file;
  QMenu* filters;
  QMenu* colours;
  QMenu* alcohols;
  QMenu* codes;
  QMenu* flavors;  //taste(s) già utilizzato che facciamo?
  file = new QMenu("File", menu_bar);
  filters = new QMenu("Filters", menu_bar);
  colours = new QMenu("Colour", filters);
  alcohols = new QMenu("Alcoholic Content", filters);
  codes = new QMenu("Code", filters);
  flavors = new QMenu("Taste", filters);

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

  // Colours
  colours->addAction(new QAction("Yellow", colours));
  colours->addAction(new QAction("Red", colours));
  colours->addAction(new QAction("Pink", colours));
  colours->addAction(new QAction("Brown", colours));
  colours->addAction(new QAction("Black", colours));
  colours->addAction(new QAction("Violet", colours));
  colours->addAction(new QAction("White", colours));
  colours->addAction(new QAction("Green", colours));
  colours->addAction(new QAction("White Trasparent", colours));
  colours->addAction(new QAction("Yellow Trasparent", colours));

  /*
  Alcohols incompleto
  alcohols->addAction();
  */

  /*
  Codes incompleto
  codes->addAction(new QAction());
  */

  //Flavors incompleto
  flavors->addAction(new QAction("Lemon", colours));
  flavors->addAction(new QAction("Halzenhut", colours));
  flavors->addAction(new QAction("Coffee", colours));
  flavors->addAction(new QAction("Licorice", colours));
  flavors->addAction(new QAction("Chocolate", colours));
  flavors->addAction(new QAction("Egg", colours));
  flavors->addAction(new QAction("Rum", colours));
  flavors->addAction(new QAction("Cream", colours));
  flavors->addAction(new QAction("Strawberry", colours));
  flavors->addAction(new QAction("berries", colours));
  flavors->addAction(new QAction("Blueberry", colours));
  flavors->addAction(new QAction("Ribes", colours));
  flavors->addAction(new QAction("Plum", colours));
  flavors->addAction(new QAction("Honey", colours));
  flavors->addAction(new QAction("Dry", colours));
  flavors->addAction(new QAction("Smooth", colours));
  flavors->addAction(new QAction("Amable", colours));
  flavors->addAction(new QAction("Mint", colours));

  connect(file->actions()[1], SIGNAL(triggered()), this, SLOT(close()));

  main_layout->addWidget(menu_bar);
}

//SetEnabled enable-disable
//SetShortcut

view::view(QWidget* parent) : QWidget(parent) {
  QVBoxLayout* main_layout = new QVBoxLayout;

  add_menu_bar(main_layout);

  main_layout->setSpacing(0);
  setLayout(main_layout);
  resize(QSize(1024, 720));
}
