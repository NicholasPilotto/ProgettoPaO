#include "product.h"

product::product(bottle_size bs, const std::string& n, const std::string& imp, double fp, double ac) : kind(bs), name(n), image_path(imp), fixed_price(fp), alcohol_content(ac) {}

double product::get_default_price() const {
  return fixed_price + kind_price();
}

bottle_size product::get_kind() const {
  return kind;
}

double product::get_alcohol_content() const {
  return alcohol_content;
}

std::string product::get_image_path() const {
  return "product";
}

double product::kind_price() const {
  if (kind == small)
    return -1.00;
  else if (kind == big)
    return 1.00;
  return 0.00;
}

std::string product::get_name() const {
  return name;
}

double product::operator+(const product& p) const {
  return get_price() + p.get_price();
}

double product::operator-(const product& p) const {
  return get_price() > p.get_price() ? get_price() - p.get_price() : p.get_price() - get_price();
}