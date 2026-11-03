#ifndef OV000_TEXTLIST_H
#define OV000_TEXTLIST_H

// The ov000 text list (vtable data_ov000_021ccadc, 0xd4 bytes). Its constructor stores the UiObj
// vtable and calls UiObj_Init, then stores data_ov000_021ccadc and calls func_ov000_021c6140,
// which clears the fields below; the dtors free them with Obj021c61a8_Release. The list shows one
// row at a time: left/right move to the previous or next row (func_ov000_021c67e4), sliding the
// old row out and the new one in over 15 frames, and A decides.
//
// Methods: slot 0x08 Ov000Vt_021ccadc_Setup (start), slot 0x54 func_ov000_021c6714 (update), slot 0x5c
// func_ov000_021c6b28 (places the rows and the cursor), slot 0x60 func_ov000_021c6d28 (draws the
// window); List021c6474_Append appends a row, func_ov000_021c65e0 selects the row with an index,
// Obj021c64b4_SetText sets the cursor text and func_ov000_021c6d64 draws the arrows beside the row.
// ov002 builds two (Task021ef69c_Start and the 021ef150 task).

#include "ov000/UiObj.h"
#include "ov000/ListRow.h"
#include "Main/Gfx/TextWin.h"

#ifdef __cplusplus

struct TextList;
typedef BOOL (*TextListFn)(TextList *self, ListRow *row);

typedef struct TextListFlags {
    u32 wrap : 1;       // moving past either end wraps around
    u32 showCursor : 1; // draw the panel and its text (set by the init)
    u32 raise : 1;      // lift counts up to 6 while set, down to 0 otherwise
    u32 unk_3 : 29;
} TextListFlags;

struct TextList : public UiObj {
    ListRow *rows;          // 0x84 first row (List021c6474_Append appends)
    ListRow *cur;           // 0x88 the row at index
    u8 decided;             // 0x8c set when A is pressed, cleared when the row changes
    s32 count;              // 0x90 rows
    s32 index;              // 0x94 shown row
    s32 prevIndex;          // 0x98 row sliding out while timer runs
    UiPanel *panel;         // 0x9c the cursor panel (built by slot 0x08)
    TextWin *panelText;     // 0xa0 the text centred on the panel (Obj021c64b4_SetText)
    s32 panelWidth;         // 0xa4 pixels (0xd2 after the init)
    s32 panelY;             // 0xa8 pixels below the list position (0x18)
    s32 bounceTime;         // 0xac 0..59, one step per update while shown
    s32 bounce;             // 0xb0 sine of bounceTime: how far out the arrows are drawn
    s32 rowWidth;           // 0xb4 width of the current row (ListRow::width)
    s32 dir;                // 0xb8 the last move (-1 or 1), handed to the rows
    s32 timer;              // 0xbc frames left of the slide (15 after a move)
    s32 lift;               // 0xc0 0..6: the window is drawn 8 pixels higher per step
    union {
        u32 unk_c4;
        TextListFlags listFlags; // 0xc4
    };
    TextListFn onDecide;    // 0xc8 called with the current row when A is pressed (the return value is not used)
    TextListFn onCursor;    // 0xcc called with the new row after a move
    s32 unk_d0;
};
SIZE_ASSERT(TextList, 0xd4);

#endif

#endif
