#!/bin/python3

'''Expression nodes'''

#> Imports
import typing
from dataclasses import dataclass, field
from collections import abc as cabc

from .bases import CausticASTNode
from .bases import BaseExpression
from .bases import BaseOperator, BaseUnaryOperator, BaseBinaryOperator
from .atom import Identifier
from .block import Block
#</Imports

#> Header >/
__all__ = (# Procedure
           'Invoke', 'ProcedureExpr',
           # Unary
           'UPlus', 'UMinus', 'Increment', 'Decrement', 'BitInvert', 'LogNot',
           # Binary
           'AssignExpr',
           ## Arithmetic
           'Add', 'Sub', 'Mult', 'Div', 'Mod', 'MMul', 'Pow',
           ## Comparison
           'Equality', 'Inequality', 'LessThan', 'GreaterThan', 'LessThanOrEquality', 'GreaterThanOrEquality', 'Nullish',
           ### Aliases
           'EQ', 'NE', 'LT', 'GT', 'LE', 'GE',
           ## Logical
           'LogAnd', 'LogOr', 'LogXor',
           ## Bitwise
           'BitAnd', 'BitOr', 'BitXor', 'LShift', 'RShift',
           # Ternary
           'Ternary')

_dc = dataclass(slots=True)

# Procedure
@_dc
class Invoke(BaseExpression):
    '''
        Represents a procedure invokation

        `varargs` is a set of integers corresponding to which indexes
            of `args` are varargs
    '''
    VARKW_MARKER: typing.ClassVar[None] = None

    proc: CausticASTNode
    args: cabc.Sequence[CausticASTNode]
    kwargs: cabc.Sequence[tuple[Identifier | None, CausticASTNode]]
    varargs: cabc.Container[int] = field(default=frozenset(), kw_only=True)
@_dc
class ProcedureExpr(BaseExpression):
    '''
        Represents an inline procedure expression

        All parameters are represented as a tuple of `name`, `type`,
            and `params` is a sequence of parameters
    '''
    return_type: CausticASTNode | None
    params: cabc.Sequence[tuple[CausticASTNode, CausticASTNode]] | None = None
    pos_only: int | None = field(default=None, kw_only=True)
    kw_only: int | None = field(default=None, kw_only=True)
    var_pos: tuple[CausticASTNode, CausticASTNode] | None = field(default=None, kw_only=True)
    var_kw: tuple[CausticASTNode, CausticASTNode] | None = field(default=None, kw_only=True)
    body: Block | None = field(default=None, kw_only=True)

# Unary
class UPlus(BaseUnaryOperator):
    '''Represents a unary plus operator'''
    __slots__ = ()
class UMinus(BaseUnaryOperator):
    '''Represents a unary minus operator'''
    __slots__ = ()
class Increment(BaseUnaryOperator):
    '''Represents an increment operator'''
    __slots__ = ()
class Decrement(BaseUnaryOperator):
    '''Represents a decrement operator'''
    __slots__ = ()
class BitInvert(BaseUnaryOperator):
    '''Represents a bit inversion operator'''
    __slots__ = ()
class LogNot(BaseUnaryOperator):
    '''Represents a logical inversion operator'''
    __slots__ = ()

# Binary
class AssignExpr(BaseBinaryOperator):
    '''Represents an assignment-expression'''
    __slots__ = ()
## Arithmetic
class Add(BaseBinaryOperator):
    '''Represents an addition operator'''
    __slots__ = ()
class Sub(BaseBinaryOperator):
    '''Represents a subtraction operator'''
    __slots__ = ()
class Mult(BaseBinaryOperator):
    '''Represents a multiplication operator'''
    __slots__ = ()
class Div(BaseBinaryOperator):
    '''Represents a division operator'''
    __slots__ = ()
class Mod(BaseBinaryOperator):
    '''Represents a modulus operator'''
    __slots__ = ()
class MMul(BaseBinaryOperator):
    '''Represents a matrix-multiplication operator'''
    __slots__ = ()
class Pow(BaseBinaryOperator):
    '''Represents a power (exponentiation) operation'''
    __slots__ = ()
## Comparison
class Equality(BaseBinaryOperator):
    '''Represents an equality comparison operator'''
    __slots__ = ()
EQ = Equality
class Inequality(BaseBinaryOperator):
    '''Represents an inequality comparison operator'''
    __Slots__ = ()
NE = Inequality
class LessThan(BaseBinaryOperator):
    '''Represents a less-than comparison operator'''
    __Slots__ = ()
LT = LessThan
class GreaterThan(BaseBinaryOperator):
    '''Represents a less-than comparison operator'''
    __Slots__ = ()
GT = GreaterThan
class LessThanOrEquality(BaseBinaryOperator):
    '''Represents a less-than or equality comparison operator'''
    __slots__ = ()
LE = LessThanOrEquality
class GreaterThanOrEquality(BaseBinaryOperator):
    '''Represents a greater-than or equality comparison operator'''
    __slots__ = ()
GE = GreaterThanOrEquality
class Nullish(BaseBinaryOperator):
    '''Represents a nullish comparison (nullish coalescing) operator'''
    __slots__ = ()
## Logical
class LogAnd(BaseBinaryOperator):
    '''Represents a logical and operator'''
    __slots__ = ()
class LogOr(BaseBinaryOperator):
    '''Represents a logical or operator'''
    __slots__ = ()
class LogXor(BaseBinaryOperator):
    '''Represents a logical exclusive-or operator'''
    __slots__ = ()
## Bitwise
class BitAnd(BaseBinaryOperator):
    '''Represents a bitwise and operator'''
    __slots__ = ()
class BitOr(BaseBinaryOperator):
    '''Represents a bitwise or operator'''
    __slots__ = ()
class BitXor(BaseBinaryOperator):
    '''Represents a bitwise exclusive or operator'''
    __slots__ = ()
class LShift(BaseBinaryOperator):
    '''Represents a left-shift operator'''
    __slots__ = ()
class RShift(BaseBinaryOperator):
    '''Represents a right-shift operator'''
    __slots__ = ()

# Ternary
@dataclass(slots=True, kw_only=True)
class Ternary(BaseOperator):
    '''Represents a ternary operator'''
    cmp: CausticASTNode = field(kw_only=False)
    true: CausticASTNode
    false: CausticASTNode
