#include "ov009/ov009.h"

typedef s16 fx16;
typedef Ov009Vec VecFx32;
struct VecFx16 { fx16 x, y, z; };

// A header's zero rotation and vector, plus copies made at startup, among this TU's motion
// names, the pointers to them, a 6-byte table and offsets. Other functions read all but the
// zero objects.
// The functions of 0x0220b70c..0x0220d034 (eight files, merged in round dtB, each in its own
// namespace) are part of this TU: they read the name pointers through the .rodata base plus an
// offset, and name them (data_ov009_02215ee4/ee8/eec) instead of a data_ov009_02215ee4[n] array
// view; the vectors they pass are taken by address (&data_ov009_02215efc, &...f14) instead of u8[]
// externs. The readers before 0x0220acb8 (022088d8.cpp) are cut off by the unmatched 0220acb8.
extern const char *const data_ov009_02215ee4;
extern const u16 data_ov009_02215ef0[3];
extern const VecFx32 data_ov009_02215efc;
extern const VecFx32 data_ov009_02215f08;
extern const VecFx32 data_ov009_02215f14;
extern char data_ov009_0221727e[];
extern char data_ov009_02217284[];
extern char data_ov009_0221728a[];
static const VecFx16 data_ov009_02215ef6 = {0, 0, 0};
static const VecFx16 data_ov009_02217278 = data_ov009_02215ef6;
static const char *const data_ov009_02215ee8 = data_ov009_02217284;
const char *const data_ov009_02215ee4 = data_ov009_0221727e;
char data_ov009_0221727e[] = "nut00";
char data_ov009_0221728a[] = "att00";
const VecFx32 data_ov009_02215f14 = {0, 0x1800, -0xa000};
char data_ov009_02217284[] = "run00";
static const char *const data_ov009_02215eec = data_ov009_0221728a;
const VecFx32 data_ov009_02215f08 = {0, 0, 0x3000};
static const VecFx32 data_ov009_02215f20 = {0, 0, 0};
const VecFx32 data_ov009_02215efc = {0, 0x4000, -0x8000};
static const VecFx32 data_ov009_02217290 = data_ov009_02215f20;
const u16 data_ov009_02215ef0[3] = {0x1a0a, 0x0d05, 0};

