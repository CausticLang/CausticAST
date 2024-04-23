#!/bin/python3

'''CST nodes for statements'''

#> Imports
from dataclasses import dataclass, field

from .bases import CausticASTNode, BaseStatement
#</Imports

#> Header >/
__all__ = ('ImportStatement',)

_dc = dataclass(slots=True)

@_dc
class ImportStatement(BaseStatement):
    '''Represents an import'''
    target: CausticASTNode
    i_from: CausticASTNode | None = field(default=None, kw_only=True)
    i_as:   CausticASTNode | None = field(default=None, kw_only=True)
