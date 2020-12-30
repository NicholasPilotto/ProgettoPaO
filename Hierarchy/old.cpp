#include "old.h"

old::old(taste*, color, bool = false, unsigned int = 18) {}

old* old::clone() const {
  return new old(*this);
}

u_vector<taste> old::get_tastes() const {
  return tastes;
}

color old::get_color() const {
  return col;
}

double old::kind_price() {
  if (kind_price() == small)
    return -1.30 + (is_barrique() ? 3.70 : 0.00);
  else if (kind_price() == big)
    return 0.80 + (is_barrique() ? 5.90 : 0.00);
  return 0.00;
}

double old::price_increment() {
  return spirits_tax() + kind_price() + price_increment_per_month * month + (is_barrique() ? 5.00 : 0.00);
}