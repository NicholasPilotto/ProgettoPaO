#ifndef CREME_H_
#define CREME_H_

#include "non_spirits.h"

class creme : public non_spirits {
 private:
  u_vector<taste> tastes;
  color col;

 protected:
  static const double creme_price_increment = 3.50;
  u_vector<taste> get_tastes() const;
  color get_color() const;

 public:
  creme(taste*, color);
  creme* clone() const override;      // OK
  double price_increment() override;  // OK
  double get_price() override;        // OK
  double promotion() override;        // OK
  double kind_price() override;       // OK
  std::string code() override;        // OK
};

#endif  // CREME_H_