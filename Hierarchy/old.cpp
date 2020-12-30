#include "old.h"

old::old(const u_vector<taste>& t, color c, bool b, unsigned int i) {}

old* old::clone() const {
  return new old(*this);
}

u_vector<taste> old::get_tastes() const {
  return tastes;
}

color old::get_color() const {
  return col;
}

double old::kind_price() const {
  if (kind_price() == small)
    return -1.30 + (is_barrique() ? +0.30 : 0.00);
  else if (kind_price() == big)
    return 0.80 + (is_barrique() ? 0.90 : 0.00);
  return 0.00;
}

double old::price_increment() const {
  return kind_price() + price_increment_per_month * month + (is_barrique() ? 3.00 : 0.00);
}

double old::get_price() const {
  return grappa::get_price() + price_increment();
}

double old::promotion() const {
  return -get_price();
}

std::string old::code() const {
  return std::string("SGI" + std::to_string(dry) + std::to_string(00) + std::to_string(00) + std::to_string(00));
}

std::string old::get_image_path() const {
  return "product/spirits/grappa/old/" + get_name();
}
}