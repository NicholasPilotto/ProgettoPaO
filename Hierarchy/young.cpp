#include "young.h"

young::young(taste* t, color c) {}

u_vector<taste> young::get_tastes() const {
  return tastes;
}

color young::get_color() const {
  return col;
}

young* young::clone() const {
  return new young(*this);
}

double young::kind_price() {
  if (get_kind() == small)
    return -0.30;
  else if (get_kind() == big)
    return 0.10;
  return 0.00;
}

// Serve override??
double young::price_increment() {
  return spirits_tax() + kind_price() + grappa_increment_price;
}

double young::get_price() {
  return get_default_price() + price_increment();
}

double young::promotion() {
  return -get_price();  // chiamare liquor::getprice() per fare lo sconto del valore di un liquore della stessa bottle_size
}

std::string young::code() {
  return std::string("SGG" + std::to_string(dry) + std::to_string(00) + std::to_string(00) + std::to_string(00));
}
