#include "ov000/HeapScope.h"
#include "ov000/Vec.h"
#include "ov000/ActorMarker.h"
#include "Main/Gfx/Model.h"

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

struct Marker021bf308 : ActorMarker {
    Model *unk_8c;
    s32 unk_90;
    s32 unk_94;
    s32 unk_98;
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
};

extern "C" {

static inline BOOL Obj021bf308_Wait(Marker021bf308 *self) {
    if (!(self->show == 1 ? TRUE : FALSE) || (self->change == 1 ? TRUE : FALSE)) {
        return TRUE;
    }
    self->work.state = 10;
    return FALSE;
}

void func_ov000_021bf308(Marker021bf308 *self) {
    VecFx32 pos;
    switch (self->work.state) {
    case 5:
        HEAP_DELETE_MODEL(self->unk_8c);
        return;
    case 1:
        {
            Model *model = self->mdl[4];
            self->mdl[4] = NULL;
            self->unk_a4 = self->unk_28[0];
            self->unk_8c = model;
            self->unk_90 = 0;
            self->unk_98 = 0;
            self->unk_9c = 0;
            self->unk_a0 = 0;
            model->flags |= 0x200000;
            self->unk_8c->flags |= 0x80000;
        }
        self->work.state = 4;
    case 4:
        self->work.fade = 0;
        self->work.alpha = 0;
        if (Obj021bf308_Wait(self)) {
            return;
        }
    case 10:
        if (ActorMarker_UpdateFade(self, 0x6000)) {
            return;
        }
        if (++self->unk_98 < 0x12) {
            self->unk_a0 += FX_MUL(0x3000 - self->unk_a0, 0x19a);
        } else if (self->unk_98 >= 0x30) {
            self->unk_98 = 0;
            self->unk_a0 = 0;
        } else {
            self->unk_a0 += FX_MUL(-self->unk_a0, 0xcd);
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
