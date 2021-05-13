#ifndef GRAPPA_H_
#define GRAPPA_H_

#include "spirits.h"

class grappa : public spirits {
 private:
 protected:
  static const double grappa_incr;

 public:
  grappa(bottle_size = medium, const std::string& = " ", double = min_ac);
  grappa(const grappa&);
  static const double min_ac;
  static const double max_ac;
  double kind_price() const;
  double price_increment() const;
  virtual double get_price() const override;
  virtual std::string code() const override;
  virtual std::string get_image_path() const override;
};

#endif  // GRAPPA_H_