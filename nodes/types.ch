#include <stdbool.h>

#if _cst_NODES_IS_HEADER
    typedef Cst__Types__EnumMember cst_nEnum_Member;
    typedef Cst__Types__StructMember cst_nStruct_Member;
    typedef Cst__Types__ClassMember cst_nClass_Member;
    #define cst_CLASS_MEMBER CST__TYPES__CLASS_MEMBER__VAL_MEMBER
    #define cst_CLASS_METHOD CST__TYPES__CLASS_MEMBER__VAL_METHOD
#else
    #include <assert.h>
    #include <malloc.h>
#endif

_cst_CREATE_NODE_FUNCS(
    Type,
    {},
    { fprintf(s, " - top[noderef]: %u\n"
                 " - sub[noderef]: %u\n", n->top, n->sub); },
    { n->top = top; n->sub = sub; }, TYPES__TYPE, cst_index top, cst_index sub
);


_cst_CREATE_NODE_FUNCS(
    Enum,
    { for (size_t i = 0; i < n->n_members; i++)
          free(n->members[i]);
      free(n->members); },
    { fprintf(s, " - name[noderef]:    %u\n"
                 " - extends[noderef]: %u\n"
                 " - n_members[ulong]: %zu\n"
                 " - members:\n", n->name, n->extends, n->n_members);
      for (size_t i = 0; i < n->n_members; i++)
          fprintf(s, "   - %04zu->name[noderef]: %u\n"
                     "         ->val[noderef]:  %u\n", i, n->members[i]->name, n->members[i]->val); },
    { n->name = name; n->extends = extends; n->members = NULL; n->n_members = 0; },
    TYPES__ENUM, cst_index name, cst_index extends
);
void cst_nEnum_addmember(cst_nEnum* node, cst_nEnum_Member* member)
#if _cst_NODES_IS_HEADER
    ;
#else
    {
        node->members = realloc(node->members, sizeof(cst_nEnum_Member*) * ++node->n_members);
        node->members[node->n_members-1] = member;
    }
#endif

_cst_CREATE_NODE_FUNCS(
    Struct,
    { for (size_t i = 0; i < n->n_members; i++)
          free(n->members[i]);
      free(n->members); },
    { fprintf(s, " - name[noderef]:    %u\n"
                 " - extends[noderef]: %u\n"
                 " - n_members[ulong]: %zu\n"
                 " - members:\n", n->name, n->extends, n->n_members);
      for (size_t i = 0; i < n->n_members; i++)
          fprintf(s, "   - %04zu->type[noderef]: %u\n"
                     "         ->name[noderef]: %u\n"
                     "         ->val[noderef]:  %u\n", i, n->members[i]->type, n->members[i]->name, n->members[i]->val); },
    { n->name = name; n->extends = extends; n->members = NULL; n->n_members = 0; },
    TYPES__STRUCT, cst_index name, cst_index extends
);
void cst_nStruct_addmember(cst_nStruct* node, cst_nStruct_Member* member)
#if _cst_NODES_IS_HEADER
    ;
#else
    {
        node->members = realloc(node->members, sizeof(cst_nStruct_Member*) * ++node->n_members);
        node->members[node->n_members-1] = member;
    }
#endif

_cst_CREATE_NODE_FUNCS(
    StructEnum,
    { free(n->members); },
    { fprintf(s, " - name[noderef]:    %u\n"
                 " - extends[noderef]: %u\n"
                 " - n_members[ulong]: %zu\n"
                 " - members[noderef*]:\n", n->name, n->extends, n->n_members);
      for (size_t i = 0; i < n->n_members; i++)
          fprintf(s, "   - %04zu: %u\n", i, n->members[i]); },
    { n->name = name; n->extends = extends; n->members = NULL; n->n_members = 0; },
    TYPES__STRUCT_ENUM, cst_index name, cst_index extends
);
void cst_nStructEnum_addmember(cst_nStructEnum* node, cst_index member)
#if _cst_NODES_IS_HEADER
    ;
#else
    {
        node->members = realloc(node->members, sizeof(cst_index) * ++node->n_members);
        node->members[node->n_members-1] = member;
    }
#endif

_cst_CREATE_NODE_FUNCS(
    Class,
    { for (size_t i = 0; i < n->n_members; i++) {
          switch (n->members[i]->val_case) {
              case cst_CLASS_MEMBER: free(n->members[i]->member); break;
              case cst_CLASS_METHOD: break;
              default: assert(false);
          }
          free(n->members[i]);
      }
      free(n->members); },
    { fprintf(s, " - name[noderef]:    %u\n"
                 " - extends[noderef]: %u\n"
                 " - n_members[ulong]: %zu\n"
                 " - members:\n", n->name, n->extends, n->n_members);
      for (size_t i = 0; i < n->n_members; i++) {
          fprintf(s, "   - %04zu->is_static[bool]: %u\n"
                     "         ->val_case:        %d\n", i, n->members[i]->is_static, n->members[i]->val_case);
          switch (n->members[i]->val_case) {
              case cst_CLASS_MEMBER:
                  fprintf(s, "         ->{member}->type[noderef]: %u\n"
                             "                   ->name[noderef]: %u\n"
                             "                   ->val[noderef]:  %u\n", n->members[i]->member->type, n->members[i]->member->name, n->members[i]->member->val);
                  break;
              case cst_CLASS_METHOD:
                  fprintf(s, "         ->{method}[noderef]: %u\n", n->members[i]->method);
                  break;
              default: assert(false);
          }
      } },
    { n->name = name; n->extends = extends; n->members = NULL; n->n_members = 0; },
    TYPES__CLASS, cst_index name, cst_index extends
);
void cst_nClass_addmember(cst_nClass* node, cst_nClass_Member* member)
#if _cst_NODES_IS_HEADER
    ;
#else
    {
        node->members = realloc(node->members, sizeof(cst_nClass_Member*) * ++node->n_members);
        node->members[node->n_members-1] = member;
    }
#endif
