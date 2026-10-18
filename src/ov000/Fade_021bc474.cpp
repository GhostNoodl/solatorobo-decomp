#include "ov000/HeapScope.h"
#include "ov000/VObj.h"

typedef struct {
    u32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    VObj *unk_10;
    void *unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
} Fade021bc474;

extern "C" {
extern s32 data_02097d78[];
s32 FX_Div(s32 a, s32 b);

static inline BOOL Fade021bc474_Idle(void) {
    BOOL r;
    if (data_02097d78[3] == 0 && data_02097d78[0] == 0) {
        r = TRUE;
    } else {
        r = FALSE;
    }
    return r;
}

static inline BOOL Fade021bc474_Busy(void) {
    if (data_02097d78[3] == 4) {
        return TRUE;
    }
    return data_02097d78[0] == 4 ? TRUE : FALSE;
}

BOOL func_ov000_021bc474(Fade021bc474 *self) {
    switch (self->unk_04) {
    case 1:
        if (Fade021bc474_Idle()) {
            self->unk_20 += 0x1000;
        } else {
            self->unk_20 = self->unk_24;
        }
        self->unk_28 = FX_Div(self->unk_20, self->unk_24);
        if (self->unk_20 >= self->unk_24) {
            self->unk_20 = self->unk_24;
            self->unk_28 = 0x1000;
            self->unk_00 |= 2;
        }
        break;
    case 2:
        if (Fade021bc474_Idle()) {
            self->unk_20 -= 0x1000;
        } else if (Fade021bc474_Busy()) {
            self->unk_20 = 0;
        }
        self->unk_28 = FX_Div(self->unk_20, self->unk_24);
        if (self->unk_20 <= 0) {
            HEAP_DELETE_VOBJ(self->unk_10);
            HEAP_DELETE_MODEL(self->unk_14);
            self->unk_00 = 0;
            self->unk_04 = 0;
            self->unk_08 = 0;
            self->unk_0c = 0;
            self->unk_10 = 0;
            self->unk_14 = 0;
            self->unk_18 = 0;
            self->unk_1c = 0;
            self->unk_20 = 0;
            self->unk_24 = 0;
            self->unk_28 = 0;
            return FALSE;
        }
        break;
    }
    return TRUE;
}
}
