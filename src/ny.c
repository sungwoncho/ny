// nyc baby
#include "ny.h"
#include "parse.tab.h"

void
repl() {
  parser_state state;

  yyparse(&state);
  node_run(&state);
}

/**
 * eval evaluates the given source.
 */
int
eval(char *source) {
  // lexer l;
  // parser p;
  //
  // init_lexer(&l, source);
  // init_parser(&p, &l);
  //
  // ny_node *node = parse(&p);
  // print_tree(node);
  // free_nodes(node);
  // free(source);
  //
  // return 0;
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

void
ny_init() {
  ny_number_init();
}
