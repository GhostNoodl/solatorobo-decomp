#include "ov009/ov009.h"

extern "C" {

extern u8 data_ov009_022179ba[];
extern Ov009Vec data_ov009_02216028;
extern void *data_02097e4c;
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);
extern void func_ov000_0219a210(Ov009Vec *v, const Ov009Vec *a, u16 b);
extern Ov009Actor *func_ov003_021d69f0(Ov009Actor *self, u16 kind, const Ov009Vec *pos, const void *rot, Ov009Actor *t);
extern void func_ov000_0218d46c(Ov009Actor *a, u16 id, s32 b);
extern void func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);

void func_ov009_02210ce8(Ov009Actor *self) {
    Ov009Actor *t = func_ov000_0218d240(self);
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_022179ba, 0x2ab, 0);
        self->unk_40->state++;
        break;
    case 1:
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            Ov009Vec p;
            Ov009Actor *a;
            p = self->pos;
            {
                Ov009Vec o = data_ov009_02216028;
                func_ov000_0219a210(&p, &o, self->rot[1]);
            }
            a = func_ov003_021d69f0(self, 0x4802, &p, self->rot, t);
            if (a != NULL) {
                a->unk_9c = func_02040498(0x80) + 0x19a;
                a->unk_a0 = 0x19a;
                a->unk_a4 = 0;
                a->unk_a8 = 0x52;
                func_ov000_0218d46c(a, self->id, 4);
            }
            func_02049f44(data_02097e4c, 0xb, &self->pos, 0);
            self->unk_40->state++;
        } else {
            func_ov000_0218d988(self, t, self->unk_b0->unk_02);
        }
        break;
    case 2:
        if (func_ov000_02191120(self->unk_38)) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

}
