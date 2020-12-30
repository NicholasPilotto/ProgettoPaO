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
  virtual u_vector<taste> get_tastes() const;
  virtual color get_color() const;
  static const double price_increment_per_month = 0.2;

 public:
  old(taste*, color, bool = false, unsigned int = 18);
  virtual old* clone() const override;
  virtual double kind_price() override;
  virtual double get_price() override;
  virtual double price_increment() override;
  virtual double promotion() override;
  virtual std::string code() override;
  bool is_barrique() const;
};

#endif  // OLD_H_