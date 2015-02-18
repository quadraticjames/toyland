# Toyland

## L1
This project is an implementation of the L1 language from the part IB course
Semantics of Programming Language. The language itself is minimal, describing
only a small set of operational semantics and concrete syntax. 

## Grammar
The grammar of the language is described below. In this definition, `b`
describes the set of boolean values, `n` describes the set of integer values,
`l` the set of store locations, `op` the available operations on values, and `e`
the range of expression values in the language.

```
b   ::= true
    |   false

n   ::= {..., -1, 0, 1, ...}

l   ::= {l, l1, l2, ...}

op  ::= +
    |   >=

e   ::= n
    |   b
    |   e1 op e2
    |   if e1 then e2 else e3
    |   l := e
    |   !l
    |   skip
    |   e1 ; e2
    |   while e1 do e2
```

## Implementation Details

### Front End
The first stage of the compiler is to implement a front end. This part of the
implementation is made up of a lexer and a parser, which we will implement using
the well know tools *lex* and *yacc*. These tools take language specifications
and generate C code that transforms a source file into an *abstract syntax
tree*. In this stage of the project we will also define the data structures used
to make up the tree.
