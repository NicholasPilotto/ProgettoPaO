#include "grappa.h"

double grappa::kind_price() {
  if (get_kind() == small)
    return -1.60;
  else if (get_kind() == big)
    return 1.00;
  return 0.00;
}

double grappa::price_increment() {
  return spirits_tax() + kind_price() + grappa_increment_price;
}

double grappa::get_price() {
  return get_default_price() + price_increment();
}

std::string grappa::code() {
  return std::string("SG");
}