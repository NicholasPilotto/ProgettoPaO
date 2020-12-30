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
  u_vector<taste> get_tastes() const;
  color get_color() const;

 public:
  static double maximum_alcohol_content;
  liquor(color, taste* = nullptr);      // u_vector<taste> al posto di taste*
  liquor* clone() const override;       // OK
  double price_increment() override;    // OK
  double kind_price() override;         // OK
  double get_price() override;          // OK
  virtual double promotion() override;  // ??
  virtual std::string code() override;
};

#endif  // LIQUOR_H_