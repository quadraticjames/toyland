#include "check.h"

int check(node *root) {
    switch(root->type) {
        case INT_T:
        case BOOL_T:
        case LOC_T:
            return root->type;
            break;
        case DEREF_T:
            return INT_T;
            break;
    }
    return 0;
}

int op_check(op_val *data) {
    return 0;
}
