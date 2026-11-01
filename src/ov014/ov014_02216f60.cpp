#include "ov014/ov014.h"

typedef s16 fx16;
typedef s32 fx32;
typedef Ov014Vec VecFx32;
struct VecFx16 { fx16 x, y, z; };
#define FX32_ONE 0x1000

// A header's zero rotation and vector, plus copies made at startup, next to this TU's name,
// colour scale and offset, which other functions read. The readers of 0x021fa8f8..0x021fc220
// (three files, each in its own namespace) joined in round dtD.
extern const char *const data_ov014_02216430;
extern const fx16 data_ov014_0221643a[4];
extern const VecFx32 data_ov014_02216444;
extern const VecFx32 data_ov014_02216450;
extern char data_ov014_022170c0[];
const char *const data_ov014_02216430 = data_ov014_022170c0;
static const VecFx16 data_ov014_02216434 = {0, 0, 0};
const fx16 data_ov014_0221643a[4] = {0x1800, 0x1800, 0x1800, 0x159a};
const VecFx32 data_ov014_02216444 = {0, 0x4333, 0};
const VecFx32 data_ov014_02216450 = {0, 0, 0};
char data_ov014_022170c0[] = "nut00";
static const VecFx16 data_ov014_022170c6 = data_ov014_02216434;
static const VecFx32 data_ov014_022170cc = data_ov014_02216450;

// ---- merged from ov014_021fa8f8.cpp
namespace m_021fa8f8 {
extern "C" {

extern u8 data_ov014_022170d8[];
extern const u8 data_ov014_02216480[];
extern void *data_02097e4c;
extern BOOL func_ov000_0218cf5c(Ov014Actor *self);
extern BOOL func_ov000_0218f110(void *p);
extern BOOL func_02035b90(void *a, s32 b);
extern BOOL func_ov000_021903b4(void *p);
extern void func_0203f364(Ov014Sub48 *p);
extern BOOL func_020621c4(void);
extern void func_ov003_021d6bac(Ov014Actor *self, const void *p);
extern BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
extern void func_ov003_021cf1f0(void *a, s32 b, s32 c, const void *d);
extern Ov014Actor *func_ov000_0219bf90(void);
extern void *func_ov003_021ceff4(void *p);
extern void *func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern void func_ov000_021911c8(void *a, s32 b);

BOOL func_ov014_021fa8f8(Ov014Actor *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (FLD(s16, self, 0x124) >= 0) {
        r = (r & func_ov000_0218f110((u8 *)self + 0x124)) ? TRUE : FALSE;
    }
    return (r & func_02035b90(data_ov014_022170d8, 7)) ? TRUE : FALSE;
}

BOOL func_ov014_021fa94c(Ov014Actor *self) {
    BOOL r = func_ov003_021d16cc(self);
    FLD(Ov014Vec, self, 0x2d4) = FLD(Ov014Vec, self, 0x104);
    func_ov000_021903b4((u8 *)self + 0x25c);
    return r;
}

void func_ov014_021fa984(Ov014Actor *self) {
    func_ov003_021d1b88(self);
    func_ov000_02190a80((u8 *)self + 0x25c, func_0203db40((u8 *)self + 0x24));
}

void func_ov014_021fa9a8(Ov014Actor *self) {
    Ov014Sub48 *m;
    Ov014Sub44 *n;
    func_ov003_021d112c(self);
    m = self->unk_48;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    m = self->unk_48;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    m = self->unk_48;
    m->unk_9a_2 = 0;
    m->unk_9a_5 = 0;
    self->unk_48->unk_30 = 0;
    m = self->unk_48;
    FLD(s32, m, 0x5c) = -0x1800;
    FLD(s32, m, 0x60) = 0x2000;
    FLD(s32, m, 0x64) = 0;
    n = self->unk_44;
    Ov014_VecSet(&FLD(Ov014Vec, n, 0xc), -0x1000, FLD(Ov014Vec, n, 0xc).y, 0);
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov014_0221643a);
        FLD(s16, self, 0x364) = 0x1800;
    }
    self->pos = FLD(Ov014Vec, self, 0xf8);
    self->rot[1] = 0;
    func_ov000_0218ffdc((u8 *)self + 0x25c, (u8 *)self + 0x124, 0, 1);
    FLD(s32, self, 0x304) = 0x2000;
    FLD(s32, self, 0x308) = 0x2000;
    FLD(s32, self, 0x30c) = 0x1000;
    FLD(Ov014Flags, self, 0x31e).b0 = 1;
    func_ov003_021cf1f0((u8 *)self + 0x348, 0, 4, data_ov014_02216480);
}

