#!/bin/python3

#> Imports
import typing
from dataclasses import dataclass
from collections import abc as cabc

from . import CSTNode
#</Imports

#> Header >/
__all__ = ('Block',)

@dataclass(slots=True)
class Block(CSTNode):
    '''Represents a block containing other nodes'''
    body: cabc.Sequence[CSTNode] | typing.Any
