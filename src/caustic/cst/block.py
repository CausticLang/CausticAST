#!/bin/python3

'''Block nodes, `Line` and `Block`'''

#> Imports
from dataclasses import dataclass
from collections import abc as cabc

from .bases import CausticASTNode
#</Imports

#> Header >/
__all__ = ('Line', 'Block')

class Line(CausticASTNode):
    '''Represents a single "line"--a statement, expression, etc.'''
    content: CausticASTNode
class Block(CausticASTNode):
    '''Represents a block of lines'''
    body: cabc.Sequence[Line]