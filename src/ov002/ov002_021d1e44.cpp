#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d1e44(void) {
}

void func_ov002_021d1e48(Task50 *self) {
    u16 keys = FIELD(data_02097dc8, 0x12, u16);
    void *ev = FIELD(self, 0x44, void *);
    if (ev != NULL) {
        if (!(keys & 2)) {
            return;
        }
        if (FIELD(ev, 0x58, s32) < 0x1000) {
            return;
        }
        FIELD(ev, 0x6c, u8) = 0;
        FIELD(self, 0x44, void *) = NULL;
        func_ov000_021c701c(self->unk_3c);
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
    } else {
        void *m;
        if (!(keys & 2)) {
            return;
        }
        FIELD(self->unk_3c, 0xc, u32) |= 4;
        m = FIELD(self->unk_3c, 0x88, void *);
        if (m != NULL) {
            data_ov002_021f0f84[2] = FIELD(m, 0x4, s32);
        }
        func_02049a48(data_02097e4c, 0x1f, -1, -1, -1);
        self->v0xc(0);
    }
}

void func_ov002_021d1f20(Task50 *self) {
    if (self->unk_3c != NULL) {
        TASK_VOBJ(self, 0x3c)->v0x20();
    }
    if (self->unk_40 != NULL) {
        self->unk_40->v0x20();
    }
    if (self->unk_48 != 0) {
        func_ov002_021d1f70(self);
    }
}

}
