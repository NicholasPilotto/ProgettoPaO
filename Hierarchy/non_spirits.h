#ifndef NON_SPIRITS_H_
#define NON_SPIRITS_H_
#include "product.h"

class non_spirits : public product {
 private:
 protected:
  double non_spirits_tax() const;

 public:
  non_spirits(bottle_size, const std::string& = "No name", const std::string& = "No path", double = 5.00, double = 17.0);  // da controllare
  static const double maximum_alcohol_content;
  virtual std::string code() const override;
  virtual double kind_price() const override;
  virtual double price_increment() const override;
  virtual double get_price() const override;
  virtual std::string get_image_path() const override;
};

#endif  // NON_SPIRITS_H_