#!/bin/python3

'''Base nodes, should not be invoked directly'''

#> Imports
from dataclasses import dataclass
#</Imports

#> Header >/
__all__ = ('CausticASTNode',
           'BaseStatement',
           'BaseExpression',
               'BaseOperator', 'BaseBinaryOperator', 'BaseUnaryOperator',
               'BaseAtom', 'BaseLiteral')

_dc = dataclass(slots=True)

class CausticASTNode:
    '''The base class for all CST nodes'''
    __slots__ = ()

class BaseStatement(CausticASTNode):
    '''The base class for all statement CST nodes'''
    __slots__ = ()

# Expressions
class BaseExpression(CausticASTNode):
    '''The base class for all expression CST nodes'''
    __slots__ = ()

class BaseOperator(BaseExpression):
    '''The base class for all operator CST nodes'''
    __slots__ = ()
@_dc
class BaseBinaryOperator(BaseOperator):
    '''The base class for all binary operator CST nodes'''
    left: CausticASTNode
    right: CausticASTNode
@_dc
class BaseUnaryOperator(BaseOperator):
    '''The base class for all unary operator CST nodes'''
    target: CausticASTNode

## Atoms
class BaseAtom(BaseExpression):
    '''The base class for all atom CST nodes'''
    __slots__ = ()
class BaseLiteral(BaseAtom):
    '''The base class for all literal CST nodes'''
    __slots__ = ()
