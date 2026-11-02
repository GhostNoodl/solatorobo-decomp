#include "ov012/ov012.h"

typedef Ov012Vec VecFx32;

// This TU's .rodata from its base to the vector the static initialiser copies, and its .data up to
// the copy. The copied vector and its source are weak: the stub loads each through its own pool
// word, not from the section base. The objects before the empty asm function are the TU's
// size-sorted group (order found with solve2.py); the rest keep definition order.
// The functions of 0x022032f4..0x0220574c (five files, merged in round dtB, each in its own
// namespace) are part of this TU: they read the name pointers through the .rodata base plus an
// offset, and name them (data_ov012_0220a57c/a580/a584) instead of a data_ov012_0220a57c[n] array
// view (ov012.h now declares it as the single pointer it is). ov012_02202994.cpp
// (0x02202994..0x022032f4, which passes data_ov012_0220a59a) joined in round dtD.
struct Ov012Rot { u16 x, y, z; };

extern "C" {

extern const char *const data_ov012_0220a57c;
extern const char *const data_ov012_0220a580;
extern const char *const data_ov012_0220a584;
extern const Ov012Rot data_ov012_0220a588;
extern const s16 data_ov012_0220a58e[6];
extern const s16 data_ov012_0220a59a[4];
extern const s16 data_ov012_0220a5a2[5];
extern const VecFx32 data_ov012_0220a5ac[3];
extern const VecFx32 data_ov012_0220a5d0;
extern const Ov012Rot data_ov012_0220afa0;
extern char data_ov012_0220afa6[];
extern char data_ov012_0220afac[];
extern char data_ov012_0220afb2[];
extern const VecFx32 data_ov012_0220afb8;

const Ov012Rot data_ov012_0220a588 = {0, 0, 0};
char data_ov012_0220afa6[] = "nut00";
char data_ov012_0220afac[] = "att00";
const Ov012Rot data_ov012_0220afa0 = data_ov012_0220a588;
const char *const data_ov012_0220a580 = data_ov012_0220afb2;
const char *const data_ov012_0220a584 = data_ov012_0220afac;
const char *const data_ov012_0220a57c = data_ov012_0220afa6;
const s16 data_ov012_0220a58e[6] = {700, 600, 500, 0x5fff, 0, 0};
char data_ov012_0220afb2[] = "run00";

static asm void Ov012_Dummy(void) {}

const s16 data_ov012_0220a59a[4] = {0x1800, 0x1800, 0x1800, 0x1800};
const s16 data_ov012_0220a5a2[5] = {0, 0x4cd, 0, 0, -1};
const VecFx32 data_ov012_0220a5ac[3] = {{-0x34cd, 0x2000, 0x2333}, {-0xccd, 0, 0x2000}, {0, 0x1800, -0x1800}};
__declspec(weak) const VecFx32 data_ov012_0220a5d0 = {0, 0, 0};
__declspec(weak) const VecFx32 data_ov012_0220afb8 = data_ov012_0220a5d0;

}


