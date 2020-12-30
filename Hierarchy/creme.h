#ifndef CREME_H_
#define CREME_H_

#include "non_spirits.h"

class creme : public non_spirits {
 private:
  color col;
  u_vector<taste> tastes;

 protected:
  static const double creme_price_increment = 3.50;
  virtual u_vector<taste> get_tastes() const override;  // protected o public???
  virtual color get_color() const override;             // protected o public???

 public:
  creme(color, const u_vector<taste>&);  // da fare
  creme(const creme&);                   // da fare
  const creme& operator=(const creme&);  // da fare
  static const double multiplicator_discount_creme;
  virtual creme* clone() const override;
  virtual double kind_price() const override;
  virtual double price_increment() const override;
  virtual double get_price() const override;
  virtual double promotion() const override;
  virtual std::string code() const override;
  virtual std::string get_image_path() const override;
};

#endif  // CREME_H_