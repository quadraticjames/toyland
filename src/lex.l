%{
#include "parse.tab.h"
%}

%option noyywrap

%%

true    { return TRUE; }
