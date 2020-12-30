#ifndef YOUNG_H_
#define YOUNG_H_

#include "grappa.h"

class young : public grappa {
 private:
  u_vector<taste> tastes;
  color col;

 protected:
  virtual u_vector<taste> get_tastes() const override;  // pubblico o privato??
  virtual color get_color() const override;             // pubblico o privato??

 public:
  young(const u_vector<taste>&, color);
  young(const young&);
  const young& operator=(const young&);
  virtual young* clone() const override;
  virtual double kind_price() const override;
  virtual double get_price() const override;
  virtual double price_increment() const override;
  virtual double promotion() const override;
  virtual std::string code() const override;
  virtual std::string get_image_path() const override;
};
// non ha incrementi di prezzo in quanto è la grappa basica, che non ha la stessa lavorazione di un liquore, di una crema, di un'invecchiata o di una barricata
#endif  //YOUNG_H_