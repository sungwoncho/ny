#ifndef _EXEC_H
#define _EXEC_H

#include "node.h"
#define NY_OK 1
#define NY_ERROR 1

int node_run(parser_state *p);
void visit_node(node *np);

#endif
