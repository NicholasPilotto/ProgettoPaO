#ifndef SPIRITS_H_
#define SPIRITS_H_

#include "product.h"

class spirits : public product {
 private:
 protected:
  double spirits_tax();

 public:
  spirits(bottle_size, const std::string& = " ", const std::string& = " ", double = 5.00, double = 21.0);
  static const double minimum_alcohol_content;
  double price_increment() override;
  double get_price() override;
  double kind_price() override;
  std::string code() override;
};

#endif  // SPIRITS_H_