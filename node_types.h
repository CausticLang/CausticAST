/* Casting */

#define cst_NODECAST(base, to) ((cst_n##to*)((base)->val))

#define cst_NODEDOWNCAST(node) ( node \
    - sizeof(ProtobufCMessage) /* base */ \
    - (sizeof(uint32_t) * 4) /* pos_start + pos_end + lineno + colno */ \
    - sizeof(Cst__Node__NodeCase) /* node_case */ \
    )
#undef cst_NODEDOWNCAST // BAD IDEA

/* Types */

#define cst_NTYPEIS(node, type) ((node)->node_case == cst_NTYPE_##type)

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
