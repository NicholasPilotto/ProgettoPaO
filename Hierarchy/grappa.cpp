#include "grappa.h"

grappa::grappa(bottle_size bs, const std::string& n, double ac) : spirits(bs, n, ac >= grappa::minimum_alcohol_content ? ac : grappa::minimum_alcohol_content) {}  // essendoci una variabile statica con lo stesso nome è conveniente cambiare nome ma secondo te va bene anche con l'operatore di scoping? Comunque io rinominerei...

grappa::grappa(const grappa& g) : spirits() {}  // non avendo campi dati come faccio? Solo il sottoogetto? Se si come?

grappa& grappa::operator=(const grappa& g) {
  if (this != &g) {
    delete this;
    *this = g;
  }
  return *this;
}

const double grappa::grappa_increment_price = 4.50;

const double grappa::minimum_alcohol_content = 38.0;

double grappa::kind_price() const {
  if (get_kind() == small) {
    return -1.60;
  } else if (get_kind() == big) {
    return 1.00;
  }
  return 0.00;
}

double grappa::price_increment() const {
  return kind_price() + grappa_increment_price;
}

double grappa::get_price() const {
  return spirits::get_price() + price_increment();
}

// da modificare??
std::string grappa::code() const {
  return "SG";
}

std::string grappa::get_image_path() const {
  return spirits::get_image_path() + "grappa/";
}