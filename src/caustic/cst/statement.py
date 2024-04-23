#!/bin/python3

'''CST nodes for statements'''

#> Imports
from dataclasses import dataclass, field
from collections import abc as cabc

from .bases import CausticASTNode, BaseStatement
#</Imports

#> Header >/
__all__ = ('ImportStatement',
           'RaiseStatement', 'TryStatement', 'CatchStatement', 'LowerStatement')

_dc = dataclass(slots=True)

@_dc
class ImportStatement(BaseStatement):
    '''Represents an import'''
    target: CausticASTNode
    i_from: CausticASTNode | None = field(default=None, kw_only=True)
    i_as:   CausticASTNode | None = field(default=None, kw_only=True)

# Exception-related
class RaiseStatement(BaseStatement):
    '''Represents an exception-raising statement'''
    target: CausticASTNode
class TryStatement(BaseStatement):
    '''Represents an exception-handling statement/block'''
    block: CausticASTNode
    catch: CatchStatement = field(kw_only=True)
class CatchStatement(BaseStatement):
    '''Represents the "catch" part of a `TryStatement`'''
    catches: cabc.Sequence[CausticASTNode]
class LowerStatement(BaseStatement):
    '''Represents an exception-ignoring statement/block'''
    lowers: cabc.Sequence[CausticASTNode]
    block: CausticASTNode
