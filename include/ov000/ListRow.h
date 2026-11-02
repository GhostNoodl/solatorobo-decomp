#ifndef OV000_LISTROW_H
#define OV000_LISTROW_H

// The rows of the ov000 row list (LoBase021ccb54_021ccbe0::rows in ov000/ObjLayouts.h).
//
// The row base has vtable data_ov000_021cbac8 (ov002 builds its rows over its own copy,
// data_ov002_021ef684). Each subclass constructor stores the base vtable, calls
// ListRow_Init (which clears the base fields), then stores its own vtable and calls its own
// init. The dtor (ListRow_Unlink inlined) unlinks the row. LoBase021ccb54_021ccbe0_AppendRow appends a row to
// a list, func_ov000_021c4014 finds one by index, and func_ov000_021c5028 places and draws the shown
// rows one below the other. Slot 0x08 of a subclass updates the row, slot 0x0c draws it.

#include "types.h"
#include "ov000/VObj.h"

struct Model;
struct TextWin;
struct Lo021cb3a8;
struct ObjBase021cac0c_021cb6f0;

#ifdef __cplusplus

// 0x30 bytes.
struct ListRow : public VObj {
    s32 index; // 0x04 set by the creator; func_ov000_021c4014 looks a row up by it
    u8 unk_08[0x4];
    s32 x; // 0x0c draw position (fx32), set by func_ov000_021c5028 before the draw slot
    s32 y;
    s32 z;
    s32 height; // 0x18 pixels down to the next row (func_ov000_021c5028)
    s32 width; // 0x1c the window width of the text row (func_ov000_021c37f0)
    union {
        u8 unk_20;
        struct {
            u8 shown : 1; // cleared while the row is scrolled out of the list
            u8 unk_20_1 : 1;
            u8 unk_20_2 : 6;
        };
    };
    s32 unk_24;
    ListRow *next; // 0x28
    ListRow *prev; // 0x2c
};

// Vtable data_ov000_021cca10 (0x48 bytes, init func_ov000_021c2334, release Hud021cca10_Release):
// two 2D models and a name text (Hud021cca10_SetText sets it), built by slot 0x08 (func_ov000_021c2450)
// and drawn by slot 0x0c (func_ov000_021c28cc).
struct Hud021cca10 : public ListRow {
    Model *unk_30;
    Model *unk_34;
    TextWin *text; // 0x38
    s32 unk_3c; // passed to the first model (func_02041c20)
    char *str; // 0x40 the text shown in text
    u8 built; // 0x44 set once slot 0x08 has made the models
    u8 unk_45[0x3];
};

// Vtable data_ov000_021cc9f8 (0x44 bytes, init func_ov000_021c2bb0): a bar display and a label
// (func_ov000_021c2c0c), built by slot 0x08 (func_ov000_021c2d48) and drawn by slot 0x0c
// (func_ov000_021c2e64). The bar shows value out of max (ov002's level list, Task021ef99c_Start, sets
// value to level * 100 + the percent of the way to the next threshold and max to 300).
struct ListRowGauge : public ListRow {
    ObjBase021cac0c_021cb6f0 *bar; // 0x30 (vtable data_ov000_021cca88)
    TextWin *label; // 0x34
    s32 max; // 0x38
    s32 value; // 0x3c
    u8 built; // 0x40 set once slot 0x08 has made the bar
    u8 unk_41[0x3];
};

// Vtable data_ov000_021cca58 (0x44 bytes, init func_ov000_021c37bc): slot 0x08 (func_ov000_021c37f0)
// opens a list window over the two strings while the row is shown, slot 0x0c
// (func_ov000_021c3aa0) moves it with the row.
struct ListRowText : public ListRow {
    Lo021cb3a8 *win; // 0x30
    char *unk_34; // the window's srcStr
    char *unk_38; // handed to Lo021cb3a8_SetText
    s32 state; // 0x3c
    u16 unk_40; // id of the item selected when the window opens
    u8 unk_42[0x2];
};

// The item shown by a ListRow021cca70 (filled by func_ov000_021c308c from the item id).
typedef struct ListRowItem {
    u8 unk_00[0x4];
    u16 id; // 0x04
    u16 mask; // 0x06 one bit per part; a set bit draws the part with the first model
    u8 count; // 0x08 set bits of mask below n
    u8 n; // 0x09 parts (4)
    u8 unk_0a; // DataRes_ReadBitsById_02059688 found the id in save block 11
    u8 unk_0b;
} ListRowItem;

// Vtable data_ov000_021cca70 (0x7c bytes, init func_ov000_021c2f10, release ListRow021cca70_Release): an
// item drawn as n parts with two models, loaded by slot 0x08 (func_ov000_021c3158) and drawn by slot 0x0c
// (func_ov000_021c34cc).
struct ListRow021cca70 : public ListRow {
    char *arc; // 0x30 the models' archive and file (func_ov000_021c308c)
    char *name; // 0x34
    Model *unk_38; // the part model for a set bit of item.mask
    Model *unk_3c; // and for a clear bit
    void *unk_40; // the row's text (ov002 Task021ef69c_Start: Param_Get(id))
    s32 unk_44;
    ListRowItem item; // 0x48
    u8 alpha; // 0x54
    s32 scale; // 0x58 fx32
    s32 ox; // 0x5c offset of the parts from the row position
    s32 oy;
    s32 partZ; // 0x64 the parts' depth
    s32 unk_68; // load state of slot 0x08
    u8 unk_6c;
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
};

#endif

#endif
