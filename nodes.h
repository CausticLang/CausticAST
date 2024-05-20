#ifndef cst_NODES_H_GUARD
#define cst_NODES_H_GUARD 1

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>


typedef uint16_t cst_index;

enum cst_NodeType:char {
    // Control
    Entrypoint = 0,
    ExtraData = 127,
    Block = 16,
    // Types
    Type = 24,
    Enum = 27,
    Struct = 28,
    StructEnum = 29,
    Class = 30,
    // Expressions
    /// Atoms
    Identifier = 1,
    Bool = 2,
    Integer = 3,
    Float = 4,
    Char = 5,
    Bytes = 6,
    String = 7,
    /// Operations
    UnaryOp = 8,
    BinaryOp = 9,
    TernaryOp = 10,
    /// Accesses
    Attribute = 11,
    Subscript = 12,
    /// Procedures
    ProcInvoke = 13,
    ProcExpr = 14,
    // Statements
    ProcStmt = 15,
    IfStmt = 17,
    ElIfStmt = 18,
    ElseStmt = 19,
    ForStmt = 20,
    WhileStmt = 21,
    PassStmt = 22,
    FlowControlStmt = 23,
    ReturnStmt = 31,
    Declaration = 25,
    Assignment = 26,
};

struct cst_NodeBase {
    enum cst_NodeType type;
    bool is_freed;
    unsigned int pos_start;
    unsigned int pos_end;
    unsigned int lineno;
    unsigned int colno;
};

struct cst_Root {
    size_t node_count;
    struct cst_NodeBase** nodes;
};

void cst_node_add(struct cst_Root* root, struct cst_NodeBase* node);

#define cst_MKNODETYPE(name, members, body, ...) \
    struct cst_n##name { \
        struct cst_NodeBase _base; \
        members \
    }; \
    struct cst_n##name* cst_ninit_##name(struct cst_n##name* n, unsigned int p_start, unsigned int p_end, unsigned int lno, unsigned int cno, __VA_ARGS__)

#define cst_MKNODETYPE_S(name, mtype, mname) \
    cst_MKNODETYPE(name, mtype mname;, {n->mname = mname;}, mtype mname)
#define cst_MKNODETYPE_E(name) \
    struct cst_n##name { \
        struct cst_NodeBase _base; \
    }; \
    struct cst_n##name* cst_ninit_##name(struct cst_n##name* n, unsigned int p_start, unsigned int p_end, unsigned int lno, unsigned int cno)

#define cst_MKNODETYPE_IS_SOURCE 0

#define cst_NODECAST(type, node) ((struct cst_n##type*)node)
#define cst_NODEDOWNCAST(node) ((struct cst_NodeBase*)node)

cst_MKNODETYPE(Entrypoint, unsigned int eof_pos; cst_index node;, {
    n->eof_pos = eof_pos;
    n->node = node;
}, unsigned int eof_pos, cst_index node);

cst_MKNODETYPE(ExtraData, char* meta; char* data; bool static_meta;, {
    n->meta = meta;
    n->data = data;
    n->static_meta = static_meta;
}, char* meta, char* data, bool static_meta);

#include "nodes/access.h"
#include "nodes/atoms.h"
#include "nodes/block.h"
#include "nodes/operators.h"
#include "nodes/procedures.h"
#include "nodes/statements.h"
#include "nodes/types.h"


#endif
