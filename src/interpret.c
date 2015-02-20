#include <stdio.h>
#include <stdlib.h>

#include "interpret.h"

long store[1048576];

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
            return NULL;
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
        case PRINT_T:
            return step_print((print_val *)n->data);
            break;
    }
    return NULL;
}

node *step_op(op_val *data) {
    if(data->left->type == INT_T) {
        if(data->right->type == INT_T) {
            long l = ((int_val *)(data->left->data))->value;
            long r = ((int_val *)(data->right->data))->value;
            switch(data->op) {
                case ADD_OP:
                    return int_node(l + r);
                    break;
                case GTEQ_OP:
                    return bool_node(l >= r);
                    break;
            }
        } else {
            return op_node(data->op, data->left, step(data->right));
        }
    } else {
        return op_node(data->op, step(data->left), data->right);
    }
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
    if(data->first->type == SKIP_T) {
        return data->second;
    } else {
        return seq_node(step(data->first), data->second);
    }
}

node *step_if(if_val *data) {
    if(data->cond->type == BOOL_T) {
        if(((bool_val *)(data->cond->data))->value) {
            return data->succ;
        } else {
            return data->fail;
        }
    } else {
        return if_node(step(data->cond), data->succ, data->fail);
    }
}

node *step_while(while_val *data) {
    return if_node(data->cond, 
                   seq_node(data->body, while_node(data->cond, data->body)), 
                   skip_node());
}

node *step_print(print_val *data) {
    printf("l%lu = %ld\n", data->reg, store[data->reg]);
    return skip_node();
}
