#include "old.h"

#include <QDebug>

old::aux_map_initializer::aux_map_initializer() {
  ptr = new old();
  _map["old"] = ptr;
}
old::aux_map_initializer::~aux_map_initializer() { delete ptr; }
old::aux_map_initializer old::aux_map;

old::old(color c, const u_vector<taste>& t, bool b, unsigned int m, bottle_size bs, const std::string& n, double ac) : grappa(bs, n, ac < max_ac && ac >= min_ac ? ac : min_ac), col(c), tastes(t), barrique(b), month(m) {}

old::old(const old& o) : grappa(o), col(o.col), tastes(o.tastes), barrique(o.barrique), month(o.month) {}

const double old::month_incr = 0.20;

unsigned int old::get_month_old() const { return month; }

double const old::discount_old = 0.80;

old* old::clone() const { return new old(*this); }

double old::kind_price() const {
  if (get_kind() == small) {
    return -1.50 + (is_barrique() ? -1.50 : 0.00);
  } else if (get_kind() == big) {
    return 1.00 + (is_barrique() ? 1.20 : 0.00);
  }
  return 0.00;
}

double old::price_increment() const { return kind_price() + month_incr * month + (is_barrique() ? 3.00 : 0.00); }

double old::get_price() const { return grappa::get_price() + price_increment(); }

double old::promotion() const { return get_price() * discount_old; }

u_vector<taste> old::get_tastes() const { return tastes; }

color old::get_color() const { return col; }

std::string old::code() const {
  std::string aux = "SGO";
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

std::string old::get_image_path() const {
  std::string name = get_name();
  name.erase(std::remove(name.begin(), name.end(), '\n'), name.end());
  return grappa::get_image_path() + "old/" + name;
}

bool old::is_barrique() const { return barrique; }

old* old::create(QMap<QString, QVariant>& m) const {
  color _color = static_cast<color>(m["color"].toString().toInt());
  u_vector<taste> _tastes;

  QList<QVariant> list = m["tastes"].toList();
  for (auto const& element : list) {
    _tastes.push_back(static_cast<taste>(element.toString().toInt()));
  }
  bottle_size _bottle = static_cast<bottle_size>(m["bottle_size"].toString().toInt());
  std::string _name = m["name"].toString().toStdString();
  double _alcohol_content = m["alcohol_content"].toString().toDouble();
  bool _barrique = m["barrique"].toBool();
  unsigned int _month = m["month"].toUInt();

  return new old(_color, _tastes, _barrique, _month, _bottle, _name, _alcohol_content);
}
