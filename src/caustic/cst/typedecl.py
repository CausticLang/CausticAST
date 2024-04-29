#!/bin/python3

#> Imports
import typing
from dataclasses import dataclass
from collections import abc as cabc

from . import CSTNode, expressions
#</Imports

#> Header >/
__all__ = ('Type',)

@dataclass(slots=True)
class Type(CSTNode):
    '''Represents a type in a declaration'''
    base: expressions.atoms.DottedIdentifier | typing.Any
    sub: None | cabc.Sequence[typing.Self] | typing.Any = None
