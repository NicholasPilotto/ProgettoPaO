#include "Hierarchy/product.h" /* attesa di receipt */
#include "receipt.h"

class model {
 private:
  receipt* r;

 public:
  model();
  ~model();
  double total_TAX() const;
  void add_item(product*);
  void remove_item(product*);
  void increment_item(product*);
  void decrement_item(product*);
  double total_price() const;
  unsigned int get_total_number_items() const;
  // bool pay() const;
  void delete_list();
  void save_receipt();
};
