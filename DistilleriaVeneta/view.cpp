#include "view.h"

#include <QDebug>

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
  // yellow, red, pink, brown, black, violet, white, green, white_trasparent, yellow_trasparent
  u_vector<QString> colours_actions = {"Giallo", "Rosso", "Rosa", "Marrone", "Nero", "Violetto", "Bianco", "Verde", "Bianco Trasparente", "Giallo Trasparente"};
  u_vector<QString>::const_iterator _color_cit = colours_actions.const_begin();
  u_vector<QString>::const_iterator _color_end = colours_actions.const_end();

  for (std::pair<u_vector<QString>::const_iterator, int> _pair = std::make_pair(_color_cit, 0); _pair.first != _color_end; _pair.first++, _pair.second++) {
    QAction* action = new QAction(*(_pair.first), colors);
    action->setCheckable(true);
    action->setObjectName(QString::number(_pair.second));
    action->setChecked(false);
    colors->addAction(action);
  }

  // Azioni in gusto

  u_vector<QString> flavors_actions = {"Limone", "Nocciola", "Caffè", "Liquirizia", "Cioccolato", "Uovo", "Rum", "Crema", "Fragola", "Frutti di bosco", "Mirtillo", "Ribes", "Prugna", "Miele", "Secco", "Smooth", "Amabile", "Menta"};

  u_vector<QString>::const_iterator _flavor_cit = flavors_actions.const_begin();
  u_vector<QString>::const_iterator _flavor_end = flavors_actions.const_end();
  for (std::pair<u_vector<QString>::const_iterator, int> _pair = std::make_pair(_flavor_cit, 10); _pair.first != _flavor_end; _pair.first++, _pair.second++) {
    QAction* action = new QAction(*(_pair.first), flavors);
    action->setObjectName(QString::number(_pair.second));
    action->setCheckable(true);
    action->setChecked(false);
    flavors->addAction(action);
  }

  // Aggiunta del menù

  main_layout->addWidget(menu_bar);
}

void view::add_title(QVBoxLayout* layout, const QString& message) {
  title = new QLabel(message, this);
  title->setAlignment(Qt::AlignCenter);
  title->setContentsMargins(5, 5, 5, 5);

  layout->addWidget(title);
}

