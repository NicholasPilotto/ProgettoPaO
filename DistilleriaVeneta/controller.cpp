#include "controller.h"

#include <QDebug>

controller::controller(QObject* parent) : QObject(parent) {}

void controller::set_model(model* m) { _model = m; }

void controller::set_view(view* v) { _view = v; }

void controller::add_item(const deep_ptr<product>& p) { _model->add_item(p); }

void controller::remove_item(const deep_ptr<product>& p) { _model->remove_item(p); }

void controller::delete_all() { _model->delete_all(); }

bool controller::presenza(const deep_ptr<product>& p) const { return _model->presenza(p); }

unsigned int controller::total_number_items() const { return _model->total_number_items(); }

double controller::total_price_line(unsigned int i) const { return _model->total_price_line(i); }

double controller::total_price() const { return _model->total_price(); }

double controller::total_taxes() const { return _model->total_taxes(); }

u_vector<deep_ptr<product>> controller::get_products_json() const { return _model->get_products_json(); }

u_vector<pair<deep_ptr<product>, int>> controller::get_receipt() const { return _model->get_receipt(); }

void controller::filter_by_products() {
  std::string _sender = sender()->objectName().toStdString();
  u_vector<deep_ptr<product>> _result = _model->filter_products(_sender);
}

void controller::filter_by_color() {
  unsigned int _sender = std::stoi(sender()->objectName().toStdString());
  u_vector<deep_ptr<product>> _result = _model->filter_color(_sender);
  qDebug() << _result.size();
}
