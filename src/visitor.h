// #include "node.h"
//
// #ifndef NY_VISITOR_H
// #define NY_VISITOR_H
//
// typedef struct visitor {
//   void (*visit_binop)(struct visitor *self, node_binop *node);
//   void (*visit_unaryop)(struct visitor *self, node_unaryop *node);
//   void (*visit_int)(struct visitor *self, node_int *node);
//   void (*visit_float)(struct visitor *self, node_float *node);
//   void (*visit_node)(struct visitor *self, node *node);
// } visitor;
//
// typedef enum {
//   INT,
//   FLOAT,
//   STRING
// } visitor_result_type;
//
// typedef struct {
//   visitor_result_type type;
//   struct {
//     int as_int;
//     float as_float;
//     char *as_string;
//   } value;
// } visitor_result;
//
// #endif
