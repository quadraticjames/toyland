#include <stdio.h>
#include <stdlib.h>

#include "interpret.h"

long store[4096];

node *step(node *n) {
    switch(n->type) {
        case BOOL_T:
            printf("Stuck on a bool value.\n");
            exit(1);
            break;
        case INT_T:
            printf("Stuck on an int value.\n");
            exit(1);
            break;
        case LOC_T:
            printf("Stuck on a location value.\n");
            exit(1);
            break;
        case OP_T:
            return step_op((op_val *)n->data);
            break;
        case DEREF_T:
            return step_deref((deref_val *)n->data);
            break;
        case ASSIGN_T:
            return step_assign((assign_val *)n->data);
            break;
        case SKIP_T:
            printf("Exiting.\n");
            exit(0);
            break;
        case SEQ_T:
            return step_seq((seq_val *)n->data);
            break;
        case IF_T:
            return step_if((if_val *)n->data);
            break;
        case WHILE_T:
            return step_while((while_val *)n->data);
            break;
    }
    return NULL;
}

node *step_op(op_val *data) {
    return NULL;
}

node *step_deref(deref_val *data) {
    return int_node(store[data->reg]);
}

node *step_assign(assign_val *data) {
    if(data->value->type == INT_T) {
        store[data->reg] = ((int_val *)(data->value->data))->value;
        return skip_node();
    } else {
        return assign_node(data->reg, step(data->value)); 
    }
}

node *step_seq(seq_val *data) {
    return NULL;
}

node *step_if(if_val *data) {
    return NULL;
}

node *step_while(while_val *data) {
    return NULL;
}
