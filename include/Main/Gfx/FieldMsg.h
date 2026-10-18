#ifndef MAIN_GFX_FIELDMSG_H
#define MAIN_GFX_FIELDMSG_H

#include "Main/Gfx/TextWin.h"
#include "Main/Res/ResMgr.h"

extern "C" {

// Message box owner: keeps a TextWin and the strings it shows.
typedef struct FieldMsgEntry {
    /* 0x000 */ u32 unk_00_0 : 20;
    /* 0x000 */ u32 busy : 1;
    /* 0x000 */ u32 unk_00_21 : 11;
    /* 0x004 */ u8 unk_004[0x2c];
    /* 0x030 */ void *unk_030;
    /* 0x034 */ u8 unk_034[0x114];
} FieldMsgEntry; // size 0x148

typedef struct FieldMsg {
    /* 0x000 */ u32 unk_00_0 : 15;
    /* 0x000 */ u32 flag15 : 1;
    /* 0x000 */ u32 flag16 : 1;
    /* 0x000 */ u32 unk_00_17 : 15;
    /* 0x004 */ u8 unk_004[0x30c];
    /* 0x310 */ u16 unk_310;
    /* 0x312 */ u16 unk_312;
    /* 0x314 */ char name[0x20];
    /* 0x334 */ char prevName[0x20];
    /* 0x354 */ TextWin *win;
    /* 0x358 */ u32 unk_358;
    /* 0x35c */ s32 unk_35c;
    /* 0x360 */ s32 unk_360;
    /* 0x364 */ u8 unk_364[0x158];
    /* 0x4bc */ FieldMsgEntry entries[5];
} FieldMsg;

// Text window that keeps glyphs in up to 0x80 VRAM blocks (stand-alone variant).
typedef struct GlyphCache {
    /* 0x000 */ u32 flag0 : 1;
    /* 0x000 */ u32 unk_00_1 : 5;
    /* 0x000 */ u32 count : 8;
    /* 0x000 */ u32 unk_00_14 : 18;
    /* 0x004 */ u8 unk_004[0xc];
    /* 0x010 */ VramBlock *blocks[0x80];
    /* 0x210 */ u16 ids[0x80];
} GlyphCache;

extern GfxMgr *data_02097ce0;
extern const u32 data_0208ba70[];
extern const char data_0208ba20[];

extern void *func_0203dd9c(u32 size);
extern void func_0204c7d0(TextWin *win);
extern u32 func_0204c4fc(u32 a, u32 b, u32 c, u32 *outSize, u32 *outArg, BOOL d);
extern void MIi_CpuClearFast(u32 value, void *dst, u32 size);
extern void func_02039828(VramBlock *block);

}

#endif
