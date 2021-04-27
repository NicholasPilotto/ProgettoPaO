#ifndef CREAM_H_
#define CREAM_H_

#include <algorithm>

#include "non_spirits.h"

class cream : public non_spirits {
 private:
    class aux_map_initializer {
     private:
        cream* ptr;

     public:
        aux_map_initializer();
        ~aux_map_initializer();
    };
    static aux_map_initializer aux_map;
    color col;
    u_vector<taste> tastes;

 protected:
  static const double cream_incr;

 public:
    cream(const color = white, const u_vector<taste>& = {}, bottle_size = medium, const std::string& = "", double = min_ac);
    cream(const cream&);
    cream& operator=(const cream&);
    static const double discount_cream;
    static const double min_ac;
    static const double max_ac;
    virtual cream* clone() const override;
    virtual double kind_price() const override;
    virtual double price_increment() const override;
    virtual double get_price() const override;
    virtual double promotion() const override;
    virtual u_vector<taste> get_tastes() const override;
    virtual color get_color() const override;
    virtual std::string code() const override;
    virtual std::string get_image_path() const override;
    virtual cream* create(QMap<QString, QVariant>&) const override;
    //	virtual std::string write() const;
};

#endif  // CREAM_H_
