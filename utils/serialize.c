#ifndef cst_UTILS_SERIALIZE_C
#define cst_UTILS_SERIALIZE_C 1

#include "serialize.h"

#include <stdio.h>
#include <string.h>
#include <malloc.h>

// includes utilities for conveniently (de)serializing roots

#ifndef cst_serialize_PAD_SIZE
    #define cst_serialize_PAD_SIZE 128
#endif
#ifndef cst_serialize_DESERIALIZE_FROM_BUFF_SIZE
    #define cst_serialize_DESERIALIZE_FROM_BUFF_SIZE 128
#endif

struct _cst_serialize_ProtobufStreamBuffer {
    ProtobufCBuffer base;
    FILE* stream;
};
static void _cst_serialize_ProtobufStreamBuffer_append(ProtobufCBuffer* buffer, size_t len, const uint8_t* data) {
    fwrite(data, len, 1, ((struct _cst_serialize_ProtobufStreamBuffer*)buffer)->stream);
}
void cst_serialize_to(FILE* stream, cst_Root* root) {
    struct _cst_serialize_ProtobufStreamBuffer buf = {0};
    buf.base.append = _cst_serialize_ProtobufStreamBuffer_append;
    buf.stream = stream;
    cst__root__pack_to_buffer(root, &(buf.base));
}

size_t cst_serialize(uint8_t** data, cst_Root* root) {
    uint8_t pad[cst_serialize_PAD_SIZE];
    ProtobufCBufferSimple buf = PROTOBUF_C_BUFFER_SIMPLE_INIT(pad);
    cst__root__pack_to_buffer(root, &(buf.base));
    *data = realloc(*data, buf.len * sizeof(uint8_t));
    memcpy(*data, buf.data, buf.len);
    return buf.len;
}


cst_Root* cst_deserialize_from(FILE* stream) {
    uint8_t* data = NULL;
    size_t len = 0;
    uint8_t buf[cst_serialize_DESERIALIZE_FROM_BUFF_SIZE];
    while (fgets(buf, cst_serialize_DESERIALIZE_FROM_BUFF_SIZE, stream) != NULL) {
        data = realloc(data, sizeof(uint8_t) * (len + cst_serialize_DESERIALIZE_FROM_BUFF_SIZE));
        memcpy(data + (sizeof(uint8_t) * len), buf, cst_serialize_DESERIALIZE_FROM_BUFF_SIZE);
        len += cst_serialize_DESERIALIZE_FROM_BUFF_SIZE;
    }
    cst_Root* root = cst_deserialize(data, len);
    free(data);
    return root;
}
cst_Root* cst_deserialize(uint8_t* data, size_t len) {
    return cst__root__unpack(NULL, len, data);
}

#endif // cst_UTILS_SERIALIZE_C
