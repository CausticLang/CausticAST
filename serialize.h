#include "nodes.h"

#include <stdio.h>

void cst_serialize_to(FILE* stream, cst_Root* root);
size_t cst_serialize(uint8_t** data, cst_Root* root);

cst_Root* cst_deserialize_from(FILE* stream);
cst_Root* cst_deserialize(uint8_t* data, size_t len);
