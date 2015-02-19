#include <stdlib.h>

#include "ast.h"

node *bool_node(unsigned b) {
    NODE_INIT;
    NODE_TYPE(BOOL_T);
    NODE_DATA(bool_val);
    NODE_SET(bool_val, value, b);
    NODE_END;
}

node *int_node(long i) {
    NODE_INIT;
    NODE_TYPE(INT_T);
    NODE_DATA(int_val);
    NODE_SET(int_val, value, i);
    NODE_END;
}

node *loc_node(unsigned long r) {
    NODE_INIT;
    NODE_TYPE(LOC_T);
    NODE_DATA(loc_val);
    NODE_SET(loc_val, reg, r);
    NODE_END;
}

node *op_node(op_type o, node *l, node *r) {
    NODE_INIT;
    NODE_TYPE(OP_T);
    NODE_DATA(op_val);
    NODE_SET(op_val, op, o);
    NODE_SET(op_val, left, l);
    NODE_SET(op_val, right, r);
    NODE_END;
}

node *deref_node(unsigned long r) {
    NODE_INIT;
    NODE_TYPE(DEREF_T);
    NODE_DATA(deref_val);
    NODE_SET(deref_val, reg, r);
    NODE_END;
}

node *assign_node(unsigned long r, node *v) {
    NODE_INIT;
    NODE_TYPE(ASSIGN_T);
    NODE_DATA(assign_val);
    NODE_SET(assign_val, reg, r);
    NODE_SET(assign_val, value, v);
    NODE_END;
}

node *seq_node(node *f, node *s) {
    NODE_INIT;
    NODE_TYPE(SEQ_T);
    NODE_DATA(seq_val);
    NODE_SET(seq_val, first, f);
    NODE_SET(seq_val, second, s);
    NODE_END;
}

node *skip_node() {
    NODE_INIT;
    NODE_TYPE(SKIP_T);
    NODE_END;
}

node *if_node(node *c, node *s, node *f) {
    NODE_INIT;
    NODE_TYPE(IF_T);
    NODE_DATA(if_val);
    NODE_SET(if_val, cond, c);
    NODE_SET(if_val, succ, s);
    NODE_SET(if_val, fail, f);
    NODE_END;
}

node *while_node(node *c, node *b) {
    NODE_INIT;
    NODE_TYPE(WHILE_T);
    NODE_DATA(while_val);
    NODE_SET(while_val, cond, c);
    NODE_SET(while_val, body, b);
    NODE_END;
}
