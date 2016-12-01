#include "value.h"

static inline int32_t
ny_to_int(ny_value v) {
  return (int32_t)(v & ~NY_TAG_MASK);
}

static inline double
ny_to_float(ny_value v) {
  union {
    double f;
    uint64_t i;
  } u;

  u.i = v;
  return u.f;
}

int
ny_int_p(ny_value v) {
  return ny_value_tag(v) == NY_TAG_INT;
}

// int
// ny_float_p(ny_value v) {
// }

int32_t
ny_value_int(ny_value v) {
  switch (ny_value_tag(v)) {
    case NY_TAG_INT:
      return ny_to_int(v);
    default:
      return ny_to_float(v);
      break;
  }

  return 0;
}

ny_value
ny_int_value(int32_t i) {
  return NY_TAG_INT | ((uint64_t)i & NY_VAL_MASK);
}

ny_value
ny_float_value(double f) {
  union {
    double f;
    uint64_t i;
  } u;

  u.f = f;
  return u.i;
}

double
ny_value_float(ny_value v) {
  return ny_to_float(v);
}
