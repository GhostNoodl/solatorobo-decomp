#include "ov014/ov014.h"

extern "C" {

extern void *data_ov014_02216500[];
extern Ov014Actor *func_ov000_0218d240(Ov014Actor *self);
extern void func_ov000_0218d918(Ov014Actor *self, Ov014Vec *v, s32 a);
extern void func_0203f364(Ov014Sub48 *p);
extern void func_0203f324(Ov014Sub48 *p);
extern void *data_02097e4c;
extern const Ov014Vec data_ov014_022165e8;
extern const Ov014Vec data_ov014_02216570;
extern s32 func_02040528(s32 n);
extern void VEC_Add(const Ov014Vec *a, const Ov014Vec *b, Ov014Vec *o);
extern s32 VEC_Distance(const Ov014Vec *a, const Ov014Vec *b);
extern void func_02049f44(void *mgr, s32 id, Ov014Vec *pos, s32 a);
extern void func_ov000_0218dbe0(Ov014Actor *self, s32 a);
extern BOOL func_ov003_021daa0c(void *p, u8 id);
extern void func_ov003_021daa6c(void *p, s32 a);
extern void func_ov003_021daae4(void *p, s32 a, Ov014Vec *v, void *b, s32 c, s32 d, s32 e);
extern void func_ov000_0219aca8(Ov014Actor *a, Ov014Actor *b, u16 c, u8 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern Ov014Actor *func_ov000_0219bf90(void);

struct Ov014bBlk12 {
    s32 w[3];
};

static inline void Ov014b_Begin(Ov014Actor *self, Ov014Vec *w) {
    self->unk_9c = 0x400;
    self->unk_a0 = 0;
    self->unk_a4 = 0;
    self->unk_a8 = 0;
    {
        Ov014Vec v = {0, 0, 0};
        v.x = func_02040528(0x3000);
        v.z = func_02040528(0x2800);
        VEC_Add(&v, &data_ov014_022165e8, w);
        w->y = self->pos.y;
        self->unk_b8 = *w;
        FLD(u32, self, 0xf4) |= 0x400000;
        func_02049f44(data_02097e4c, 0x57, &self->pos, 0);
    }
    self->unk_40->state++;
}

static inline void Ov014b_Effect(Ov014Actor *self) {
    Ov014Vec t;
    *(Ov014bBlk12 *)&t = *(const Ov014bBlk12 *)&data_ov014_02216570;
    if (FLD(u32, self, 0xf4) & 0x400000) {
        func_ov000_0219aca8(self, self, (u16)(((s64)FLD(s16, self, 0x12c) * 0x6e + 0x800) >> 12), 0x30, (s32)&t, 0, 0x2800, 0x1000, 0x64, 0x1000);
        self->unk_94_1 = 1;
    }
}

extern void func_0204a028(void *a, s32 b, Ov014Vec *c, s32 d);
extern Ov014V *func_02065f88(s32 id, Ov014Vec *pos);
extern void func_ov003_021da9ac(void *p, u8 id, void *obj);
extern void *func_ov003_021daa3c(void *p, u8 id);
extern Ov014V *func_020657b0(void *a, void *b);
extern void *data_0214a420;
extern void func_ov000_02191690(void *a);
extern void func_ov000_02191708(void *a);
extern s32 FX_Div(s32 a, s32 b);
extern s32 func_ov003_021d8820(void *p);
extern void func_ov003_021d87d0(void *p, s32 a);
extern void func_ov003_021d85c8(void *p, s32 a, s32 b, s32 c, s32 d);
extern void MIi_CpuClear32(u32 data, void *dst, u32 size);
extern const u16 data_ov014_02216510[];
extern const Ov014Vec data_ov014_0221660c;

static inline s32 Ov014c_FxMul64(s32 a, s64 b) {
    return (a * b + 0x800) >> 12;
}

void func_ov014_02203c00(Ov014Actor *self) {
    Ov014Vec tp;
    Ov014Vec t;
    Ov014Actor *tg = func_ov000_0218d240(self);
    tp.x = tg->pos.x;
    tp.y = tg->pos.y;
    tp.z = tg->pos.z;
    switch (self->unk_40->state) {
    case 0: {
        Ov014V *e;
        func_ov000_02190cb0(self->unk_38, data_ov014_02216500[1], 0x3f, 0);
        func_ov000_021915a0(self->unk_38);
        func_0204a028(data_02097e4c, 0x71, &self->pos, -2);
        e = func_02065f88(0x5e4, &self->pos);
        e->v0c(0x2000);
        func_ov003_021da9ac(FLD(void *, self, 0xfc), 0xf9, e);
        self->unk_40->state++;
        break;
    }
    case 1: {
        Ov014V *e;
        if (FLD(u8, self, 0xf9) != 0) {
            func_ov000_0218d918(self, &tp, 0x148);
            self->unk_98 = self->rot[1];
        }
        if (func_ov003_021daa0c(FLD(void *, self, 0xfc), 0xf9)) {
            break;
        }
        func_ov000_02191690(self->unk_38);
        e = func_02065f88(0x68, &self->pos);
        e->v0c(0x1800);
        e->v34(0x71c, self->rot[1], self->rot[2]);
        FLD(s32, e, 0x7c) = FX_Div(0xf000, 0x1f000);
        func_ov003_021da9ac(FLD(void *, self, 0xfc), 0xfd, e);
        func_0204a028(data_02097e4c, 0x66, &self->pos, -5);
        func_02065f88(0x579, &self->pos)->v0c(0x2000);
        if (func_ov003_021d8820((u8 *)self + 0x100) == 1) {
            func_ov003_021d87d0((u8 *)self + 0x100, 0);
        }
        func_ov003_021d85c8((u8 *)self + 0x100, 0, 0, 1, 0);
        self->unk_40->state++;
        break;
    }
    case 2:
        if (!func_ov003_021daa0c(FLD(void *, self, 0xfc), 0xfd)) {
            u8 i;
            Ov014Sub48 *m;
            func_ov000_02191708(self->unk_38);
            func_ov003_021d87d0((u8 *)self + 0x100, 1);
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_9c = 0x4cd;
            FLD(u32, self, 0xf4) |= 0x400000;
            m = self->unk_48;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
            for (i = 0; i < 3; i++) {
                Ov014V *e = func_02065f88(0x3ea, &self->pos);
                e->v0c(0x6800);
                e->v34(0, (u16)(self->rot[1] + data_ov014_02216510[i]), 0);
                FLD(s32, e, 0x7c) = FX_Div(0xb000, 0x1f000);
                MIi_CpuClear32(0xffffffff, (u8 *)e + 0x84, 0x40);
                FLD(s32, e, 0xc8) = -1;
                func_ov003_021da9ac(FLD(void *, self, 0xfc), 0xfa, e);
            }
            func_02049f44(data_02097e4c, 0x57, &self->pos, 0);
            self->unk_40->state++;
        } else {
            Ov014V *o = func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0xfc), 0xfd));
            if (o != NULL) {
                o->v0c(FLD(u8 *, o, 0x40) + 0xa4);
            }
        }
        self->unk_94_1 = 1;
        break;
    case 3:
        tp.y = self->pos.y;
        if (VEC_Distance(&self->pos, &tp) < 0x5000) {
            self->unk_40->state++;
        } else {
            func_ov000_0218d918(self, &tp, 0x148);
            self->unk_98 = self->rot[1];
            func_ov000_0218dbe0(self, 0);
        }
        func_ov003_021daae4(FLD(void *, self, 0xfc), 0xfa, &self->pos, NULL, 0, 0, 0);
        break;
    case 4:
        func_ov000_0218dbe0(self, 0);
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (self->unk_48->unk_50 & 0x40000000) {
            if (FLD(u32, self, 0xf4) & 0x400000) {
                FLD(u32, self, 0xf4) ^= 0x400000;
            }
            self->unk_48->unk_30 = 0;
            self->unk_40->state = 10;
        }
        func_ov003_021daae4(FLD(void *, self, 0xfc), 0xfa, &self->pos, NULL, 0, 0, 0);
        break;
    }
    if (self->pos.z >= 0xc000) {
        if (FLD(u32, self, 0xf4) & 0x1000000) {
            FLD(u32, self, 0xf4) ^= 0x1000000;
            self->unk_48->unk_30 = 0x40000000;
        }
    }
    if (self->unk_40->state >= 2) {
        self->unk_94_1 = 1;
    }
    *(Ov014bBlk12 *)&t = *(const Ov014bBlk12 *)&data_ov014_0221660c;
    if (FLD(u32, self, 0xf4) & 0x400000) {
        func_ov000_0219aca8(self, self, (u16)Ov014c_FxMul64(FLD(s16, self, 0x12c), 0x6e), 0x30, (s32)&t, 0, 0x2800, 0x1000, 0x64, 0x1000);
        self->unk_94_1 = 1;
    }
}

