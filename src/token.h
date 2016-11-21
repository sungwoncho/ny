#ifndef NY_TOKEN_H
#define NY_TOKEN_H

#define NY_TOKEN_LIST \
  X(INT, "Int") \
  X(FLOAT, "Float") \
  X(PLUS, "Plus") \
  X(MINUS, "Minus") \
  X(MUL, "Mul") \
  X(DIV, "Div") \
  X(LPAREN, "LPAREN") \
  X(RPAREN, "RPAREN") \
  X(EOF, "EOF")


typedef enum {
  #define X(num, str) NY_TOKEN_##num,
  NY_TOKEN_LIST
  #undef X
} ny_token_type;

static char *ny_token_type_strings[] = {
  #define X(num, str) str,
  NY_TOKEN_LIST
  #undef X
};

typedef struct {
  ny_token_type type;
  char *val;
} ny_token;

void inspect_token(ny_token *tok);

const char *get_token_type_string(ny_token *tok);

ny_token ny_token_new(ny_token_type type, char *val);

#endif
