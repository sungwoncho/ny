#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "token.h"
#include "lexer.h"

void
advance(lexer *self) {
  self->pos++;
  self->current_char = self->text[self->pos];
  // if (self->pos > strlen(self->text) + 1) {
  //   self->current_char = '\0';
  // } else {
  //   self->current_char = self->text[self->pos];
  // }
}

ny_token
scan_number(lexer *self) {
  char buf[BUFSIZE];
  int i;
  int has_dot = 0;

  for (i = 0; i < BUFSIZE; i++) {
    if (isdigit(self->current_char)) {
      buf[i] = self->current_char;
      advance(self);
    } else if (self->current_char == '.' && !has_dot) {
      printf("has_dot\n");
      has_dot = 1;
      buf[i] = self->current_char;
      advance(self);
    } else if (self->current_char == '.' && has_dot) {
      printf("error. more than one dots\n");
      // error
    } else {
      buf[i] = '\0';
      break;
    }
  }

  if (has_dot) {
    printf("buf: %s\n", buf);
    return ny_token_new(NY_TOKEN_FLOAT, strdup(buf)); // FIXME: leak
  }

  return ny_token_new(NY_TOKEN_INT, strdup(buf)); // FIXME: leak
}

ny_token
scan(lexer *self) {
  while (self->current_char != '\0') {
    // Skip whitespace
    while (isspace(self->current_char)) {
      advance(self);
    }

    if (isdigit(self->current_char)) {
      return scan_number(self);
    }
    if (self->current_char == '+') {
      advance(self);
      return ny_token_new(NY_TOKEN_PLUS, "+");
    }
    if (self->current_char == '-') {
      advance(self);
      return ny_token_new(NY_TOKEN_MINUS, "-");
    }
    if (self->current_char == '*') {
      advance(self);
      return ny_token_new(NY_TOKEN_MUL, "*");
    }
    if (self->current_char == '/') {
      advance(self);
      return ny_token_new(NY_TOKEN_DIV, "/");
    }

    // TODO: if reached this point, error
  }

  return ny_token_new(NY_TOKEN_EOF, "EOF");
}

void
init_lexer(lexer *self) {
  self->pos = 0;
  self->current_char = self->text[0];
}
