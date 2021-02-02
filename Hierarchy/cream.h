#ifndef CREAM_H_
#define CREAM_H_

#include "non_spirits.h"

class cream : public non_spirits {
 private:
  color col;
  u_vector<taste> tastes;

 protected:
  static const double cream_incr;

 public:
  cream(color, const u_vector<taste>&, bottle_size = medium, const std::string& = "", double = min_ac);  // da fare
  cream(const cream&);                                                                                   // da fare
  cream& operator=(const cream&);                                                                        // da fare
  static const double discount_cream;
  static const double min_ac;
  static const double max_ac;
  virtual cream* clone() const override;
  virtual double kind_price() const override;
  virtual double price_increment() const override;
  virtual double get_price() const override;
  virtual double promotion() const override;
  virtual u_vector<taste> get_tastes() const override;
  virtual color get_color() const override;
  virtual std::string code() const override;
  virtual std::string get_image_path() const override;
};

#endif  // CREAM_H_