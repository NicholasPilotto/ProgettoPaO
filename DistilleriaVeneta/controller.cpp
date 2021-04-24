#include "controller.h"

controller::controller(QObject* parent) : QObject(parent) {}

controller::~controller() {
  delete _view;
  delete _model;
}

void controller::refresh_receipt()
{
    auto receipt_items = _model->get_receipt_item(); //items

    _view->refresh_receipt(receipt_items);

}

void controller::link_model(model* model) { _model = model; }

void controller::link_view(view* view) { _view = view; }
//aggiunto dopo
u_vector<deep_ptr<product> > controller::load_products() const
{
    return _model->load_from_file();
}

void controller::add_item(product* p) { _model->add_item(p); }

void controller::save_receipt() const {}

void controller::pay() {
  double total_price = _model->total_price();
  double total_tax = _model->total_TAX();
}

void controller::decrement_item(product* p) { _model->decrement_item(p); }

void controller::increment_item(product* p) { _model->increment_item(p); }

void controller::remove_item(product* p) { _model->remove_item(p); }