void func_ov014_021faae8(Ov014Actor *self) {
    s32 pct;
    u8 k;
    s32 f;
    u8 *p;
    Ov014Actor *a;
    self->unk_93_4 = 0;
    if (!Ov014_GameIdle()) {
        return;
    }
    self->unk_90 = 0xffff;
    a = func_ov000_0219bf90();
    if (a != NULL) {
        self->unk_90 = a->id;
    }
    self->unk_93_4 = 1;
    k = self->unk_40->unk_13;
    pct = (u16)(self->unk_50[0] * 100 / self->unk_50[1]);
    if (k == 1) {
        f = FLD(s32, self, 0xf4);
        if (f == 0) {
            u8 *t = FLD(u8 *, self, 0x354);
            FLD(u8 *, self, 0x344) = FLD(u8 *, t, 0xc) + FLD(u16, t, 8) * 8;
            func_ov003_021ceff4((u8 *)self + 0x348);
            switch (*FLD(s16 *, self, 0x344)) {
            case 0:
                FLD(s32, self, 0xf4) |= 4;
                FLD(u8, self, 0x11f) = 0;
                self->unk_40->flags |= 0x8000;
                break;
            case 1:
                FLD(s32, self, 0xf4) |= 8;
                FLD(u8, self, 0x11f) = 0;
                self->unk_40->flags |= 0x10000;
                break;
            }
        } else if (f & 1) {
            p = FLD(u8 *, self, 0x344);
            if (p != NULL) {
                self->unk_b6++;
                if (self->unk_b6 >= FLD(u16, p, 6)) {
                    FLD(s32, self, 0xf4) = f ^ 1;
                    self->unk_b6 = 0;
                }
            } else if ((s32)++self->unk_b6 >= 0x19) {
                FLD(s32, self, 0xf4) = f ^ 1;
                self->unk_b6 = 0;
            }
        }
    }
    if (self->unk_30 & 0x200) {
        if (func_02040498(1)) {
            func_02049f44(data_02097e4c, 0x905, &self->pos, 0);
        } else {
            func_02049f44(data_02097e4c, 0xa05, &self->pos, 0);
        }
        if (self->unk_50[0] != 0 && k != 0xf && k != 0x10) {
            self->unk_40->flags = 0;
            self->unk_40->flags |= 0x40000;
        }
        if (FLD(s16, self, 0x364) == 0x1000 && pct <= 50 && !(FLD(s32, self, 0xf4) & 0x1000)) {
            FLD(s32, self, 0xf4) |= 0x1000;
            self->unk_40->flags = 0;
            self->unk_40->flags |= 0x200000;
        }
        FLD(u16, self, 0x312) = 0x14bf;
        FLD(u16, self, 0x314) = 0x14bf;
        FLD(u16, self, 0x316) = 0xb;
        FLD(u16, self, 0x318) = 0xa;
    }
    self->unk_ea_0 = 3;
}


}
}  // namespace m_021fa8f8

