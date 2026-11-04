# Labelled fakematches (round fkA, experimental)

This is an experiment the owner is considering, kept on a side branch. It lists every function that the default
build matches only through a trick that `docs/UNMATCHED.md` ("Rules for a match") does not accept: fake parameters,
`volatile` on ordinary memory, never-true pointer-bit tests, permuter aliases and the like. Other decomps (SM64,
OoT) accept a few such "fakematches" when each one is clearly labelled. Here each one is:

- **labelled at the trick** with a `// FAKEMATCH: <what the trick is and why>` comment;
- **kept beside its honest draft**. The function is one `#ifdef NONMATCHING` / `#else` / `#endif` block: the
  `NONMATCHING` branch is the honest draft (its `Status` comments and history unchanged), and the `#else` branch is
  the fakematch, which the default build compiles. The `#else` branch starts with the line
  `// Round fkA fakematch (docs/FAKEMATCHES.md). The honest draft is the NONMATCHING branch above.`
  A trick that needs a declaration outside the function (a prototype with the fake parameters, a header
  prototype renamed out of the way) has its own `#ifdef NONMATCHING` / `#else` pair with a `FAKEMATCH:` comment;
- **linked**: its `delinks.txt` range or entry is back as it was before round auA cut it (the way round mtA restored
  its matches), so `ninja report` counts it;
- **listed in the table below**, which the tools read.

To drop the experiment, revert the round fkA commit: the `#else` branches, this file, the `delinks.txt` lines and
the tool changes go away together, and the honest drafts stay as they are.

## Tools

- `python3 tools/honesty_scan.py` reads the table. A hit is a *fakematch hit* (hidden, counted separately, not a
  failure) only when its file and function are a row, its category is in the row's "Scan categories" (`comment` is
  always accepted, since the label says "fake"), and the function carries a `FAKEMATCH:` comment. Every other trick
  still fails. `--fake` shows the fakematch hits, `--summary` counts them per category, and the run prints
  `fakematch: N labelled hits in M functions` on stderr. Category `fakelist` (a failure) reports a `FAKEMATCH:`
  comment in a function that is not in the table, and a row whose function has no `FAKEMATCH:` comment.
- `python3 tools/check_drafts.py --score` scores each row's honest draft (compiled with `NONMATCHING`) against the
  "Honest draft" column, the same way it scores `docs/UNMATCHED.md` rows, so a refactor that breaks or worsens one
  still shows up as `WORSE`.
- A build with `NONMATCHING` defined compiles the honest drafts. It does not link to a matching ROM, since these
  functions have `delinks.txt` ranges again; that is the same as for every other `NONMATCHING` draft before it is
  cut out.

## The list

20 functions. Tricks (a function can use two): fake parameter 14, pointer-bit test 5, permuter alias 1, volatile 1.

