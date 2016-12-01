#ifndef _NODE_H
#define _NODE_H

#define NODE_HEADER node_type type

typedef enum {
  NODE_INT,
  NODE_FLOAT,
  NODE_BINOP,
  NODE_UNARYOP,
} node_type;

typedef struct {
  void *lval;
  int lineno;
} parser_state;

typedef struct {
  NODE_HEADER;
} node;

typedef struct {
  NODE_HEADER;
  char *op;
  node *lhs;
  node *rhs;
} node_binop;

typedef struct {
  NODE_HEADER;
  int val;
} node_int;

typedef struct {
  NODE_HEADER;
  float val;
} node_float;

typedef struct {
  NODE_HEADER;
  char *op;
  node *factor;
} node_unaryop;

node *node_binop_new(const char *op, node *lhs, node *rhs);
node *node_int_new(int val);
node *node_float_new(float val);
void node_free(node *np);
void inspect_node(node *np);

#endif
