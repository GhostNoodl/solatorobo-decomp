#include "ov000/LoCommon.h"
#include "nitro/mi.h"
#include "ov000/ActorMarker.h"
#include "Main/Gfx/Model.h"

// A kind's pair of functions (ActorMarker::update / draw).
typedef struct {
    ActorMarkerFn update;
    ActorMarkerFn draw;
} ActorMarkerKind;

extern "C" {

extern ActorMarkerKind ActorMarker_KindTable[];
extern ActorMarkerKind Ov000Vt_021cc938_vtbl[]; // ActorMarker_KindTable + 4: its .update is the kind's draw
BOOL Vram_IsIdle(void);
BOOL Model_IsReady(Model *p, u16 a);

static inline s32 Norm021bd624(s32 k) {
    if (k >= 12 && k < 16) {
        k = 11;
    }
    return k;
}

void ActorMarker_Update(ActorMarker *self) {
    switch (self->step) {
    case 7:
        if (!ActorMarker_LoadIcons(self)) {
            break;
        }
        self->step = 8;
    case 8: {
        s32 i;
        BOOL ok;
        s32 k = Norm021bd624(self->nextKind);
        ok = FALSE;
        if (k == 11) {
            if (Vram_IsIdle()) {
                ok = TRUE;
            }
        } else {
            for (i = 0; i < 8; i++) {
                if (self->mdl[i] != NULL && !Model_IsReady(self->mdl[i], 0xffff)) {
                    break;
                }
            }
            if (i == 8) {
                ok = TRUE;
            }
        }
        if (!ok) {
            break;
        }
        self->step = 9;
    }
    case 9: {
        s32 n;
        s32 k;
        if (self->work.state != 4) {
            break;
        }
        self->change = 0;
        self->work.state = 5;
        if (self->update != NULL) {
            self->update(self);
        }
        MI_CpuFill8(&self->work, 0, sizeof(self->work));
        self->work.state = 1;
        n = Norm021bd624(self->nextKind);
        self->kind = self->nextKind;
        self->nextKind = -1;
        self->update = ActorMarker_KindTable[n].update;
        self->draw = Ov000Vt_021cc938_vtbl[n].update;
        if (self->update != NULL) {
            self->update(self);
        }
        self->step = 10;
    }
    }
    if (self->update != NULL) {
        self->update(self);
    }
}

}
