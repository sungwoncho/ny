#include <stdio.h>
#include <string.h>
#include "token.h"

void
inspect_token(ny_token *tok) {
  const char *type = get_token_type_string(tok);

  printf("Token(%s, %s)\n", type, tok->val);
}

ny_token
ny_token_new(ny_token_type type, char *val) {
  ny_token tok;

  tok.type = type;
  tok.val = val;

  return tok;
}

const char *
get_token_type_string(ny_token *tok) {
  return ny_token_type_strings[tok->type];
}