// ---- merged from ov009_0220b70c.cpp
namespace m_0220b70c {
extern "C" {

extern const Ov009Vec data_ov009_02215f74[];
extern Ov009Vec data_ov009_02215f78[];
extern Ov009Vec data_ov009_02215f7c[];
extern void func_01ffc9fc(Ov009Vec *out, const void *a, s32 b);
extern void func_0203f364(Ov009Sub48 *p);

static inline void Ov009_SetPos(Ov009Actor *self, s32 x, s32 y, s32 z) {
    self->pos.x = x;
    self->pos.y = y;
    self->pos.z = z;
}

void func_ov009_0220b70c(Ov009ActVt_02217640 *self) {
    Ov009Sub48 *s48;
    func_ov003_021d112c(self);
    if (self->unk_1a != 0) {
        Ov009_SetPos(self, data_ov009_02215f74[self->unk_1a - 1].x, data_ov009_02215f74[self->unk_1a - 1].y, data_ov009_02215f74[self->unk_1a - 1].z);
    }
    switch (self->kind) {
    case 0x5808:
    case 0x580a:
        self->unk_f7 = 0;
        break;
    case 0x5809:
    case 0x580b: {
        Ov009Sub48 *p;
        self->unk_f7 = 1;
        func_01ffc9fc(&self->unk_fc, &data_ov009_02215efc, (u16)(func_02040528(0x3c) * 0xb6));
        self->pos = self->unk_fc;
        self->unk_f2 = self->kind == 0x5809 ? 0x78 : 0xa0;
        p = self->unk_48;
        self->unk_f8 = p->unk_38 << 1;
        p->unk_30 = 0;
        self->unk_93_4 = 1;
        break;
    }
    }
    switch (self->kind) {
    case 0x580b:
        self->unk_f6 = 0x96;
        self->unk_f4 = 0x64;
        break;
    case 0x5809:
        self->unk_f6 = 0xaa;
        self->unk_f4 = 0x96;
        break;
    }
    self->unk_f0 = 0;
    s48 = self->unk_48;
    s48->unk_9a_0 = 0;
    s48->unk_9a_3 = 0;
    func_0203f364(s48);
    FLD(u8, self->unk_38, 0xbe) = 0;
    self->unk_ea_14 = 1;
}


extern u8 data_ov009_02215f38[];
extern void *data_02097e4c;
extern Ov009Actor *func_ov000_0219bf90(void);
extern s32 func_ov000_0219a2f4(Ov009Vec *pos, s32 a, s32 b);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern void func_ov000_0218d9e8(Ov009Obj *self, Ov009Vec *v, s32 a);
extern void *func_02049f44(void *a, s32 b, Ov009Vec *c, s32 d);

static inline BOOL Ov009Game_IsPausedB(Ov009Game54 *g) {
    return g->unk_d4 != 0;
}

void func_ov009_0220b8a0(Ov009ActVt_02217640 *self) {
    Ov009Actor *pl;
    Ov009Vec d;
    Ov009Vec v;
    u8 k;
    self->unk_90 = 0xffff;
    {
        pl = func_ov000_0219bf90();
        if (pl != NULL) {
            self->unk_90 = pl->id;
        }
    }
    k = self->unk_40->unk_13;
    if (self->unk_f7 == 0) {
        func_ov003_021d1e8c(self);
        if (k == 1 || k == 0x20 || k == 2 || k == 0xf || (u8)(k + 0xee) <= 1) {
            func_ov000_021987b8(self->unk_48, 1, 0, 0);
            v = self->pos;
            func_ov000_0219a2f4(&v, self->pos.y + 0x1800, -0xa000);
            self->pos.y += Ov009_FxMul(*(volatile s32 *)&v.y + 0x1800 - self->pos.y, 0x19a);
            v.y += 0x1800;
            VEC_Distance(&self->pos, &v);
        }
    }
    if (self->unk_f7 == 1) {
        if (!Ov009_GameIdle()) {
            return;
        }
        if (Ov009Game_IsPausedB(data_ov000_021ccd54)) {
            return;
        }
        if (k == 1) {
            if (self->unk_f0 == 0) {
                self->unk_f0 = 4;
                self->unk_40->flags |= 0x8000;
            } else if (self->unk_f0 & 1) {
                self->unk_b6++;
                if (self->unk_b6 > self->unk_f4) {
                    self->unk_f0 = 0;
                    self->unk_b6 = 0;
                }
            }
        } else if (k != 0xf && k != 0x11) {
            func_01ffc9fc(&d, data_ov009_02215f38, self->rot[1]);
            VEC_Add(&self->pos, &d, &d);
            func_ov000_0218d9e8(self, &d, 0x29);
        }
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (self->pos.y <= -0x2000) {
            func_ov000_02198360(self->unk_40, 0x11, 0);
        }
    }
    if ((self->unk_30 & 0x200) && *self->unk_50 != 0) {
        func_02049f44(data_02097e4c, 0x40, &self->pos, 0);
    }
    if (self->pos.y <= -0x8000) {
        self->unk_40->flags |= 0x200000;
    }
}

}
}  // namespace m_0220b70c

