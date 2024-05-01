Caustic's Abstract Syntax Tree

Note that the `serialize` module, instead of providing node types,
provides (de)serialization functions for nodes

# Nodes

> Note: Treat all names as being under `caustic.cst`

> Note: nodes marked with `*` are considered "base" nodes,
> and nodes prefixed with `_` are implementation details used
> purely for grouping

```
CSTNode*
 ├─ CustomNode
 ├─ block.Block
 ├─ typedecl.Type
 ├─ expressions.Expression*
 │   ├─ procedure.ProcedureExpr
 │   ├─ procedure.Invokation
 │   ├─ expressions.atoms.Atom*
 │   │   ├─ expressions.atoms.Identifier
 │   │   ├─ expressions.atoms.DottedIdentifier
 │   │   └─ expressions.atoms.Integer
 │   ├─ expressions.operators.Operation*
 │   │   ├─ expressions.operators._UnaryOp*
 │   │   │   ├─ expressions.operators.Positive
 │   │   │   ├─ expressions.operators.Negative
 │   │   │   ├─ expressions.operators.LogInverse
 │   │   │   ├─ expressions.operators.BitInverse
 │   │   │   ├─ expressions.operators.Increment
 │   │   │   └─ expressions.operators.Decrement
 │   │   ├─ expressions.operators._BinaryOp*
 │   │   │   ├─ expressions.operators.Subscription
 │   │   │   ├─ expressions.operators.Add
 │   │   │   ├─ expressions.operators.Sub
 │   │   │   ├─ expressions.operators.Mult
 │   │   │   ├─ expressions.operators.MMul
 │   │   │   ├─ expressions.operators.Div
 │   │   │   ├─ expressions.operators.Mod
 │   │   │   ├─ expressions.operators.Exp
 │   │   │   ├─ expressions.operators.EQ
 │   │   │   ├─ expressions.operators.NE
 │   │   │   ├─ expressions.operators.LT
 │   │   │   ├─ expressions.operators.LE
 │   │   │   ├─ expressions.operators.GT
 │   │   │   ├─ expressions.operators.GE
 │   │   │   ├─ expressions.operators.NullCoalescing
 │   │   │   ├─ expressions.operators.LogAnd
 │   │   │   ├─ expressions.operators.LogOr
 │   │   │   ├─ expressions.operators.LogXOr
 │   │   │   ├─ expressions.operators.BitAnd
 │   │   │   ├─ expressions.operators.BitOr
 │   │   │   ├─ expressions.operators.BitXOr
 │   │   │   ├─ expressions.operators.LShift
 │   │   │   └─ expressions.operators.RShift
 │   │   └─ expressions.operators.TernaryConditional
 └─ statements.Statement*
     ├─ procedure.ProcedureStmt
     ├─ statements.Declaration
     ├─ statements.Assignment
     ├─ statements.If
     │   └─ statements.Elif
     ├─ statements.Else
     ├─ statements.While
     │   ├─ statements.DoWhile
     │   └─ statements.For
     ├─ statements.ForOf
     └─ statements.objects.Object*
         ├─ statements.objects.Enum
         ├─ statements.objects.Struct
         ├─ statements.objects.Namespace
         └─ statements.objects.Class
```
