#ifndef OLD_H_
#define OLD_H_

#include "grappa.h"

class old : public grappa {
 private:
  color col;
  u_vector<taste> tastes;
  bool barrique;
  unsigned int month;

 protected:
  static const double price_increment_per_month;
  unsigned int get_month_old() const;

 public:
  old(color, const u_vector<taste>&, bool = false, unsigned int = 18, bottle_size = medium, const std::string& = "", double = 38.0);  //da fare
  old(const old&);                                                                                                                    //da fare
  old& operator=(const old&);                                                                                                         //da fare
  static const double multiplicator_discount_old;
  virtual old* clone() const override;
  virtual double kind_price() const override;
  virtual double price_increment() const override;
  virtual double get_price() const override;
  virtual double promotion() const override;
  virtual u_vector<taste> get_tastes() const override;
  virtual color get_color() const override;
  virtual std::string code() const override;
  virtual std::string get_image_path() const override;
  bool is_barrique() const;
};

#endif  // OLD_H_