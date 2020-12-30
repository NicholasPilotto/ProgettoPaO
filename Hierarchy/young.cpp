#include "young.h"

young::young(const u_vector<taste>& t, color c) {}

u_vector<taste> young::get_tastes() const {
  return tastes;
}

color young::get_color() const {
  return col;
}

double const young::multiplicator_discount_young = 0.85;

young* young::clone() const {
  return new young(*this);
}

double young::kind_price() const {
  if (get_kind() == small)
    return -0.30;
  else if (get_kind() == big)
    return 0.10;
  return 0.00;
}

// Serve override??
double young::price_increment() const {
  return kind_price() + grappa_increment_price;
}

double young::get_price() const {
  return grappa::get_price() + price_increment();
}

double young::promotion() const {
  return get_price() * multiplicator_discount_young;  // chiamare liquor::getprice() per fare lo sconto del valore di un liquore della stessa bottle_size
}

std::string young::code() const {
  return std::string("SGG" + std::to_string(dry) + std::to_string(00) + std::to_string(00) + std::to_string(00));
}

std::string young::get_image_path() const {
  return "product/spirits/grappa/young/" + get_name();
}