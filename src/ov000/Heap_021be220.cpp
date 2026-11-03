#include "ov000/HeapScope.h"
#include "ov000/Vec.h"
#include "ov000/ActorMarker.h"

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

struct Marker021be220 : ActorMarker {
    void *unk_8c;
    s32 unk_90;
    s32 unk_94;
    s32 unk_98;
};

extern "C" {

void *func_ov000_021be1a8(ActorMarkerWork *work, void *src, void *out, u16 *count);
void TexObj_SetOamFunc(void *model, s32 a, void *cb, void *arg);

static inline BOOL Obj021be220_Wait(Marker021be220 *self) {
    if (!(self->show == 1 ? TRUE : FALSE) || (self->change == 1 ? TRUE : FALSE)) {
        return TRUE;
    }
    self->work.state = 10;
    return FALSE;
}

void ActorMarker_UpdateKind00(Marker021be220 *self) {
    VecFx32 pos;
    switch (self->work.state) {
    case 5:
        HEAP_DELETE_MODEL(self->unk_8c);
        return;
    case 1:
        {
            void *model = self->mdl[4];
            self->mdl[4] = NULL;
            self->unk_8c = model;
            self->unk_90 = 0;
            self->unk_94 = 0;
            self->unk_98 = self->unk_28[0];
            TexObj_SetOamFunc(model, 3, (void *)func_ov000_021be1a8, &self->work);
        }
        self->work.state = 4;
    case 4:
        self->work.fade = 0;
        self->work.alpha = 0;
        if (Obj021be220_Wait(self)) {
            return;
        }
    case 10:
        if (ActorMarker_UpdateFade(self, 0x8000)) {
            return;
        }
        if (++self->unk_90 < 0x12) {
            self->unk_94 += FX_MUL(0x3000 - self->unk_94, 0x19a);
        } else if (self->unk_90 >= 0x30) {
            self->unk_90 = 0;
            self->unk_94 = 0;
        } else {
            self->unk_94 += FX_MUL(-self->unk_94, 0xcd);
        }
        pos = self->unk_50;
        ActorMarker_UpdateScreenPos(self, &pos);
        self->work.z = -0x1ccd;
        break;
    case 0:
    case 2:
    case 3:
    case 6:
    case 7:
    case 8:
    case 9:
        break;
    }
}

}
