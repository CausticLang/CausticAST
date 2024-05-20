enum cst_OperatorType:char {
    // Unary
    POS = 1, NEG = 2, LOGINV = 3, BITINV = 4, INC = 5, DEC = 6,
    // Binary
    ADD = 7, SUB = 8, MULT = 9, MMUL = 10, DIV = 11, MOD = 12, POW = 13,
    EQ = 14, NE = 15, IS = 16, ISNT = 17, LT = 18, LE = 19, GT = 20, GE = 21,
    NULLCOALESCING = 22,
    LOGAND = 23, LOGOR = 24, LOGXOR = 25,
    BITAND = 26, BITOR = 27, BITXOR = 28, LSHIFT = 29, RSHIFT = 30,
    // Ternary
    CONDITIONAL = 31,
};


cst_MKNODETYPE(UnaryOp, enum cst_OperatorType op; cst_index target;, {
    n->op = op;
    n->target = target;
}, enum cst_OperatorType op, cst_index target);
cst_MKNODETYPE(BinaryOp, enum cst_OperatorType op; cst_index left; cst_index right;, {
    n->op = op;
    n->left = left;
    n->right = right;
}, enum cst_OperatorType op, cst_index left, cst_index right);
cst_MKNODETYPE(TernaryOp, enum cst_OperatorType op; cst_index a; cst_index b; cst_index c;, {
    n->op = op;
    n->a = a;
    n->b = b;
    n->c = c;
}, enum cst_OperatorType op, cst_index a, cst_index b, cst_index c);
