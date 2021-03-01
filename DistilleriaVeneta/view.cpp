#include "view.h"

void view::show_warning(const QString& message) {
    QDialog* dialog = new QDialog(this);

    dialog->setLayout(new QHBoxLayout);
    dialog->layout()->addWidget(new QLabel(message, dialog));
    dialog->layout()->setAlignment(Qt::AlignCenter);
    dialog->setMinimumWidth(120);
    dialog->setMaximumWidth(500);

    dialog->show();
}

void view::add_menu_bar(QVBoxLayout* main_layout) {

  menu_bar = new QMenuBar(this);

  QMenu* file;
  QMenu* filters;
  QMenu* alcohols;
  //QAction* codes;
  QMenu* colours;
  QMenu* flavors;

  file = new QMenu("File", menu_bar);
  filters = new QMenu("Filtri", menu_bar);
  colours = new QMenu("Colore", filters);
  alcohols = new QMenu("Contenuto Alcolico", filters);
  //codes = new QAction("Codice", filters);
  flavors = new QMenu("Gusto", filters);

  menu_bar->addMenu(file);
  menu_bar->addMenu(filters);
  filters->addMenu(alcohols);
  //filters->addAction(codes);
  filters->addMenu(colours);
  filters->addMenu(flavors);

  //Da non fare
  //file->addAction(new QAction("Aggiungi Prodotto", file));
  /*    file->addAction(new QAction("Modify product", file));
    file->addAction(new QAction("Remove product", file));*/

    QAction* close_action = new QAction("Chiudi", file);
    const QKeySequence* closing = new QKeySequence("Ctrl+Q");
    close_action->setShortcut(*closing);
    file->addAction(close_action);

  //Alcohols incompleto
    //Si può risolvere con Qlistview(non utilizzata per il momento)
  //Problema di non contemporaneità
  QAction* cresc = new QAction("Ordine Crescente", alcohols);
  QAction* desc = new QAction("Ordine Decrescente", alcohols);
  cresc->setCheckable(true);
  cresc->setChecked(true);
  desc->setCheckable(true);
  desc->setChecked(false);
  alcohols->addAction(cresc);
  alcohols->addAction(desc);


  // Colours
  /*u_vector<QString> colours_actions = {"Giallo","Rosso","Rosa","Marrone","Nero","Violetto","Bianco","Verde","Bianco Trasparente","Giallo Trasparente",};
  for(auto cit = colours_actions.const_begin(); cit != colours_actions.const_end(); cit++){
      QAction* action = new QAction(*cit, colours);
      action->setCheckable(true);
      action->setChecked(false);
      colours->addAction(action);
  }*/

  //Prova colours
  std::vector<QString> colours_actions = {"Giallo","Rosso","Rosa","Marrone","Nero","Violetto","Bianco","Verde","Bianco Trasparente","Giallo Trasparente",};
    for(auto cit = colours_actions.cbegin(); cit != colours_actions.cend(); cit++){
        QAction* action = new QAction(*cit, colours);
        action->setCheckable(true);
        action->setChecked(false);
        colours->addAction(action);
    }

  //Flavors incompleto
  /*u_vector<QString> flavors_actions = {"Nocciola","Caffè","Liquirizia","Cioccolato","Uovo","Rum","Panna","Fragola","Frutti di Bosco","Mirtillo","Ribes","Prugna","Miele","Secco","Fruttato","Amabile","Menta"};
  for(auto cit = flavors_actions.const_begin(); cit != flavors_actions.const_end(); cit++){
      QAction* action = new QAction(*cit, flavors);
      action->setCheckable(true);
      action->setChecked(false);
      flavors->addAction(action);
  }*/

    std::vector<QString> flavors_actions = {"Nocciola","Caffè","Liquirizia","Cioccolato","Uovo","Rum","Panna","Fragola","Frutti di Bosco","Mirtillo","Ribes","Prugna","Miele","Secco","Fruttato","Amabile","Menta"};
    for(auto cit = flavors_actions.cbegin(); cit != flavors_actions.cend(); cit++){
        QAction* action = new QAction(*cit, flavors);
        action->setCheckable(true);
        action->setChecked(false);
        flavors->addAction(action);
    }


  connect(file->actions()[0], SIGNAL(triggered()), this, SLOT(close()));

  main_layout->addWidget(menu_bar);
}

