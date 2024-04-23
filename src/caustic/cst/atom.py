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
__all__ = ('Identifier',
           'Integer', 'Decimal',
           'Char', 'Bytes', 'String')

_dc = dataclass(slots=True)

@_dc
class Identifier(BaseAtom):
    '''Represents an identifier'''
    name: str | cabc.Sequence[str]

    @property
    def is_dotted(self) -> bool:
        return not isinstance(self.name, str)

# Literals
## Numeric
@_dc
class Integer(BaseLiteral):
    '''Represents an integer literal'''
    val: int
@_dc
class Decimal(BaseLiteral):
    '''Represents a decimal'''
    val: str

    def to_float(self) -> float:
        return float(self.val)
## Character
@_dc
class Char(BaseLiteral):
    '''
        Represents a character
        `val` is automatically encoded with UTF-8
            and converted to an integer post-initialization, if it is a string
    '''
    val: int | str

    def __post_init__(self) -> None:
        if isinstance(self.val, int): return
        encd = self.val.encode('UTF-8')
        assert len(encd) == 1, f'Invalid length ({len(encd)}) for char: {self.val!r}'
        return encd[0]
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
