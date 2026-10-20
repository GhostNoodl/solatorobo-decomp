# Matching functions

## Quick loop

1. Find a function in the disassembly under `build/usa/asm/` (run `ninja dis` first).
2. Write C (or C++) for it in a file under `src/`, for example `src/Main/Res/ResMgr.cpp` for game code, `libs/<lib>/...` for SDK code or `src/ov000/...` for an overlay.
3. Check it without a full build:

   ```shell
   python tools/match.py libs/nnsys/snd/snd_heap.c NNS_SndHeapCreate --address 0203053c
   python tools/match.py src/ov000/Foo.c func_ov000_0214b438 --module ov000
   ```

   Branch targets and relocated pool constants are ignored, since only the linker knows them.
4. When every function in a contiguous range matches, add the file to the module's `delinks.txt` (`config/usa/arm9/delinks.txt` for main, `config/usa/arm9/overlays/ovNNN/delinks.txt` for overlays):

   ```
   libs/nnsys/snd/snd_heap.c:
       complete
       .text       start:0x0203053c end:0x020308d4
   ```

   The range must cover whole functions, end exactly where the next function starts, and contain nothing that doesn't match.
5. Run `ninja`. It relinks everything and checks that every module and symbol still matches the base ROM.

## Tips

- Local variable declaration order changes register allocation. If only registers differ, try reordering the declarations, or move initializations out of the declarations.
- `static` functions must be marked `local` in `symbols.txt`, or `ninja` fails the symbol check.
- Call other functions and use data by their `symbols.txt` names (`func_02021d98`, `data_0208f0dc`) and declare them `extern`. Rename a symbol in `symbols.txt` once you know what it is.
- The game is C++ (overlays have static initializers), but plain functions compile the same as C. Use `extern "C"` or `.c` files to keep `symbols.txt` names unmangled.
- NitroSystem (NNS) and TwlSDK headers go in `include/nnsys/` and `include/nitro/`. Write declarations from scratch; don't copy SDK headers.

## String literals

Most of the game was built with `-str reuse,pool`: in each source file, equal string literals are one object, and all of the file's literals are packed back to back, in the order the compiled code first uses them, into one `@stringBase0` object in `.data`. The linker starts every object's `.data` on a 4-byte boundary, so a pool always starts aligned.

Write strings as real literals, not `extern char data_...[]`. MWCC treats a literal's address as a constant and may load it into a saved register early, which an `extern` array never does. If the target keeps string addresses in `r4`-`r11` across calls, only literals will match. Named arrays (`char s[] = "..."`) behave like `extern`.

1. See what the function loads, the pool it sits in, and every function that loads from that pool (`*` marks functions not in any `delinks.txt` file):

   ```shell
   python tools/strrefs.py ov006 func_ov006_021db65c
   python tools/strrefs.py ov006 --pools        # every pool in the module
   ```

2. Your file can only compile the pool if it contains every function that loads a string in it, and if the first string your file uses is the pool's first string. If not, keep `extern` for now. Often this means merging neighbouring files, since the original source file was bigger than our split. Equal strings in different pools are from different source files.
3. Write the literals. `python tools/strrefs.py ov006 --literalize src/ov006/foo.cpp` prints the file with each string symbol replaced by its literal. Prototypes need `const char *` parameters. The build defaults to `-str noreuse` (the MSL files were matched that way), so start the file with:

   ```c
   #pragma pool_strings on
   #pragma dont_reuse_strings off
   ```
4. Add the pool to the file's `delinks.txt` entry. End it at the next 4-byte boundary, since the linker pads there anyway:

   ```
   src/ov006/ov006_021db65c.cpp:
       complete
       .text       start:0x021db65c end:0x021db8c4
       .data       start:0x021ec080 end:0x021ec094
   ```

5. Rewrite `symbols.txt` and `relocs.txt` so they describe one pool object instead of separate strings:

   ```shell
   python tools/strrefs.py ov006 --claim 0x021ec080 0x021ec094
   ```

   This renames the pool's first symbol to `@stringBase0` (local, sized to the range), removes the symbols inside the pool, and turns each load of a later string into `to:<pool start> add:<offset>`.
6. Run `ninja`.

If the original file also had other `.data` next to the pool (vtables, tables of string pointers), your `.data` range has to cover and define those too.

## Duplicate literal-pool entries

Sometimes the target's literal pool holds the same symbol twice (`.word data_x` ... `.word data_x`), while MWCC merges every use of one declaration into one entry. MWCC keys pool entries by declaration, so declare the symbol a second time in a namespace and use that name for the reference that gets its own entry:

```cpp
namespace Dup { extern "C" Ov015Stat data_ov015_0221332c; }   // outside any extern "C" block

st = &Dup::data_ov015_0221332c;   // second pool entry, same symbol in the object
```

The `extern "C"` keeps the symbol name unmangled, so the relocation still points at the same symbol. A block-scope `extern` redeclaration does not work; it is merged with the file-scope one.

## Reloads the compiler would normally merge

If the target loads the same field twice where your code loads it once (for example `ldrh r0, [r2, #2]; cmp r0, #3; ... ldrh r0, [r2, #2]; add r0, r0, #1`), make the second access go through a `volatile` lvalue, such as `(*(volatile u16 *)(p + 0x6e))++` or a `volatile Foo *` local. The non-volatile accesses around it still merge as usual. To load a bitfield byte once and test two of its bits from that one copy, read it into a local with `*(volatile u8 *)` and cast the local's address to the bitfield struct.

A stack-passed parameter (the fifth argument onward) that the target reloads from `[sp, #N]` before each use can be declared `volatile` in the signature, for example `void f(..., volatile bool b2)`. This is how `func_ov003_021d85c8` matched: it passes `b2` to three inlined calls.

## Unused argument registers

If the target reuses `r1`-`r3` right before a call as if they held nothing, the callee may take fewer parameters than your prototype says. Check the callee's own disassembly to see which argument registers it actually reads.

## Fixed-point multiplies and other small patterns

