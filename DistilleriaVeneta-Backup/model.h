#ifndef _MODEL_H
#define _MODEL_H
#include <QDebug>

#include "./Utilities/u_vector.hpp"
#include "Hierarchy/product.h" /* attesa di receipt */
#include "io_json.h"
#include "receipt.h"

#define DEFAULT_JSON_PATH :/data/data.json

class model {
 private:
  receipt* r;

 public:
  model();
  ~model();
  double total_TAX() const;
  void add_item(const deep_ptr<product>&);
  void remove_item(const deep_ptr<product>&);
  void increment_item(const deep_ptr<product>&);
  void decrement_item(const deep_ptr<product>&);
  double total_price_line(int) const;
  double total_price() const;
  unsigned int get_total_number_items() const;
  void delete_list();
  void save_receipt();
  u_vector<deep_ptr<product>> load_from_file(const std::string& = ":/data/data.json") const;
  u_vector<pair<deep_ptr<product>, int>> get_receipt_items();
};
#endif
