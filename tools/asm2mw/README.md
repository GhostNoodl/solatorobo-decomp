# asm2mw

Turns hand-written ARM code from the extracted ROM into MWCC `asm` functions that build
byte-identical, in the house style of `libs/runtime/FP_fastI_*.c`.

```sh
# print the C file for [START, END) of a module (main, itcm, dtcm, ovNNN)
python3 tools/asm2mw/asm2mw.py main 02004800 02004f7c --verify
# write it with a header comment and `#pragma force_active on`
tools/asm2mw/mkfile.sh libs/nitro/init/crt0.c "header text" main 02004800 02004f7c
```

Inputs come from the repo: bytes from `extract/<version>`, function boundaries from the module's
`symbols.txt` (every `kind:function` in the range starts a new `asm` function; `--split NAME@ADDR`
adds more), relocations from `relocs.txt`. Needs `capstone`, `pyelftools` and `pyyaml`.

How words are emitted:

* relocated data words: `dcd symbol+addend`; relocated calls: `bl symbol`;
* literal pools at the end of a function: `ldr rX, =value` (MWCC rebuilds the pool in first-use
  order); otherwise, or for `symbol+offset` values, the load stays `ldr rX, [pc, #n]` and the pool
  words are `dcd`;
* branches inside a function: `@L<addr>` labels; branches leaving it with no relocation: raw `dcd`
  with the instruction in a comment. `--add-relocs` instead adds the missing relocation to
  `relocs.txt` for *unconditional* branches to a function start (dsd delinks every
  `arm_call`/`arm_branch` as unconditional, so conditional ones must stay raw);
* zero words and anything capstone cannot decode: `dcd`.

`--verify` compiles the result with the project's MWCC flags and compares every function's
section with the ROM; functions whose pool did not come out right fall back to literal pools and
any other mismatching word becomes a `dcd`.

Things to keep in mind when carving a range out of a gap (none of these are checked by the tool,
only by a full `ninja` and `ninja report`):

* MWLD's dead-stripping does not follow relocations from `dcd` words in asm functions (it does
  follow `bl` and `ldr =`). A gap object that is only referenced through such words gets
  stripped and the link check fails; leave a function that something else references in it.
* objdiff (v3.4.0) panics on a code section without any mapping symbol, i.e. a gap that ends up
  containing only data. Every remaining gap in `.text` must keep at least one function symbol.
* `dcd` words are data to objdiff, so a function containing them scores below 100% even though
  the bytes match.

## asmblob.py

For position-independent hand-written code with tables inside it (the Mobiclip video decoder),
`asmblob.py` splits code from data with a flow analysis instead of symbols, and writes one
`asm` block per given range (`NAME:START:END:code|data`). See its docstring; `--verify` checks
the bytes, and `--labels` prints the `kind:label(arm[,data])` lines for symbols.txt.
