// nyc baby
#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"
#include "token.h"
#include "linenoise.h"
#include "print_ast.h"
#include "utils.h"

void
repl() {
  lexer l;
  parser p;

  char *line;
  while ((line = linenoise("ny> ")) != NULL) {
    init_lexer(&l, line);
    init_parser(&p, &l);

    ny_node *node = parse(&p);
    print_tree(node);
    free_nodes(node);

    linenoiseHistoryAdd(line);
  }
  free(line);
}

/**
 * eval evaluates the given source.
 */
int
eval(char *source) {
  lexer l;
  parser p;

  init_lexer(&l, source);
  init_parser(&p, &l);

  ny_node *node = parse(&p);
  print_tree(node);
  free_nodes(node);
  free(source);

  return 0;
}

/**
 * Usage:
 * [1] ny
 * [2] ny filename.ny
 */
int
main(int argc, char const *argv[]) {
  const char *path;
  char *source;

  if (argc == 1) {
    repl();
  } else if (argc == 2) {
    path = argv[1];

    source = read_file(path);
    return eval(source);
  }
}
