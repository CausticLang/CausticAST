#!/bin/python3

#> Imports
import typing
from dataclasses import dataclass
from collections import abc as cabc

from . import Expression
#</Imports

#> Header >/
__all__ = ('Atom', 'Identifier', 'DottedIdentifier')

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