// ---- merged from ov009_0220bb70.cpp
namespace m_0220bb70 {
extern "C" {

extern void func_0203f324(Ov009Sub48 *p);
extern void *NNS_G3dGlbGetInvV(void);
extern void MTX_MultVec33(const Ov009Vec *v, const void *m, Ov009Vec *out);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);

static inline BOOL Ov009Game_IsPaused3(Ov009Game54 *g) {
    return g->unk_d4 != 0;
}

void func_ov009_0220bb70(Ov009ActVt_02217640 *self) {
    Ov009Vec p;
    Ov009Vec v;
    Ov009Sub40 *st;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (Ov009Game_IsPaused3(data_ov000_021ccd54)) {
        return;
    }
    switch (self->unk_40->state) {
    case 0: {
        Ov009Sub44 *s44;
        func_ov000_02190cb0(self->unk_38, data_ov009_02215ee4, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->unk_40->timer = 0;
        self->unk_40->state++;
    }
    case 1: {
        Ov009Sub38 *m;
        u8 b;
        st = self->unk_40;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            s32 w;
            s32 y;
            s32 x;
            s32 r;
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            p.y -= self->unk_6c;
            w = self->unk_64;
            y = func_02040528(self->unk_68 << 1);
            x = func_02040528(w << 1);
            v.x = x;
            v.y = y;
            v.z = w;
            MTX_MultVec33(&v, NNS_G3dGlbGetInvV(), &v);
            VEC_Add(&v, &p, &v);
            r = func_02040498(0x1000);
            func_02065f88(0x389, &v)->v0c(r + 0x1000);
            self->unk_40->timer = 5;
        }
        m = self->unk_38;
        b = FLD(u8, m, 0xbe);
        if (b < 0x1f) {
            b++;
            if (b >= 0x1f) {
                b = 0x1f;
            }
            FLD(u8, m, 0xbe) = b;
        } else {
            self->unk_40->timer = 0;
            self->unk_40->state = 0x1e;
        }
        break;
    }
    case 0x1e:
        st = self->unk_40;
        st->timer++;
        if (st->timer >= 0x1e) {
            self->unk_40->timer = 0;
            if (self->unk_f7 == 0) {
                Ov009Sub44 *s44 = self->unk_44;
                Ov009Sub48 *s48;
                s44->unk_22_0 = 1;
                s44->unk_22_1 = 1;
                s48 = self->unk_48;
                s48->unk_9a_0 = 1;
                s48->unk_9a_3 = 1;
                func_0203f324(s48);
            }
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    func_ov000_0218d988(self, func_ov000_0218d240(self), self->unk_b0->unk_02);
}

}
}  // namespace m_0220bb70

// ---- merged from ov009_0220be20.cpp
namespace m_0220be20 {
extern "C" {

extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);

void func_ov009_0220be20(Ov009ActVt_02217640 *self) {
    Ov009Vec d;
    switch (self->unk_40->state) {
    case 0:
        {
            Ov009Sub38 *m = self->unk_38;
            const char *an = data_ov009_02215ee4;
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            func_ov000_02190cb0(m, an, 0x89, 0);
        }
        func_ov000_021915a0(self->unk_38);
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        if (self->unk_f7 == 1) {
            Ov009Sub40 *st = self->unk_40;
            if (st->timer != 0) {
                st->timer--;
            }
            if (st->timer == 0) {
                self->unk_40->timer = 0x32;
                self->unk_108 = self->unk_fc;
                self->unk_108.x += func_02040528(0x800);
                self->unk_108.y += func_02040528(0x800);
                self->unk_108.z += func_02040528(0x800);
            }
            d.x = self->unk_108.x - self->pos.x;
            d.y = self->unk_108.y - self->pos.y;
            d.z = self->unk_108.z - self->pos.z;
            VEC_MultAdd(0xcd, &d, &self->pos, &self->pos);
        }
        break;
    }
    if (self->unk_f7 != 1) {
        return;
    }
    if (VEC_Distance(&self->pos, &self->unk_fc) > 0x6000) {
        self->unk_f0 = 0x10;
        func_ov000_02198360(self->unk_40, 0x11, 0);
    }
    func_ov000_0218d988(self, func_ov000_0218d240(self), self->unk_b0->unk_02);
}

}
}  // namespace m_0220be20

