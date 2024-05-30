_cst_CREATE_NODE_FUNCS(
    Attribute,
    {},
    { fprintf(s, " - top[noderef]: %d\n"
                 " - sub[noderef]: %d\n", n->top, n->sub); },
    { n->top = top; n->sub = sub; }, ACCESSES__ATTRIBUTE, cst_index top, cst_index sub
);

_cst_CREATE_NODE_FUNCS(
    Subscript,
    {},
    { fprintf(s, " - top[noderef]: %d\n"
                 " - sub[noderef]: %d\n", n->top, n->sub); },
    { n->top = top; n->sub = sub; }, ACCESSES__SUBSCRIPT, cst_index top, cst_index sub
);
