#!/bin/python3

#> Imports
from dataclasses import dataclass

from .. import CSTNode
#</Imports

__all__ = ('Expression',
           'atoms', 'operators')

_dc = dataclass(slots=True, kw_only=True)

#> Header
@_dc
class Expression(CSTNode):
    '''The base class for all expression nodes'''
#</Header

#> Package
from . import atoms
from . import operators
#</Package

#> Header
#</Header
