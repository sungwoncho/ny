%{
#include <stdio.h>
#include "parse.tab.h"

#define YY_DECL     int yylex(YYSTYPE *lval, parser_state *p)

static int
lex_return(parser_state *p, int c) {
  p->lineno = yylineno;
  return c;
}

#define LEX_RETURN(c) return lex_return(p, c)
%}

%option noyywrap

%%

([ \t]|"#")*   ;
"+"   LEX_RETURN(tPLUS);
"-"   LEX_RETURN(tMINUS);
"*"   LEX_RETURN(tMUL);
"/"   LEX_RETURN(tDIV);
"("   LEX_RETURN(tLPAREN);
")"   LEX_RETURN(tRPAREN);

[0-9]+\.[0-9]+ {
  lval->nd = node_float_new(atof(yytext));
  LEX_RETURN(tFLOAT);
};

[0-9]+ {
  lval->nd = node_int_new(atoi(yytext));
  LEX_RETURN(tINT);
}

%%
