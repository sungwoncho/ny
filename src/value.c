#include "value.h"

static inline int32_t
ny_to_int(ny_value v) {
  return (int32_t)(v & ~NY_TAG_MASK);
}

int32_t
ny_value_int(ny_value v) {
  switch (ny_value_tag(v)) {
    case NY_TAG_INT:
      return ny_to_int(v);
    default:
      // float
      break;
  }

  return 0;
}

ny_value
ny_int_value(int32_t i) {
  return NY_TAG_INT | ((uint64_t)i & NY_VAL_MASK);
}
