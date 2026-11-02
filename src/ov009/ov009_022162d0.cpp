#include "ov009/ov009.h"

typedef s16 fx16;
typedef s32 fx32;
typedef Ov009Vec VecFx32;
struct VecFx16 { fx16 x, y, z; };
#define FX32_ONE 0x1000

// A header's zero rotation and vector, plus copies made at startup, next to this TU's name and
// scale. The pointer to the name and the scale are read by the functions of 0x022143d8..0x02215714
// (nine files, merged in round dtD, each in its own namespace).
extern const char *const data_ov009_022161c8;
extern const VecFx32 data_ov009_022161d4;
extern char data_ov009_0221800a[];
const char *const data_ov009_022161c8 = data_ov009_0221800a;
static const VecFx16 data_ov009_022161cc = {0, 0, 0};
const VecFx32 data_ov009_022161d4 = {0, 0, FX32_ONE};
static const VecFx32 data_ov009_022161e0 = {0, 0, 0};
static const VecFx16 data_ov009_02218004 = data_ov009_022161cc;
char data_ov009_0221800a[] = "nut00";
static const VecFx32 data_ov009_02218010 = data_ov009_022161e0;

// ---- merged from ov009_022143d8.cpp
namespace m_022143d8 {
extern "C" {

extern void func_0203f364(Ov009Sub48 *p);

void func_ov009_022143d8(Ov009ActExVt_0221828c *self) {
    if (self->unk_40->state == 0) {
        Ov009Sub48 *s48;
        func_ov000_02190cb0(self->unk_38, data_ov009_022161c8, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        s48 = self->unk_48;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
        FLD(u8, self, 0xce) = 0;
        if (self->kind == 0x408f) {
            Ov009Sub44 *s44 = self->unk_44;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
        }
        self->unk_40->state++;
    }
    self->unk_94_1 = FLD(u8, self, 0xce);
}

}
}  // namespace m_022143d8

// ---- merged from ov009_022144a8.cpp
namespace m_022144a8 {
extern "C" {

extern void *data_ov000_021ccd68;
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern void func_ov000_02195d88(Ov009Obj *self);
extern void func_ov000_02196c40(Ov009Obj *self);

static inline Ov009Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov009_022144a8(Ov009ActExVt_0221828c *self) {
    func_ov000_02198360(self->unk_40, 0x15, 0);
}

void func_ov009_022144c0(Ov009ActExVt_0221828c *self) {
    func_ov000_02195d88(self);
    if (Ov009_FindActor(self->unk_d2) == NULL) {
        func_ov000_02198360(self->unk_40, 0x15, 0);
    }
}

void func_ov009_02214508(Ov009ActorEx *self) {
    if (self->unk_40->state == 0 && self->unk_9c == 0) {
        self->unk_48->unk_30 = 0;
    }
    func_ov000_02196c40(self);
}

extern void *data_ov000_021ccd64;
extern void func_0203f364(Ov009Sub48 *p);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern Ov009Actor *func_ov000_0218e4cc(void *mgr, u16 id);
extern u16 func_ov000_0218dfb4(Ov009Actor *a, u16 id);
extern void func_ov000_02198c8c(void *p, s32 a);
extern void func_ov000_02197dec(void *self, u8 a, s16 b);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov000_0218bed8(void *mgr, s32 a, Ov009Obj *actor);
struct Ov009SpawnDesc2 {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

struct Ov009Rot16 {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov009Flag8 {
    u8 b0 : 1;
    u8 b1 : 7;
};

extern Ov009Actor *func_ov000_0218bf1c(void *mgr, Ov009SpawnDesc2 *d, Ov009Vec *pos, Ov009Rot16 *rot, u16 a);

static inline void Ov009Spawn_Init(Ov009SpawnDesc2 *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

void func_ov009_02214534(Ov009ActorEx *self) {
    Ov009Vec p;
    Ov009SpawnDesc2 desc;
    Ov009Rot16 r;
    Ov009Sub40 *st = self->unk_40;
    switch (st->state) {
    case 0: {
        u16 i;
        u16 n;
        Ov009Actor *e;
        s32 s;
        Ov009Spawn_Init(&desc, 0x4006);
        n = 3;
        e = func_ov000_0218e4cc(data_ov000_021ccd68, 0x4000);
        if (e != NULL) {
            u32 c = func_ov000_0218dfb4(e, 0x4006);
            if (c > 3) {
                c = 3;
            }
            n = 3 - c;
        }
        for (i = 0; i < n; i++) {
            Ov009Actor *o;
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            p.y += 0x1000;
            r.x = self->rot[0];
            r.y = self->rot[1];
            r.z = self->rot[2];
            o = func_ov000_0218bf1c(data_ov000_021ccd64, &desc, &p, &r, 0xffff);
            if (o != NULL) {
                FLD(Ov009Flag8, o, 0x16).b0 = 1;
                o->unk_90 = self->unk_90;
                o->unk_9c = 0;
                o->unk_a0 = 0x333;
                o->unk_a4 = 0;
                o->unk_a8 = 0x52;
                if (o->unk_4c != NULL) {
                    o->unk_4c->target = self->id;
                }
            }
        }
        p.x = self->pos.x;
        p.y = self->pos.y;
        p.z = self->pos.z;
        p.y += self->unk_6c;
        {
            Ov009V *e2 = func_02065f88(0x1f7, &p);
            s = self->unk_64 + (self->unk_64 >> 3);
            e2->v14(s, s, s);
        }
        func_ov000_0218996c(0xc, 0x14);
        if (self->unk_44 != NULL) {
            Ov009Sub44 *s44 = self->unk_44;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
        }
        if (self->unk_48 != NULL) {
            Ov009Sub48 *s48;
            func_ov000_02198c8c(self->unk_48, 0xffff);
            s48 = self->unk_48;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            func_0203f364(s48);
            s48 = self->unk_48;
            s48->unk_9a_1 = 0;
            s48->unk_9a_4 = 0;
        }
        self->unk_40->state++;
        self->unk_40->timer = 0;
        break;
    }
    case 1:
        st->timer++;
        if (st->timer > 5) {
            func_ov000_02197dec(self, 0xf, 0x63);
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->v08();
            return;
        }
        if (self->unk_38 != NULL) {
            self->unk_38->alpha = 0x1f - (self->unk_40->timer << 2);
        }
        break;
    }
}

}
}  // namespace m_022144a8

// ---- merged from ov009_02214810.cpp
namespace m_02214810 {
extern "C" {

extern void func_ov000_02194758(Ov009Obj *self);

void func_ov009_02214810(Ov009ActExVt_022181f4 *self) {
    func_ov000_02194758(self);
    self->unk_d0 = 0x5a;
    self->unk_ce = 0xb4;
    self->unk_d2 = 0xffff;
}

}
}  // namespace m_02214810

// ---- merged from ov009_0221483c.cpp
namespace m_0221483c {
extern "C" {

extern void *data_02097e4c;
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);

void func_ov009_0221483c(Ov009ActExVt_022181f4 *self) {
    if (self->unk_ce != 0) {
        self->unk_ce--;
        if (self->unk_ce <= self->unk_d0) {
            Ov009Sub38 *m = self->unk_38;
            FLD(u16, m, 0xb6) = 0x14bf;
            FLD(u16, m, 0xb8) = 0x73ff;
            FLD(u16, m, 0xba) = 9;
            FLD(u16, m, 0xbc) = 8;
            if (self->unk_d0 >= 0x46) {
                self->unk_d0 -= 0x14;
            } else if (self->unk_d0 >= 0x28) {
                self->unk_d0 -= 10;
            }
        }
        if (self->unk_ce <= 0x14) {
            if (self->unk_ce == 0x14) {
                Ov009V *e = func_02065f88(0x196, &self->pos);
                FLD(s32, e, 0x30) = 0x2a000;
                e->v0c(0xe66);
                self->unk_bc = FLD(void *, e, 0x24);
                func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
            }
        }
        if (self->unk_ce <= 0x10) {
            self->unk_a0 >>= 1;
            self->unk_a4 = 0xc7b;
        }
    } else {
        if (self->unk_40->unk_13 == 9) {
            self->unk_4c->target = 0xffff;
            self->unk_d2 = 0xffff;
        }
        func_ov000_02198360(self->unk_40, 0x15, 0);
    }
}

}
}  // namespace m_0221483c

// ---- merged from ov009_02214974.cpp
namespace m_02214974 {
extern "C" {

extern u8 data_ov009_0221801c[];
extern void *func_ov000_02199ba0(void *p);
extern void func_0203f324(Ov009Sub48 *p);
extern void func_ov000_02196060(Ov009Obj *self);

void func_ov009_02214974(Ov009ActExVt_022181f4 *self) {
    u8 *p = (u8 *)func_ov000_02199ba0(self->unk_4c);
    if (p != NULL) {
        self->unk_d2 = FLD(u16, p, 0xc);
        if (FLD(u16, p, 0xe) == 0x501d && self->unk_40->state == 0) {
            Ov009Sub44 *s44;
            func_ov000_02190cb0(self->unk_38, data_ov009_0221801c, 0x1000, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_9c = 0x2f6;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0x29;
            s44 = self->unk_44;
            s44->unk_22_0 = 1;
            s44->unk_22_1 = 1;
            if (self->unk_48 != NULL) {
                Ov009Sub48 *s48 = self->unk_48;
                s48->unk_9a_0 = 1;
                s48->unk_9a_3 = 1;
                func_0203f324(s48);
                s48 = self->unk_48;
                s48->unk_9a_1 = 1;
                s48->unk_9a_4 = 1;
            }
            self->unk_40->state++;
            self->unk_40->timer = 0;
        } else {
            func_ov000_02196060(self);
        }
    } else {
        self->unk_d2 = 0xffff;
        func_ov000_02198360(self->unk_40, 4, 0);
    }
}

}
}  // namespace m_02214974

// ---- merged from ov009_02214a9c.cpp
namespace m_02214a9c {
extern "C" {

void func_ov009_02214a9c(Ov009ActExVt_022181f4 *self) {
    self->unk_d2 = 0xffff;
    func_ov000_02198360(self->unk_40, 4, 0);
}


#define OV009_F32_TO_FX32(f) ((s32)(((f) > 0) ? (f) * 4096.0f + 0.5f : (f) * 4096.0f - 0.5f))

struct Ov009ParamB {
    s16 unk_00;
    u16 unk_02_0 : 3;
    u16 unk_02_3 : 13;
};

static inline s32 Ov009_FxMulL(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

extern void *data_02097e4c;
extern void func_0203f324(Ov009Sub48 *p);
extern void func_0203f364(Ov009Sub48 *p);
extern void *func_0204a028(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern u16 func_ov000_02198da8(Ov009Sub48 *p, u16 a);
extern void func_ov000_0218dbe0(Ov009Obj *self, s32 a);
extern void *func_ov000_02199ba0(void *p);

void func_ov009_02214ac0(Ov009ActExVt_022181f4 *self) {
    Ov009Vec v;
    Ov009Sub48 *o48;
    BOOL flag;
    switch (self->unk_40->state) {
    case 0: {
        Ov009Sub48 *s48;
        Ov009Sub44 *s44;
        if (self->unk_a8 == 0) {
            self->unk_a8 = 0x52;
        }
        self->unk_a4 = 0xfae;
        s48 = self->unk_48;
        s48->unk_9a_0 = 1;
        s48->unk_9a_3 = 1;
        func_0203f324(s48);
        s48 = self->unk_48;
        s48->unk_9a_1 = 1;
        s48->unk_9a_4 = 1;
        s44 = self->unk_44;
        s44->unk_22_0 = 1;
        s44->unk_22_1 = 1;
        self->unk_92 = 0;
        self->unk_40->state++;
    }
    case 1: {
        Ov009Sub48 *s48 = self->unk_48;
        u32 f = s48->unk_50;
        if ((f & 0x20000000) || (f & 0x40000000) || ((s32)s48->unk_58) != 0) {
            u8 n = self->unk_92;
            if (f & 0x20000000) {
                if (n < 5) {
                    self->unk_a0 = OV009_F32_TO_FX32(0.2f - 0.0315f * n);
                    func_0204a028(data_02097e4c, 0x83, &self->pos, -2);
                    self->unk_92++;
                }
                if (self->unk_a0 < 0) {
                    self->unk_a0 = 0;
                }
                self->unk_a8 = 0x29;
                self->unk_9c = Ov009_FxMulL(self->unk_9c, 0xc00);
            } else {
                self->unk_98 = func_ov000_02198da8(s48, self->unk_98);
                self->unk_9c = Ov009_FxMulL(self->unk_9c, 0x59a);
                if (((s32)self->unk_48->unk_58) != 0 && n < 5) {
                    if (self->unk_a0 < 0xcd) {
                        self->unk_a0 = 0xcd;
                    }
                    self->unk_92++;
                }
                self->unk_a8 = 0x29;
            }
            self->unk_4c->target = 0xffff;
        }
        break;
    }
    }
    func_ov000_0218dbe0(self, 0);
    if (self->unk_48 == NULL) {
        return;
    }
    if (((Ov009ParamB *)self->unk_b0)->unk_02_0 == 2) {
        Ov009Sub48 *s48 = self->unk_48;
        s48->unk_9a_0 = 1;
        s48->unk_9a_3 = 1;
        func_0203f324(s48);
    }
    o48 = NULL;
    flag = FALSE;
    {
        Ov009Target *p4c = self->unk_4c;
        if (p4c != NULL && p4c->target != 0xffff && p4c->unk_01 == 1) {
            void *p;
            s32 r = self->unk_64 + 0x4cd;
            if (r < 0xccd) {
                r = 0xccd;
            }
            self->unk_48->unk_44 = r;
            p = func_ov000_02199ba0(self->unk_4c);
            if (p != NULL && (o48 = FLD(Ov009Sub48 *, p, 0x48)) != NULL && o48->unk_9a_3) {
                o48->unk_9a_3 = 0;
                func_0203f364(o48);
                flag = TRUE;
            }
        }
    }
    v = self->pos;
    v.y -= self->unk_68;
    func_ov000_021987b8(self->unk_48, 1, (s32)&v, (s32)self->rot);
    if (flag) {
        o48->unk_9a_3 = 1;
        func_0203f324(o48);
    }
}

}
}  // namespace m_02214a9c

// ---- merged from ov009_02214e90.cpp
namespace m_02214e90 {
extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd68;
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern Ov009Actor *func_ov000_0218e640(void *mgr, u16 id);
extern Ov009Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_0219aae8(Ov009Obj *self, Ov009Obj *src, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern BOOL func_ov000_0219a8bc(void *p, Ov009Obj *a, Ov009Obj *b, s32 c, s32 d, const Ov009Vec *pos, s32 e, s32 f, s32 g);
extern void func_ov000_0219763c(Ov009Obj *self);

static inline Ov009Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

void func_ov009_02214e90(Ov009ActExVt_022181f4 *self) {
    if (self->unk_40->state == 0) {
        Ov009Obj *a;
        Ov009Actor *t;
        func_ov000_0218996c(10, 10);
        self->unk_4c->unk_02 = 0;
        func_02065f88(5, &self->pos)->v0c(0x299a);
        func_02049f44(data_02097e4c, 0x1a, &self->pos, 0);
        a = Ov009_FindActor(self->unk_d2);
        if (a == NULL) {
            a = self;
        }
        func_ov000_0219aae8(self, a, self->unk_4c->unk_08, self->unk_4c->unk_0a & 0xff, 0x30, 0, 0, 0x299a, 0, 0x64, 0x1000);
        t = func_ov000_0219bf90();
        if (t != NULL && func_01ffc198(&t->pos, &self->pos, t->unk_64 + 0x299a)) {
            Ov009Target *q = self->unk_4c;
            func_ov000_0219a8bc(t->unk_44, self, self, q->unk_08, q->unk_0a & 0xff, &self->pos, 0x64, 0x1000, 0x1000);
        }
    }
    func_ov000_0219763c(self);
}

}
}  // namespace m_02214e90

// ---- merged from ov009_02214fe4.cpp
namespace m_02214fe4 {
extern "C" {

extern void func_ov000_02194758(Ov009Obj *self);
extern void func_0203f364(Ov009Sub48 *p);
extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_0218d988(Ov009Obj *self, Ov009Actor *other, s32 a);
extern void func_ov000_0219433c(Ov009Obj *self);
extern void *func_ov000_02199ba0(void *p);

void func_ov009_02214fe4(Ov009ActorEx *self) {
    Ov009Sub48 *s48;
    func_ov000_02194758(self);
    s48 = self->unk_48;
    s48->unk_9a_0 = 0;
    s48->unk_9a_3 = 0;
    func_0203f364(s48);
}

void func_ov009_02215014(Ov009ActorEx *self) {
    func_ov000_0218d988(self, func_ov000_0219bf90(), 0x7b);
    func_ov000_02198360(self->unk_40, 1, 0);
}

void func_ov009_02215044(Ov009ActExVt_0221802c *self) {
    func_ov000_0219433c(self);
    self->rot[0] = 0xd548;
    self->unk_d0 = 0;
}

void func_ov009_02215068(Ov009ActExVt_0221802c *self) {
    Ov009Sub48 *s48;
    u8 *p;
    func_ov000_02194758(self);
    s48 = self->unk_48;
    s48->unk_9a_0 = 0;
    s48->unk_9a_3 = 0;
    func_0203f364(s48);
    p = (u8 *)func_ov000_02199ba0(self->unk_4c);
    if (p != NULL && FLD(s16, p, 0x1c) == 0) {
        self->unk_48->unk_30 = 0;
    }
    func_ov000_02198360(self->unk_40, 0xb, 0);
}

}
}  // namespace m_02214fe4

// ---- merged from ov009_022150cc.cpp
namespace m_022150cc {
extern "C" {

extern void *data_02097e4c;
extern const Ov009Vec data_ov009_022161ec;
extern void *func_ov000_02199ba0(void *p);
extern void func_0203f364(Ov009Sub48 *p);
extern void func_0203f324(Ov009Sub48 *p);
extern void func_ov009_02215714(Ov009ActExVt_0221802c *self);
extern void func_ov009_02215a6c(Ov009ActExVt_0221802c *self);
extern Ov009V *func_02065f88(s32 id, const Ov009Vec *pos);
extern void *func_02049f44(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_01ffc9fc(Ov009Vec *out, const void *a, s32 b);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern void VEC_Normalize(const Ov009Vec *in, Ov009Vec *out);
extern void func_ov000_0218d9e8(Ov009Obj *self, const Ov009Vec *v, s32 a);
extern void func_ov000_0218996c(s32 a, s32 b);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, const Ov009Vec *v, s32 e, s32 f, s32 g, s32 h, s32 i);
extern void func_ov000_0218dbe0(Ov009Obj *self, s32 a);

static inline s32 Ov009_FxMulL(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov009_RotX(Ov009Vec *out, const Ov009Vec *v, u16 ang) {
    s32 y = 0;
    s32 z = 0;
    s32 s = OV009_SIN(ang);
    s32 c = OV009_COS(ang);
    if (v->y != 0) {
        y += Ov009_FxMul(c, v->y);
        z += Ov009_FxMul(s, v->y);
    }
    if (v->z != 0) {
        y += Ov009_FxMul(-s, v->z);
        z += Ov009_FxMul(c, v->z);
    }
    out->x = v->x;
    out->y = y;
    out->z = z;
}

void func_ov009_022150cc(Ov009ActExVt_0221802c *self) {
    Ov009Actor *p;
    Ov009Sub48 *m;
    p = (Ov009Actor *)func_ov000_02199ba0(self->unk_4c);
    if (p != NULL) {
        m = p->unk_48;
        if (m != NULL && m->unk_9a_3) {
            m->unk_9a_3 = 0;
            func_0203f364(m);
        }
    } else {
        func_ov000_02198360(self->unk_40, 0x15, 0);
        return;
    }
    if (p->kind == 0x1000) {
        func_ov009_02215714(self);
        return;
    }
    switch (self->unk_40->state) {
    case 0:
        func_02065f88(0x6a, &self->pos)->v0c(0xccd);
        func_02049f44(data_02097e4c, 0x2b, &self->pos, 0);
        self->unk_d8 = func_02040528(0x14) + 0x7b;
        if (self->unk_18 == 1) {
            self->unk_d8 = 0x3d;
        }
        self->unk_d4 = 0;
        self->unk_92 = 0;
        self->unk_40->state++;
        break;
    case 1: {
        Ov009Vec a = data_ov009_022161ec;
        func_01ffc9fc(&a, &a, self->rot[1]);
        VEC_Add(&a, &self->pos, &a);
        func_ov000_0218d9e8(self, &a, ((s32)self->unk_d8));
        if (self->unk_48->unk_50 & 0x40000000) {
            self->rot[0] = 0x3ffc;
        } else if (self->rot[0] < 0xbff4 && self->rot[0] > 0x3ffc) {
            self->rot[0] = 0x3ffc;
        }
        Ov009Vec v = data_ov009_022161d4;
        Ov009_RotX(&v, &v, self->rot[0]);
        func_01ffc9fc(&v, &v, self->rot[1]);
        VEC_Normalize(&v, &v);
        self->unk_9c = Ov009_FxMulL(v.x, 0x333);
        self->unk_a0 = Ov009_FxMulL(v.y, 0x333);
        self->unk_a4 = Ov009_FxMulL(v.z, 0x333);
        switch (self->unk_18) {
        case 1:
            if (p->pos.y > 0x9000) {
                self->unk_9c = Ov009_FxMulL(v.x, 0x51f);
                self->unk_a0 = Ov009_FxMulL(v.y, 0x51f);
                self->unk_a4 = Ov009_FxMulL(v.z, 0x51f);
            } else {
                self->unk_9c = Ov009_FxMulL(v.x, 0x59a);
                self->unk_a0 = Ov009_FxMulL(v.y, 0x59a);
                self->unk_a4 = Ov009_FxMulL(v.z, 0x59a);
            }
            break;
        case 2:
            self->unk_9c = Ov009_FxMulL(v.x, 0x47b);
            self->unk_a0 = Ov009_FxMulL(v.y, 0x47b);
            self->unk_a4 = Ov009_FxMulL(v.z, 0x47b);
            break;
        }
        VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
        func_ov009_02215a6c(self);
        m = self->unk_48;
        if (m->unk_50 & 0x20000000) {
            self->unk_a0 = 0x266;
            self->unk_a8 = 0x29;
            self->unk_92++;
            m->unk_9a_0 = true;
            m->unk_9a_3 = 1;
            func_0203f324(m);
            self->unk_40->state++;
        }
        if (++self->unk_d4 >= 0x96) {
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
        break;
    }
    case 2:
        if (self->unk_a0 <= 0 && (self->unk_48->unk_50 & 0x20000000)) {
            if (++self->unk_92 <= 2) {
                self->unk_a0 = 0x19a;
            } else {
                Ov009Sub44 *s;
                func_ov000_0218996c(10, 10);
                func_02065f88(5, &self->pos)->v0c(0x3000);
                func_ov000_0219aae8(self, self, self->unk_4c->unk_08, self->unk_4c->unk_0a, 2, NULL, 0, 0x4000, 0, 0x64, 0x1000);
                self->unk_9c = 0;
                self->unk_a0 = 0;
                self->unk_a4 = 0;
                self->unk_a8 = 0;
                s = self->unk_44;
                s->unk_22_0 = 0;
                s->unk_22_1 = 0;
                func_ov000_02198360(self->unk_40, 0x15, 0);
            }
        }
        func_ov000_0218dbe0(self, 0);
        break;
    }
    func_ov000_021987b8(self->unk_48, 1, 0, 0);
}

}
}  // namespace m_022150cc
