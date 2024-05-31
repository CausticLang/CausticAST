#ifndef cst_UTILS_ROOT_UTILS_C
#define cst_UTILS_ROOT_UTILS_C 1

#include "root_utils.h"

#include <malloc.h>

// includes non-essential utilities for working with roots

cst_Root* cst_root_extend(cst_Root* dst, cst_Root* src) {
    if (!src->n_nodes) return dst;
    dst->nodes = realloc(dst->nodes, (dst->n_nodes + src->n_nodes) * sizeof(cst_Node*));
    memcpy(dst->nodes + (dst->n_nodes * sizeof(cst_Node*)), src->nodes, src->n_nodes * sizeof(cst_Node*));
    dst->n_nodes += src->n_nodes;
    return dst;
}
cst_Node* cst_root_pop(cst_Root* root) {
    assert(root->n_nodes);
    return cst_root_pop_at(root, root->n_nodes - 1);
}
cst_Node* cst_root_pop_at(cst_Root* root, cst_index node) {
    assert(node < root->n_nodes);
    cst_Node* target = root->nodes[node];
    if (root->n_nodes == 1) {
        root->n_nodes = 0;
        free(root->nodes);
        root->nodes = NULL;
        return target;
    }
    cst_Node** new = malloc(--root->n_nodes * sizeof(cst_Node*));
    size_t noffset = node * sizeof(cst_Node*);
    memcpy(new, root->nodes, noffset);
    memcpy(new + noffset, root->nodes + noffset, (root->n_nodes * sizeof(cst_Node*)) - noffset);
    free(root->nodes);
    root->nodes = new;
    return target;
}

#endif // cst_UTILS_ROOT_UTILS_C
