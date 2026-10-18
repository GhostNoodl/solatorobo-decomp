#include "ov002/ov002.h"

extern "C" {

typedef struct E18_2ca4 { void *p; u8 pad[0x14]; } E18_2ca4;

static inline bool ov002_Task50_getFlag1(Task50 *self) {
    return self->flag1;
}

static inline BOOL ov002_isDone2ca4(VObject *o) {
    return FIELD(o, 4, s32) == 5;
}

void func_ov002_021d2ca4(Task50 *self) {
    switch (self->unk_08) {
    case 8:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        FIELD(self->unk_3c, 0xc, u32) &= ~2;
        FIELD(self->unk_40, 0xc, u32) &= ~2;
        FIELD(self->unk_44, 0xc, u32) &= ~2;
        break;
    case 12: {
        void *x = (&FIELD(self, 0x60, E18_2ca4))[FIELD(FIELD(self->unk_3c, 0xa0, void *), 4, s32)].p;
        if (self->unk_40 != NULL) {
            func_ov000_0215bb14(self->unk_40, x);
            self->unk_40->v0x70();
        }
        break;
    }
    case 10:
        func_02049a48(data_02097e4c, 0x28, -1, -1, -1);
        FIELD(self->unk_3c, 0xc, u32) |= 2;
        FIELD(self->unk_40, 0xc, u32) |= 2;
        FIELD(self->unk_44, 0xc, u32) |= 2;
        break;
    }
    if (FIELD(self, 0x48, VObject *) != NULL) {
        data_ov000_021ccd34 = 1;
        FIELD(self->unk_3c, 0xc, u32) |= 4;
        FIELD(self, 0x48, VObject *)->v0x1c();
        if (ov002_isDone2ca4(FIELD(self, 0x48, VObject *))) {
            u32 saved;
            HEAP_PUSH(saved);
            DELETE_VOBJ(FIELD(self, 0x48, VObject *));
            HEAP_POP(saved);
            data_ov000_021ccd34 = 0;
            FIELD(self->unk_3c, 0xc, u32) &= ~4;
        }
    } else if (self->unk_3c != NULL) {
        if (self->v0x54()) {
            BOOL f = ov002_Task50_getFlag1(self);
            if (!f) {
                FIELD(self->unk_3c, 0xc, u32) &= ~4;
                goto done;
            }
        }
        FIELD(self->unk_3c, 0xc, u32) |= 4;
    }

done:
    ((VObject *)self->unk_3c)->v0x1c();
    self->unk_40->v0x1c();
    self->unk_44->v0x1c();
}

}
