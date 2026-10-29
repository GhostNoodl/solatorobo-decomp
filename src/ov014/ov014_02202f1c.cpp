#include "ov014/ov014.h"

extern "C" {

extern void func_ov014_02202fe8(Ov014Actor *self);
extern void func_ov014_022033a8(Ov014Actor *self);
extern void func_ov014_022038b8(Ov014Actor *self);

void func_ov014_02202f1c(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0:
    case 1:
    case 2:
        func_ov014_02202fe8(self);
        break;
    case 10:
    case 11:
    case 12:
        func_ov014_022033a8(self);
        break;
    case 20:
    case 21:
    case 22:
        func_ov014_022038b8(self);
        break;
    case 30:
        if (FLD(u32, self, 0xf4) & 4) {
            FLD(u32, self, 0xf4) ^= 4;
        }
        FLD(u32, self, 0xf4) |= 1;
        func_ov000_02198360(self->unk_40, 0x15, 0);
        break;
    }
}


extern void *data_02097e4c;
extern void *data_ov014_02216500[];
extern const Ov014Vec data_ov014_0221657c;
extern Ov014Actor *func_ov000_0218d240(Ov014Actor *self);
extern void func_01ffc9fc(Ov014Vec *out, const void *a, s32 b);
extern void VEC_Add(const Ov014Vec *a, const Ov014Vec *b, Ov014Vec *out);
extern void *func_02049f44(void *mgr, s32 id, const Ov014Vec *pos, s32 a);
extern void func_ov000_0218dbe0(Ov014Actor *self, s32 a);
extern void func_ov000_0218d918(Ov014Actor *self, Ov014Vec *p, s32 a);
extern u16 FX_Atan2(s32 y, s32 x);

#define OV014_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014_SQRT_PARAM (*(volatile u64 *)0x40002b8)

struct Ov014Blk12F {
    s32 w[3];
};

void func_ov014_02202fe8(Ov014Actor *self) {
    Ov014Vec v;
    Ov014Vec tp;
    Ov014Vec c;
    Ov014Vec diff;
    s32 zero = 0;
    Ov014Actor *pl = func_ov000_0218d240(self);
    tp = pl->pos;
    self->unk_94_1 = 1;
    switch (self->unk_40->state) {
    case 0: {
        s32 h;
        u16 ang;
        func_ov000_02190cb0(self->unk_38, data_ov014_02216500[0], 0x111, zero);
        func_ov000_021915a0(self->unk_38);
        v.x = zero;
        v.y = 0x1800;
        v.z = 0x1000;
        func_01ffc9fc(&v, &v, self->rot[1]);
        VEC_Add(&self->pos, &v, &v);
        self->unk_9c = zero;
        self->unk_a0 = zero;
        self->unk_a4 = zero;
        self->unk_a8 = zero;
        {
            s64 sq;
            s32 dx = self->pos.x - v.x;
            s32 dz = self->pos.z - v.z;
            sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            OV014_SQRTCNT = 1;
            OV014_SQRT_PARAM = (u64)(sq * 4);
        }
        while (OV014_SQRTCNT & 0x8000) {
        }
        h = ((s32)OV014_SQRT_RESULT + 1) >> 1;
        ang = FX_Atan2(h, v.y - self->pos.y);
        self->unk_9c = Ov014_FxMul(OV014_SIN(ang), 0x23d);
        self->unk_a0 = Ov014_FxMul(OV014_COS(ang), 0x23d);
        func_02049f44(data_02097e4c, 0x57, &self->pos, 0);
        self->unk_40->state++;
        break;
    }
    case 1: {
        Ov014Sub40 *w;
        func_ov000_0218dbe0(self, zero);
        w = self->unk_40;
        w->timer++;
        if (w->timer != 0x1e) {
            break;
        }
        self->unk_a0 = zero;
        self->unk_a4 = zero;
        self->unk_a8 = zero;
        self->unk_9c = 0x400;
        self->unk_40->timer = zero;
        self->unk_40->state++;
        break;
    }
    case 2: {
        s32 d;
        func_ov000_0218d918(self, &tp, 0x19a);
        self->unk_98 = self->rot[1];
        tp.y = self->pos.y;
        d = VEC_Distance(&self->pos, &tp);
        if (d <= 0x1000) {
            *(Ov014Blk12F *)&c = *(const Ov014Blk12F *)&data_ov014_0221657c;
            VEC_Add(&self->pos, &c, &v);
            self->unk_b8 = v;
            func_02049f44(data_02097e4c, 0x50, &self->pos, zero);
            self->unk_40->timer = zero;
            self->unk_40->state = 10;
        }
        if (d >= 0x3000) {
            func_ov000_0218dbe0(self, 0);
        } else {
            func_ov000_02190cb0(self->unk_38, data_ov014_02216500[3], 0x111, zero);
            func_ov000_021915a0(self->unk_38);
            v.z = 0x1000;
            v.x = zero;
            v.y = zero;
            func_01ffc9fc(&v, &v, self->rot[1]);
            VEC_Add(&tp, &v, &v);
            diff.x = v.x - self->pos.x;
            diff.y = v.y - self->pos.y;
            diff.z = v.z - self->pos.z;
            VEC_MultAdd(0x19a, &diff, &self->pos, &self->pos);
        }
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        break;
    }
    }
}


