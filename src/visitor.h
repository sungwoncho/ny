#include "ast.h"

#ifndef NY_VISITOR_H
#define NY_VISITOR_H

typedef struct visitor {
  void (*visit_binop)(struct visitor *self, ny_node_binop *node);
  void (*visit_unaryop)(struct visitor *self, ny_node_unaryop *node);
  void (*visit_int)(struct visitor *self, ny_node_int *node);
  void (*visit_float)(struct visitor *self, ny_node_float *node);
  void (*visit_node)(struct visitor *self, ny_node *node);
} visitor;

typedef enum {
  INT,
  FLOAT,
  STRING
} visitor_result_type;

typedef struct {
  visitor_result_type type;
  struct {
    int as_int;
    float as_float;
    char *as_string;
  } value;
} visitor_result;

#endif
