#include <stdio.h>
#include "visitor.h"
#include "ast.h"

// FIXME: how to implement method missing error?
#define VISIT(type) \
  if (!self->visit_##type) break; \
  self->visit_##type(self, (ny_node_##type *) node); \
  break;

void
visit_int(visitor *self, ny_node_int *node) {
  printf(" (int %d)", node->val);
}

void
visit_float(visitor *self, ny_node_float *node) {
  printf(" (float %f)", node->val);
}

void
visit_binop(visitor *self, ny_node_binop *node) {
  printf("%s", node->op.val);

  printf("\nleft:\n");
  visit_node(self, node->left);
  printf("\nright:\n");
  visit_node(self, node->right);
}

void
visit_node(visitor *self, ny_node *node) {
  switch (node->type) {
    case NY_NODE_BINOP: VISIT(binop);
    case NY_NODE_INT: VISIT(int);
    case NY_NODE_FLOAT: VISIT(float);
  }
}

void
print_nodes(ny_node *node) {
  visitor v = {
    .visit_node = visit_node,
    .visit_float = visit_float,
    .visit_binop = visit_binop,
    .visit_int = visit_int
  };

  visit_node(&v, node);
  printf("\n");
}
