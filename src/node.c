#include <string.h>
#include <stdlib.h>
#include "node.h"

node*
node_binop_new(const char *op, node *lhs, node *rhs) {
  node_binop *nbinop = malloc(sizeof(node_binop));

  nbinop->type = NODE_BINOP;
  nbinop->op = strdup(op);
  nbinop->lhs = lhs;
  nbinop->rhs = rhs;

  return (node*)nbinop;
}

node*
node_int_new(int val) {
  node_int *ni = malloc(sizeof(node_int));

  ni->type = NODE_INT;
  ni->val = val;

  return (node*)ni;
}

node *
node_float_new(float val) {
  node_float *nf = malloc(sizeof(node_float));

  nf->type = NODE_FLOAT;
  nf->val = val;

  return (node*)nf;
}

void
node_free(node *np) {
  switch (np->type) {
    case NODE_BINOP:
      node_free(((node_binop *)np)->lhs);
      node_free(((node_binop *)np)->rhs);
      free(np); // IDEA: does this free the result of strdup(op) in node_binop_new?
      break;
    case NODE_INT:
    case NODE_FLOAT:
      free(np);
      break;
    case NODE_UNARYOP:
      //TODO
      break;
  }
}
