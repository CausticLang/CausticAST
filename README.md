Caustic's Abstract Syntax Tree

# Nodes

> Note: Treat all names as being under `caustic.cst`

> This took way too long to make

```
bases.CausticASTNode
 ├─ bases.BaseStatement
 │   ├─ statement.ImportStatement
 │   ├─ statement.ExportStatement
 │   ├─ statement.IfStatement
 │   │   └─ statement.ElifStatement
 │   ├─ statement.ElseStatement
 │   ├─ statement.ForStatement
 │   ├─ statement.WhileStatement
 │   ├─ statement.RaiseStatement
 │   ├─ statement.TryStatement
 │   ├─ statement.CatchStatement
 │   └─ statement.LowerStatement
 ├─ bases.BaseExpression
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
