#include "nodes.h"

#define _cst_NODES_IS_HEADER 0
#define _cst_CREATE_NODE_FUNCS_(name, free_body, print_body) \
    cst_Node* cst_binit_##name(cst_Node* base, cst_n##name* n) { \
        *base = (cst_Node)cst_EMPTYNODE; \
        base->val = (Cst__DummyEmpty*)n; \
        base->node_case = cst_NTYPE_##name; \
    } \
    void cst_nfree_##name(cst_n##name* n) free_body; \
    void cst_nprint_##name(FILE* s, cst_n##name* n) { \
        fputs("Node type: " #name "\n", s); \
        print_body \
    }
#define _cst_CREATE_NODE_FUNCS(name, free_body, print_body, init_body, init_name, ...) \
    cst_n##name* cst_ninit_##name(cst_n##name* n, __VA_ARGS__) { \
        *n = (cst_n##name)CST__##init_name##__INIT; \
        init_body \
        return n; \
    } \
    _cst_CREATE_NODE_FUNCS_(name, free_body, print_body)
#define _cst_CREATE_NODE_FUNCS_NIP(name, free_body, print_body, init_body, init_name) \
    cst_n##name* cst_ninit_##name(cst_n##name* n) { \
        *n = (cst_n##name)CST__##init_name##__INIT; \
        init_body \
        return n; \
    } \
    _cst_CREATE_NODE_FUNCS_(name, free_body, print_body)

#include "protobuf/nodes.pb-c.c"

#include "protobuf/accesses.pb-c.c"
#include "nodes/accesses.ch"

#include "protobuf/atoms.pb-c.c"
#include "nodes/atoms.ch"

#include "protobuf/control.pb-c.c"
#include "nodes/control.ch"

#include "protobuf/operators.pb-c.c"
#include "nodes/operators.ch"

#include "protobuf/procedures.pb-c.c"
#include "nodes/procedures.ch"

#include "protobuf/statements.pb-c.c"
#include "nodes/statements.ch"

#include "protobuf/types.pb-c.c"
#include "nodes/types.ch"

#undef _cst_NODES_IS_HEADER
#undef _cst_CREATE_NODE_FUNCS_
#undef _cst_CREATE_NODE_FUNCS
#undef _cst_CREATE_NODE_FUNCS_ONEPARAM
#undef _cst_CREATE_NODE_FUNCS_NOPARAMS
