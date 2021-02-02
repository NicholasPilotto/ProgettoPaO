#include "model.h"

model::model() : receipt(new receipt) {}

model::~model() {
  delete receipt;
}

double model::total_TAX() const {
  return receipt->tot_taxes();
}

void model::add_item(product* p) {
  receipt->add_item(p);
}

void model::remove_item(product* p) {
  receipt->remove_item(p);
}

void model::increment_item(product* p) {
  receipt->increase_item(p);
}

void model::decrement_item(product* p) {
  receipt->decrease_item(p);
}

double total_price() const {
  return receipt->total_price();
}

unsigned int model::get_total_number_items() /* const? */ {
  unsigned int count = 0;
  for (u_vector<std::pair<deep_ptr<product>, unsigned int>>::const_iterator cit = aux.const_begin(); cit != aux.const_end(); cit++) {
    count += (*cit).second  // dereferenziare unsigned int presente in pair
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