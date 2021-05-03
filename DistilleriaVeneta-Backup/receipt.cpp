#include "receipt.h"

receipt::receipt() : date(steady_clock::now()), items({}) {}

void receipt::add_item(product* p) {
  pair<deep_ptr<product>, int> element(p, 1);
  items.push_back(element);
}

void receipt::remove_item(product* p) {
  u_vector<pair<deep_ptr<product>, int>>::iterator it = items.begin();
  u_vector<pair<deep_ptr<product>, int>>::iterator end = items.end();

  bool stop = false;
  for (; !stop && it != end; it++) {
    if (typeid(*((*it).first)) == typeid(*p)) {
      items.erase(it);
      stop = true;
    }
  }
}

void receipt::increase_item(product* p) {
  u_vector<pair<deep_ptr<product>, int>>::iterator it = items.begin();
  u_vector<pair<deep_ptr<product>, int>>::iterator end = items.end();

  bool stop = false;
  for (; !stop && it != end; it++) {
    if (typeid(*((*it).first)) == typeid(*p)) {
      if (typeid(*((*it).first)) == typeid(*p)) {
        ((*it).second) += 1;
        stop = true;
      }
    }
  }

  if (!stop) {
    add_item(p);
  }
}

void receipt::decrease_item(product* p) {
  u_vector<pair<deep_ptr<product>, int>>::iterator it = items.begin();
  u_vector<pair<deep_ptr<product>, int>>::iterator end = items.end();

  bool stop = false;
  for (; !stop && it != end; it++) {
    if (((*it).second) != 0) {
      ((*it).second) -= 1;
      stop = true;
    }
  }
}

unsigned int receipt::total_number_items()
{
    unsigned int count = 0;
    u_vector<std::pair<deep_ptr<product>,int>> aux = get_items();
    auto cit = aux.const_begin();
    auto end = aux.const_end();

    for(; cit != end; cit++)
        count += (*cit).second;

    return count;
}

double receipt::total_price() const {
  double price = 0;
  u_vector<pair<deep_ptr<product>, int>>::iterator it = items.begin();
  u_vector<pair<deep_ptr<product>, int>>::iterator end = items.end();

  for (; it != end; it++) {
    price += (it->first->get_price() * it->second);
  }

  return price;
}

double receipt::total_price_line(int i) const
{
    auto pos = items.at(i);
    return pos.first->get_price() * pos.second;
}

double receipt::total_taxes() const {
  double tot_taxes = 0;
  u_vector<pair<deep_ptr<product>, int>>::iterator it = items.begin();
  u_vector<pair<deep_ptr<product>, int>>::iterator end = items.end();

  for (; it != end; it++) {
    tot_taxes += (it->first->taxes() * it->second);
  }

  return tot_taxes;
}

u_vector<pair<deep_ptr<product>, int>> receipt::get_items() { return items; }
