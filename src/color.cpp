#include "color.hpp"
#include "types.hpp"

typedef Color Self;


Self::Color(const usize i) {
  constexpr unit d = 1.0 / (unit) 0xff;
  r = (unit) ((i >> 24)       ) * d;
  g = (unit) ((i >> 16) & 0xff) * d;
  b = (unit) ((i >>  8) & 0xff) * d;
  a = (unit) ((i      ) & 0xff) * d;
}

