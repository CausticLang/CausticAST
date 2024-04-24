#!/bin/python3

'''CST nodes for an exception module'''

#> Imports
from collections import abc as cabc
from dataclasses import dataclass, field

from ..bases import CausticASTNode, BaseStatement
from ..block import Block
#</Imports

#> Header >/

__all__ = ('RaiseStatement', 'TryStatement', 'CatchStatement', 'LowerStatement')

_dc = dataclass(slots=True)

class RaiseStatement(BaseStatement):
    '''Represents an exception-raising statement'''
    target: CausticASTNode
class TryStatement(BaseStatement):
    '''Represents an exception-handling statement/block'''
    block: Block
    catch: 'CatchStatement' = field(kw_only=True)
class CatchStatement(BaseStatement):
    '''Represents the "catch" part of a `TryStatement`'''
    catches: cabc.Sequence[CausticASTNode]
    block: Block
class LowerStatement(BaseStatement):
    '''Represents an exception-ignoring statement/block'''
    lowers: cabc.Sequence[CausticASTNode]
    block: Block
