#include "exec.h"
#include <string.h>

int
node_run(parser_state *p) {
  int status;
  ny_value v;

  print_node((node*)p->lval, 0);
  return 0;

  // status = exec_node((node*)p->lval, &v);
  // printf("result %llu\n", v);
  // return status;
}

static void
print_node(node *np, int indent) {
  int i;
  for (i = 0; i < indent; i++) putchar(' ');

  switch (np->type) {
     case NODE_BINOP:
       {
         node_binop *nbop = (node_binop*)np;
         inspect_node(np);

         indent++;
         print_node(nbop->lhs, indent);
         print_node(nbop->rhs, indent);
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

static int
exec_node(node *np, ny_value *val) {
  int n;

  switch (np->type) {
    case NODE_BINOP:
      {
        node_binop *nbinop = (node_binop*)np;
        ny_value args[2];
        int i = 0;

        n = exec_node(nbinop->lhs, &args[i++]);
        if (n) return n;
        n = exec_node(nbinop->rhs, &args[i++]);
        if (n) return n;

        if (strcmp(nbinop->op, "+") == 0) {
          printf("%d + %d\n", ny_value_int(args[0]), ny_value_int(args[1]));
          *val = ny_value_int(args[0]) + ny_value_int(args[1]);
        } else if ((strcmp(nbinop->op, "-") == 0)) {
          *val = ny_value_int(args[0]) - ny_value_int(args[1]);
        } else if ((strcmp(nbinop->op, "*") == 0)) {
          *val = ny_value_int(args[0]) * ny_value_int(args[1]);
        } else if ((strcmp(nbinop->op, "/") == 0)) {
          *val = ny_value_int(args[0]) / ny_value_int(args[1]); // TODO: return float
        }
        return NY_OK;
      } break;
    case NODE_INT:
      {
        *val = ny_int_value(((node_int*)np)->val);
        return NY_OK;
      } break;
    case NODE_FLOAT:
      {
        // TODO: float
        return NY_OK;
      } break;
    default:
      printf("unknown node\n");
      break;
  }

  return NY_ERROR;
}
