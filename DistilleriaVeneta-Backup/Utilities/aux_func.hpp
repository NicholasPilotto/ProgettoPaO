#ifndef __AUX_FUNC_H__
#define __AUX_FUNC_H__

#include <math.h>

#include <iostream>

template <typename F>
F trunc_decs(const F& f) {
  int i1 = floor(f);
  F rmnd = (floor((f - i1) * 10) + 1) / 10;
  int i2 = static_cast<int>(rmnd * pow(10, 2));
  F f1 = i2 / pow(10, 2);

  return i1 + f1;
}

#endif  // __AUX_FUNC_H__