void func_ov014_02204134(Ov014Actor *self) {
    Ov014Vec w;
    Ov014Actor *pl;
    func_ov000_0218d240(self);
    switch (self->unk_40->state) {
    case 10:
        Ov014b_Begin(self, &w);
    case 11:
        w = self->unk_b8;
        func_ov000_0218d918(self, &w, 0xcd);
        self->unk_98 = self->rot[1];
        func_ov000_0218dbe0(self, 0);
        func_ov003_021daae4(FLD(void *, self, 0xfc), 0xfa, &self->pos, NULL, 0, 0, 0);
        if (VEC_Distance(&self->pos, &self->unk_b8) <= 0x4000) {
            self->unk_a4 = 0xf5c;
            self->unk_40->state++;
        }
        break;
    case 12:
        w = self->unk_b8;
        func_ov000_0218d918(self, &w, 0xcd);
        self->unk_98 = self->rot[1];
        func_ov000_0218dbe0(self, 0);
        if (func_ov003_021daa0c(FLD(void *, self, 0xfc), 0xfa)) {
            func_ov003_021daae4(FLD(void *, self, 0xfc), 0xfa, &self->pos, NULL, 0, 0, 0);
        }
        if (self->unk_9c <= 0x19a) {
            if (FLD(u32, self, 0xf4) & 0x400000) {
                FLD(u32, self, 0xf4) ^= 0x400000;
            }
            func_ov003_021daa6c(FLD(void *, self, 0xfc), 0xfa);
        }
        if (self->unk_9c <= 0x52) {
            Ov014Sub48 *m;
            self->unk_48->unk_30 = 0x40000000;
            m = self->unk_48;
            m->unk_9a_0 = 1;
            m->unk_9a_3 = 1;
            func_0203f324(m);
            self->unk_40->state = 20;
        }
        break;
    }
    Ov014b_Effect(self);
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        FLD(s32, pl, 0xb90) = self->pos.x;
        FLD(s32, pl, 0xb94) = self->pos.y;
        FLD(s32, pl, 0xb98) = self->pos.z;
        FLD(s32, pl, 0xb9c) = 0x4cd;
    }
}


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

