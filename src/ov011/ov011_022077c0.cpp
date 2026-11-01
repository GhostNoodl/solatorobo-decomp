#include "ov011/ov011.h"

typedef s16 fx16;
typedef Ov011Vec VecFx32;
struct VecFx16 { fx16 x, y, z; };

// A header's zero rotation and vector, plus copies made at startup, between this TU's resource
// names and the pointers to them. The first pointer and a scale are read by other functions.
// The functions of 0x021ffb58..0x02200aac (three files, merged in rounds dtB and jkL, each in its
// own namespace) are part of this TU: they read the name pointers and the zero vector through the
// .rodata base plus an offset, and name them (data_ov011_02207258/725c/7260/7264, 7278.x/y/z)
// instead of a data_ov011_02207258[n] array view. With the TU's own objects func_ov011_021fff38
// keeps the ROM's load order without a volatile. The other readers (021fc0b8..021ff8fc) are cut
// off from this range by the unmatched func_ov011_021ff24c.
extern const char *const data_ov011_02207258;
extern const fx16 data_ov011_0220726e[4];
extern const VecFx32 data_ov011_02207278;
extern char data_ov011_022078c0[];
extern char data_ov011_022078cf[];
extern char data_ov011_022078a0[];
extern char data_ov011_022078ac[];
static const char *const data_ov011_02207260 = data_ov011_022078c0;
static const char *const data_ov011_0220725c = data_ov011_022078cf;
static const char *const data_ov011_02207264 = data_ov011_022078a0;
const char *const data_ov011_02207258 = data_ov011_022078ac;
const fx16 data_ov011_0220726e[4] = {0x1800, 0x1800, 0x1800, 0x1800};
static const VecFx16 data_ov011_02207268 = {0, 0, 0};
const VecFx32 data_ov011_02207278 = {0, 0, 0};
char data_ov011_022078ac[] = "nut00";
char data_ov011_022078a0[] = "run00";
static const VecFx16 data_ov011_022078a6 = data_ov011_02207268;
static const VecFx32 data_ov011_022078b4 = data_ov011_02207278;


