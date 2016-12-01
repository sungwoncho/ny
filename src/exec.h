#ifndef _EXEC_H
#define _EXEC_H

#include "node.h"
#include "value.h"
#include <stdio.h>

#define NY_OK 0
#define NY_ERROR 1

static int exec_node(node *np, ny_value *val);
static void print_node(node *, int);
int node_run(parser_state *p);

#endif
