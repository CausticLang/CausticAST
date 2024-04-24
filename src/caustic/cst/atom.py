#!/bin/python3

'''
    CST node for atoms (literals, identifiers, etc.)
    Note that atoms are considered subtypes of expressions,
        A.E. an atom is an expression
'''

#> Imports
import codecs
from dataclasses import dataclass, field
from collections import abc as cabc

from .bases import BaseAtom, BaseLiteral
#</Imports

#> Header >/
__all__ = ('Identifier', 'DottedIdentifier',
           'Integer', 'Decimal',
           'Char', 'Bytes', 'String')

_dc = dataclass(slots=True)

@_dc
class Identifier(BaseAtom):
    '''Represents an identifier'''
    name: str

@_dc
class DottedIdentifier(BaseAtom):
    '''Represents a multipart identifier'''
    names: cabc.Sequence[str]

# Literals
## Numeric
@_dc
class Integer(BaseLiteral):
    '''Represents an integer literal'''
    val: str
@_dc
class Decimal(BaseLiteral):
    '''Represents a decimal'''
    val: str
## Character
@_dc
class Char(BaseLiteral):
    '''Represents a character'''
    val: str

@_dc
class Bytes(BaseLiteral):
    '''Represents a sequence of bytes'''
    val: bytes
    raw: bool = field(default=False, kw_only=True)
@_dc
class String(BaseLiteral):
    '''Represents a string'''
    val: bytes
    raw: bool = field(default=False, kw_only=True)
