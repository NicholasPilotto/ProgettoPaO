#ifndef ENUM_H_
#define ENUM_H_

enum bottle_size {
  small,
  medium,
  big
};

enum taste {
  lemon = 10,
  halzenhut = 11,
  coffee = 12,
  licorice = 13,
  chocolate = 14,
  egg = 15,
  rum = 16,
  cream = 17,
  strawberry = 18,
  berries = 19,
  blueberry = 20,
  ribes = 21,
  plum = 22,
  honey = 23,
  dry = 24,
  smooth = 25,
  amable = 26
};  // differenza tra smooth e amable:
    // smooth -> invecchiata
    // amable -> più amabile

enum color {
  yellow,
  red,
  pink,
  brown,
  black,
  violet,
  white,
  white_trasparent,
  yellow_trasparent
};

enum bag_size {
  single_bag,
  double_bag,
  triple_bag
};
#endif  // ENUM_H_