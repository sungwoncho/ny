// #include <stdio.h>
// #include "print_ast.h"
//
// // TODO: print tree in console
//
// void
// visit_int(visitor *self, ny_node_int *node) {
//   printf(" (int %d)", node->val);
// }
//
// void
// visit_float(visitor *self, ny_node_float *node) {
//   printf(" (float %f)", node->val);
// }
//
// void
// visit_binop(visitor *self, ny_node_binop *node) {
//   printf("%s", node->op.val);
//   visit_node(self, node->left);
//   visit_node(self, node->right);
// }
//
// void
// visit_unaryop(visitor *self, ny_node_unaryop *node) {
//   printf("%s", node->op.val);
//   visit_node(self, node->factor);
// }
//
// void
// print_tree(ny_node *node) {
//   visitor v = {
//     .visit_int = visit_int,
//     .visit_float = visit_float,
//     .visit_binop = visit_binop,
//     .visit_unaryop = visit_unaryop
//   };
//
//   visit_node(&v, node);
//   printf("\n");
// }
