#include "product.h"

product::product(bottle_size bs, const std::string& n, double ac) : kind(bs), name(n), alcohol_content(ac) {}

const double product::fixed_price = 5.00;

bottle_size product::get_kind() const {
  return kind;
}

double product::get_default_price() const {
  return kind_price() + fixed_price;
}

double product::get_alcohol_content() const {
  return alcohol_content;
}

product::product(const product& p) : kind(p.kind), name(p.name), alcohol_content(p.alcohol_content) {}

product& product::operator=(const product& p) {
  if (this != &p) {
    delete this;
    *this = p;
  }
  return *this;
}

double product::kind_price() const {
  if (kind == small) {
    return -1.00;
  } else if (kind == big) {
    return 1.00;
  }
  return 0.00;
}

std::string product::get_image_path() const {
  return "product/";
}

std::string product::get_name() const {
  return name;
}

double product::operator+(const product& p) const {
  return get_price() + p.get_price();
}

double product::operator-(const product& p) const {
  return get_price() >= p.get_price() ? get_price() - p.get_price() : p.get_price() - get_price();
}