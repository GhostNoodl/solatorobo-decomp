#include "ov002/ov002.h"

extern "C" {

static inline bool ov002_Task_getFlag1(Task *self) {
    return self->unk_04_1;
}

void Task021ef89c_PreUpdate(Task021ef89c *self) {
    switch (self->state) {
    case 8:
        if (func_ov002_isMode4() || func_ov002_isMode4b()) {
            GfxSys_SetFadePlanes(0x3f, -1);
            GfxSys_StartFadeIn(0xa000, 0, -1);
        }
        if (self->unk_3c != NULL) {
            self->unk_3c->flags &= ~2;
        }
        if (self->unk_40 != NULL) {
            self->unk_40->flags &= ~2;
        }
        SndMgr_PlayVolume(data_02097e4c, 0x27, -1, -1, -1);
        break;
    case 10:
        SndMgr_PlayVolume(data_02097e4c, 0x28, -1, -1, -1);
        if (self->unk_3c != NULL) {
            self->unk_3c->flags |= 2;
        }
        if (self->unk_40 != NULL) {
            self->unk_40->flags |= 2;
        }
        break;
    }
    if (self->unk_3c != NULL) {
        if (self->vfunc_54()) {
            BOOL f = ov002_Task_getFlag1(self);
            if (!f) {
                self->unk_3c->flags &= ~4;
                goto done;
            }
        }
        self->unk_3c->flags |= 4;
    done:
        ((VObj *)self->unk_3c)->vfunc_1c();
    }
    if (self->unk_40 != NULL) {
        self->unk_40->vfunc_1c();
    }
}

}
