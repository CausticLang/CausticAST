#!/bin/python3

'''Provides functions for (de)serializing CSTs'''

#> Imports
import io
import pickle
import typing
import pickletools
from dataclasses import asdict
from collections import abc as cabc

from . import bases
#</Imports

#> Header >/
__all__ = ('node_types', 'register_nodetype',
           'CSTPickler', 'CSTUnpickler',
           'serialize', 'deserialize')

node_types = {}

def register_nodetype(nt: type['bases.CausticASTNode']) -> None:
    '''
        Registers a node for serialization and deserialization
            purposes
    '''
    node_types[nt.__name__] = nt

class CSTPickler(pickle.Pickler):
    '''Pickles a CST'''
    __slots__ = ()

    def persistent_id(self, obj: typing.Any) -> str | None:
        if isinstance(obj, type) and issubclass(obj, bases.CausticASTNode) \
                and (name := getattr(obj, '__name__', None)) in node_types:
            return name
        return None
class CSTUnpickler(pickle.Unpickler):
    '''Unpickles a CST'''
    __slots__ = ()

    def persistent_load(self, pid: str) -> type['bases.CausticASTNode']:
        return node_types[pid]

def serialize(root: 'bases.CausticASTNode') -> bytes:
    '''Serializes `root` in Pickle format, using `CSTPickler`'''
    with io.BytesIO() as bio:
        CSTPickler(bio).dump(root)
        return pickletools.optimize(bio.getvalue())
def deserialize(data: bytes) -> 'bases.CausticASTNode':
    '''Deserializes `data` into a CST'''
    with io.BytesIO(data) as bio:
        return CSTUnpickler(bio).load()
