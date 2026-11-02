#ifndef OV000_MAPCTX_H
#define OV000_MAPCTX_H

// The map screen's work area (an object's unk_30 in Lo_02165f94.cpp and Lo_02166be8.cpp), its
// area nodes and their items (round svG; the layout is round mtA's, from its typed draft of
// func_ov000_02166180).

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Item0216607c Item0216607c;

// An area node (0x1c bytes, the array at Ctx0216607c::nodes).
typedef struct Node0216607c {
    u32 f0 : 1;
    u32 f1 : 1;
    u32 f2 : 1;
    u32 f3 : 1;
    u32 f4 : 1;
    u32 a : 8;
    u32 b : 8;
    u8 pad_04[0x7];
    u8 count;
    u8 pad_0c[0xc];
    Item0216607c *items;
} Node0216607c;

// One item of a node (0x18 bytes): its node, map position and kind.
struct Item0216607c {
    Node0216607c *node;
    u8 pad_04[8];
    s32 a;
    s32 b;
    u8 key;
    u8 pad_15[3];
};

typedef struct {
    u32 unk_00;
    Item0216607c **list;
} Slot0216607c;

// The busy-list header at Ctx0216607c::anim (func_ov000_02165f94 cycles its colour).
typedef struct LoAnimC {
    u8 rgb[4];
    u8 pad[0x84];
    u8 *frames[0x20];
    u8 cnt;
    u8 pad2;
    u16 state;
    u16 idx;
    u16 timer;
    u16 period;
} LoAnimC;

typedef struct {
    u8 unk_00;
    u8 pad_01[3];
    u16 unk_04; // area id
    u8 pad_06[2];
    u8 count;
    u8 pad_09[0xc7b];
    Node0216607c *nodes;
    Slot0216607c *slots;
    u8 pad_c8c[0x28];
    Item0216607c *cur;
    Node0216607c *sel;
    s32 ox;
    s32 oy;
    s32 unk_cc4;
    s32 unk_cc8;
    s32 unk_ccc;
    s32 unk_cd0;
    s32 unk_cd4;
    s32 unk_cd8;
    LoAnimC *anim;
} Ctx0216607c;

#ifdef __cplusplus
}
#endif

#endif
