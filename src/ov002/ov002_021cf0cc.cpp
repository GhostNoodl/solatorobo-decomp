#include "ov002/ov002.h"

extern "C" {

void func_ov002_021cf280(Task021ef4b0 *self, void *a);

void Task021ef4b0_PreUpdate(Task021ef4b0 *self) {
    switch (self->state) {
    case 8:
        if (self->unk_3c != NULL) {
            self->unk_3c->flags &= ~2;
        }
        if (self->unk_40 != NULL) {
            self->unk_40->flags &= ~2;
            func_ov002_021cf280(self, FIELD(self, 0x44, void *));
        }
        SndMgr_PlayVolume(data_02097e4c, 0x27, -1, -1, -1);
        break;
    case 10:
        if (self->unk_3c != NULL) {
            self->unk_3c->flags |= 2;
        }
        if (self->unk_40 != NULL) {
            self->unk_40->flags |= 2;
        }
        SndMgr_PlayVolume(data_02097e4c, 0x27, -1, -1, -1);
        break;
    }
    if (self->unk_3c != NULL) {
        BOOL a = FALSE;
        BOOL b = FALSE;
        BOOL c = FALSE;
        if (!data_ov000_021ccd34) {
            BOOL t = !self->unk_04_0;
            if (t) {
                c = TRUE;
            }
        }
        if (c) {
            if (self->vfunc_54()) {
                b = TRUE;
            }
        }
        if (b) {
            if (!self->unk_04_2) {
                a = TRUE;
            }
        }
        if (a) {
            self->unk_3c->flags &= ~4;
        } else {
            self->unk_3c->flags |= 4;
        }
        self->unk_3c->vfunc_1c();
    }
    if (self->unk_40 != NULL) {
        self->unk_40->vfunc_1c();
    }
}

}
