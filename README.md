Caustic's Abstract Syntax Tree

> !NOTE! `serialize` module not yet re-implemented

Note that the `serialize` module, instead of providing node types,
provides (de)serialization functions for nodes

# Nodes

> Note: Treat all names as being under `caustic.cst`

> !NOTE! Outdated!

```
bases.CausticASTNode
 ├─ bases.BaseStatement
 │   ├─ statement.ProcedureStatement
 │   ├─ statement.ImportStatement
 │   ├─ statement.ExportStatement
 │   ├─ statement.IfStatement
 │   │   └─ statement.ElifStatement
 │   ├─ statement.ElseStatement
 │   ├─ statement.ForStatement
 │   ├─ statement.WhileStatement
 │   ├─ statement.Directive
 │   └─ bases.BaseTypeDecl
 │       ├─ typedecl.SingletonType
 │       ├─ typedecl.EnumType
 │       └─ typedecl.StructType
 │           └─ typedecl.ClassType
 ├─ bases.BaseExpression
 │   ├─ expression.Invoke
 │   ├─ expression.ProcedureExpr
 │   ├─ bases.BaseOperator
 │   │   ├─ bases.BaseUnaryOperator
 │   │   │   ├─ expression.UPlus
 │   │   │   ├─ expression.UMinus
 │   │   │   ├─ expression.Increment
 │   │   │   ├─ expression.Decrement
 │   │   │   ├─ expression.BitInvert
 │   │   │   └─ expression.LogNot
 │   │   ├─ bases.BaseBinaryOperator
 │   │   │   ├─ expression.AssignExpr
 │   │   │   ├─ expression.Add
 │   │   │   ├─ expression.Sub
 │   │   │   ├─ expression.Mult
 │   │   │   ├─ expression.Div
 │   │   │   ├─ expression.Mod
 │   │   │   ├─ expression.MMul
 │   │   │   ├─ expression.Pow
 │   │   │   ├─ expression.Equality [EQ]
 │   │   │   ├─ expression.Inequality [NE]
 │   │   │   ├─ expression.LessThan [LT]
 │   │   │   ├─ expression.GreaterThan [GT]
 │   │   │   ├─ expression.LessThanOrEquality [LE]
 │   │   │   ├─ expression.GreaterThanOrEquality [GE]
 │   │   │   ├─ expression.Nullish
 │   │   │   ├─ expression.LogAnd
 │   │   │   ├─ expression.LogOr
 │   │   │   ├─ expression.LogXor
 │   │   │   ├─ expression.BitAnd
 │   │   │   ├─ expression.BitOr
 │   │   │   ├─ expression.BitXor
 │   │   │   ├─ expression.LShift
 │   │   │   └─ expression.RShift
 │   │   └─ expression.Ternary
 │   └─ bases.BaseAtom
 │       ├─ bases.BaseConstant
 │       │   ├─ constant.BoolTrue
 │       │   ├─ constant.BoolFalse
 │       │   ├─ constant.Null
 │       │   └─ constant.Default
 │       ├─ bases.BaseLiteral
 │       │   ├─ atom.Integer
 │       │   ├─ atom.Decimal
 │       │   ├─ atom.Char
 │       │   ├─ atom.Bytes
 │       │   └─ atom.String
 │       ├─ atom.Identifier
 │       └─ atom.DottedIdentifier
 ├─ block.Line
 └─ block.Block
```
