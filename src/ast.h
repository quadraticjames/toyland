typedef enum {
    BOOL_T,
    INT_T,
    LOC_T,
    OP_T,
    DEREF_T,
    ASSIGN_T,
    SKIP_T,
    SEQ_T,
    IF_T,
    WHILE_T
} node_type;

typedef enum {
    ADD_OP,
    GTEQ_OP
} op_type;

typedef struct {
    node_type type;
    void *data;
} node;

typedef struct {
    unsigned char value;
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
