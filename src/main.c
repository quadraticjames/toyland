#include "parse.tab.h"

YYSTYPE yyparse();

int main(void) {
    yyparse();
    return 0;
}
