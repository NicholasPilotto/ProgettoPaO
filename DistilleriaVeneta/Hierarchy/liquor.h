#ifndef LIQUOR_H_
#define LIQUOR_H_

#include "spirits.h"

class liquor : public spirits {
 private:
  class aux_map_initializer {
   private:
    liquor* ptr;

   public:
    aux_map_initializer();
    ~aux_map_initializer();
  };
  static aux_map_initializer aux_map;
  color col;
  u_vector<taste> tastes;

 protected:
  static const double liquor_incr;
  static const double taste_incr;

 public:
  liquor(const color = white, const u_vector<taste>& = {}, bottle_size = medium, const std::string& = "", double = min_ac);  // da controllare
  liquor(const liquor&);
  liquor& operator=(const liquor&);
  static const double min_ac;
  static const double max_ac;
  static const double discount_liquor;
  virtual liquor* clone() const override;
  double kind_price() const;
  double price_increment() const;
  virtual std::string get_product() const override;
  virtual double get_price() const override;
  virtual double promotion() const override;
  virtual u_vector<taste> get_tastes() const override;
  virtual color get_color() const override;
  virtual std::string code() const override;
  virtual std::string get_image_path() const override;
  virtual liquor* create(QMap<QString, QVariant>&) const override;
  virtual std::string write() const;
};

#endif  // LIQUOR_H_