- `umull` + `mla` with a constant means a 64-bit multiply by a literal: `(s32)(((s64)x * 0x29 + 0x800) >> 12)`, or an inline `FxMul(x, 0x333)` after constant propagation. If the target uses `smull` with the constant in a register, the multiplier was read back from memory: `FLD(dc) = 0x333; x = FxMul(x, FLD(dc));` (the store is forwarded, but the multiply stays signed).
- `sub r0, r2, r2` (one load used twice) comes from subtracting two different lvalues for the same address, such as `self->pos.x - FLD(s32, self, 0x70)`. The front end doesn't fold them, and CSE merges the loads later.
- Stack slots: locals get addresses in declaration order (the first declared sits highest), and locals of inline functions are placed after the caller's own locals, in expansion order. Use this to move a matrix or temp vector below the others.
- `Vec o = {0, 0, 0};` stores the zeros through the address register (`str rX, [rY]`, `[rY, #4]`, ...) rather than through `sp`-relative stores.
- To keep a data address in a callee-saved register across a call, load it into a local at the top of the function (`u8 *tmpl = data_x;`).
- If the target loads a field before an unrelated store, read it into a temp first (`s32 z = p.z; p.y += ...; use z`).
- Clearing bitfields in several fields of one sub-object without reloading the pointer: take a local pointer once (`Bits *q = self->unk_44; q->a = 0; q->b = 0;`).
- A bool built in `r1` after a call (`mov r1,#1; cmp r0,#0; moveq r1,#0`) while `r0` is returned unchanged: `BOOL r = f(); field = r ? 1 : 0; return r;`.
- Declaring extern tables `const` (`extern const char *const tbl[];`) lets the compiler schedule the load across stores, which some targets need.
- A named local tends to get a callee-saved register, while a repeated expression (merged by CSE) gets a scratch one. Try both forms when two registers are swapped. Reordering local declarations (even inserting an unused-looking `s32 i` between two others) also changes allocation, so script a permutation pass.
- Unsigned byte range check `add rX, rX, #0xff; and rX, rX, #0xff; cmp rX, #1`: `if ((u8)(x + 0xff) > 1)`.
- 12-byte `ldm`/`stm` copies: copy through a `struct { s32 w[3]; }` lvalue, e.g. `*(Blk12 *)&v = data;`.
- Copying a source struct into a local first (`Vec t = pl->pos;`) keeps its fields in registers across an inline sqrt or other long sequences.
- To get the target's argument order around a null-checked call, read the argument into a local first: `u16 id = self->ids[i]; a = mgr == NULL ? NULL : f(mgr, id);`.
- `const` changes scheduling. If the target hoists a load or reorders loads across stores where your build doesn't, try `const`: on a pointer parameter (`const Slot *self`), on an extern rodata table (`extern const Ent data_x[];`), or on an extern string (`namespace K { extern "C" const char data_x[]; }`, used as `(char *)K::data_x`). A const extern's address is loaded early, like a literal, and you don't have to claim the shared pool.

## Narrow temporaries

When the target unpacks a field into pieces in a different order (or into different registers) than your code, try giving the pieces their own narrow-typed locals, declared in the order the target computes them. MWCC schedules a `u16`/`u8` temporary differently from a value used straight in an expression or passed to an inline:

```cpp
s32 arg = self->args[i];
u16 hi = (u32)arg >> 16;   // target computes the high half first
u16 lo = arg;
Start(self, lo, hi, self->kinds[i]);
```

```cpp
u16 arg = self->unk_a6;
u16 kind = arg & 0xff;          // 'and #0xff' before 'and #0xf'
u8 mode = (arg >> 8) & 0xf;
```

A short script that writes every combination of declaration order and types and runs `tools/match.py -q` on each finds these quickly.

## `const` on source pointers

MWCC uses `const` when it orders loads and stores: a struct copy from a `const T *` loads every field before storing, while the same copy from a plain `T *` interleaves loads and stores (`ldrb; ldrb; strb; strb; ldrb; strb` for a 3-byte struct). If a copy from a parameter loads everything up front, make that parameter `const`.

## Where a bitfield store sits decides which loads are shared

MWCC reuses a field address (and sometimes the loaded halfword) only within a stretch of code with no store to that field in between. If the target reloads a bitfield word with a freshly computed address, and that reload is shared with a later inline, move the store so it sits next to the code that shares it, after any unrelated branches. For example, in `func_ov000_021b1d28` the target clears `b13` after normalising `st`, not before:

```cpp
if (st != 2 && st != 3) {
    st = 2;
}
LFLD(Bits021b1a54, self, 0xb22).b13 = 0;
SetSt(self, st);
```

## Boolean flags from conditions

If a flag computed in an `if` hoists a constant into the wrong register, write it as an expression: `on = a != 0 && b < c;` rather than `on = FALSE; if (a != 0 && b < c) on = TRUE;`.

## Casts that change register allocation or CSE

Some casts change no values but still change MWCC's output:

