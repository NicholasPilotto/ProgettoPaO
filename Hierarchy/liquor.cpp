#include "liquor.h"

#include "creme.h"
#include "non_spirits.h"

creme a;

liquor::liquor(color c, taste* t) : col(c), tastes(t) {}

double liquor::maximum_alcohol_content = 38;

liquor* liquor::clone() const {
  return new liquor(*this);
}

double liquor::price_increment() {
  return spirits_tax() + liquor_price_increment + kind_price() + tastes.size() * taste_increment_per_each;
}

double liquor::kind_price() {
  if (get_kind() == small)
    return -1.20;
  else if (get_kind() == big)
    return 0.30;
  return 0.00;
}

double liquor::get_price() {
  return get_default_price() + price_increment();
}

double liquor::promotion() {
  return -(get_price() + a::get_price());  // chiamare creme::getprice() per fare lo sconto del valore di una crema della stessa bottle_size
}
// sconto percentuale

// PROBLEMA: il codice non verrebbe identico perchè le prime 10 posizioni dell'enum sono da 1 cifra e il resto da 2 cifre
// UNA SOLUZIONE: assegnazione di un valore a due cifre nell'enum

std::string liquor::code() {
  return std::string("SL0" + std::to_string(halzenhut) + std::to_string(halzenhut) + std::to_string(00) + std::to_string(halzenhut));  // quando si ha 00 solo la stringa e non la funzione
}
// sostituire con dereferenziazione dell'u_vector al posto di lemon, hanzenhut etc etc con 00 s'intende gusto e null(da aggiungere ai "gusti" in enum?)

u_vector<taste> liquor::get_tastes() const {
  return tastes;
}

color liquor::get_color() const {
  return col;
}

bool liquor::in_fridge() const {
  return fridge;
}