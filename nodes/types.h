cst_MKNODETYPE(Type, cst_index top; cst_index sub;, {
    n->top = top;
    n->sub = sub;
}, cst_index top, cst_index sub);


#if !cst_MKNODETYPE_IS_SOURCE
struct cst_nEnum_Member {
    cst_index name;
    cst_index val;
};
#endif

cst_MKNODETYPE(Enum, cst_index name; cst_index base; struct cst_nEnum_Member* members; size_t member_count;, {
    n->name = name;
    n->base = base;
    n->members = members;
    n->member_count = member_count;
}, cst_index name, cst_index base, struct cst_nEnum_Member* members, size_t member_count);

#if !cst_MKNODETYPE_IS_SOURCE
struct cst_nStruct_Member {
    cst_index type;
    cst_index name;
    cst_index val;
};
#endif

cst_MKNODETYPE(Struct, cst_index name; cst_index base; struct cst_nStruct_Member* members; size_t member_count;, {
    n->name = name;
    n->base = base;
    n->members = members;
    n->member_count = member_count;
}, cst_index name, cst_index base, struct cst_nStruct_Member* members, size_t member_count);

cst_MKNODETYPE(StructEnum, cst_index name; cst_index base; cst_index* members; size_t member_count;, {
    n->name = name;
    n->base = base;
    n->members = members;
    n->member_count = member_count;
}, cst_index name, cst_index base, cst_index* members, size_t member_count);

#if !cst_MKNODETYPE_IS_SOURCE
struct cst_nClass_Member {
    union {
        struct cst_nStruct_Member* member;
        cst_index method;
    };
    bool is_static;
    bool is_method;
};
#endif

cst_MKNODETYPE(Class, cst_index name; cst_index base; struct cst_nClass_Member* members; size_t member_count;, {
    n->name = name;
    n->base = base;
    n->members = members;
    n->member_count = member_count;
}, cst_index name, cst_index base, struct cst_nClass_Member* members, size_t member_count);
