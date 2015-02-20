#include <stdio.h>
#include <stdlib.h>

#include "interpret.h"
#include "check.h"
#include "parse.tab.h"

YYSTYPE yyparse();

extern int yydebug;
extern node *root;

int main(void) {
    root = malloc(sizeof(node));
    yyparse();
    while(root != NULL) {
        root = step(root);
    }
    return 0;
}
