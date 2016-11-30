%{
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include "node.h"
#include "lex.yy.c"

#define DEBUG(msg) printf(msg)
%}

%union {
  node *nd;
}

%type <nd> expr
%pure-parser
%parse-param {parser_state *p}
%lex-param {p}

%{
int yylex(YYSTYPE *lval, parser_state *p);
static void yyerror (parser_state *p, char const  *);
%}

%token <nd> tINT
%token <nd> tFLOAT
%token
        tPLUS
        tMINUS
        tMUL
        tDIV
        tLPAREN
        tRPAREN

%left tPLUS tMINUS
%left tMUL tDIV


%%
program:
    expr {
      p->lval = $1;
    }
;

expr:
    tINT   {
      $$ = $1;
    }
|   tFLOAT   { $$ = $1; }
|   expr tPLUS expr   { $$ = node_binop_new("+", $1, $3); }
|   expr tMINUS expr   {
      $$ = node_binop_new("-", $1, $3);
    }
|   expr tMUL expr   { $$ = node_binop_new("*", $1, $3); }
|   expr tDIV expr   { $$ = node_binop_new("/", $1, $3); }
|   tLPAREN expr tRPAREN   { $$ = $2; }
;
%%


static void
yyerror (parser_state *p, char const *s)
{
  fprintf(stderr, "%d:%s\n", p->lineno, s);
}
