#include "view.h"
// Nuova versione
#include <QApplication>
#include <QDesktopWidget>

#include "./Hierarchy/cream.h"

view::view(QWidget* parent) : QWidget(parent) {}

view::~view() {
  delete file;
  delete filters;
  delete alcohols;
  // delete codes;
  delete colors;
  delete flavors;
  delete menu_bar;
  delete main_layout;
  delete main_object_layout;
  delete grappa_button;
  delete liquor_button;
  delete cream_button;
  delete delete_receipt;
  delete pay_button;
  delete presenter;
  delete cresc;
  delete desc;
  delete close_action;
  delete title;
  delete filter_buttons;
  delete receipt_area;
  delete receipt_buttons;
  delete resoconto;
  delete receipt_title;
  delete right_app;
  delete left_app;
  delete product_area;
  delete products_title;
}

void view::add_elements() {
  main_layout = new QVBoxLayout;
  main_object_layout = new QHBoxLayout;

  add_menu_bar(main_layout);

  QRect desktopRect = QApplication::desktop()->availableGeometry(this);
  QPoint center = desktopRect.center();

  move(center.x() - width(), 0);

  add_title(main_layout, "Distilleria Veneta");

  add_grid(main_object_layout);

  add_receipt(main_object_layout);

  main_layout->addLayout(main_object_layout);

  main_layout->setSpacing(20);
  setLayout(main_layout);
}

// TODO
unsigned int view::total_number_items() { return presenter->total_number_items(); }

double view::calc_total() { return presenter->total_price(); }

