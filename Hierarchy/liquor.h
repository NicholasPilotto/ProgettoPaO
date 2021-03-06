#ifndef LIQUOR_H_
#define LIQUOR_H_

#include "spirits.h"

class liquor : public spirits {
 private:
  color col;
  u_vector<taste> tastes;

 protected:
  static const double liquor_incr;
  static const double taste_incr;

 public:
  liquor(color, const u_vector<taste>&, bottle_size = medium, const std::string& = "", double = min_ac);  // da controllare
  liquor(const liquor&);                                                                                // da controllare
  liquor& operator=(const liquor&);                                                                     // da controllare
  static const double min_ac;
  static const double max_ac;
  static const double discount_liquor;
  virtual liquor* clone() const override;
  virtual double kind_price() const override;
  virtual double price_increment() const override;
  virtual double get_price() const override;
  virtual double promotion() const override;
  virtual u_vector<taste> get_tastes() const override;
  virtual color get_color() const override;
  virtual std::string code() const override;
  virtual std::string get_image_path() const override;
};

#endif  // LIQUOR_H_