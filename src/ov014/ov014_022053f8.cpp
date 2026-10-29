#include "ov014/ov014.h"

extern "C" {

extern void *data_ov014_02216500[];
extern void *func_ov000_0218d240(Ov014Actor *self);
extern void func_ov000_0218d9e8(Ov014Actor *self, Ov014Vec *v, s32 a);

void func_ov014_022053f8(Ov014Actor *self) {
    func_ov000_0218d240(self);
    switch (self->unk_40->state) {
    case 20: {
        s32 n = 0;
        u16 *p;
        func_ov000_02190cb0(self->unk_38, data_ov014_02216500[3], 0x400, 0);
        func_ov000_021915a0(self->unk_38);
        p = FLD(u16 *, self, 0x130);
        if (p != NULL) {
            n = p[2];
        }
        if (++FLD(u8, self, 0xf9) < n) {
            self->unk_40->state++;
        } else {
            self->unk_40->state = 30;
        }
        break;
    }
    case 21: {
        Ov014Vec v = {0, 0, 0};
        v.y = self->pos.y;
        func_ov000_0218d9e8(self, &v, 0x400);
        Ov014Sub40 *s = self->unk_40;
        s->timer++;
        if (FLD(u16 *, self, 0x130)[1] == s->timer) {
            self->unk_40->timer = 0;
            self->unk_40->state = 2;
        }
        break;
    }
    }
}

}
