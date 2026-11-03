# Unmatched functions

This is the list of every code function that does not match yet, for anyone who picks one up. Matched: 8,115 of
8,216 entries in `ninja report`. The other entries are not on this list: the BIOS stubs in `_dsd_gap@main_0`
(`CpuSet`, `Div`, `Sqrt`, ...), the data gaps (`data_...`), and `__sinit_ov002_021ef1f0`.

Each function has its best clean draft in the tree. The draft sits in an `#ifdef NONMATCHING` block in the file
named below. It is either in the file whose `.text` range in `delinks.txt` ends where the function starts, or in
the file that already holds its neighbours. Round auA (the honesty audit) added 27 drafts: matches that depended
on a trick (fake parameters, `volatile` on ordinary memory, never-true pointer-bit tests, dead stores, a permuter
reference alias), demoted to their honest form. Fifteen of them were the whole `.text` of their file, so the file
keeps the draft and has no `delinks.txt` entry (it compiles to an empty object that is not linked). Their blocks
start with `Status (round auA)`. Round mtA re-matched seven of them honestly (`docs/MATCHING.md`, round mtA). The default build leaves the block out, and the function comes from the
`dsd` gap (the original bytes), so the ROM still matches. Each block starts with a `Status (round drA)` comment:
the score, the blocker and the rounds. Older notes from earlier rounds follow it. The full history is in
`docs/MATCHING.md`. Search for the address (for example `0216715c`): each function appears in many rounds, and
the column below names only the main ones.

## Scoring a draft

```sh
f=src/ov000/Lo_02166be8.cpp
{ echo "#define NONMATCHING"; cat $f; } > ${f%.cpp}_nm.cpp
python3 tools/match.py ${f%.cpp}_nm.cpp func_ov000_0216715c --module ov000
rm ${f%.cpp}_nm.cpp
```

The copy has to sit next to the original so that relative includes still resolve. Scores are counted as
`tools/match.py` counts them, with `dsi/1.3` and the project flags. "Raw" is the number of differing instruction
lines (branch targets ignored). "Masked" is the same count with every register name replaced, so a masked 0 means
only register colouring differs. Round cvA (`docs/MATCHING.md`) swept 17 compiler versions and about 60 flag and
pragma settings over every draft. None scores better than the default, so each blocker is in the source shape, not
in the compiler choice.

## Checking the drafts after a refactor

The default build leaves every `NONMATCHING` block out, so a retyped struct, a rename or a header change can break a
draft without `ninja` noticing. After such a change, run `ninja` and then `python3 tools/check_drafts.py --score`.
It compiles every file that has a `NONMATCHING` block with that file's exact `build.ninja` command (compiler version,
flags and include paths) and `NONMATCHING` defined, into a temporary directory, and prints each compile error. With
`--score` it also scores every draft function (the functions the object defines that the built object does not) the
way `tools/match.py` counts, raw and register-masked, and compares each with the table below: `WORSE` is a draft that
scores higher than its entry and `NODRAFT` an entry whose draft is missing. It exits non-zero on either, and on a
compile error. Pass files or directories to check only those. It reads the ROM from `extract/` at run time and
writes nothing to the tree. Fix a broken draft by adapting it to the current types and names, and bring it back to
its score here; if a draft gets better, update its row.

## The list

