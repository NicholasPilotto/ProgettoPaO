#ifndef SPIRITS_H_
#define SPIRITS_H_

#include "product.h"

class spirits : public product {
 public:
  spirits(bottle_size = medium, const std::string& = " ", double = 21.0);  // da controllare
  spirits(const spirits&);                                                 // da controllare
  spirits& operator=(const spirits&);                                      // da controllare
  static const double minimum_alcohol_content;
  static double maximum_alcohol_content;
  virtual double kind_price() const override;
  virtual double price_increment() const override;
  virtual double get_price() const override;
  virtual std::string code() const override;
  virtual std::string get_image_path() const override;
};

#endif  // SPIRITS_H_