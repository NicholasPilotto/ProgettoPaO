#include "model.h"

model::model() : r(new receipt) {}

model::~model() {
  delete r;
}

double model::total_TAX() const {
  return r->tot_taxes();
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

double total_price() {
  return r->total_price();
}

unsigned int model::get_total_number_items() const {
  unsigned int count = 0;
  for (u_vector<std::pair<deep_ptr<product>, unsigned int>>::const_iterator cit = items->const_begin(); cit != items.const_end(); cit++) {
    count += (*cit).second;  // dereferenziare unsigned int presente in pair
  }
  return count;
}
/*
void model::delete_list() {
    delete receipt();
}


receipt save_receipt() {
    return receipt();
}
*/