#include "view.h"

void view::add_menu_bar(QVBoxLayout* main_layout) {

    menu_bar = new QMenuBar(this);

    file = new QMenu("File", menu_bar);
    filters = new QMenu("Filtri", menu_bar);

    alcohols = new QMenu("Contenuto Alcolico", filters);
    colors = new QMenu("Colore", filters);
    flavors = new QMenu("Gusto", filters);

    menu_bar->addMenu(file);
    menu_bar->addMenu(filters);

    filters->addMenu(alcohols);
    filters->addMenu(colors);
    filters->addMenu(flavors);

    // Azioni in file

    close_action = new QAction("Chiudi", file);
    const QKeySequence* closing = new QKeySequence("Ctrl+Q");
    close_action->setShortcut(*closing);
    file->addAction(close_action);

    // Azioni in Contenuto Alcolico

    QAction* cresc = new QAction("Ordine Crescente", alcohols);
    QAction* desc = new QAction("Ordine Decrescente", alcohols);
    cresc->setCheckable(true);
    cresc->setChecked(true);
    desc->setCheckable(true);
    desc->setChecked(false);
    alcohols->addAction(cresc);
    alcohols->addAction(desc);

    // Azioni in Colore

    u_vector<QString> colours_actions = {
          "Giallo",
          "Rosso",
          "Rosa",
          "Marrone",
          "Nero",
          "Violetto",
          "Bianco",
          "Verde",
          "Bianco Trasparente",
          "Giallo Trasparente",
      };

      for (auto cit = colours_actions.const_begin(); cit != colours_actions.const_end(); cit++) {
        QAction* action = new QAction(*cit,colors);
        action->setCheckable(true);
        action->setChecked(false);
        colors->addAction(action);
      }

      // Azioni in gusto

      u_vector<QString> flavors_actions = {
          "Nocciola",
          "Caffè",
          "Liquirizia",
          "Cioccolato",
          "Uovo",
          "Rum",
          "Panna",
          "Fragola",
          "Frutti di Bosco",
          "Mirtillo",
          "Ribes",
          "Prugna",
          "Miele",
          "Secco",
          "Fruttato",
          "Amabile",
          "Menta",
      };

      for (auto cit = flavors_actions.const_begin(); cit != flavors_actions.const_end(); cit++) {
        QAction* action = new QAction(*cit, flavors);
        action->setCheckable(true);
        action->setChecked(false);
        flavors->addAction(action);
      }

      // Aggiunta del menù

      main_layout->addWidget(menu_bar);

}

void view::add_title(QVBoxLayout* layout, const QString& message) {

      title = new QLabel(message,this);
      title->setAlignment(Qt::AlignCenter);
      title->setContentsMargins(5, 5, 5, 5);

      layout->addWidget(title);

}

QHBoxLayout* view::add_filter_buttons() {

    filter_buttons = new QHBoxLayout(this);

    // Creazione bottoni

    grappa_button = new QPushButton("Grappa");
    liquor_button = new QPushButton("Liquore");
    cream_button = new QPushButton("Crema");

    // Aggiunta bottoni

    filter_buttons->addWidget(grappa_button);
    filter_buttons->addWidget(liquor_button);
    filter_buttons->addWidget(cream_button);

    // Ritorno layout

    filter_buttons->setSpacing(50);
    filter_buttons->setContentsMargins(50, 20, 50, 20);
    return filter_buttons;

}

void view::add_grid(QHBoxLayout* object_layout) {

    left_app = new QVBoxLayout(this);

    // Aggiunta sottotitolo

    add_title(left_app, "Prodotti");

    // Creazione e aggiunta griglia vuota

    product_area = new QGridShow();
    left_app->addWidget(product_area);

    // Aggiunta pulsanti di filtro veloci

    left_app->addLayout(add_filter_buttons());

    // Aggiunta parte sinistra al layout orizzontale

    left_app->setSpacing(0);
    left_app->setContentsMargins(20, 20, 20, 20);
    object_layout->addLayout(left_app);

}

QHBoxLayout* view::add_receipt_buttons() {

    receipt_buttons = new QHBoxLayout(this);

    // Creazione bottoni

    delete_receipt = new QPushButton("Elimina");
    pay_button = new QPushButton("Paga");

    // Aggiunta bottoni

    receipt_buttons->addWidget(delete_receipt);
    receipt_buttons->addWidget(pay_button);

    // Ritorno layout

    receipt_buttons->setSpacing(50);
    receipt_buttons->setContentsMargins(100, 20, 100, 20);
    return receipt_buttons;

}

