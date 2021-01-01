#include "non_spirits.h"

non_spirits::non_spirits(bottle_size bs, const std::string& n, double ac) : product(bs, n, ac < maximum_alcohol_content ? ac : 17.0) {}

non_spirits::non_spirits(const non_spirits& ns) : non_spirits() {}  // non avendo campi dati come faccio? Solo il sottoogetto? Se si come?

non_spirits& non_spirits::operator=(const non_spirits& ns) {
  if (this != &ns) {
    delete this;
    *this = ns;
  }
  return *this;
}

double non_spirits::non_spirits_tax() const {
  return 0.1 * get_alcohol_content();
}

const double non_spirits::maximum_alcohol_content = 21.0;

double non_spirits::kind_price() const {
  if (get_kind() == small) {
    return -1.20;
  } else if (get_kind() == big) {
    return 0.40;
  }
  return 0.00;
}

double non_spirits::price_increment() const {
  return kind_price() + non_spirits_tax();
}

double non_spirits::get_price() const {
  return get_default_price() + price_increment();
}

std::string non_spirits::code() const {
  return "A";
}

std::string non_spirits::get_image_path() const {
  return product::get_image_path() + "non_spirits/";
}