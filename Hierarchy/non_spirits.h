#ifndef NON_SPIRITS_H_
#define NON_SPIRITS_H_
#include "product.h"

class non_spirits : public product {
 private:
 protected:
  double non_spirits_tax();

 public:
  non_spirits(bottle_size, const std::string& = "No name", const std::string& = "No path", double = 5.00, double = 17.0);
  static const double maximum_alcohol_content;
  double price_increment() override;
  double get_price() override;
  std::string code() override;
  double kind_price() override;
};

#endif  // NON_SPIRITS_H_