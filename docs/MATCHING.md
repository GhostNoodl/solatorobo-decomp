# Matching functions

## Quick loop

1. Find a function in the disassembly under `build/usa/asm/` (run `ninja dis` first).
2. Write C (or C++) for it in a file under `src/`, for example `src/Main/Heap/GroupHeap.c` for main or `src/ov000/...` for an overlay.
3. Check it without a full build:

   ```shell
   python tools/match.py src/Main/Heap/GroupHeap.c func_0203053c
   python tools/match.py src/ov000/Foo.c func_ov000_0214b438 --module ov000
   ```

   Branch targets and relocated pool constants are ignored, since only the linker knows them.
4. When every function in a contiguous range matches, add the file to the module's `delinks.txt` (`config/usa/arm9/delinks.txt` for main, `config/usa/arm9/overlays/ovNNN/delinks.txt` for overlays):

   ```
   src/Main/Heap/GroupHeap.c:
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
