#include "liquor.h"

liquor::liquor(color c, const u_vector<taste>& t, bottle_size bs, const std::string& n, double ac) : spirits(bs, n, ac <= maximum_alcohol_content ? ac : minimum_alcohol_content), col(c), tastes(t) {}

const double liquor::liquor_price_increment = 4.00;

const double liquor::taste_increment_per_each = 0.10;

liquor::liquor(const liquor& l) : spirits(l), col(l.col), tastes(l.tastes) {}  // Anche il sottooggetto? Se si come?

liquor& liquor::operator=(const liquor& l) {
  if (this != &l) {
    spirits::operator=(l);
    col = l.col;
    tastes = l.tastes;
  }
  return *this;
}

double const liquor::maximum_alcohol_content = 38.0;

double const liquor::multiplicator_discount_liquor = 0.90;

liquor* liquor::clone() const {
  return new liquor(*this);
}

double liquor::kind_price() const {
  if (get_kind() == small) {
    return -1.20;
  } else if (get_kind() == big) {
    return 0.30;
  }
  return 0.00;
}

double liquor::price_increment() const {
  return kind_price() + liquor_price_increment + tastes.size() * taste_increment_per_each;
}

double liquor::get_price() const {
  return spirits::get_price() + price_increment();
}

double liquor::promotion() const {
  return get_price() * multiplicator_discount_liquor;
}

u_vector<taste> liquor::get_tastes() const {
  return tastes;
}

color liquor::get_color() const {
  return col;
}

std::string liquor::code() const {
  std::string aux = "SL0";
  int count = 0;
  u_vector<taste>::const_iterator cit = tastes.const_begin();
  u_vector<taste>::const_iterator end = tastes.const_end();
  for (; cit != end; cit++) {
    aux += std::to_string(*cit);
    count++;
  }
  for (; count < tastes.capacity(); count++) {
    aux += "00";
  }
  return aux;
}

std::string liquor::get_image_path() const {
  return spirits::get_image_path() + "liquor/" + get_name();
}