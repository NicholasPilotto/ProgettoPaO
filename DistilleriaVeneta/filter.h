#ifndef FILTER_H
#define FILTER_H

#include <functional>
#include <string>

#include "./Hierarchy/enum.h"
#include "./Hierarchy/product.h"
#include "./Utilities/deep_ptr.hpp"
#include "./Utilities/u_vector.hpp"

class filter {
 public:
  filter();
  static u_vector<deep_ptr<product>> colors(u_vector<deep_ptr<product>>&, const unsigned int = 0);
  static u_vector<deep_ptr<product>> products(u_vector<deep_ptr<product>>&, const std::string& = std::string());
  static u_vector<deep_ptr<product>> tastes(u_vector<deep_ptr<product>>&, const taste = taste::_amable);
};

#endif  // FILTER_H
