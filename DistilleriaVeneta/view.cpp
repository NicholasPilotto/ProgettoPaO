#include "view.h"
// Nuova versione

// TODO
unsigned int view::number_items() {
  unsigned int count = 0;
  // for per sommare tutti i numeri di elementi
  return count;
}

double view::calc_total_per_item() {
  double total_per_item = 0.0;
  return total_per_item /* moltiplicato per number of items */;
}

u_vector<deep_ptr<product> > view::load_products(const std::string & path) const
{
    io_json* io = new io_json(path);
    return io->read();
}

void view::refresh_receipt(u_vector<pair<deep_ptr<product>, int> > items) const
{
   showrec->refreshtable(items);
}

double view::calc_total() {
  double total = 0.0;
  // for per sommare tutti i prodotti a carrello tramite la funzione calc_total_per_item
  return total;
}

void view::show_warning(const QString &message) {
  QDialog *dialog = new QDialog(this);

  dialog->setLayout(new QHBoxLayout);
  dialog->layout()->addWidget(new QLabel(message, dialog));
  dialog->layout()->setAlignment(Qt::AlignCenter);
  dialog->setMinimumWidth(120);
  dialog->setMaximumWidth(500);

  dialog->show();
}

void view::add_menu_bar(QVBoxLayout *main_layout) {
  menu_bar = new QMenuBar(this);

  QMenu *file;
  QMenu *filters;
  QMenu *alcohols;
  QMenu *colours;
  QMenu *flavors;

  file = new QMenu("File", menu_bar);
  filters = new QMenu("Filtri", menu_bar);
  colours = new QMenu("Colore", filters);
  alcohols = new QMenu("Contenuto Alcolico", filters);
  // codes = new QAction("Codice", filters);
  flavors = new QMenu("Gusto", filters);

  menu_bar->addMenu(file);
  menu_bar->addMenu(filters);
  filters->addMenu(alcohols);
  // filters->addAction(codes);
  filters->addMenu(colours);
  filters->addMenu(flavors);

  QAction *close_action = new QAction("Chiudi", file);
  const QKeySequence *closing = new QKeySequence("Ctrl+Q");
  close_action->setShortcut(*closing);
  file->addAction(close_action);

  // Alcohols incompleto
  // Si può risolvere con Qlistview(non utilizzata per il momento)
  // Problema di non contemporaneità
  QAction *cresc = new QAction("Ordine Crescente", alcohols);
  QAction *desc = new QAction("Ordine Decrescente", alcohols);
  cresc->setCheckable(true);
  cresc->setChecked(true);
  desc->setCheckable(true);
  desc->setChecked(false);
  alcohols->addAction(cresc);
  alcohols->addAction(desc);

  // Colours
  u_vector<QString> colours_actions = {
      "Giallo", "Rosso", "Rosa", "Marrone", "Nero", "Violetto", "Bianco", "Verde", "Bianco Trasparente", "Giallo Trasparente",
  };
  for (auto cit = colours_actions.const_begin(); cit != colours_actions.const_end(); cit++) {
    QAction *action = new QAction(*cit, colours);
    action->setCheckable(true);
    action->setChecked(false);
    colours->addAction(action);
  }

  // Flavors incompleto
  u_vector<QString> flavors_actions(17, 17);
  flavors_actions = {"Nocciola", "Caffè", "Liquirizia", "Cioccolato", "Uovo", "Rum", "Panna", "Fragola", "Frutti di Bosco", "Mirtillo", "Ribes", "Prugna", "Miele", "Secco", "Fruttato", "Amabile", "Menta"};
  for (auto cit = flavors_actions.const_begin(); cit != flavors_actions.const_end(); cit++) {
    QAction *action = new QAction(*cit, flavors);
    action->setCheckable(true);
    action->setChecked(false);
    flavors->addAction(action);
  }

  connect(file->actions()[0], SIGNAL(triggered()), this, SLOT(close()));

  main_layout->addWidget(menu_bar);
}

void view::add_title(QVBoxLayout *main_layout) {
  QLabel *title = new QLabel("Distilleria Veneta");

  title->setAlignment(Qt::AlignCenter);

  main_layout->addWidget(title);
}

void view::add_grid(QHBoxLayout *main_object_layout) {
  QVBoxLayout *left_app = new QVBoxLayout;

  QLabel *products_title = new QLabel("Prodotti");
  products_title->setContentsMargins(0, 20, 0, 20);
  products_title->setAlignment(Qt::AlignCenter);

  left_app->addWidget(products_title);

  auto products = load_products();

  showgrid* grid = new showgrid(products);

  left_app->addWidget(grid);
  left_app->addLayout(add_filter_buttons());
  left_app->setSpacing(0);
  left_app->setContentsMargins(20, 20, 20, 20);

  main_object_layout->addLayout(left_app);
}

// Utilizzare il ciclo for per l'inizializzazione
void view::add_receipt(QHBoxLayout *main_object_layout) {
  QVBoxLayout *right_app = new QVBoxLayout;

  // Receipt Title

  QLabel *receipt_title = new QLabel("Scontrino");
  receipt_title->setAlignment(Qt::AlignCenter);
  receipt_title->setContentsMargins(0, 20, 0, 20);

  // List
  showrec = new showreceipt();

  // Right app

  right_app->addWidget(receipt_title);
  right_app->addWidget(showrec);
  right_app->addLayout(add_receipt_buttons());

  right_app->setSpacing(0);
  right_app->setContentsMargins(20, 20, 20, 20);

  main_object_layout->addLayout(right_app);
}

// SetShortcut

QHBoxLayout *view::add_filter_buttons() {
  QHBoxLayout *filter_buttons = new QHBoxLayout;

  grappa_button = new QPushButton("Grappa");
  liquor_button = new QPushButton("Liquore");
  cream_button = new QPushButton("Crema");

  filter_buttons->addWidget(grappa_button);
  filter_buttons->addWidget(liquor_button);
  filter_buttons->addWidget(cream_button);
  filter_buttons->setSpacing(50);
  filter_buttons->setContentsMargins(50, 20, 50, 20);

  return filter_buttons;
}

QHBoxLayout *view::add_receipt_buttons() {
  QHBoxLayout *receipt_buttons = new QHBoxLayout;

  pay_button = new QPushButton("Elimina");
  delete_receipt = new QPushButton("Paga");

  receipt_buttons->addWidget(pay_button);
  receipt_buttons->addWidget(delete_receipt);
  receipt_buttons->setSpacing(50);
  receipt_buttons->setContentsMargins(100, 20, 100, 20);

  return receipt_buttons;
}

view::view(QWidget *parent) : QWidget(parent) {
  QVBoxLayout *main_layout = new QVBoxLayout;
  QHBoxLayout *main_object_layout = new QHBoxLayout;

  add_menu_bar(main_layout);

  add_title(main_layout);

  add_grid(main_object_layout);

  add_receipt(main_object_layout);

  main_layout->addLayout(main_object_layout);

  main_layout->setSpacing(20);
  setLayout(main_layout);
}

void view::set_controller(controller * ctr)
{
   presenter = ctr;

   //segnali
   //segnale inserimento OK su prodotto -> slot: refresh_receipt
}
