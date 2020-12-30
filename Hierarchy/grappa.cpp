#include "grappa.h"

double grappa::kind_price() const {
  if (get_kind() == small)
    return -1.60;
  else if (get_kind() == big)
    return 1.00;
  return 0.00;
}

double grappa::price_increment() const {
  return spirits_tax() + kind_price() + grappa_increment_price;
}

double grappa::get_price() const {
  return spirits::get_price() + price_increment();
}

std::string grappa::code() const {
  return std::string("SG");
}

std::string grappa::get_image_path() const {
  return "product/spirits/grappa";
}