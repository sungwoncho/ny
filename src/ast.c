#include <string.h>
#include <stdlib.h>
#include "token.h"
#include "ast.h"

ny_node_int *
ny_node_int_new(int val) {
  ny_node_int *node = malloc(sizeof(ny_node_int));
  node->base.type = NY_NODE_INT;
  node->val = val;

  return node;
}

ny_node_float *
ny_node_float_new(float val) {
  ny_node_float *node = malloc(sizeof(ny_node_float));
  node->base.type = NY_NODE_FLOAT;
  node->val = val;

  return node;
}

ny_node_binop *
ny_node_binop_new(ny_token tok, ny_node *left, ny_node *right) {
  ny_node_binop *node = malloc(sizeof(ny_node_binop));

  node->base.type = NY_NODE_BINOP;
  node->op = tok;
  node->left = left;
  node->right = right;

  return node;
}

ny_node_unaryop *
ny_node_unary_op_new(ny_token tok, ny_node *factor) {
  ny_node_unaryop *node = malloc(sizeof(ny_node_unaryop));

  node->base.type = NY_NODE_UNARYOP;
  node->op = tok;
  node->factor = factor;

  return node;
}

const char *
get_node_type_string(ny_node *node) {
  return ny_node_type_strings[node->type];
}
