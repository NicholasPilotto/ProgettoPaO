#include "cream.h"

#include <QDebug>

cream::aux_map_initializer::aux_map_initializer() {
  ptr = new cream();
  _map["cream"] = ptr;
}
cream::aux_map_initializer::~aux_map_initializer() { delete ptr; }
cream::aux_map_initializer cream::aux_map;

cream::cream(const color c, const u_vector<taste>& t, bottle_size bs, const std::string& n, double ac) : non_spirits(bs, n, ac < max_ac && ac >= min_ac ? ac : min_ac), col(c), tastes(t) {}

const double cream::cream_incr = 3.50;

cream::cream(const cream& c) : non_spirits(c), col(c.col), tastes(c.tastes) {}

cream& cream::operator=(const cream& c) {
  if (this != &c) {
    non_spirits::operator=(c);
    col = c.col;
    u_vector<taste>::const_iterator cit = tastes.const_begin();
    u_vector<taste>::const_iterator end = tastes.const_end();
    for (; cit != end; cit++) {
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

std::string cream::get_product() const { return "cream"; }

double cream::get_price() const {
  return non_spirits::get_price() + price_increment();
  ;
}

double cream::promotion() const { return get_price() * discount_cream; }

u_vector<taste> cream::get_tastes() const { return tastes; }

color cream::get_color() const { return col; }

// da modificare con la proposta di liquor???
std::string cream::code() const {
  std::string aux = "AC0";
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

std::string cream::get_image_path() const {
  std::string name = get_name();
  name.erase(std::remove(name.begin(), name.end(), '\n'), name.end());
  return non_spirits::get_image_path() + "cream/" + name + ".png";
}

cream* cream::create(QMap<QString, QVariant>& m) const {
  color _color = static_cast<color>(m["color"].toString().toInt());
  u_vector<taste> _tastes;

  QList<QVariant> list = m["tastes"].toList();
  for (auto const& element : list) {
    _tastes.push_back(static_cast<taste>(element.toString().toInt()));
  }

  bottle_size _bottle = static_cast<bottle_size>(m["bottle_size"].toString().toInt());
  std::string _name = m["name"].toString().toStdString();
  double _alcohol_content = m["alcohol_content"].toString().toDouble();

  return new cream(_color, _tastes, _bottle, _name, _alcohol_content);
}
