#include "ov009/ov009.h"

extern "C" {

struct Ov009Blk12 {
    s32 w[3];
};

extern void *const data_ov009_02215ee4[];
extern const Ov009Vec data_ov009_02215f2c;
extern const Ov009Vec data_ov009_02215f44;
extern u8 data_ov009_02215efc[];
extern void func_01ffc9fc(Ov009Vec *out, const void *a, s32 b);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern void func_ov000_0218d9e8(Ov009Actor *self, const Ov009Vec *v, s32 a);
extern void func_ov000_0218d918(Ov009Actor *self, const Ov009Vec *v, s32 a);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 a);

struct Ov009RotC {
    u16 x;
    u16 y;
    u16 z;
};

static inline s32 Ov009_Sqrt64c(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline s32 Ov009_DistXZc(const Ov009Vec *a, const Ov009Vec *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov009_Sqrt64c(sq);
}

extern const Ov009Vec data_ov009_02215f08;
extern void *data_02097e4c;
extern void func_ov003_021d452c(Ov009Actor *self);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_020639d4(Ov009V *o, s32 a, s32 b);
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern void func_0203f364(Ov009Sub48 *p);
extern void func_0203f324(Ov009Sub48 *p);
extern void func_0204a028(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);
extern void func_ov000_02191690(void *p);
extern void func_ov000_02191708(void *p);
extern s32 FX_Atan2(s32 y, s32 x);
extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_0219aca8(Ov009Actor *a, Ov009Actor *b, u16 c, u8 d, s32 e, Ov009RotC *f, s32 g, s32 h, s32 i, s32 j);
extern void func_ov000_0218996c(s32 a, s32 b);

void func_ov009_0220c094(Ov009Actor *self) {
    Ov009Vec a;
    Ov009Vec v;
    Ov009Vec w;
    Ov009RotC r;
    Ov009Actor *t;
    s32 y0 = 0;
    if (FLD(u8, self, 0xf7) == 0) {
        Ov009V *o;
        func_ov003_021d452c(self);
        if (FLD(s16, self->unk_38, 0xc4) != 2) {
            return;
        }
        o = func_02065f88(0x130, &self->pos);
        *(Ov009Blk12 *)&a = *(const Ov009Blk12 *)&data_ov009_02215f08;
        func_01ffc9fc(&a, &a, self->rot[1]);
        o->v20(&a);
        o->v34(0x4000, self->rot[1], self->rot[2]);
        o->v0c(0xb33);
        func_020639d4(o, 0x82, 0);
        return;
    }
    t = func_ov000_0218d240(self);
    v = t->pos;
    v.y = y0;
    switch (self->unk_40->state) {
    case 0:
    {
        Ov009Sub48 *s48;
        func_ov000_02190cb0(self->unk_38, data_ov009_02215ee4[2], 0x111, 0);
        s48 = self->unk_48;
        self->unk_9c = 0xcd;
        self->unk_a0 = 0x7b;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
    }
        func_0204a028(data_02097e4c, 0x5b, &self->pos, 2);
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        func_ov000_0218d988(self, t, self->unk_b0->unk_02);
        self->unk_98 = self->rot[1];
        v.y = -0x1000;
        func_ov000_0218d9e8(self, &v, self->unk_b0->unk_02);
        func_ov000_0218dbe0(self, 0);
        if (func_ov000_02191120(self->unk_38)) {
            func_ov000_02191690(self->unk_38);
            self->unk_40->state++;
        }
        break;
    case 2: {
        Ov009Sub40 *s = self->unk_40;
        s->timer++;
        if (s->timer > 0x14) {
            s32 ang;
            func_ov000_02191708(self->unk_38);
            v.y = y0 - 0x1000;
            self->unk_84 = v;
            ang = FX_Atan2(Ov009_DistXZc(&self->pos, &self->unk_84), self->unk_84.y - self->pos.y);
            {
                s32 sn = OV009_SIN(ang);
                s32 cs = OV009_COS(ang);
                s32 spd = self->unk_b0->unk_00;
                self->unk_9c = Ov009_FxMul(spd, sn);
                self->unk_a0 = Ov009_FxMul(spd, cs);
            }
            func_0204a028(data_02097e4c, 0x32, &self->pos, 5);
            self->unk_98 = self->rot[1];
            self->unk_40->timer = 0;
            self->unk_40->state++;
        }
        break;
    }
    case 3:
        func_ov000_0218dbe0(self, 0);
        if (*func_ov000_0219bf90()->unk_50 != 0) {
            r = *(Ov009RotC *)self->rot;
            r.x += 0x4000;
            func_ov000_0219aca8(self, self, FLD(u16, self, 0xf2), FLD(u16, FLD(void *, self, 0x4c), 0xa), 0, &r, 0x99a, 0x2000, 100, 0x1000);
        }
        if (self->unk_48->unk_50 & 0x20000000) {
            func_ov000_0218996c(0xf, 0xf);
            func_02049f44(data_02097e4c, 0x52, &self->pos, 0);
            w = self->pos;
            w.y = 0;
            func_02065f88(0x67, &w)->v34(0, (u16)(self->rot[1] + 0x7fff), 0);
            {
                Ov009Sub48 *s48;
                Ov009Sub44 *s44;
                self->unk_48->unk_38 = FLD(s32, self, 0xf8) >> 1;
                s48 = self->unk_48;
                s48->unk_9a_0 = 1;
                s48->unk_9a_3 = 1;
                func_0203f324(s48);
                self->unk_48->unk_30 = 0x40000000;
                s44 = self->unk_44;
                s44->unk_22_0 = 1;
                s44->unk_22_1 = 1;
            }
            self->unk_40->state++;
        }
        break;
    case 4: {
        Ov009Sub40 *s = self->unk_40;
        s->timer++;
        if (s->timer > FLD(u8, self, 0xf6)) {
            self->unk_40->timer = 0;
            func_ov000_02198360(self->unk_40, 0x11, 0);
        }
        break;
    }
    }
    self->unk_ea_0 = 3;
}

void func_ov009_0220c594(Ov009Actor *self) {
    Ov009Vec t1;
    Ov009Vec t2;
    Ov009Vec d;
    self->unk_94_1 = 1;
    switch (self->unk_40->state) {
    case 0: {
        Ov009Sub44 *s44;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_40->timer = 0;
        self->unk_48->unk_38 = FLD(s32, self, 0xf8);
        self->unk_48->unk_30 = 0;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        if (FLD(u16, self, 0xf0) & 4) {
            *(Ov009Blk12 *)&t1 = *(const Ov009Blk12 *)&data_ov009_02215f2c;
            t1.y = FLD(s32, self, 0x100) + 0x1000;
            func_01ffc9fc(&t1, &t1, self->rot[1]);
            VEC_Add(&self->pos, &t1, &t1);
            self->unk_b8 = t1;
            self->unk_40->state = 10;
        } else {
            func_ov000_02190cb0(self->unk_38, data_ov009_02215ee4[0], 0x400, 0);
            func_ov000_021915a0(self->unk_38);
            self->rot[0] = 0;
            self->unk_40->state++;
        }
        break;
    }
    case 1:
        if (self->pos.y < 0x2800) {
            self->unk_a0 = 0x266;
            break;
        }
        if (self->pos.y >= 0x2800 && self->pos.y < FLD(s32, self, 0x100)) {
            self->unk_a0 = 0x7b;
            break;
        }
        self->unk_40->state = 0x14;
        break;
    case 10:
        {
            s32 bx = self->unk_b8.x;
            s32 by = self->unk_b8.y;
            s32 bz = self->unk_b8.z;
            d.x = bx - self->pos.x;
            d.y = by - self->pos.y;
            d.z = bz - self->pos.z;
        }
        VEC_MultAdd(0x19a, &d, &self->pos, &self->pos);
        if (VEC_Distance(&self->pos, &self->unk_b8) <= 0x1000) {
            func_ov000_02190cb0(self->unk_38, data_ov009_02215ee4[0], 0x89, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_40->state++;
        }
        break;
    case 11: {
        Ov009Sub40 *s;
        *(Ov009Blk12 *)&t2 = *(const Ov009Blk12 *)&data_ov009_02215f44;
        func_01ffc9fc(&t2, &t2, self->rot[1]);
        VEC_Add(&self->pos, &t2, &t2);
        func_ov000_0218d9e8(self, &t2, 0x11f);
        s = self->unk_40;
        s->timer++;
        if (s->timer >= 0x32) {
            self->unk_40->state = 0x14;
        }
        break;
    }
    case 0x14:
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_9c = 0x333;
        func_01ffc9fc(&FLD(Ov009Vec, self, 0xfc), data_ov009_02215efc, (u16)(func_02040528(0x3c) * 0xb6));
        self->unk_b8 = FLD(Ov009Vec, self, 0xfc);
        func_ov000_02190cb0(self->unk_38, data_ov009_02215ee4[1], 0x111, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state++;
    case 0x15:
        func_ov000_0218d918(self, &FLD(Ov009Vec, self, 0xfc), 0xcd);
        FLD(u16, self, 0x98) = self->rot[1];
        if (VEC_Distance(&self->pos, &self->unk_b8) <= 0x4000) {
            self->unk_a4 = 0xf85;
            self->unk_40->state++;
        }
        break;
    case 0x16:
        if (self->unk_9c <= 0x52) {
            FLD(u16, self, 0xf0) = 1;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    func_ov000_0218dbe0(self, 0);
}

void func_ov009_0220c93c(Ov009Actor *self) {
    if (self->unk_40->state == 0 && FLD(u8, self, 0xf7) == 1) {
        self->unk_48->unk_38 = FLD(s32, self, 0xf8);
        self->rot[0] = 0;
    }
    func_ov003_021d5900(self);
}

}
