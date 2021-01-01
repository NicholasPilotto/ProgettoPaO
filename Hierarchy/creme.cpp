#include "creme.h"

creme::creme(color c, const u_vector<taste>& t, bottle_size bs, const std::string& n, double ac) : non_spirits(bs, n, ac < maximum_alcohol_content ? ac : 17.0), col(c), tastes(t) {}

const double creme::creme_price_increment = 3.50;

creme::creme(const creme& c) : col(c.col), tastes(c.tastes) {}  // Anche il sottooggetto? Se si come?

creme& creme::operator=(const creme& c) {
  if (this != &c) {
    delete this;
    *this = c;
  }
  return *this;
}

const double creme::multiplicator_discount_creme = 0.95;

creme* creme::clone() const {
  return new creme(*this);
}

double creme::kind_price() const {
  if (get_kind() == small) {
    return -0.50;
  } else if (get_kind() == big) {
    return 0.50;
  }
  return 0.00;
}

double creme::price_increment() const {
  return kind_price() + creme_price_increment;
}

double creme::get_price() const {
  return non_spirits::get_price() + price_increment();
}

double creme::promotion() const {
  return get_price() * multiplicator_discount_creme;
}

u_vector<taste> creme::get_tastes() const {
  return tastes;
}

color creme::get_color() const {
  return col;
}

//da modificare con la proposta di liquor???
std::string creme::code() const {
  return "AC0" + std::to_string(halzenhut) + std::to_string(lemon) + std::to_string(berries) + std::to_string(chocolate);
}

std::string creme::get_image_path() const {
  return non_spirits::get_image_path() + "creme/" + get_name();
}