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
__all__ = ('ImportStatement', 'ExportStatement',
           'IfStatement', 'ElifStatement', 'ElseStatement',
           'ForStatement', 'WhileStatement',
           'RaiseStatement', 'TryStatement', 'CatchStatement', 'LowerStatement')

_dc = dataclass(slots=True)

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

# Exception-related
class RaiseStatement(BaseStatement):
    '''Represents an exception-raising statement'''
    target: CausticASTNode
class TryStatement(BaseStatement):
    '''Represents an exception-handling statement/block'''
    block: Block
    catch: 'CatchStatement' = field(kw_only=True)
class CatchStatement(BaseStatement):
    '''Represents the "catch" part of a `TryStatement`'''
    catches: cabc.Sequence[CausticASTNode]
    block: Block
class LowerStatement(BaseStatement):
    '''Represents an exception-ignoring statement/block'''
    lowers: cabc.Sequence[CausticASTNode]
    block: Block
