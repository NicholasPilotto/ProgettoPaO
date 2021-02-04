#include "view.h"

void view::add_menu_bar(QVBoxLayout* main_layout) {
  QMenuBar* menu_bar = new QMenuBar(this);
  QMenu* file;
  QMenu* filters;
  QMenu* colours;
  QMenu* alcohols;
  QMenu* codes;
  QMenu* flavors;
  file = new QMenu("File", menu_bar);
  filters = new QMenu("Filtri", menu_bar);
  colours = new QMenu("Colore", filters);
  alcohols = new QMenu("Contenuto Alcolico", filters);
  codes = new QMenu("Codice", filters);
  flavors = new QMenu("Gusto", filters);

  menu_bar->addMenu(file);
  menu_bar->addMenu(filters);
  filters->addMenu(colours);
  filters->addMenu(alcohols);
  filters->addMenu(codes);
  filters->addMenu(flavors);

  file->addAction(new QAction("Aggiungi Prodotto", file));
  /*    file->addAction(new QAction("Modify product", file));
    file->addAction(new QAction("Remove product", file));*/
  file->addAction(new QAction("Chiudi", file));

  // Colours
  colours->addAction(new QAction("Giallo", colours));
  colours->addAction(new QAction("Rosso", colours));
  colours->addAction(new QAction("Rosa", colours));
  colours->addAction(new QAction("Marrone", colours));
  colours->addAction(new QAction("Nero", colours));
  colours->addAction(new QAction("Violetto", colours));
  colours->addAction(new QAction("Bianco", colours));
  colours->addAction(new QAction("Verde", colours));
  colours->addAction(new QAction("Bianco Trasparente", colours));
  colours->addAction(new QAction("Giallo Trasparente", colours));

  /*
  Alcohols incompleto
  alcohols->addAction();
  */

  /*
  Codes incompleto
  codes->addAction(new QAction());
  */

  //Flavors incompleto
  flavor_actions();
  flavors->addAction(new QAction("Limone", colours));
  flavors->addAction(new QAction("Nocciola", colours));
  flavors->addAction(new QAction("Caffè", colours));
  flavors->addAction(new QAction("Liquirizia", colours));
  flavors->addAction(new QAction("Cioccolato", colours));
  flavors->addAction(new QAction("Uovo", colours));
  flavors->addAction(new QAction("Rum", colours));
  flavors->addAction(new QAction("Panna", colours));
  flavors->addAction(new QAction("Fragola", colours));
  flavors->addAction(new QAction("Frutti di Bosco", colours));
  flavors->addAction(new QAction("Mirtillo", colours));
  flavors->addAction(new QAction("Ribes", colours));
  flavors->addAction(new QAction("Prugna", colours));
  flavors->addAction(new QAction("Miele", colours));
  flavors->addAction(new QAction("Secco", colours));
  flavors->addAction(new QAction("Fruttato", colours));
  flavors->addAction(new QAction("Amabile", colours));
  flavors->addAction(new QAction("Menta", colours));

  connect(file->actions()[1], SIGNAL(triggered()), this, SLOT(close()));

  main_layout->addWidget(menu_bar);
}

