#include "receipt.h"

receipt::receipt() : date(steady_clock::now()), items(u_vector<pair<deep_ptr<product>, int>>()) {}

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

double receipt::total_price() const {
  double price = 0;
  u_vector<pair<deep_ptr<product>, int>>::iterator it = items.begin();
  u_vector<pair<deep_ptr<product>, int>>::iterator end = items.end();

  for (; it != end; it++) {
    price += (it->first->get_price() * it->second)
  }

  return price;
}