#ifndef OV000_UIOBJ_H
#define OV000_UIOBJ_H

#include "ov000/VObj.h"
#include "nitro/fx.h"

#ifdef __cplusplus

struct Model;
struct TextWin;
struct UiObj;
struct UiList;
struct UiListItem;
struct UiPanel;

typedef void (*UiStateFn)(UiObj *self);
typedef BOOL (*UiDrawFn)(UiObj *self, s32 id, VecFx32 *pos, s32 extra);
typedef void (*UiDrawItemFn)(void *arg, UiObj *self, void *arg2);
typedef BOOL (*UiItemFn)(UiList *self, UiListItem *item);

// ov000 UI object: windows, labels, number displays, list menus and dialogs (base vtable
// data_ov000_021cac60, 0x84 bytes). Every subclass constructor stores this vtable and calls
// slot 0x28 (UiObj_Init, which sets the defaults below), then its own vtable and slot 0x28.
// The overlays see the same object as Ov015Ui, ov006_Window, Ov008Menu and Ov007Player.
struct UiObj : public VObj {
    s32 state;          // 0x04 UiObj_Update: 0 open, 3 opening, 2 shown, 1 close, 4 closing, 5 closed
    void *owner;        // 0x08 read back by the callbacks
    union {
        u32 flags;      // 0x0c
        struct {
            u32 busy : 1;       // set while opening/closing
            u32 hidden : 1;     // stay closed (state 5) until cleared
            u32 flag2 : 1;
            u32 flag3 : 1;
            u32 flag4 : 1;
            u32 flag5 : 1;
            u32 flag6 : 1;
            u32 fade : 2;       // 7..8: 1 fading in, 2 shown, 3 fading out (fadeTime/fadeLen)
            u32 flag9 : 1;
            u32 flag10 : 1;
            u32 flag11 : 1;
            u32 flag12 : 1;
            u32 flag13 : 1;
            u32 flag14 : 1;
            u32 flag15 : 1;
            u32 flag16 : 1;
            u32 flag17 : 1;
            u32 flag18 : 1;
            u32 flag19 : 1;
            u32 flag20 : 1;
            u32 flag21 : 1;
            u32 flag22 : 1;
            u32 flag23 : 1;
            u32 flag24 : 1;
            u32 flag25 : 1;
            u32 flag26 : 1;
            u32 flag27 : 1;
            u32 flag28 : 1;
            u32 flag29 : 1;
            u32 flag30 : 1;
            u32 flag31 : 1;
        };
    };
    Model *model;       // 0x10 freed with LO_FREE_M
    TextWin *title;     // 0x14 TextWin (vtable data_0208ba70); slot 0x10 (UiObj_SetTitle) builds it from a string, font 8
    TextWin *caption;   // 0x18 TextWin; slot 0x14 (UiObj_SetCaption): one line, font 4, scrolled by scrollPos
    s32 font;           // 0x1c copied to data_02097ce0->unk_004
    s32 rows;           // 0x20
    s32 width;          // 0x24 G3 frame x scale (func_ov000_02153804)
    s32 height;         // 0x28 G3 frame y scale
    s32 slideMode;      // 0x2c UiObj_GetSlide: 1 scales slideX/Y by 1 - sin(openRatio)
    s32 openTime;       // 0x30 +-0x1000 per frame while opening/closing
    s32 openLen;        // 0x34
    s32 openRatio;      // 0x38 openTime / openLen
    s32 fadeTime;       // 0x3c the same for the fade bits of flags
    s32 fadeLen;        // 0x40
    s32 fadeRatio;      // 0x44
    u16 color;          // 0x48 frame colour (RGB555, halved for the G3 colour)
    s16 unk_4a;
    s32 scrollPos;      // 0x4c advanced by 0x666 per frame, wraps at scrollLen
    s32 scrollLen;      // 0x50 caption width + 0x40
    s32 unk_54;
    s32 slideX;         // 0x58
    s32 slideY;
    s32 slideZ;
    s16 posX;           // 0x64 screen position
    s16 posY;
    s16 posZ;
    VecFx16 *shape;     // 0x6c frame outline points (NULL: the default frame)
    s32 shapeCount;     // 0x70
    VObj *child;        // 0x74 ticked and drawn with the window, freed when its slot 0x1c returns FALSE
    UiStateFn onState;  // 0x78 called on each open/close state change
    UiDrawFn onDraw;    // 0x7c draw filter (UiObj_Draw)
    UiDrawItemFn onDrawItem; // 0x80 called by slot 0x48 (UiObj_DrawItem; Ov008Menu sets it)
};

// List entry (0x30 bytes, UiList_AddItem).
struct UiListItem {
    const char *name;   // 0x00
    s16 index;          // 0x04 position in the list
    u16 id;             // 0x06
    u16 unk_08;
    u16 unk_0a;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    VObj *label;        // 0x1c TextWin of the name (Obj02153c48_CreateText)
    VObj *unk_20;
    u32 unk_24;
    UiListItem *prev;   // 0x28
    UiListItem *next;   // 0x2c
};

