%{
#include <stdio.h>

int yylex();
int yyerror(char *e);
%}

%token TRUE FALSE INT

%%

bool:
        TRUE
    |   FALSE;

%%

int yyerror(char *e) {
    printf("ERROR: %s", e);
    return 1;
}
