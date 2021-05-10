#include "model.h"

model::model(const std::string& filename) : r(new receipt()) {load_from_file(filename);}

void model::load_from_file(const std::string& path) {
  io_json* io = new io_json(path);
  products = io->read();
}



u_vector<deep_ptr<product> > model::get_products_json() const { return products; }



void model::add_item(const deep_ptr<product>& p) { r->add_item(p); }

void model::remove_item(const deep_ptr<product>& p) { r->remove_item(p); }

void model::delete_all() { r->delete_all(); }

bool model::presenza(const deep_ptr<product>& p) const { return r->presenza(p); }

unsigned int model::total_number_items() const { return r->total_number_items(); }

double model::total_price_line(unsigned int i) const { return r->total_price_line(i); }

double model::total_price() const { return r->total_price(); }

double model::total_taxes() const { return r->total_taxes(); }

u_vector<pair<deep_ptr<product>, int>> model::get_receipt() const { return r->get_items(); }
