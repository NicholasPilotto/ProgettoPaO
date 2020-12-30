#include "liquor.h"

#include "creme.h"
#include "non_spirits.h"

liquor::liquor(color c, const u_vector<taste>& t) : col(c), tastes(t) {}

u_vector<taste> liquor::get_tastes() const {
  return tastes;
}

color liquor::get_color() const {
  return col;
}

double const liquor::maximum_alcohol_content = 38.0;

double const liquor::multiplicator_discount_liquor = 0.90;

liquor* liquor::clone() const {
  return new liquor(*this);
}

double liquor::kind_price() const {
  if (get_kind() == small)
    return -1.20;
  else if (get_kind() == big)
    return 0.30;
  return 0.00;
}

double liquor::price_increment() const {
  return kind_price() + liquor_price_increment + tastes.size() * taste_increment_per_each;
}

double liquor::get_price() const {
  return spirits::get_price() + price_increment();
}

// ??
double liquor::promotion() const {
  return get_price() * multiplicator_discount_liquor;  // chiamare creme::getprice() per fare lo sconto del valore di una crema della stessa bottle_size
}
// sconto percentuale

// PROBLEMA: il codice non verrebbe identico perchè le prime 10 posizioni dell'enum sono da 1 cifra e il resto da 2 cifre
// UNA SOLUZIONE: assegnazione di un valore a due cifre nell'enum

std::string liquor::code() const {
  return std::string("SL0" + std::to_string(tastes.size() < 1 ? "00" : "arraydereferenziato") + std::to_string(tastes.size() < 2 ? "00" : "arraydereferenziato") + std::to_string(tastes.size() < 3 ? "00" : "arraydereferenziato") + std::to_string(tastes.size() < 4 ? "00" : "arraydereferenziato"));  // quando si ha 00 solo la stringa e non la funzione
}
// sostituire con dereferenziazione dell'u_vector al posto di lemon, hanzenhut etc etc con 00 s'intende gusto e null(da aggiungere ai "gusti" in enum?)
// come faccio a far apparire la derefernziazione del'u_vector e contemporaneamente a sapere lo 00??

std::string liquor::get_image_path() const {
  return "product/spirits/liquor/" + get_name();
}