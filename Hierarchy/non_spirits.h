#ifndef NON_SPIRITS_H_
#define NON_SPIRITS_H_
#include "product.h"

class non_spirits : public product {
 public:
  non_spirits(bottle_size = medium, const std::string& = "", double = 17.0);  // da controllare
  non_spirits(const non_spirits&);                                            // da controllare (penso non corretto)
  non_spirits& operator=(const non_spirits&);                                 // da controllare
  static const double minimum_alcohol_content;
  static const double maximum_alcohol_content;
  virtual double kind_price() const override;
  virtual double price_increment() const override;
  virtual double get_price() const override;
  virtual std::string code() const override;
  virtual std::string get_image_path() const override;
};

#endif  // NON_SPIRITS_H_