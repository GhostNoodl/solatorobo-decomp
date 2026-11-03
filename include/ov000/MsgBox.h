#ifndef OV000_MSGBOX_H
#define OV000_MSGBOX_H

#include "types.h"
#include "Main/Gfx/SlideWin.h"
#include "Main/Res/MsgRes.h"

// Message box (0x2c bytes): opens one message of a message archive (MsgRes) and shows it in a
// SlideWin. MsgBox_Init is its ctor (the vtable is set by the overlay that allocates it,
// e.g. ov006_MsgBox_vtbl), MsgBox_Open selects the message, MsgBox_Update steps
// it (load, show, fade) and returns FALSE once it is done, MsgBox_Release frees it.
typedef struct MsgBox {
    /* 0x00 */ void *vtbl;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char *arcName; // MsgRes::Open arguments
    /* 0x0c */ char *name;
    /* 0x10 */ u8 unk_10;     // copied to SlideWin::unk_bc_7
    /* 0x14 */ s32 msgId;     // message index (MsgRes_GetLines)
    /* 0x18 */ s32 numLines;  // MsgRes_GetLines result
    /* 0x1c */ char *text;    // MsgRes_GetLines out
    /* 0x20 */ SlideWin *win;
    /* 0x24 */ MsgRes *res;
    /* 0x28 */ s32 state;     // 0..3 steps, 4 idle
} MsgBox; // size 0x2c

#ifdef __cplusplus
extern "C" {
#endif

void MsgBox_Init(MsgBox *self);
void MsgBox_Release(MsgBox *self);
void MsgBox_Open(MsgBox *self, s32 msgId, char *arcName, char *name, u8 a4);
BOOL MsgBox_Update(MsgBox *self);
void MsgBox_Render(MsgBox *self);

#ifdef __cplusplus
}
#endif

#endif
