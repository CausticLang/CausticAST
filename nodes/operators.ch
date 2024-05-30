#if _cst_NODES_IS_HEADER
    typedef Cst__Operators__UnaryOpType cst_UnaryOpType;
    typedef Cst__Operators__BinaryOpType cst_BinaryOpType;
    typedef Cst__Operators__TernaryOpType cst_TernaryOpType;
#endif

_cst_CREATE_NODE_FUNCS(
    UnaryOp,
    {},
    { fprintf(s, " - op[UnaryOpType]: %d\n"
                 " - target[noderef]: %u\n", n->op, n->target); },
    { n->op = op; n->target = target; }, OPERATORS__UNARY_OP, cst_UnaryOpType op, cst_index target);

_cst_CREATE_NODE_FUNCS(
    BinaryOp,
    {},
    { fprintf(s, " - op[BinaryOpType]: %d\n"
                 " - left[noderef]:    %u\n"
                 " - right[noderef]:   %u\n", n->op, n->left, n->right); },
    { n->op = op; n->left = left; n->right = right; }, OPERATORS__BINARY_OP, cst_BinaryOpType op, cst_index left, cst_index right);

_cst_CREATE_NODE_FUNCS(
    TernaryOp,
    {},
    { fprintf(s, " - op[TernaryOpType]: %d\n"
                 " - a[noderef]:        %u\n"
                 " - b[noderef]:        %u\n"
                 " - c[noderef]:        %u\n", n->op, n->a, n->b, n->c); },
    { n->op = op; n->a = a; n->b = b; n->c = c; }, OPERATORS__TERNARY_OP, cst_TernaryOpType op, cst_index a, cst_index b, cst_index c);
