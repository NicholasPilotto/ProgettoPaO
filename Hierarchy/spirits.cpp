#include "spirits.h"

spirits::spirits(bottle_size bs, const std::string& n, double ac) : product(bs, n, ac >= minimum_alcohol_content ? ac : minimum_alcohol_content) {}

spirits::spirits(const spirits& s) : product(s) {}  // non avendo campi dati come faccio? Solo il sottoogetto? Se si come?

spirits& spirits::operator=(const spirits& s) {
  if (this != &s) {
    product::operator=(s);
  }
  return *this;
}

const double spirits::minimum_alcohol_content = 21.0;

double spirits::kind_price() const {
  if (get_kind() == small) {
    return -1.80;
  } else if (get_kind() == big) {
    return 1.20;
  }
  return 0.00;
}

double spirits::price_increment() const {
  return kind_price();
}

double spirits::get_price() const {
  return get_default_price() + price_increment();
}

std::string spirits::code() const {
  return "S";
}

std::string spirits::get_image_path() const {
  return product::get_image_path() + "spirits/";
}