- **`(u32)` on a loop index used as an array subscript.** If the loop counter and a temporary in the loop body are in swapped callee-saved registers, write `p = self->arr[(u32)i];` (only on the load). This matched `func_ov000_0215cf38` and `func_ov000_021bd228`, where the body is a heap-scoped delete.
- **`(u8 *)` on a pointer that is already `u8 *`.** MWCC shares an address computation between two calls only when the two expressions have the same form. If the target recomputes `self + 0x78 + i * 0x138` for each call, but shares it in one place, cast some of the uses. `func_ov000_02161cd4` needed a specific mix, which a script that tried each combination found.
- **An unsigned zero.** `if (n > 0)` on a `u8` becomes `cmp; beq`. Comparing against a `u32 zero = 0;` local gives `cmp; bls` instead (`func_ov000_02181c4c`).
- **A `u32` counter in a list walk.** In a "find the i-th node" loop (`for (n = head; n; n = n->next) { if (k == i) break; k++; }`), declaring `k` as `u32` swaps the registers of `k` and `i` in the compare (`func_ov000_021c6b28`).
- **Load, then accumulate.** If the registers of some temporaries are swapped, try copying the fields into locals first (`s32 x = p.x; s32 y = p.y;`) and adding the offsets in later statements (`x += ...;`), instead of computing each sum in its initializer. This fixed the last register swaps in `func_ov000_021c6b28`.
- The last-declared local gets the lowest stack address; to move a buffer to `sp+0`, declare it last.
- For loop- or switch-carried constants, assign the constant before the arithmetic that uses it (`k = 3; x = a * k + b;`) to get the target's scheduling.
- To stop an `s64` constant from being folded, store it and read it back (`FLD(s64, p, 8) = 0x1000; v = FLD(s64, p, 8) * x;`).
- The extra `and rX, rX, #0xff` before `lsl #12`: take a `u32` parameter and write `(u8)n << 12`.
- Read an id into a local before an inlined find (`u16 id = self->id; e = Find(mgr, id);`), or the load moves into the loop.
- Compare operand order matters: `a->tgt != a->cur` and `a->cur != a->tgt` load and compare in different registers.
- A dummy `case X: break;` moves the pivot of the binary-tree compare sequence MWCC emits for a sparse `switch`.
- To keep argument evaluation order around a nested call, hoist the plain arguments into locals first, then put the call's result in a local declared after them: `s32 a = p->a; s32 b = p->b; s32 r = g(x); f(a, b, r);`.
- Some files were built at a lower optimization level. Signs: loops aren't rotated (a `b` to the test at the bottom), loop-invariant loads stay inside the loop, and near misses at the default level won't close. Put `#pragma optimization_level 2` at the top of the file (after a comment saying why) and re-check. Several ov006 functions (`021dc578`, `021e46e8`, `021e5050`) need it.
- The Nintendo wireless helper code (`src/Main/Net/Wh*.cpp`, NitroSDK's `wh.c`) was built at `#pragma optimization_level 2`: at O4 a scan loop's exit came out as `beq top` instead of the target's `bne exit; b top` (`func_020460d0`). Two `Wh.cpp` functions (`02045674`, `0204587c`) still need O4, so the pragma goes on a whole file only after checking the file's other functions.
- A struct or array local that's stored to the stack but never read back comes from an aggregate initializer of non-constant values, e.g. `Rgb c = {r, g, b}; game->next = c;` in an inline. If any initializer is a constant, MWCC loads it from a rodata template instead. Plain field assignments get optimized away.
- Byte-by-byte copies that load two bytes before storing them (`ldrb r2; ldrb r1; strb r2; strb r1`) are a struct assignment of a small `u8 c[3]` struct, not field-by-field copies.
- A shift of a `u16` table value done as `lsr` rather than `asr` is `/ 2` on an `int` (the compiler knows it's non-negative). `>> 1` gives `asr`.
- An integer local the target allocates later than you do (a higher callee-saved register) may be unsigned in the original (`u32 x = v.x & ~0xfff;`).
- If two parallel computations (x then y) come out with the registers and loads swapped, the original may finish one before starting the other: `dx = ...; x = ...; self->x = x; dy = ...; y = ...; self->y = y;` instead of computing both and then storing both.
- `#pragma optimization_level 3` also exists in some ov002 files. If a near miss won't close at O4 or O2, try O3 together with different declaration orders of the locals; `func_ov002_021dcf00` needed both (with initializers moved to plain assignments).
- An extra `{ }` block around locals changes scheduling. If a draft wraps its locals in an inner block, try declaring them at function level instead (`func_ov002_021e8cc4`).
- If a register swap involves an inline's parameter or a block-scoped local, expand the inline by hand and declare the variable at function level; its declaration position relative to the other locals then picks the register (`func_ov006_021e0480`, and `info` before `id` in the ov006 `021d4118` draft).
- Nesting about four inlines deep makes MWCC emit a `bl` to the innermost one instead of inlining it. Flatten the helpers if a call shows up that the target doesn't have.
- A stack struct copy the target keeps (`Vec3 v = src;`) needs the init-declaration form. Declaring first and assigning later lets MWCC scalarize the struct and drop the stack stores.

## DSProtect code (ov004)

- These functions were built at a higher optimization level than the rest. `#pragma optimization_level 3` at the top of the file closed the RC4 encrypt routine.
- Pointers are stored offset by `0x3200`. To get a `sym+0x3200` relocation, declare the target as a data array (`extern u8 func_xxx[];`). Arithmetic on an array folds into the addend; on a function symbol it does not.
- Write `(u32)(sym + 0x3200) - 0x6400` to keep a separate `sub`.
- Functions that nothing calls by name get dead-stripped, and the symbol check then fails. Wrap the file in `#pragma force_active on` / `#pragma force_active reset`.
- The cache flush (`mcr p15` loops) works as an inline-asm block inside a `static inline` function, using `@label` labels.

## Small tricks

- Assigning `true` to a 1-bit bitfield in C++ gave the target's `bic`+`orr` insertion (`func_ov003_021d7894`).
- An `s32` loop index compared as `(u32)i == count - 1` changed the compare and register allocation enough to match.
- Declaring a read-only table `const` (`extern const T tbl[];`) changed scheduling around its loads.
- A parameter typed `bool` instead of `int`/`BOOL` changes when MWCC moves it out of its argument register. In `func_02040dd8` a flag that was spilled and then passed to a call next to a constant (`0xffff`) only came out in the target's order as `bool load`.
- Passing the same member address (`wh->bssDesc`) to several calls: a function-level local set once (`u8 *bssDesc; ... bssDesc = wh->bssDesc;`) gives different callee-saved registers from repeating the expression. The permuter found this for `func_020461e4`.
- In a pointer-walking loop, `u32 w = *q; q++;` and `u32 w = *q++;` schedule differently. Recomputing an expression where it is used (`((Fn)DEC(*lp))(&ctx)`) can also beat keeping a copy in a local, because MWCC then CSEs it into the register the target uses (the ov004 `021cdc6c` family).

## Branches that the compiler merged

MWCC merges identical code at the end of two branches (tail merging), and that can leave an unconditional branch to a branch behind. If the target has a jump pattern that if-conversion would normally remove, the original probably repeated code:

- `cmp; bgt L; b Clamp` before a block that both paths share: the source had two branches with identical bodies, e.g. `if (a <= b) { CLAMP } else if (x == 0) { CLAMP } else { ... }` (`func_ov000_02158120`). An `||` condition or a `goto` gives a plain `ble`.
- `cmp; beq L; b M; L: mov r1, #c; M: bl f`: two calls to the same function that differ in one argument, `if (id != 0xffff) { t = f(d, id); } else { t = f(d, 0x8d); }`. The other arguments must already sit in registers, so read them into locals first (`void *d = data_x;`). A ternary or an `if` that changes `id` gives `moveq r1, #c` instead (`func_ov000_0215e344`).

## Reassigning a variable

If the target computes a value into a variable's own callee-saved register (`asr r5, r5, #12` while `r5` held `y`) and does it earlier than your code, write it as an assignment to that variable, `y = (y >> 12) + 2;`, before the other statements, instead of passing `(y >> 12) + 2` as an argument (`func_ov000_02159720`).

## Functions nothing calls

The linker strips functions that nothing references. If `ninja` reports a matched function as "not found by name in linked binary", check `relocs.txt` for calls to it (`grep to:0x<addr>` over every module); if there are none, wrap it in `#pragma force_active on` / `#pragma force_active reset`. The same applies to what your range leaves behind: an undecompiled gap is kept only while something in it is referenced, so don't split off a range that leaves an unreferenced function alone in a gap (`func_ov000_0214b654` is in, `0214b670` waits for `0214b68c`).
- **A comma expression on a local's initial load.** `actor = (0, self->list->actor);` computes the same value but changes which callee-saved register the local gets (the permuter found this; it moved `actor` from `r5` to the target's `r7` in `func_ov011_021fb02c` and halved the diff). Try it on the one local whose register is shifted when every other value is shifted with it.

## Inline arguments and struct results (overlays 9–13)

- **Pass a field expression straight into an inline.** `Ov011_SetTw(FLD(Ov011Tw108 *, self, 0x108), 0, 0x1000)` in each branch, instead of a local hoisted above the `if`, let MWCC hoist the pointer load and a constant shared by the branches above the branch, as the target does (`func_ov011_02200310`).
- **Give a struct-returning inline the source pointer.** `Ov010_MkRotZ(q)` reading `FLD(u16, q, 8)` inside the inline fixed a register swap that `MkRotZ(q->ang)` caused (`func_ov010_021fb5c8`).
- **Narrow before a narrow-parameter inline.** `u8 a = v; SetAlpha(self, a);` gave the target's clamp sequence.
- **Materialized bool.** `BOOL on = FALSE; if (pl) on = bits != 0;` gives the `movne/moveq` pair stored as a value.
- **Scalarized struct result.** `Vec res; if (..) res = d; else if (..) res = r1; else res = r2; *out = res;` gives a single `stm r0, {r8, r9, r10}`. A function that appears to return a `Vec` is really `void f(Vec *out, ...)`.
- **64-bit dot products.** An inline that copies components into `s64` locals and multiplies them gives the generic `umull`/`mla` sequence (`func_ov013_02205c74` draft).
## More patterns (ov000, round 17)

- **Check the callee's prototype in other overlays.** An old draft declared `func_0204bfa8(void)`, but every caller passes the camera in `r0`. With the correct prototype `u16 func_0204bfa8(void *cam)`, `func_ov000_0218c25c` matched immediately. When a draft is a few register moves off around a call, grep the other callers before you touch the body.
- **Copy the struct, then accumulate.** For the target pattern `ldmia` of a `VecFx32`, then `add`s on the copies, then a call taking `x,y,z`, declare `VecFx32 p;` at function scope, write `p = *v;`, then `p.x += ...; p.y += ...;`. Pass `p.x, p.y, p.z` to the call (`func_ov000_021c4fdc`).
- **Repeated calls in both branches.** If both arms end in the same `STD_CopyString; STD_CopyString; flags |= 0x10` sequence and the target has the tail-merged jump, write the whole sequence in each branch rather than hoisting it out (`func_ov000_02193e5c`).
- **Chained flag tests as nested BOOL inlines.** If the target computes `mov r0,#0` and then sets `r0=1` in steps, write each condition as an inline `BOOL r = FALSE; if (a && Inner(self)) r = TRUE; return r;` that calls the next one (`func_ov000_021732a8`, four levels deep). Flat `&&` chains give a different branch layout.
- **Sub-object pointer declared, then assigned.** In `func_ov000_02162294`, the call that tears down the inlined member needed `u8 *sub; ... sub = self + 4; Dtor(sub);` placed after the other calls. An initialized `u8 *sub = self + 4;` or a plain `self + 4` gets a different register.
- **Factories that switch over `new`.** Write each case's `operator new` and constructor as its own `static inline` helper. That stopped MWCC from cross-jumping the cases and gave the target layout in `func_ov000_021b4828`. That function was matched in round 18.
- **Pooled small constants in G3 wrappers.** `func_ov000_021535a8`, `0215d4b4` and `0215b2e4` load constants like `0x2a` with `ldr rX,=imm`, where any version would normally emit `mov`. Neither pragmas nor other compiler versions reproduced this. These may be hand-written asm or inline G3 macros writing through a volatile pointer. Not solved yet.

## Local initializers and accumulation order (overlays 9–14)

- **Const cast on one table read.** When only the key comparison in a table scan needs the early-scheduled load, cast that one read: `key == ((const Ent *)tbl)[i].key && tbl[i].fn != 0` (`func_ov010_02202750`).
- **Zero-initialized vectors declared in place.** `Vec a = {0, 0, 0};` declared right before its fields are set, rather than at the top of the function, gave the target's store order and stack slots (`func_ov010_022090b4`).
- **Struct copy as an initializer.** `Rot r = *(Rot *)self->rot;` followed by a field overwrite kept the `ldm`/`stm` copy where an assignment after the declaration did not (`func_ov009_0220387c`).
- **Sum of squares order.** MWCC emits the terms of `sq = dx * dx; sq += dz * dz;` as `smull` for `dz` then `smlal` for `dx`, so write the terms in the reverse of the order in which the target multiplies them.
- **Copy, then add to one field.** `FLD(Vec, 0xd8) = pos; FLD(s32, 0xdc) += h / 2;` matched where computing the adjusted vector first did not (`func_ov014_0220ee9c`).

## Store order, constant reuse and duplicated cases (overlays 9–14, round 16)

- **Store order can be the reverse of the source.** The target in `func_ov011_022063b0` stores `++cnt` before `id = 0xffff`. Writing `cnt++; id = 0xffff;` produced the opposite order. Writing `id = 0xffff; cnt++; if (cnt < 3)` produced the target order. When two independent stores come out swapped, try swapping the statements in the source. The same fix applied to `*(Vec *)0x370 = v; id = h;` in `func_ov011_02206920`, and to a bitfield store versus a `u16` store in `func_ov009_02212978`.
- **A computed constant shows constant reuse.** `sub r0, r4, #0x1000`, with `r4` known to hold 0, or `sub r0, r4, #0x10800`, with `r4 = 0x1800` from an earlier call argument, is MWCC making one constant from another register. Write the plain constant (`-0x1000`, `-0xf000`). Constant reuse can also stop a match: in the parked `func_ov009_02208b24`, MWCC built `0x19a` as `0x66 + 0x134`, but the target loads it from the pool.
- **Duplicated case bodies.** A switch case whose whole body is `b <other case>` comes from two cases with identical bodies that MWCC cross-jumped. Write the body twice; `case 0: case 10:` gives a different compare tree (`func_ov009_0220aeb8`, `0220a128`).
- **The rounding macro for float to fx32.** `x > 0 ? x * 4096.0f + 0.5f : x * 4096.0f - 0.5f` gives `_fgr` + `_fadd`/`_fsub` (`func_ov009_02214ac0`). A `(s64)`-param inline, `s32 f(s32 a, s64 b) { return (a * b + 0x800) >> 12; }`, gives the generic `umull`/`mla`/`asr #31` 64-bit multiply with a zero register.
- **Element copies plus the following call's pointer in one block.** In `func_ov009_021fde1c`, the target interleaves a `Vec` copy, `t.y += 0x1400` and the `data+0xf4` pointer for the next call. It matched only with `{ Src *g = ...; t = pl->pos; t.y += 0x1400; ang = Get(g); }`.
- **Read the field before the constant stores.** `{ s32 y = FLD(s32, self, 0x6c); v.x = 0; v.y = y; v.z = 0x1000; }` fixed the register shift in `func_ov012_02208c0c`. So did `s32 z = Rand(..) + 0x2400; v.x = 0; v.y = 0; v.z = z;` in `func_ov009_0220aeb8`. A plain `v.y = FLD(...)` between the stores did not.
- **Widen an inline's last parameter.** Declaring an inline's trailing parameter `s32` instead of `u8` removed a stray `and #0xff` and fixed the allocation in `func_ov011_02206e18`.
## More patterns (ov000, round 18)

- **Two zero words sharing a register.** When the target clears two adjacent words through one scratch register (`mov r0,#0; str r0; str r0` with a shared base), `LFLD(s64, st, 4) = 0` reproduced it (`func_ov000_021b06dc`).
- **Avoid address CSE across a key compare.** Read the table key through `*(s32 *)((u8 *)tbl + i * 12)`, with an `s32` key variable, so MWCC does not reuse the entry address for the later pointer-to-member call. Pointer-to-member dispatch is written `(((Cls *)self)->*tbl[i].fn)()` (`func_ov000_021b06dc`).
- **Store order z then x.** `s32 x = pos.x + dx; pos.z += dz; pos.x = x;` gives the early x sum with the z store first (`func_ov000_0218dbe0`).
- **Re-read the field in each FX multiply.** Hoisting `(s64)spd` into a local produced a full 64x64 multiply. Reading `self->unk_9c` again in each multiply, with the operand order the `smull` uses, gave the target.
- **Float compare against zero.** `if (v != 0.0f)` with an `s32 v` emits `_fflt` and then `_fneq(0, f)`.
- **12-byte vector mask.** `v.x = mul; v.y = 0; v.x &= ~0xfff; v.y &= ~0xfff;` gives the target's `and r2, r0, #0` (`func_ov000_0217de7c`).
- **Narrow parameter types fix spill order.** A `u8` (or `u16`) parameter instead of `BOOL` fixed the parameter-spill order. An if/else that repeats the call gives the target's `beq; b` fallback shape (`func_ov000_021b6994`).
- **Boolean return order.** `if (x != 3) return FALSE; return TRUE;` gives the `movne #0` / `moveq #1` order. `b12 != 3 ? A : B` gives the right branch sense (`func_ov000_021a16b0`).
- **Use the global array directly.** Write `data_ov000_021ccd34[...]`, not a local alias, so the inline CSE reuses the top-level load. The declaration order of `u32 saved` and `VObj *next` fixed a register swap (`func_ov000_02180900`).
- **Shared `return 0` enables tail merge.** Restructuring so that both paths reach one `return 0` enabled the cross-jump tail merge (`func_ov000_021778f0`).
- **OAM SetPos.** `e->x = (u16)(x - 0x80)` keeps `-8 - 0x80` from being folded. A `u32` value gives unsigned division through `umull`. The OAM words are `y:8, :8, x:9, :7` and `tile:10, prio:2, pal:4`.
- **Packing two halfwords.** `((a & 0xffff) << 16) | (b & 0xffff)` with `s32` parameters gives `lsl`/`lsl` + `orr ..., lsr #16`. `(a << 16) | (u16)b` and `(u32)(b << 16) >> 16` do not (`func_ov000_021722c4`).
- **`fl = FALSE; if (cond) fl = TRUE;`** gives `mov r9,#0; moveq r9,#1`, where `fl = cond` gives a `moveq/movne` pair (`func_ov000_02172f7c` draft).
- **Known blockers.** The `0214b4xx` TWL functions are `module:none`. The `__sinit_ov000_*` functions are blocked. In `func_ov000_021c14f4`, the camera `g+0x1ec` base cannot be reproduced.
- **Register-only drafts that are still parked.**
  - `func_ov000_021c2e64` (7). The permuter got it to 2 by giving the `CalcY` inline a `volatile u32` return type. That is not plausible source, so the draft is still parked.
  - `0216607c` (8, row/list register).
  - `0218e12c` (22, mgr/group swap). A decl-order search took it from 37 to 22 by reversing the decl order.
  - `021708ec` (11, mq/end swap inside the message-queue lookup inline). That function needs a local `FindById` variant that reads `writeIndex` before `readIndex`.
  - `02199180` (27, loop-invariant registers). `02199554` has the same shape.
  - `021c17dc` (77). MWCC keeps the shared `0x40` copy size in a callee-saved register, which shifts every allocation.
  - `02181c4c` (55, stack-temp scheduling).
  - `0217a1f8` (3). MWCC derives `-1` from `0x78` (`sub r2, r1, #0x79`) where the target uses `mvn`.

## Stack slots, split stores and repeated bodies (overlays 9–15, round 17)

- **Decrement a timer only if it is nonzero, reading it once.** When the target loads the timer once, tests it, and stores `t-1`, write `u16 t = *(volatile u16 *)&st->timer; if (t) st->timer = t - 1;`. With a plain `if (st->timer) st->timer--;` the compiler reloads the field (`func_ov014_0220abf8`).
- **Splitting a store that the compiler merged.** If the target stores the same field twice (a clamp to `lim`, then a compare, then a store of `mn`), keep both stores in the source and put the first one *before* the second compare. A `volatile` store did not keep the two stores apart (`func_ov015_0220064c`).
- **Moving a local's stack slot.** Locals declared inside a `static inline` helper get their slots in expansion order, below the caller's function-level locals. Moving a computation into an inline function moves its local to the lowest slot (`func_ov014_022033a8`). Block-scoped `Vec v = {0,0,0}` locals likewise go after the function-level ones. Reordering local declarations also shifts the slots.
- **Statement order in large camera bodies.** Several ov015 camera functions (`021fe218`, `021fe548`, `021fd634`) differ only in the order of independent loads and stores. A small script that permutes the candidate statements and runs `tools/match.py` on each version found the order faster than editing by hand.
- **Prepending a function.** When the unmatched function sits directly before an existing `complete` file, move that file's delinks `start` down and prepend the function. The file name can stay the same (`func_ov015_02208070`, `func_ov014_0220abf8`).
- **Repeated bodies inlined into a dispatcher.** `func_ov015_021fd900` contains the full bodies of `021fe814`, `021fd634` and `021feb34`. Copying them into the file as static inlines produces a frame of 0x1cc where the target has 0x184, plus calls to `Ov015Vec` constructors, because the class has an empty user-written constructor. A plain-old-data (POD) vector type for the inline locals is the next thing to try.
## More patterns (ov000, round 19)

- **High-nibble and low-12-bit ids.** `ldrh; lsl #4; lsr #16` is `(u16)(v >> 12)`, and `and 0xfff; lsl #16; lsr #16` is `(u16)(v & 0xfff)`. Write them as small `u16` inlines (`ItemKind(v)`, `ItemIdx(v)`), not as a bitfield (`func_ov000_02178dcc`).
- **Pointer plus index plus offset.** `add r1, r2, r1, lsr #16; ldrb r1, [r1, #0x2a]` comes from `*(base + idx + 0x2a)`. `base[idx + 0x2a]` gives `add #0x2a; ldrb [r2, r1]` instead.
- **Saturating add through a local base.** `u8 *g = data_x; if ((LFLD(u32, g, 0x20) += n) > 99999) LFLD(u32, g, 0x20) = 99999;` gives `add; str; cmp; strhi` with no reload.
- **`muls` operand order.** If `muls rD, rA, rB` has its operands swapped, swap the factors in the source (`p->8c * p->88`).
- **Per-arm compares give an unconverted branch.** `cmp; beq L; ldr r1,=A; b M; L: sub r1, r3, #B; M: cmp rX, r1` comes from two arms that each do their own compare and set the same flag: `if (bit) { if (d >= -0x666) hit = TRUE; } else { if (d >= -0x7b) hit = TRUE; }`. A ternary or an `if` that picks the limit gets if-converted (`func_ov000_02198ad8`).
- **`const` on the subtracted vector.** `pos->x -= vel->x; ...` after field-wise stores to `self->pos` loads `vel` early, interleaved with the stores, only when `vel` is `const VecFx32 *` (`func_ov000_02198ad8`).
- **Rotated offset vector.** For `ofs` rotated by `rot_y` with `FX_SinCosTable_` and passed to `VEC_Add`, read `rot_y` into a local before `if (ofs != NULL)`, keep `x`/`z` as scalar locals starting at 0, and read `ofs->y` into its own local just before the three `dv` stores. That puts `ofs` in a callee-saved register as the target does. A narrow (`u16`) type on the third parameter moved its spill to the first instruction (`func_ov000_0219aae8`, `0219aca8`).
- **Parked this round.** `0217a1f8` (3): the target uses `mvn r2, #0` where MWCC reuses `0x78`. No prototype type, inline or local changed it. `0218a5ec` (6): the target keeps the stack argument `0x8000` in `ip` and stores it last. `0214bcc4` (40): `switch` with `if (id == kind)` cross-jumps. `021bd474` (33): the target loads `out.y` first and computes `dx` first. `0218cfc8` (35): the inlined `FindActor` uses `ip`/`lr` in the target. `021597dc` (76): `trg` in `r0`. `02161994` (10), `02195618` (6), `021b2b08` (21), `021b3e90` (6): register-only diffs.

## Inline size, pointer locals and statement order (overlays 9–15, round 18)

- **Raise the inline size limit for very large inline bodies.** `func_ov015_021fd900` inlines the full bodies of three camera functions. Past MWCC's default inline size limit, the compiler stops inlining the small helpers inside them and emits calls to the `Ov015Vec` constructor and to the implicit `operator=` for each copy. That gave a frame of 0x1cc instead of 0x184. A POD vector type did not help, because MWCC still calls the implicit `operator=`. `#pragma inline_max_size(512)` at the top of the file matched with no other changes. 256 is too small; 450 and up all work. The camera file now covers `0x021fd00c`–`0x021fee54` in one unit. In a dispatcher, keep the three bodies as `static inline` copies. Making `021fe814`, `021fd634` and `021feb34` thin wrappers around the inlines changes their stack slots.
- **A pointer local for `&self->pos`.** `func_ov012_0220422c` was 12 diffs from register allocation and the argument order of one `VEC_Add`. The permuter found `Ov012Vec *pos = &self->pos;` (declared with the other locals, assigned after the first statements), used everywhere the function passes `&self->pos`. That matched, and the old wrapper that forced out-pointer-first evaluation was no longer needed.
- **Split a modulo increment.** `FLD(s32, self, 8)++; FLD(s32, self, 8) %= 0x7fff;` gave the target registers, where `x = (x + 1) % 0x7fff` did not (`func_ov015_021fb5d4`).
- **if/else gives `movge`/`movlt`.** A ternary `x = c >= k ? 1 : 2` gave `mov #1; movlt #2`. Writing an if/else that stores in both arms, after taking the `&Dup::` pointer, gave the target's pair of conditional moves and the right store order (`func_ov015_021fb5d4`).
- **Re-read a field in a call argument.** `func_ov003_021d9980(..., self->unk_98, ...)` right after `self->unk_98 = r;` matched, where passing the parameter `r` did not (`func_ov013_02205bec`).
- **Persp init order.** For a camera init that inlines `SetFovy` (`func_ov015_021fce94`, parked at 13), the closest order was: set the fovy angle, then `n`, then `dirty = 1` as a separate statement, then `f`. The rest is a swap of the registers holding `1` and `0x119a`.

## Overlay IDs as linker symbols, and blockers (overlays 2–8, round ovlow1)

- **`OVERLAY_N_ID` literals.** Small constants that are loaded from the literal pool with no relocation (`ldr r4, =0x9` … `=0xe`) are linker absolute symbols. Declare them as `extern u8 OVERLAY_9_ID[];` and use `(s32)OVERLAY_9_ID` in the code (for example as switch results). Plain integer constants become `mov` immediates and do not match (`func_ov003_021cf77c`).
- **Whole-struct copy inside a copy inline.** `*d = *s` inside a small copy helper gave the target's interleaved `ldr/ldr/str/str` for Pair copies. Field-by-field copies scheduled differently (`func_ov003_021eb818` draft).
- **Jump-table size needs an empty case.** If the target's jump table has an entry for a value that does nothing, add `case N: break;` so the table size matches (`func_ov006_021cf420` draft, which needs `case 7`).
- **Claiming a small pool by extending the next file.** `func_ov003_021d6e04` keeps a string literal in a saved register, so it needs a real literal. Its pool (`0x021f7cb0`..`0x021f7cbc`) was shared only with the functions of the following file, so that file was renamed to start at `0x021d6e04` and claimed the pool with `tools/strrefs.py --claim`. A string loaded right before each use (`ldr r1, =str` just before the call) still matches with an `extern char[]`, so such functions do not need their pool claimed (`func_ov003_021d36fc`, `func_ov003_021e6274` drafts).
- **Constant 1 kept in a register.** When the target derives `0xffff` and `0x201` from a register holding 1 (`rsb r3, r4, #0x10000`, `add r2, r4, #0x200`), the inlined code shares one CSE'd constant with the caller. In `func_ov008_021cfa38` this structure only appeared once a bool-returning inline was written as two nested `? TRUE : FALSE` inlines (the target's double `movne/moveq` normalisation); registers are still rotated.
- **Blockers.**
  - **Shared string pools.** The ov006 pool (`0x021ebbb0`..`0x021ebc65`) and the ov003 pool (`0x021f8564`..`0x021f85c1`) are used by many functions in many files. Externs declared as `const char[]` do not reproduce the early literal loads. With real string literals, `func_ov006_021d3f04` reaches 0 diffs and `func_ov003_021e44dc` reaches 7, but the literals only work if one file claims the whole pool.
  - **`func_ov006_021cf414`.** This is a vtable entry (the vtable at `0x021ebda4` references it), so it cannot be stripped as an unreferenced gap function. Its body is `ldr r1,[r0,#0x4c]; cmp r1,#0; bx lr`, which has no value return. No variant of the C source has reproduced it.
  - **`func_ov004_021cd97c`** (DSProtect decryption, `optimization_level 3`). It is at 24 diffs and only register allocation differs: the loop index and the word temporaries are swapped between r4 and r7.

