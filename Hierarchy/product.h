#ifndef PRODOTTO_H_
#define PRDOTTO_H_

#include <string>

#include "./Utilities/Contenitore/u_vector.hpp"
#include "enum.h"

class product {
 private:
  bottle_size kind;
  std::string name;
  std::string image_path;
  double fixed_price;
  double alcohol_content;

 protected:
  double get_default_price() const;
  bottle_size get_kind() const;
  double get_alcohol_content() const;

 public:
  product(bottle_size = medium, const std::string& = " ", const std::string& = " ", double = 5.00, double = 17.0);
  virtual ~product() = default;
  virtual product* clone() const = 0;
  virtual double get_price() const = 0;
  virtual double price_increment() const = 0;
  virtual double promotion() const = 0;
  virtual std::string code() const = 0;
  //virtual u_vector<taste> get_tastes() const = 0;
  //virtual color get_color() const = 0;
  //std::string get_name() const;
  //virtual std::string get_image_path() const;
  virtual double kind_price() const;
};

//get_color e get_taste da istanziare nelle classi concrete
//get_name subito e poi basta mentre get_image_path come code

#endif  // PRODOTTO_H_