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