// Highlight panel of a list (0x2c bytes, built by the list subclasses, freed by UiList_Release).
struct UiPanel {
    union {
        u32 flags;
        struct {
            u32 b0 : 1;
            u32 b1 : 2;     // set by func_ov000_021548cc
            u32 b3 : 1;
            u32 rest : 28;
        } bits;
    };
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;         // 0x80000
    s32 unk_14;         // 0xf000
    s32 unk_18;         // x offset
    s32 unk_1c;         // y offset
    s32 unk_20;
    s32 unk_24;
    Model *model;       // 0x28 freed with LO_FREE_M
};

// A text label in a frame (0x2c bytes): reset by func_ov000_0215f514, released by
// UiLabel_Release, built by UiLabel_SetText (the frame model and the text window) and
// drawn by UiLabel_Draw, which centres the text in width x height.
struct UiLabel {
    union {
        u32 flags;
        struct {
            u32 centered : 1; // x is the centre (UiLabel_Draw)
            u32 b1 : 3;
            u32 altFrame : 1; // the frame comes from the second archive (UiLabel_SetText)
            u32 rest : 27;
        } bits;
    };
    s32 style;          // 0x04 index into data_02fe0188
    s32 x;              // 0x08 screen position
    s32 y;
    s32 z;
    s32 width;          // 0x14 text width + 0x10 once built
    s32 height;         // 0x18 from the style
    s32 unk_1c;
    s32 unk_20;
    TextWin *text;      // 0x24
    Model *model;       // 0x28 the frame
};

// The label styles (data_02fe0188, 0x18 bytes each).
typedef struct UiLabelStyle {
    u16 part;           // frame model part
    u16 color0;         // gradient colours of the frame (func_ov000_0215f618)
    u16 color1;
    u8 unk_06[0x6];
    s32 height;         // fx32
    s32 ofsX;           // fx32 inset of the frame
    s32 ofsY;
} UiLabelStyle;

// List menu (vtable data_ov000_021caec8, 0xd4 bytes, slot 0x28 UiList_Init).
struct UiList : public UiObj {
    UiItemFn onDecide;  // 0x84 slot 0x98
    UiItemFn onCursor;  // 0x88 slot 0x9c
    UiItemFn unk_8c;
    UiItemFn unk_90;    // 0x90 slot 0x50 calls it once with the current item
    UiListItem *items;  // 0x94
    UiListItem *topItem; // 0x98 first shown item
    s16 itemCount;      // 0x9c
    s16 unk_9e;
    s16 unk_a0;
    s16 unk_a2;
    void *unk_a4;
    void *unk_a8;
    UiPanel *panel;     // 0xac
    s8 unk_b0;
    s8 cursor;          // 0xb1 row of the current item below topItem
    s8 unk_b2;
    s8 unk_b3;
    Model *unk_b4;
    Model *unk_b8;      // 0xb8 func_ov000_021546ec
    Model *unk_bc;      // 0xbc func_ov000_021547e8
    u8 unk_c0;
    s8 unk_c1;          // 0xc1 row height / 8 (func_ov000_02151fd8)
    s8 unk_c2;
    s8 unk_c3;
    s32 unk_c4;
    s32 unk_c8;
    s32 unk_cc;
    s32 unk_d0;
};

// List subclass (vtable data_ov000_021cb4a8, 0xe0 bytes); data_ov000_021cb2a8 (0xe0), data_ov000_021caac8
// (0xe4) and data_ov000_021cb3a8 (0xf0) derive from it.
struct UiList021cb4a8 : public UiList {
    UiLabel *unk_d4;    // UiList021cb4a8_SetLabel
    UiLabel *unk_d8;    // UiList021cb4a8_SetCenteredLabel
    u8 unk_dc;          // func_ov000_021520a4: row height - 0x12
    u8 unk_dd[0x3];
};

static inline UiListItem *UiList_GetCurrent(UiList *self) {
    UiListItem *item = self->topItem;
    s32 n;
    if (item == NULL) {
        return NULL;
    }
    n = self->cursor;
    while (n-- != 0) {
        item = item->next;
    }
    return item;
}

static inline void UiLabel_Reset(UiLabel *self) {
    self->flags = 0;
    self->style = 0;
    self->x = 0;
    self->y = 0;
    self->z = 0;
    self->width = 0x80;
    self->height = 6;
    self->text = NULL;
    self->model = NULL;
}

extern "C" {
void UiLabel_SetText(UiLabel *self, u32 text);
void UiLabel_Draw(UiLabel *self);
void func_ov000_0215f514(UiLabel *self);
void UiLabel_Release(UiLabel *self);
void func_ov000_0215f618(UiLabel *self, s32 *pos);
}

#endif

#endif
