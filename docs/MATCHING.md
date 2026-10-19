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
