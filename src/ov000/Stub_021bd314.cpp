#include "ov000/VObj.h"
#include "ov000/ActorMarker.h"

extern "C" {

s32 FX_Div(s32 a, s32 b);
extern const s16 FX_SinCosTable_[];

BOOL ActorMarker_SetKind(ActorMarker *self, s32 x) {
    if (self->nextKind == x) {
        return TRUE;
    }
    if ((u32)(self->step - 7) <= 2) {
        func_ov000_021bd7b8(self);
    }
    if (self->kind == x) {
        return TRUE;
    }
    self->step = 7;
    self->nextKind = x;
    self->flags |= 8;
    return TRUE;
}

BOOL ActorMarker_UpdateFade(ActorMarker *self, s32 len) {
    s32 v;
    if (!(self->show == 1 ? TRUE : FALSE) || (self->change == 1 ? TRUE : FALSE)) {
        self->work.fade -= 0x1000;
    } else {
        self->work.fade += 0x1000;
    }
    v = FX_Div(self->work.fade, len);
    if (v >= 0x1000) {
        self->work.fade = len;
        v = 0x1000;
    } else if (v <= 0) {
        self->work.fade = 0;
        self->work.state = 4;
        return TRUE;
    }
    self->work.alpha = FX_SinCosTable_[((v << 14) >> 16) * 2];
    return FALSE;
}

}
