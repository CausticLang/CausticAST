#!/bin/python3

#> Imports
from dataclasses import dataclass

from .. import CSTNode
#</Imports

__all__ = ('Expression',)

#> Package
#</Package

#> Header >/
_dc = dataclass(slots=True, kw_only=True)

# Base
@_dc
class Expression(CSTNode):
    '''The base class for all expression nodes'''
