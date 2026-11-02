#ifndef OV000_MSGBOX_H
#define OV000_MSGBOX_H

#include "types.h"
#include "Main/Gfx/SlideWin.h"
#include "Main/Res/MsgRes.h"

// Message box (0x2c bytes): opens one message of a message archive (MsgRes) and shows it in a
// SlideWin. func_ov000_02163224 is its ctor (the vtable is set by the overlay that allocates it,
// e.g. data_ov006_021ebc70), func_ov000_021632f0 selects the message, func_ov000_021633ac steps
// it (load, show, fade) and returns FALSE once it is done, func_ov000_02163254 frees it.
typedef struct MsgBox {
    /* 0x00 */ void *vtbl;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char *arcName; // MsgRes::Open arguments
    /* 0x0c */ char *name;
    /* 0x10 */ u8 unk_10;     // copied to SlideWin::unk_bc_7
    /* 0x14 */ s32 msgId;     // message index (func_0204c08c)
    /* 0x18 */ s32 numLines;  // func_0204c08c result
    /* 0x1c */ char *text;    // func_0204c08c out
    /* 0x20 */ SlideWin *win;
    /* 0x24 */ MsgRes *res;
    /* 0x28 */ s32 state;     // 0..3 steps, 4 idle
} MsgBox; // size 0x2c

#ifdef __cplusplus
extern "C" {
#endif

void func_ov000_02163224(MsgBox *self);
void func_ov000_02163254(MsgBox *self);
void func_ov000_021632f0(MsgBox *self, s32 msgId, char *arcName, char *name, u8 a4);
BOOL func_ov000_021633ac(MsgBox *self);
void func_ov000_02163594(MsgBox *self);

#ifdef __cplusplus
}
#endif

#endif
