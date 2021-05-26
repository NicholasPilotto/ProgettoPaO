#ifndef _MODEL_H
#define _MODEL_H

#include <QObject>

#include "./Utilities/u_vector.hpp"
#include "Hierarchy/product.h"
#include "filter.h"
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
  void remove_item(int);
  void delete_all();
  void refresh_quantity(const deep_ptr<product>&, int);
  bool presenza(const deep_ptr<product>&) const;
  unsigned int total_number_items() const;
  double total_price_line(unsigned int) const;
  double total_price() const;
  double total_taxes() const;
  u_vector<pair<deep_ptr<product>, int>> get_receipt() const;
  u_vector<deep_ptr<product>> filter_products(const std::string& = std::string()) const;
  u_vector<deep_ptr<product>> filter_color(const unsigned int = 0) const;
  u_vector<deep_ptr<product>> filter_taste(const unsigned int = 0) const;
  u_vector<deep_ptr<product>> filter_all() const;
};
#endif
