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
           'Declaration', 'Assignment',
           'If', 'Elif', 'Else',
           'While', 'DoWhile', 'For', 'ForOf',
           'objects')

_dc = dataclass(slots=True, kw_only=True)

#> Header
@_dc
class Statement(CSTNode):
    '''The base class for all statement nodes'''

# Declaration
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

# Conditional
@_dc
class If(Statement):
    '''Represents a conditional block'''
    condition: expressions.Expression | typing.Any
    body: CSTNode | typing.Any
@_dc
class Elif(If):
    '''Represents a conditional block that proceeds an `If`'''
@_dc
class Else(Statement):
    '''Represents the "false" condition of an `If` or `Elif`'''
    body: CSTNode | typing.Any

# Loops
@_dc
class While(Statement):
    '''Represents a while-loop'''
    condition: expressions.Expression | typing.Any
    body: CSTNode | typing.Any
@_dc
class DoWhile(While):
    '''
        Represents a while-loop that checks its condition
            after its first run
    '''
@_dc
class For(While):
    '''Represents a 3-part for-loop'''
    condition: expressions.Expression | None | typing.Any
    init: expressions.Expression | Declaration | None | typing.Any
    foreach: expressions.Expression | None | typing.Any
@_dc
class ForOf(Statement):
    '''Represents a 1(ish)-part for-loop'''
    name: Declaration | None | typing.Any
    iname: Declaration | None | typing.Any
    target: expressions.Expression | typing.Any
    body: CSTNode | typing.Any
#</Header

#> Package
from . import objects
#</Package

#> Header
#</Header
