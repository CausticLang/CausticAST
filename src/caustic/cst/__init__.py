#!/bin/python3

'''Caustic (Abstract) Syntax Tree'''

#> Imports
import typing
import collections
from dataclasses import dataclass
try: import parglare
except ModuleNotFoundError:
    parglare = None
#</Imports

#> Package >/
__all__ = ('SourceInfo',)

class SourceInfo(collections.namedtuple('SourceInfo', (
        'source', 'input_str', 'start_pos', 'end_pos',
        'start_line', 'start_col', 'end_line', 'end_col',
        'metadata'))):

    def __new__(cls, source: int | None, input_str: str | None = None, start_pos: int | None = None, end_pos: int | None = None,
                start_line: int | None = None, start_col: int | None = None, end_line: int | None = None, end_col: int | None = None,
                metadata: typing.Any | None = None, *, parglare_auto_lcno: bool = True):
        if (parglare is not None) and (input_str is not None):
            if (start_pos is not None) and ((start_line is None) or (start_col is None)):
                start = parglare.pos_to_line_col(input_str, start_pos)
                if start_line is None: start_line = start[0]
                if start_col is None: start_col = start[1]
            if (end_pos is not None) and ((end_line is None) or (end_col is None)):
                end = parglare.pos_to_line_col(input_str, start_pos)
                if end_line is None: end_line = end[0]
                if end_col is None: end_col = end[1]
        return super().__new__(cls, source=source, input_str=input_str, start_pos=start_pos, end_pos=end_pos,
                               start_line=start_line, start_col=start_col, end_line=end_line, end_col=end_col,
                               metadata=metadata)

    @classmethod
    def from_parglare_ctx(cls, ctx: typing.Any):
        return cls(file_name=ctx.file_name, input_str=ctx.input_str, start_pos=ctx.start_position, end_pos=ctx.end_position, metadata=ctx)

    def str_pos(self) -> str:
        return (f'P{self.start_pos}{"" if self.end_pos is None else f"-{self.end_pos}"}'
                if self.start_line is None else
                (f'L{self.start_line}{"" if self.start_col is None else f"C{self.start_col}"}'
                 f'{"" if self.end_line is None else f"""-L{self.end_line}{"" if self.end_col is None else f"C{self.end_col}"}"""}'))

    def __str__(self) -> str:
        return f'{self.source or "<unknown>"}@{"<unknown position>" if (self.start_pos is None) and (self.start_line is None) else self.str_pos()}'
