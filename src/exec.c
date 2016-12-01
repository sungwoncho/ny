#include "exec.h"
#include "number.h"
#include <string.h>

// debug flag
#define DEBUG 0

int
node_run(parser_state *p) {
  int status;
  ny_value v;

  if (DEBUG) {
    print_node((node*)p->lval, 0);
    return NY_OK;
  }

  status = exec_node((node*)p->lval, &v);
  if (ny_int_p(v)) {
    printf("result %d\n", ny_value_int(v));
  } else {
    printf("result %f\n", ny_value_float(v));
  }
  return status;
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
          num_plus(&args[0], &args[1], val);
        } else if ((strcmp(nbinop->op, "-") == 0)) {
          num_minus(&args[0], &args[1], val);
        } else if ((strcmp(nbinop->op, "*") == 0)) {
          num_mul(&args[0], &args[1], val);
        } else if ((strcmp(nbinop->op, "/") == 0)) {
          num_div(&args[0], &args[1], val);
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
        *val = ny_float_value(((node_float*)np)->val);
        return NY_OK;
      } break;
    default:
      printf("unknown node\n");
      break;
  }

  return NY_ERROR;
}
