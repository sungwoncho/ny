#include <stdio.h>
#include "visitor.h"


// FIXME: how to implement method missing error?
#define VISIT(type) \
  if (!self->visit_##type) break; \
  self->visit_##type(self, (ny_node_##type *) node); \
  break;

void
visit_node(visitor *self, ny_node *node) {
  switch (node->type) {
    case NY_NODE_BINOP: VISIT(binop);
    case NY_NODE_UNARYOP: VISIT(unaryop);
    case NY_NODE_INT: VISIT(int);
    case NY_NODE_FLOAT: VISIT(float);
  }
}
