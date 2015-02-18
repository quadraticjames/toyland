#include "parse.tab.h"
#include "ast.h"

YYSTYPE yyparse();

int main(void) {
    yyparse();
    return 0;
}
