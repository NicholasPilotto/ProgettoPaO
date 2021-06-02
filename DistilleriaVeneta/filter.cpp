#include "filter.h"

#include <QDebug>

filter::filter() {}

u_vector<deep_ptr<product>> filter::colors(const u_vector<deep_ptr<product>>& _vector, const unsigned int __value) {
  u_vector<deep_ptr<product>> _result;
  std::function<deep_ptr<product>(deep_ptr<product>)> lambda = [&](deep_ptr<product> value) {
    if (value->get_color() == static_cast<color>(__value)) {
      return value;
    }
    return deep_ptr<product>();
  };

  _vector.filter(_result, lambda);

  return _result;
}

u_vector<deep_ptr<product>> filter::tastes(const u_vector<deep_ptr<product>>& _vector, const taste __value) {
  u_vector<deep_ptr<product>> _result;
  std::function<deep_ptr<product>(deep_ptr<product>)> lambda = [&](deep_ptr<product> value) {
    if (value->get_tastes().search(__value)) {
      return value;
    }
    return deep_ptr<product>();
  };

  _vector.filter(_result, lambda);

  return _result;
}

u_vector<deep_ptr<product>> filter::products(const u_vector<deep_ptr<product>>& _vector, const std::string& __value) {
  u_vector<deep_ptr<product>> _result;
  std::function<deep_ptr<product>(deep_ptr<product>)> lambda = [&](deep_ptr<product> value) {
    if (value->get_product() == __value) {
      return value;
    }
    return deep_ptr<product>();
  };

  _vector.filter(_result, lambda);

  return _result;
}

u_vector<deep_ptr<product>> filter::cre_ac(const u_vector<deep_ptr<product>>& _vector) {
  u_vector<deep_ptr<product>> result(_vector);
  std::sort(result.begin(), result.end(), [](deep_ptr<product>& a, deep_ptr<product>& b) { return a->get_alcohol_content() < b->get_alcohol_content(); });

  return result;
}

u_vector<deep_ptr<product>> filter::dec_ac(const u_vector<deep_ptr<product>>& _vector) {
  u_vector<deep_ptr<product>> result(_vector);
  std::sort(result.begin(), result.end(), [](deep_ptr<product>& a, deep_ptr<product>& b) { return a->get_alcohol_content() > b->get_alcohol_content(); });

  return result;
}