void view::pay_banner() {
  QDialog* pay_dialog = new QDialog(this);

  QGridLayout* datas = new QGridLayout();
  datas->addWidget(new QLabel("Il cliente ha pagato:"), 0, 0, 1, 1);

  QLineEdit* pay_customer = new QLineEdit();
  pay_customer->setValidator(new QDoubleValidator(0, 2147483647, 2, this));

  datas->addWidget(pay_customer, 0, 1, 1, 1);
  datas->addWidget(new QLabel("Totale dovuto"), 1, 1, 1, 1);
  datas->addWidget(new QLabel(QString::number(calc_total())), 2, 1, 1, 1);
  datas->addWidget(new QLabel("Resto"), 1, 2, 1, 1);
  datas->addWidget(new QLabel(QString::number(pay_customer->text().toDouble() - calc_total())), 2, 2, 1, 1);

  pay_dialog->setLayout(datas);

  pay_dialog->layout()->setAlignment(Qt::AlignCenter);
  pay_dialog->setMinimumWidth(120);
  pay_dialog->setMaximumWidth(500);
  // chiamare elimina tutto poichè il tutto viene pagato e o scontrino ritorna a 0 elementi (SIGNAL E SLOT)

  pay_dialog->show();
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

void view::add_menu_bar(QVBoxLayout* main_layout) {
  menu_bar = new QMenuBar(this);

  file = new QMenu("File", menu_bar);
  filters = new QMenu("Filtri", menu_bar);
  colors = new QMenu("Colore", filters);
  alcohols = new QMenu("Contenuto Alcolico", filters);
  // codes = new QAction("Codice", filters);
  flavors = new QMenu("Gusto", filters);

  menu_bar->addMenu(file);
  menu_bar->addMenu(filters);
  filters->addMenu(alcohols);
  // filters->addAction(codes);
  filters->addMenu(colors);
  filters->addMenu(flavors);

  close_action = new QAction("Chiudi", file);
  const QKeySequence* closing = new QKeySequence("Ctrl+Q");
  close_action->setShortcut(*closing);
  file->addAction(close_action);

  // Alcohols incompleto
  // Si può risolvere con Qlistview(non utilizzata per il momento)
  // Problema di non contemporaneità
  cresc = new QAction("Ordine Crescente", alcohols);
  desc = new QAction("Ordine Decrescente", alcohols);
  cresc->setCheckable(true);
  cresc->setChecked(true);
  desc->setCheckable(true);
  desc->setChecked(false);
  alcohols->addAction(cresc);
  alcohols->addAction(desc);

  // Colours
  u_vector<QString> colours_actions({
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
  });
  for (auto cit = colours_actions.const_begin(); cit != colours_actions.const_end(); cit++) {
    QAction* action = new QAction(*cit, colors);
    action->setCheckable(true);
    action->setChecked(false);
    colors->addAction(action);
  }

  // Flavors incompleto
  u_vector<QString> flavors_actions({"Nocciola", "Caffè", "Liquirizia", "Cioccolato", "Uovo", "Rum", "Panna", "Fragola", "Frutti di Bosco", "Mirtillo", "Ribes", "Prugna", "Miele", "Secco", "Fruttato", "Amabile", "Menta"});

  for (auto cit = flavors_actions.const_begin(); cit != flavors_actions.const_end(); cit++) {
    QAction* action = new QAction(*cit, flavors);
    action->setCheckable(true);
    action->setChecked(false);
    flavors->addAction(action);
  }

  connect(file->actions()[0], SIGNAL(triggered()), this, SLOT(close()));

  main_layout->addWidget(menu_bar);
}

void view::add_title(QVBoxLayout* main_layout, const QString& message) {
  title = new QLabel(message);

  title->setAlignment(Qt::AlignCenter);
  title->setContentsMargins(10, 10, 10, 10);

  main_layout->addWidget(title);
}

void view::add_grid(QHBoxLayout* main_object_layout) {
  left_app = new QVBoxLayout;

  products_title = new QLabel("Prodotti");
  products_title->setContentsMargins(0, 20, 0, 20);
  products_title->setAlignment(Qt::AlignCenter);

  left_app->addWidget(products_title);

  u_vector<deep_ptr<product>> aux = presenter->load_from_file(":/data/data.json");
  product_area = new gridshow(aux);

  left_app->addWidget(product_area);
  left_app->addLayout(add_filter_buttons());
  left_app->setSpacing(0);
  left_app->setContentsMargins(20, 20, 20, 20);

  main_object_layout->addLayout(left_app);
}

// Utilizzare il ciclo for per l'inizializzazione
void view::add_receipt(QHBoxLayout* main_object_layout) {
  right_app = new QVBoxLayout();

  // Receipt Title

  receipt_title = new QLabel("Scontrino");
  receipt_title->setAlignment(Qt::AlignCenter);
  receipt_title->setContentsMargins(0, 20, 0, 20);

  // Creazione tabella

  u_vector<std::pair<deep_ptr<product>, int>> tmp = presenter->get_receipt_items();

  receipt_area = new receiptshow(tmp);

  // Comparsa totale

  resoconto = new QGridLayout();

  resoconto->addWidget(new QLabel(("TOTALE:")), 0, 0, 1, 1, Qt::AlignLeft);
  resoconto->addWidget(new QLabel(QString::number(calc_total(), 'f', 2) + " €"), 0, 1, 1, 1, Qt::AlignRight);
  resoconto->addWidget(new QLabel("Tasse:"), 1, 0, 1, 1, Qt::AlignLeft);
  resoconto->addWidget(new QLabel(QString::number(presenter->total_taxes(), 'f', 2) + " €"), 1, 1, 1, 1, Qt::AlignRight);

  // Right app

  right_app->addWidget(receipt_title);

  right_app->addWidget(receipt_area);

  right_app->addLayout(resoconto);

  right_app->addLayout(add_receipt_buttons());

  right_app->setSpacing(0);
  right_app->setContentsMargins(20, 20, 20, 20);

  main_object_layout->addLayout(right_app);
}

// SetShortcut

QHBoxLayout* view::add_filter_buttons() {
  filter_buttons = new QHBoxLayout();

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

QHBoxLayout* view::add_receipt_buttons() {
  receipt_buttons = new QHBoxLayout();

  pay_button = new QPushButton("Elimina");
  delete_receipt = new QPushButton("Paga");

  receipt_buttons->addWidget(pay_button);
  receipt_buttons->addWidget(delete_receipt);
  receipt_buttons->setSpacing(50);
  receipt_buttons->setContentsMargins(100, 20, 100, 20);

  return receipt_buttons;
}

void view::set_controller(const deep_ptr<controller>& c) { presenter = c.get(); }
