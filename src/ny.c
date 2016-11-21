// nyc baby
#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"
#include "token.h"
#include "linenoise.h"
#include "print_ast.h"

void
repl() {
  lexer l;
  parser p;

  char *line;
  while ((line = linenoise("ny> ")) != NULL) {
    l.text = line;
    init_lexer(&l);
    init_parser(&p, &l);

    ny_node *node = parse(&p);
    print_tree(node);
    free_nodes(node);

    linenoiseHistoryAdd(line);
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
