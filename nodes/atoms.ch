#include <stdbool.h>
#include <stdint.h>
#if !_cst_NODES_IS_HEADER
    #include <malloc.h>
#endif

_cst_CREATE_NODE_FUNCS(
    Identifier,
    { free(n->val); },
    { fprintf(s, " - val[char*]: %s\n", n->val); },
    { n->val = val; }, ATOMS__IDENTIFIER, char* val
);

_cst_CREATE_NODE_FUNCS(
    Bool,
    {},
    { fprintf(s, " - val[bool]: %d\n", n->val); },
    { n->val = val; }, ATOMS__BOOL, bool val
);
_cst_CREATE_NODE_FUNCS(
    Integer,
    { free(n->val); },
    { fprintf(s, " - val[char*]:    %s\n"
                 " - intbase[uint]: %u\n", n->val, n->intbase); },
    { n->val = val; n->intbase = intbase; }, ATOMS__INTEGER, char* val, uint32_t intbase
);
_cst_CREATE_NODE_FUNCS(
    Float,
    { free(n->integer); free(n->fractional); },
    { fprintf(s, " - integer[char*]:   %s\n"
                 " - fractional[uint]: %u\n"
                 " - exp[int]:         %d\n", n->integer, n->fractional, n->exp); },
    { n->integer = integer; n->fractional = fractional; n->exp = exp; }, ATOMS__FLOAT, char* integer, char* fractional, int32_t exp
);

_cst_CREATE_NODE_FUNCS(
    Char,
    { free(n->val); },
    { fprintf(s, " - val[char*]: %s\n", n->val); },
    { n->val = val; }, ATOMS__CHAR, char* val
);
_cst_CREATE_NODE_FUNCS(
    Bytes,
    { free(n->val); },
    { fprintf(s, " - val[char*]: %s\n",
                 " - raw[bool]:  %d\n", n->val, n->raw); },
    { n->val = val; n->raw = raw; }, ATOMS__BYTES, char* val, bool raw
);
_cst_CREATE_NODE_FUNCS(
    String,
    { free(n->val); },
    { fprintf(s, " - val[char*]: %s\n",
                 " - raw[bool]:  %d\n", n->val, n->raw); },
    { n->val = val; n->raw = raw; }, ATOMS__STRING, char* val, bool raw
);
