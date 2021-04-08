#ifndef YOUNG_H_
#define YOUNG_H_

#include "grappa.h"

class young : public grappa {
 private:
	class aux_map_initializer {
	 private:
		young* ptr;

	 public:
		aux_map_initializer();
		~aux_map_initializer();
	};

	static aux_map_initializer aux_map;
	color col;
	u_vector<taste> tastes;

 public:
	young(const color = white_trasparent, const u_vector<taste>& = {}, bottle_size = medium, const std::string& = "", double = min_ac);  // da fare
	young(const young&);                                                                                                                 // da fare
	young& operator=(const young&);                                                                                                      // da fare
	static const double discount_young;
	virtual young* clone() const override;
	virtual double kind_price() const override;
  virtual double price_increment() const override;
  virtual double get_price() const override;
  virtual double promotion() const override;
  virtual u_vector<taste> get_tastes() const override;
  virtual color get_color() const override;
  virtual std::string code() const override;
  virtual std::string get_image_path() const override;
	virtual young* create(std::map<std::string, QVariant>&) const override;
};
// non ha incrementi di prezzo in quanto è la grappa basica, che non ha la stessa lavorazione di un liquore, di una crema, di un'invecchiata o di una barricata
#endif  //YOUNG_H_
