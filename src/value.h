#ifndef _H_VALUE
#define _H_VALUE

#include <stdint.h>

// value types
#define NY_MAKE_TAG(n) ((uint64_t)(0xFFF0|n) << 48)
enum ny_value_tag {
  NY_TAG_INT = NY_MAKE_TAG(0x00),
  NY_TAG_FLOAT = NY_MAKE_TAG(0x01),
};

#define NY_TAG_MASK NY_MAKE_TAG(0x0F)// 0xFFFFF
#define NY_VAL_MASK ~NY_TAG_MASK
#define ny_value_tag(v) ((v) & NY_TAG_MASK)

typedef uint64_t ny_value;


ny_value ny_int_value(int32_t i);
int32_t ny_value_int(ny_value v);
double ny_value_float(ny_value v);
ny_value ny_float_value(double f);
int ny_int_p(ny_value);

#endif
