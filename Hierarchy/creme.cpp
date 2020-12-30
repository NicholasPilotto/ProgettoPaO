#include "creme.h"

creme::creme(const u_vector<taste>& t, color c) {}

u_vector<taste> creme::get_tastes() const {
  return tastes;
}

color creme::get_color() const {
  return col;
}

double const creme::multiplicator_discount_creme = 0.95;

creme* creme::clone() const {
  return new creme(*this);
}

double creme::kind_price() const {
  if (get_kind() == small)
    return -0.50;
  else if (get_kind() == big)
    return 0.50;
  return 0.00;
}

double creme::price_increment() const {
  return kind_price() + creme_price_increment;  //creme_price_increment + kind_price()
}

double creme::get_price() const {
  return non_spirits::get_price() + price_increment();  // non_spirits::get_price() + price_increment()
}

double creme::promotion() const {
  return get_price() * multiplicator_discount_creme;
}

// PROBLEMA: il codice non verrebbe identico perchè le prime 10 posizioni dell'enum sono da 1 cifra e il resto da 2 cifre
// UNA SOLUZIONE: assegnazione di un valore a due cifre nell'enum
// ALTERNATIVA: creare enum per le creme ed enum per liquori ed enum per le grappe
std::string creme::code() const {
  return std::string("AC0" + std::to_string(halzenhut) + std::to_string(lemon) + std::to_string(berries) + std::to_string(chocolate));
}
// sostituire con dereferenziazione dell'u_vector al posto di lemon, hanzenhut etc etc

std::string creme::get_image_path() const {
  return "product/non_spirits/creme/" + get_name();
}