#!/bin/python3

'''Caustic (Abstract) Syntax Tree'''

#> Imports
import typing
from dataclasses import dataclass
try: import parglare
except ModuleNotFoundError:
    parglare = None
#</Imports

__all__ = ('SourceInfo', 'CSTNode', 'CustomNode',
           'expressions')

#> Header
class SourceInfo(typing.NamedTuple):

    source: str | None
    start_pos: int | None = None
    end_pos: int | None = None
    start_line: int | None = None
    start_col: int | None = None
    end_line: int | None = None
    end_col: int | None = None

    @classmethod
    def from_parglare_ctx(cls, ctx: typing.Any, **kwargs):
        if parglare is not None:
            start = parglare.pos_to_line_col(ctx.input_str, ctx.start_position)
            end = parglare.pos_to_line_col(ctx.input_str, ctx.end_position)
            kwargs.update(start_line=start[0], start_col=start[1],
                          end_line=end[0], end_col=end[1])
        return cls(source=ctx.file_name, start_pos=ctx.start_position, end_pos=ctx.end_position, **kwargs)

    def str_pos(self) -> str:
        return (f'P{self.start_pos}{"" if self.end_pos is None else f"-{self.end_pos}"}'
                if self.start_line is None else
                (f'L{self.start_line}{"" if self.start_col is None else f"C{self.start_col}"}'
                 f'{"" if self.end_line is None else f"""-L{self.end_line}{"" if self.end_col is None else f"C{self.end_col}"}"""}'))

    def __str__(self) -> str:
        return f'{self.source or "<unknown>"}@{"<unknown position>" if (self.start_pos is None) and (self.start_line is None) else self.str_pos()}'

@dataclass(slots=True, kw_only=True)
class CSTNode:
    '''The base class for all CST nodes'''
    source: SourceInfo

    BASE_MODULE = __module__
    NODE_DIRECTORY: typing.ClassVar[dict[str, type[typing.Self]]] = {}

    def __init_subclass__(cls):
        cls.register_node(cls)

    @classmethod
    def node_name(cls) -> str:
        return f'{cls.__module__.removeprefix(f"{cls.BASE_MODULE}").strip(".")}.{cls.__name__}'

    @classmethod
    def register_node(cls, other: type) -> str:
        name = getattr(other, 'node_name', cls.node_name).__func__(other)
        cls.NODE_DIRECTORY[name] = other
        return name

@dataclass(slots=True)
class CustomNode(CSTNode):
    '''
        Provided for ease-of-use with compiler mods
            without having to define node classes
    '''
    data: typing.Any
#</Header

#> Package >/
from . import expressions
