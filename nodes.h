#include <malloc.h>
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

#define cst_NTYPEIS(node, type) ((node)->node_case == cst_NTYPE_##type)

typedef uint32_t cst_index;

#define _cst_NODES_IS_HEADER 1

#define _cst_CREATE_NODE_FUNCS(name, free_body, print_body, init_body, init_name, ...) \
    cst_n##name* cst_ninit_##name(cst_n##name* n, __VA_ARGS__); \
    cst_Node* cst_binit_##name(cst_Node* base, cst_n##name* n); \
    void cst_nprint_##name(FILE* s, cst_n##name* n); \
    void cst_nfree_##name(cst_n##name* n);
#define _cst_CREATE_NODE_FUNCS_NIP(name, free_body, print_body, init_body, init_name) /* NIP = No Init Params */ \
    cst_n##name* cst_ninit_##name(cst_n##name* n); \
    cst_Node* cst_binit_##name(cst_Node* base, cst_n##name* n); \
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

#define cst_NTYPE_Entrypoint CST__NODE__NODE_ENTRYPOINT
#define cst_NTYPE_ExtraData CST__NODE__NODE_EXTRADATA
#define cst_NTYPE_Block CST__NODE__NODE_BLOCK
#define cst_NTYPE_Type CST__NODE__NODE_TYPE
#define cst_NTYPE_Enum CST__NODE__NODE_ENUM
#define cst_NTYPE_Struct CST__NODE__NODE_STRUCT
#define cst_NTYPE_StructEnum CST__NODE__NODE_STRUCTENUM
#define cst_NTYPE_Class CST__NODE__NODE_CLASS
#define cst_NTYPE_Identifier CST__NODE__NODE_IDENTIFIER
#define cst_NTYPE_Bool CST__NODE__NODE_BOOL
#define cst_NTYPE_Integer CST__NODE__NODE_INTEGER
#define cst_NTYPE_Float CST__NODE__NODE_FLOAT
#define cst_NTYPE_Char CST__NODE__NODE_CHAR
#define cst_NTYPE_Bytes CST__NODE__NODE_BYTES
#define cst_NTYPE_String CST__NODE__NODE_STRING
#define cst_NTYPE_UnaryOp CST__NODE__NODE_UNARYOP
#define cst_NTYPE_BinaryOp CST__NODE__NODE_BINARYOP
#define cst_NTYPE_TernaryOp CST__NODE__NODE_TERNARYOP
#define cst_NTYPE_Attribute CST__NODE__NODE_ATTRIBUTE
#define cst_NTYPE_Subscript CST__NODE__NODE_SUBSCRIPT
#define cst_NTYPE_Invokation CST__NODE__NODE_INVOKATION
#define cst_NTYPE_ProcExpr CST__NODE__NODE_PROCEXPR
#define cst_NTYPE_ProcStmt CST__NODE__NODE_PROCSTMT
#define cst_NTYPE_If CST__NODE__NODE_IF
#define cst_NTYPE_ElIf CST__NODE__NODE_ELIF
#define cst_NTYPE_Else CST__NODE__NODE_ELSE
#define cst_NTYPE_For CST__NODE__NODE_FOR
#define cst_NTYPE_While CST__NODE__NODE_WHILE
#define cst_NTYPE_Declaration CST__NODE__NODE_DECLARATION
#define cst_NTYPE_Assignment CST__NODE__NODE_ASSIGNMENT
#define cst_NTYPE_Return CST__NODE__NODE_RETURN
#define cst_NTYPE_Pass CST__NODE__NODE_PASS
#define cst_NTYPE_FlowCtl CST__NODE__NODE_FLOWCTL

#define cst_INITROOT CST__ROOT__INIT
#define cst_EMPTYNODE CST__NODE__INIT

