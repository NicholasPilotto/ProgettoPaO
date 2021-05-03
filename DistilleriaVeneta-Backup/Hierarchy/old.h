#ifndef OLD_H_
#define OLD_H_

#include "grappa.h"

class old : public grappa {
 private:
  class aux_map_initializer {
   private:
    old* ptr;

   public:
    aux_map_initializer();
    ~aux_map_initializer();
  };
  static aux_map_initializer aux_map;

  color col;
  u_vector<taste> tastes;
  bool barrique;
  unsigned int month;

 protected:
  static const double month_incr;
  unsigned int get_month_old() const;

 public:
  old(const color = white_trasparent, const u_vector<taste>& = {}, bool = false, unsigned int = 18, bottle_size = medium, const std::string& = "", double = min_ac);  // da fare
  old(const old&);                                                                                                                                                    // da fare
  old& operator=(const old&);                                                                                                                                         // da fare
  static const double discount_old;
  virtual old* clone() const override;
  double kind_price() const;
  double price_increment() const;
  virtual double get_price() const override;
  virtual double promotion() const override;
  virtual u_vector<taste> get_tastes() const override;
  virtual color get_color() const override;
  virtual std::string code() const override;
  virtual std::string get_image_path() const override;
  bool is_barrique() const;
  virtual old* create(QMap<QString, QVariant>&) const override;
};

#endif  // OLD_H_
