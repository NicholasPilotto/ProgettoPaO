#include "cream.h"

cream::aux_map_initializer::aux_map_initializer() {
  ptr = new cream();
  _map["cream"] = ptr;
}
cream::aux_map_initializer::~aux_map_initializer() { delete ptr; }

cream::cream(color c, const u_vector<taste>& t, bottle_size bs, const std::string& n, double ac) : non_spirits(bs, n, ac < max_ac && ac >= min_ac ? ac : min_ac), col(c), tastes(t) {}

const double cream::cream_incr = 3.50;

cream::cream(const cream& c) : non_spirits(c), col(c.col), tastes(c.tastes) {}

cream& cream::operator=(const cream& c) {
  if (this != &c) {
    non_spirits::operator=(c);
    col = c.col;
    u_vector<taste>::const_iterator cit = tastes.const_begin();
    for (; cit != tastes.const_end(); cit++) {
      tastes = c.tastes;
    }
  }
  return *this;
}

const double cream::discount_cream = 0.95;

const double cream::max_ac = 21.0;

const double cream::min_ac = 18.0;

cream* cream::clone() const { return new cream(*this); }

double cream::kind_price() const {
  if (get_kind() == small) {
    return -0.50;
  } else if (get_kind() == big) {
    return 0.50;
  }
  return 0.00;
}

double cream::price_increment() const { return kind_price() + cream_incr; }

double cream::get_price() const { return non_spirits::get_price() + price_increment(); }

double cream::promotion() const { return get_price() * discount_cream; }

u_vector<taste> cream::get_tastes() const { return tastes; }

color cream::get_color() const { return col; }

// da modificare con la proposta di liquor???
std::string cream::code() const {
  std::string aux = "AC0";
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

std::string cream::get_image_path() const { return non_spirits::get_image_path() + "cream/" + get_name(); }

cream* cream::create(std::map<std::string, QVariant>& m) const { return new cream(); }