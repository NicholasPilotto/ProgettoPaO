#include "model.h"

model::model() : r(new receipt) {}

model::~model() {
  delete r;
}

double model::total_TAX() const {
    return r->total_taxes();
}

void model::add_item(product* p) {
  r->add_item(p);
}

void model::remove_item(product* p) {
  r->remove_item(p);
}

void model::increment_item(product* p) {
  r->increase_item(p);
}

void model::decrement_item(product* p) {
  r->decrease_item(p);
}

double model::total_price() const {
  return r->total_price();
}

unsigned int model::get_total_number_items() const {
  unsigned int count = 0;
    u_vector<std::pair<deep_ptr<product>, int>>::const_iterator cit = r->get_items().const_begin();
    u_vector<std::pair<deep_ptr<product>, int>>::const_iterator end = r->get_items().const_end();
    for (; cit != end; cit++) {
        count += (*cit).second;
    }
    return count;
}

u_vector<deep_ptr<product>> model::load_from_file(const std::string& path) const {
    io_json* io = new io_json(path);
    return io->read();
}
/*
void model::delete_list() {
    delete r;
}


receipt save_receipt() {
    return r;
}
*/
