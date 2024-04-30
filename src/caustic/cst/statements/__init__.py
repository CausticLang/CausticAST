#!/bin/python3

#> Imports
import typing
from dataclasses import dataclass
from collections import abc as cabc

from .. import CSTNode
from .. import typedecl
from .. import expressions
#</Imports

__all__ = ('Statement',
           'Declaration', 'Assignment')

_dc = dataclass(slots=True, kw_only=True)

#> Header
@_dc
class Statement(CSTNode):
    '''The base class for all statement nodes'''

@_dc
class Declaration(Statement):
    '''Represents a typed name declaration, along with an optional value'''
    mods: cabc.Sequence[str] | None | typing.Any = None
    type: typedecl.Type | typing.Any
    name: expressions.atoms.Identifier | typing.Any
    val: expressions.Expression | None | typing.Any = None

@_dc
class Assignment(Statement):
    '''Represents an assignment to a name as a statement'''
    name: expressions.atoms.DottedIdentifier | typing.Any
    val: expressions.Expression | typing.Any
#</Header

#> Package
#</Package

#> Header
#</Header