QHBoxLayout* view::add_filter_buttons() {
  filter_buttons = new QHBoxLayout(this);

  // Creazione bottoni

  grappa_button = new QPushButton("Grappa");
  grappa_button->setObjectName("grappa");
  liquor_button = new QPushButton("Liquore");
  liquor_button->setObjectName("liquor");
  cream_button = new QPushButton("Crema");
  cream_button->setObjectName("cream");
  all_button = new QPushButton("Tutti");
  all_button->setObjectName("all");

  // Aggiunta bottoni

  filter_buttons->addWidget(grappa_button);
  filter_buttons->addWidget(liquor_button);
  filter_buttons->addWidget(cream_button);
  filter_buttons->addWidget(all_button);

  // Ritorno layout

  filter_buttons->setSpacing(30);
  filter_buttons->setContentsMargins(30, 20, 30, 20);
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

void view::add_receipt(QHBoxLayout* object_layout) {
  right_app = new QVBoxLayout(this);

  // Aggiungi sottotitolo

  add_title(right_app, "Scontrino");

  // Creazione e aggiunta della tabella

  receipt_area = new QReceiptShow();
  right_app->addWidget(receipt_area);

  // Aggiunta dei pulsanti per lo scontrino

  right_app->addLayout(add_receipt_buttons());

  // Aggiunta layout

  right_app->setSpacing(0);
  right_app->setContentsMargins(20, 20, 20, 20);
  object_layout->addLayout(right_app);
}

void view::update_json() {
  auto bind_item = std::bind(&controller::add_item, presenter, _1);
  product_area->refresh_grid(presenter->get_products_json(), bind_item);
  }

view::view(QWidget* parent) : QWidget(parent) {
  main_layout = new QVBoxLayout(this);
  object_layout = new QHBoxLayout(this);

  QRect desktopRect = QApplication::desktop()->availableGeometry(this);
  QPoint center = desktopRect.center();

  move(center.x() - width(), 0);

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

  receipt_area->setpresenter(c);

  // Update del file json

  update_json();

  // Segnali

  // Segnali della Menubar
  connect(file->actions()[0], SIGNAL(triggered()), this, SLOT(close()));

  // Segnali right_app
  connect(pay_button, SIGNAL(clicked()), this, SLOT(pay_banner()));
  connect(delete_receipt, SIGNAL(clicked()), this, SLOT(confirm_deletion()));

  connect(grappa_button, SIGNAL(clicked()), presenter, SLOT(filter_by_products()));
  connect(liquor_button, SIGNAL(clicked()), presenter, SLOT(filter_by_products()));
  connect(cream_button, SIGNAL(clicked()), presenter, SLOT(filter_by_products()));
  connect(all_button, SIGNAL(clicked()), presenter, SLOT(filter_by_products()));

  QList<QAction*>::const_iterator _color_cit = colors->actions().constBegin();
  QList<QAction*>::const_iterator _color_end = colors->actions().constEnd();
  for (; _color_cit != _color_end; _color_cit++) {
    connect(*_color_cit, SIGNAL(triggered()), presenter, SLOT(filter_by_color()));
  }

  QList<QAction*>::const_iterator _flavor_cit = flavors->actions().constBegin();
  QList<QAction*>::const_iterator _flavor_end = flavors->actions().constEnd();
  for (; _flavor_cit != _flavor_end; _flavor_cit++) {
    connect(*_flavor_cit, SIGNAL(triggered()), presenter, SLOT(filter_by_taste()));
  }
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

void view::refresh_scontrino(const u_vector<pair<deep_ptr<product>,int>> & p)
{
    receipt_area->refreshTable(p);
}

void view::refresh_grid_view(const u_vector<deep_ptr<product>>& _vector) {
  auto bind_item = std::bind(&controller::add_item, presenter, _1);
  product_area->refresh_grid(_vector,bind_item); }

// SLOTS

void view::pay_banner() {
  pay_dialog = new QDialog(this);

  QVBoxLayout* main = new QVBoxLayout(pay_dialog);
  QHBoxLayout* buttons = new QHBoxLayout(pay_dialog);

  QPushButton* ok_button = new QPushButton("OK");
  QPushButton* annulla_button = new QPushButton("Annulla");
  QLabel* alert;

  if(presenter->get_receipt().size()){
  alert = new QLabel("\t  Confermi il pagamento?");
  main->addWidget(alert,Qt::AlignCenter);
  buttons->addWidget(annulla_button,Qt::AlignLeft);
  buttons->addWidget(ok_button,Qt::AlignRight);
  buttons->setSpacing(120);
  main->addLayout(buttons);
  } else {
      alert = new QLabel("Nessun prodotto presente nel carrello.\n          Pagamento non effettuato!");
      alert->setContentsMargins(10,10,10,10);
      main->addWidget(alert);
  }

  pay_dialog->setLayout(main);

  pay_dialog->setFixedWidth(310);
  pay_dialog->setFixedHeight(150);
  connect(ok_button, SIGNAL(clicked()), presenter, SLOT(delete_all()));
  connect(ok_button, SIGNAL(clicked()), pay_dialog, SLOT(close()));
  connect(annulla_button, SIGNAL(clicked()), pay_dialog, SLOT(close()));

  pay_dialog->show();
}

void view::confirm_deletion()
{
    delete_dialog = new QDialog(this);

    QLabel* alert;
    QVBoxLayout* main = new QVBoxLayout(delete_dialog);
    QHBoxLayout* buttons = new QHBoxLayout(delete_dialog);

    QPushButton* ok = new QPushButton("OK");
    QPushButton* annulla = new QPushButton("Annulla");

    if(presenter->get_receipt().size()) {

    alert = new QLabel("\t     Vuoi davvero cancellare\n\t  tutti i prodotti del carrello?");
    main->addWidget(alert,Qt::AlignCenter);
    buttons->addWidget(annulla,Qt::AlignLeft);
    buttons->addWidget(ok,Qt::AlignRight);
    buttons->setSpacing(150);
    main->addLayout(buttons);

    } else {
        alert = new QLabel("Nessun prodotto presente nello scontrino.\n\t   Il carrello è già vuoto!");
        alert->setContentsMargins(10,0,10,0);
        main->addWidget(alert,Qt::AlignCenter);
    }

    delete_dialog->setLayout(main);
    delete_dialog->setFixedWidth(330);
    delete_dialog->setFixedHeight(150);

    connect(ok, SIGNAL(clicked()), presenter, SLOT(delete_all()));
    connect(ok, SIGNAL(clicked()), delete_dialog, SLOT(close()));
    connect(annulla, SIGNAL(clicked()), delete_dialog, SLOT(close()));

    delete_dialog->show();
}

void view::delete_all(){
  presenter->delete_all();
}


