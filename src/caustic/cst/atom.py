#!/bin/python3

'''CST node for atoms (literals, identifiers, etc.)'''

#> Imports
from dataclasses import dataclass
from collections import abc as cabc

from .base import BaseAtom
#</Imports

#> Header >/
__slots__ = ('Identifier',)

@dataclass(slots=True)
class Identifier(BaseAtom):
    '''Represents an identifier'''
    name: str | cabc.Sequence[str]

    @property
    def is_dotted(self) -> bool:
        return not isinstance(self.name, str)
