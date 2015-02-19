#include "parse.tab.h"
#include "ast.h"

YYSTYPE yyparse();

int main(void) {
    node *x = int_node(0);
    yyparse();
    return 0;
}
