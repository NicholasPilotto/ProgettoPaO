#ifndef PRODOTTO_H_
#define PRDOTTO_H_

#include <string>

#include "./Utilities/Contenitore/u_vector.hpp"
#include "enum.h"

class product {
 private:
  bottle_size kind;
  std::string name;
  double alcohol_content;

 protected:
  static const double fixed_price;
  bottle_size get_kind() const;
  double get_default_price() const;
  double get_alcohol_content() const;

 public:
  product(bottle_size = medium, const std::string& = "", double = min_ac);  // da controllare
  product(const product&);
  product& operator=(const product&);
  virtual ~product() = default;
  static const double multiplier_taxes;
  static const double min_ac;
  static const double max_ac;
  virtual product* clone() const = 0;
  virtual double kind_price() const;
  virtual double price_increment() const = 0;
  virtual double get_price() const = 0;  // chiamata ricorsiva
  virtual std::string code() const = 0;  // problema delle prime tre lettere ricorsive con differenza tra creme/liquori e old/young
  virtual double promotion() const = 0;
  virtual u_vector<taste> get_tastes() const = 0;
  virtual color get_color() const = 0;
  virtual std::string get_image_path() const;
  std::string get_name() const;
  double taxes() const;
  double operator+(const product&) const;
  double operator-(const product&) const;
};

#endif  // PRODOTTO_H_