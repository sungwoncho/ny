// nyc baby
#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "token.h"
#include "linenoise.h"

void
repl() {
  lexer l;

  char *line;
  while ((line = linenoise("ny > ")) != NULL) {
    l.text = line;
    printf("line %s\n", line);
    init_lexer(&l);

    ny_token tok = scan(&l);
    inspect_token(&tok);
  }
  free(line);
}

int
main(int argc, char const *argv[]) {

  // repl
  if (argc == 1) {
    repl();
  }
}
