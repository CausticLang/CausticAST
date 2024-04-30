#!/bin/python3

#> Imports
import typing
from dataclasses import dataclass, field
from collections import abc as cabc

from . import Expression
#</Imports

#> Header >/
__all__ = ('Operation',
           'Positive', 'Negative', 'LogInverse', 'BitInverse', 'Increment', 'Decrement',
           'Add', 'Sub', 'Mult', 'MMul', 'Div', 'Mod', 'Exp')

_dc = dataclass(slots=True)

# Bases
@_dc
class Operation(Expression):
    '''The base class for all operations'''

@_dc
class _UnaryOp(Operation):
    # Internal base class for unary operations
    target: Expression | typing.Any
@_dc
class _BinaryOp(Operation):
    # Internal base class for binary operations
    left: Expression | typing.Any
    right: Expression | typing.Any

# Unary operations
@_dc
class Positive(_UnaryOp):
    '''Represents a unary positive operation'''
@_dc
class Negative(_UnaryOp):
    '''Represents a unary negative operation'''
@_dc
class LogInverse(_UnaryOp):
    '''Represents a logical inverse operation'''
@_dc
class BitInverse(_UnaryOp):
    '''Represents a bitwise inverse operation'''
@_dc
class Increment(_UnaryOp):
    '''Represents an increment operation'''
@_dc
class Decrement(_UnaryOp):
    '''Represents a decrement operation'''

# Binary operations
## Arithmetic
@_dc
class Add(_BinaryOp):
    '''Represents an addition operation'''
@_dc
class Sub(_BinaryOp):
    '''Represents a subtraction operation'''
@_dc
class Mult(_BinaryOp):
    '''Represents a multiplication operation'''
@_dc
class MMul(_BinaryOp):
    '''Represents a matrix multiplication operation'''
@_dc
class Div(_BinaryOp):
    '''Represents a division operation'''
@_dc
class Mod(_BinaryOp):
    '''Represents a modulus operation'''
@_dc
class Exp(_BinaryOp):
    '''Represents an exponent operation'''
