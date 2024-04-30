#!/bin/python3

#> Imports
from dataclasses import dataclass

from .. import CSTNode
#</Imports

__all__ = ('Statement',)

_dc = dataclass(slots=True, kw_only=True)

#> Header
@_dc
class Statement(CSTNode):
    '''The base class for all statement nodes'''
#</Header

#> Package
#</Package

#> Header
#</Header
