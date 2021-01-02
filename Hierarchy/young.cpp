#include "young.h"

young::young(color c, const u_vector<taste>& t, bottle_size bs, const std::string& n, double ac) : grappa(bs, n, ac >= grappa::minimum_alcohol_content ? ac : grappa::minimum_alcohol_content), col(c), tastes(t) {}

young::young(const young& y) : col(y.col), tastes(y.tastes) {}  // Anche il sottooggetto? Se si come?

young& young::operator=(const young& y) {
  if (this != &y) {
    delete this;
    *this = y;
  }
  return *this;
}

double const young::multiplicator_discount_young = 0.85;

young* young::clone() const {
  return new young(*this);
}

double young::kind_price() const {
  if (get_kind() == small) {
    return -0.30;
  } else if (get_kind() == big) {
    return 0.10;
  }
  return 0.00;
}

double young::price_increment() const {
  return kind_price();
}

double young::get_price() const {
  return grappa::get_price() + price_increment();
}

double young::promotion() const {
  return get_price() * multiplicator_discount_young;
}

u_vector<taste> young::get_tastes() const {
  return tastes;
}

color young::get_color() const {
  return col;
}

std::string young::code() const {
  return "SGG" + std::to_string(dry) + std::to_string(00) + std::to_string(00) + std::to_string(00);
}

std::string young::get_image_path() const {
  return grappa::get_image_path() + "young/" + get_name();
}