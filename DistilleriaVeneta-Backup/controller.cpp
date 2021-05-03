#include "controller.h"

#include <QDebug>

controller::controller(model* m, QObject* parent) : QObject(parent), _model(m) {}

controller::~controller() {
  delete _view;
  delete _model;
}

void controller::link_model(model* model) { _model = model; }

void controller::link_view(view* view) { _view = view; }

void controller::add_item(product* p) { _model->add_item(p); }

void controller::save_receipt() const {}

void controller::pay() {
  //  double total_price = _model->total_price();
  //  double total_tax = _model->total_TAX();
}

void controller::decrement_item(product* p) { _model->decrement_item(p); }

void controller::increment_item(product* p) { _model->increment_item(p); }

void controller::remove_item(product* p) { _model->remove_item(p); }

double controller::total_taxes()
{
    return _model->total_TAX();
}

u_vector<deep_ptr<product>> controller::load_from_file(const std::string& path) const { return _model->load_from_file(path); }

u_vector<pair<deep_ptr<product>, int>> controller::get_receipt_items() { return _model->get_receipt_items(); }
