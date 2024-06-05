#ifndef cst_NODES_H
#define cst_NODES_H 1

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include "protobuf/nodes.pb-c.h"

/* define types and include type-related utils */

typedef uint32_t cst_index;

#define cst_INITROOT CST__ROOT__INIT
#define cst_EMPTYNODE CST__NODE__INIT

#include "node_types.h"

/* generate node functions (header) */

#define _cst_NODES_IS_HEADER 1

#define _cst_CREATE_NODE_FUNCS(name, free_body, print_body, init_body, init_name, ...) \
    cst_n##name* cst_ninit_##name(cst_n##name* n, __VA_ARGS__); \
    cst_Node* cst_binit_##name(cst_Node* base, cst_n##name* n, uint32_t pstart, uint32_t pend, uint32_t lno, uint32_t cno); \
    void cst_nprint_##name(FILE* s, cst_n##name* n); \
    void cst_nfree_##name(cst_n##name* n)
#define _cst_CREATE_NODE_FUNCS_NIP(name, free_body, print_body, init_body, init_name) /* NIP = No Init Params */ \
    cst_n##name* cst_ninit_##name(cst_n##name* n); \
    cst_Node* cst_binit_##name(cst_Node* base, cst_n##name* n, uint32_t pstart, uint32_t pend, uint32_t lno, uint32_t cno); \
    void cst_nprint_##name(FILE* s, cst_n##name* n); \
    void cst_nfree_##name(cst_n##name* n)

// nodes.pb-c.h
typedef Cst__Root cst_Root;
typedef Cst__Node__NodeCase cst_NodeType;
typedef Cst__Node cst_Node;
// accesses.pb-c.h
typedef Cst__Accesses__Attribute cst_nAttribute;
typedef Cst__Accesses__Subscript cst_nSubscript;
#include "nodes/accesses.ch"
// atoms.pb-c.h
typedef Cst__Atoms__Identifier cst_nIdentifier;
typedef Cst__Atoms__Bool cst_nBool;
typedef Cst__Atoms__Integer cst_nInteger;
typedef Cst__Atoms__Float cst_nFloat;
typedef Cst__Atoms__Char cst_nChar;
typedef Cst__Atoms__Bytes cst_nBytes;
typedef Cst__Atoms__String cst_nString;
#include "nodes/atoms.ch"
// control.pb-c.h
typedef Cst__Control__Entrypoint cst_nEntrypoint;
typedef Cst__Control__Block cst_nBlock;
typedef Cst__Control__ExtraData cst_nExtraData;
#include "nodes/control.ch"
// operators.pb-c.h
typedef Cst__Operators__UnaryOp cst_nUnaryOp;
typedef Cst__Operators__BinaryOp cst_nBinaryOp;
typedef Cst__Operators__TernaryOp cst_nTernaryOp;
#include "nodes/operators.ch"
// procedures.pb-c.h
typedef Cst__Procedures__Invokation cst_nInvokation;
typedef Cst__Procedures__ProcParam cst_nProcParam;
typedef Cst__Procedures__ProcExpr cst_nProcExpr;
typedef Cst__Procedures__ProcStmt cst_nProcStmt;
#include "nodes/procedures.ch"
// statements.pb-c.h
typedef Cst__Statements__If cst_nIf;
typedef Cst__Statements__ElIf cst_nElIf;
typedef Cst__Statements__Else cst_nElse;
typedef Cst__Statements__For cst_nFor;
typedef Cst__Statements__While cst_nWhile;
typedef Cst__Statements__Declaration cst_nDeclaration;
typedef Cst__Statements__Assignment cst_nAssignment;
typedef Cst__Statements__Return cst_nReturn;
typedef Cst__Statements__Pass cst_nPass;
typedef Cst__Statements__FlowCtl cst_nFlowCtl;
#include "nodes/statements.ch"
// types.pb-c.h
typedef Cst__Types__Type cst_nType;
typedef Cst__Types__Enum cst_nEnum;
typedef Cst__Types__Struct cst_nStruct;
typedef Cst__Types__StructEnum cst_nStructEnum;
typedef Cst__Types__Class cst_nClass;
#include "nodes/types.ch"

#undef _cst_NODES_IS_HEADER
#undef _cst_CREATE_NODE_FUNCS
#undef _cst_CREATE_NODE_FUNCS_NIP

/* functions and useful function macros */

void cst_print_node(FILE* s, cst_Node* n);
void cst_free_node(cst_Node* n);

#define cst_ADDNODE(r, n) do { \
    (r)->nodes = (cst_Node*)realloc((r)->nodes, sizeof(cst_Node) * ++(r)->n_nodes); \
    (r)->nodes[(r)->n_nodes-1] = n; \
} while(0)

#include "node_generics.h"

#endif // cst_NODES_H