## Inline helpers and pointer locals (main, round 23)

- **Wrapping a body in a `static inline` helper** pushes its parameters later in register allocation, which can fix a rotation among the callee-saved registers. Nested inlines inside it become `bl` calls unless the file has `#pragma inline_max_size(4096)`.
- **A pointer local for an address passed to several calls** (`ResRing *ring = &loader->ring;`) can reorder the whole callee-saved register assignment. The permuter finds these as `new_varN`.
- **Recognise inlined helpers.** `func_0205b588` inlines the whole body of `func_02059454` (read N bits from a save block). Copying that body as a `static inline` fixed the loop's instruction order. The registers matched only once the inline took `(u32 idx, s32 n, u16 start)` and the caller computed `int n = v & 0xff;` into a local before the call.
- **Search declaration orders with a script.** A small script that moves each top-of-function declaration to every other position (or tries N random shuffles) and scores each version with `tools/match.py -q` took `func_020534dc` from 289 diffs to 12 in round 25. Run one before hand-editing a near miss whose diffs are mostly registers.
- **Inline parameter type versus caller parameter type.** `func_0206d0d4` takes `u8 used` (a stack argument) but passes it to a bitfield-setting inline whose parameter is `BOOL used`. Only that mix gave the target's load order of the two stack arguments. `u8` in both, or `int` in the caller, did not.

