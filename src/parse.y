%{
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include "node.h"
int yylex (void);
void yyerror (char const  *);
%}

%union {
  node *nd;
}

%token <nd> tINT
%token <nd> tFLOAT
%token tNEWLINE
%left '+' '-'
%left '*' '/'

%type <nd> expr

%%
expr:
    tINT   { $$ = node_int_new(1111); }
|   tFLOAT   { $$ = node_float_new(2222); }
|   expr '+' expr   { $$ = node_binop_new("+", $1, $3); }
|   expr '-' expr   { $$ = node_binop_new("-", $1, $3); }
|   expr '*' expr   { $$ = node_binop_new("*", $1, $3); }
|   expr '/' expr   { $$ = node_binop_new("/", $1, $3); }
|   '(' expr ')'   { $$ = $2; }
;
%%

int
yylex (void)
{
//   int c;
//
// while ((c = getchar()) == ' ' || c == '\t')
//   continue;
//
// if (c == '.' || isdigit(c))
//   {
//     ungetc(c, stdin);
//     scanf("%lf", &yylval);
//     return tINT;
//   }
//
//   if (c == EOF)
//     return 0;
//
//   return c;
}

void
yyerror (char const *s)
{
  fprintf(stderr, "%s\n", s);
}
