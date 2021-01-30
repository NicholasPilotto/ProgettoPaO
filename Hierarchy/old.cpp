#include "old.h"

old::old(color c, const u_vector<taste>& t, bool b, unsigned int m, bottle_size bs, const std::string& n, double ac) : grappa(bs, n, ac >= grappa::minimum_alcohol_content ? ac : grappa::minimum_alcohol_content), col(c), tastes(t), barrique(b), month(m) {}

old::old(const old& o) : grappa(o), col(o.col), tastes(o.tastes), barrique(o.barrique), month(o.month) {}  // Anche il sottooggetto? Se si come?

old& old::operator=(const old& o) {
  if (this != &o) {
    grappa::operator=(o);
    col = o.col;
    tastes = o.tastes;
    barrique = o.barrique;
    month = o.month;
  }
  return *this;
}

const double old::price_increment_per_month = 0.20;

unsigned int old::get_month_old() const {
  return month;
}

double const old::multiplicator_discount_old = 0.80;

old* old::clone() const {
  return new old(*this);
}

double old::kind_price() const {
  if (kind_price() == small) {
    return -1.30 + (is_barrique() ? 0.30 : 0.00);
  } else if (kind_price() == big) {
    return 0.80 + (is_barrique() ? 0.90 : 0.00);
  }
  return 0.00;
}

double old::price_increment() const {
  return kind_price() + price_increment_per_month * month + (is_barrique() ? 3.00 : 0.00);
}

double old::get_price() const {
  return grappa::get_price() + price_increment();
}

double old::promotion() const {
  return get_price() * multiplicator_discount_old;
}

u_vector<taste> old::get_tastes() const {
  return tastes;
}

color old::get_color() const {
  return col;
}

std::string old::code() const {
  std::string aux = "SGO";
  int count = 0;
  u_vector<taste>::const_iterator cit = tastes.const_begin();
  u_vector<taste>::const_iterator end = tastes.const_end();
  for (; cit != end; cit++) {
    aux += std::to_string(*cit);
    count++;
  }
  for (; count < tastes.capacity(); count++) {
    aux += "00";
  }
  return aux;
}

std::string old::get_image_path() const {
  return grappa::get_image_path() + "old/" + get_name();
}

bool old::is_barrique() const {
  return barrique;
}