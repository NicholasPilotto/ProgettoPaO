#ifndef _MODEL_H
#define _MODEL_H

#include "./Utilities/u_vector.hpp"
#include "Hierarchy/product.h"
#include "io_json.h"
#include "receipt.h"

class model {
 private:
  receipt* r;
  u_vector<deep_ptr<product>> products;

 public:
  model(const std::string&);
  void load_from_file(const std::string& = ":/data/data.json");

  u_vector<deep_ptr<product>> get_products_json() const;

  void add_item(const deep_ptr<product>&);
  void remove_item(const deep_ptr<product>&);
  void delete_all();
  bool presenza(const deep_ptr<product>&) const;
  unsigned int total_number_items() const;
  double total_price_line(unsigned int) const;
  double total_price() const;
  double total_taxes() const;
  u_vector<pair<deep_ptr<product>, int>> get_receipt() const;
};
#endif
