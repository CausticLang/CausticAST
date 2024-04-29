#!/bin/python3

#> Imports
from dataclasses import dataclass

from . import Expression
#</Imports

#> Header >/
__all__ = ('Atom',)

_dc = dataclass(slots=True)

# Base
@_dc
class Atom(Expression):
    '''The base class for atom nodes'''
