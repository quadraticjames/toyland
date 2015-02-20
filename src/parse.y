%{
#include <stdio.h>

#include "ast.h"

int yylex();
int yyerror(char *e);

extern char *yytext;
#define YYDEBUG_LEXER_TEXT yytext

node *root;
%}

%union {
    node *node_t;
    long int_val;
    unsigned long loc_val;
}

%token TRUE FALSE INT LOC
%token PLUS SUB MUL DIV
%token GTEQ LTEQ GT LT EQ NEQ
%token IF THEN ELSE
%token ASSIGN DEREF
%token SKIP SEQ
%token WHILE DO
%token END
%token PRINT

%nonassoc IF THEN ELSE WHILE DO
%left SEQ
%right ASSIGN DEREF
%nonassoc GTEQ;
%left PLUS SUB MUL DIV

%type <node_t> bool number expr
%type <loc_val> location

%start prog

%%

prog:
        expr { root = $1; };

bool:
        TRUE { $$ = bool_node(1); }
    |   FALSE { $$ = bool_node(0); };

number:
        INT { $$ = int_node($<int_val>1); };

location:
        LOC { $$ = $<loc_val>1; };

expr:
        number { $$ = $1; }
    |   bool { $$ = $1; }
    |   expr PLUS expr { $$ = op_node(ADD_OP, $1, $3); }
    |   expr SUB expr { $$ = op_node(SUB_OP, $1, $3); }
    |   expr MUL expr { $$ = op_node(MUL_OP, $1, $3); }
    |   expr DIV expr { $$ = op_node(DIV_OP, $1, $3); }
    |   expr GTEQ expr { $$ = op_node(GTEQ_OP, $1, $3); }
    |   IF expr THEN expr ELSE expr { $$ = if_node($2, $4, $6); }
    |   location ASSIGN expr { $$ = assign_node($<loc_val>1, $3); }
    |   DEREF location { $$ = deref_node($<loc_val>2); }
    |   SKIP { $$ = skip_node(); }
    |   expr SEQ expr { $$ = seq_node($1, $3); }
    |   WHILE expr DO expr END { $$ = while_node($2, $4); }
    |   PRINT location { $$ = print_node($2); };
%%

int yyerror(char *e) {
    printf("ERROR: %s\n", e);
    return 1;
}