// ---- merged from ov014_021fad9c.cpp
namespace m_021fad9c {
extern "C" {

extern u8 data_ov014_022170d8[];
extern const u8 data_ov014_02216480[];
extern void *data_02097e4c;
extern BOOL func_ov000_0218cf5c(Ov014Actor *self);
extern BOOL func_ov000_0218f110(void *p);
extern BOOL func_02035b90(void *a, s32 b);
extern BOOL func_ov000_021903b4(void *p);
extern void func_0203f364(Ov014Sub48 *p);
extern BOOL func_020621c4(void);
extern void func_ov003_021d6bac(Ov014Actor *self, const void *p);
extern BOOL func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
extern void func_ov003_021cf1f0(void *a, s32 b, s32 c, const void *d);
extern Ov014Actor *func_ov000_0219bf90(void);
extern void *func_ov003_021ceff4(void *p);
extern void *func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern void func_ov000_021911c8(void *a, s32 b);

void func_ov014_021fad9c(Ov014Actor *self) {
    const char *anim;
    if (self->unk_40->state != 0) {
        return;
    }
    anim = data_ov014_02216430;
    func_ov000_02190cb0(self->unk_38, anim, 0x111, 0);
    func_ov000_021911c8(self->unk_38, 0x1ec);
    func_ov000_021915a0(self->unk_38);
    func_ov000_02190cb0((u8 *)self + 0x25c, anim, 0x111, 0);
    func_ov000_021911c8((u8 *)self + 0x25c, 0x1ec);
    func_ov000_021915a0((u8 *)self + 0x25c);
    self->unk_9c = 0;
    self->unk_a0 = 0;
    self->unk_a4 = 0;
    self->unk_a8 = 0;
    self->unk_40->state++;
}

extern const u8 data_ov014_022170fe[];
extern const u8 data_ov014_02217104[];
extern void *data_0214a420;
extern void *data_ov000_021ccd68;
extern BOOL func_ov000_02191120(void *a);
extern void VEC_Add(const Ov014Vec *a, const Ov014Vec *b, Ov014Vec *out);
extern Ov014Actor *func_02065f88(s32 id, Ov014Vec *pos);
extern void *func_020657b0(void *a, void *b);
extern void func_ov014_021fbb90(Ov014Actor *self, s16 n);
extern Ov014Actor *func_ov000_0218e640(void *mgr, u16 id);
void func_020627a0(u16 a, u16 b);
void func_020627dc(s32 a);
void func_ov000_02182590(void *p);

void func_ov014_021fae44(Ov014Actor *self) {
    Ov014Vec v;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov014_022170fe, 0x111, 0);
        func_ov000_021911c8(self->unk_38, 0x400);
        self->unk_84.x = self->pos.x;
        self->unk_84.y = self->pos.y - 0x1333;
        self->unk_84.z = self->pos.z;
        self->unk_40->state++;
        break;
    case 1:
        if (func_ov000_02191120(self->unk_38)) {
            Ov014Actor *e;
            VEC_Add(&self->pos, &data_ov014_02216444, &v);
            e = func_02065f88(0x195, &v);
            FLD(u32, self, 0x120) = FLD(u32, e, 0x24);
            func_02049f44(data_02097e4c, 0x36, &v, 0);
            self->unk_40->state++;
        } else {
            self->pos.y += (s32)(((s64)(self->unk_84.y - self->pos.y) * 0x133 + 0x800) >> 12);
        }
        break;
    case 2:
        if (func_020657b0(data_0214a420, FLD(void *, self, 0x120)) == NULL) {
            func_ov014_021fbb90(self, 1);
            self->unk_40->state = 10;
        }
        break;
    case 10: {
        Ov014Actor *a;
        u16 id = FLD(u16, self, 0xde);
        if (data_ov000_021ccd68 == NULL) {
            a = NULL;
        } else {
            a = func_ov000_0218e640(data_ov000_021ccd68, id);
        }
        if (a != NULL) {
            Ov014Sub40 *s = a->unk_40;
            if ((s != NULL ? s->unk_13 : 0) == 11) {
                self->unk_40->state++;
            }
        }
        break;
    }
    case 11:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217104, 0x400, 0);
        func_ov000_021911c8(self->unk_38, 0x4cd);
        func_02049f44(data_02097e4c, 0x64, &self->pos, 0);
        self->unk_40->state++;
        break;
    case 12:
        if (func_ov000_02191120(self->unk_38)) {
            self->unk_40->state = 0x1e;
        }
        break;
    case 0x1e: {
        Ov014Actor *a;
        u16 id = FLD(u16, self, 0xde);
        if (data_ov000_021ccd68 == NULL) {
            a = NULL;
        } else {
            a = func_ov000_0218e640(data_ov000_021ccd68, id);
        }
        if (a == NULL) {
            u8 *g;
            func_ov000_02190cb0(self->unk_38, data_ov014_02216430, 0x400, 0);
            func_ov000_021911c8(self->unk_38, 0x1ec);
            func_ov000_021915a0(self->unk_38);
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            g = (u8 *)data_ov000_021ccd54;
            g[0xac] = 1;
            func_ov000_02182590(g + 0xac);
            self->unk_40->state++;
        }
        break;
    }
    }
}

