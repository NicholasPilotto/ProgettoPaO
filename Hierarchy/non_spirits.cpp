#include "non_spirits.h"

non_spirits::non_spirits(bottle_size bs, const std::string& n, const std::string& imp, double fp, double ac) : product(bs, n, imp, fp, ac < maximum_alcohol_content ? ac : 17.0) {}

double const non_spirits::maximum_alcohol_content = 21.0;

double non_spirits::non_spirits_tax() {
  return 0.1 * get_alcohol_content();
}

double non_spirits::price_increment() {
  return non_spirits_tax() + kind_price();
}

double non_spirits::get_price() {
  return get_default_price() + price_increment();
}

double non_spirits::kind_price() {
  if (get_kind() == small)
    return -1.20 + product::kind_price();
  else if (get_kind() == big)
    return 0.40;
  else
    return 0.00;
}

std::string code() {
  return std::string("A");
}