// ---- merged from ov011_021ffb58.cpp
namespace m_021ffb58 {

extern "C" {

extern void *data_02097e4c;
void *func_02049f44(void *a, s32 b, void *c, s32 d);
void func_ov003_021d4fd8(void *p);
void func_ov003_021d5348(void *p);

void func_ov003_021d5900(void *p);
void func_ov000_0218e8ec(void *mgr, u16 id, s32 c);
BOOL func_ov000_02198360(void *a, s32 b, s32 c);
void func_02065804(void *a, void *b);
extern void *data_0214a420;

struct Ov011FbChr {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
    u8 pad[3];
    s32 unk_04;
};

struct Ov011FbScl {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
    u8 pad;
    u16 sx;
    u16 sy;
};

struct Ov011FbObj {
    u16 cnt;
    u8 pad02[2];
    u64 flags;
    u8 pad0c[7];
    u8 state;
    Ov011V obj;
    u8 pad18[0x20];
    void *unk_38;
};

struct Ov011FbSub {
    u8 pad[0x14];
    s32 unk_14;
    u8 pad18;
    u8 unk_19;
};

struct Ov011Fb {
    u8 pad[0x3c];
    Ov011FbSub *unk_3c;
    u16 *unk_40;
    u8 pad44[4];
    u8 *unk_48;
    u8 pad4c[4];
    u16 *unk_50;
    u8 pad54[0x10];
    s32 unk_64;
    u8 pad68[0x2c];
    u8 f94_0 : 1;
    u8 f94_m : 2;
    u8 f94_r : 5;
    u8 pad95[0x5b];
    u8 b0 : 1;
    u8 b1 : 1;
    u8 restf0 : 6;
    u8 padf1[7];
    s32 unk_f8;
    u8 padfc[4];
    Ov011FbChr *unk_100;
    Ov011FbObj *unk_104;
    Ov011FbScl *unk_108;
};

static inline void Ov011_ChrKick(Ov011FbChr *c, s32 v) {
    if (c->b0 && c->b2) {
        c->unk_04 = v;
        c->b2 = 0;
    }
}

static inline u32 Ov011_ChrBusy(Ov011FbChr *c) {
    u32 r = 0;
    if (c->b0) {
        r = c->b2;
    }
    return r;
}

#pragma force_active on
void func_ov011_021ffb58(Ov011Fb *self) {
    switch (*self->unk_40) {
    case 0:
        if (self->b1) {
            Ov011_ChrKick(self->unk_100, 2);
        } else {
            Ov011_ChrKick(self->unk_100, 3);
        }
        *self->unk_40 = 1;
        break;
    case 1:
        if (Ov011_ChrBusy(self->unk_100)) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    self->unk_f8 = 0x3e69;
}

void func_ov011_021ffc38(Ov011Fb *self) {
    switch (*self->unk_40) {
    case 0:
        Ov011_ChrKick(self->unk_100, 4);
        *self->unk_40 = 1;
        break;
    case 1:
        if (Ov011_ChrBusy(self->unk_100)) {
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
}

void func_ov011_021ffcd0(Ov011Fb *self) {
    if (*self->unk_40 == 0) {
        Ov011FbChr *c;
        Ov011FbScl *p;
        Ov011FbObj *o;
        self->b0 = 0;
        c = self->unk_100;
        if (c->b0) {
            c->b1 = 1;
        }
        p = self->unk_108;
        p->b0 = 0;
        p->b1 = 0;
        p->sx = 0;
        p->sy = 0x1000;
        o = self->unk_104;
        if (o != NULL) {
            func_ov003_021da48c(o, 0);
            o->obj.v08();
            if (o->unk_38 != NULL) {
                func_02065804(data_0214a420, o->unk_38);
                o->unk_38 = NULL;
            }
        }
        self->unk_3c->unk_14 = self->unk_64 << 1;
        self->unk_3c->unk_19 = 0xff;
        if (*self->unk_50 == 0) {
            func_ov000_0218e8ec(data_ov000_021ccd68, 0x4812, 0x15);
        }
    }
    func_ov003_021d5900(self);
}

void func_ov011_021ffdd0(void *self) {
    if (**(u16 **)((u8 *)self + 0x40) == 0) {
        func_02049f44(data_02097e4c, 0x42, (u8 *)self + 0x70, 0);
    }
    func_ov003_021d4fd8(self);
}

void func_ov011_021ffe10(void *self) {
    if (**(u16 **)((u8 *)self + 0x40) == 0) {
        func_02049f44(data_02097e4c, 0x42, (u8 *)self + 0x70, 0);
    }
    func_ov003_021d5348(self);
}

Ov011V *func_02065f88(s32 id, Ov011Vec *v);
void func_ov003_021d6054(void *p);
void func_ov011_021ffe50(Ov011Fb *self) {
    if (*self->unk_40 == 0) {
        Ov011FbObj *o;
        Ov011V *v;
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4812, 0x15);
        o = self->unk_104;
        if (o != NULL) {
            func_ov003_021da48c(o, 0);
            o->obj.v08();
            if (o->unk_38 != NULL) {
                func_02065804(data_0214a420, o->unk_38);
                o->unk_38 = NULL;
            }
        }
        self->unk_3c->unk_14 = self->unk_64 << 1;
        self->unk_3c->unk_19 = 0xff;
        v = func_02065f88(0x69, (Ov011Vec *)((u8 *)self + 0x70));
        if (v != NULL) {
            v->v0c(0x2800);
            v->v24(0, 0x1000, 0);
        }
    }
    func_ov003_021d6054(self);
}

Ov011V *func_02066900(const char *arc, const char *name, const Ov011Vec *pos);
Ov011V *func_020657b0(void *m, void *id);
void func_02065860(void *m, void *id);
BOOL func_ov011_02202d04(void *self, const Ov011Vec *to, const Ov011Vec *from, s16 speed);
void func_ov003_021da40c(void *p);

static inline void VSet_ff38(Ov011Vec *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void func_ov011_021fff38(Ov011Fb *self) {
    Ov011Vec t;
    Ov011Vec spawnPos;
    Ov011Vec effPos;

    Ov011FbObj *o;
    const Ov011Vec *home;

    home = &data_ov011_02207278;
    t.x = data_ov011_02207278.x;
    t.y = data_ov011_02207278.y - 0x2000;
    t.z = data_ov011_02207278.z;
    o = self->unk_104;
    if (o == NULL) {
        return;
    }
    switch (o->state) {
    case 0:
        break;
    case 1: {
        u8 n;
        s32 v = self->unk_3c->unk_14;
        n = self->unk_3c->unk_19;
        if (n == 0xff) {
            n = 0xf;
        }
        v += Ov011_FxMul(0x8000 - v, 0x333);
        if (n >= 0x1e) {
            n = 0x1e;
        } else {
            n++;
        }
        self->unk_3c->unk_14 = v;
        self->unk_3c->unk_19 = n;
        break;
    }
    case 2:
        if (o->cnt == 0) {
            Ov011V *g;
            o->obj.v08();
            func_ov011_02202d04(&self->unk_104->obj, &t, home, 0x19a);
            self->unk_104->cnt++;
            spawnPos = *(Ov011Vec *)(self->unk_48 + 0x68);
            g = func_02066900(data_ov011_02207260, data_ov011_0220725c, &spawnPos);
            self->unk_104->unk_38 = FLD(void *, g, 0x24);
            FLD(s32, g, 0xc8) = -1;
        }
        if (self->unk_104->unk_38 != NULL) {
            Ov011V *e = func_020657b0(data_0214a420, self->unk_104->unk_38);
            if (e != NULL) {
                effPos = *(Ov011Vec *)(self->unk_48 + 0x68);
                e->v18(&effPos);
            }
        }
        self->f94_m = 1;
        break;
    case 3:
        if (o->cnt == 0) {
            o->obj.v08();
            func_ov011_02202d04(&self->unk_104->obj, home, &t, 0x19a);
            self->unk_104->cnt++;
            if (self->unk_104->unk_38 != NULL) {
                func_02065860(data_0214a420, self->unk_104->unk_38);
                self->unk_104->unk_38 = NULL;
            }
            self->b0 = 0;
        } else {
            s32 v;
            v = self->unk_3c->unk_14;
            u8 n = self->unk_3c->unk_19;
            if (n <= 0xf) {
                n = 0xf;
                if (o->obj.v14()) {
                    self->unk_104->obj.v08();
                    self->f94_m = 0;
                    self->unk_104->flags |= 1;
                }
            } else {
                n--;
                v += Ov011_FxMul((self->unk_64 << 1) - v, 0x59a);
            }
            self->unk_3c->unk_14 = v;
            self->unk_3c->unk_19 = n;
        }
        break;
    }
    func_ov003_021da40c(self->unk_104);
    self->unk_104->obj.v0c();
}
#pragma force_active reset
}
}  // namespace m_021ffb58

// ---- merged from ov011_0220023c.cpp
namespace m_0220023c {
struct Ov011Tw108 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
    u8 pad;
    s16 unk_02;
    s16 unk_04;
};

struct Ov011Ea {
    u16 lo : 3;
    u16 rest : 13;
};

struct Ov011B0a {
    u16 lo : 7;
    u16 mid : 3;
    u16 rest : 6;
};

extern "C" {

void func_ov000_0218d988(void *self, void *target, s32 c);
void func_ov000_02191690(void *a);
void func_ov000_02191708(void *a);
void func_ov000_021911c8(void *a, s32 b);

#pragma force_active on
void func_ov011_0220023c(void *self) {
    void *pl;
    void *q;
    s32 s;
    if (FLD(Ov011Tw108 *, self, 0x108) == NULL) {
        return;
    }
    pl = func_ov000_0219bf90();
    q = FLD(void *, self, 0xb0);
    if (q != NULL && pl != NULL && (s = FLD(Ov011Tw108 *, self, 0x108)->unk_02) != 0) {
        func_ov000_0218d988(self, pl, Ov011_FxMul(FLD(s16, q, 2), s));
    }
    if (FLD(Ov011Tw108 *, self, 0x108)->b1) {
        FLD(Ov011Ea, self, 0xea).lo = 2;
    } else {
        FLD(Ov011Ea, self, 0xea).lo = FLD(Ov011B0a, FLD(void *, self, 0xb0), 0xa).mid;
    }
    if (FLD(Ov011Tw108 *, self, 0x108)->b0) {
        func_ov000_02191690(FLD(void *, self, 0x38));
    } else {
        func_ov000_02191708(FLD(void *, self, 0x38));
    }
    func_ov000_021911c8(FLD(void *, self, 0x38), FLD(Ov011Tw108 *, self, 0x108)->unk_04);
}
#pragma force_active reset

struct Ov011Tw10c {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
    u8 pad;
    u16 timer;
};

struct Ov011Tbl6 {
    s32 v[6];
};

extern const Ov011Tbl6 data_ov011_022072c0;
extern void *data_02097e4c;
BOOL func_ov000_02190cb0(void *a, const void *b, s32 c, s32 d);
void func_ov000_02191618(void *a);
void func_ov000_021915a0(void *a);
u16 func_ov003_021d9c50(Ov011Vec *a, Ov011Vec *b);
Ov011V *func_02065f88(s32 id, Ov011Vec *pos);
void *func_02049f44(void *mgr, s32 id, const Ov011Vec *pos, s32 a);
s32 VEC_Distance(const Ov011Vec *a, const Ov011Vec *b);
void func_ov000_0218dbe0(void *self, s32 a);
void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
u16 FX_Atan2(s32 y, s32 x);

static inline void Ov011_SetTw(Ov011Tw108 *q, s16 a, s16 b) {
    q->b0 = 0;
    q->b1 = 0;
    q->unk_02 = a;
    q->unk_04 = b;
}

void func_ov011_02200310(void *self) {
    Ov011Tbl6 tbl = data_ov011_022072c0;
    Ov011Vec v;
    BOOL ok;
    u32 i;
    u8 st;
    Ov011Tw10c *p;
    st = FLD(u8, FLD(void *, self, 0x40), 0x13);
    ok = TRUE;
    for (i = 0; i < 6; i++) {
        s32 *e = &tbl.v[i];
        if (*e == st) {
            ok = FALSE;
            break;
        }
    }
    p = FLD(Ov011Tw10c *, self, 0x10c);
    if (p == NULL || !ok) {
        return;
    }
    if (p->b0) {
        if (p->timer == 0) {
            Ov011V *e;
            s32 r;
            if (!p->b1) {
                Ov011_SetTw(FLD(Ov011Tw108 *, self, 0x108), 0, 0x1000);
                p = FLD(Ov011Tw10c *, self, 0x10c);
                p->b0 = 1;
                p->b1 = 1;
                p->b2 = 1;
                p->timer = 0x78;
                func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov011_02207264, 0x1000, 0);
                func_ov000_02191618(FLD(void *, self, 0x38));
                FLD(s32, self, 0x9c) = 0;
                FLD(s32, self, 0xa0) = 0;
                FLD(s32, self, 0xa4) = 0;
                FLD(s32, self, 0xa8) = 0;
            } else {
                Ov011_SetTw(FLD(Ov011Tw108 *, self, 0x108), 0x1000, 0x1000);
                p = FLD(Ov011Tw10c *, self, 0x10c);
                p->b0 = 1;
                p->b1 = 0;
                p->b2 = 1;
                p->timer = 1;
                func_ov000_02190cb0(FLD(void *, self, 0x38), data_ov011_02207258, 0x1000, 0);
                func_ov000_021915a0(FLD(void *, self, 0x38));
            }
            v = FLD(Ov011Vec, self, 0xb8);
            r = func_ov003_021d9c50(&v, &FLD(Ov011Vec, self, 0x70));
            e = func_02065f88(0x192, &FLD(Ov011Vec, self, 0x70));
            e->v34(0, r, 0);
            e->v14(0x4000, 0x4000, 0x4000);
            func_02049f44(data_02097e4c, 0x32, &FLD(Ov011Vec, self, 0x70), 0);
        } else if (p->b1 == 1) {
            FLD(Ov011Flags, FLD(void *, self, 0x48), 0x9a).b5 = 1;
            FLD(Ov011Tw10c *, self, 0x10c)->b2 = 0;
            if (VEC_Distance(&FLD(Ov011Vec, self, 0x70), &FLD(Ov011Vec, self, 0xb8)) < 0x4000) {
                if (FLD(s32, self, 0x9c) >= 0x200) {
                    FLD(s32, self, 0x9c) = 0x200;
                }
                FLD(s32, self, 0xa4) = 0xf60;
            } else {
                FLD(s32, self, 0x9c) += Ov011_FxMul(FLD(s16, FLD(void *, self, 0xb0), 0), 0xcd);
                FLD(s32, self, 0x9c) = FLD(s32, self, 0x9c) > FLD(s16, FLD(void *, self, 0xb0), 0) ? FLD(s16, FLD(void *, self, 0xb0), 0) : (FLD(s32, self, 0x9c) < 0 ? 0 : FLD(s32, self, 0x9c));
            }
            func_ov000_0218dbe0(self, 0);
            func_ov000_021987b8(FLD(void *, self, 0x48), 1, 0, 0);
            if (FLD(u32, FLD(void *, self, 0x48), 0x50) & 0x40000000) {
                FLD(s32, self, 0x9c) = 0;
                FLD(s32, self, 0xa0) = 0;
                FLD(s32, self, 0xa4) = 0;
                FLD(s32, self, 0xa8) = 0;
                FLD(Ov011Tw10c *, self, 0x10c)->b0 = 0;
            }
        }
        FLD(Ov011Tw10c *, self, 0x10c)->timer--;
    }
    if (!FLD(Ov011Tw10c *, self, 0x10c)->b2) {
        return;
    }
    if (func_ov000_0219bf90() == NULL) {
        return;
    }
    {
        void *pl = func_ov000_0219bf90();
        Ov011Vec t;
        t = FLD(Ov011Vec, pl, 0x70);
        FLD(Ov011Vec, self, 0xb8) = t;
        FLD(u16, self, 0x98) = FX_Atan2(t.x - FLD(s32, self, 0x70), t.z - FLD(s32, self, 0x78));
    }
}
}
}  // namespace m_0220023c

// ---- merged from ov011_0220068c.cpp
namespace m_0220068c {
// Teardown of the scene object: inlines the whole destructor of the object at
// 0x100. Past the default inline size limit MWCC calls the helpers instead.
#pragma inline_max_size(512)


struct Ov011Tw108 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
    u8 pad;
    s16 unk_02;
    s16 unk_04;
};

struct Ov011Bit01 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
};

