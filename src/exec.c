#include "exec.h"

int
node_run(parser_state *p) {
  visit_node((node*)p->lval);

  return NY_OK;
}

void
visit_node(node *np) {
  switch (np->type) {
    case NODE_BINOP:
      {
        node_binop *nbop = (node_binop*)np;
        inspect_node(np);
        visit_node(nbop->lhs);
        visit_node(nbop->rhs);
        break;
      }
    case NODE_INT:
      inspect_node(np);
      break;
    case NODE_FLOAT:
      inspect_node(np);
      break;
    default:
      break;
  }
}
