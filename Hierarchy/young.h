#ifndef YOUNG_H_
#define YOUNG_H_

#include "grappa.h"

class young : public grappa {
 private:
  u_vector<taste> tastes;
  color col;

 protected:
  virtual u_vector<taste> get_tastes() const;
  virtual color get_color() const;

 public:
  young(taste*, color);
  virtual young* clone() const override;
  virtual double kind_price() override;
  virtual double get_price() override;
  virtual double price_increment() override;
  virtual double promotion() override;
  virtual std::string code() override;
};
// non ha incrementi di prezzo in quanto è la grappa basica, che non ha la stessa lavorazione di un liquore, di una crema, di un'invecchiata o di una barricata
#endif  //YOUNG_H_