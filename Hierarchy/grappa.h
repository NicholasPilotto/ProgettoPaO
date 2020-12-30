#ifndef GRAPPA_H_
#define GRAPPA_H_

#include "spirits.h"

class grappa : public spirits {
 private:
 protected:
  static const double grappa_increment_price = 4.50;

 public:
  grappa();  //nessun campo dato?
  static const double minimum_alcohol_content = 38.0;
  virtual double kind_price() const override;
  virtual double price_increment() const override;
  virtual double get_price() const override;
  virtual std::string code() const override;
  virtual std::string get_image_path() const;
};

#endif  // GRAPPA_H_