| Address | Module | Function | File | Scan categories | Honest draft raw / masked | Trick | What it does |
|---|---|---|---|---|---|---|---|
| `0202b048` | main | `getMdlRot_` | `libs/nnsys/g3d/nsbca.c` | paramlocal, unusedparam, arity | 15 / 1 | fake parameter | the SDK locals `A`, `B` and `pNd` are trailing parameters (callers pass only `pResult`), and `pNd` is set through a non-const temporary |
| `02049690` | main | `SndMgr_UpdateLoad` | `src/Main/Snd/SndMgr_LoadStep.cpp` | paramlocal, unusedparam, arity | 10 / 0 | fake parameter | `seq` is a second parameter (callers pass only `mgr`); the header prototype is renamed out of the way with a `#define` around the include |
| `02160534` | ov000 | `Ov000Vt_021cac0c_DrawFrame` | `src/ov000/ov000_02160534.cpp` | paramlocal, unusedparam, arity | 256 / 248 | fake parameter | `y` and `x` are parameters past the slot's five, and the slot's second parameter is reused as the `pid` local |
| `021afaf8` | ov000 | `Robo021ca458_State1f` | `src/ov000/Robo_021afaf8.cpp` | paramlocal, unusedparam, arity | 44 / 0 | fake parameter | `anm` and `def` are parameters set to NULL in the body (the dispatcher passes only `self`) |
| `021b70c0` | ov000 | `func_ov000_021b70c0` | `src/ov000/Mdl_021b70c0.cpp` | paramlocal, unusedparam, arity | 21 / 0 | fake parameter | `tex` is a seventh parameter (callers pass six) |
| `021c194c` | ov000 | `func_ov000_021c194c` | `src/ov000/ov000_021c194c.cpp` | paramlocal, unusedparam, arity | 14 / 5 | fake parameter | `p` is a trailing parameter (auA's second one, `flag`, is not needed) |
| `021c7038` | ov000 | `Ov000Vt_021cca88_DrawFrame` | `src/ov000/Gauge_021c7038.cpp` | paramlocal, unusedparam, arity | 211 / 193 | fake parameter | `w`, `i` and `step` are parameters past the slot's five, the unused fourth parameter is reused as `h` and the second as `alpha` |
| `021dd9dc` | ov002 | `func_ov002_021dd9dc` | `src/ov002/ov002_021dd9dc.cpp` | paramlocal, unusedparam, arity | 67 / 1 | fake parameter | `w` is a second parameter (the dispatcher passes only `self`) |
| `021ddf18` | ov002 | `Obj021efef0_Enter` | `src/ov002/ov002_021ddf18.cpp` | paramlocal, unusedparam, arity | 127 / 0 | fake parameter | `h` and `cam` are trailing parameters (the dispatcher passes two) |
| `021df2ec` | ov002 | `Obj021eff30_Enter` | `src/ov002/ov002_021df2ec.cpp` | paramlocal, unusedparam, arity | 114 / 1 | fake parameter | `y`, `x`, `id` and `w` are trailing parameters (the dispatcher passes two) |
| `021e0ff8` | ov002 | `Ov002HudInfo_Draw` | `src/ov002/ov002_021e0e78.cpp` | ptrbit, deadstore | 2 / 2 | pointer-bit test | `if ((u32)self & 3) { i = 0; }` (never true) keeps `i = 0` after the `by` add |
| `021ddce4` | ov003 | `Ov003ActVt_021f7e7c_Start` | `src/ov003/ov003_021ddcb0.c` | ptrbit, deadstore | 14 / 14 | pointer-bit test | `if ((u32)self & 3) { p = self->unk_44; }` keeps the arms' `ldrh; bic` in each arm |
| `021eb818` | ov003 | `Ov003ActExSway_StateDie` | `src/ov003/ov003_021eba54.cpp` | ptrbit, deadstore | 11 / 11 | pointer-bit test | `if ((u32)self & 3) { sfxOn = 1; }` stops `sfxOn`'s copy propagation |
| `021db258` | ov006 | `ov006_UpdateNetSlots` | `src/ov006/ov006_021db258.cpp` | noise | 34 / 0 | permuter alias | `slot->aid` is written through a C++ reference `slotRef` to `slot` |
| `021e9f80` | ov006 | `Ov006Racer_UpdateCheckpoint` | `src/ov006/ov006_021e9f80.cpp` | ptrbit, deadstore | 2 / 2 | pointer-bit test | the sqrt busy mask is a local set to `0x8000` twice, the second time under `if ((u32)self & 3)` |
| `0220a128` | ov009 | `Ov009ActVt_02217390_Update` | `src/ov009/ov009_0220a028.cpp` | paramlocal, unusedparam, arity | 12 / 0 | fake parameter | `st` is a trailing `u8` parameter (the dispatcher passes only `self`) |
| `021fb9b8` | ov011 | `Ov011Mgr2_State02` | `src/ov011/ov011_021fb66c.cpp` | paramlocal, unusedparam, arity | 38 / 0 | fake parameter | `owner` is a second parameter (callers pass only `self`) |
| `021fb1b4` | ov013 | `Ov013Boss_StateAttack2` | `src/ov013/ov013_021fb1b4.cpp` | paramlocal, unusedparam, arity | 642 / 601 | fake parameter | `prev` and `cur` are trailing parameters (auA's third one, `pos`, is not needed) |
| `02206764` | ov013 | `Ov013ActVt_0220bdd8_Update` | `src/ov013/ov013_022065ac.cpp` | paramlocal, unusedparam, arity, volatile | 22 / 0 | fake parameter, volatile | `b` is a second parameter, and the pointer local `t` is `volatile` (the `t->pos` load order); both are needed |
| `0220ae90` | ov015 | `func_ov015_0220ae90` | `src/ov015/ov015_0220ab84.cpp` | ptrbit, deadstore | 5 / 0 | pointer-bit test | `if ((u32)self & 3) { dec = p->info.unk_20; }` swaps `acc` and `st` into `lr`/`r4` |
