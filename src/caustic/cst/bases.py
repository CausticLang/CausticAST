#!/bin/python3

'''Base nodes, should not be invoked directly'''

#> Imports
#</Imports

#> Header >/
__all__ = ('CausticASTNode', 'BaseAtom')

class CausticASTNode:
    '''The base class for all CST nodes'''
    __slots__ = ()

class BaseAtom(CausticASTNode):
    '''The base class for all atom CST nodes'''
    __slots__ = ()
