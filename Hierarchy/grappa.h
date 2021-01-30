#ifndef GRAPPA_H_
#define GRAPPA_H_

#include "spirits.h"

class grappa : public spirits {
 protected:
  static const double grappa_price_increment;

 public:
  grappa(bottle_size = medium, const std::string& = " ", double = 38.0);  // da controllare
  grappa(const grappa&);                                                  // da controllare
  grappa& operator=(const grappa&);                                       // da controllare
  static const double minimum_alcohol_content;
  static const double maximum_alcohol_content;
  virtual double kind_price() const override;
  virtual double price_increment() const override;
  virtual double get_price() const override;
  virtual std::string code() const override;
  virtual std::string get_image_path() const;
};

#endif  // GRAPPA_H_