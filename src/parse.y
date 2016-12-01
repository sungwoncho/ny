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

%type <nd> factor
%type <nd> term
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
    term tPLUS expr   {
      $$ = node_binop_new("+", $1, $3);
    }
|   term tMINUS expr   {
      $$ = node_binop_new("-", $1, $3);
    }
|   term
;

term:
    factor tMUL term {
      $$ = node_binop_new("*", $1, $3);
    }
|   factor tDIV term {
      $$ = node_binop_new("/", $1, $3);
    }
|   factor

factor:
    tINT   {
      $$ = $1;
    }
|   tFLOAT   {
      $$ = $1;
    }
|   tLPAREN expr tRPAREN   {
      $$ = $2;
    }
%%


static void
yyerror (parser_state *p, char const *s)
{
  fprintf(stderr, "%d:%s\n", p->lineno, s);
}
