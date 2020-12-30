#ifndef GRAPPA_H_
#define GRAPPA_H_

#include "spirits.h"

class grappa : public spirits {
 private:
 protected:
  static const double grappa_increment_price = 4.50;

 public:
  static const double minimum_alcohol_content = 38.0;
  double get_price() override;
  double price_increment() override;
  double kind_price() override;
  std::string code() override;
};

#endif  // GRAPPA_H_