extern void *data_0214a420;
extern const Ov014Vec data_ov014_02216588;
extern void *func_ov003_021daa3c(void *p, u8 id);
extern Ov014V *func_020657b0(void *a, void *b);
extern void func_ov003_021da9ac(void *p, u8 id, void *obj);
extern BOOL func_ov003_021daa0c(void *p, u8 id);
extern BOOL func_ov000_0219aca8(Ov014Actor *a, Ov014Actor *b, u16 c, u8 d, void *e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern Ov014V *func_02065f88(s32 id, Ov014Vec *pos);
extern void func_0203f324(Ov014Sub48 *p);
extern s32 FX_Div(s32 a, s32 b);

struct Ov014G190B {
    u8 b0 : 2;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 3;
};

static inline s32 Ov014B_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov014B_Approach(Ov014Actor *self, s32 k) {
    Ov014Vec d;
    {
        s32 bx = self->unk_b8.x;
        s32 by = self->unk_b8.y;
        s32 bz = self->unk_b8.z;
        d.x = bx - self->pos.x;
        d.y = by - self->pos.y;
        d.z = bz - self->pos.z;
    }
    VEC_MultAdd(k, &d, &self->pos, &self->pos);
}

void func_ov014_022033a8(Ov014Actor *self) {
    s32 h = Ov014_FxMul(FLD(s32, self->unk_38, 0xac), 0x15c3);
    func_ov000_0218d240(self);
    switch (self->unk_40->state) {
    case 10: {
        u8 *cam;
        Ov014B_Approach(self, 0x19a);
        if (VEC_Distance(&self->pos, &self->unk_b8) <= 0x4cd) {
            func_ov000_02190cb0(self->unk_38, data_ov014_02216500[1], 0x400, 0);
            func_02049f44(data_02097e4c, 0x54, &self->pos, 0);
            {
                s32 z = self->pos.z;
                self->unk_b8.x = self->pos.x;
                self->unk_b8.y = h + 0x4719a;
                self->unk_b8.z = z;
            }
            self->unk_9c = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_a0 = -0x59a;
            self->unk_48->unk_60 = -0x2000;
            FLD(u32, self, 0xf4) |= 0x400000;
            self->unk_40->state++;
        }
        cam = (u8 *)data_ov000_021ccd54 + 0xf4;
        FLD(u16, cam, 0xf8) = 0xaab;
        FLD(Ov014G190B, cam, 0xda).b4 = 1;
        break;
    }
    case 11: {
        Ov014Vec save;
        Ov014V *e;
        Ov014Game54 *g;
        func_ov000_0218dbe0(self, 0);
        save = self->unk_b8;
        if (VEC_Distance(&self->pos, &self->unk_b8) > 0x4cd && self->pos.y > save.y) {
            break;
        }
        if (FLD(u32, self, 0xf4) & 0x400000) {
            FLD(u32, self, 0xf4) ^= 0x400000;
        }
        FLD(u32, self, 0xf4) |= 0x800000;
        g = data_ov000_021ccd54;
        FLD(Ov014G190B, g, 0x190).b2 = 0;
        FLD(Ov014G190B, g, 0x190).b3 = 1;
        FLD(Ov014G190B, g, 0x190).b4 = 0;
        FLD(u8, g, 0x18d) = 0x1e;
        FLD(u8, g, 0x18e) = 0x3c;
        FLD(u8, g, 0x18f) = 0x3c;
        func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
        e = func_02065f88(0x66, &self->pos);
        e->v0c(0x2000);
        {
            Ov014Vec r = {0, 0, 0};
            r.y = -h;
            e->v20(&r);
        }
        func_ov003_021da9ac(FLD(void *, self, 0xfc), 0xfb, e);
        {
        Ov014Vec c;
        *(Ov014Blk12F *)&c = *(const Ov014Blk12F *)&data_ov014_02216588;
        c.x = self->pos.x;
        c.z = self->pos.z;
        e = func_02065f88(0x68, &c);
        FLD(s32, e, 0x7c) = FX_Div(0x10000, 0x1f000);
        func_ov003_021da9ac(FLD(void *, self, 0xfc), 0xfd, e);
        }
        self->pos = save;
        {
            Ov014Sub48 *m = self->unk_48;
            m->unk_9a_0 = 1;
            m->unk_9a_3 = 1;
            func_0203f324(m);
        }
        self->unk_40->state++;
        break;
    }
    case 12: {
        Ov014Sub40 *s = self->unk_40;
        Ov014V *o;
        if (FLD(u32, self, 0xf4) & 0x800000) {
            s->timer++;
            if (s->timer == 10) {
                self->unk_40->timer = 0;
                FLD(u32, self, 0xf4) ^= 0x800000;
            }
        }
        o = func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0xfc), 0xfd));
        if (o != NULL) {
            o->v0c(FLD(s32, o, 0x40) + 0x19a);
        }
        if (!func_ov003_021daa0c(FLD(void *, self, 0xfc), 0xfb)) {
            s = self->unk_40;
            s->timer++;
            if (s->timer == 0x14) {
                self->unk_40->timer = 0;
                self->unk_40->state = 0x14;
            }
        }
        break;
    }
    }
    {
    Ov014Vec v = {0, 0, 0};
    v.y = -h;
    if (FLD(u32, self, 0xf4) & 0x400000) {
        func_ov000_0219aca8(self, self, Ov014B_FxMul64(FLD(s16, self, 0x12c), 0x5a), 0x30, &v, 0, self->unk_64, 0x3000, 100, 0x1000);
        self->unk_94_1 = 1;
    }
    if (FLD(u32, self, 0xf4) & 0x800000) {
        func_ov000_0219aca8(self, self, Ov014B_FxMul64(FLD(s16, self, 0x12c), 0x5a), 0x30, &v, 0, 0x2ccc, 0x1000, 100, 0x1000);
        self->unk_94_1 = 1;
    }
    }
}

}
