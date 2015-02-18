%{
#include "parse.tab.h"
%}

%option noyywrap

%%

true        { return TRUE; }
false       { return FALSE; }

-?[0-9]+    { return INT; }

l[0-9]+     { return LOC; }

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
