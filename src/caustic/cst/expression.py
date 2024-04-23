#!/bin/python3

'''Expression nodes'''

#> Imports
from .bases import BaseUnaryOperator, BaseBinaryOperator
#</Imports

#> Header >/
__all__ = (# Unary
           'UPlus', 'UMinus', 'Increment', 'Decrement', 'BitInvert', 'LogNot',
           # Binary
           'AssignExpr',
           ## Arithmetic
           'Add', 'Sub', 'Mult', 'Div', 'Mod', 'MMul')

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
