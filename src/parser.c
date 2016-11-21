#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "parser.h"
#include "lexer.h"

// eat moves on to the next token, if the current token matches the given type
static void
eat(parser *self, ny_token_type token_type) {
  if (self->current_token.type == token_type) {
    self->current_token = scan(self->lexer);
  } else {
    printf("Error: token mismatch. %s - %s\n", ny_token_type_strings[token_type], get_token_type_string(&self->current_token));
    // TODO: Error
  }
}

/**
 * expression : term ((PLUS | MINUS) term)*
 */
static ny_node *
expression(parser *self) {
  ny_node *node, *right;
  node = term(self);

  while (
    self->current_token.type == NY_TOKEN_PLUS ||
    self->current_token.type == NY_TOKEN_MINUS
  ) {
    ny_token token = self->current_token;

    if (token.type == NY_TOKEN_PLUS) {
      eat(self, NY_TOKEN_PLUS);
    } else if (token.type == NY_TOKEN_MINUS) {
      eat(self, NY_TOKEN_MINUS);
    }

    right = term(self);
    node = (ny_node *) ny_node_binop_new(token, node, right);
  }

  return  node;
}

/**
 * term : factor ((MUL | DIV) factor)*
 */
static ny_node *
term(parser *self) {
  ny_node *node, *right;
  node = factor(self);

  while (
    self->current_token.type == NY_TOKEN_MUL ||
    self->current_token.type == NY_TOKEN_DIV
  ) {
    ny_token token = self->current_token;

    if (token.type == NY_TOKEN_MUL) {
      eat(self, NY_TOKEN_MUL);
    } else if (token.type == NY_TOKEN_DIV) {
      eat(self, NY_TOKEN_DIV);
    }

    right = factor(self);
    node = (ny_node *) ny_node_binop_new(token, node, right);
  }

  return  node;
}

/**
 * factor : INTEGER
          | FLOAT
          | LPAREN expr RPAREN
 */
static ny_node *
factor(parser *self) {
  ny_node *ret;
  switch (self->current_token.type) {
    case NY_TOKEN_INT:
      ret = (ny_node *) ny_node_int_new(atoi(self->current_token.val));
      eat(self, NY_TOKEN_INT);
      break;
    case NY_TOKEN_FLOAT:
      ret = (ny_node *) ny_node_float_new(atof(self->current_token.val));
      eat(self, NY_TOKEN_FLOAT);
      break;
    case NY_TOKEN_LPAREN:
      eat(self, NY_TOKEN_LPAREN);
      ret = expression(self);
      eat(self, NY_TOKEN_RPAREN);
    default:
      break;
  }

  return ret;
}

ny_node *
parse(parser *self) {
  ny_node *node = expression(self);

  if (self->current_token.type != NY_TOKEN_EOF) {
    printf("error: no EOF\n");
    //TODO: error
  }

  return node;
}

void
free_nodes(ny_node *node) {
  switch (node->type) {
    case NY_NODE_BINOP:
      free_nodes(((ny_node_binop *) node)->left);
      free_nodes(((ny_node_binop *) node)->right);
      free(node);
      break;
    case NY_NODE_INT:
      free(node);
      break;
    case NY_NODE_FLOAT:
      free(node);
      break;
    default:
      break;
  }
}

void
init_parser(parser *self, lexer *lexer) {
  self->lexer = lexer;
  self->current_token = scan(lexer);
}
