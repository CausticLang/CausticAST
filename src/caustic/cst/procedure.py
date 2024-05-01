#!/bin/python3

#> Imports
import typing
from dataclasses import dataclass, field
from collections import abc as cabc

from . import CSTNode
from . import block
from . import typedecl
from . import statements
from . import expressions
#</Imports

#> Header >/
__all__ = ('Param',
           'ProcedureStmt', 'ProcedureExpr',
           'Invokation')

class Param(typing.NamedTuple):
    '''
        Represents a procedure parameter
        Note: not a node
    '''
    name: expressions.atoms.Identifier | typing.Any
    type: typing.Union['typedecl.Type', None, typing.Any]
    default: expressions.Expression | None | typing.Any

@dataclass(slots=False, kw_only=True) # slots false to prevent layout conflict
class _Signature:
    # Mixin for a procedure's signature
    return_type: typing.Union['typedecl.Type', None, typing.Any]
    params: cabc.Sequence[Param] | None | typing.Any
    pos_only: int | None | typing.Any = None
    var_pos: Param | None | typing.Any = None
    kw_only: int | None | typing.Any = None
    var_kw: Param | None | typing.Any = None


@dataclass(slots=True)
class ProcedureStmt(statements.Statement, _Signature):
    '''Represents a procedure statement'''
    name: expressions.atoms.Identifier
    body: block.Block | None | typing.Any

@dataclass(slots=True)
class ProcedureExpr(expressions.Expression, _Signature):
    '''Represents a procedure expression'''
    body: block.Block | None | typing.Any

@dataclass(slots=True, kw_only=True)
class Invokation(expressions.Expression):
    '''Represents a procedure invokation'''
    target: expressions.Expression | typing.Any = field(kw_only=False)
    args: cabc.Sequence[expressions.Expression] | typing.Any = ()
    kwargs: cabc.Sequence[tuple[expressions.atoms.Identifier | None, expressions.Expression]] | typing.Any = ()
    unpack_args: cabc.Set[int] | typing.Any = frozenset()
