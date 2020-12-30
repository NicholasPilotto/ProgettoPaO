#ifndef SPIRITS_H_
#define SPIRITS_H_

#include "product.h"

class spirits : public product {
 private:
 protected:
  double spirits_tax() const;

 public:
  spirits(bottle_size, const std::string& = " ", const std::string& = " ", double = 5.00, double = 21.0);  // da controllare
  static const double minimum_alcohol_content;
  double kind_price() const override;
  double price_increment() const override;
  double get_price() const override;
  std::string code() const override;
  virtual std::string get_image_path() const override;
};

#endif  // SPIRITS_H_