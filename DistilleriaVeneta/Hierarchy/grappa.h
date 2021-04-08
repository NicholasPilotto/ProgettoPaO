#ifndef GRAPPA_H_
#define GRAPPA_H_

#include "spirits.h"

class grappa : public spirits {
 private:

 protected:
	static const double grappa_incr;

 public:
	grappa(const color = white_trasparent, const u_vector<taste>& = {}, bottle_size = medium, const std::string& = " ", double = min_ac);  // da controllare
	grappa(const grappa&);                                                                                                                 // da controllare
	grappa& operator=(const grappa&);                                                                                                      // da controllare
	static const double min_ac;
	static const double max_ac;
	virtual double kind_price() const override;
	virtual double price_increment() const override;
	virtual double get_price() const override;
	virtual std::string code() const override;
	virtual std::string get_image_path() const override;
	virtual ~grappa() = default;
};

#endif  // GRAPPA_H_