void view::add_title(QVBoxLayout* main_layout){

    QLabel* title = new QLabel("Distilleria Veneta");

    title->setAlignment(Qt::AlignCenter);

    main_layout->addWidget(title);
}
/*
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
*/
void view::add_grid(QHBoxLayout* main_object_layout){
    QVBoxLayout* left_app = new QVBoxLayout;

    QLabel* products_title = new QLabel("Prodotti");
    products_title->setAlignment(Qt::AlignCenter);
    products_title->setContentsMargins(0,0,0,20);

    QListWidget* table_list = new QListWidget;
    for(int i=0; i<50; i++)
    table_list->addItem("Prova1");

    left_app->addWidget(products_title);
    left_app->addWidget(table_list);
    left_app->addLayout(add_filter_buttons());
    left_app->setSpacing(0);
    left_app->setContentsMargins(20,20,20,20);

    main_object_layout->addLayout(left_app);
}


//Utilizzare il ciclo for per l'inizializzazione
void view::add_receipt(QHBoxLayout* main_object_layout){
    QVBoxLayout* right_app = new QVBoxLayout;

    //Receipt Title

    QLabel* receipt_title = new QLabel("Scontrino");
    receipt_title->setAlignment(Qt::AlignCenter);
    receipt_title->setContentsMargins(0,0,0,20);

    //Receipt Menu

    QHBoxLayout* receipt_menu = new QHBoxLayout;
    QLabel* name_receipt = new QLabel("Nome");
    name_receipt->setAlignment(Qt::AlignCenter);
    name_receipt->setContentsMargins(0,0,0,20);
    QLabel* size_receipt = new QLabel("Dimensione");
    size_receipt->setAlignment(Qt::AlignCenter);
    size_receipt->setContentsMargins(0,0,0,20);
    QLabel* quantity_receipt = new QLabel("Quantità");
    quantity_receipt->setAlignment(Qt::AlignCenter);
    quantity_receipt->setContentsMargins(0,0,0,20);
    QLabel* price_receipt = new QLabel("Prezzo");
    price_receipt->setAlignment(Qt::AlignCenter);
    price_receipt->setContentsMargins(0,0,0,20);

    receipt_menu->addWidget(name_receipt);
    receipt_menu->addWidget(size_receipt);
    receipt_menu->addWidget(quantity_receipt);
    receipt_menu->addWidget(price_receipt);

    //List

    QListWidget* receipt_list = new QListWidget;
    for(int i=0; i<50; i++)
    receipt_list->addItem("Prova1");

    //Right app

    right_app->addWidget(receipt_title);

    right_app->addLayout(receipt_menu);

    right_app->addWidget(receipt_list);
    right_app->addLayout(add_receipt_buttons());

    right_app->setSpacing(0);
    right_app->setContentsMargins(20,20,20,20);

    main_object_layout->addLayout(right_app);
}

//SetShortcut

QHBoxLayout* view::add_filter_buttons(){
    QHBoxLayout* filter_buttons = new QHBoxLayout;

    grappa_button = new QPushButton("Grappa");
    liquor_button = new QPushButton("Liquore");
    cream_button = new QPushButton("Crema");

    filter_buttons->addWidget(grappa_button);
    filter_buttons->addWidget(liquor_button);
    filter_buttons->addWidget(cream_button);
    filter_buttons->setSpacing(50);
    filter_buttons->setContentsMargins(50,20,50,20);

    return filter_buttons;
}

QHBoxLayout* view::add_receipt_buttons(){
    QHBoxLayout* receipt_buttons = new QHBoxLayout;

    pay_button = new QPushButton("Elimina");
    delete_receipt = new QPushButton("Paga");

    receipt_buttons->addWidget(pay_button);
    receipt_buttons->addWidget(delete_receipt);
    receipt_buttons->setSpacing(50);
    receipt_buttons->setContentsMargins(50,20,50,20);

    return receipt_buttons;
}

view::view(QWidget* parent) : QWidget(parent) {
  QVBoxLayout* main_layout = new QVBoxLayout;
  QHBoxLayout* main_object_layout = new QHBoxLayout;

  add_menu_bar(main_layout);

  add_title(main_layout);

  add_grid(main_object_layout);

  add_receipt(main_object_layout);

  main_layout->addLayout(main_object_layout);

  main_layout->setSpacing(20);
  setLayout(main_layout);
  resize(QSize(1024, 720));
}