#define cst_NODEFREE(n) _Generic(n, \
    cst_nAttribute*: cst_nfree_Attribute(n), \
    cst_nSubscript*: cst_nfree_Subscript(n), \
    cst_nIdentifier*: cst_nfree_Identifier(n), \
    cst_nBool*: cst_nfree_Bool(n), \
    cst_nInteger*: cst_nfree_Integer(n), \
    cst_nFloat*: cst_nfree_Float(n), \
    cst_nBytes*: cst_nfree_Bytes(n), \
    cst_nString*: cst_nfree_String(n), \
    cst_nEntrypoint*: cst_nfree_Entrypoint(n), \
    cst_nBlock*: cst_nfree_Block(n), \
    cst_nExtraData*: cst_nfree_ExtraData(n), \
    cst_nUnaryOp*: cst_nfree_UnaryOp(n), \
    cst_nBinaryOp*: cst_nfree_BinaryOp(n), \
    cst_nTernaryOp*: cst_nfree_TernaryOp(n), \
    cst_nInvokation*: cst_nfree_Invokation(n), \
    cst_nProcParam*: cst_nfree_ProcParam(n), \
    cst_nProcExpr*: cst_nfree_ProcExpr(n), \
    cst_nProcStmt*: cst_nfree_ProcStmt(n), \
    cst_nIf*: cst_nfree_If(n), \
    cst_nElIf*: cst_nfree_ElIf(n), \
    cst_nElse*: cst_nfree_Else(n), \
    cst_nFor*: cst_nfree_For(n), \
    cst_nWhile*: cst_nfree_While(n), \
    cst_nDeclaration*: cst_nfree_Declaration(n), \
    cst_nAssignment*: cst_nfree_Assignment(n), \
    cst_nReturn*: cst_nfree_Return(n), \
    cst_nPass*: cst_nfree_Pass(n), \
    cst_nFlowCtl*: cst_nfree_FlowCtl(n), \
    cst_nType*: cst_nfree_Type(n), \
    cst_nEnum*: cst_nfree_Enum(n), \
    cst_nStruct*: cst_nfree_Struct(n), \
    cst_nStructEnum*: cst_nfree_StructEnum(n), \
    cst_nClass*: cst_nfree_Class(n))

#define cst_NODEPRINT(s, n) _Generic(n, \
    cst_nAttribute*: cst_nprint_Attribute, \
    cst_nSubscript*: cst_nprint_Subscript, \
    cst_nIdentifier*: cst_nprint_Identifier, \
    cst_nBool*: cst_nprint_Bool, \
    cst_nInteger*: cst_nprint_Integer, \
    cst_nFloat*: cst_nprint_Float, \
    cst_nBytes*: cst_nprint_Bytes, \
    cst_nString*: cst_nprint_String, \
    cst_nEntrypoint*: cst_nprint_Entrypoint, \
    cst_nBlock*: cst_nprint_Block, \
    cst_nExtraData*: cst_nprint_ExtraData, \
    cst_nUnaryOp*: cst_nprint_UnaryOp, \
    cst_nBinaryOp*: cst_nprint_BinaryOp, \
    cst_nTernaryOp*: cst_nprint_TernaryOp, \
    cst_nInvokation*: cst_nprint_Invokation, \
    cst_nProcExpr*: cst_nprint_ProcExpr, \
    cst_nProcStmt*: cst_nprint_ProcStmt, \
    cst_nIf*: cst_nprint_If, \
    cst_nElIf*: cst_nprint_ElIf, \
    cst_nElse*: cst_nprint_Else, \
    cst_nFor*: cst_nprint_For, \
    cst_nWhile*: cst_nprint_While, \
    cst_nDeclaration*: cst_nprint_Declaration, \
    cst_nAssignment*: cst_nprint_Assignment, \
    cst_nReturn*: cst_nprint_Return, \
    cst_nPass*: cst_nprint_Pass, \
    cst_nFlowCtl*: cst_nprint_FlowCtl, \
    cst_nType*: cst_nprint_Type, \
    cst_nEnum*: cst_nprint_Enum, \
    cst_nStruct*: cst_nprint_Struct, \
    cst_nStructEnum*: cst_nprint_StructEnum, \
    cst_nClass*: cst_nprint_Class)(s, n)

#define cst_ADDNODE(r, n) do { \
    realloc(r->nodes, sizeof(cst_Node) * ++r->n_nodes); \
    r->nodes[r->n_nodes-1] = n; \
} while(0)

