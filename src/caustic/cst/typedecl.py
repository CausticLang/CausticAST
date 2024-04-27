#!/bin/python3

'''
    CST nodes for type declarations (classes, structs, singletons, etc.)
    Note that type declarations are considered subtypes of statements,
        A.E. a type declaration is a statement
'''

#> Imports
from dataclasses import dataclass, field
from collections import abc as cabc

from .bases import CausticASTNode, BaseExpression, BaseTypeDecl
from .atom import Identifier, DottedIdentifier
from .statement import ProcedureStatement
#</Imports

#> Header >/
__all__ = ('SingletonType', 'EnumType', 'StructType', 'ClassType')

_dc = dataclass(slots=True)

@_dc
class SingletonType(BaseTypeDecl):
    '''Represents a singleton'''
    val: BaseExpression | None = None

@_dc
class EnumType(BaseTypeDecl):
    '''Represents an enum'''
    members: cabc.Sequence[tuple[Identifier, BaseExpression | None]]
    type: DottedIdentifier | None = field(default=None, kw_only=True)

@_dc
class StructType(BaseTypeDecl):
    '''Represents a struct, A.E. a container of values'''
    members: cabc.Sequence[tuple[Identifier, DottedIdentifier, CausticASTNode | None]]
    base: DottedIdentifier | None = field(default=None, kw_only=True)

@_dc
class ClassType(StructType):
    '''Represents a class, A.E. a struct type with methods'''
    methods: cabc.Sequence[tuple[Identifier, ProcedureStatement]]
    base: DottedIdentifier | None = field(default=None, kw_only=True)
