#include "grappa.h"

grappa::grappa(const color c, const u_vector<taste>& tastes, bottle_size bs, const std::string& n, double ac) : spirits(bs, n, ac < max_ac && ac >= min_ac ? ac : min_ac) {}  // essendoci una variabile statica con lo stesso nome è conveniente cambiare nome ma secondo te va bene anche con l'operatore di scoping? Comunque io rinominerei...

grappa::grappa(const grappa& g) : spirits(g) {}  // non avendo campi dati come faccio? Solo il sottoogetto? Se si come?

grappa& grappa::operator=(const grappa& g) {
  if (this != &g) {
    spirits::operator=(g);
  }
  return *this;
}

const double grappa::grappa_incr = 4.50;

const double grappa::min_ac = 38.0;

const double grappa::max_ac = 90.0;

double grappa::kind_price() const {
  if (get_kind() == small) {
    return -0.40;
  } else if (get_kind() == big) {
    return 0.10;
  }
  return 0.00;
}

double grappa::price_increment() const { return kind_price() + grappa_incr; }

double grappa::get_price() const { return spirits::get_price() + price_increment(); }

std::string grappa::code() const { return "SG"; }

std::string grappa::get_image_path() const { return spirits::get_image_path() + "grappa/"; }
