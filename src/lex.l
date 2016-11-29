%{
#include <stdio.h>

#include "parse.tab.h"
%}

%%

[ \t]   ;
[0-9]+\.[0-9]+
[0-9]+
\n
"+"
"-"
"*"
"/"
"("
")"

%%