#define cst_GENERIC_PFXARGS(n, f_prefix, on_default, ...) \
    switch ((n)->node_case) { \
        case cst_NTYPE_Entrypoint: f_prefix##Entrypoint(cst_NODECAST(n, Entrypoint), __VA_ARGS__)); break; \
        case cst_NTYPE_ExtraData: f_prefix##ExtraData(cst_NODECAST(n, ExtraData), __VA_ARGS__)); break; \
        case cst_NTYPE_Block: f_prefix##Block(cst_NODECAST(n, Block), __VA_ARGS__)); break; \
        case cst_NTYPE_Type: f_prefix##Type(cst_NODECAST(n, Type), __VA_ARGS__)); break; \
        case cst_NTYPE_Enum: f_prefix##Enum(cst_NODECAST(n, Enum), __VA_ARGS__)); break; \
        case cst_NTYPE_Struct: f_prefix##Struct(cst_NODECAST(n, Struct), __VA_ARGS__)); break; \
        case cst_NTYPE_StructEnum: f_prefix##StructEnum(cst_NODECAST(n, StructEnum), __VA_ARGS__)); break; \
        case cst_NTYPE_Class: f_prefix##Class(cst_NODECAST(n, Class), __VA_ARGS__)); break; \
        case cst_NTYPE_Identifier: f_prefix##Identifier(cst_NODECAST(n, Identifier), __VA_ARGS__)); break; \
        case cst_NTYPE_Bool: f_prefix##Bool(cst_NODECAST(n, Bool), __VA_ARGS__)); break; \
        case cst_NTYPE_Integer: f_prefix##Integer(cst_NODECAST(n, Integer), __VA_ARGS__)); break; \
        case cst_NTYPE_Float: f_prefix##Float(cst_NODECAST(n, Float), __VA_ARGS__)); break; \
        case cst_NTYPE_Char: f_prefix##Char(cst_NODECAST(n, Char), __VA_ARGS__)); break; \
        case cst_NTYPE_Bytes: f_prefix##Bytes(cst_NODECAST(n, Bytes), __VA_ARGS__)); break; \
        case cst_NTYPE_String: f_prefix##String(cst_NODECAST(n, String), __VA_ARGS__)); break; \
        case cst_NTYPE_UnaryOp: f_prefix##UnaryOp(cst_NODECAST(n, UnaryOp), __VA_ARGS__)); break; \
        case cst_NTYPE_BinaryOp: f_prefix##BinaryOp(cst_NODECAST(n, BinaryOp), __VA_ARGS__)); break; \
        case cst_NTYPE_TernaryOp: f_prefix##TernaryOp(cst_NODECAST(n, TernaryOp), __VA_ARGS__)); break; \
        case cst_NTYPE_Attribute: f_prefix##Attribute(cst_NODECAST(n, Attribute), __VA_ARGS__)); break; \
        case cst_NTYPE_Subscript: f_prefix##Subscript(cst_NODECAST(n, Subscript), __VA_ARGS__)); break; \
        case cst_NTYPE_Invokation: f_prefix##Invokation(cst_NODECAST(n, Invokation), __VA_ARGS__)); break; \
        case cst_NTYPE_ProcExpr: f_prefix##ProcExpr(cst_NODECAST(n, ProcExpr), __VA_ARGS__)); break; \
        case cst_NTYPE_ProcStmt: f_prefix##ProcStmt(cst_NODECAST(n, ProcStmt), __VA_ARGS__)); break; \
        case cst_NTYPE_If: f_prefix##If(cst_NODECAST(n, If), __VA_ARGS__)); break; \
        case cst_NTYPE_ElIf: f_prefix##ElIf(cst_NODECAST(n, ElIf), __VA_ARGS__)); break; \
        case cst_NTYPE_Else: f_prefix##Else(cst_NODECAST(n, Else), __VA_ARGS__)); break; \
        case cst_NTYPE_For: f_prefix##For(cst_NODECAST(n, For), __VA_ARGS__)); break; \
        case cst_NTYPE_While: f_prefix##While(cst_NODECAST(n, While), __VA_ARGS__)); break; \
        case cst_NTYPE_Declaration: f_prefix##Declaration(cst_NODECAST(n, Declaration), __VA_ARGS__)); break; \
        case cst_NTYPE_Assignment: f_prefix##Assignment(cst_NODECAST(n, Assignment), __VA_ARGS__)); break; \
        case cst_NTYPE_Return: f_prefix##Return(cst_NODECAST(n, Return), __VA_ARGS__)); break; \
        case cst_NTYPE_Pass: f_prefix##Pass(cst_NODECAST(n, Pass), __VA_ARGS__)); break; \
        case cst_NTYPE_FlowCtl: f_prefix##FlowCtl(cst_NODECAST(n, FlowCtl), __VA_ARGS__)); break; \
        default: on_default; \
    }
