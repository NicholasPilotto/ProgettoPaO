#ifndef LIQUOR_H_
#define LIQUOR_H_

#include "spirits.h"

class liquor : public spirits {
 private:
  color col;
  u_vector<taste> tastes;

 protected:
  static const double liquor_price_increment = 4.00;
  static const double taste_increment_per_each = 0.10;
  u_vector<taste> get_tastes() const override;  // protected o public???
  color get_color() const override;             // protected o public???

 public:
  liquor(color, const u_vector<taste>&);   // da fare
  liquor(const liquor&);                   // da fare
  const liquor& operator=(const liquor&);  // da fare
  static const double maximum_alcohol_content;
  static const double multiplicator_discount_liquor;
  liquor* clone() const override;
  double kind_price() const override;
  double price_increment() const override;
  double get_price() const override;
  virtual double promotion() const override;
  virtual std::string code() const override;
  virtual std::string get_image_path() const override;
};

#endif  // LIQUOR_H_