#include "view.h"
//Nuova versione
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


  QAction* add_product_menu = new QAction("Aggiungi Prodotto", file);
  const QKeySequence* adding = new QKeySequence("Ctrl+A");
  add_product_menu->setShortcut(*adding);
  file->addAction(add_product_menu);

  QAction* modify_product_menu = new QAction("Modifica Prodotto", file);
  const QKeySequence* modifing = new QKeySequence("Ctrl+M");
  modify_product_menu->setShortcut(*modifing);
  file->addAction(modify_product_menu);

  QAction* remove_product_menu = new QAction("Remove product", file);
  const QKeySequence* removing = new QKeySequence("Ctrl+R");
  remove_product_menu->setShortcut(*removing);
  file->addAction(remove_product_menu);

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
  u_vector<QString> colours_actions = {"Giallo","Rosso","Rosa","Marrone","Nero","Violetto","Bianco","Verde","Bianco Trasparente","Giallo Trasparente",};
  for(auto cit = colours_actions.const_begin(); cit != colours_actions.const_end(); cit++){
      QAction* action = new QAction(*cit, colours);
      action->setCheckable(true);
      action->setChecked(false);
      colours->addAction(action);
  }

  //Flavors incompleto
  u_vector<QString> flavors_actions(17,17);
  flavors_actions = {"Nocciola","Caffè","Liquirizia","Cioccolato","Uovo","Rum","Panna","Fragola","Frutti di Bosco","Mirtillo","Ribes","Prugna","Miele","Secco","Fruttato","Amabile","Menta"};
  for(auto cit = flavors_actions.const_begin(); cit != flavors_actions.const_end(); cit++){
      QAction* action = new QAction(*cit, flavors);
      action->setCheckable(true);
      action->setChecked(false);
      flavors->addAction(action);
  }

  connect(file->actions()[3], SIGNAL(triggered()), this, SLOT(close()));

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
*/
QString view::add_dialog_choice(){
    QString fileName = QFileDialog::getOpenFileName(
            this, tr("Apri il file"), "/home", tr("Immagini (*.png *.jpg)"));

    if (fileName == "")
        throw std::runtime_error("Nessun file scelto: aggiunta annullata");

    return fileName;
}

void view::add_grid(QHBoxLayout* main_object_layout){
    QVBoxLayout* left_app = new QVBoxLayout;

    QLabel* products_title = new QLabel("Prodotti");
    products_title->setContentsMargins(0,20,0,20);
    products_title->setAlignment(Qt::AlignCenter);

    /*QTableView* table_list = new QTableView;
    table_list->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    table_list-
*/

    left_app->addWidget(products_title);

    QScrollArea* product_area = new QScrollArea;
    product_area->setMinimumSize(QSize(500,500));
    product_area->setWidgetResizable(true);
    product_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    QFrame* contenitore = new QFrame();

    QGridLayout* layout = new QGridLayout();

    contenitore->setLayout(layout);

    product_area->setWidget(contenitore);


    int r = 1, c = 1;

    for(int i = 0; i < 9; i++) {
        QProduct* p = new QProduct();

        layout->addWidget(p,r,c);

        if(c == 3) {
            r++;
            c = 1;
        } else
            c++;
    }

    /*
    QFrame* product_background = new QFrame;
    QVBoxLayout* product_list = new QVBoxLayout;
    product_area->setWidget(product_background);
    product_background->setLayout(product_list);
    QHBoxLayout* line = new QHBoxLayout;
    for(int i=0; i<3; i++)
        line->addWidget(new QProduct);
    product_list->addLayout(line);
    QHBoxLayout* line2 = new QHBoxLayout;
    for(int i=0; i<3; i++)
        line2->addWidget(new QProduct);
    product_list->addLayout(line2);
    QHBoxLayout* line3 = new QHBoxLayout;
    for(int i=0; i<3; i++)
        line3->addWidget(new QProduct);
    product_list->addLayout(line3);
    */


    left_app->addWidget(product_area);
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
    receipt_title->setContentsMargins(0,20,0,20);

    //Receipt Menu

    QHBoxLayout* receipt_menu = new QHBoxLayout;
    QLabel* name_receipt = new QLabel("Nome");
    name_receipt->setAlignment(Qt::AlignCenter);
    name_receipt->setContentsMargins(40,20,0,20);
    QLabel* size_receipt = new QLabel("Dimensione");
    size_receipt->setAlignment(Qt::AlignCenter);
    size_receipt->setContentsMargins(50,20,0,20);
    QLabel* quantity_receipt = new QLabel("Quantità");
    quantity_receipt->setAlignment(Qt::AlignCenter);
    quantity_receipt->setContentsMargins(50,20,0,20);
    QLabel* price_receipt = new QLabel("Prezzo");
    price_receipt->setAlignment(Qt::AlignCenter);
    price_receipt->setContentsMargins(0,20,0,20);

    receipt_menu->addWidget(name_receipt);
    receipt_menu->addWidget(size_receipt);
    receipt_menu->addWidget(quantity_receipt);
    receipt_menu->addWidget(price_receipt);

    //List

    QScrollArea* receipt_area = new QScrollArea;
    receipt_area->setMinimumSize(QSize(500,500));
    receipt_area->setWidgetResizable(true);
    receipt_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    QFrame* receipt_background = new QFrame;
    QVBoxLayout* receipt_list = new QVBoxLayout;
    receipt_area->setWidget(receipt_background);
    receipt_background->setLayout(receipt_list);
    for(int i=0;i<50;i++)
    receipt_list->addWidget(new QReceiptitem);



    //Right app

    right_app->addWidget(receipt_title);

    right_app->addLayout(receipt_menu);

    right_app->addWidget(receipt_area);
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
    receipt_buttons->setContentsMargins(100,20,100,20);

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
}

