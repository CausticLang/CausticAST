#ifndef cst_UTILS_ROOT_UTILS_H
#define cst_UTILS_ROOT_UTILS_H 1

#include "../nodes.h"

cst_Root* cst_root_extend(cst_Root* dst, cst_Root* src);
cst_Node* cst_root_pop(cst_Root* root);
cst_Node* cst_root_pop_at(cst_Root* root, cst_index node);

#endif // cst_UTILS_ROOT_UTILS_H
