#ifndef OLD_H_
#define OLD_H_

#include "grappa.h"

class old : public grappa {
 private:
  u_vector<taste> tastes;
  color col;
  bool barrique;
  unsigned int month;

 protected:
  virtual u_vector<taste> get_tastes() const override;  // pubblico o privato??
  virtual color get_color() const override;             // pubblico o privato??
  static const double price_increment_per_month = 0.2;

 public:
  old(const u_vector<taste>&, color, bool = false, unsigned int = (is_barrique() ? 24 : 18));  //da fare
  old(const old&);                                                                             //da fare
  const old& operator=(const old&);                                                            //da fare
  virtual old* clone() const override;
  virtual double kind_price() const override;
  virtual double get_price() const override;
  virtual double price_increment() const override;
  virtual double promotion() const override;
  virtual std::string code() const override;
  virtual std::string get_image_path() const override;
  bool is_barrique() const;
};

#endif  // OLD_H_