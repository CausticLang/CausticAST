#!/bin/python3

'''
    Provides functions for node serialization
        and de-serialization
'''

#> Imports
import pickle
import typing

from . import CSTNode
#</Imports

#> Header >/
__all__ = ('CSTPickler', 'CSTUnpickler')

class CSTPickler(pickle.Pickler):
    __slots__ = ()

    def persistent_id(self, obj: typing.Any) -> str | None:
        print(obj)
        if isinstance(obj, type) and issubclass(obj, CSTNode):
            return obj.node_name()
        return None

class CSTUnpickler(pickle.Unpickler):
    __slots__ = ()

    def persistent_load(self, id: str) -> type[CSTNode]:
        return CSTNode.NODE_DIRECTORY[id]
