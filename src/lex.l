%{
#include "ast.h"
#include "parse.tab.h"
%}

%option noyywrap

%%

true        { return TRUE; }
false       { return FALSE; }

-?[0-9]+    { yylval.int_val = atol(yytext); return INT; }

l[0-9]+     { yylval.loc_val = atol(yytext+1); return LOC; }

"+"         { return PLUS; }
">="        { return GTEQ; }

if          { return IF; }
then        { return THEN; }
else        { return ELSE; }

":="        { return ASSIGN; }
"!"         { return DEREF; }

skip        { return SKIP; }

";"         { return SEQ; }

while       { return WHILE; }
do          { return DO; }
end         { return END; }

print       { return PRINT; }

[ \t\n]     { }

[a-z].      { return 1; }

<<EOF>>     { return 0; }

.           { printf("Unexpected.\n"); }
