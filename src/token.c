#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "token.h"

void
inspect_token(ny_token *tok) {
  const char *type = get_token_type_string(tok);

  printf("Token(%s, %s)\n", type, tok->val);
}

// IDEA: do I need to free ny_token?
ny_token
ny_token_new(ny_token_type type, char *val) {
  ny_token tok;

  char *tok_val = malloc(strlen(val));
  strcpy(tok_val, val);

  tok.type = type;
  tok.val = tok_val;

  return tok;
}

const char *
get_token_type_string(ny_token *tok) {
  return ny_token_type_strings[tok->type];
}
