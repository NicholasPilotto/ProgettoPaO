#include "controller.h"

#include <QDebug>

controller::controller(QObject* parent) : QObject(parent) {}

void controller::set_model(model* m) { _model = m; }

void controller::set_view(view* v) { _view = v; }

void controller::add_item(const deep_ptr<product>& p) {
  _model->add_item(p);
  _view->refresh_scontrino(get_receipt());
    }

void controller::remove_row(int i) { std::cout << "b" << std::endl;
    _model->remove_item(i);
    _view->refresh_scontrino(get_receipt());                                }
void controller::refresh_quantity(const deep_ptr<product> & p, int v)
{
    _model->refresh_quantity(p,v);
    _view->refresh_scontrino(get_receipt());
}

void controller::delete_all() {
    _model->delete_all();
    _view->refresh_scontrino(get_receipt());
}

bool controller::presenza(const deep_ptr<product>& p) const { return _model->presenza(p); }

unsigned int controller::total_number_items() const { return _model->total_number_items(); }

double controller::total_price_line(unsigned int i) const { return _model->total_price_line(i); }

double controller::total_price() const { return _model->total_price(); }

double controller::total_taxes() const { return _model->total_taxes(); }

u_vector<deep_ptr<product>> controller::get_products_json() const { return _model->get_products_json(); }

u_vector<pair<deep_ptr<product>, int>> controller::get_receipt() const { return _model->get_receipt(); }

void controller::filter_by_products() const {
  std::string _sender = sender()->objectName().toStdString();
  u_vector<deep_ptr<product>> _result;
  if (_sender != "all") {
    _view->refresh_grid_view(_model->filter_products(_sender));
  } else {
    _view->refresh_grid_view(_model->filter_all());
  }
}

void controller::filter_by_color() {
  QAction* aux = qobject_cast<QAction*>(sender());
  if (aux->isChecked()) {
    unsigned int _sender = std::stoi(sender()->objectName().toStdString());
    _view->refresh_grid_view(_model->filter_color(_sender));
    if (previous_sender) {
      previous_sender->setChecked(false);
    }
  } else {
    _view->refresh_grid_view(_model->filter_all());
  }

  previous_sender = aux;
}

void controller::filter_by_taste() {
  QAction* aux = qobject_cast<QAction*>(sender());
  if (aux->isChecked()) {
    unsigned int _sender = std::stoi(sender()->objectName().toStdString());
    _view->refresh_grid_view(_model->filter_taste(_sender));
    if (previous_sender) {
      previous_sender->setChecked(false);
    }
  } else {
    _view->refresh_grid_view(_model->filter_all());
  }

  previous_sender = aux;
}
