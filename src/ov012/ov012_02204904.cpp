#include "ov012/ov012.h"

extern "C" {

extern char data_ov012_0220afd6[];
extern Ov012Vec data_ov012_0220a680;
extern void func_0204a028(void *a, s32 b, Ov012Vec *c, s32 d);
extern void func_ov000_02191690(void *p);
extern void func_ov000_02191708(void *p);
extern void func_ov000_02191780(void *p);
extern void func_ov000_021911c8(void *p, s32 a);
extern BOOL func_ov012_02205080(Ov012Actor *self, s32 a);
extern void func_ov012_022053a4(Ov012Actor *self);

struct Ov012bEA4 {
    u16 b0 : 3;
};

void func_ov012_02204904(Ov012Actor *self) {
    Ov012Vec v;
    Ov012Vec p;
    Ov012Sub40 *s;
    Ov012V *e;
    p = func_ov000_0218d240(self)->pos;
    FLD(Ov012bEA4, self, 0xea).b0 = 4;
    s = self->unk_40;
    switch (s->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220afd6, 0x111, 0);
        self->unk_40->state++;
        break;
    case 1:
        self->unk_94_1 = 1;
        s->timer++;
        if (s->timer <= 0x82) {
            func_ov000_0218d918(self, &p, 0x400);
        }
        if (FLD(s16, self->unk_38, 0xc4) == 2) {
            func_0204a028(data_02097e4c, 0x66, &self->pos, -10);
        }
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            e = func_02065f88(0x391, &self->pos);
            e->v0c(0x2000);
            e->v20(&data_ov012_0220a680);
            func_020639d4(e, 0x5b, 0);
            func_ov003_021da9ac(FLD(void *, self, 0x100), 0, e);
            FLD(u32, self, 0xf0) |= 0x100000;
            func_ov000_02191690(self->unk_38);
        }
        if ((FLD(u32, self, 0xf0) & 0x100000) && !func_ov003_021daa0c(FLD(void *, self, 0x100), 0)) {
            func_02049f44(data_02097e4c, 0x404, &self->pos, 0);
            FLD(u32, self, 0xf0) ^= 0x100000;
            func_ov000_02191708(self->unk_38);
            func_ov012_022053a4(self);
            e = func_02065f88(0x68, &self->pos);
            e->v0c(0x800);
            e->v34(0xbfff, self->rot[1], 0);
            v.x = 0;
            v.y = 0x3000;
            v.z = 0x4000;
            func_01ffc9fc(&v, &v, self->rot[1]);
            e->v20(&v);
            func_ov003_021da9ac(FLD(void *, self, 0x100), 0xf9, e);
            e = func_02065f88(0x6a, &self->pos);
            v.x = 0;
            v.y = 0x3000;
            v.z = 0x4000;
            func_01ffc9fc(&v, &v, self->rot[1]);
            e->v20(&v);
            func_020639d4(e, 0x1a, 0);
            func_ov000_0218996c(10, 10);
        }
        if (!func_ov000_02191120(self->unk_38)) {
            break;
        }
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 2:
        s->timer++;
        if (s->timer == 10) {
            func_ov000_02190cb0(self->unk_38, data_ov012_0220afd6, 0x52, 0);
            func_ov000_021911c8(self->unk_38, 0xccd);
            func_ov000_02191780(self->unk_38);
        } else if (s->timer >= 0x82) {
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    case 3:
        if (func_ov012_02205080(self, 0x25)) {
            self->unk_40->timer = 0;
            self->unk_40->state = 0x1e;
        }
        break;
    case 0x1e:
        if (FLD(u32, self, 0xf0) & 0x10) {
            FLD(u32, self, 0xf0) ^= 0x10;
        }
        FLD(u32, self, 0xf0) |= 1;
        FLD(Ov012bEA4, self, 0xea).b0 = self->unk_b0->unk_0a_7;
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    e = (Ov012V *)func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0x100), 0xf9));
    if (e != NULL) {
        e->v0c(FLD(s32, e, 0x40) + 0xcd);
    }
}

}
