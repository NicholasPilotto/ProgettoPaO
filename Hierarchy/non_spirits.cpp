#include "non_spirits.h"

non_spirits::non_spirits(bottle_size bs, const std::string& n, const std::string& imp, double fp, double ac) : product(bs, n, imp, fp, ac < maximum_alcohol_content ? ac : 17.0) {}

double non_spirits::non_spirits_tax() const {
  return 0.1 * get_alcohol_content();
}

double const non_spirits::maximum_alcohol_content = 21.0;

double non_spirits::kind_price() const {
  if (get_kind() == small)
    return -1.20;  //+ product::kind_price(); è compreso in get_default_price
  else if (get_kind() == big)
    return 0.40;
  else
    return 0.00;
}

double non_spirits::price_increment() const {
  return kind_price() + non_spirits_tax();
}

double non_spirits::get_price() const {
  return get_default_price() + price_increment();
}

std::string non_spirits::code() const {
  return std::string("A");
}

std::string non_spirits::get_image_path() const {
  return "product/non_spirits";
}