| Address | Module | Size | File | Raw / masked | Blocker | Main rounds |
|---|---|---|---|---|---|---|
| `02008a20` | main | 0x2bc | `libs/runtime/ExceptionHandler_unwind.cpp` | 38 / 38 | NextAction, clean-room rewrite (whole-file draft, no delinks entry): every instruction matches but the stack offsets; the target reserves an unused 4-byte slot at sp+0x30 between the action-15 and action-16 operands, and no plausible source shape reserves it | rwA |
| `02008cdc` | main | 0x834 | `libs/runtime/ExceptionHandler_unwind.cpp` | 463 / 460 | UnwindStack, clean-room rewrite (whole-file draft): the same unused sp+0x30 slot shifts every lower operand (most of the count), plus scheduling in the array-destroy cases and different cross-jump targets for the shared next-action stores | rwA |
| `020096e4` | main | 0x60 | `libs/runtime/ExceptionHandler_unexp.cpp` | 2 / 0 | HandleUnexpected, clean-room rewrite (whole-file draft): the target sets up r2 for UnwindStack before it saves r0; no parameter type, pragma, compiler or permuter result moves it | smallsweep1, rwA |
| `0200d36c` | main | 0x11c | `libs/nitro/card/card_rom.c` | 5 / 0 | CARDi_ReadRomWithCPU (SDK, -O2 + opt_propagation off): the read loop's word/data/ctrl get r1/r0/r2, the ROM r3/r1/r2; data is a codegen temp, so no object lever reaches it | raB, raC, raE, rgB, cvA |
| `0202b048` | main | 0x180 | `libs/nnsys/g3d/nsbca.c` | 15 / 1 | honest form of a fake-parameter match: A, B and pNd are locals again (the match declared them as trailing parameters) | auA |
| `0203a984` | main | 0x12c | `src/Main/Gfx/GfxMgr_3.cpp` | 10 / 0 | colouring of codegen temps only (the blocks[i] load and the (addr >> 5) >> shift temp); every order and type of the named locals stays at 10 | mainbig5, raC, rgB, nmA, mtA, cvA |
| `0203b4ac` | main | 0x1f4 | `src/Main/Gfx/GfxMgrText_2.cpp` | 51 / 12 | prologue colouring (canvas/w/x/h/end/nx) and the stack slots of srcStride and j; ramerge does not reproduce the graph | rtG, qpA, pmC, mlA, cvA |
| `020417e0` | main | 0x330 | `src/Main/Gfx/TexObj.cpp` | 38 / 31 | the NULL arm's zero is hoisted to the entry (move-constant-loads step 34 -> 5, block 5 pressure 6 vs 11) and SetData's data is numbered above Upload's size | mcA, hzS, hzT, qpE, nmA, cvA |
| `02043100` | main | 0x3e0 | `src/Main/Gfx/Gfx3D.cpp` | 105 / 62 | the ROM loads attr01 three times (needs a join between the shape read and the x read); colouring of the rest | frD, qpE, pmC, bgQ2, mlA, cvA |
| `02048e74` | main | 0x214 | `src/Main/Save/PlayTime.cpp` | 60 / 20 | the schedule of the second and third borrows (ROM movlo/movhs pair in the register of a->millis) | qpE, pmC, bgQ2, mlA, cvA |
| `02049690` | main | 0x1cc | `src/Main/Snd/SndMgr_LoadStep.cpp` | 10 / 0 | honest form of a fake-parameter match: seq is a local (the match declared it as a second parameter and renamed the header prototype) | auA |
| `02049c80` | main | 0x168 | `src/Main/Snd/SndMgr_4.cpp` | 60 / 42 | extended-block shape of the -1 returns: the slot-fail block must lie outside the zero's extended block, and no if/inline form gives both returns | bgW, svA, swA, cvA |
| `02053254` | main | 0x270 | `src/Main/Gfx/SceneDraw.cpp` | 37 / 4 | a cmp/add class tie in the tail and o's colour (r6 in the ROM) | qpE, qpF, bgQ2, nmA, cvA |
| `02069b3c` | main | 0x2c8 | `src/Main/Effect/Effect_10.cpp` | 44 / 4 | the param + key sum of the inlined Effect_GetTexImageParam (a codegen temp) is coloured and scheduled differently | mainfresh4, fresh6, mainJ, rgB, cvA |
| `0206d43c` | main | 0xa0 | `src/Main/Save/GameSave.cpp` | 12 / 0 | register-only: the card pointer and the first sum swap registers; every wrong node is a backend temp | qpB, raC, raE, rgB, nmA, cvA |
| `0206d99c` | main | 0x12c | `src/Main/Save/GameSave_2.cpp` | 19 / 0 | register-only: the first product and the card pointer swap registers; every wrong node is a backend temp | qpB, raC, rgB, cvA |
| `0214dd3c` | ov000 | 0x2cc | `src/ov000/Misc_0214dcc4.cpp` | 26 / 0 | register-only: the first walk's p and the new node lose r6; no declaration order or Insert inline moves it | tmA, raE, rgB, nmA, mtA, cvA |
| `021512b4` | ov000 | 0x2d8 | `src/ov000/Lo_0215123c.cpp` | 23 / 0 | register-only: the -0x191a depth constant swaps with bx (bx lives across the virtual calls, so it stays an object) | smW, qpH, raC, raE, mtA, cvA |
| `0215e6f0` | ov000 | 0x1c0 | `src/ov000/Model_0215e8b0.cpp` | 11 / 0 | register-only: the 0xfe00ffff x mask and the shifted x (backend vregs) swap sl/lr; the 9 / 0 drafts need a no-op cast | qpH, raC, raE, rgB, cvA |
| `02160534` | ov000 | 0x4b8 | `src/ov000/ov000_02160534.cpp` | 256 / 248 | honest form of a fake-parameter match: y, x and pid are locals and the signature is the slot's five parameters | auA |
| `021652e4` | ov000 | 0x604 | `src/ov000/Model_02164a94.cpp` | 81 / 36 | the col loop's tbl[ry * 3 + rx] reload placement and the sx/sy block's schedule (the cxxperm 91 / 46 drafts need seven fake parameters) | frC, bgN, bgZ, bgQ2, mlA, cvA |
| `02166180` | ov000 | 0xa68 | `src/ov000/Lo_02165f94.cpp` | 27 / 0 | register-only: oams and the j value swap (the j value is an IRO temp, numbered below every user variable) | dgB, bgL, bgN, raB, raF, mtA, cvA |
| `0216715c` | ov000 | 0x490 | `src/ov000/Lo_02166be8.cpp` | 3 / 0 | register-only: the outer sine (a codegen temp) is r1, the ROM r6 (a coalesce with f_0 or j, not a numbering) | bgS, bgU, raF, rgB, mtA, cvA |
| `0216c310` | ov000 | 0x3ec | `src/ov000/Lo_0216bf30.cpp` | 65 / 22 | colouring order (the ROM pops y between next and self) plus the post-allocation CSE movne r0, ip; the 65 / 10 drafts need fake parameters | mcA, hzS, qpG, pmA, nmA, mtA, cvA |
| `0218867c` | ov000 | 0x524 | `src/ov000/Lo_021814dc.cpp` | 45 / 32 | case 1 hoists data_02fe1534 to the case head (move-constant-loads 17 -> 12, refused in the ROM) and the entry order of arg / 0x64 | rtF, qpG, raF, raH, mlA, cvA |
| `021afaf8` | ov000 | 0x8d0 | `src/ov000/Robo_021afaf8.cpp` | 44 / 0 | honest form of a fake-parameter match: anm and def are locals (the match declared them as parameters and set them to NULL) | auA |
| `021b70c0` | ov000 | 0x520 | `src/ov000/Mdl_021b70c0.cpp` | 21 / 0 | honest form of a fake-parameter match: tex is a local (the match declared it as a seventh parameter; callers pass six). Round mtA: tex in the anm block (25 to 21); mdl and tex still swap r7/r8 | auA, mtA |
| `021b9b14` | ov000 | 0x824 | `src/ov000/Stub_021b9a84.cpp` | 12 / 4 | colouring of the two bit-field stores' temporaries in section 4 (the ROM's and before the word load needs another dependence graph) | lfA, pmB, bgY, mlA, mtA, cvA |
| `021c194c` | ov000 | 0x52c | `src/ov000/ov000_021c194c.cpp` | 14 / 5 | honest form of a fake-parameter match: flag and p are locals (the match declared them as two trailing parameters) | auA |
| `021c7038` | ov000 | 0x3d4 | `src/ov000/Gauge_021c7038.cpp` | 211 / 193 | honest form of a fake-parameter match: h, w, i, step and alpha are locals, the signature is the slot's five parameters (round ovhimid6 put them in parameters) | auA |
| `021dd9dc` | ov002 | 0x2e0 | `src/ov002/ov002_021dd9dc.cpp` | 67 / 1 | honest form of a fake-parameter match: w is a local (the match declared it as a second parameter so it numbers below the temps) | auA |
| `021ddf18` | ov002 | 0x62c | `src/ov002/ov002_021ddf18.cpp` | 127 / 0 | honest form of a fake-parameter match: h and cam are locals (round jkE: the registers rotate) | auA |
| `021df2ec` | ov002 | 0x4c8 | `src/ov002/ov002_021df2ec.cpp` | 114 / 1 | honest form of a fake-parameter match: y, x, id and w are locals | auA |
| `021e0ff8` | ov002 | 0x150 | `src/ov002/ov002_021e0e78.cpp` | 2 / 2 | honest form of a pointer-bit match: the never-true `if ((u32)self & 3)` block is removed | auA |
| `021eca14` | ov002 | 0x17c | `src/ov002/ov002_021ec6a8.cpp` | 6 / 3 | return TRUE's mov r0, #1 is scheduled into the ldrh stall; the ROM has return TRUE in a block of its own | bgV, bgX, rgB, mtA, cvA |
| `021cd91c` | ov003 | 0x98c | `src/ov003/ov003_021cd744.cpp` | 44 / 35 | case 10's alpha register and state/timer stores, and pressure-mode picks in Ov003Cd_Color's 64-bit products (7 lines are Thumb bl/blx, link-time only) | pmB, bgW, bgY, bgQ2, mlA, cvA |
| `021ddce4` | ov003 | 0x64 | `src/ov003/ov003_021ddcb0.c` | 14 / 14 | honest form of a pointer-bit match: the never-true `if ((u32)self & 3)` block is removed | auA |
| `021eb818` | ov003 | 0x23c | `src/ov003/ov003_021eba54.cpp` | 11 / 11 | honest form of a pointer-bit match: the never-true `if ((u32)self & 3)` block is removed | auA |
| `021db258` | ov006 | 0x404 | `src/ov006/ov006_021db258.cpp` | 34 / 0 | honest form of a permuter match: slot->aid is written through slot (the match used a C++ reference alias `slotRef`) | auA |
| `021e7004` | ov006 | 0x38c | `src/ov006/ov006_021e6eb0.cpp` | 22 / 13 | the ROM issues the dz smull before the t->x load and builds hy + curYaw before hp + curPitch (the 20-21 drafts start with a junk store) | rtG, pmB, qpL, nmA, cvA |
| `021e9f80` | ov006 | 0x2c4 | `src/ov006/ov006_021e9f80.cpp` | 2 / 2 | honest form of a pointer-bit match: the sqrt busy mask is the constant 0x8000 (the match set it again under `if ((u32)self & 3)`) | auA |
| `02204a10` | ov009 | 0xa80 | `src/ov009/ov009_022161f8.cpp` | 295 / 283 | the hoisted self + 0x10c base is kept in fp, the ROM spills it (every stack offset from 0x10 up is 4 low); the 57-67 drafts need a volatile base pointer | qpD, qpG, qpL, svB, cvA |
| `02206084` | ov009 | 0x2ec | `src/ov009/ov009_02205d14.cpp` | 7 / 7 | the ROM reads pl->id before the unk_93 bit-field store; the strh/strb pair has no memory edge, so list order decides and no honest source flips it | near7, bgV, nmA, mtA, cvA |
| `0220a128` | ov009 | 0x438 | `src/ov009/ov009_0220a028.cpp` | 12 / 0 | honest form of a fake-parameter match: st is a local (the match declared it as a trailing u8 parameter) | auA |
| `0220acb8` | ov009 | 0x194 | `src/ov009/ov009_0220ac74.cpp` | 15 / 13 | the ROM computes y + 0x1333 before the unk_f0 load and colours the stack-argument constants 0x64/0x1000 ip/r3 (ours r3/r1) | qpC, nmA, mtA, cvA |
| `02204030` | ov010 | 0x1d4 | `src/ov010/ov010_02203ff4.cpp` | 26 / 23 | pressure-mode allocation of the loop's LICM'd preheader values; 2 lines are bl vs the ROM's blx to Thumb MTX_RotY33_ (link-time only) | qpA, pmA, nmA, mtA, cvA |
| `021fb9b8` | ov011 | 0x450 | `src/ov011/ov011_021fb66c.cpp` | 38 / 0 | honest form of a fake-parameter match: owner is a local (the match declared it as a second parameter) | auA |
| `021fc0b8` | ov011 | 0x894 | `src/ov011/ov011_021fc0a0.cpp` | 26 / 17 | one move-constant-loads step: the list-removal zero is hoisted past the n != NULL guard (refusing it under gdb gives 0 / 0) | hzR, hzZ, raG, hzA, svC, cvA |
| `021fd638` | ov011 | 0x4a4 | `src/ov011/ov011_021fd4a4.cpp` | 56 / 34 | the Ov011Ent_Remove zero is hoisted to the entry (move-constant-loads 82 -> 9), plus the ring loop's Ov011_FxMul temps and ang colouring | bigM, hzR, cvZ, raF, hzA, svC, cvA |
| `021ff24c` | ov011 | 0x630 | `src/ov011/ov011_021ff8fc.cpp` | 26 / 0 | register colouring of the ring loop only (head, p and pos share r3 in the ROM) | qpJ, raD, raF, svC, mtA, cvA |
| `021fb1b4` | ov013 | 0xb6c | `src/ov013/ov013_021fb1b4.cpp` | 642 / 601 | honest form of a fake-parameter match: pos, prev and cur are locals (the match declared them as parameters) | auA |
| `02206764` | ov013 | 0x288 | `src/ov013/ov013_022065ac.cpp` | 22 / 0 | honest form of a fake-parameter and volatile match: b is a local and t is not volatile | auA |
| `0220ae90` | ov015 | 0x13c | `src/ov015/ov015_0220ab84.cpp` | 5 / 0 | honest form of a pointer-bit match: the never-true `if ((u32)self & 3)` block is removed | auA |