#define cst_GENERIC_SFXARGS(n, f_prefix, on_default, ...) \
    switch ((n)->node_case) { \
        case cst_NTYPE_Entrypoint: f_prefix##Entrypoint(__VA_ARGS__, cst_NODECAST(n, Entrypoint)); break; \
        case cst_NTYPE_ExtraData: f_prefix##ExtraData(__VA_ARGS__, cst_NODECAST(n, ExtraData)); break; \
        case cst_NTYPE_Block: f_prefix##Block(__VA_ARGS__, cst_NODECAST(n, Block)); break; \
        case cst_NTYPE_Type: f_prefix##Type(__VA_ARGS__, cst_NODECAST(n, Type)); break; \
        case cst_NTYPE_Enum: f_prefix##Enum(__VA_ARGS__, cst_NODECAST(n, Enum)); break; \
        case cst_NTYPE_Struct: f_prefix##Struct(__VA_ARGS__, cst_NODECAST(n, Struct)); break; \
        case cst_NTYPE_StructEnum: f_prefix##StructEnum(__VA_ARGS__, cst_NODECAST(n, StructEnum)); break; \
        case cst_NTYPE_Class: f_prefix##Class(__VA_ARGS__, cst_NODECAST(n, Class)); break; \
        case cst_NTYPE_Identifier: f_prefix##Identifier(__VA_ARGS__, cst_NODECAST(n, Identifier)); break; \
        case cst_NTYPE_Bool: f_prefix##Bool(__VA_ARGS__, cst_NODECAST(n, Bool)); break; \
        case cst_NTYPE_Integer: f_prefix##Integer(__VA_ARGS__, cst_NODECAST(n, Integer)); break; \
        case cst_NTYPE_Float: f_prefix##Float(__VA_ARGS__, cst_NODECAST(n, Float)); break; \
        case cst_NTYPE_Char: f_prefix##Char(__VA_ARGS__, cst_NODECAST(n, Char)); break; \
        case cst_NTYPE_Bytes: f_prefix##Bytes(__VA_ARGS__, cst_NODECAST(n, Bytes)); break; \
        case cst_NTYPE_String: f_prefix##String(__VA_ARGS__, cst_NODECAST(n, String)); break; \
        case cst_NTYPE_UnaryOp: f_prefix##UnaryOp(__VA_ARGS__, cst_NODECAST(n, UnaryOp)); break; \
        case cst_NTYPE_BinaryOp: f_prefix##BinaryOp(__VA_ARGS__, cst_NODECAST(n, BinaryOp)); break; \
        case cst_NTYPE_TernaryOp: f_prefix##TernaryOp(__VA_ARGS__, cst_NODECAST(n, TernaryOp)); break; \
        case cst_NTYPE_Attribute: f_prefix##Attribute(__VA_ARGS__, cst_NODECAST(n, Attribute)); break; \
        case cst_NTYPE_Subscript: f_prefix##Subscript(__VA_ARGS__, cst_NODECAST(n, Subscript)); break; \
        case cst_NTYPE_Invokation: f_prefix##Invokation(__VA_ARGS__, cst_NODECAST(n, Invokation)); break; \
        case cst_NTYPE_ProcExpr: f_prefix##ProcExpr(__VA_ARGS__, cst_NODECAST(n, ProcExpr)); break; \
        case cst_NTYPE_ProcStmt: f_prefix##ProcStmt(__VA_ARGS__, cst_NODECAST(n, ProcStmt)); break; \
        case cst_NTYPE_If: f_prefix##If(__VA_ARGS__, cst_NODECAST(n, If)); break; \
        case cst_NTYPE_ElIf: f_prefix##ElIf(__VA_ARGS__, cst_NODECAST(n, ElIf)); break; \
        case cst_NTYPE_Else: f_prefix##Else(__VA_ARGS__, cst_NODECAST(n, Else)); break; \
        case cst_NTYPE_For: f_prefix##For(__VA_ARGS__, cst_NODECAST(n, For)); break; \
        case cst_NTYPE_While: f_prefix##While(__VA_ARGS__, cst_NODECAST(n, While)); break; \
        case cst_NTYPE_Declaration: f_prefix##Declaration(__VA_ARGS__, cst_NODECAST(n, Declaration)); break; \
        case cst_NTYPE_Assignment: f_prefix##Assignment(__VA_ARGS__, cst_NODECAST(n, Assignment)); break; \
        case cst_NTYPE_Return: f_prefix##Return(__VA_ARGS__, cst_NODECAST(n, Return)); break; \
        case cst_NTYPE_Pass: f_prefix##Pass(__VA_ARGS__, cst_NODECAST(n, Pass)); break; \
        case cst_NTYPE_FlowCtl: f_prefix##FlowCtl(__VA_ARGS__, cst_NODECAST(n, FlowCtl)); break; \
        default: on_default; \
    }