// ---- merged from ov012_02202994.cpp
namespace m_02202994 {
extern "C" {
void func_ov012_02202994(Ov012ActExVt_0220af10 *self) {
    if (self->unk_40->state == 0) {
        self->unk_4c->target = self->unk_e0;
        self->unk_48->unk_30 = 0x40000000;
    }
    func_ov000_02196860(self);
}
}

extern "C" {
void func_ov012_022029c8(Ov012ActExVt_0220af10 *self) {
    if (self->unk_40->state == 0) {
        self->unk_64 = 0x1800;
        func_02065f88(0x69, &self->pos);
    }
    func_ov000_0219763c(self);
}
}

extern "C" {
void func_ov012_02202a00(Ov012Actor *self) {
    if (self->unk_38 != NULL) {
        func_ov000_02190a80(self->unk_38, func_0203db40((u8 *)self + 0x24));
    }
}
}

extern "C" {
void func_ov012_02202a2c(void) {
}
}

extern "C" {
void func_ov012_02202a30(void) {
}
}

extern "C" {
void func_ov012_02202a34(void) {
}
}

extern "C" {
void func_ov012_02202a38(void) {
}
}

extern "C" {
void func_ov012_02202a3c(void) {
}
}

extern "C" {
void func_ov012_02202a40(void) {
}
}

extern "C" {
void func_ov012_02202a44(void) {
}
}

extern "C" {
void *func_ov012_02202a48(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}
}

extern "C" {
void *func_ov012_02202a64(void *self) {
    func_ov000_0219429c(self);
    return self;
}
}

extern "C" {
void func_ov012_02202a78(Ov012Actor *self, Ov012Actor *other) {
    u16 *hp = other->unk_50;
    s32 pct = (u16)(hp[0] * 100 / hp[1]);
    u16 *st = FLD(u16 *, self, 0xc);
    if (pct >= 70) {
        if (st[2] != 0) {
            func_ov003_021cf278(self, 0, 0);
        }
    } else if (pct >= 35) {
        if (st[2] != 1) {
            func_ov003_021cf278(self, 1, 0);
        }
    } else {
        if (st[2] != 2) {
            func_ov003_021cf278(self, 2, 0);
        }
    }
}
}

extern "C" {
extern u8 data_ov012_0220afe4[];
#pragma force_active on
Ov012Act_02202b10 *func_ov012_02202b10(Ov012Act_02202b10 *self) {
    func_ov003_021d0c1c(self);
    FLD(void *, self, 0) = data_ov012_0220afe4;
    func_ov003_021ceedc((u8 *)self + 0x108);
    self->unk_f8 = 0;
    self->unk_f6 = 0;
    self->unk_f0 = 0x200000;
    self->unk_f9 = 0;
    self->unk_100 = 0;
    FLD(s32, self, 0x104) = 0;
    self->unk_fa = 0;
    self->unk_fb = 0;
    self->unk_fc = 0;
    self->unk_fd = 0;
    self->unk_124 = 0x1000;
    return self;
}
#pragma force_active reset
}

extern "C" {
extern u8 data_ov012_0220afe4[];
void *func_ov012_02202b74(void *self) {
    FLD(void *, self, 0) = data_ov012_0220afe4;
    Ov012_FreeFx(self, 0x100);
    func_ov003_021cef0c((u8 *)self + 0x108);
    func_ov003_021d0edc(self);
    return self;
}
}

extern "C" {
extern u8 data_ov012_0220afe4[];
void *func_ov012_02202bec(void *self) {
    FLD(void *, self, 0) = data_ov012_0220afe4;
    Ov012_FreeFx(self, 0x100);
    func_ov003_021cef0c((u8 *)self + 0x108);
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}
}

extern "C" {
void func_ov012_02202c6c(Ov012Actor *self) {
    func_ov003_021d0fc0(self);
    func_02049564(data_02097e4c, 1, 1);
    func_02049678(data_02097e4c, 4, 4, -1);
}
}

extern "C" {
BOOL func_ov012_02202ca4(Ov012Actor *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (r && !func_0204985c(data_02097e4c)) {
        r = FALSE;
    }
    return r;
}
}

extern "C" {
s32 func_ov012_02202cd4(Ov012Act_02202b10 *self, Ov012Msg *msg) {
    s32 r = 0;
    if (msg->type == 6) {
        self->unk_f8 = msg->idx;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
    } else {
        r = func_ov003_021d1c00(self, msg);
    }
    return r;
}
}

extern "C" {
extern const u8 data_ov012_0220a63c[];
extern const u8 data_ov012_0220a6c8[];
extern const u8 data_ov012_0220a708[];
void func_ov012_02202a78(Ov012Actor *self, Ov012Actor *other);
void func_ov012_02202d1c(Ov012Act_02202b10 *self) {
    Ov012Sub48 *m;
    u8 v;
    func_ov003_021d112c(self);
    FLD(s32 *, self, 0x100) = Ov012_NewFx();
    Ov012_ClearOwnerFlag(self);
    m = self->unk_48;
    m->unk_5c = 0;
    m->unk_60 = 0x1800;
    m->unk_64 = 0;
    v = data_ov000_021ccd54->unk_ca;
    self->unk_f4 = v;
    if (v == 3) {
        self->unk_50[1] = 700;
        self->unk_50[0] = 700;
    }
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov012_0220a59a);
        self->unk_124 = 0x1800;
    }
    func_ov003_021cf1f0((u8 *)self + 0x108, 0, 4, data_ov012_0220a63c);
    func_ov003_021cf1f0((u8 *)self + 0x108, 1, 8, data_ov012_0220a6c8);
    func_ov003_021cf1f0((u8 *)self + 0x108, 2, 8, data_ov012_0220a708);
    self->unk_11c = self;
    self->unk_118 = (void *)func_ov012_02202a78;
}
}

