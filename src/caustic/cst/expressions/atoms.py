#!/bin/python3

#> Imports
import typing
from dataclasses import dataclass, field
from collections import abc as cabc

from . import Expression
#</Imports

#> Header >/
__all__ = ('Atom',
           'Identifier', 'DottedIdentifier',
           'Integer')

_dc = dataclass(slots=True)

# Base
@_dc
class Atom(Expression):
    '''The base class for atom nodes'''

# Identifiers
@_dc
class Identifier(Atom):
    '''Represents a (non-dotted) identifier'''
    name: str | typing.Any

@_dc
class DottedIdentifier(Atom):
    '''Represents a dotted identifier'''
    names: cabc.Sequence[str] | typing.Any

# Literals
## Numerics
@_dc
class Integer(Atom):
    '''Represents an integer literal'''
    val: int | str | typing.Any
    base: int | typing.Any = field(default=10, kw_only=True)