// ---- merged from ov009_0220bfcc.cpp
namespace m_0220bfcc {
extern "C" {

extern void func_ov000_0218ddd4(Ov009Actor *self, const Ov009Vec *v, s32 a);

void func_ov009_0220bfcc(Ov009ActVt_02217640 *self) {
    u8 k = self->unk_f7;
    if (k == 0) {
        Ov009Vec v;
        Ov009Param *p;
        if (self->unk_40->state == 0) {
            func_ov000_02190cb0(self->unk_38, data_ov009_02215ee8, 0x2ab, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            self->unk_40->state++;
        }
        v = self->unk_b8;
        p = self->unk_b0;
        self->unk_9c = p->unk_00;
        func_ov000_0218ddd4(self, &v, p->unk_02);
    } else if (k == 1) {
        func_ov003_021d3600(self);
    }
}

}
}  // namespace m_0220bfcc

// ---- merged from ov009_0220c93c.cpp
namespace m_0220c93c {
extern "C" {

extern const Ov009Vec data_ov009_02215f2c;
extern const Ov009Vec data_ov009_02215f44;
extern void func_01ffc9fc(Ov009Vec *out, const void *a, s32 b);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern void func_ov000_0218d9e8(Ov009Obj *self, const Ov009Vec *v, s32 a);
extern void func_ov000_0218d918(Ov009Actor *self, const Ov009Vec *v, s32 a);
extern void func_ov000_0218dbe0(Ov009Obj *self, s32 a);

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

extern void *data_02097e4c;
extern void func_ov003_021d452c(Ov009Actor *self);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_020639d4(Ov009V *o, s32 a, s32 b);
extern Ov009Actor *func_ov000_0218d240(Ov009Actor *self);
extern void func_0203f364(Ov009Sub48 *p);
extern void func_0203f324(Ov009Sub48 *p);
extern void *func_0204a028(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_ov000_0218d988(Ov009Actor *self, Ov009Actor *other, s32 a);
extern void func_ov000_02191690(void *p);
extern void func_ov000_02191708(void *p);
extern u16 FX_Atan2(s32 y, s32 x);
extern Ov009Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_0219aca8(Ov009Actor *a, Ov009Actor *b, u16 c, u8 d, s32 e, Ov009RotC *f, s32 g, s32 h, s32 i, s32 j);
extern void func_ov000_0218996c(s32 a, s32 b);

void func_ov009_0220c094(Ov009ActVt_02217640 *self) {
    Ov009Vec a;
    Ov009Vec v;
    Ov009Vec w;
    Ov009RotC r;
    Ov009Actor *t;
    s32 y0 = 0;
    if (self->unk_f7 == 0) {
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
        func_ov000_02190cb0(self->unk_38, data_ov009_02215eec, 0x111, 0);
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
            func_ov000_0219aca8(self, self, self->unk_f2, FLD(u16, ((void *)self->unk_4c), 0xa), 0, &r, 0x99a, 0x2000, 100, 0x1000);
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
                self->unk_48->unk_38 = self->unk_f8 >> 1;
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
        if (s->timer > self->unk_f6) {
            self->unk_40->timer = 0;
            func_ov000_02198360(self->unk_40, 0x11, 0);
        }
        break;
    }
    }
    self->unk_ea_0 = 3;
}

void func_ov009_0220c594(Ov009ActVt_02217640 *self) {
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
        self->unk_48->unk_38 = self->unk_f8;
        self->unk_48->unk_30 = 0;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        if (self->unk_f0 & 4) {
            *(Ov009Blk12 *)&t1 = *(const Ov009Blk12 *)&data_ov009_02215f2c;
            t1.y = self->unk_fc.y + 0x1000;
            func_01ffc9fc(&t1, &t1, self->rot[1]);
            VEC_Add(&self->pos, &t1, &t1);
            self->unk_b8 = t1;
            self->unk_40->state = 10;
        } else {
            func_ov000_02190cb0(self->unk_38, data_ov009_02215ee4, 0x400, 0);
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
        if (self->pos.y >= 0x2800 && self->pos.y < self->unk_fc.y) {
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
            func_ov000_02190cb0(self->unk_38, data_ov009_02215ee4, 0x89, 0);
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
        func_01ffc9fc(&self->unk_fc, &data_ov009_02215efc, (u16)(func_02040528(0x3c) * 0xb6));
        self->unk_b8 = self->unk_fc;
        func_ov000_02190cb0(self->unk_38, data_ov009_02215ee8, 0x111, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state++;
    case 0x15:
        func_ov000_0218d918(self, &self->unk_fc, 0xcd);
        self->unk_98 = self->rot[1];
        if (VEC_Distance(&self->pos, &self->unk_b8) <= 0x4000) {
            self->unk_a4 = 0xf85;
            self->unk_40->state++;
        }
        break;
    case 0x16:
        if (self->unk_9c <= 0x52) {
            self->unk_f0 = 1;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    func_ov000_0218dbe0(self, 0);
}

void func_ov009_0220c93c(Ov009ActVt_02217640 *self) {
    if (self->unk_40->state == 0 && self->unk_f7 == 1) {
        self->unk_48->unk_38 = self->unk_f8;
        self->rot[0] = 0;
    }
    func_ov003_021d5900(self);
}

}
}  // namespace m_0220c93c

// ---- merged from ov009_0220c970.cpp
namespace m_0220c970 {
extern "C" {

extern void func_0203f364(Ov009Sub48 *p);
extern void *func_02065f88(s32 id, const Ov009Vec *pos);
extern void func_020639d4(void *p, s32 a, s32 b);
extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);
extern void func_ov003_021d6954(Ov009Actor *self, u8 a);
extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_0218d918(Ov009Actor *self, const Ov009Vec *v, s32 a);
extern void func_ov000_0218dbe0(Ov009Obj *self, s32 a);

void func_ov009_0220c970(Ov009Actor *self) {
    switch (self->unk_40->state) {
    case 0: {
        Ov009Sub48 *s48 = self->unk_48;
        Ov009Sub44 *s44;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        FLD(u16, self->unk_4c, 0x1c) = 0xffff;
        func_020639d4(func_02065f88(0x38a, &self->pos), 0x40, 0);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    }
    case 1: {
        Ov009Sub40 *st = self->unk_40;
        st->timer++;
        if (st->timer > 0x3c) {
            func_ov003_021d6a3c(self, 1, 1, 1);
        } else {
            func_ov003_021d6954(self, 0x1f - (self->unk_40->timer >> 1));
        }
        break;
    }
    }
}

extern void func_01ffc9fc(Ov009Vec *out, const void *a, s32 b);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);

void func_ov009_0220ca64(Ov009Actor *self) {
    Ov009Vec t;
    Ov009Actor *a;
    Ov009Sub44 *s44;
    u32 saved;
    func_ov003_021d112c(self);
    self->unk_9c = 0x52;
    func_01ffc9fc(&t, &data_ov009_02215f14, (u16)(func_02040528(0x1e) * 0xb6));
    VEC_Add(&self->pos, &t, &self->pos);
    a = func_ov000_0219bf90();
    {
        s32 x = a->pos.x;
        s32 z = a->pos.z;
        s32 y = self->pos.y;
        self->unk_b8.x = x;
        self->unk_b8.y = y;
        self->unk_b8.z = z;
    }
    FLD(u8, self->unk_38, 0xbe) = 0;
    self->unk_ea_6 = 1;
    self->unk_48->unk_30 = 0;
    s44 = self->unk_44;
    s44->unk_22_0 = 0;
    s44->unk_22_1 = 0;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (self->unk_3c != NULL) {
        if (self->unk_3c != NULL) {
            self->unk_3c->v04();
        }
        self->unk_3c = NULL;
    }
    data_02097dd0->cur = saved;
}

}
}  // namespace m_0220c970

// ---- merged from ov009_0220cb64.cpp
namespace m_0220cb64 {
extern "C" {

extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_0218d918(Ov009Actor *self, const Ov009Vec *v, s32 a);
extern void func_ov000_0218dbe0(Ov009Obj *self, s32 a);

void func_ov009_0220cb64(Ov009Actor *self) {
    Ov009Vec v;
    if (self->unk_40->state == 0) {
        u8 n = FLD(u8, self->unk_38, 0xbe);
        if (n < 0x1f) {
            n = n + 1;
            if (n >= 0x1f) {
                Ov009Sub44 *s44 = self->unk_44;
                s44->unk_22_0 = 1;
                s44->unk_22_1 = 1;
                n = 0x1f;
                func_ov000_02198360(self->unk_40, 1, 0);
            }
            FLD(u8, self->unk_38, 0xbe) = n;
        }
    }
    v = func_ov000_0219bf90()->pos;
    func_ov000_0218d918(self, &v, 0x1000);
    self->unk_98 = self->rot[1];
    func_ov000_0218dbe0(self, 0);
}

}
}  // namespace m_0220cb64

// ---- merged from ov009_0220cc24.cpp
namespace m_0220cc24 {
extern "C" {

extern s32 func_ov000_0219a510(Ov009Obj *self, s32 a, const Ov009Vec *pos, s32 r, s32 b, void **out);
extern BOOL func_ov000_021985c0(void *p);
extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_0218d918(Ov009Actor *self, const Ov009Vec *v, s32 a);
extern void func_ov000_0218dbe0(Ov009Obj *self, s32 a);

void func_ov009_0220cc24(Ov009Actor *self) {
    Ov009Vec v;
    void *list[32];
    s32 i;
    s32 n;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov009_02215ee4, 0x111, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->timer = 0;
        self->unk_40->state++;
    case 1:
        n = func_ov000_0219a510(self, 2, &self->pos, 0x1000, 0, list);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                if (list[i] != NULL && func_ov000_021985c0(list[i])) {
                    func_ov000_02198360(self->unk_40, 0x15, 0);
                    break;
                }
            }
        }
        break;
    }
    v = func_ov000_0219bf90()->pos;
    func_ov000_0218d918(self, &v, 0x1000);
    self->unk_98 = self->rot[1];
    func_ov000_0218dbe0(self, 0);
}

extern void *data_02097e4c;
extern void func_0203f364(Ov009Sub48 *p);
extern void *NNS_G3dGlbGetInvV(void);
extern void MTX_MultVec33(const Ov009Vec *v, const void *m, Ov009Vec *out);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void *func_0204a028(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, void *f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);
void func_ov009_0220cd40(Ov009Actor *self) {
    Ov009Vec p;
    Ov009Vec v;
    Ov009Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0: {
        Ov009Sub48 *s48;
        Ov009Sub44 *s44;
        *self->unk_50 = 0;
        s48 = self->unk_48;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        FLD(u16, self->unk_4c, 0x1c) = 0xffff;
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    }
    case 1:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            s32 w;
            s32 y;
            s32 x;
            s32 s;
            s16 n;
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            w = self->unk_64;
            y = func_02040528(self->unk_68);
            x = func_02040528(w);
            v.x = x;
            v.y = y;
            v.z = w;
            MTX_MultVec33(&v, NNS_G3dGlbGetInvV(), &v);
            VEC_Add(&v, &p, &v);
            s = func_02040498(0x4cd) + 0x4cd;
            n = self->unk_18;
            if (n % 3 == 0) {
                func_02065f88(0x69, &self->pos)->v0c(0x1333);
                func_02065f88(4, &self->pos);
                if (n >= 9) {
                    self->unk_40->state++;
                }
            } else {
                func_02065f88(0x69, &v)->v0c(s);
                if (n % 2 == 0) {
                    func_02065f88(4, &v)->v0c(s);
                }
                self->unk_40->timer = 5;
            }
            func_0204a028(data_02097e4c, 0x2b, &v, -5);
            self->unk_18 = n + 1;
        }
        if (*func_ov000_0219bf90()->unk_50 == 0) {
            return;
        }
        func_ov000_0219aae8(self, self, 0xc8, FLD(u16, self->unk_4c, 0xa), 2, NULL, 0, 0x2000, 0, 0x64, 0x1000);
        break;
    case 2: {
        u8 b = FLD(u8, self->unk_38, 0xbe);
        if (b == 0) {
            return;
        }
        b--;
        if (b == 0) {
            st->state = 10;
            b = 0;
        }
        FLD(u8, self->unk_38, 0xbe) = b;
        break;
    }
    case 10:
        func_ov003_021d6a3c(self, 1, 1, 1);
        break;
    }
}

}
}  // namespace m_0220cc24
