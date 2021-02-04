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
    if (typeid(*it) == typeid(*p)) {
      items.erase(it);
      stop = true;
    }
  }
}

