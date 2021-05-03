#include "controller.h"

#include <QDebug>

controller::controller(model* m, QObject* parent) : QObject(parent), _model(m) {}

controller::~controller() {
  delete _view;
  delete _model;
}

void controller::link_model(const deep_ptr<model>& model) { _model = model.get(); }

void controller::link_view(const deep_ptr<view>& view) { _view = view.get(); }

void controller::add_item(const deep_ptr<product>& p) { _model->add_item(p); }

void controller::save_receipt() const {}

void controller::pay() {
  //  double total_price = _model->total_price();
  //  double total_tax = _model->total_TAX();
}

void controller::decrement_item(const deep_ptr<product>& p) { _model->decrement_item(p); }

void controller::increment_item(const deep_ptr<product>& p) { _model->increment_item(p); }

void controller::remove_item(const deep_ptr<product>& p) { _model->remove_item(p); }

double controller::total_taxes() { return _model->total_TAX(); }

double controller::total_price_line(int i) const { return _model->total_price_line(i); }

double controller::total_price() { return _model->total_price(); }

unsigned int controller::total_number_items() { return _model->get_total_number_items(); }

u_vector<deep_ptr<product>> controller::load_from_file(const std::string& path) const { return _model->load_from_file(path); }

u_vector<pair<deep_ptr<product>, int>> controller::get_receipt_items() { return _model->get_receipt_items(); }
