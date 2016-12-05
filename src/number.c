#include "number.h"
#include "ny.h"

// TODO: initialize functions in the built-in symbol table
// maybe namespace it using ny_ns_number?
void
ny_number_init() {

}

// TODO: this should not be directly used. make it static and register
// to symbol table using ny_number_init

int
num_plus(ny_value *x, ny_value *y, ny_value *ret) {
  if (ny_int_p(*x) && ny_int_p(*y)) {
    *ret = ny_int_value(ny_value_int(*x) + ny_value_int(*y));
    return NY_OK;
  }

  if (ny_number_p(*x) || ny_number_p(*y)) {
    *ret = ny_float_value(ny_value_float(*x) + ny_value_float(*y));
    return NY_OK;
  }

  return NY_ERROR;
}

int
num_minus(ny_value *x, ny_value *y, ny_value *ret) {
  if (ny_int_p(*x) && ny_int_p(*y)) {
    *ret = ny_int_value(ny_value_int(*x) - ny_value_int(*y));
    return NY_OK;
  }

    if (ny_number_p(*x) || ny_number_p(*y)) {
      *ret = ny_float_value(ny_value_float(*x) - ny_value_float(*y));
      return NY_OK;
    }

    return NY_ERROR;
}

int
num_mul(ny_value *x, ny_value *y, ny_value *ret) {
  if (ny_int_p(*x) && ny_int_p(*y)) {
    *ret = ny_int_value(ny_value_int(*x) * ny_value_int(*y));
    return NY_OK;
  }

  if (ny_number_p(*x) || ny_number_p(*y)) {
    *ret = ny_float_value(ny_value_float(*x) * ny_value_float(*y));
    return NY_OK;
  }

  return NY_ERROR;
}

int
num_div(ny_value *x, ny_value *y, ny_value *ret) {
  *ret = ny_float_value(ny_value_float(*x) / ny_value_float(*y));
  return NY_OK;
}
