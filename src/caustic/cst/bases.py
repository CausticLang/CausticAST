#!/bin/python3

'''Base nodes, should not be invoked directly'''

#> Imports
#</Imports

#> Header >/
__all__ = ('CausticASTNode',
           'BaseStatement',
           'BaseExpression', 'BaseAtom', 'BaseLiteral')

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

## Atoms
class BaseAtom(BaseExpression):
    '''The base class for all atom CST nodes'''
    __slots__ = ()
class BaseLiteral(BaseAtom):
    '''The base class for all literal CST nodes'''
    __slots__ = ()
