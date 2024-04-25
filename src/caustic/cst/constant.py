#!/bin/python3

'''
    CST node for constants (boolean true/false, null, etc.)
    Note that constants are considered subtypes of atoms,
        A.E. a constant is an atom
'''

#> Imports
from .bases import BaseConstant
#</Imports

#> Header >/
__all__ = ('BoolTrue', 'BoolFalse', 'Null', 'Default')

class BoolTrue(BaseConstant):
    '''Represents a "true" boolean constant'''
    __slots__ = ()
class BoolFalse(BaseConstant):
    '''Represents a "false" boolean constant'''
    __slots__ = ()

class Null(BaseConstant):
    '''Represents a null constant (like `None` in Python)'''
    __slots__ = ()

class Default(BaseConstant):
    '''Represents a default constant'''
    __slots__ = ()