extern const Ov014Vec data_ov014_0221645c;
extern Ov014Actor *func_ov000_0218d240(Ov014Actor *self);
extern void func_ov014_021fbab8(Ov014Actor *self, s16 n);

void func_ov014_021fb198(Ov014Actor *self) {
    Ov014Vec v;
    Ov014Vec w;
    Ov014Actor *t = func_ov000_0218d240(self);
    v.x = t->pos.x;
    v.y = t->pos.y;
    v.z = t->pos.z;
    switch (self->unk_40->state) {
    case 0: {
        Ov014Actor *e;
        func_ov000_02190cb0((u8 *)self + 0x25c, data_ov014_022170fe, 0x111, 0);
        func_ov000_021911c8((u8 *)self + 0x25c, 0x400);
        FLD(s16, self, 0x11c) = 0;
        FLD(Ov014Vec, self, 0x110) = v;
        FLD(u8, self, 0x11e) = 0;
        VEC_Add(&FLD(Ov014Vec, self, 0x104), &data_ov014_0221645c, &w);
        e = func_02065f88(0x5e3, &w);
        FLD(u32, self, 0x120) = FLD(u32, e, 0x24);
        VEC_Add(&FLD(Ov014Vec, self, 0x104), &data_ov014_0221645c, &w);
        func_02065f88(0xcb, &w);
        self->unk_40->state++;
        break;
    }
    case 1: {
        Ov014Actor *e;
        if (func_020657b0(data_0214a420, FLD(void *, self, 0x120)) != NULL) {
            break;
        }
        func_ov000_02190cb0((u8 *)self + 0x25c, data_ov014_02217104, 0x400, 0);
        func_ov000_021911c8((u8 *)self + 0x25c, 0x4cd);
        func_02049f44(data_02097e4c, 0x900, &self->pos, 0);
        VEC_Add(&FLD(Ov014Vec, self, 0x104), &data_ov014_0221645c, &w);
        e = func_02065f88(0x68, &w);
        e->v10(&data_ov014_02216450);
        e->v34(0xbfff, self->rot[1], self->rot[2]);
        FLD(u32, self, 0x120) = FLD(u32, e, 0x24);
        self->unk_40->state = 10;
        break;
    }
    case 10: {
        u8 b = FLD(u8, self, 0x11e);
        if (b == 1) {
            if (FLD(s32, self, 0x110) >= v.x) {
                FLD(s16, self, 0x11c) = 10;
            }
        }
        func_ov014_021fbab8(self, b + FLD(s16, self, 0x11c));
        self->unk_40->timer = 0;
        self->unk_40->state++;
    }
    case 11: {
        Ov014V *e;
        Ov014Sub40 *s = self->unk_40;
        s->timer++;
        if (s->timer >= 14) {
            u16 n;
            self->unk_40->timer = 0;
            n = 0;
            if (++FLD(u8, self, 0x11e) < 6) {
                self->unk_40->state = 10;
            } else {
                if (FLD(u16 *, self, 0x344) != NULL) {
                    n = FLD(u16 *, self, 0x344)[2];
                }
                if (++FLD(u8, self, 0x11f) >= n) {
                    self->unk_40->state = 0x1e;
                } else {
                    func_ov000_02190cb0((u8 *)self + 0x25c, data_ov014_02216430, 0x111, 0);
                    func_ov000_021911c8((u8 *)self + 0x25c, 0x1ec);
                    func_ov000_021915a0((u8 *)self + 0x25c);
                    self->unk_40->state = 0x14;
                }
            }
        }
        e = (Ov014V *)func_020657b0(data_0214a420, FLD(void *, self, 0x120));
        if (e != NULL) {
            e->v0c(FLD(s32, e, 0x40) + 0xcd);
        }
        break;
    }
    case 0x14: {
        Ov014Sub40 *s = self->unk_40;
        s->timer++;
        if (s->timer >= FLD(u16 *, self, 0x344)[1]) {
            self->unk_40->timer = 0;
            self->unk_40->state = 0;
        }
        break;
    }
    case 0x1e:
        if (FLD(u32, self, 0xf4) & 4) {
            FLD(u32, self, 0xf4) ^= 4;
        }
        FLD(u32, self, 0xf4) |= 1;
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
}

extern void func_020639d4(void *e, s32 a, s32 b);
extern void *func_ov000_02199ba0(void *p);

void func_ov014_021fb554(Ov014Actor *self) {
    Ov014Vec v;
    func_ov000_0218d240(self);
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov014_022170fe, 0x111, 0);
        func_ov000_021911c8(self->unk_38, 0x400);
        self->unk_40->state++;
        break;
    case 1:
        if (func_ov000_02191120(self->unk_38)) {
            Ov014Actor *e;
            VEC_Add(&self->pos, &data_ov014_02216444, &v);
            e = func_02065f88(0x195, &v);
            func_020639d4(e, 0x36, 0);
            FLD(u32, self, 0x120) = FLD(u32, e, 0x24);
            self->unk_40->state++;
        }
        break;
    case 2:
        if (func_020657b0(data_0214a420, FLD(void *, self, 0x120)) == NULL) {
            func_02049f44(data_02097e4c, 0xa01, &self->pos, 0);
            func_ov014_021fbb90(self, 0);
            self->unk_40->state = 10;
        }
        break;
    case 10: {
        Ov014Actor *a;
        void *r;
        u16 id = FLD(u16, self, 0xde);
        if (data_ov000_021ccd68 == NULL) {
            a = NULL;
        } else {
            a = func_ov000_0218e640(data_ov000_021ccd68, id);
        }
        if (a != NULL) {
            if (FLD(void *, a, 0x4c) == NULL) {
                break;
            }
            r = func_ov000_02199ba0(FLD(void *, a, 0x4c));
            if (r == NULL) {
                break;
            }
            {
                Ov014Sub40 *s = a->unk_40;
                if ((s != NULL ? s->unk_13 : 0) == 11 && FLD(u16, r, 0xe) == 0x5c15) {
                    self->unk_40->state++;
                }
            }
        } else {
            self->unk_40->state = 0;
        }
        break;
    }
    case 11:
        func_ov000_02190cb0(self->unk_38, data_ov014_02217104, 0x400, 0);
        func_ov000_021911c8(self->unk_38, 0x4cd);
        func_02049f44(data_02097e4c, 0x64, &self->pos, 0);
        self->unk_40->state++;
        break;
    case 12:
        if (func_ov000_02191120(self->unk_38)) {
            u16 n = 0;
            if (FLD(u16 *, self, 0x344) != NULL) {
                n = FLD(u16 *, self, 0x344)[2];
            }
            if (++FLD(u8, self, 0x11f) >= n) {
                self->unk_40->state = 0x1e;
                break;
            }
            func_ov000_02190cb0(self->unk_38, data_ov014_02216430, 0x111, 0);
            func_ov000_021911c8(self->unk_38, 0x1ec);
            func_ov000_021915a0(self->unk_38);
            self->unk_40->state = 0x14;
        }
        break;
    case 0x14: {
        Ov014Sub40 *s = self->unk_40;
        s->timer++;
        if (s->timer >= FLD(u16 *, self, 0x344)[1]) {
            self->unk_40->timer = 0;
            self->unk_40->state = 0;
        }
        break;
    }
    case 0x1e:
        if (FLD(u32, self, 0xf4) & 8) {
            FLD(u32, self, 0xf4) ^= 8;
        }
        FLD(u32, self, 0xf4) |= 1;
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
}

}
}  // namespace m_021fad9c

