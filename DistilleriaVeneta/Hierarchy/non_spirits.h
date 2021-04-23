#ifndef NON_SPIRITS_H_
#define NON_SPIRITS_H_
#include "product.h"

class non_spirits : public product {
 public:
  non_spirits(bottle_size = medium, const std::string& = "", double = min_ac);  // da controllare
  non_spirits(const non_spirits&);                                              // da controllare (penso non corretto)
  non_spirits& operator=(const non_spirits&);                                   // da controllare
  static const double min_ac;
  static const double max_ac;
  virtual double kind_price() const override;
  virtual double price_increment() const override;
  virtual double get_price() const override;
  virtual std::string code() const override;
  virtual std::string get_image_path() const override;
};

#endif  // NON_SPIRITS_H_
