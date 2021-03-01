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

  //Alcohols incompleto


  // Colours
  u_vector<QString> colours_actions = {"Giallo","Rosso","Rosa","Marrone","Nero","Violetto","Bianco","Verde","Bianco Trasparente","Giallo Trasparente",};
  for(auto cit = colours_actions.const_begin(); cit != colours_actions.const_end(); cit++){
      QAction* action = new QAction(*cit, flavors);
      action->setCheckable(true);
      action->setChecked(false);
      colours->addAction(action);
  }

  //Flavors incompleto
  u_vector<QString> flavors_actions = {"Nocciola","Caffè","Liquirizia","Cioccolato","Uovo","Rum","Panna","Fragola","Frutti di Bosco","Mirtillo","Ribes","Prugna","Miele","Secco","Fruttato","Amabile","Menta"};
  for(auto cit = flavors_actions.const_begin(); cit != flavors_actions.const_end(); cit++){
      QAction* action = new QAction(*cit, flavors);
      action->setCheckable(true);
      action->setChecked(false);
      flavors->addAction(action);
  }


  connect(file->actions()[1], SIGNAL(triggered()), this, SLOT(close()));

  main_layout->addWidget(menu_bar);
}

void view::add_title(QVBoxLayout* main_layout){

    QLabel* title = new QLabel("Distilleria Veneta");

    title->setAlignment(Qt::AlignCenter);

    main_layout->addWidget(title);
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
