#include "Main/Sys/Pad.h"
#include "Main/Gfx/SlidePanel.h"

typedef struct {
    u8 pad_00[4];
    s32 unk_04;
    u8 pad_08[4];
    u32 unk_0c_0 : 1;
    u32 unk_0c_1 : 1;
    u32 unk_0c_2 : 30;
} Inner02180350;

typedef struct {
    u8 pad_00[0xc];
    u32 unk_0c;
} Sub02180350;

typedef struct {
    u8 pad_00[0x3c];
    Sub02180350 *unk_3c;
    u8 pad_40[4];
    Inner02180350 *unk_44;
    u8 pad_48[0x16];
    u8 unk_5e;
} Obj02180350;

extern "C" {

void func_ov000_02180350(Obj02180350 *self) {
    Inner02180350 *in = self->unk_44;
    u16 trig = data_02097dc8->trig;
    BOOL ok = FALSE;
    if (in->unk_0c_1 ? TRUE : FALSE) {
        if (in->unk_04 == 5 ? TRUE : FALSE) {
            ok = TRUE;
        }
    }
    if (!ok) {
        self->unk_3c->unk_0c |= 4;
        return;
    }
    self->unk_3c->unk_0c &= ~4;
    if (self->unk_5e != 0) {
        return;
    }
    if (trig & 2) {
        func_02049a48(data_02097e4c, 0x20, -1, -1, -1);
    }
}

}
