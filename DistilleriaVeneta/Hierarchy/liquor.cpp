#include "liquor.h"

#include <algorithm>

liquor::aux_map_initializer::aux_map_initializer() {
	ptr = new liquor(color::white, {});
	_map["liquor"] = ptr;
}
liquor::aux_map_initializer::~aux_map_initializer() { delete ptr; }
liquor::aux_map_initializer liquor::aux_map;

liquor::liquor(const color c, const u_vector<taste>& t, bottle_size bs, const std::string& n, double ac) : spirits(bs, n, ac < max_ac && ac >= min_ac ? ac : min_ac), col(c), tastes(t) {}

const double liquor::liquor_incr = 4.00;

const double liquor::taste_incr = 0.10;

liquor::liquor(const liquor& l) : spirits(l), col(l.col), tastes(l.tastes) {}  // Anche il sottooggetto? Se si come?

liquor& liquor::operator=(const liquor& l) {
  if (this != &l) {
    spirits::operator=(l);
    col = l.col;
    tastes = l.tastes;
  }
  return *this;
}

const double liquor::min_ac = 21.0;

const double liquor::max_ac = 38.0;

double const liquor::discount_liquor = 0.90;

liquor* liquor::clone() const {
  return new liquor(*this);
}

double liquor::kind_price() const {
  if (get_kind() == small) {
    return -0.80;
  } else if (get_kind() == big) {
    return 0.30;
  }
  return 0.00;
}

double liquor::price_increment() const {
  return kind_price() + liquor_incr + tastes.size() * taste_incr;
}

double liquor::get_price() const {
  return spirits::get_price() + price_increment();
}

double liquor::promotion() const {
  return get_price() * discount_liquor;
}

u_vector<taste> liquor::get_tastes() const {
  return tastes;
}

color liquor::get_color() const {
  return col;
}

std::string liquor::code() const {
  std::string aux = "SL0";
  unsigned int count = 0;
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

std::string liquor::get_image_path() const {
  return spirits::get_image_path() + "liquor/" + get_name();
}

liquor* liquor::create(std::map<std::string, QVariant>& m) const {
	color _color = static_cast<color>(m["color"].toString().toInt());
	u_vector<taste> _tastes;
	std::for_each(m["tastes"].toList().begin(), m["tastes"].toList().end(), [&_tastes](QVariant value) { _tastes.push_back(static_cast<taste>(value.toString().toInt())); });
	bottle_size _bottle = static_cast<bottle_size>(m["bottle_size"].toString().toInt());
	std::string _name = m["name"].toString().toStdString();
	double _alcohol_content = m["min_ac"].toString().toDouble();

	return new liquor(_color, _tastes, _bottle, _name, _alcohol_content);
}
