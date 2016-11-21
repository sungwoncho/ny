#include <string.h>
#include <stdlib.h>
#include "token.h"

#ifndef NY_AST_H
#define NY_AST_H

#define NY_NODE_LIST \
  X(INT, "int") \
  X(FLOAT, "float") \
  X(BINOP, "binop") \
  X(UNARYOP, "unaryop") \

typedef enum {
  #define X(num, str) NY_NODE_##num,
  NY_NODE_LIST
  #undef X
} ny_node_type;

static char *ny_node_type_strings[] = {
  #define X(num, str) str,
  NY_NODE_LIST
  #undef X
};

// node structs
typedef struct {
  ny_node_type type;
} ny_node;

typedef struct {
  ny_node base; // IDEA: do I need to free base?
  ny_token op;
  ny_node *left;
  ny_node *right;
} ny_node_binop;

typedef struct {
  ny_node base;
  int val;
} ny_node_int;

typedef struct {
  ny_node base;
  float val;
} ny_node_float;

typedef struct {
  ny_node base;
  ny_token op;
  ny_node *factor;
} ny_node_unaryop;

// prototypes
ny_node_int *ny_node_int_new(int val);
ny_node_float *ny_node_float_new(float val);
ny_node_binop *ny_node_binop_new(ny_token tok, ny_node *left, ny_node *right);
ny_node_unaryop * ny_node_unary_op_new(ny_token tok, ny_node *factor);

const char *get_node_type_string(ny_node *node);

#endif
