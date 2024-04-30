#!/bin/python3

#> Imports
import typing
from dataclasses import dataclass, field
from collections import abc as cabc

from . import Expression
#</Imports

#> Header >/
__all__ = ('Operation',
           'Positive', 'Negative', 'LogInverse', 'BitInverse', 'Increment', 'Decrement')

_dc = dataclass(slots=True)

# Bases
@_dc
class Operation(Expression):
    '''The base class for all operations'''

@_dc
class _UnaryOp(Operation):
    # Internal base class for unary operations
    target: Expression | typing.Any

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
