#ifndef _H_NUMBER
#define _H_NUMBER

#include "value.h"

void ny_number_init();
int num_plus(ny_value *, ny_value *, ny_value *);
int num_minus(ny_value *, ny_value *, ny_value *);
int num_mul(ny_value *, ny_value *, ny_value *);
int num_div(ny_value *, ny_value *, ny_value *);

#endif
