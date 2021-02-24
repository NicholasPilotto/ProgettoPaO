#ifndef __RECEIPT_H__
#define __RECEIPT_H__

#include <chrono>

#include "./Hierarchy/product.h"
#include "./Utilities/Contenitore/u_vector.hpp"
#include "./Utilities/DeepPtr/deep_ptr.hpp"

using std::pair;
using std::chrono::steady_clock;
using std::chrono::time_point;

class receipt {
 private:
  time_point<steady_clock> date;
  u_vector<pair<deep_ptr<product>, int>> items;
  // u_vector<pair<int, int>> package;

 public:
  receipt();

  void add_item(product*);
  void remove_item(product*);
  void increase_item(product*);
  void decrease_item(product*);
  double total_price() const;
  u_vector<pair<deep_ptr<product>, int>> get_items() const;

  // METODI PACKAGE
};
#endif  // __RECEIPT_H__