// ---- merged from ov014_021fb8dc.cpp
namespace m_021fb8dc {
struct Ov014SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov014Spawn_Init(Ov014SpawnDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

static inline void Ov014Spawn_Set(Ov014SpawnDesc *d, u16 k) {
    d->kind = k;
    d->flags = k & 0xf000;
}

extern "C" {

extern const s32 data_ov014_022164e8[];
extern u8 data_ov014_022172c4[];
extern void *data_ov000_021ccd68;
extern void func_ov000_021911c8(void *a, s32 b);
extern void func_ov000_0218e8ec(void *mgr, u16 id, s32 msg);
extern void func_0203f364(Ov014Sub48 *p);
extern void func_ov003_021d6a3c(Ov014Actor *self, s32 a, s32 b, s32 c);
extern Ov014Actor *func_ov000_02192b24(Ov014SpawnDesc *desc);
extern void func_ov000_0219bebc(Ov014Actor *a, s32 b);
extern void VEC_Add(const Ov014Vec *a, const Ov014Vec *b, Ov014Vec *out);
extern void func_ov000_021984f4(void *a, s32 b, s32 c);
extern void func_ov000_0219864c(void *a, s32 b, s32 c);
extern void *func_ov000_02194074(void *self);
extern void *func_ov003_021da940(void *p);
extern void func_ov000_02194758(void *self);

void func_ov014_021fb8dc(Ov014Actor *self) {
    if (self->unk_40->state != 0) {
        return;
    }
    FLD(u16, self, 0x312) = 0x14bf;
    FLD(u16, self, 0x314) = 0x14bf;
    FLD(u16, self, 0x316) = 0xb;
    FLD(u16, self, 0x318) = 0xa;
    FLD(s32, self, 0xf4) = 1;
    func_ov000_02198360(self->unk_40, 1, 0);
}

void func_ov014_021fb92c(Ov014Actor *self) {
    FLD(s32, self, 0xf4) = 1;
    func_ov000_02198360(self->unk_40, 1, 0);
}

void func_ov014_021fb948(Ov014Actor *self) {
    const char *anim;
    Ov014Sub40 *st;
    FLD(Ov014Flags, self, 0xea).b9 = 1;
    switch (self->unk_40->state) {
    case 0:
        anim = data_ov014_02216430;
        func_ov000_02190cb0(self->unk_38, anim, 0x111, 0);
        func_ov000_021911c8(self->unk_38, 0x1ec);
        func_ov000_021915a0(self->unk_38);
        func_ov000_02190cb0((u8 *)self + 0x25c, anim, 0x111, 0);
        func_ov000_021911c8((u8 *)self + 0x25c, 0x1ec);
        func_ov000_021915a0((u8 *)self + 0x25c);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4821, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4822, 0x15);
        {
            Ov014Sub48 *m = self->unk_48;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
        }
        {
            Ov014Sub44 *n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
        }
        FLD(u16, FLD(u8 *, self, 0x4c), 0x1c) = 0xffff;
        self->unk_40->state++;
    case 1:
        st = self->unk_40;
        st->timer++;
        if (st->timer > 0x3c) {
            func_ov003_021d6a3c(self, 0, 1, 1);
            self->unk_40->state++;
        }
        break;
    }
}

void func_ov014_021fbab8(Ov014Actor *self, s16 n) {
    Ov014SpawnDesc desc;
    Ov014Actor *o;
    Ov014Spawn_Init(&desc, 0xffff);
    Ov014Spawn_Set(&desc, 0x4821);
    o = func_ov000_02192b24(&desc);
    if (o == NULL) {
        return;
    }
    o->unk_18 = n;
    o->pos = FLD(Ov014Vec, self, 0x110);
    func_ov000_0219bebc(o, FLD(s16, self, 0x364));
    o->v04();
    FLD(Ov014Flags8, o, 0x16).b0 = 1;
    o->unk_90 = self->unk_90;
    if (FLD(u8 *, o, 0x4c) != NULL) {
        FLD(u16, FLD(u8 *, o, 0x4c), 0x1c) = self->id;
    }
}

void func_ov014_021fbb90(Ov014Actor *self, s16 n) {
    Ov014SpawnDesc desc;
    Ov014Vec v;
    Ov014Actor *o;
    Ov014Spawn_Init(&desc, 0xffff);
    Ov014Spawn_Set(&desc, 0x4822);
    o = func_ov000_02192b24(&desc);
    if (o == NULL) {
        return;
    }
    VEC_Add(&self->pos, &data_ov014_02216444, &v);
    o->pos = v;
    o->unk_18 = n;
    func_ov000_0219bebc(o, FLD(s16, self, 0x364));
    o->v04();
    FLD(Ov014Flags8, o, 0x16).b0 = 1;
    o->unk_90 = self->unk_90;
    FLD(u16, self, 0xde) = o->id;
    if (FLD(u8 *, o, 0x4c) != NULL) {
        FLD(u16, FLD(u8 *, o, 0x4c), 0x1c) = self->id;
    }
}

void func_ov014_021fbc88(Ov014Actor *self) {
    if (self->unk_44 != NULL) {
        func_ov000_021984f4(self->unk_44, 0, 0);
    }
}

void func_ov014_021fbca8(Ov014Actor *self) {
    if (self->unk_48 != NULL) {
        func_ov000_0219864c(self->unk_48, 0, 0);
    }
}

void func_ov014_021fbcc8(void) {
}

void func_ov014_021fbccc(void) {
}

void func_ov014_021fbcd0(void) {
}

void func_ov014_021fbcd4(void) {
}

void func_ov014_021fbcd8(void) {
}

void func_ov014_021fbcdc(void) {
}

void func_ov014_021fbce0(void) {
}

void func_ov014_021fbce4(Ov014Actor *self) {
    self->v54();
}

void func_ov014_021fbcf8(Ov014Actor *self) {
    self->unk_ee_5 = 1;
    self->v70();
}

void func_ov014_021fbd18(Ov014Actor *self) {
    self->unk_ee_2 = 2;
    self->v64();
}

void func_ov014_021fbd3c(Ov014Actor *self) {
    self->v60();
}

void func_ov014_021fbd50(Ov014Actor *self) {
    self->v7c();
}

#pragma force_active on
Ov014Actor *func_ov014_021fbd64(Ov014Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov014_022172c4;
    FLD(u8, self, 0xce) = 0;
    FLD(void *, self, 0xd0) = NULL;
    return self;
}
#pragma force_active reset

static inline void Ov014_FreeD0(Ov014Actor *self) {
    u32 saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (FLD(void *, self, 0xd0) != NULL) {
        void *p = FLD(void *, self, 0xd0);
        if (p != NULL) {
            func_ov003_021da940(p);
            func_0203de1c(p);
        }
        FLD(void *, self, 0xd0) = NULL;
    }
    data_02097dd0->cur = saved;
}

Ov014Actor *func_ov014_021fbd90(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_022172c4;
    Ov014_FreeD0(self);
    func_ov000_0219429c(self);
    return self;
}

Ov014Actor *func_ov014_021fbe00(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_022172c4;
    Ov014_FreeD0(self);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov014_021fbe78(Ov014Actor *self) {
    s16 n;
    s32 *p;
    func_ov000_02194758(self);
    n = self->unk_18;
    if (self->pos.y > 0x5000) {
        self->pos.y = 0x5000;
    }
    if (n < 10) {
        self->pos.x = self->pos.x + data_ov014_022164e8[n];
    } else {
        self->pos.x = self->pos.x - data_ov014_022164e8[(s16)(n % 10)];
    }
    p = (s32 *)func_0203dd9c(4);
    if (p != NULL) {
        *p = 0;
    }
    FLD(s32 *, self, 0xd0) = p;
}


extern void *data_02097e4c;
extern char data_ov014_022171d0[];
extern char data_ov014_022171df[];
extern char data_ov014_022171f1[];
extern char data_ov014_022171fd[];
extern Ov014V *func_02066900(const char *arc, const char *name, Ov014Vec *pos);
extern Ov014V *func_02066774(const void *a, const void *b, s32 c, Ov014Vec *pos);
extern void MIi_CpuClear32(u32 data, void *dst, u32 size);
extern void func_ov003_021da9ac(void *p, s32 id, void *e);
extern BOOL func_ov003_021daa0c(void *p, s32 id);
extern void func_ov003_021daa6c(void *p, s32 id);
extern void *func_0204a028(void *a, s32 b, Ov014Vec *c, s32 d);
extern void *func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern s32 FX_Div(s32 a, s32 b);
extern void func_020639d4(void *e, s32 a, s32 b);
extern BOOL func_ov000_0219aca8(Ov014Actor *a, Ov014Actor *b, u16 c, u8 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern Ov014Actor *func_ov000_0218d240(Ov014Actor *self);

struct Ov014Ccd190 {
    u8 b0 : 2;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 3;
};

void func_ov014_021fbf0c(Ov014Actor *self) {
    Ov014V *e;
    switch (self->unk_40->state) {
    case 0:
        e = func_02066900(data_ov014_022171d0, data_ov014_022171df, &self->pos);
        e->v24(0, 0xcd, 0);
        e->v0c(0x1333);
        MIi_CpuClear32(0xffffffff, (u8 *)e + 0x84, 0x40);
        func_ov003_021da9ac(FLD(void *, self, 0xd0), 0xff, e);
        func_0204a028(data_02097e4c, 0x11, &self->pos, 0xa);
        e = func_02066774(data_ov014_022171d0, data_ov014_022171f1, 0, &self->pos);
        e->v24(0, 0xcd, 0);
        e->v0c(0x2000);
        FLD(u8, e, 0x28) = 0;
        FLD(s32, e, 0xc8) = 1;
        FLD(s32, e, 0x7c) = FX_Div(0x1e000, 0x1f000);
        func_ov003_021da9ac(FLD(void *, self, 0xd0), 0xfe, e);
        self->unk_40->state++;
    case 1:
        if (func_ov003_021daa0c(FLD(void *, self, 0xd0), 0xfe)) {
            break;
        }
        func_ov003_021daa6c(FLD(void *, self, 0xd0), 0xff);
        self->unk_40->state++;
    case 2: {
        Ov014Game54 *g;
        e = func_02066774(data_ov014_022171d0, data_ov014_022171fd, 0, &self->pos);
        e->v14(0x14cd, 0x1800, 0x14cd);
        FLD(s32, e, 0x3c) = 0x1800;
        FLD(s32, e, 0x7c) = FX_Div(0x1e000, 0x1f000);
        FLD(u8, e, 0x28) = 0;
        func_020639d4(e, 0x79, 3);
        func_ov003_021da9ac(FLD(void *, self, 0xd0), 0xfd, e);
        func_02049f44(data_02097e4c, 0x19, &self->pos, 0x140);
        g = data_ov000_021ccd54;
        FLD(Ov014Ccd190, g, 0x190).b2 = 0;
        FLD(Ov014Ccd190, g, 0x190).b3 = 1;
        FLD(Ov014Ccd190, g, 0x190).b4 = 0;
        FLD(u8, g, 0x18d) = 0xf;
        FLD(u8, g, 0x18e) = 5;
        FLD(u8, g, 0x18f) = 5;
        self->unk_40->state++;
    }
    case 3: {
        Ov014Param *pr = FLD(Ov014Param *, self, 0x4c);
        if (func_ov000_0219aca8(self, self, pr->unk_08, FLD(u16, pr, 0xa), 0, 0, 0x119a, 0x5000, 0x6b, 0x1000)) {
            Ov014Actor *o = func_ov000_0218d240(self);
            if (o != NULL) {
                Ov014Vec v;
                v.x = o->pos.x;
                v.y = o->pos.y;
                v.z = o->pos.z;
                func_02049f44(data_02097e4c, 0x10, &v, 0);
            }
        }
        if (!func_ov003_021daa0c(FLD(void *, self, 0xd0), 0xfd)) {
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
        break;
    }
    }
    func_ov003_021dacfc(FLD(void *, self, 0xd0));
}

}
}  // namespace m_021fb8dc
