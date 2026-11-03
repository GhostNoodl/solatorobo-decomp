#include "ov000/HeapScope.h"
#include "ov000/Vec.h"
#include "ov000/ActorMarker.h"
#include "Main/Gfx/Model.h"

#define FX_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

struct Marker021bfa10 : ActorMarker {
    Model *unk_8c;
    Model *unk_90;
    Model *unk_94;
    s32 unk_98;
    s32 unk_9c;
    s32 unk_a0;
    s32 unk_a4;
};

extern "C" {

void *func_ov000_021bec38(ActorMarkerWork *work, void *src, void *out, u16 *count);
void TexObj_SetOamFunc(void *model, s32 a, void *cb, void *arg);

static inline BOOL Obj021bfa10_Wait(Marker021bfa10 *self) {
    if (!(self->show == 1 ? TRUE : FALSE) || (self->change == 1 ? TRUE : FALSE)) {
        return TRUE;
    }
    self->work.state = 10;
    return FALSE;
}

void func_ov000_021bfa10(Marker021bfa10 *self) {
    VecFx32 pos;
    switch (self->work.state) {
    case 5:
        HEAP_DELETE_MODEL(self->unk_8c);
        HEAP_DELETE_MODEL(self->unk_90);
        HEAP_DELETE_MODEL(self->unk_94);
        return;
    case 1:
        {
            Model *model = self->mdl[4];
            self->unk_90 = self->mdl[5];
            self->unk_94 = self->mdl[6];
            self->mdl[4] = NULL;
            self->unk_8c = model;
            self->mdl[5] = NULL;
            self->mdl[6] = NULL;
            self->unk_98 = 0;
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = self->unk_28[0];
            model->flags |= 0x200000;
            self->unk_8c->flags |= 0x80000;
            self->unk_90->flags |= 0x200000;
            self->unk_90->flags |= 0x80000;
            TexObj_SetOamFunc(self->unk_90, 2, (void *)func_ov000_021bec38, &self->work);
            self->unk_94->flags |= 0x200000;
            self->unk_94->flags |= 0x80000;
        }
        self->work.state = 4;
    case 4:
        self->work.fade = 0;
        self->work.alpha = 0;
        if (Obj021bfa10_Wait(self)) {
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