void view::flavor_actions(){
    QAction* action_lemon;
    QAction* action_halzenhut;
    QAction* action_coffee;
    QAction* action_licorice;
    QAction* action_chocolate;
    QAction* action_egg;
    QAction* action_rum;
    QAction* action_cream;
    QAction* action_strawberry;
    QAction* action_berries;
    QAction* action_blueberry;
    QAction* action_ribes;
    QAction* action_plum;
    QAction* action_honey;
    QAction* action_dry;
    QAction* action_smooth;
    QAction* action_amable;
    QAction* action_mint;

    action_lemon = new QAction("Limone");
    action_lemon->setCheckable(true);
    action_lemon->setChecked(true);

    action_halzenhut = new QAction("Nocciola");
    action_halzenhut->setCheckable(true);
    action_halzenhut->setChecked(true);

    action_coffee = new QAction("Caffè");
    action_coffee->setCheckable(true);
    action_coffee->setChecked(true);

    action_licorice =new QAction("Liquirizia");
    action_licorice->setCheckable(true);
    action_licorice->setChecked(true);

    action_chocolate = new QAction("Cioccolato");
    action_chocolate->setCheckable(true);
    action_chocolate->setChecked(true);

    action_egg = new QAction("Uovo");
    action_egg->setCheckable(true);
    action_egg->setChecked(true);

    action_rum = new QAction("Rum");
    action_rum->setCheckable(true);
    action_rum->setChecked(true);

    action_cream = new QAction("Panna");
    action_cream->setCheckable(true);
    action_cream->setChecked(true);

    action_strawberry = new QAction("Fragola");
    action_strawberry->setCheckable(true);
    action_strawberry->setChecked(true);

    action_berries = new QAction("Frutti di Bosco");
    action_berries->setCheckable(true);
    action_berries->setChecked(true);

    action_blueberry = new QAction("Mirtillo");
    action_blueberry->setCheckable(true);
    action_blueberry->setChecked(true);

    action_ribes = new QAction("Ribes");
    action_ribes->setCheckable(true);
    action_ribes->setChecked(true);

    action_plum = new QAction("Prugna");
    action_plum->setCheckable(true);
    action_plum->setChecked(true);

    action_honey = new QAction("Miele");
    action_honey->setCheckable(true);
    action_honey->setChecked(true);

    action_dry = new QAction("Secco");
    action_dry->setCheckable(true);
    action_dry->setChecked(true);

    action_smooth = new QAction("Fruttato");
    action_smooth->setCheckable(true);
    action_smooth->setChecked(true);

    action_amable = new QAction("Amabile");
    action_amable->setCheckable(true);
    action_amable->setChecked(true);

    action_mint = new QAction("Menta");
    action_mint->setCheckable(true);
    action_mint->setChecked(true);

}

//SetEnabled enable-disable
//SetShortcut

view::view(QWidget* parent) : QWidget(parent) {
  QVBoxLayout* main_layout = new QVBoxLayout;

  add_menu_bar(main_layout);

  add_filter_buttons(main_layout);

  add_receipt_buttons(main_layout);

  main_layout->setSpacing(0);
  setLayout(main_layout);
  resize(QSize(1024, 720));
}

void view::show_warning(const QString& message) {
    QDialog* dialog = new QDialog(this);

    dialog->setLayout(new QHBoxLayout);
    dialog->layout()->addWidget(new QLabel(message, dialog));
    dialog->layout()->setAlignment(Qt::AlignCenter);
    dialog->setMinimumWidth(120);
    dialog->setMaximumWidth(500);

    dialog->show();
}

void view::add_filter_buttons(QVBoxLayout* main_layout){
    QHBoxLayout* filter_buttons = new QHBoxLayout;

    grappa_button = new QPushButton("Grappa");
    liquor_button = new QPushButton("Liquore");
    cream_button = new QPushButton("Crema");

    filter_buttons->addWidget(grappa_button);
    filter_buttons->addWidget(liquor_button);
    filter_buttons->addWidget(cream_button);
    filter_buttons->setSpacing(150);
    filter_buttons->setContentsMargins(20,0,20,0);

    main_layout->addLayout(filter_buttons);
}

void view::add_receipt_buttons(QVBoxLayout* main_layout){
    QHBoxLayout* receipt_buttons = new QHBoxLayout;

    pay_button = new QPushButton("Elimina");
    delete_receipt = new QPushButton("Paga");

    receipt_buttons->addWidget(pay_button);
    receipt_buttons->addWidget(delete_receipt);
    receipt_buttons->setSpacing(100);
    receipt_buttons->setContentsMargins(20,0,20,0);

    main_layout->addLayout(receipt_buttons);
}