## Struct members and split constants (overlays 12–15, round ovhi8)

- **Interleaved 6-byte `Rot` copy.** The target's `ldrh; ldrh; strh; strh; ldrh; strh` for a 6-byte rotation comes from copying a member of a named struct object (`r = dat.r;`), not from array-plus-offset addressing (`*(Rot *)(data_x + 0xc)`). If the object's symbol name clashes with an existing declaration, redeclare it in a namespace with `extern "C"` (see "Duplicate literal-pool entries").
- **A split constant.** `sub r0, rX, #0x34000` followed by `sub r0, r0, #0x10000` came from `SetV(&v, 0, -0x34000, 0); v.y -= 0x10000;`, not from one `-0x44000`.
- **A callee's declared return type changes scheduling.** In `func_ov012_02205990`, a `mov r1, #0xa` and an `ldr r0, [r7, #0x40]` after a call were in the wrong order until `func_02049a48` was declared returning `void *` (it returns a sound handle) instead of `void`. The permuter found it by trying a `long long` return. When a load or `mov` right after a `bl` is out of order, check the callee's return type.
- **Folded null guard on string arguments.** A `NewModel2(nm, arc)` inline that copies its arguments into locals (`char *n = nm; char *a = arc; if (n) {...}`) keeps the string loads hoisted into saved registers without emitting a real compare, since the guard folds away on literals (`src/ov000/Lo_0217ef3c.cpp`).

