#include "ov000/HeapScope.h"
#include "ov000/Vec.h"
#include "ov000/ActorMarker.h"

struct Marker021be96c : ActorMarker {
    void *unk_8c;
    s32 unk_90;
    s32 unk_94;
    s32 unk_98;
};

extern "C" {

static inline BOOL Obj021be96c_Wait(Marker021be96c *self) {
    if (!(self->show == 1 ? TRUE : FALSE) || (self->change == 1 ? TRUE : FALSE)) {
        return TRUE;
    }
    self->work.state = 10;
    return FALSE;
}

void func_ov000_021be96c(Marker021be96c *self) {
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
        }
        self->unk_90 = 0;
        self->unk_94 = 0;
        self->unk_98 = self->unk_28[0];
        self->work.state = 4;
    case 4:
        self->work.fade = 0;
        self->work.alpha = 0;
        if (Obj021be96c_Wait(self)) {
            return;
        }
    case 10:
        if (func_ov000_021bd374(self, 0x8000)) {
            return;
        }
        pos = self->unk_50;
        func_ov000_021bd474(self, &pos);
        self->work.z = -0x99a;
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
