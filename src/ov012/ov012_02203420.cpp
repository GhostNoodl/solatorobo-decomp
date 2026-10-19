#include "ov012/ov012.h"

extern "C" {

extern u16 func_01ffc128(u16 target, u16 cur, s32 a, s32 b, s32 c);
extern void func_ov003_021daae4(void *p, s32 a, Ov012Vec *v, void *b, void *c, void *d, void *e);
extern void func_ov000_0219aca8(Ov012Actor *a, Ov012Actor *b, u16 c, u8 d, Ov012Vec *e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern Ov012Vec data_ov012_0220a748[];
extern Ov012Vec data_ov012_0220a7a8[];
extern u8 data_ov012_0220a5d0[];
extern Ov012Vec data_ov012_0220a65c[];

struct Ov012bEA {
    u16 b0 : 3;
};

void func_ov012_02203420(Ov012Actor *self) {
    Ov012Vec tgt;
    Ov012Vec p;
    Ov012Sub40 *s;
    u8 k = FLD(u8, data_ov000_021ccd54, 0xca);
    if (k != 3) {
        if (k == 8) {
            tgt = data_ov012_0220a748[FLD(u8, self, 0xfa)];
        }
    } else {
        tgt = data_ov012_0220a7a8[FLD(u8, self, 0xfa)];
    }
    if (!func_01ffc198(&self->pos, &tgt, self->unk_64 + 0x400)) {
        FLD(u16, self, 0xf6) = func_01ffc128(FX_Atan2(tgt.x - self->pos.x, tgt.z - self->pos.z), FLD(u16, self, 0xf6), 0x1000, 1, 0x8000);
    }
    FLD(Ov012bEA, self, 0xea).b0 = 4;
    p = func_ov000_0218d240(self)->pos;
    s = self->unk_40;
    switch (s->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a57c[2], 0x111, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_9c = self->unk_b0->unk_00;
        FLD(Ov012Vec, self, 0xb8) = tgt;
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 1: {
        Ov012V *e;
        u8 i;
        func_ov000_0218d918(self, &p, 0x19a);
        if (FLD(s16, self->unk_38, 0xc4) != 1) {
            return;
        }
        e = func_02065f88(0x68, &self->pos);
        e->v10(data_ov012_0220a5d0);
        e->v34(0xbfff, FLD(u16, self, 0xf6), self->rot[2]);
        e->v20(data_ov012_0220a65c);
        func_ov003_021da9ac(FLD(void *, self, 0x100), 0xf9, e);
        for (i = 1; i <= 2; i++) {
            Ov012Vec o;
            e = func_02065f88(0x6c, &self->pos);
            func_01ffc9fc(&o, &data_ov012_0220a65c[i], self->rot[1]);
            e->v20(&o);
            FLD(s32, e, 0xc8) = -1;
            func_ov003_021da9ac(FLD(void *, self, 0x100), (u8)(0xfd - i), e);
        }
        func_02049f44(data_02097e4c, 0x400, &self->pos, 0);
        {
            Ov012Sub48 *m = self->unk_48;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
        }
        self->unk_40->state++;
        break;
    }
    case 2: {
        Ov012V *e;
        Ov012V *o;
        Ov012Vec q;
        u8 i;
        u16 n;
        self->unk_94_1 = 1;
        s->timer++;
        if (s->timer == 10) {
            e = func_02065f88(0x192, &self->pos);
            e->v0c(0x4000);
            e->v34(self->rot[0], FLD(u16, self, 0xf6), self->rot[2]);
            func_020639d4(e, 0x29, 0);
            func_ov003_021da9ac(FLD(void *, self, 0x100), 0, e);
        }
        func_ov000_0218d918(self, &p, 0x19a);
        q = FLD(Ov012Vec, self, 0xb8);
        func_ov000_0218ddd4(self, &q, 0);
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        self->unk_48->unk_9a_5 = 1;
        func_ov003_021daae4(FLD(void *, self, 0x100), 0, &self->pos, 0, 0, 0, 0);
        for (i = 1; i <= 2; i++) {
            func_ov003_021daae4(FLD(void *, self, 0x100), (u8)(0xfd - i), &self->pos, 0, 0, &data_ov012_0220a65c[i], self->rot);
        }
        o = (Ov012V *)func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0x100), 0xf9));
        if (o != NULL) {
            o->v0c(FLD(s32, o, 0x40) + 0x19a);
        }
        func_ov000_0219aca8(self, self, Ov012_FxMul(FLD(s16, self, 0x124), 0x3c), 0x30, 0, 0, self->unk_64 + 0x800, FLD(s32, self, 0x68), 100, 0xccd);
        if (VEC_Distance(&self->pos, &FLD(Ov012Vec, self, 0xb8)) > 0x800) {
            return;
        }
        e = func_02065f88(0x67, &self->pos);
        e->v0c(0x2000);
        e->v34(self->rot[0], (u16)(FLD(u16, self, 0xf6) + 0x7fff), self->rot[2]);
        func_020639d4(e, 0x82, 0);
        if (++FLD(u8, self, 0xfa) >= 8) {
            FLD(u8, self, 0xfa) = 0;
        }
        for (i = 1; i <= 2; i++) {
            func_ov003_021daa6c(FLD(void *, self, 0x100), (u8)(0xfd - i));
        }
        n = 0;
        if (FLD(u8 *, self, 0x104) != NULL) {
            n = FLD(u16, FLD(u8 *, self, 0x104), 4);
        }
        if (++FLD(u8, self, 0xfb) >= n) {
            self->unk_40->state = 0x1e;
        } else {
            func_ov000_02190cb0(self->unk_38, data_ov012_0220a57c[0], 0x111, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_40->state = 10;
        }
        self->unk_40->timer = 0;
        break;
    }
    case 10:
        func_ov000_0218d918(self, &p, 0xcd);
        s = self->unk_40;
        s->timer++;
        if (s->timer >= FLD(u16, FLD(u8 *, self, 0x104), 2)) {
            self->unk_40->timer = 0;
            self->unk_40->state = 0;
        }
        break;
    case 30: {
        Ov012Sub48 *m;
        if (FLD(u32, self, 0xf0) & 0x80) {
            FLD(u32, self, 0xf0) ^= 0x80;
        }
        FLD(u32, self, 0xf0) |= 1;
        m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        func_0203f324(m);
        self->unk_40->timer = 0;
        FLD(Ov012bEA, self, 0xea).b0 = self->unk_b0->unk_0a_7;
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    }
}

}
