#ifndef MAIN_RES_STAGEFLAGS_H
#define MAIN_RES_STAGEFLAGS_H

#include "nitro/fx.h"

// The game's save flags block (data_0214a424); split out of StageCmd.h so that code which only
// reads the flags does not pull in the stage script declarations.

#ifdef __cplusplus
extern "C" {
#endif

typedef VecFx32 StageVec;

typedef struct StageColor {
    u8 r;
    u8 g;
    u8 b;
} StageColor;

typedef struct StageItemEntry {
    /* 0x0 */ u16 id;
    /* 0x2 */ union {
        u16 info;
        struct {
            u16 a : 3;
            u16 b : 3;
            u16 c : 2;
            u16 used : 1;
            u16 unk_9 : 7;
        } bits;
    };
} StageItemEntry;

#define STAGE_FLAGS_MAGIC 0x45564153 // 'SAVE'
#define STAGE_ITEM_ENTRY_MAX 37

typedef struct StageFlags {
    /* 0x000 */ u32 magic;
    /* 0x004 */ u32 frameCount;
    /* 0x008 */ u8 unk_008;
    /* 0x009 */ u8 unk_009;
    /* 0x00a */ u16 unk_00a;
    /* 0x00c */ u32 unk_00c;
    /* 0x010 */ u32 unk_010;
    /* 0x014 */ u16 unk_014;
    /* 0x016 */ u16 unk_016;
    /* 0x018 */ union {
        u16 unk_018;
        struct {
            u16 unk_0 : 1;
            u16 mode : 2;
            u16 unk_3 : 4;
            u16 flag7 : 1;
            u16 flag8 : 1;
            u16 flag9 : 1;
            u16 flag10 : 1;
            u16 unk_b : 5;
        } bits18;
    };
    /* 0x01a */ u8 unk_01a;
    /* 0x01b */ u8 unk_01b;
    /* 0x01c */ u32 unk_01c;
    /* 0x020 */ u32 unk_020;
    /* 0x024 */ u16 unk_024;
    /* 0x026 */ u16 unk_026;
    /* 0x028 */ u16 itemTotal;
    /* 0x02a */ u8 items[100];
    /* 0x08e */ StageItemEntry entries[STAGE_ITEM_ENTRY_MAX];
    /* 0x122 */ u8 bits[8];
    /* 0x12a */ u16 shapeId;
    /* 0x12c */ u8 unk_12c[5];
    /* 0x131 */ StageColor color2;
    /* 0x134 */ StageColor color;
    /* 0x137 */ u8 unk_137;
    /* 0x138 */ u16 unk_138;
    /* 0x13a */ u8 unk_13a[2];
    /* 0x13c */ StageVec pos;
    /* 0x148 */ StageVec target;
    /* 0x154 */ u16 rotY;
    /* 0x156 */ u16 targetRotY;
    /* 0x158 */ u8 unk_158[0x518 - 0x158];
    /* 0x518 */ u32 unk_518_0 : 8;
    /* 0x518 */ u32 unk_518_8 : 8;
    /* 0x518 */ u32 unk_518_16 : 8;
    /* 0x518 */ u32 unk_518_24 : 4;
    /* 0x518 */ u32 unk_518_28 : 4;
    /* 0x51c */ u8 buf[0xf0];
    /* 0x60c */ u32 slots[2];
    /* 0x614 */ u32 unk_614;
    /* 0x618 */ u32 unk_618;
    /* 0x61c */ u16 unk_61c;
    /* 0x61e */ u8 unk_61e[2];
    /* 0x620 */ union {
        u32 unk_620;
        struct {
            u32 unk_620_0 : 1;
            u32 unk_620_1 : 31;
        };
    };
    /* 0x624 */ u32 unk_624[5];
    /* 0x638 */ u8 unk_638;
    /* 0x639 */ u8 unk_639;
    /* 0x63a */ u8 unk_63a[2];
} StageFlags; // size 0x63c

extern StageFlags *data_0214a424;

#ifdef __cplusplus
}
#endif

#endif
