# Permuter tools for MWCC/ARM

`cxxperm.py` is a self-contained random permuter that rewrites the source text directly, so it runs on
C++ drafts as they are (see "Permuting C++ drafts" in `docs/MATCHING.md`, or `cxxperm.py --help`):

```shell
python3 tools/permuter/cxxperm.py draft.cpp func_ov014_022153e0 --module ov014 --time 900 -j 2 --inlines
```

The rest of this directory is glue for decomp-permuter, which needs C.

## decomp-permuter

Glue for running [decomp-permuter](https://github.com/simonlindholm/decomp-permuter) on overlay
functions. The permuter only parses C, so these scripts turn a C++ draft into permuter C and
compile the permuted C back as C++ with the project's MWCC flags.

The decomp-permuter checkout itself is not included. Point `PERMUTER` at it (see `env.sh`).
Target bytes are read from `extract/` at run time; nothing here contains ROM data.

## Usage

```shell
export PERMUTER=~/decomp-permuter           # directory holding permuter.py
export PERM_WORK=/tmp/perm                  # default: build/permuter
tools/permuter/run.sh draft.cpp 021c4230 1500        # set up p_021c4230 and permute for 25 minutes
tools/permuter/rerun.sh 021c4230 1500                # continue from p_021c4230's best output, in q_021c4230
tools/permuter/pdiff.sh $PERM_WORK/q_021c4230 $PERM_WORK/q_021c4230/output-10-1/source.c
```

`PERM_MODULE` selects the overlay (default `ov000`). The draft is the function's C++ file: it
can include project headers and use `extern "C"` blocks and `obj->vfunc_XX(...)` virtual calls.

## Scripts

- `setup.sh`: preprocesses the draft as C, then `fixbrace.py` (drops `extern "C"` blocks),
  `classconv.py` (flattens simple classes into structs) and `conv.py` (rewrites
  `obj->vfunc_XX(args)` as `VC_XX(obj, args)`), and writes `target.o`, `compile.sh` and
  `settings.toml`.
- `mktarget.py`: writes a fake target object with the function's bytes and reloc offsets.
- `fakeobjdump.py`: disassembler used for scoring. `bl` targets and relocated pool words are
  masked; branch targets are compared as function-relative offsets.
- `cc.sh` / `wrap.py`: compile permuter C as C++, turning `VC_XX` calls back into virtual calls.
- `pdiff.sh`: shows the diff the scorer sees for a source file.

## Limits

The C front end can't express pointers to members, references or `new` with constructors.
For `CmdObj` code, replace the `CmdPmf` member with a two-word struct and write the
`__ptmf_null` assignment as two loads and two stores (b first, then a); that reproduces
MWCC's code for the null pointer-to-member copy. Calls that pass a derived class to
`CmdObj_Done` need an explicit `(CmdObj *)` cast in the C version, and the base class needs a
trailing `u16 pad_aa;` so derived fields stay at C++ offsets.

Permuter wins often rely on meaningless code (`if (n && n) {}`, odd temporaries). Use them
to find which change matters, then write that change as normal source.
