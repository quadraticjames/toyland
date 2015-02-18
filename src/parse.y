%{
#include <stdio.h>

int yylex();
int yyerror(char *e);
%}

%token TRUE FALSE INT LOC
%token PLUS GTEQ
%token IF THEN ELSE
%token ASSIGN DEREF
%token SKIP SEQ
%token WHILE DO

%right ASSIGN DEREF
%nonassoc IF THEN ELSE WHILE DO
%left SEQ
%nonassoc GTEQ;
%left PLUS;

%start expr

%%

bool:
        TRUE
    |   FALSE;

number:
        INT;

location:
        LOC;

expr:
        number
    |   bool
    |   expr PLUS expr
    |   expr GTEQ expr
    |   IF expr THEN expr ELSE expr
    |   location ASSIGN expr
    |   DEREF location
    |   SKIP
    |   expr SEQ expr
    |   WHILE expr DO expr;
%%

int yyerror(char *e) {
    printf("ERROR: %s\n", e);
    return 1;
}
