#include "product.h"

product::product(bottle_size bs, const std::string& n, const std::string& imp, double fp, double ac) : kind(bs), name(n), image_path(imp), fixed_price(fp), alcohol_content(ac) {}

double product::get_default_price() {
  return fixed_price + kind_price();
}

bottle_size product::get_kind() {
  return kind;
}

double product::kind_price() {
  if (kind == small)
    return -1.00;
  else if (kind == big)
    return 1.00;
  return 0.00;
}

double product::get_alcohol_content() {
  return alcohol_content;
}