#include <stdbool.h>

#if _cst_NODES_IS_HEADER
    typedef Cst__Statements__FlowCtlType cst_FlowCtlType;
#endif

// Conditionals
_cst_CREATE_NODE_FUNCS(
    If,
    {},
    { fprintf(s, " - condition[noderef]: %u\n"
                 " - body[noderef]:      %u\n"
                 " - next[noderef]:      %u\n", n->condition, n->body, n->next); },
    { n->condition = condition; n->body = body; n->next = next; },
    STATEMENTS__IF, cst_index condition, cst_index body, cst_index next
);

_cst_CREATE_NODE_FUNCS(
    ElIf,
    {},
    { fprintf(s, " - condition[noderef]: %u\n"
                 " - body[noderef]:      %u\n"
                 " - next[noderef]:      %u\n", n->condition, n->body, n->next); },
    { n->condition = condition; n->body = body; n->next = next; },
    STATEMENTS__EL_IF, cst_index condition, cst_index body, cst_index next
);

_cst_CREATE_NODE_FUNCS(
    Else,
    {},
    { fprintf(s, " - body[noderef]: %u\n", n->body); },
    { n->body = body; }, STATEMENTS__ELSE, cst_index body
);

// Loops
_cst_CREATE_NODE_FUNCS(
    For,
    {},
    { fprintf(s, " - init[noderef]:      %u\n"
                 " - condition[noderef]: %u\n"
                 " - body[noderef]:      %u\n", n->init, n->condition, n->body); },
    { n->init = init; n->condition = condition; n->iterate = iterate; n->body = body; },
    STATEMENTS__FOR, cst_index init, cst_index condition, cst_index iterate, cst_index body
);

_cst_CREATE_NODE_FUNCS(
    While,
    {},
    { fprintf(s, " - condition[noderef]: %u\n"
                 " - body[noderef]:      %u\n"
                 " - do_while[bool]:     %d\n", n->condition, n->body, n->do_while); },
    { n->condition = condition; n->body = body; n->do_while = do_while; },
    STATEMENTS__WHILE, cst_index condition, cst_index body, bool do_while
);

// Declarations
_cst_CREATE_NODE_FUNCS(
    Declaration,
    {},
    { fprintf(s, " - type[noderef]: %u\n"
                 " - name[noderef]: %u\n"
                 " - val[noderef]:  %u\n", n->type, n->name, n->val); },
    { n->type = type; n->name = name; n->val = val; },
    STATEMENTS__DECLARATION, cst_index type, cst_index name, cst_index val
);

_cst_CREATE_NODE_FUNCS(
    Assignment,
    {},
    { fprintf(s, " - target[noderef]: %u\n"
                 " - val[noderef]:    %u\n", n->target, n->val); },
    { n->target = target; n->val = val; }, STATEMENTS__ASSIGNMENT, cst_index target, cst_index val
);

// Misc. statements
_cst_CREATE_NODE_FUNCS(
    Return,
    {},
    { fprintf(s, " - val[noderef]: %u\n", n->val); },
    { n->val = val; }, STATEMENTS__RETURN, cst_index val
);
_cst_CREATE_NODE_FUNCS_NIP(
    Pass,
    {},
    {},
    {},
    STATEMENTS__PASS
);
_cst_CREATE_NODE_FUNCS(
    FlowCtl,
    {},
    { fprintf(s, " - type: %u\n", n->type); },
    { n->type = type; }, STATEMENTS__FLOW_CTL, cst_FlowCtlType type
);
