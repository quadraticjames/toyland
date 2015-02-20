#include "ast.h"

node *step(node *n);

node *step_op(op_val *data);
node *step_deref(deref_val *data);
node *step_assign(assign_val *data);
node *step_seq(seq_val *data);
node *step_if(if_val *data);
node *step_while(while_val *data);
