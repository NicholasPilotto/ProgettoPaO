#include "filter.h"

filter::filter()
{
  
}

u_vector<deep_ptr<product>> filter::colors(const u_vector<deep_ptr<product>>& _vector, const unsigned int __value) {
  u_vector<deep_ptr<product>> _result;
  std::function<deep_ptr<product>(deep_ptr<product>)> lambda = [&](deep_ptr<product> value) {
    if (value->get_color() == __value) {
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

// u_vector<deep_ptr<product>> filter::products(const std::string&) {
//  u_vector<deep_ptr<product>> result;
//  std::function<deep_ptr<product>(deep_ptr<product>)> lambda = [&](deep_ptr<product> value) {
//    if (value-> == __value) {
//      return value;
//    }
//    return deep_ptr<product>();
//  };
//}
