#include "view.h"

void view::add_menu_bar(QVBoxLayout* main_layout) {

  menu_bar = new QMenuBar(this);

  QMenu* file;
  QMenu* filters;
  QAction* alcohols;
  QAction* codes;
  QMenu* colours;
  QMenu* flavors;

  file = new QMenu("File", menu_bar);
  filters = new QMenu("Filtri", menu_bar);
  colours = new QMenu("Colore", filters);
  alcohols = new QAction("Contenuto Alcolico", filters);
  codes = new QAction("Codice", filters);
  flavors = new QMenu("Gusto", filters);

  menu_bar->addMenu(file);
  menu_bar->addMenu(filters);
  filters->addAction(alcohols);
  filters->addAction(codes);
  filters->addMenu(colours);
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


  //Alcohols incompleto

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

void view::add_title(QVBoxLayout* main_layout){

    QLabel* title = new QLabel("Distilleria Veneta");

    title->setAlignment(Qt::AlignCenter);

    main_layout->addWidget(title);
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

void view::upload_grid_item() {
    QGridLayout* upload = new QGridLayout;

    QLabel* name_product = new QLabel("Nome Prodotto:");
    QLineEdit* name_line = new QLineEdit;

    QLabel* alc = new QLabel("Contenuto Alcolico:");
    QLineEdit* alc_line = new QLineEdit;

    QLabel* colore = new QLabel("Colore:");
    QLineEdit* colore_line = new QLineEdit;

    QLabel* path = new QLabel("Path:");
    QLineEdit* path_line = new QLineEdit(add_dialog_choice());
    QPushButton* path_button = new QPushButton;

    QPushButton* confirm = new QPushButton;
    QPushButton* undo = new QPushButton;

    upload->addWidget(name_product,0,0);
    upload->addWidget(name_line,0,1);
    upload->addWidget(alc,1,0);
    upload->addWidget(alc_line,1,1);
    upload->addWidget(colore,2,0);
    upload->addWidget(colore_line,2,1);
    upload->addWidget(path,3,0);
    upload->addWidget(path_line,3,1);
    upload->addWidget(path_button,3,2);
    upload->addWidget(confirm,4,0,1,1);
    upload->addWidget(undo,4,1,1,2,Qt::AlignRight);
}

QString view::add_dialog_choice(){
    QString fileName = QFileDialog::getOpenFileName(
            this, tr("Apri il file"), "/home", tr("Immagini (*.png *.jpg)"));

    if (fileName == "")
        throw std::runtime_error("Nessun file scelto: aggiunta annullata");

    return fileName;
}
/*
void view::add_grid(QVBoxLayout* main_layout){
    QVBoxLayout* left_app = new QVBoxLayout;
    QVBoxLayout* product_layout = new QVBoxLayout;

    product_grid->addWidget(product_layout,0,0);
    product_grid->addLayout(product_layout,0,1);
    product_grid->addLayout(product_layout,0,2);
    product_grid->addLayout(product_layout,0,3);
    product_grid->addLayout(product_layout,1,0);
    product_grid->addLayout(product_layout,1,1);
    product_grid->addLayout(product_layout,1,2);
    product_grid->addLayout(product_layout,1,3);
    product_grid->addLayout(product_layout,2,0);
    product_grid->addLayout(product_layout,2,1);
    product_grid->addLayout(product_layout,2,2);
    product_grid->addLayout(product_layout,2,3);
    product_grid->addLayout(product_layout,3,0);
    product_grid->addLayout(product_layout,3,1);
    product_grid->addLayout(product_layout,3,2);
    product_grid->addLayout(product_layout,3,3);
    product_grid->addWidget(grid_scroll,0,4);



    left_app->addLayout(product_grid);
    left_app->addLayout(add_filter_buttons());

    main_layout->addLayout(left_app);
}
*/
//SetEnabled enable-disable
//SetShortcut

view::view(QWidget* parent) : QWidget(parent) {
  QVBoxLayout* main_layout = new QVBoxLayout;

  add_menu_bar(main_layout);

  add_title(main_layout);

  //add_grid(main_layout);

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

QHBoxLayout* view::add_filter_buttons(){
    QHBoxLayout* filter_buttons = new QHBoxLayout;

    grappa_button = new QPushButton("Grappa");
    liquor_button = new QPushButton("Liquore");
    cream_button = new QPushButton("Crema");

    filter_buttons->addWidget(grappa_button);
    filter_buttons->addWidget(liquor_button);
    filter_buttons->addWidget(cream_button);
    filter_buttons->setSpacing(150);
    filter_buttons->setContentsMargins(20,0,20,0);

    return filter_buttons;
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
/*
QProduct::QProduct(QWidget* parent) : QWidget(parent){
    QVBoxLayout* first_layout = new QVBoxLayout;

    image = new QFrame;
    name_prod = new QLabel(QString::fromStdString(get_name));

    first_layout->addWidget(image);
    first_layout->addWidget(name_prod, Qt::AlignCenter);
}
*/
