#include "ast.h"
#include "lexer.h"

#ifndef NY_PARSER_H
#define NY_PARSER_H

typedef struct {
  lexer *lexer;
  ny_token current_token;
} parser;

static ny_node * expression(parser *self);
static ny_node * term(parser *self);
static ny_node * factor(parser *self);

void init_parser(parser *self, lexer *lexer);
ny_node *parse(parser *self);
void free_nodes(ny_node *node);

#endif
