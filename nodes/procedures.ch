#if _cst_NODES_IS_HEADER
    typedef Cst__Procedures__InvokationKwarg cst_ProcKwarg;
    typedef Cst__Procedures__ProcParam cst_ProcParam;
#else
    #include <malloc.h>
#endif

_cst_CREATE_NODE_FUNCS(
    Invokation,
    { free(n->args);
      for (size_t i = 0; i < n->n_kwargs; i++)
          free(n->kwargs[i]);
      free(n->kwargs); },
    { fprintf(s, " - proc[noderef]:  %u\n"
                 " - n_args[uint]:   %u\n"
                 " - args[noderef*]:\n", n->proc, n->n_args);
      for (size_t i = 0; i < n->n_args; i++)
          fprintf(s, "   - %04u: %u\n", i, n->args[i]);
      fprintf(s, " - n_kwargs[uint]: %u\n - kwargs:\n", n->n_kwargs);
      for (size_t i = 0; i < n->n_kwargs; i++)
          fprintf(s, "   - %04u->key: %u\n"
                     "         ->val: %u\n", i, n->kwargs[i]->key, n->kwargs[i]->val); },
    { n->proc = proc; n->n_args = 0; n->args = NULL; n->n_kwargs = 0; n->kwargs = NULL; }, PROCEDURES__INVOKATION, cst_index proc
);

void cst_nInvokation_addarg(cst_nInvokation* n, cst_index arg)
#if _cst_NODES_IS_HEADER
    ;
#else
    {
        n->args = realloc(n->args, sizeof(cst_index) * ++n->n_args);
        n->args[n->n_args-1] = arg;
    }
#endif
void cst_nInvokation_addkwarg(cst_nInvokation* n, cst_ProcKwarg* kwarg)
#if _cst_NODES_IS_HEADER
    ;
#else
    {
        n->kwargs = realloc(n->kwargs, sizeof(cst_ProcKwarg*) * ++n->n_kwargs);
        n->kwargs[n->n_kwargs-1] = kwarg;
    }
#endif

_cst_CREATE_NODE_FUNCS(
    ProcExpr,
    { for (size_t i = 0; i < n->n_params; i++)
          free(n->params[i]);
      free(n->params); },
    { fprintf(s, " - rtype[noderef]: %u\n"
                 " - n_params[uint]: %u\n"
                 " - params:\n", n->rtype, n->n_params);
      for (size_t i = 0; i < n->n_params; i++)
          fprintf(s, "   - %04u->param_type:    %u\n"
                     "         ->type[noderef]: %u\n"
                     "         ->name[noderef]: %u\n"
                     "         ->val[noderef]:  %u\n", i, n->params[i]->param_type, n->params[i]->type, n->params[i]->name, n->params[i]->val);
      fprintf(s, " - body[noderef]:  %u\n", n->body); },
    { n->rtype = rtype; n->n_params = 0; n->params = NULL; n->body = body; },
    PROCEDURES__PROC_EXPR, cst_index rtype, cst_index body
);
void cst_nProcExpr_addparam(cst_nProcExpr* n, cst_ProcParam* param)
#if _cst_NODES_IS_HEADER
    ;
#else
    {
        n->params = realloc(n->params, sizeof(cst_ProcParam*) * ++n->n_params);
        n->params[n->n_params-1] = param;
    }
#endif

_cst_CREATE_NODE_FUNCS(
    ProcStmt,
    { for (size_t i = 0; i < n->n_params; i++)
          free(n->params[i]);
      free(n->params); },
    { fprintf(s, " - name[noderef]:  %u\n"
                 " - rtype[noderef]: %u\n"
                 " - n_params[uint]: %u\n", n->name, n->rtype, n->n_params);
      for (size_t i = 0; i < n->n_params; i++)
          fprintf(s, "   - %04u->param_type:    %u\n"
                     "         ->type[noderef]: %u\n"
                     "         ->name[noderef]: %u\n"
                     "         ->val[noderef]:  %u\n", i, n->params[i]->param_type, n->params[i]->type, n->params[i]->name, n->params[i]->val);
      fprintf(s, " - body[noderef]:  %u\n", n->body); },
    { n->name = name; n->rtype = rtype;
      n->n_params = 0; n->params = NULL;
      n->body = body; }, PROCEDURES__PROC_STMT,
    cst_index name, cst_index rtype, cst_index body
);
void cst_nProcStmt_addparam(cst_nProcStmt* n, cst_ProcParam* param)
#if _cst_NODES_IS_HEADER
    ;
#else
    {
        n->params = realloc(n->params, sizeof(cst_ProcParam*) * ++n->n_params);
        n->params[n->n_params-1] = param;
    }
#endif
