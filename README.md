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
 │   └─ statement.Directive
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

## "Mod" nodes

These nodes are used along with compiler mods (by using the `insmod` directive, for instance)

> Note: Nodes under the `bases` name are not used with mods, but the nodes under them
inherit from them

### Exceptions
```
bases.BaseStatement
 ├─ mods.m_exception.RaiseStatement
 ├─ mods.m_exception.TryStatement
 ├─ mods.m_exception.CatchStatement
 └─ mods.m_exception.LowerStatement
```
