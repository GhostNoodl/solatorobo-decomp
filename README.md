# Solatorobo: Red the Hunter decompilation

A work-in-progress matching decompilation of *Solatorobo: Red the Hunter* (Nintendo DS, DSi-enhanced, USA).

This repository contains no game code or assets. To build it, you need your own legally dumped copy of the game.

## Status

Early: about 200 of 8,100 functions matched. The ROM is unpacked and split across the main ARM9 program, ITCM/DTCM and 16 overlays, ready to be matched with [objdiff](https://github.com/encounter/objdiff).

## About the game's code

- Built with Nintendo's TwlSDK (DSi SDK), NitroSystem (NNS) and Actimagine's Mobiclip SDK 1.2.1.
- DSi-enhanced, so it has a few layout quirks that upstream [dsd](https://github.com/AetiasHax/ds-decomp) doesn't handle yet. We build dsd from source with small patches in [`tools/dsd-patches`](tools/dsd-patches):
  1. No ARM9 footer: fall back to the header's build info offset.
  2. TwlSDK autoload entries are 16 bytes, and DTCM sits at `0x02fe0000`.
  3. The `.ctor` runner isn't the last call in the entrypoint.
  4. The exception table is empty.
  5. Gap files share a name, which the linker script check wrongly flagged as duplicates.
- dsd can't rebuild a DSi-enhanced ROM yet (animated banner, arm9i/arm7i), so for now we verify matching code per module with `ninja check` instead of a full ROM SHA1.

## Compiler

The game was built with CodeWarrior for DSi, somewhere between `dsi/1.2` and `dsi/1.3p1` (mwccarm 4.0 builds 1026 to 1036). Some functions have odd-sized stack frames that newer versions don't produce, and `dsi/1.1` breaks other functions. We use `dsi/1.3p1` (`mwcc_40_1036` on decomp.me). The 2.0 compilers that most DS decomps use don't match.

## Building

1. Install Python 3.11+, Ninja, git and a Rust toolchain. On Linux you also need GCC for Wibo.
2. `python -m pip install -r tools/requirements.txt`
3. Put your ROM in [`extract/`](extract/README.md).
4. Put the Metrowerks compilers in `tools/mwccarm/`.
5. `python tools/configure.py usa`, then `ninja`.

The first `ninja` run builds the patched dsd, which takes a few minutes.

## Credits

The build scripts are adapted from the [Phantom Hourglass decompilation](https://github.com/zeldaret/ph) (CC0).
