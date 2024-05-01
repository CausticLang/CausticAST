#!/bin/python3

#> Imports
import typing
from dataclasses import dataclass, field
from collections import abc as cabc

from . import Statement
from .. import typedecl
from .. import procedure
from .. import expressions
#</Imports

#> Header >/
__all__ = ('Object',
           'Enum', 'Struct', 'Namespace', 'Class')

_dc = dataclass(slots=True, kw_only=True)

@_dc
class Object(Statement):
    '''The base type for all object nodes'''
    name: expressions.atoms.Identifier | typing.Any = field(kw_only=False)

@_dc
class Enum(Object):
    '''Represents an enum, a group of singletons of a base type'''
    class Member(typing.NamedTuple):
        '''A member of an enum'''
        name: expressions.atoms.Identifier | typing.Any
        val: expressions.atoms.Expression | None | typing.Any = None
    members: cabc.Sequence[Member] | typing.Any
    type: typedecl.Type | None | typing.Any = None

@_dc
class Struct(Object):
    '''Represents a structure of values'''
    class Member(typing.NamedTuple):
        '''A member of a struct'''
        name: expressions.atoms.Identifier | typing.Any
        type: typedecl.Type | None | typing.Any
        default: expressions.Expression | None | typing.Any = None
    super: typedecl.Type | None | typing.Any = None
    members: cabc.Sequence[Member] | typing.Any

@_dc
class Namespace(Object):
    '''Represents a namespace that stores procedures and variables'''
    class Member(typing.NamedTuple):
        '''A member of a namespace or class'''
        name: expressions.atoms.Identifier | typing.Any
        type: typedecl.Type | None | typing.Any
        val: expressions.atoms.Expression | typing.Any
    members: cabc.Sequence[Member] | typing.Any
    procedures: cabc.Sequence[procedure.ProcedureStmt] | typing.Any

@_dc
class Class(Namespace):
    '''
        Represents an instantiable class with procedures (or methods),
            members (static valuse), and attributes
    '''
    class Attribute(typing.NamedTuple):
        '''An attribute of a class'''
        name: expressions.atoms.Identifier | typing.Any
        type: typedecl.Type | None | typing.Any
        default: expressions.Expression | None | typing.Any = None
    super: typedecl.Type | None | typing.Any = None
    attributes: cabc.Sequence[Attribute] | typing.Any
