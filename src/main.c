#include <stdio.h>
#include <stdlib.h>

#include "ast.h"
#include "parse.tab.h"

YYSTYPE yyparse();

extern int yydebug;
extern node *root;

int main(void) {
    root = malloc(sizeof(node));
    yyparse();
    return 0;
}
