#include "ov000/HeapScope.h"
#include "nitro/mi.h"
#include "ov000/ActorMarker.h"
#include "Main/Gfx/Model.h"

struct Marker021c0560 : ActorMarker {
    Model *unk_8c;
    Model *unk_90;
    s32 unk_94;
};

extern "C" {

void *ActorMarker_OamCallback08(ActorMarkerWork *work, void *src, void *out, u16 *count);
void TexObj_SetOamFunc(void *model, s32 a, void *cb, void *arg);

static inline BOOL Obj021c0560_Wait(Marker021c0560 *self) {
    if (!(self->show == 1 ? TRUE : FALSE) || (self->change == 1 ? TRUE : FALSE)) {
        return TRUE;
    }
    self->work.state = 10;
    return FALSE;
}

void ActorMarker_UpdateKind08(Marker021c0560 *self) {
    switch (self->work.state) {
    case 5:
        HEAP_DELETE_MODEL(self->unk_8c);
        HEAP_DELETE_MODEL(self->unk_90);
        return;
    case 1:
        {
            Model *model = self->mdl[4];
            self->unk_90 = self->mdl[5];
            self->mdl[4] = NULL;
            self->unk_8c = model;
            self->mdl[5] = NULL;
            self->unk_94 = 5;
            model->flags |= 0x200000;
            self->unk_8c->flags |= 0x80000;
            self->unk_90->flags |= 0x200000;
            self->unk_90->flags |= 0x80000;
            TexObj_SetOamFunc(self->unk_90, 2, (void *)ActorMarker_OamCallback08, &self->work);
        }
        self->work.state = 4;
    case 4:
        self->work.fade = 0;
        self->work.alpha = 0;
        if (Obj021c0560_Wait(self)) {
            self->work.state = 5;
            if (self->update != NULL) {
                self->update(self);
            }
            MI_CpuFill8(&self->work, 0, 0x24);
            self->work.state = 4;
            self->kind = -1;
            self->update = NULL;
            self->draw = 0;
            return;
        }
    case 10:
        if (!ActorMarker_UpdateFade(self, 0x6000)) {
            self->work.z = -0x1ccd;
        }
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