## Lower-scoring drafts that are not clean

Older drafts score lower on some of these functions. Each of them depends on something the project does not
accept as a match, so none of them is the in-tree draft:

- `02204a10`: 57-67 raw (round giantsB), but only with `Ov009Vec *volatile arr` as the trail base. Without the
  `volatile` the draft is 297-300.
- `021512b4` 11 / 0, `0216c310` 65 / 10, `02053254` 36 / 10, `021652e4` 91-105: permuter output with fake
  trailing parameters, one-element arrays and `__typeof__` temporaries.
- `0215e6f0` 9 / 0: the in-tree draft plus a no-op `(int)` cast on one argument.
- `021e7004` 20-21: these start with a junk `kq = 1; if ((u32)self & 3) kq = 1;` store.
- Every `auA` row: the trick form matched exactly (0 / 0). It is in the git history before round auA, and the
  `Status (round auA)` comment of each block names the trick.

Earlier rounds (`honL`, `rtF`, `rtG`, `bgG` and others) rebuilt the clean bases for these. The in-tree drafts
are those bases, or later improvements of them.

## Rules for a match

A match has to be source that someone could have written. No `volatile` on ordinary memory (hardware registers
such as `0x40002b0` are fine), no fake or reused parameters, no junk locals, arrays or struct views, no
out-of-bounds views, no dead assignments, no empty branches, no hand-rotated loops, no inline `asm` and no
permuter temporaries. `python3 tools/honesty_scan.py` finds these patterns in the tree (see `docs/MATCHING.md`,
round auA, for the categories and the triage of every hit). Many blockers above are known exactly: one move-constant-loads step, one register coalesce,
or one temp's number. Under gdb the compiler can be forced to produce the ROM's code (rounds hzR, hzS, qpG). A
match still needs a source form that gives that code honestly.
