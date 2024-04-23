#!/bin/python3

'''Expression nodes'''

#> Imports
from .bases import BaseUnaryOperator
#</Imports

#> Header >/
__all__ = ('UPlus', 'UMinus', 'Increment', 'Decrement', 'BitInvert', 'LogNot')

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
