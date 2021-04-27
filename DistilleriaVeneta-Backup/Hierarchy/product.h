#ifndef _PRODOTTO_H_
#define _PRODOTTO_H_

#include <QMap>
#include <QString>
#include <QVariant>
#include <map>
#include <string>

#include "./Utilities/u_vector.hpp"
#include "enum.h"

class product {
 private:
  bottle_size kind;
  std::string name;
  double alcohol_content;

 protected:
  static const double fixed_price;
  double get_default_price() const;
  inline static std::map<std::string, product*> _map; // non inline

 public:
  product(bottle_size = medium, const std::string& = "", double = min_ac);
  product(const product&);
  product& operator=(const product&);
  virtual ~product() = default;
  static const double multiplier_taxes;
  static const double min_ac;
  static const double max_ac;
  virtual product* clone() const = 0;
  virtual double kind_price() const;
  virtual double price_increment() const = 0;
  virtual double get_price() const = 0;  // chiamata ricorsiva e prezzi sballati
  virtual std::string code() const = 0;
  virtual double promotion() const = 0;
  virtual u_vector<taste> get_tastes() const = 0;
  virtual color get_color() const = 0;
  virtual std::string get_image_path() const;
  std::string get_name() const;
  double taxes() const;
    double get_alcohol_content() const;
    bottle_size get_kind() const;
    static product* unserialize(QMap<QString, QVariant>&);
    virtual product* create(QMap<QString, QVariant>&) const = 0;
    //	virtual std::string write() const = 0;
    double operator+(const product&) const;
    double operator-(const product&) const;
};

#endif  // PRODOTTO_H_