QGridLayout* view::add_total() {
    resoconto = new QGridLayout();

    resoconto->addWidget(new QLabel("TOTALE:"), 0, 0, 1, 1, Qt::AlignLeft);
//    resoconto->addWidget(new QLabel("€ -.--"), 0, 1, 1, 1, Qt::AlignRight);
    resoconto->addWidget(new QLabel("Tasse:"), 1, 0, 1, 1, Qt::AlignLeft);
//    resoconto->addWidget(new QLabel("€ -.--"), 1, 1, 1, 1, Qt::AlignRight);

    return resoconto;
}

void view::add_receipt(QHBoxLayout* object_layout) {

    right_app = new QVBoxLayout(this);

    // Aggiungi sottotitolo

    add_title(right_app, "Scontrino");

    // Creazione e aggiunta della tabella

    receipt_area = new QReceiptShow();
    right_app->addWidget(receipt_area);

    // Aggiunta del totale dello scontrino

    right_app->addLayout(add_total());

    // Aggiunta dei pulsanti per lo scontrino

    right_app->addLayout(add_receipt_buttons());

    // Aggiunta layout

    right_app->setSpacing(0);
    right_app->setContentsMargins(20, 20, 20, 20);
    object_layout->addLayout(right_app);

}

void view::update_json() {

    auto aux = presenter->get_products_json();
    product_area->refresh_grid(aux);

}



view::view(QWidget* parent) : QWidget(parent) {

    main_layout = new QVBoxLayout(this);
    object_layout = new QHBoxLayout();

    // Aggiunta della barra dei menù

    add_menu_bar(main_layout);

    // Aggiunta del titolo

    add_title(main_layout, "Distilleria Veneta");

    // Creazione  layout orizzontale con aggiunta delle 2 tabelle (left-to-right)

    add_grid(object_layout);
    add_receipt(object_layout);

    // Aggiunta del layout al main e setto il main

    main_layout->addLayout(object_layout);
    main_layout->setSpacing(20);
    setLayout(main_layout);

}

void view::set_controller(controller* c) {

    // Controller viene settato

    presenter = c;

    // Update del file json

    update_json();

    // Segnali

    // Segnali della Menubar
    connect(file->actions()[0], SIGNAL(triggered()), this, SLOT(close()));

    // Segnali right_app
    connect(pay_button, SIGNAL(clicked()), this, SLOT(pay_banner()));

}

void view::show_warning(const QString& message) {

  // Creazione dialog

  QDialog* dialog = new QDialog(this);

  // Aggiunta Label e show

  dialog->setLayout(new QHBoxLayout);
  dialog->layout()->addWidget(new QLabel(message, dialog));
  dialog->layout()->setAlignment(Qt::AlignCenter);
  dialog->setMinimumWidth(120);
  dialog->setMaximumWidth(500);

  dialog->show();
  
}

// SLOTS

void view::pay_banner() {
    pay_dialog = new QDialog(this);

    QGridLayout* datas = new QGridLayout(pay_dialog);

    QLineEdit* pay_customer = new QLineEdit(pay_dialog);
    pay_customer->setValidator(new QDoubleValidator(0, INT16_MAX, 2, this));

    QPushButton* ok_button = new QPushButton("OK",pay_dialog);
    QPushButton* annulla_button = new QPushButton("Annulla",pay_dialog);

    datas->addWidget(new QLabel("Il cliente ha pagato:",pay_dialog), 0, 0, 1, 1);
    datas->addWidget(pay_customer, 0, 1, 1, 1);
    datas->addWidget(new QLabel("Totale dovuto: ",pay_dialog), 1, 0, 1, 1);
    datas->addWidget(new QLabel(QString::number(presenter->total_price(), 'f', 2) + " €",pay_dialog), 1, 1, 1, 1, Qt::AlignRight);
    datas->addWidget(new QLabel("Resto: ",pay_dialog), 2, 0, 1, 1);
    datas->addWidget(new QLabel(QString::number(pay_customer->text().toDouble() - presenter->total_price(), 'f', 2) + " €",pay_dialog), 2, 1, 1, 1, Qt::AlignRight);
    datas->addWidget(annulla_button,3,0,1,1,Qt::AlignLeft);
    datas->addWidget(ok_button,3,1,1,1,Qt::AlignRight);

    pay_dialog->setLayout(datas);

    pay_dialog->layout()->setAlignment(Qt::AlignCenter);
    pay_dialog->setMinimumWidth(300);
    pay_dialog->setMinimumHeight(175);
    // chiamare elimina tutto poichè il tutto viene pagato e o scontrino ritorna a 0 elementi (SIGNAL E SLOT)

    pay_dialog->show();
}