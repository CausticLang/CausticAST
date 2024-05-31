/* Single-function generics */

#define cst_NODEFREE(n) _Generic(n, \
    cst_nAttribute*: cst_nfree_Attribute, \
    cst_nSubscript*: cst_nfree_Subscript, \
    cst_nIdentifier*: cst_nfree_Identifier, \
    cst_nBool*: cst_nfree_Bool, \
    cst_nInteger*: cst_nfree_Integer, \
    cst_nFloat*: cst_nfree_Float, \
    cst_nBytes*: cst_nfree_Bytes, \
    cst_nString*: cst_nfree_String, \
    cst_nEntrypoint*: cst_nfree_Entrypoint, \
    cst_nBlock*: cst_nfree_Block, \
    cst_nExtraData*: cst_nfree_ExtraData, \
    cst_nUnaryOp*: cst_nfree_UnaryOp, \
    cst_nBinaryOp*: cst_nfree_BinaryOp, \
    cst_nTernaryOp*: cst_nfree_TernaryOp, \
    cst_nInvokation*: cst_nfree_Invokation, \
    cst_nProcExpr*: cst_nfree_ProcExpr, \
    cst_nProcStmt*: cst_nfree_ProcStmt, \
    cst_nIf*: cst_nfree_If, \
    cst_nElIf*: cst_nfree_ElIf, \
    cst_nElse*: cst_nfree_Else, \
    cst_nFor*: cst_nfree_For, \
    cst_nWhile*: cst_nfree_While, \
    cst_nDeclaration*: cst_nfree_Declaration, \
    cst_nAssignment*: cst_nfree_Assignment, \
    cst_nReturn*: cst_nfree_Return, \
    cst_nPass*: cst_nfree_Pass, \
    cst_nFlowCtl*: cst_nfree_FlowCtl, \
    cst_nType*: cst_nfree_Type, \
    cst_nEnum*: cst_nfree_Enum, \
    cst_nStruct*: cst_nfree_Struct, \
    cst_nStructEnum*: cst_nfree_StructEnum, \
    cst_nClass*: cst_nfree_Class)(n)

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

/* Code generation */

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
