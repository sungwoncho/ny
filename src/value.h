#ifndef _H_VALUE
#define _H_VALUE

#include <stdint.h>

/********* value types */

// 64 bit
// 0x0000000000000000-0xFFFFFFFFFFFFFFFF
#define NY_MAKE_TAG(n) ((uint64_t)(0xFFF0|n) << 48)
enum ny_value_tag {
  NY_TAG_NAN = NY_MAKE_TAG(0x00), // 0xfff0000000000000 (1111111111110000000000000000000000000000000000000000000000000000)
  NY_TAG_INT = NY_MAKE_TAG(0x01), // 0xfff1000000000000 (1111111111110001000000000000000000000000000000000000000000000000)
  NY_TAG_FLOAT = NY_MAKE_TAG(0x02),
};

// 0xffff000000000000
// 1111111111111111000000000000000000000000000000000000000000000000
#define NY_TAG_MASK NY_MAKE_TAG(0x0F)

// 0xffffffffffff
// 111111111111111111111111111111111111111111111111
#define NY_VAL_MASK ~NY_TAG_MASK

#define ny_value_tag(v) ((v) & NY_TAG_MASK)

typedef uint64_t ny_value;

ny_value ny_int_value(int32_t i);
int32_t ny_value_int(ny_value v);
double ny_value_float(ny_value v);
ny_value ny_float_value(double f);
int ny_int_p(ny_value);
int ny_float_p(ny_value v);
int ny_number_p(ny_value v);

#endif
