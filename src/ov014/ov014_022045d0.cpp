#include "ov014/ov014.h"

extern "C" {

extern void *data_ov014_02216500[];
extern Ov014Actor *func_ov000_0218d240(Ov014Actor *self);
extern void func_ov000_0218d918(Ov014Actor *self, Ov014Vec *v, s32 a);
extern void func_0203f364(Ov014Sub48 *p);
extern void func_0203f324(Ov014Sub48 *p);

void func_ov014_0220446c(Ov014Actor *self) {
    Ov014Vec v;
    Ov014Actor *t = func_ov000_0218d240(self);
    v.x = t->pos.x;
    v.y = t->pos.y;
    v.z = t->pos.z;
    switch (self->unk_40->state) {
    case 20: {
        s32 n;
        u16 *p;
        func_ov000_02190cb0(self->unk_38, data_ov014_02216500[3], 0x52, 0);
        func_ov000_021915a0(self->unk_38);
        {
            Ov014Sub48 *m = self->unk_48;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
        }
        if (FLD(u32, self, 0xf4) & 0x2000000) {
            FLD(u32, self, 0xf4) ^= 0x2000000;
        }
        n = 0;
        p = FLD(u16 *, self, 0x130);
        if (p != NULL) {
            n = p[2];
        }
        if (++FLD(u8, self, 0xf9) >= n) {
            self->unk_40->state = 30;
            return;
        }
        {
            Ov014Sub48 *m = self->unk_48;
            m->unk_9a_0 = 1;
            m->unk_9a_3 = 1;
            func_0203f324(m);
        }
        self->unk_40->state++;
        break;
    }
    case 21: {
        Ov014Sub40 *s;
        func_ov000_0218d918(self, &v, 0x148);
        self->unk_98 = self->rot[1];
        s = self->unk_40;
        s->timer++;
        if (FLD(u16 *, self, 0x130)[1] == s->timer) {
            self->unk_40->timer = 0;
            self->unk_40->state = 0;
        }
        break;
    }
    }
}

extern void func_ov014_022046ac(Ov014Actor *self);
extern void func_ov014_022049e8(Ov014Actor *self);
extern void func_ov014_022053f8(Ov014Actor *self);

void func_ov014_022045d0(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        func_ov014_022046ac(self);
        break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
        func_ov014_022049e8(self);
        break;
    case 20:
    case 21:
        func_ov014_022053f8(self);
        break;
    case 30:
        if (FLD(u32, self, 0xf4) & 0x20) {
            FLD(u32, self, 0xf4) ^= 0x20;
        }
        FLD(u32, self, 0xf4) |= 1;
        func_ov000_02198360(self->unk_40, 0x15, 0);
        break;
    }
}

}