## Ternaries and block-scoped vectors (overlays 9–14, round ovhi10)

- **An angle as a ternary inside the null check.** `if (t) a = (t && t != self) ? FX_Atan2(...) : self->rot[1];` fixed a register swap that the equivalent if/else caused.
- **A block-scoped vector with an initializer stays on the stack.** `Ov014Vec b2 = data;` inside a block kept the stack copy, and putting the null path in a trailing `else` instead of an early `return` gave the target's layout.

## Assignment versus initialisation, references and getters (overlays 2–8, round ovlo4)

- **Plain assignment after the declaration.** `Rot rot; ...; rot = self->rot; rot.x += ...;` matched where `Rot rot = self->rot;` at the top stayed far off. The init-declaration moves the copy and changes slot order.
- **C++ reference alias.** Declaring `T *&ref = p;` and writing through `ref` fixed a register swap that the permuter could not reach otherwise.
- **Tiny static inline getter.** Wrapping a repeated call expression in a one-line `static inline` getter fixed the register order of its results.
- **`bool` normalisation needs C++.** A helper returning `g->a != g->b` gives the target's `movne/moveq` pair only in a `.cpp` file (`func_ov003_021f27ec`). The same helper in `.c` does not.
- **Bitfield/field store order is source order.** In `func_ov003_021f27ec` the camera block only matched as `fa`, `da_5 = 1`, `fc`, `da_6 = 1`, interleaving the bitfield sets with the halfword stores.
- **Right-to-left argument evaluation.** In a call with two calls as arguments, the rightmost runs first. Write `Add(list, k, Get(g, 0x48 + k), Get(g, 0x160 + k))` when the target calls `0x160` first.
- **A zero passed to a call.** `f = 0;` written right before the call that receives `f` (instead of at the top) kept the zero in the target's register (`func_ov006_021e96cc` draft).