struct Ov011FreeNode {
    u8 pad[0xc];
    Ov011FreeNode *next;
};

struct Ov011Fed {
    u8 pad[0xf0];
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
    u8 padf1;
    u16 unk_f2;
    s32 unk_f4;
    s32 unk_f8;
    s32 unk_fc;
    u8 *unk_100;
    u8 *unk_104;
    Ov011Tw108 *unk_108;
    void *unk_10c;
};

struct Ov011Lst {
    u8 pad[4];
    Ov011Lst *next;
};

extern "C" {

extern void *data_0214a420;
void func_02065804(void *a, void *b);
void __cxa_vec_delete(void *arr, u32 size, u32 hdr, void *dtor);
void *func_ov011_021fb66c(void *self);
void func_ov003_021d7800(void *p);
void func_ov011_02201688(void *p);
void func_ov011_0220205c(void *p);
void func_ov011_02202fbc(void *p);
void func_ov011_021fa7dc(void *p);
void func_ov011_02202f04(void *p);
void *func_ov011_02201d10(void *p);
void *func_ov011_0220154c(void *p);
void *func_ov011_02202cac(void *p);

static inline void Ov011B_FreeBuf(u8 *b) {
    if (FLD(Ov011Bit01, b, 0x10).b0) {
        u32 saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (FLD(void *, b, 0x18) != NULL) {
            func_0203de50(FLD(void *, b, 0x18));
            FLD(void *, b, 0x18) = NULL;
        }
        data_02097dd0->cur = saved;
        FLD(Ov011Bit01, b, 0x10).b0 = 0;
    }
}

static inline void Ov011B_FreeVec(u8 *b) {
    if (FLD(Ov011Bit01, b, 0xb4).b0) {
        FLD(Ov011Bit01, b, 0xb4).b0 = 0;
        {
            u32 saved = data_02097dd0->cur;
            data_02097dd0->cur = data_02097dd0->def;
            if (FLD(void *, b, 0xbc) != NULL) {
                __cxa_vec_delete(FLD(void *, b, 0xbc), 0x40, 8, func_ov011_021fb66c);
                FLD(void *, b, 0xbc) = NULL;
            }
            data_02097dd0->cur = saved;
        }
        func_ov011_0220205c(b + 0xdc);
        func_ov011_02202fbc(b + 0x194);
    }
}

static inline void Ov011B_FreeList(u8 *b) {
    if (FLD(Ov011Bit01, b, 0x204).b0) {
        if (FLD(Ov011Bit01, b, 0x204).b0) {
            Ov011FreeNode *p = FLD(Ov011FreeNode *, b, 0x208);
            while (p != NULL) {
                Ov011FreeNode *next = p->next;
                if (p != NULL) {
                    func_0203de1c(p);
                }
                p = next;
            }
            FLD(Ov011FreeNode *, b, 0x208) = NULL;
        }
        FLD(Ov011Bit01, b, 0x204).b0 = 0;
    }
}

static inline void Ov011B_Free(u8 *b) {
    if (FLD(Ov011Bit01, b, 0).b0) {
        Ov011Lst *p;
        Ov011Lst *next;
        FLD(Ov011Bit01, b, 0).b0 = 0;
        for (p = FLD(Ov011Lst *, b, 0xc); p != NULL; p = next) {
            next = p->next;
            func_ov003_021d7800(p);
        }
        Ov011B_FreeBuf(b);
        func_ov011_02201688(b + 0x34);
        Ov011B_FreeVec(b);
        if (FLD(Ov011Bit01, b, 0x1b4).b0) {
            FLD(Ov011Bit01, b, 0x1b4).b0 = 0;
        }
        func_ov011_021fa7dc(b + 0x1d4);
        Ov011B_FreeList(b);
    }
}

static inline void Ov011B_Dtor(u8 *b) {
    Ov011B_Free(b);
    Ov011B_FreeList(b);
    func_ov011_021fa7dc(b + 0x1d4);
    if (FLD(Ov011Bit01, b, 0x1b4).b0) {
        FLD(Ov011Bit01, b, 0x1b4).b0 = 0;
    }
    Ov011B_FreeVec(b);
    func_ov011_02202f04(b + 0x194);
    func_ov011_02201d10(b + 0xdc);
    func_ov011_0220154c(b + 0x34);
    Ov011B_FreeBuf(b);
}

void func_ov011_0220068c(Ov011Fed *self) {
    u8 *a = self->unk_104;
    if (a != NULL) {
        func_ov003_021da48c(a, 0);
        ((Ov011V *)(a + 0x14))->v08();
        if (FLD(void *, a, 0x38) != NULL) {
            func_02065804(data_0214a420, FLD(void *, a, 0x38));
            FLD(void *, a, 0x38) = NULL;
        }
    }
    if (self->unk_108 != NULL) {
        Ov011Tw108 *q = self->unk_108;
        q->b0 = 0;
        q->b1 = 0;
        q->unk_02 = 0x1000;
        q->unk_04 = 0x1000;
    }
    {
        u32 saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (self->unk_100 != NULL) {
            u8 *b = self->unk_100;
            if (b != NULL) {
                Ov011B_Dtor(b);
                func_0203de1c(b);
            }
            self->unk_100 = NULL;
        }
        data_02097dd0->cur = saved;
    }
    {
        u32 saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (self->unk_104 != NULL) {
            u8 *b = self->unk_104;
            if (b != NULL) {
                func_ov011_02202cac(b + 0x14);
                func_0203de1c(b);
            }
            self->unk_104 = NULL;
        }
        data_02097dd0->cur = saved;
    }
    {
        u32 saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (self->unk_108 != NULL) {
            func_0203de1c(self->unk_108);
            self->unk_108 = NULL;
        }
        data_02097dd0->cur = saved;
    }
    {
        u32 saved = data_02097dd0->cur;
        data_02097dd0->cur = data_02097dd0->def;
        if (self->unk_10c != NULL) {
            func_0203de1c(self->unk_10c);
            self->unk_10c = NULL;
        }
        data_02097dd0->cur = saved;
    }
    self->b0 = 0;
    self->b1 = 0;
    self->unk_f2 = 0;
    self->unk_f4 = data_ov011_02207278.x;
    self->unk_f8 = data_ov011_02207278.y;
    self->unk_fc = data_ov011_02207278.z;
    self->unk_100 = NULL;
    self->unk_104 = NULL;
    self->unk_108 = NULL;
    self->unk_10c = NULL;
}

}
}  // namespace m_0220068c
