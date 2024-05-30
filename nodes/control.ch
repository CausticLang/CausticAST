#include <stdint.h>
#if !_cst_NODES_IS_HEADER
    #include <malloc.h>
#endif

_cst_CREATE_NODE_FUNCS(
    Entrypoint,
    {},
    { fprintf(s, " - node[noderef]: %u\n"
                 " - eof_pos[uint]: %u\n", n->node, n->eof_pos); },
    { n->node = node; n->eof_pos = eof_pos; }, CONTROL__ENTRYPOINT, cst_index node, uint32_t eof_pos
);

_cst_CREATE_NODE_FUNCS_NIP(
    Block,
    { free(n->nodes); },
    { fputs(" - nodes[noderef*]:\n", s);
      for (cst_index i = 0; i < n->n_nodes; i++)
          fprintf(s, "   - %.04u: %u\n", i, n->nodes[i]);
      fprintf(s, " - n_nodes[uint]:   %u\n", n->n_nodes); },
    { n->nodes = NULL; n->n_nodes = 0; }, CONTROL__BLOCK
);
void cst_nBlock_addnode(cst_nBlock* block, cst_index node)
#if _cst_NODES_IS_HEADER
    ;
#else
    {
        block->nodes = realloc(block->nodes, sizeof(cst_index) * ++block->n_nodes);
        block->nodes[block->n_nodes-1] = node;
    }
#endif

_cst_CREATE_NODE_FUNCS(
    ExtraData,
    { free(n->data); },
    { fprintf(s, " - meta[char*]: %s\n"
                 " - data[char*]: %s\n", n->meta, n->data); },
    { n->meta = (char*)meta; n->data = data; }, CONTROL__EXTRA_DATA, const char* meta, char* data
);
