#include "token.h"

#ifndef NY_LEXER_H
#define NY_LEXER_H
#define BUFSIZE 128

typedef struct {
  char *text;
  int pos;
  char current_char;
} lexer;

ny_token scan(lexer *self);
void init_lexer(lexer *self, char *text);

#endif