extern "C" {
extern void *func_ov003_021ceff4(void *p);
static inline BOOL Ov012_HasFlag(Ov012Sub40 *s, u64 f) {
    return (s->flags & f) != 0;
}
void func_ov012_02202e30(Ov012Act_02202b10 *self) {
    Ov012Vec v;
    u8 *pl;
    u8 kind;
    if (!Ov012_GameIdle()) {
        return;
    }
    self->unk_90 = 0xffff;
    pl = (u8 *)func_ov000_0219bf90();
    if (pl != NULL) {
        self->unk_90 = ((Ov012Actor *)pl)->id;
    }
    kind = self->unk_40->unk_13;
    self->unk_93_4 = 1;
    if (kind == 1) {
        u32 f0 = self->unk_f0;
        if (f0 == 0) {
            u8 *t = self->unk_114;
            u16 k = FLD(u16, t, 8);
            u8 *ent = FLD(u8 *, t, 0xc);
            s16 mode;
            self->unk_104 = ent + k * 8;
            mode = *(s16 *)(ent + k * 8);
            v = ((Ov012Actor *)pl)->pos;
            if (VEC_Distance(&self->pos, &v) <= 0x7000 && mode != 0 && mode != 4) {
                mode = 3;
            } else {
                func_ov003_021ceff4((u8 *)self + 0x108);
            }
            self->unk_40->timer = 0;
            switch (mode) {
            case 0:
                self->unk_f0 |= 0x80;
                self->unk_fb = 0;
                self->unk_40->flags |= 0x400000;
                break;
            case 1:
                self->unk_f0 |= 0x20;
                self->unk_fb = 0;
                self->unk_40->flags |= 0x4000;
                break;
            case 2:
                self->unk_f0 |= 4;
                self->unk_40->flags |= 0x8000;
                break;
            case 3:
                self->unk_f0 |= 8;
                self->unk_fb = 0;
                self->unk_fc = 0;
                self->unk_40->flags |= 0x10000;
                break;
            case 4:
                self->unk_f0 |= 0x10;
                self->unk_fb = 0;
                self->unk_fc = 0;
                self->unk_40->flags |= 0x20000;
                break;
            }
        } else if (f0 & 1) {
            u8 *p = self->unk_104;
            if (p != NULL) {
                self->unk_b6++;
                if (self->unk_b6 >= FLD(u16, p, 6)) {
                    self->unk_f0 = f0 ^ 1;
                    self->unk_b6 = 0;
                }
            } else {
                self->unk_b6++;
                if (self->unk_b6 >= 10) {
                    self->unk_f0 = f0 ^ 1;
                    self->unk_b6 = 0;
                }
            }
        } else if ((f0 & 0x200000) && !(f0 & 1) && self->unk_50[0] != 0) {
            f0 ^= 0x200000;
            f0 |= 0x80;
            self->unk_104 = NULL;
            self->unk_fb = 0;
            self->unk_f0 = f0;
            self->unk_40->flags |= 0x400000;
        }
    }
    if (self->unk_30 & 0x200) {
        if (self->unk_50[0] != 0) {
            BOOL f = FALSE;
            func_02049f44(data_02097e4c, 0x405, &self->pos, 0);
            if (self->unk_4c->unk_19 != 0) {
                f = TRUE;
            }
            if (kind != 0x16 && kind != 0xf && kind != 0x10 && kind != 0x11 && !f) {
                func_ov003_021daab0(((void *)self->unk_100));
                self->unk_104 = NULL;
                self->unk_f8 = 0;
                if (!(self->unk_f0 & 0x400000)) {
                    self->unk_f0 = 1;
                    self->unk_f0 |= 0x200000;
                }
            }
        } else {
            self->unk_40->flags = 0;
            self->unk_40->flags |= 0x100000;
        }
    }
    if (self->unk_f4 == 3) {
        if (self->unk_f0 != 0x400000) {
            u16 *hp = self->unk_50;
            s32 pct = (u16)(hp[0] * 100 / hp[1]);
            if ((self->unk_18 == 0 && pct < 0x46) || (self->unk_18 == 1 && pct < 0x32)) {
                u8 k;
                hp[5] = 10;
                k = self->unk_40->unk_13;
                if (k == 1 || k == 2 || k == 0x14) {
                    if (!Ov012_HasFlag(self->unk_40, 0x100000)) {
                        if (self->unk_e8 != 0) {
                            self->unk_e8 = 0;
                            self->unk_4c->unk_1a = 0;
                            self->unk_4c->type = *func_02070558((void *)self->kind);
                        }
                        self->unk_f0 = 0x400000;
                        self->unk_40->flags |= 2;
                    }
                }
            }
        } else {
            if (pl != NULL && FLD(u8, pl, 0xb2e) < 2) {
                FLD(u8, pl, 0xb2e) = 2;
            }
            Ov012Sub48 *m = self->unk_48;
            m->unk_9a_3 = 0;
            func_0203f364(m);
        }
    }
    if (func_ov003_021daa0c(((void *)self->unk_100), 0xfe) && pl != NULL && FLD(u16, pl, 0xb1e) == self->id) {
        func_ov003_021daa6c(((void *)self->unk_100), 0xfe);
    }
    if (pl != NULL) {
        FLD(Ov012Vec, pl, 0xb90) = self->pos;
        FLD(s32, pl, 0xb9c) = 0x59a;
    }
    func_ov003_021dacfc(((void *)self->unk_100));
}
}
}  // namespace m_02202994
// ---- merged from ov012_022032f4.cpp
namespace m_022032f4 {
extern "C" {
void func_ov012_022054cc(Ov012Act_02202b10 *self);
void func_ov012_022032f4(Ov012Act_02202b10 *self) {
    u32 f;
    if (self->unk_f0 & 0x400) {
        Ov012_ResetF0(self);
    }
    f = self->unk_f0;
    if (!(f & 0x400000)) {
        if (f & 1) {
            f ^= 1;
        }
        if (f & 0x200000) {
            f ^= 0x200000;
        }
        if (f != 0) {
            Ov012_ResetF0(self);
            self->unk_f0 |= 0x200000;
        }
    }
    if (self->unk_f0 & 0x400000) {
        Ov012Actor *o = func_ov000_0219bf90();
        if (o != NULL && !func_ov000_021b4738(o)) {
            func_ov012_022054cc(self);
        }
    }
    if (self->unk_40->state == 0) {
        func_ov003_021daab0(((void *)self->unk_100));
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a57c, 0x89, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_40->state++;
    }
    if (self->unk_93_4) {
        Ov012Actor *t = func_ov000_0218d240(self);
        Ov012Vec v;
        v.x = t->pos.x;
        v.y = t->pos.y;
        v.z = t->pos.z;
        func_ov000_0218d918(self, &v, 0xcd);
    }
    func_ov003_021d3524(self);
}
}
}  // namespace m_022032f4