## Factories, colour copies and large switches (ov000, round hi9)

- **Block-local temp for each `new` in a big factory switch.** Write every case as `{ u8 *t = (u8 *)Alloc(size); if (t) { Ctor(t, ...); } p = t; } break;`. With the `new` result assigned straight to the shared `p`, MWCC merges the identical case tails.
- **3-byte colour copy.** Copy an RGB triple as a struct, `*(Rgb3 *)dst = *(const Rgb3 *)src;` with `struct Rgb3 { u8 v[3]; };`. Three `u8 r, g, b` locals schedule differently.
- **Mapping cases to bodies in a large sparse switch.** A small script that parses the jump table and the `cmp` tree from the disassembly and prints each case value with its body label (`parse.py`, `gen.py` in the hi9 scratch `gen/` folder) saves a lot of manual tracing.

## Inline wrappers and reused zero registers (ov000, round hi10)

- **A BOOL inline can fix a register swap.** In `func_ov000_021a4a6c`, an r1/r2 swap went away once the fall-height test was moved into `static inline BOOL Falling(u8 *self) { BOOL drop = FALSE; ... return drop; }` and called as `BOOL drop = Falling(self);`.
- **`orr r0, r1, r3` where you expect `orr r0, r1, #0`.** MWCC reuses a register known to hold 0 as the high half of a 64-bit OR. In `func_ov000_0219efc0`, `r3` was a pointer set to NULL before an `if`/`else`. Declare that variable once, before the branch, rather than inside each arm.
- **Layout follows source order for `else` chains too.** If the target puts the `|= 0x80` body before the `|= 0x4000` body, write `if (m != 3) { if (...) |= 0x80; } else { |= 0x4000; }` instead of `if (m == 3) ... else if ...`. In a switch, put `default:` first when its body comes first.

## Duplicated per-arm adjustments (overlays 2–8, round ovlo5)

- **One temp per arm instead of a shared one.** When the target computes a small adjustment separately in each `if`/`else` arm, write it out in each arm with its own block-local temp (`if (held & 0x40) { if (kind == 5) { u16 t = a; steer += t; base += t; } else { u16 t = b; steer += t; base += t; } }`) rather than picking one shared `t` with a ternary first. That fixed the scheduling in the ov006 car function `func_ov006_021e8ef8`.
- **OAM-style copies: take the destination pointer first.** When an entry is copied from the previous one and then positioned, write `{ T *o = &oam[n]; oam[n] = oam[n - 1]; Put(o, x); }` so the address is computed before the copy, as in `src/ov006/ov006_021dd5dc.cpp`.
- **Zeros reloaded from a stack slot.** If the target reloads `0` from one stack slot before many unrelated zero stores (`ldr r0, [sp, #0x14]; strh r0, ...`) and later sets that slot to 1 and tests it, the slot is a spilled flag that MWCC merged with the constant 0. Declaring the flag `u8` instead of `BOOL` reproduced the reloads; with `BOOL` (or `volatile`) they did not (the `func_ov003_021ed6b8` draft went from 724 to 6 diffs). Declaring the hit-list array after the query, finder and flag locals closed most of the rest.
## Early returns, block-scoped locals and stack arrays (ov000, round hi11)

- **Early-return inlines versus a result flag.** In `func_ov000_0219efc0` the target's idle check branches with `bne` and loads `mov r4, #0` fresh. That came from `if (IsBusy(g)) return FALSE; if (*g != 3) return FALSE; return TRUE;`. A `BOOL r = FALSE; if (...) r = TRUE;` body gave conditional instructions instead. The colour check next to it needed the opposite form, a flag set to `FALSE` and then to `TRUE` inside the `if`.
- **An early `return NULL` in a lookup inline.** `func_ov000_021a6280` matched once `FindActor` became `u8 *r; if (mgr == NULL) return NULL; r = Find(mgr, id); return r;`. That fixed an r7/r8 swap between the actor and a hoisted pointer, and the conditional `moveq` of the NULL.
- **Block-scoped locals fix callee-saved register rotations.** In the `func_ov000_0219d9fc` draft, `off`, `res` and `alpha` were rotated through r5, r6 and r9. Declaring them with initialisers in a new block at the point of first use, ordered `res`, `off`, `alpha`, and writing `alpha = (0, load)`, gave the target's registers. Decl order inside a nested block (`BOOL set; u16 rz, ry, rx;`) also moved the rotation-matrix registers.
- **A stack copy that is written but never read.** When the target stores three values both to a stack slot and to the destination, use an array with field-wise assignments: `s32 q[3]; q[0] = ...; q[1] = ...; q[2] = ...; dst = *(VecFx32 *)q;`. A `VecFx32` with field assignments or an aggregate initializer gets scalarized away. `VecFx32 q = src;` stays on the stack but copies with `ldm`/`stm`.
## By-value vector inlines and `const` parameters (overlays 9–15, round ovhi13)

