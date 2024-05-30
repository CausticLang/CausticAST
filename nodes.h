#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include "protobuf/nodes.pb-c.h"

#define cst_NODECAST(base, to) ((cst_n##to*)((base)->val))

#define cst_NODEDOWNCAST(node) ( node \
    - sizeof(ProtobufCMessage) /* base */ \
    - (sizeof(uint32_t) * 4) /* pos_start + pos_end + lineno + colno */ \
    - sizeof(Cst__Node__NodeCase) /* node_case */ \
    )
#undef cst_NODEDOWNCAST // BAD IDEA

#define cst_NTYPEIS(node, type) ((node)->node_case == CST__NODE__NODE_##type)

typedef uint32_t cst_index;

#define _cst_NODES_IS_HEADER 1

#define _cst_CREATE_NODE_FUNCS(name, free_body, print_body, init_body, init_name, ...) \
    cst_n##name* cst_ninit_##name(cst_n##name* n, __VA_ARGS__); \
    void cst_nprint_##name(FILE* s, cst_n##name* n); \
    void cst_nfree_##name(cst_n##name* n);
#define _cst_CREATE_NODE_FUNCS_NIP(name, free_body, print_body, init_body, init_name) /* NIP = No Init Params */ \
    cst_n##name* cst_ninit_##name(cst_n##name* n); \
    void cst_nprint_##name(FILE* s, cst_n##name* n); \
    void cst_nfree_##name(cst_n##name* n);

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


#define cst_NODEFREE(n) _Generic(n, \
    cst_nAttribute: cst_nfree_Attribute(n), \
    cst_nSubscript: cst_nfree_Subscript(n), \
    cst_nIdentifier: cst_nfree_Identifier(n), \
    cst_nBool: cst_nfree_Bool(n), \
    cst_nInteger: cst_nfree_Integer(n), \
    cst_nFloat: cst_nfree_Float(n), \
    cst_nBytes: cst_nfree_Bytes(n), \
    cst_nString: cst_nfree_String(n), \
    cst_nEntrypoint: cst_nfree_Entrypoint(n), \
    cst_nBlock: cst_nfree_Block(n), \
    cst_nExtraData: cst_nfree_ExtraData(n), \
    cst_nUnaryOp: cst_nfree_UnaryOp(n), \
    cst_nBinaryOp: cst_nfree_BinaryOp(n), \
    cst_nTernaryOp: cst_nfree_TernaryOp(n), \
    cst_nInvokation: cst_nfree_Invokation(n), \
    cst_nProcParam: cst_nfree_ProcParam(n), \
    cst_nProcExpr: cst_nfree_ProcExpr(n), \
    cst_nProcStmt: cst_nfree_ProcStmt(n), \
    cst_nIf: cst_nfree_If(n), \
    cst_nElIf: cst_nfree_ElIf(n), \
    cst_nElse: cst_nfree_Else(n), \
    cst_nFor: cst_nfree_For(n), \
    cst_nWhile: cst_nfree_While(n), \
    cst_nDeclaration: cst_nfree_Declaration(n), \
    cst_nAssignment: cst_nfree_Assignment(n), \
    cst_nReturn: cst_nfree_Return(n), \
    cst_nPass: cst_nfree_Pass(n), \
    cst_nFlowCtl: cst_nfree_FlowCtl(n), \
    cst_nType: cst_nfree_Type(n), \
    cst_nEnum: cst_nfree_Enum(n), \
    cst_nStruct: cst_nfree_Struct(n), \
    cst_nStructEnum: cst_nfree_StructEnum(n), \
    cst_nClass: cst_nfree_Class(n)