/*
product::product (QFrame* parent) : QFrame(parent) {
     QVBoxLayout* mainlayout = new QVBoxLayout;

     img = new QLabel();
     left_widget_name = new QLabel();
     left_widget_price = new QLabel();

     img->setPixmap(QPixmap("path"));
     left_widget_name->setText("name");
     left_widget_price->setText("41");

     mainlayout->addWidget(img);
     mainlayout->addWidget(left_widget_name);
     mainlayout->addWidget(left_widget_price);

     setLayout(mainlayout);
}
*/


QProduct::QProduct(QWidget* parent) : QWidget(parent) {


    QVBoxLayout* mainlayout = new QVBoxLayout;
    QHBoxLayout* image_layout = new QHBoxLayout;
    left_widget_image = new QFrame;
    left_widget_image->setStyleSheet("background-color: rgb(50,50,50)");
    left_widget_image->setLayout(image_layout);
    //left_widget_image->layout()->setMargin(0);
    left_widget_image->layout()->setSpacing(0);
    left_widget_image->layout()->setAlignment(Qt::AlignCenter);
    left_widget_image->setMinimumSize(100, 178);
    left_widget_image->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    mainlayout->addWidget(left_widget_image, Qt::AlignCenter);
    left_widget_name = new QLabel("Liquirizia");//getname
    left_widget_name->setAlignment(Qt::AlignCenter);
    mainlayout->addWidget(left_widget_name, Qt::AlignCenter);
    left_widget_price = new QLabel("10.50");
    left_widget_price->setAlignment((Qt::AlignCenter));
    mainlayout->addWidget(left_widget_price, Qt::AlignHCenter);

    setLayout(mainlayout);
}

QReceiptitem::QReceiptitem(QWidget* parent) : QWidget(parent){
    QHBoxLayout* left_widget = new QHBoxLayout;

    left_widget_name = new QLabel("Nome Prodotto");
    left_widget_name->setAlignment(Qt::AlignCenter);
    left_widget_name->setContentsMargins(30,0,10,0);

    left_widget_dim = new QLabel("Grande"); //richiamo funzione code
    left_widget_dim->setAlignment(Qt::AlignCenter);
    left_widget_dim->setContentsMargins(50,0,60,0);

    QPushButton* minus = new QPushButton("-");

    left_widget_n_items = new QLabel(QString::number(10));
    left_widget_n_items->setAlignment(Qt::AlignCenter);
    left_widget_n_items->setContentsMargins(0,0,0,0);

    QPushButton* plus = new QPushButton("+");

    left_widget_line_price = new QLabel("€ " + QString::number(70.20));
    left_widget_line_price->setAlignment(Qt::AlignCenter);
    left_widget_line_price->setContentsMargins(30,0,0,0);

    //left_widget->addWidget(new QLabel(this));

    left_widget->addWidget(left_widget_name);
    left_widget->addWidget(left_widget_dim);
    left_widget->addWidget(minus);
    left_widget->addWidget(left_widget_n_items);
    left_widget->addWidget(plus);
    left_widget->addWidget(left_widget_line_price);

    setLayout(left_widget);
}



















