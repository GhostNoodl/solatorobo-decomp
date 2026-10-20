#include "ov012/ov012.h"

extern "C" {
void func_ov012_0220824c(Ov012Actor *self) {
    if (self->unk_40->state == 0 && self->unk_1a == 0) {
        func_02049f44(data_02097e4c, 0x600, &self->pos, 0);
    }
    func_ov003_021d452c(self);
}

extern char data_ov012_0220b335[];
extern char data_ov012_0220b33b[];
extern char data_ov012_0220b341[];
extern void func_ov000_021911c8(void *p, s32 a);
extern void func_0204a028(void *a, s32 b, Ov012Vec *c, s32 d);
extern u16 func_01ffc128(u16 a, u16 b, s32 c, s32 d, s32 e);

struct Ov012Rot8294 {
    u16 x;
    u16 y;
    u16 z;
};

static inline u16 Ov012_HpPct8294(Ov012Actor *self) {
    return self->unk_50[0] * 100 / self->unk_50[1];
}

void func_ov012_02208294(Ov012Actor *self) {
    Ov012Actor *pl = Ov012_FindActor(self->unk_90);
    Ov012Sub40 *s = self->unk_40;
    Ov012Vec t;
    switch (s->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220b335, 0x400, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        t = self->unk_b8;
        self->unk_98 = FX_Atan2(t.x - self->pos.x, t.z - self->pos.z);
        self->unk_40->state++;
        break;
    case 1:
        s->timer++;
        if (s->timer > 0x14) {
            Ov012V *e;
            func_02049f44(data_02097e4c, 0x29, &self->pos, 0);
            e = func_02065f88(0x192, &self->pos);
            e->v24(0, 0x1333, 0);
            e->v0c(0x1333);
            e->v34(0, self->unk_98, 0);
            self->unk_9c = 0x533;
            self->unk_40->timer = 0;
            self->unk_40->state++;
        } else {
            self->rot[1] = func_01ffc128(self->unk_98, self->rot[1], 0x400, 1, 0x8000);
        }
        break;
    case 2:
        s->timer++;
        if (s->timer > 0x2d || VEC_Distance(&self->pos, &self->unk_b8) < 0x4800) {
            func_ov000_02190cb0(self->unk_38, data_ov012_0220b33b, 0x19a, 0);
            self->unk_94_1 = 1;
            self->unk_ea_0 = 3;
            self->unk_a4 = 0xc00;
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        t = self->unk_b8;
        func_ov000_0218ddd4(self, &t, 0);
        self->rot[1] = func_01ffc128(self->unk_98, self->rot[1], 0x400, 1, 0x8000);
        break;
    case 3:
        func_ov000_0218d988(self, pl, 0x400);
        self->unk_40->timer++;
        if (self->unk_40->timer == 5 || self->unk_40->timer == 0x23) {
            Ov012V *e = func_02065f88(0x384, &self->pos);
            e->v24(0, 0x1333, 0);
            e->v0c(0xe66);
        }
        if (FLD(s16, self->unk_38, 0xc4) == 1) {
            self->unk_9c = 0;
            self->unk_ea_3 = 1;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        self->unk_94_1 = 1;
        func_ov000_0218dbe0(self, 0);
        break;
    case 4:
        if (func_ov000_02191120(self->unk_38)) {
            self->unk_ea_3 = 0;
            self->unk_ea_0 = self->unk_b0->unk_0a_7;
            func_ov000_02190cb0(self->unk_38, data_ov012_0220b341, 0x19a, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            if (Ov012_HpPct8294(self) < 0x28 && FLD(u16, self, 0x228) == 0) {
                FLD(u16, self, 0x228)++;
                func_ov000_02198360(self->unk_40, 0x10, 1);
            } else {
                func_ov000_02190cb0(self->unk_38, data_ov012_0220b335, 0x19a, 0);
                func_ov000_021911c8(self->unk_38, 0x666);
                self->unk_40->timer = 0;
                self->unk_40->state++;
            }
        }
        self->unk_94_1 = 1;
        break;
    case 5:
        s->timer++;
        if (s->timer > 0x14) {
            Ov012V *e;
            Ov012Rot8294 r;
            func_0204a028(data_02097e4c, 0x54, &self->pos, 3);
            e = func_02065f88(0x25d, &self->pos);
            e->v24(0, 0x1333, 0);
            e->v0c(0xb33);
            r.y = self->rot[1] + 0x6000;
            r.x = 0x800;
            r.z = 0;
            e->v30(&r);
            e = func_02065f88(0x25d, &self->pos);
            e->v24(0, 0x1333, 0);
            e->v0c(0xb33);
            r.y = self->rot[1] - 0x6000;
            r.x = 0x800;
            r.z = 0;
            e->v30(&r);
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    case 6:
        s->timer++;
        if (s->timer > 100) {
            FLD(u16, self, 0x228) = 0;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    self->unk_48->unk_9a_5 = 1;
    func_ov000_021987b8(self->unk_48, 0, 0, 0);
    if (self->unk_48->unk_50 & 0x20000000) {
        self->unk_a0 = 0;
    }
}
}
