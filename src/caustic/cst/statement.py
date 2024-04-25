#!/bin/python3

'''CST nodes for statements'''

#> Imports
import typing
from dataclasses import dataclass, field
from collections import abc as cabc

from .bases import CausticASTNode, BaseStatement
from .block import Block, Line
#</Imports

#> Header >/
__all__ = ('ProcedureStatement',
           'ImportStatement', 'ExportStatement',
           'IfStatement', 'ElifStatement', 'ElseStatement',
           'ForStatement', 'WhileStatement',
           'Directive')

_dc = dataclass(slots=True)

@_dc
class ProcedureStatement(BaseStatement):
    '''
        Represents a named procedure declaration statement

        All parameters are represented as a tuple of `name`, `type`,
            and `params` is a sequence of parameters
    '''
    name: CausticASTNode
    return_type: CausticASTNode | None
    params: cabc.Sequence[tuple[CausticASTNode, CausticASTNode]] | None = None
    pos_only: int | None = field(default=None, kw_only=True)
    kw_only: int | None = field(default=None, kw_only=True)
    var_pos: tuple[CausticASTNode, CausticASTNode] | None = field(default=None, kw_only=True)
    var_kw: tuple[CausticASTNode, CausticASTNode] | None = field(default=None, kw_only=True)
    body: Block | None = field(default=None, kw_only=True)

# External-related
@_dc
class ImportStatement(BaseStatement):
    '''Represents an import'''
    target: CausticASTNode
    i_from: CausticASTNode | None = field(default=None, kw_only=True)
    i_as:   CausticASTNode | None = field(default=None, kw_only=True)
@_dc
class ExportStatement(BaseStatement):
    '''Represents an export'''
    target: CausticASTNode
    e_as: str | None = field(default=None, kw_only=True)
    extern: bool = field(default=False, kw_only=True)

# Conditional-related
@_dc
class IfStatement(BaseStatement):
    '''Represents an if statement'''
    condition: CausticASTNode
    block: Block
    next: typing.Union['ElifStatement', 'ElseStatement'] | None = None
class ElifStatement(IfStatement):
    '''Represents an else-if statement'''
    __slots__ = ()
@_dc
class ElseStatement(BaseStatement):
    '''Represents an else statement'''
    block: Block

# Loop-related
@_dc
class ForStatement(BaseStatement):
    '''Represents a for loop'''
    clause: tuple[Line, Line, Line] | CausticASTNode
    block: Block
    for_in: bool = field(default=False, kw_only=True)
@_dc
class WhileStatement(BaseStatement):
    '''Represents a while loop'''
    clause: CausticASTNode
    block: Block
    do_while: bool = field(default=False, kw_only=True)

# Directive
class Directive(BaseStatement):
    '''Represents a compiler directive'''
    name: str
    args: cabc.Sequence[typing.Any]
