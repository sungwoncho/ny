#ifndef NY_TOKEN_H
#define NY_TOKEN_H

#define NY_TOKEN_LIST \
  X(INTEGER, "Integer") \
  X(FLOAT, "Float") \
  X(PLUS, "Plus") \
  X(MINUS, "Minus") \
  X(MUL, "Mul") \
  X(DIV, "Div") \
  X(EOF, "EOF")


typedef enum {
  #define X(enum, str) NY_##enum,
  NY_TOKEN_LIST
  #undef X
} ny_token_type;

static char *ny_token_type_strings[] = {
  #define X(enum, str) str,
  NY_TOKEN_LIST
  #undef X
};

typedef struct {
  ny_token_type type;
  char *val;
} ny_token;

void inspect_token(ny_token *tok);

static const char *get_token_type_string(ny_token *tok);

ny_token get_token(ny_token_type type, char *val);

#endif
