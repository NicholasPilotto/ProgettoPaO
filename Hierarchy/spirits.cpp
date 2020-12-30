#include "spirits.h"

spirits::spirits(bottle_size bs, const std::string& n, const std::string& imp, double fp, double ac) : product(bs, n, imp, fp, ac >= minimum_alcohol_content ? ac : minimum_alcohol_content) {}

double const spirits::minimum_alcohol_content = 21.0;

double spirits::spirits_tax() const {
  return 0.2 * get_alcohol_content();
}

double spirits::price_increment() const {
  return spirits_tax() + kind_price();
}

double spirits::get_price() const {
  return get_default_price() + price_increment();
}

std::string spirits::code() const {
  return std::string("S");
}

double spirits::kind_price() const {
  if (get_kind() == small)
    return -1.80;
  else if (get_kind() == big)
    return 1.20;
  else
    return 0.00;
}

std::string spirits::get_image_path() const {
  return "product/spirits";
}