#define cst_GENERIC_NOARGS(n, f_prefix, on_default) \
    switch ((n)->node_case) { \
        case cst_NTYPE_Entrypoint: f_prefix##Entrypoint(cst_NODECAST(n, Entrypoint)); break; \
        case cst_NTYPE_ExtraData: f_prefix##ExtraData(cst_NODECAST(n, ExtraData)); break; \
        case cst_NTYPE_Block: f_prefix##Block(cst_NODECAST(n, Block)); break; \
        case cst_NTYPE_Type: f_prefix##Type(cst_NODECAST(n, Type)); break; \
        case cst_NTYPE_Enum: f_prefix##Enum(cst_NODECAST(n, Enum)); break; \
        case cst_NTYPE_Struct: f_prefix##Struct(cst_NODECAST(n, Struct)); break; \
        case cst_NTYPE_StructEnum: f_prefix##StructEnum(cst_NODECAST(n, StructEnum)); break; \
        case cst_NTYPE_Class: f_prefix##Class(cst_NODECAST(n, Class)); break; \
        case cst_NTYPE_Identifier: f_prefix##Identifier(cst_NODECAST(n, Identifier)); break; \
        case cst_NTYPE_Bool: f_prefix##Bool(cst_NODECAST(n, Bool)); break; \
        case cst_NTYPE_Integer: f_prefix##Integer(cst_NODECAST(n, Integer)); break; \
        case cst_NTYPE_Float: f_prefix##Float(cst_NODECAST(n, Float)); break; \
        case cst_NTYPE_Char: f_prefix##Char(cst_NODECAST(n, Char)); break; \
        case cst_NTYPE_Bytes: f_prefix##Bytes(cst_NODECAST(n, Bytes)); break; \
        case cst_NTYPE_String: f_prefix##String(cst_NODECAST(n, String)); break; \
        case cst_NTYPE_UnaryOp: f_prefix##UnaryOp(cst_NODECAST(n, UnaryOp)); break; \
        case cst_NTYPE_BinaryOp: f_prefix##BinaryOp(cst_NODECAST(n, BinaryOp)); break; \
        case cst_NTYPE_TernaryOp: f_prefix##TernaryOp(cst_NODECAST(n, TernaryOp)); break; \
        case cst_NTYPE_Attribute: f_prefix##Attribute(cst_NODECAST(n, Attribute)); break; \
        case cst_NTYPE_Subscript: f_prefix##Subscript(cst_NODECAST(n, Subscript)); break; \
        case cst_NTYPE_Invokation: f_prefix##Invokation(cst_NODECAST(n, Invokation)); break; \
        case cst_NTYPE_ProcExpr: f_prefix##ProcExpr(cst_NODECAST(n, ProcExpr)); break; \
        case cst_NTYPE_ProcStmt: f_prefix##ProcStmt(cst_NODECAST(n, ProcStmt)); break; \
        case cst_NTYPE_If: f_prefix##If(cst_NODECAST(n, If)); break; \
        case cst_NTYPE_ElIf: f_prefix##ElIf(cst_NODECAST(n, ElIf)); break; \
        case cst_NTYPE_Else: f_prefix##Else(cst_NODECAST(n, Else)); break; \
        case cst_NTYPE_For: f_prefix##For(cst_NODECAST(n, For)); break; \
        case cst_NTYPE_While: f_prefix##While(cst_NODECAST(n, While)); break; \
        case cst_NTYPE_Declaration: f_prefix##Declaration(cst_NODECAST(n, Declaration)); break; \
        case cst_NTYPE_Assignment: f_prefix##Assignment(cst_NODECAST(n, Assignment)); break; \
        case cst_NTYPE_Return: f_prefix##Return(cst_NODECAST(n, Return)); break; \
        case cst_NTYPE_Pass: f_prefix##Pass(cst_NODECAST(n, Pass)); break; \
        case cst_NTYPE_FlowCtl: f_prefix##FlowCtl(cst_NODECAST(n, FlowCtl)); break; \
        default: on_default; \
    }
