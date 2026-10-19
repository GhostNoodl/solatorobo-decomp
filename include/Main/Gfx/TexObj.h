#ifndef MAIN_GFX_TEXOBJ_H
#define MAIN_GFX_TEXOBJ_H

#include "types.h"
#include "Main/Gfx/PlttRes.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct TexObjEntry {
    /* 0x00 */ u16 index;
    /* 0x04 */ void *anim;
    /* 0x08 */ int unk_08;
    /* 0x0c */ int unk_0c;
    /* 0x10 */ u32 transfers[3];
    /* 0x1c */ int key;
    /* 0x20 */ int slot0;
    /* 0x24 */ int slot1;
} TexObjEntry; // size 0x28

typedef struct TexObjVec {
    int v[4];
} TexObjVec;

typedef struct TexObjPair {
    int a;
    int b;
} TexObjPair;

typedef struct TexObj {
    /* 0x000 */ u8 unk_000[0xc];
    /* 0x00c */ int unk_00c;
    /* 0x010 */ int unk_010;
    /* 0x014 */ int unk_014;
    /* 0x018 */ int unk_018;
    /* 0x01c */ int unk_01c;
    /* 0x020 */ int unk_020;
    /* 0x024 */ u8 owned;
    /* 0x028 */ void *res;
    /* 0x02c */ char arcName[0x20];
    /* 0x04c */ char name[0x20];
    /* 0x06c */ u32 unk_06c;
    /* 0x070 */ int unk_070;
    /* 0x074 */ int unk_074;
    /* 0x078 */ TexObjEntry *entries;
    /* 0x07c */ int unk_07c;
    /* 0x080 */ int count;
    /* 0x084 */ u8 unk_084;
    /* 0x085 */ u8 unk_085;
    /* 0x088 */ PlttRes pltt;
    /* 0x0ec */ PlttRes *plttPtr;
    /* 0x0f0 */ u8 unk_0f0[8];
    /* 0x0f8 */ u32 texKey;
    /* 0x0fc */ TexObjPair pairs[3];
    /* 0x114 */ TexObjVec vecs[3];
    /* 0x144 */ int unk_144;
    /* 0x148 */ int unk_148;
    /* 0x14c */ int unk_14c;
    /* 0x150 */ int unk_150;
    /* 0x154 */ u16 unk_154;
    /* 0x158 */ int unk_158;
    /* 0x15c */ int unk_15c;
} TexObj;

#ifdef __cplusplus
}
#endif

#endif
