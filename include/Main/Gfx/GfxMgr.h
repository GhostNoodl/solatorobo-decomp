#ifndef MAIN_GFX_GFXMGR_H
#define MAIN_GFX_GFXMGR_H

#include "Main/Res/ResMgr.h"

#ifdef __cplusplus
extern "C" {
#endif

// Memory block of a VRAM allocator.
typedef struct VramBlock {
    /* 0x00 */ u32 addr;
    /* 0x04 */ u32 size;
    /* 0x08 */ struct VramBlock *prev;
    /* 0x0c */ struct VramBlock *next;
    /* 0x10 */ u32 used : 1;
    /* 0x10 */ u32 temporary : 1;
    /* 0x10 */ u32 unk_10_2 : 1;
    /* 0x10 */ u32 kind : 3;
    /* 0x10 */ u32 unk_10_6 : 16;
    /* 0x10 */ u32 pad : 7;
    /* 0x10 */ u32 unk_10_29 : 1;
    /* 0x10 */ u32 unk_10_30 : 1;
    /* 0x10 */ u32 unk_10_31 : 1;
    /* 0x14 */ u32 unk_14;
} VramBlock; // size 0x18

typedef struct VramPool {
    /* 0x00 */ u32 alignShift;
    /* 0x04 */ VramBlock *blocks;
    /* 0x08 */ int numBlocks;
} VramPool;

typedef struct GfxPltt {
    int id;
} GfxPltt;

typedef struct GfxSub {
    u8 unk_000[0x800];
    GfxPltt pltt;
} GfxSub;

typedef struct GfxSys {
    /* 0x000 */ int state;
    /* 0x004 */ u8 unk_004[0x1e0];
    /* 0x1e4 */ GfxSub sub;
    /* 0x9e8 */ u8 unk_9e8[0x48];
    /* 0xa30 */ u8 unk_a30_0 : 4;
    /* 0xa30 */ u8 unk_a30_4 : 1;
    /* 0xa30 */ u8 unk_a30_5 : 3;
} GfxSys;

typedef struct GfxFontEntry {
    /* 0x00 */ int index;
    /* 0x04 */ int mode;
    /* 0x08 */ const char *name;
} GfxFontEntry;

typedef struct GfxFont {
    u8 unk_00[0x4];
    struct {
        u8 unk_00[0x8];
        u8 *info;
    } *res;
} GfxFont;

typedef struct GfxCell {
    u8 unk_00[0x18];
} GfxCell;

typedef struct GfxMgr {
    /* 0x000 */ int unk_000;
    /* 0x004 */ u32 unk_004;
    /* 0x008 */ u32 unk_008;
    /* 0x00c */ u16 unk_00c;
    /* 0x00e */ u16 unk_00e;
    /* 0x010 */ u16 unk_010;
    /* 0x012 */ u16 unk_012;
    /* 0x014 */ GfxFont *fonts[10];
    /* 0x03c */ u8 fontHeights[10];
    /* 0x046 */ u16 unk_046;
    /* 0x048 */ GfxCell cells[64];
    /* 0x648 */ u16 plttSlots[4];
    /* 0x650 */ void *unk_650;
    /* 0x654 */ void *unk_654;
    /* 0x658 */ u32 unk_658;
    /* 0x65c */ u32 unk_65c;
    /* 0x660 */ VramPool pools[2];
    /* 0x678 */ u16 unk_678;
    /* 0x67a */ u16 unk_67a;
    /* 0x67c */ void *unk_67c;
    /* 0x680 */ u32 unk_680;
    /* 0x684 */ u8 unk_684[0x18];
    /* 0x69c */ u8 unk_69c[4];
} GfxMgr; // size 0x6a0

extern GfxMgr *data_02097ce0;
extern GfxSys *data_02097d48;
extern const GfxFontEntry data_020827f8[9];

#ifdef __cplusplus
}
#endif

#endif