- **An inline that returns a vector struct by value** creates the extra stack temporaries some targets have. In `func_ov013_022038a8`, `static inline Ov013Vec Ov013_Around(const Ov013Vec *base, u16 r)` builds the vector in a local and returns it, and `Ov013Vec c = Ov013_Around(...);` gives the target's additional stack slots and copies. An out-pointer version does not.
- **A `const` pointer parameter can change codegen.** Declaring the function's `pos` parameter as `const Ov013Vec *` took `func_ov013_022038a8` from 12 diffs to 0.

## Reusing a sibling file's helper (main, round 28)

- **Look for the same computation in the neighbouring files before rewriting it.** `func_02048a48` (a backup write in `SaveBase_5.cpp`) sat at 9 diffs for several rounds: its pool loads came out in the wrong order with every expression form of the backup offset. `SaveBase_4.cpp` already had a matched `BackupDataOffset` written as load-then-accumulate (`off = dataSize * slotCount; off += baseOffset + headerSize; off += idx * dataSize;`). Using that body (now `SaveBase_BackupOffset` in `SaveBase.h`) matched at once.
- **A null test keeps a sub-object address unfolded.** In the parked `func_02050ebc`, the target reads `owner->sub.id` (offset 0x3d2) as `add r0, r4, #0x3c0; ldrh r0, [r0, #0x12]`, where MWCC folds every plain form into `#0x300` + `#0xd2`. Only `(sub = &owner->sub) != NULL && sub->id != 0x1000` kept the `#0x3c0` add (3 diffs: `adds` and conditional loads remain). The original's form is still unknown.
## `const` data and store/load ordering (overlays 9–15, round big1)

- **A `const` extern lets loads move above stores.** MWCC treats a load from a `const` object as independent of earlier stores, so the scheduler may hoist it. In `func_ov010_021fd694` the target stores `self->f4 = 0` before building the attach-offset copy (`str r4, [r5, #0xf4]; add r6, sp, #0x24; ldm`), while a `const Ov010Vec data_ov010_0220ec20` gave `add r6` first. Reading the vector through a non-const redeclaration, `namespace NC { extern "C" Ov010Vec data_ov010_0220ec20; }`, kept the store first and matched. Two `bl`/`blx`-free diffs that look like pure scheduling are worth this check.
- **Block-local vectors give the target's stack order in a big switch.** When every case of a state machine has its own vectors, declare them inside the case blocks (with the struct-returning inline as an initializer, `Ov010Vec pos = AttachPos(self);`) rather than at function level. Their slots then follow the order of the cases, and the struct-returning inline writes straight into the variable instead of through an extra temporary (`func_ov010_021fd694`, 0x18 bytes of frame saved).
- **A volatile reload only on the read.** For `if (t >= N) { reset; } else { t++; }` where the target reloads `t` in the else arm but still schedules the epilogue `add sp` above the first load, write the increment as `FLD(u16, st, 2) = (*(volatile u16 *)&FLD(u16, st, 2)) + 1;`. A volatile `++` (volatile store too) pins the epilogue below it.
- **`match.py` shows `bl` against `blx` for calls to Thumb functions** (`MTX_RotX33_` and friends). The linker rewrites these, so ignore those lines when counting a draft's real diffs.
- **Pool constant against `sub; sub`.** `h = x - 0x19a;` loads `-0x19a` from the pool and adds it; `h = x; h -= 0x19a;` gives `sub #0x9a; sub #0x100`. Try both when a large subtraction differs (`func_ov009_02204a10` draft).
- **Signed compare of a `u16` field.** `if (st->state <= 2 && b == 1)` compares unsigned (`cmp; pophi`). `if ((s32)st->state <= 2) { if (b == 1) ... }` gives the signed, if-converted `cmp; ldrle; ldrshle; cmple` chain.
## Spills, zero registers and callee return types (ov000, round lo9)

- **A pointer alias to a bitfield byte.** Taking `Bits *fl = &LFLD(Bits, self, 0xa2);` once and testing `fl->b0`, `fl->b3` through it, instead of re-reading `self`'s bitfield each time, changes which variable MWCC spills to the stack across the loop (`func_ov000_0218af9c` draft).
- **if / else-if / else stops zero-register reuse in `adc`.** A 64-bit add whose high half is `adc rX, rY, #0` in the target came out as `adc rX, rY, rZ` (reusing a register holding 0) when written as nested ifs; an `if / else if / else` chain around it ended the zero's live range and gave the immediate.
- **A callee's declared return type changes stack-store order.** Declaring `sprintf` as returning `void` instead of `int` changed the order of the stack-argument stores before the call. Try both when only `str [sp, #N]` order differs around a varargs call.
- **`long` loop counter.** In `func_ov000_0217b324` (draft), declaring the items-loop index as `long i` instead of `s32 i` swapped the loop counter and the saved heap value into the target's registers (`r7`/`sb`), removing 9 diffs. `long` and `int` are both 32-bit, but MWCC orders them differently in register allocation. The permuter found it as a type change.
## Factories and hoisted constants (overlays 2–8, round ovlo8)

- **Same address, different overlays.** A factory case that calls a constructor at an address shared by several overlays (`relocs.txt` says `module:overlays(9,10,...)`) must name the overlay that the case's id loads. In `func_ov003_021cfab4`, ids `0x5c02` and `0x5c15` both call `0x021fa6a0`. Declared once as `func_ov009_021fa6a0`, MWCC cross-jumped the two case tails. Using `func_ov012_021fa6a0` and `func_ov014_021fa6a0` (the overlays `func_ov003_021cf77c` returns for those ids) kept them apart. The id-to-label map for the big sparse switch came from a small script that runs the compare tree for every `u16` value (`gen/parse.py` in the ovlo8 scratch folder).
- **Order of hoisted constants in a switch.** When the target loads two constants for a case in the dispatch (`movge r0, #0x32; movge r6, #0x1e`) in the opposite order to yours, check the other cases that use the same constants. In `func_ov006_021d96a8` the fix was in a different case: `else if (send) { A } else { B }` became `else if (!send) { B } else { A }`.
- **A store moved after the loads of the next statement.** If the target stores `vel.y = 0` after the loads for `vel.z` (`ldrsh; ldrsh; str rZero; smull`), compute the next value into a temporary first: `{ s32 z = MUL(...); vel.y = 0; vel.z = z; }` (the `func_ov003_021db244` draft).
- **Use the global directly in some calls.** `func_ov002_021e1148` reads `mgr = data_02149ef8;` into a local and passes it to nine `func_0204c0e8` calls. Every callee-saved register was rotated by one until the first two calls (`0x15f`, `0x156`) used `data_02149ef8` directly, as the permuter found. When the registers of a whole function are rotated, try mixing the local and the global it was loaded from.
- **Reload a pointer into the same local after a call.** In `func_ov003_021db244` all of case 1 had two callee-saved registers swapped (the hoisted zero and the step pointer). The fix was in the trail block: after the effect call, `cfg = self->cfg; v.x = cfg->tx << 4; ...` (reusing the function-level `cfg` local) instead of `self->cfg->tx` in each line. Keeping `cfg` live across the call, or using a new block-local, did not match.
