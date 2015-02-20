// Type enums
#define BOOL_T 0
#define INT_T 1
#define LOC_T 2
#define OP_T 3
#define DEREF_T 4
#define ASSIGN_T 5
#define SKIP_T 6
#define SEQ_T 7
#define IF_T 8
#define WHILE_T 9
#define PRINT_T 10

typedef enum {
    ADD_OP,
    GTEQ_OP
} op_type;

// Node structures
typedef struct {
    int type;
    void *data;
} node;

typedef struct {
    unsigned value;
} bool_val;

typedef struct {
    long value;
} int_val;

typedef struct {
    unsigned long reg;
} loc_val;

typedef struct {
    op_type op;
    node *left;
    node *right;
} op_val;

typedef struct {
    unsigned long reg;
} deref_val;

typedef struct {
    unsigned long reg;
    node *value;
} assign_val;

typedef struct {
    node *first;
    node *second;
} seq_val;

typedef struct {
    node *cond;
    node *succ;
    node *fail;
} if_val;

typedef struct {
    node *cond;
    node *body;
} while_val;

typedef struct {
    unsigned long reg;
} print_val;

// Constructors
#define NODE_INIT node *ret = malloc(sizeof(node))
#define NODE_TYPE(x) ret->type = x
#define NODE_DATA(x) ret->data = (x *)malloc(sizeof(x))
#define NODE_SET(t,k,v) ((t *)(ret->data))->k = v
#define NODE_END return ret

node *bool_node(unsigned b);
node *int_node(long i);
node *loc_node(unsigned long r);
node *op_node(op_type o, node *l, node *r);
node *deref_node(unsigned long r);
node *assign_node(unsigned long r, node *v);
node *seq_node(node *f, node *s);
node *skip_node();
node *if_node(node *c, node *s, node *f);
node *while_node(node *c, node *b);
node *print_node(unsigned long r);
