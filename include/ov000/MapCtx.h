#ifndef OV000_MAPCTX_H
#define OV000_MAPCTX_H

// The map screen's work area (an object's unk_30 in Lo_02165f94.cpp and Lo_02166be8.cpp), its
// area nodes and their items (round svG; the layout is round mtA's, from its typed draft of
// func_ov000_02166180). Lo021cb6b0_BuildMap allocates it (0xce0 bytes, high heap) and builds a node
// per area (func_ov000_021652e4) with its OAM entries, parts and items taken from the pools here.

#include "types.h"

struct PlttRes;

// An OAM entry of the map (attribute words 0/1 and 2/3).
typedef struct MapOam {
    union {
        u32 raw;
        struct {
            u32 y : 8;
            u32 a0 : 8;
            u32 x : 9;
            u32 a1 : 3;
            u32 hf : 1;
            u32 vf : 1;
            u32 sz : 2;
        };
    } w0;
    union {
        u32 raw;
        struct {
            u32 tile : 10;
            u32 prio : 2;
            u32 pal : 4;
            u32 hi : 16;
        };
    } w1;
} MapOam;

typedef struct MapPos {
    s32 x;
    s32 y;
} MapPos;

// A part of a node (0x14 bytes, the pool at Ctx0216607c::parts): one OAM entry and its position.
typedef struct MapPart {
    MapPos *pos;
    MapOam *oam;
    s32 x;
    s32 y;
    u8 c[4];
} MapPart;

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Item0216607c Item0216607c;

// An area node (0x1c bytes, the array at Ctx0216607c::nodes).
typedef struct Node0216607c {
    union {
        u32 flags; // the first word of the area's definition
        struct {
            u32 f0 : 1;
            u32 f1 : 1;
            u32 f2 : 1;
            u32 f3 : 1;
            u32 f4 : 1;
            u32 a : 8;
            u32 b : 8;
        };
    };
    u16 unk_04;
    u8 w; // size in 8-pixel cells
    u8 h;
    u8 slot;
    u8 n; // OAM entries (oam / pos)
    u8 nPart;
    u8 count; // items
    MapPos *pos;
    MapOam *oam;
    MapPart *parts;
    Item0216607c *items;
} Node0216607c;

// One item of a node (0x18 bytes): its node, map position and kind.
struct Item0216607c {
    Node0216607c *node;
    s32 lo; // the player's y range the item covers (Lo021cb6b0_FindFloor)
    s32 hi;
    s32 a; // map position
    s32 b;
    u8 key;
    u8 pad_15[3];
};

typedef struct {
    u32 unk_00;
    Item0216607c **list;
} Slot0216607c;

// The busy-list header at Ctx0216607c::anim (Lo021cb6b0_HandleInput cycles its colour): a path of
// up to 0x20 nodes.
typedef struct LoAnimC {
    u8 rgb[4];
    u8 pad[0x84];
    Node0216607c *frames[0x20];
    u8 cnt;
    u8 key; // the item key the path follows (Lo021cb6b0_FindFloor)
    u16 state;
    u16 idx;
    u16 timer;
    u16 period;
} LoAnimC;

typedef struct Ctx0216607c {
    /* 0x000 */ u8 unk_00;
    /* 0x001 */ u8 oamUsed; // of oams / poss
    /* 0x002 */ u8 markCount; // marks used (Lo021cb6b0_DrawMarkers)
    /* 0x003 */ u8 pad_03;
    /* 0x004 */ u16 unk_04; // area id
    /* 0x006 */ u8 partUsed;
    /* 0x007 */ u8 itemUsed;
    /* 0x008 */ u8 count; // nodes
    /* 0x009 */ u8 slotCount;
    /* 0x00a */ u8 pad_0a[2];
    /* 0x00c */ MapOam unk_0c; // cell 3
    /* 0x014 */ MapOam unk_14; // cell 0xc
    /* 0x01c */ MapOam unk_1c; // cell 0xb
    /* 0x024 */ u16 tiles[3]; // cells 0xc..0xe
    /* 0x02a */ u8 pad_2a[2];
    /* 0x02c */ MapOam oams[0xc4]; // oams[0] is the cell 2 template
    /* 0x64c */ MapOam marks[2]; // target marks, drawn when unk_cd8 > 0x800
    /* 0x65c */ MapPos poss[0xc4];
    /* 0xc7c */ MapPart *parts;
    /* 0xc80 */ Item0216607c *items;
    /* 0xc84 */ Node0216607c *nodes;
    /* 0xc88 */ Slot0216607c *slots;
    /* 0xc8c */ struct PlttRes *pltt;
    /* 0xc90 */ s8 *palMap; // the model's extended palette map (+0x58)
    /* 0xc94 */ u16 unk_c94[2];
    /* 0xc98 */ u8 pad_c98[0x1c];
    /* 0xcb4 */ Item0216607c *cur;
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
