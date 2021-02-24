#include <iostream>

#include "Hierarchy/cream.h"
#include "Hierarchy/grappa.h"
#include "Hierarchy/liquor.h"
#include "Hierarchy/non_spirits.h"
#include "Hierarchy/old.h"
#include "Hierarchy/product.h"
#include "Hierarchy/spirits.h"
#include "Hierarchy/young.h"
#include "Utilities/Contenitore/u_vector.hpp"
#include "Utilities/DeepPtr/deep_ptr.hpp"

u_vector<deep_ptr<product>> v(10, 10);
u_vector<taste> t(4, 4);
for (auto cit = t.const_begin(); cit != t.const_end(); cit++) {
  (*cit) = _chocolate;
}
deep_ptr<product> p(yellow, const u_vector<taste>&, medium, "Limone", 18);