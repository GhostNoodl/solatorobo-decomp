#include "ov002/ov002.h"

extern "C" {

void func_0204aab0(void *p);

static inline BOOL ov002_isState5(void *o) {
    return FIELD(o, 0x4, s32) == 5 ? TRUE : FALSE;
}

void func_ov002_021d0810(Task50 *self) {
    switch (self->unk_08) {
    case 8:
        func_02049a48(data_02097e4c, 0x27, -1, -1, -1);
        FIELD(self->unk_3c, 0xc, u32) &= ~2;
        FIELD(self->unk_40, 0xc, u32) &= ~2;
        break;
    case 10:
        FIELD(self->unk_3c, 0xc, u32) |= 2;
        FIELD(self->unk_40, 0xc, u32) |= 2;
        func_02049a48(data_02097e4c, 0x28, -1, -1, -1);
        break;
    case 11:
        if (ov002_isState5(self->unk_3c) && ov002_isState5(self->unk_40)) {
            {
                u8 *m = data_02097e48;
                FIELD(m, 0x80, u16) = 0x8000;
                FIELD(m, 0x7c, u16) = 0;
            }
            {
                u8 *m;
                u16 id;
                FIELD(data_02097e48, 0x0, Bits16).b0 = 1;
                FIELD(data_02097e48, 0x0, u16) |= 8;
                m = data_02097e48;
                id = 0xd;
                if (FIELD(m, 0x0, Bits16).b0) {
                    if (FIELD(m, 0x6, u16) != 0xffff || FIELD(m, 0x4, u16) != id) {
                        u16 st;
                        if (FIELD(m, 0x2, u16) != 10 && FIELD(m, 0x2, u16) != 0) {
                            if (FIELD(m, 0x6, u16) != 0xffff) {
                                func_0204aab0(m);
                            }
                            st = 1;
                        } else {
                            st = 0;
                        }
                        FIELD(m, 0x2, u16) = st;
                        FIELD(m, 0x6, u16) = id;
                        FIELD(m, 0x8, u16) = 10;
                    }
                }
            }
        }
        break;
    case 13:
        break;
    }
    ((VObject *)self->unk_3c)->v0x1c();
    self->unk_40->v0x1c();
}

}
