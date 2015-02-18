# Toyland

## Implementation Details

### Front End
The first stage of the compiler is to implement a front end. This part of the
implementation is made up of a lexer and a parser, which we will implement using
the well know tools *lex* and *yacc*. These tools take language specifications
and generate C code that transforms a source file into an *abstract syntax
tree*. In this stage of the project we will also define the data structures used
to make up the tree.