extern const Ov014Vec data_ov014_022167d0[];
extern Ov014V *func_02065f88(s32 id, Ov014Vec *pos);
extern void func_ov003_021da9ac(void *p, u8 id, void *obj);

void func_ov014_022046ac(Ov014Actor *self);

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


void func_ov014_022046ac(Ov014Actor *self) {
    Ov014Vec w;
    Ov014Actor *pl;
    func_ov000_0218d240(self);
    switch (self->unk_40->state) {
    case 0:
        self->unk_9c = 0xb33;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        w.x = 0;
        w.y = 0x4719a;
        w.z = 0xf000;
        w.y = self->pos.y;
        self->unk_b8 = w;
        func_02049f44(data_02097e4c, 0x57, &self->pos, 0);
        self->unk_40->state++;
    case 1:
        w = self->unk_b8;
        func_ov000_0218d918(self, &w, 0x400);
        self->unk_98 = self->rot[1];
        func_ov000_0218dbe0(self, 0);
        if (VEC_Distance(&self->pos, &self->unk_b8) <= 0x2000) {
            self->unk_40->state++;
        }
        break;
    case 2: {
        Ov014V *e;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_9c = 0xb33;
        w = data_ov014_022167d0[FLD(u8, self, 0x12e)];
        w.y = self->pos.y;
        self->unk_b8 = w;
        e = func_02065f88(0x4b0, &self->pos);
        e->v14(0x99a, 0x99a, 0x1000);
        func_ov003_021da9ac(FLD(void *, self, 0xfc), 0, e);
        self->unk_40->state++;
        break;
    }
    case 3:
        w = self->unk_b8;
        func_ov000_0218d918(self, &w, 0x11f);
        self->unk_98 = self->rot[1];
        func_ov000_0218dbe0(self, 0);
        func_ov003_021daae4(FLD(void *, self, 0xfc), 0, &self->pos, self->rot, 0, 0, 0);
        if (VEC_Distance(&self->pos, &self->unk_b8) <= 0x6000) {
            self->unk_a4 = 0xecd;
            func_02049f44(data_02097e4c, 0x57, &self->pos, 0);
            self->unk_40->state++;
        }
        break;
    case 4:
        w = self->unk_b8;
        func_ov000_0218d918(self, &w, 0x19a);
        self->unk_98 = self->rot[1];
        func_ov000_0218dbe0(self, 0);
        func_ov003_021daae4(FLD(void *, self, 0xfc), 0, &self->pos, self->rot, 0, 0, 0);
        if (self->unk_9c <= 0x52) {
            if (++FLD(u8, self, 0x12e) >= 6) {
                FLD(u8, self, 0x12e) = 0;
            }
            self->unk_40->state = 10;
        }
        break;
    }
    if (self->unk_9c > 0x19a) {
        pl = func_ov000_0219bf90();
        if (pl != NULL) {
            FLD(s32, pl, 0xb90) = self->pos.x;
            FLD(s32, pl, 0xb94) = self->pos.y;
            FLD(s32, pl, 0xb98) = self->pos.z;
            FLD(s32, pl, 0xb9c) = 0x400;
        }
    }
}

}