// ---- merged from ov012_02203420.cpp
namespace m_02203420 {
extern "C" {

extern u16 func_01ffc128(u16 target, u16 cur, s32 a, s32 b, s32 c);
extern void func_ov003_021daae4(void *p, s32 a, Ov012Vec *v, void *b, void *c, void *d, void *e);
extern BOOL func_ov000_0219aca8(Ov012Obj *a, Ov012Obj *b, u16 c, u8 d, Ov012Vec *e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern Ov012Vec data_ov012_0220a748[];
extern Ov012Vec data_ov012_0220a7a8[];
extern Ov012Vec data_ov012_0220a65c[];

struct Ov012bEA {
    u16 b0 : 3;
};

void func_ov012_02203420(Ov012Act_02202b10 *self) {
    Ov012Vec tgt;
    Ov012Vec p;
    Ov012Sub40 *s;
    u8 k = data_ov000_021ccd54->unk_ca;
    if (k != 3) {
        if (k == 8) {
            tgt = data_ov012_0220a748[self->unk_fa];
        }
    } else {
        tgt = data_ov012_0220a7a8[self->unk_fa];
    }
    if (!func_01ffc198(&self->pos, &tgt, self->unk_64 + 0x400)) {
        self->unk_f6 = func_01ffc128(FX_Atan2(tgt.x - self->pos.x, tgt.z - self->pos.z), self->unk_f6, 0x1000, 1, 0x8000);
    }
    FLD(Ov012bEA, self, 0xea).b0 = 4;
    p = func_ov000_0218d240(self)->pos;
    s = self->unk_40;
    switch (s->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a584, 0x111, 0);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_9c = self->unk_b0->unk_00;
        self->unk_b8 = tgt;
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 1: {
        Ov012V *e;
        u8 i;
        func_ov000_0218d918(self, &p, 0x19a);
        if (self->unk_38->unk_c4 != 1) {
            return;
        }
        e = func_02065f88(0x68, &self->pos);
        e->v10(&data_ov012_0220a5d0);
        e->v34(0xbfff, self->unk_f6, self->rot[2]);
        e->v20(data_ov012_0220a65c);
        func_ov003_021da9ac(((void *)self->unk_100), 0xf9, e);
        for (i = 1; i <= 2; i++) {
            Ov012Vec o;
            e = func_02065f88(0x6c, &self->pos);
            func_01ffc9fc(&o, &data_ov012_0220a65c[i], self->rot[1]);
            e->v20(&o);
            FLD(s32, e, 0xc8) = -1;
            func_ov003_021da9ac(((void *)self->unk_100), (u8)(0xfd - i), e);
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
            e->v34(self->rot[0], self->unk_f6, self->rot[2]);
            func_020639d4(e, 0x29, 0);
            func_ov003_021da9ac(((void *)self->unk_100), 0, e);
        }
        func_ov000_0218d918(self, &p, 0x19a);
        q = self->unk_b8;
        func_ov000_0218ddd4(self, &q, 0);
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        self->unk_48->unk_9a_5 = 1;
        func_ov003_021daae4(((void *)self->unk_100), 0, &self->pos, 0, 0, 0, 0);
        for (i = 1; i <= 2; i++) {
            func_ov003_021daae4(((void *)self->unk_100), (u8)(0xfd - i), &self->pos, 0, 0, &data_ov012_0220a65c[i], self->rot);
        }
        o = (Ov012V *)func_020657b0(data_0214a420, func_ov003_021daa3c(((void *)self->unk_100), 0xf9));
        if (o != NULL) {
            o->v0c(FLD(s32, o, 0x40) + 0x19a);
        }
        func_ov000_0219aca8(self, self, Ov012_FxMul(self->unk_124, 0x3c), 0x30, 0, 0, self->unk_64 + 0x800, self->unk_68, 100, 0xccd);
        if (VEC_Distance(&self->pos, &self->unk_b8) > 0x800) {
            return;
        }
        e = func_02065f88(0x67, &self->pos);
        e->v0c(0x2000);
        e->v34(self->rot[0], (u16)(self->unk_f6 + 0x7fff), self->rot[2]);
        func_020639d4(e, 0x82, 0);
        if (++self->unk_fa >= 8) {
            self->unk_fa = 0;
        }
        for (i = 1; i <= 2; i++) {
            func_ov003_021daa6c(((void *)self->unk_100), (u8)(0xfd - i));
        }
        n = 0;
        if (self->unk_104 != NULL) {
            n = FLD(u16, self->unk_104, 4);
        }
        if (++self->unk_fb >= n) {
            self->unk_40->state = 0x1e;
        } else {
            func_ov000_02190cb0(self->unk_38, data_ov012_0220a57c, 0x111, 0);
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
        if (s->timer >= FLD(u16, self->unk_104, 2)) {
            self->unk_40->timer = 0;
            self->unk_40->state = 0;
        }
        break;
    case 30: {
        Ov012Sub48 *m;
        if (self->unk_f0 & 0x80) {
            self->unk_f0 ^= 0x80;
        }
        self->unk_f0 |= 1;
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
}  // namespace m_02203420

// ---- merged from ov012_02203b2c.cpp
namespace m_02203b2c {
extern "C" {

extern char data_ov012_0220afc4[];
extern char data_ov012_0220afca[];
extern Ov012Vec data_ov012_0220a624[];
extern u8 data_ov012_0220a68c[];
extern void *func_0204a028(void *a, s32 b, Ov012Vec *c, s32 d);
extern void func_ov000_021911c8(void *p, s32 a);

extern Ov012Vec data_ov012_0220a618;
extern void func_ov000_02191690(void *p);
extern void func_ov000_02191708(void *p);
extern void func_ov012_02205254(Ov012Act_02202b10 *self);

struct Ov012bEA2 {
    u16 b0 : 3;
};

void func_ov012_02203b2c(Ov012Act_02202b10 *self) {
    Ov012Vec p;
    p = func_ov000_0218d240(self)->pos;
    switch (self->unk_40->state) {
    case 0:
        func_02049f44(data_02097e4c, 0x401, &self->pos, 0);
        switch (self->unk_f9) {
        case 0:
            func_ov000_02190cb0(self->unk_38, data_ov012_0220afc4, 0x400, 0);
            break;
        case 1:
            func_ov000_02190cb0(self->unk_38, data_ov012_0220afca, 0x400, 0);
            break;
        }
        if ((u16)(self->unk_50[0] * 100 / self->unk_50[1]) < 0x23) {
            func_ov000_021911c8(self->unk_38, 0x1333);
        }
        self->unk_40->state++;
        break;
    case 1:
        if (!(self->unk_f0 & 0x100000)) {
            func_ov000_0218d918(self, &p, 0x19a);
        }
        if (self->unk_38->unk_c4 == 3) {
            func_0204a028(data_02097e4c, 0x12, &self->pos, 0xf);
        }
        if (self->unk_38->unk_c4 == 1) {
            Ov012Vec v;
            Ov012SpawnDesc d;
            Ov012Actor *o;
            self->unk_f0 |= 0x100000;
            Ov012Spawn_Init(&d, 0x480d);
            v = data_ov012_0220a624[self->unk_f9];
            func_01ffc9fc(&v, &v, self->rot[1]);
            VEC_Add(&self->pos, &v, &v);
            o = func_ov000_0218bf1c(data_ov000_021ccd64, &d, &v, self->rot, 0xffff);
            if (o != NULL) {
                o->unk_60 = data_ov012_0220a68c;
                func_ov000_0219bebc(o, self->unk_124);
                o->unk_16.b0 = 1;
                o->unk_90 = self->unk_90;
                if (o->unk_4c != NULL) {
                    o->unk_4c->target = self->id;
                }
            }
        }
        if (!func_ov000_02191120(self->unk_38)) {
            return;
        }
        if (++self->unk_f9 >= 2) {
            self->unk_f9 = 0;
        }
        {
            u16 n = 0;
            if (((void *)self->unk_104) != NULL) {
                n = FLD(u16, ((void *)self->unk_104), 4);
            }
            if (++self->unk_fb >= n) {
                self->unk_40->state = 0x1e;
            } else {
                func_ov000_02190cb0(self->unk_38, data_ov012_0220a57c, 0x111, 0);
                func_ov000_021915a0(self->unk_38);
                self->unk_40->state = 10;
            }
        }
        self->unk_f0 ^= 0x100000;
        break;
    case 10: {
        Ov012Sub40 *w;
        func_ov000_0218d918(self, &p, 0xcd);
        w = self->unk_40;
        w->timer++;
        if (w->timer >= FLD(u16, ((void *)self->unk_104), 2)) {
            self->unk_40->timer = 0;
            self->unk_40->state = 0;
        }
        break;
    }
    case 0x1e:
        if (self->unk_f0 & 0x20) {
            self->unk_f0 ^= 0x20;
        }
        self->unk_f0 |= 1;
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
}

void func_ov012_02203ed4(Ov012Act_02202b10 *self) {
    Ov012Vec v;
    switch (self->unk_40->state) {
    case 0:
        FLD(Ov012bEA2, self, 0xea).b0 = 4;
        func_ov000_02190cb0(self->unk_38, data_ov012_0220afca, 0x111, 0);
        self->unk_40->state++;
        break;
    case 1: {
        Ov012V *e;
        if (self->unk_38->unk_c4 != 2) {
            break;
        }
        e = func_02065f88(0x644, &self->pos);
        v.x = -0x1000;
        v.y = 0x2ccd;
        v.z = 0x4000;
        func_01ffc9fc(&v, &v, self->rot[1]);
        e->v20(&v);
        func_ov003_021da9ac(((void *)self->unk_100), 0, e);
        func_ov000_02191690(self->unk_38);
        func_0204a028(data_02097e4c, 0x12, &self->pos, 0xa);
        self->unk_40->state++;
        break;
    }
    case 2:
        if (func_ov003_021daa0c(((void *)self->unk_100), 0)) {
            break;
        }
        func_02049f44(data_02097e4c, 0x402, &self->pos, 0);
        func_ov000_02191708(self->unk_38);
        self->unk_40->state++;
        break;
    case 3:
        if (self->unk_38->unk_c4 == 1) {
            Ov012V *e;
            func_02049f44(data_02097e4c, 0x2b, &self->pos, 0);
            func_ov012_02205254(self);
            e = func_02065f88(0x12d, &self->pos);
            v.x = -0x1000;
            v.y = 0x2ccd;
            v.z = 0x4000;
            func_01ffc9fc(&v, &v, self->rot[1]);
            e->v20(&v);
            e = func_02065f88(0x6b, &self->pos);
            v.x = -0x1000;
            v.y = 0x2ccd;
            v.z = 0x4000;
            func_01ffc9fc(&v, &v, self->rot[1]);
            e->v20(&v);
        }
        if (func_ov000_02191120(self->unk_38)) {
            FLD(Ov012bEA2, self, 0xea).b0 = self->unk_b0->unk_0a_7;
            func_ov000_02190cb0(self->unk_38, data_ov012_0220a57c, 0x89, 0);
            func_ov000_021915a0(self->unk_38);
            self->unk_40->state = 0x1e;
        }
        break;
    case 0x1e: {
        s32 n = func_ov003_021d9edc(0x4824);
        if (((u8)(self->unk_f8 + 0xff) <= 1 && n <= 1) || n == 0) {
            self->unk_f8 = 0;
            if (self->unk_f0 & 4) {
                self->unk_f0 ^= 4;
            }
            self->unk_f0 |= 1;
            self->unk_40->timer = 0;
            func_ov000_02198360(self->unk_40, 1, 0);
        }
        break;
    }
    }
    switch (data_ov000_021ccd54->unk_ca) {
    case 8:
        func_ov000_0218d918(self, &data_ov012_0220a618, 0x400);
        break;
    case 3:
        func_ov000_0218d918(self, data_ov012_0220a5ac, 0x400);
        break;
    }

}



extern char data_ov012_0220afd0[];
extern Ov012Vec data_ov012_0220a60c;
extern Ov012Vec data_ov012_0220a600;
extern void *func_0204a028(void *a, s32 b, Ov012Vec *c, s32 d);
extern void func_ov000_02191690(void *p);
extern void func_ov000_02191708(void *p);

struct Ov012Blk12R {
    s32 w[3];
};

struct Ov012bEA3 {
    u16 b0 : 3;
};

#define OV012R_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV012R_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV012R_SQRT_PARAM (*(volatile u64 *)0x40002b8)

void func_ov012_0220422c(Ov012Act_02202b10 *self) {
    Ov012Vec t;
    Ov012Vec *pos;
    Ov012Vec q;
    Ov012Vec c;
    Ov012Vec d2;
    Ov012Vec v;
    Ov012SpawnDesc d;
    Ov012Vec d14;
    Ov012Sub40 *s;
    pos = &self->pos;
    self->unk_94_1 = 1;
    FLD(Ov012bEA3, self, 0xea).b0 = 4;
    s = self->unk_40;
    switch (s->state) {
    case 0: {
        func_ov000_02190cb0(self->unk_38, data_ov012_0220afd0, 0x111, 0);
        VEC_Add(pos, &data_ov012_0220a60c, &t);
        self->unk_b8 = t;
        self->unk_40->state++;
        break;
    }
    case 1:
        if (self->unk_38->unk_c4 != 1) {
            break;
        }
        func_02065f88(0x12f, pos);
        self->unk_40->state++;
        break;
    case 2: {
        if (self->unk_38->unk_c4 == 2) {
            func_ov000_02191690(self->unk_38);
        }
        t = self->unk_b8;
        d2.x = t.x - self->pos.x;
        d2.y = t.y - self->pos.y;
        d2.z = t.z - self->pos.z;
        VEC_MultAdd(0x19a, &d2, pos, pos);
        if (VEC_Distance(pos, &self->unk_b8) > 0x4cd) {
            break;
        }
        func_ov000_02191708(self->unk_38);
        self->unk_40->state++;
        break;
    }
    case 3:
        if (self->unk_38->unk_c4 != 3) {
            break;
        }
        func_02049f44(data_02097e4c, 0x403, pos, 0);
        func_0204a028(data_02097e4c, 0x12, pos, 0xa);
        func_ov000_02191690(self->unk_38);
        self->unk_40->state++;
        break;
    case 4: {
        Ov012Actor *o;
        Ov012V *e;
        s->timer++;
        if (s->timer <= 10) {
            break;
        }
        func_ov000_02191708(self->unk_38);
        func_02049f44(data_02097e4c, 0x2b, pos, 0);
        Ov012Spawn_Init(&d, 0x4825);
        v.x = -0xccd;
        v.y = 0;
        v.z = 0x2000;
        func_01ffc9fc(&v, &v, self->rot[1]);
        VEC_Add(pos, &v, &v);
        o = func_ov000_0218bf1c(data_ov000_021ccd64, &d, &v, self->rot, 0xffff);
        if (o != NULL) {
            o->unk_16.b0 = 1;
            o->rot[1] = self->rot[1];
            o->unk_90 = self->unk_90;
            func_ov000_0219bebc(o, self->unk_124);
            if (o->unk_4c != NULL) {
                o->unk_4c->target = self->id;
            }
        }
        e = func_02065f88(0x68, pos);
        q.x = -0xccd;
        q.y = 0;
        q.z = 0x2000;
        func_01ffc9fc(&q, &q, self->rot[1]);
        e->v20(&q);
        e->v34(0xeaaa, self->rot[1], self->rot[2]);
        e = func_02065f88(0x12d, pos);
        q.x = -0xccd;
        q.y = 0;
        q.z = 0x2000;
        func_01ffc9fc(&q, &q, self->rot[1]);
        e->v20(&q);
        e = func_02065f88(0x6a, pos);
        q.x = -0xccd;
        q.y = 0;
        q.z = 0x2000;
        func_01ffc9fc(&q, &q, self->rot[1]);
        e->v20(&q);
        q.x = 0;
        q.y = 0x1800;
        q.z = -0x1800;
        func_01ffc9fc(&q, &q, self->rot[1]);
        VEC_Add(pos, &q, &t);
        self->unk_b8 = t;
        self->unk_84 = self->pos;
        self->unk_40->timer = 0;
        self->unk_40->state = 0x14;

        break;
    }
    case 0x14: {
        s32 r;
        u16 ang;
        t = self->unk_b8;
        d14.x = t.x - self->pos.x;
        d14.y = t.y - self->pos.y;
        d14.z = t.z - self->pos.z;
        VEC_MultAdd(0x4cd, &d14, pos, pos);
        if (VEC_Distance(pos, &self->unk_b8) > 0x4cd) {
            break;
        }
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a57c, 0x52, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        {
            s64 sq;
            s32 dx = self->pos.x - self->unk_84.x;
            s32 dz = self->pos.z - self->unk_84.z;
            sq = (s64)dx * dx;
            sq += (s64)dz * dz;

            OV012R_SQRTCNT = 1;
            OV012R_SQRT_PARAM = (u64)(sq * 4);
        }
        while (OV012R_SQRTCNT & 0x8000) {
        }
        r = (s32)(OV012R_SQRT_RESULT + 1) >> 1;
        ang = FX_Atan2(r, self->unk_84.y - self->pos.y);
        self->unk_9c = Ov012_FxMul(OV012_SIN(ang), 0x19a);
        self->unk_a0 = Ov012_FxMul(OV012_COS(ang), 0x19a);
        self->unk_b8 = self->unk_84;
        self->unk_40->state++;
        break;
    }
    case 0x15: {
        t = self->unk_b8;
        func_ov000_0218ddd4(self, &t, 0);
        if (VEC_Distance(pos, &self->unk_b8) > 0x19a) {
            break;
        }
        FLD(Ov012bEA3, self, 0xea).b0 = self->unk_b0->unk_0a_7;
        func_ov000_02198360(self->unk_40, 4, 0);
        break;
    }
    }
    {
        u8 *cam = (u8 *)data_ov000_021ccd54 + 0xf4;
        *(Ov012Blk12R *)&c = *(Ov012Blk12R *)&data_ov012_0220a600;
        c.y = self->pos.y;
        FLD(Ov012Vec, cam, 0xdc) = c;
        FLD(Ov012Flags8, cam, 0xda).b0 = 1;
        FLD(u16, cam, 0xf8) = 0xe39;
        FLD(Ov012Flags8, cam, 0xda).b4 = 1;
    }
}

}
}  // namespace m_02203b2c

// ---- merged from ov012_02204904.cpp
namespace m_02204904 {
extern "C" {

extern char data_ov012_0220afd6[];
extern Ov012Vec data_ov012_0220a680;
extern void *func_0204a028(void *a, s32 b, Ov012Vec *c, s32 d);
extern void func_ov000_02191690(void *p);
extern void func_ov000_02191708(void *p);
extern void func_ov000_02191780(void *p);
extern void func_ov000_021911c8(void *p, s32 a);
extern BOOL func_ov012_02205080(Ov012Act_02202b10 *self, s32 a);
extern void func_ov012_022053a4(Ov012Act_02202b10 *self);

struct Ov012bEA4 {
    u16 b0 : 3;
};

void func_ov012_02204904(Ov012Act_02202b10 *self) {
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
        if (self->unk_38->unk_c4 == 2) {
            func_0204a028(data_02097e4c, 0x66, &self->pos, -10);
        }
        if (self->unk_38->unk_c4 == 1) {
            e = func_02065f88(0x391, &self->pos);
            e->v0c(0x2000);
            e->v20(&data_ov012_0220a680);
            func_020639d4(e, 0x5b, 0);
            func_ov003_021da9ac(((void *)self->unk_100), 0, e);
            self->unk_f0 |= 0x100000;
            func_ov000_02191690(self->unk_38);
        }
        if ((self->unk_f0 & 0x100000) && !func_ov003_021daa0c(((void *)self->unk_100), 0)) {
            func_02049f44(data_02097e4c, 0x404, &self->pos, 0);
            self->unk_f0 ^= 0x100000;
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
            func_ov003_021da9ac(((void *)self->unk_100), 0xf9, e);
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
        if (self->unk_f0 & 0x10) {
            self->unk_f0 ^= 0x10;
        }
        self->unk_f0 |= 1;
        FLD(Ov012bEA4, self, 0xea).b0 = self->unk_b0->unk_0a_7;
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    e = (Ov012V *)func_020657b0(data_0214a420, func_ov003_021daa3c(((void *)self->unk_100), 0xf9));
    if (e != NULL) {
        e->v0c(FLD(s32, e, 0x40) + 0xcd);
    }
}

}
}  // namespace m_02204904

// ---- merged from ov012_02204d00.cpp
namespace m_02204d00 {
extern "C" {
void func_ov012_02204d00(Ov012Act_02202b10 *self) {
    if (self->unk_40->state == 0) {
        func_02049f44(data_02097e4c, 0x406, &self->pos, 0);
        self->unk_f0 = 1;
        FLD(s32, self, 0x104) = 0;
        self->unk_f8 = 0;
        FLD(s32, self, 0xf0) |= 0x400;
        func_ov003_021daab0(((void *)self->unk_100));
    }
    func_ov003_021d5348(self);
}
}

extern "C" {
void func_ov012_02204d64(Ov012Act_02202b10 *self) {
    if (self->unk_40->state == 0) {
        func_02049f44(data_02097e4c, 0x406, &self->pos, 0);
        FLD(s32, self, 0xf0) |= 0x800;
        func_ov003_021daab0(((void *)self->unk_100));
    }
    func_ov003_021d5900(self);
}
}

extern "C" {
BOOL func_ov012_02205080(Ov012Act_02202b10 *self, s32 a);
void func_ov012_02204dbc(Ov012Act_02202b10 *self) {
    Ov012Actor *t;
    Ov012Sub40 *s;
    Ov012Sub48 *m;
    if (self->unk_f0 & 0x800) {
        Ov012_ResetF0(self);
        self->unk_f0 |= 0x200000;
    }
    if (self->unk_f0 & 8) {
    t = func_ov000_0218d240(self);
    s = self->unk_40;
    switch (Ov012Sub40_State(s)) {
    case 0:
        m = self->unk_48;
        m->unk_9a_0 = 0;
        m->unk_9a_3 = 0;
        func_0203f364(m);
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        if (self->unk_a8 == 0) {
            self->unk_a8 = 0x52;
        }
        self->unk_40->state++;
    case 1:
        func_ov000_0218dbe0(self, 0);
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        self->unk_48->unk_9a_5 = 1;
        if (!(self->unk_48->unk_50 & 0x20000000)) {
            return;
        }
        func_02049f44(data_02097e4c, 0x2a, &self->pos, 0);
        m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        func_0203f324(m);
        self->unk_40->timer = 0;
        self->unk_40->state++;
        break;
    case 2:
        if (*t->unk_50 != 0) {
            s->timer++;
            if (s->timer <= 0x28) {
                return;
            }
            if (!func_ov012_02205080(self, 0x1b)) {
                return;
            }
            self->unk_40->state++;
            self->unk_40->timer = 0;
        } else {
            s->state++;
        }
        break;
    case 3:
        s->timer++;
        if (s->timer <= 10) {
            return;
        }
        self->unk_40->timer = 0;
        if (*t->unk_50 != 0) {
            Ov012_ResetF0(self);
            self->unk_f0 |= 0x200000;
        }
        func_ov000_02198360(self->unk_40, 1, 0);
        break;
    }
    } else {
        func_ov003_021d3d28(self);
    }
}
}

extern "C" {
void func_ov012_02204fc8(Ov012Actor *self) {
    if (self->unk_40->state == 0) {
        Ov012V *e;
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x480d, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4824, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4825, 0x15);
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x4826, 0x15);
        e = func_02065f88(0x69, &self->pos);
        if (e != NULL) {
            e->v0c(0x2800);
            e->v24(0, self->unk_6c, 0);
        }
    }
    func_ov003_021d6054(self);
}
}

extern "C" {
extern const u8 data_ov012_0220a680[];
extern const Ov012Vec data_ov012_0220a5f4;
BOOL func_ov012_02205080(Ov012Act_02202b10 *self, s32 a) {
    Ov012V *e;
    switch (self->unk_fc) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov012_0220a580, a, 0);
        e = func_02065f88(0x25e, &self->pos);
        e->v34(0x9fff, self->rot[1], self->rot[2]);
        e->v20(data_ov012_0220a680);
        func_ov003_021da9ac(((void *)self->unk_100), 0xff, e);
        self->unk_fc++;
        break;
    case 1:
        if (self->unk_f4 != 3) {
            u16 t = FLD(u16, func_ov000_0219bf90(), 0xb1e);
            if (t != self->id) {
            e = func_02065f88(0x12f, &self->pos);
            e->v24(0, 0x1000, 0);
            e->v0c(0xb33);
            func_ov003_021da9ac(((void *)self->unk_100), 0xfe, e);
            }
        }
        self->unk_fc++;
        break;
    case 2:
        if (func_ov003_021daa0c(((void *)self->unk_100), 0xfe)) {
            Ov012V *o = (Ov012V *)func_020657b0(data_0214a420, func_ov003_021daa3c(((void *)self->unk_100), 0xfe));
            if (o != NULL) {
                Ov012Vec t = data_ov012_0220a5f4;
                o->v20(&t);
            }
        } else {
            self->unk_fc = 1;
        }
        if (func_ov000_02191120(self->unk_38)) {
            func_ov003_021daa6c(((void *)self->unk_100), 0xff);
            return TRUE;
        }
        break;
    }
    return FALSE;
}
}

extern "C" {
void func_ov012_02205254(Ov012Act_02202b10 *self) {
    Ov012SpawnDesc d;
    Ov012Vec v;
    Ov012Actor *o;
    Ov012Spawn_Init(&d, 0x4824);
    v.x = -0x1000;
    v.y = 0x2ccd;
    v.z = 0x4000;
    func_01ffc9fc(&v, &v, self->rot[1]);
    VEC_Add(&self->pos, &v, &v);
    o = func_ov000_0218bf1c(data_ov000_021ccd64, &d, &v, self->rot, 0xffff);
    if (o == NULL) {
        return;
    }
    o->unk_16.b0 = 1;
    o->unk_18 = 0;
    func_ov000_0219bebc(o, self->unk_124);
    switch (data_ov000_021ccd54->unk_ca) {
    case 8:
        Ov012_VecSet(&o->unk_84, 0, 0x2000, -0x1f0a);
        break;
    case 3:
        Ov012_VecSet(&o->unk_84, -0x34cd, 0x2000, 0x2333);
        break;
    }
    o->rot[1] = self->rot[1];
    o->unk_90 = self->unk_90;
    if (o->unk_4c != NULL) {
        o->unk_4c->target = self->id;
    }
}
}

extern "C" {
void func_ov012_022053a4(Ov012Act_02202b10 *self) {
    Ov012SpawnDesc d;
    Ov012Vec v;
    Ov012Actor *o;
    Ov012Actor *t;
    Ov012Spawn_Init(&d, 0x4826);
    v.y = 0x3000;
    v.z = 0x4000;
    v.x = 0;
    func_01ffc9fc(&v, &v, self->rot[1]);
    VEC_Add(&self->pos, &v, &v);
    o = func_ov000_0218bf1c(data_ov000_021ccd64, &d, &v, self->rot, 0xffff);
    if (o == NULL) {
        return;
    }
    o->unk_16.b0 = 1;
    t = func_ov000_0218d240(self);
    Ov012_VecSet(&o->unk_84, t->pos.x, 0x800, t->pos.z);
    o->rot[1] = self->rot[1];
    o->unk_90 = self->unk_90;
    if (self->unk_f4 == 3) {
        o->unk_18 = 1;
    }
    func_ov000_0219bebc(o, self->unk_124);
    if (o->unk_4c != NULL) {
        o->unk_4c->target = self->id;
    }
}
}

extern "C" {
extern const u8 data_ov012_0220a5e8[];
void func_ov012_022054cc(Ov012Act_02202b10 *self) {
    Ov012Sub40 *s;
    Ov012V *e;
    switch (self->unk_fd) {
    case 0:
        s = self->unk_40;
        s->timer++;
        if (s->timer <= 0x1e) {
            return;
        }
        self->unk_40->timer = 0;
        self->unk_fd++;
        break;
    case 1:
        func_ov003_021daab0(((void *)self->unk_100));
        e = func_02065f88(0x190, &self->pos);
        e->v0c(0x1800);
        e->v20(data_ov012_0220a5e8);
        func_ov003_021da9ac(((void *)self->unk_100), 0xfa, e);
        self->unk_fd++;
        break;
    case 2:
        if (!func_ov003_021daa0c(((void *)self->unk_100), 0xfa)) {
            u16 hp;
            e = func_02065f88(0xcb, &self->pos);
            e->v0c(0x1800);
            e->v20(data_ov012_0220a5e8);
            {
                s16 v = self->unk_18 + 1;
                hp = data_ov012_0220a58e[v];
                self->unk_18 = v;
            }
            self->unk_50[1] = hp;
            self->unk_50[0] = hp;
            self->unk_fd++;
        }
        func_ov003_021dacfc(((void *)self->unk_100));
        break;
    case 3: {
        Ov012Sub48 *m;
        Ov012Sub44 *n;
        s = self->unk_40;
        s->timer++;
        if (s->timer <= 0x5a) {
            return;
        }
        func_020627a0(self->kind, self->id);
        func_020627dc(5);
        {
            u8 *g = (u8 *)data_ov000_021ccd54;
            g[0xac] = 1;
            func_ov000_02182590(g + 0xac);
        }
        Ov012_ResetF0(self);
        self->unk_f0 |= 0x200000;
        m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        func_0203f324(m);
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        self->unk_40->timer = 0;
        self->unk_fd = 0;
        break;
    }
    }
}
}

extern "C" {
extern const u8 data_ov012_0220b09c[];
void func_ov012_022056d4(Ov012Actor *self) {
    func_ov000_0219433c(self);
    func_ov000_0218f074((u8 *)self + 0xd8, data_ov012_0220b09c, 1, 1, 0, 0);
    FLD(s16, self, 0xd8) = 0;
}
}

extern "C" {
BOOL func_ov012_02205714(Ov012Actor *self) {
    BOOL r = func_ov000_021946f8(self);
    if (FLD(s16, self, 0xd8) >= 0) {
        r = (r & func_ov000_0218f110((u8 *)self + 0xd8)) ? TRUE : FALSE;
    }
    return r;
}
}
}  // namespace m_02204d00
