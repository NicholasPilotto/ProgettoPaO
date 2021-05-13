#ifndef __RECEIPT_H__
#define __RECEIPT_H__

#include <chrono>

#include "./Utilities/u_vector.hpp"
#include "Hierarchy/product.h"
#include "Utilities/deep_ptr.hpp"

using std::pair;
using std::chrono::steady_clock;
using std::chrono::time_point;

class receipt {
 private:
  time_point<steady_clock> date;
  u_vector<pair<deep_ptr<product>, int>> items;

 public:
  receipt();
  void add_item(const deep_ptr<product>&);
  void remove_item(const deep_ptr<product>&);
  void delete_all();
  bool presenza(const deep_ptr<product>&) const;
  unsigned int total_number_items() const;
  double total_price_line(unsigned int i) const;
  double total_price() const;
  double total_taxes() const;
  u_vector<pair<deep_ptr<product>, int>> get_items() const;
};
#endif  // __RECEIPT_H__
