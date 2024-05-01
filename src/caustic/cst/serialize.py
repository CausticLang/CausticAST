#!/bin/python3

'''
    Provides functions for node serialization
        and de-serialization
'''

#> Imports
import io
import pickle
import typing
import pickletools

from . import CSTNode
#</Imports

#> Header >/
__all__ = ('CSTPickler', 'CSTUnpickler',
           'serialize', 'deserialize', 'serialize_to', 'deserialize_from')

class CSTPickler(pickle.Pickler):
    __slots__ = ()

    def persistent_id(self, obj: typing.Any) -> str | None:
        if isinstance(obj, type) and issubclass(obj, CSTNode):
            return obj.node_name()
        return None

class CSTUnpickler(pickle.Unpickler):
    __slots__ = ()

    def persistent_load(self, id: str) -> type[CSTNode]:
        return CSTNode.NODE_DIRECTORY[id]


def serialize(cst: CSTNode, *, optimize: bool = True) -> bytes:
    '''Serializes a CST to bytes'''
    with io.BytesIO() as stream:
        serialize_to(cst, stream)
        return (pickletools.optimize(stream.getvalue())
                if optimize else stream.getvalue())
def serialize_to(cst: CSTNode, stream: typing.BinaryIO) -> None:
    '''Serializes a CST to bytes into a stream'''
    CSTPickler(stream).dump(cst)
def deserialize(data: bytes) -> CSTNode:
    '''Deserializes a previously serialized CST'''
    with io.BytesIO(data) as stream:
        return deserialize_from(stream)
def deserialize_from(stream: typing.BinaryIO) -> CSTNode:
    '''Deserializes a previously serialized CST from a stream'''
    return CSTUnpickler(stream).load()
