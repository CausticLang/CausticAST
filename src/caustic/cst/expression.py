#!/bin/python3

'''Expression nodes'''

#> Imports
from dataclasses import dataclass, field

from .bases import CausticASTNode
from .bases import BaseOperator, BaseUnaryOperator, BaseBinaryOperator
#</Imports

#> Header >/
__all__ = (# Unary
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
