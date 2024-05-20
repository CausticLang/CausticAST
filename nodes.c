#ifndef cst_NODES_S_GUARD
#define cst_NODES_S_GUARD 1

#include "nodes.h"

#include <malloc.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

void cst_node_add(struct cst_Root* root, struct cst_NodeBase* node) {
    root->nodes = realloc(root->nodes, sizeof(struct cst_NodeBase*) * ++root->node_count);
    root->nodes[root->node_count-1] = node;
}

#undef cst_MKNODETYPE
#define cst_MKNODETYPE(name, members, body, ...) \
    struct cst_n##name* cst_ninit_##name(struct cst_n##name* n, unsigned int p_start, unsigned int p_end, unsigned int lno, unsigned int cno, __VA_ARGS__) { \
        cst_NODEDOWNCAST(n)->type = name; \
        cst_NODEDOWNCAST(n)->is_freed = false; \
        cst_NODEDOWNCAST(n)->pos_start = p_start; \
        cst_NODEDOWNCAST(n)->pos_end = p_end; \
        cst_NODEDOWNCAST(n)->lineno = lno; \
        cst_NODEDOWNCAST(n)->colno = cno; \
        body; return n; }

#undef cst_MKNODETYPE_S
#define cst_MKNODETYPE_S(name, mtype, mname) \
    cst_MKNODETYPE(name, mtype mname;, {n->mname = mname;}, mtype mname)
#undef cst_MKNODETYPE_E
#define cst_MKNODETYPE_E(name) \
    struct cst_n##name* cst_ninit_##name(struct cst_n##name* n, unsigned int p_start, unsigned int p_end, unsigned int lno, unsigned int cno) { \
        cst_NODEDOWNCAST(n)->type = name; \
        cst_NODEDOWNCAST(n)->is_freed = false; \
        cst_NODEDOWNCAST(n)->pos_start = p_start; \
        cst_NODEDOWNCAST(n)->pos_end = p_end; \
        cst_NODEDOWNCAST(n)->lineno = lno; \
        cst_NODEDOWNCAST(n)->colno = cno; \
        return n; }

#undef cst_MKNODETYPE_IS_SOURCE
#define cst_MKNODETYPE_IS_SOURCE 1

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
