#include "ov013/ov013.h"

class Ov013Cls;
typedef void (Ov013Cls::*Ov013Pmf)();

struct Ov013Rot {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov013RotC {
    u16 x;
    u16 y;
    u16 z;
    Ov013RotC() {
        x = 0;
        y = 0;
        z = 0;
    }
};

struct Ov013Offs5 {
    u16 v[5];
};

extern "C" {

extern void *data_ov000_021ccd68;
extern void *data_ov000_021ccd64;
extern Ov013Pmf data_ov013_0220bc48;
extern Ov013Pmf data_ov013_0220bc50;
extern Ov013Pmf data_ov013_0220bc58;
extern const u8 data_ov003_021f4340;
extern char data_ov013_0220ba6c[];
extern u8 data_ov013_0220b308[];
extern u8 data_ov013_0220b324[];
struct Ov013RotTbl { u16 pad; Ov013Rot r; };
extern Ov013RotTbl data_ov013_0220b290;
extern void func_ov000_02194758(void *self);
extern char data_ov013_0220ba73[];
extern const Ov013Pmf data_ov013_0220bc60;
extern Ov013Pmf data_ov013_0220bc68;
extern Ov013Pmf data_ov013_0220bc70;
extern void func_0203f324(Ov013Sub48 *p);
extern void func_ov003_021f0c60(Ov013Actor *self, s32 a);
extern Ov013Actor *func_ov000_0218d240(Ov013Actor *self);
extern void func_ov000_0218dbe0(Ov013Actor *self, s32 a);
extern void *func_ov000_0218fe1c(void *p);
extern void func_ov000_0218ffdc(void *a, void *b, s32 c, s32 d);
extern void func_0203f364(Ov013Sub48 *p);
extern void func_ov003_021cf330(void *p, const char *name, u8 a);
extern void func_ov013_02205760(Ov013Actor *self);
extern void func_ov003_021da40c(void *p);
extern void func_ov000_0218d7e8(Ov013Actor *self, s32 a);
extern BOOL func_ov000_021950e8(Ov013Actor *self, Ov013Msg *msg);
extern Ov013Actor *func_ov000_0218e640(void *mgr, u16 id);
extern u16 FX_Atan2(s32 y, s32 x);
extern u8 *func_020704b4(u16 kind);
extern void func_ov013_02205098(Ov013Actor *self);
extern void func_ov000_02195d88(Ov013Actor *self);
extern Ov013Actor *func_ov003_021da32c(u16 kind);
extern void func_ov000_02197dec(Ov013Actor *self, s32 a, s32 b);
extern void func_ov000_0218bed8(void *a, s32 b, void *c);
extern void func_ov000_0219763c(Ov013Actor *self);

static inline Ov013Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return func_ov000_0218e640(data_ov000_021ccd68, id);
}

static inline u16 Ov013_FaceAngle(Ov013Actor *self, Ov013Actor *a) {
    if (a != NULL) {
        if (a != NULL && a != self) {
            return FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
        }
        return self->rot[1];
    }
    return self->unk_98 + 0x7fff;
}

void func_ov013_02204a3c(Ov013Actor *self) {
    s32 x;
    s32 y;
    s32 z;
    void *m;
    Ov013Sub48 *m48;
    Ov013Sub44 *n;
    func_ov000_02194758(self);
    self->unk_38->unk_c2_0 = 0;
    func_ov000_02198360(self->unk_40, 0x20, 0);
    FLD(s8, self, 0xcf) = 2;
    FLD(Ov013Pmf, self, 0xe4) = data_ov013_0220bc48;
    x = FLD(s32, self->unk_38, 0xa8);
    y = FLD(s32, self->unk_38, 0xac);
    z = FLD(s32, self->unk_38, 0xb0);
    m = func_0203dd9c(0xe8);
    if (m != NULL) {
        m = func_ov000_0218fe1c(m);
    }
    FLD(void *, self, 0xe0) = m;
    func_ov000_0218ffdc(m, FLD(void *, self, 0xdc), 0, 1);
    m = FLD(void *, self, 0xe0);
    FLD(s32, m, 0xa8) = x;
    FLD(s32, m, 0xac) = y;
    FLD(s32, m, 0xb0) = z;
    n = self->unk_44;
    n->unk_22_0 = 0;
    n->unk_22_1 = 0;
    FLD(s32, self->unk_44, 0x1c) = x + 0x2000;
    m48 = self->unk_48;
    m48->unk_9a_1 = 0;
    m48->unk_9a_4 = 0;
    m48 = self->unk_48;
    m48->unk_9a_0 = 0;
    m48->unk_9a_3 = 0;
    func_0203f364(m48);
    self->unk_48->unk_30 = 0;
    func_ov003_021cf330((u8 *)self + 0xec, data_ov013_0220ba6c, data_ov003_021f4340);
}

void func_ov013_02204b60(Ov013Actor *self) {
    u32 *p = FLD(u32 *, self, 0x5c);
    if (p != NULL) {
        *p &= ~2;
    }
    self->rot[0] += FLD(u16, self, 0xd0);
}

void func_ov013_02204b88(Ov013Actor *self) {
    Ov013Sub40 *s = self->unk_40;
    u8 k = s->unk_13;
    if (k != 0x15) {
        if (k == 0x27) {
            func_ov013_02205760(self);
            self->unk_40->flags = 0;
        } else if (s->flags & 0x200000) {
            func_ov000_02198360(s, 0x15, 0);
        } else if (s->flags & 0x200) {
            func_ov000_02198360(s, 9, 0);
        } else {
            func_ov003_021da40c(s);
        }
    }
    func_ov000_0218d7e8(self, self->unk_40->unk_13);
}

BOOL func_ov013_02204c20(Ov013Actor *self, Ov013Msg *msg) {
    BOOL r;
    if (msg->type == 0xe) {
        r = TRUE;
        if (FLD(u8, msg, 8) == 1) {
            Ov013Actor *a;
            FLD(u16, FLD(void *, self, 0x4c), 0x1c) = FLD(u16, msg, 6);
            self->unk_90 = 0xffff;
            a = Ov013_FindActor(FLD(u16, msg, 6));
            if (a != NULL) {
                self->unk_90 = a->unk_90;
            }
            FLD(s8, self, 0xcf)--;
            if (FLD(s8, self, 0xcf) <= 0) {
                FLD(Ov013Pmf, self, 0xe4) = data_ov013_0220bc50;
                func_ov000_02198360(self->unk_40, 0x27, 0);
            } else {
                FLD(Ov013Pmf, self, 0xe4) = data_ov013_0220bc58;
                self->unk_98 = Ov013_FaceAngle(self, Ov013_FindActor(self->unk_90));
                FLD(Ov013Flags8, self, 0xce).b1 = 0;
                FLD(void *, self, 0xd8) = data_ov013_0220b308;
                FLD(u16, self, 0xd0) = 0xc00;
                FLD(u8, FLD(void *, self, 0x4c), 0) = func_020704b4(self->kind)[0];
                func_ov000_02198360(self->unk_40, 0xe, 0);
            }
        }
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
    } else {
        r = func_ov000_021950e8(self, msg);
    }
    return r;
}

void func_ov013_02204dbc(Ov013Actor *self) {
    func_ov013_02205098(self);
}

void func_ov013_02204dc8(Ov013Actor *self) {
    if (self->unk_40->state == 0) {
        FLD(u16, self, 0xd0) = 0;
    }
    func_ov000_02195d88(self);
}

static inline BOOL Ov013_IsSolid(Ov013Sub44 *n) {
    return n->unk_22_0 == 1 && n->unk_22_1 == 1;
}

void func_ov013_02204de8(Ov013Actor *self) {
    Ov013Sub44 *n;
    Ov013Sub48 *m;
    switch (self->unk_40->state) {
    case 0:
        func_ov000_02190cb0(self->unk_38, data_ov013_0220ba73, 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        FLD(Ov013Pmf, self, 0xe4) = data_ov013_0220bc60;
        FLD(u16, self, 0xd0) = 0x700;
        self->unk_9c = 0x59a;
        self->unk_a0 = 0;
        self->unk_98 = self->rot[1];
        self->unk_a8 = 1;
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        func_0203f324(m);
        m = self->unk_48;
        m->unk_9a_1 = 1;
        m->unk_9a_4 = 1;
        self->unk_40->state++;
    case 1: {
        u16 t;
        self->unk_40->timer++;
        t = self->unk_40->timer;
        if (t > 3 && (FLD(u32, self->unk_48, 0x58) & 0x20)) {
            n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
            m = self->unk_48;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
            m = self->unk_48;
            m->unk_9a_1 = 0;
            m->unk_9a_4 = 0;
            func_ov003_021f0c60(self, 0);
            func_ov000_02198360(self->unk_40, 0x15, 0);
            return;
        }
        if (t > 0x96) {
            FLD(Ov013Pmf, self, 0xe4) = data_ov013_0220bc68;
            func_ov000_02198360(self->unk_40, 0x15, 0);
            return;
        }
        if (t > 0x3c) {
            Ov013Actor *a = func_ov000_0218d240(self);
            n = NULL;
            if (a != NULL) {
                n = a->unk_44;
            }
            if (n != NULL && !Ov013_IsSolid(n)) {
                n = NULL;
            }
            if (n == NULL) {
                FLD(Ov013Pmf, self, 0xe4) = data_ov013_0220bc70;
                func_ov000_02198360(self->unk_40, 0x15, 0);
                return;
            }
        }
        func_ov000_0218dbe0(self, 0);
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        break;
    }
    }
}

void func_ov013_02205054(Ov013Actor *self) {
    func_ov000_02198360(self->unk_40, 0x15, 1);
}

void func_ov013_0220506c(Ov013Actor *self) {
    (((Ov013Cls *)self)->*FLD(Ov013Pmf, self, 0xe4))();
}

static inline void Ov013_RotZero(Ov013Rot *p) {
    p->x = 0;
    p->y = 0;
    p->z = 0;
}

static inline Ov013Actor *Ov013_SpawnAt(u16 kind, const Ov013Vec *pos, const Ov013Rot *rot) {
    Ov013Actor *b = func_ov003_021da32c(kind);
    if (b != NULL) {
        b->pos = *pos;
        FLD(Ov013Rot, b, 0x7c) = *rot;
    }
    return b;
}


struct Ov013Prm {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 pad;
    s16 v2;
    s16 v4;
    s16 v6;
    s16 v8;
    s16 va;
    s16 vc;
    u16 ve;
    s16 v10;
    s16 v12;
    s16 v14;
    u8 pad2[2];
    s32 v18;
};

// Reads the parameter pointer through a const view, so the plain reads in Ov013_Dur that
// follow load it again, as in the target.
static inline BOOL Ov013_PrmB0(const Ov013Actor *self) {
    return (*(const Ov013Prm *const *)((const u8 *)self + 0xd8))->b0;
}

struct Ov013Blk12 {
    s32 w[3];
};

extern void *func_ov000_02199ba0(void *p);
extern void VEC_Normalize(const Ov013Vec *src, Ov013Vec *dst);
extern void func_ov003_021d9980(Ov013Vec *out, u16 ang, const void *b);
extern u16 func_ov003_021d9c38(Ov013Vec *v);
extern Ov013V *func_02065f88(s32 id, Ov013Vec *pos);
extern void *data_02097e4c;
extern void func_02049f44(void *a, s32 b, Ov013Vec *c, s32 d);
extern const u8 data_ov013_0220b2cc[];
extern const Ov013Blk12 data_ov013_0220b2b4;
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, void *f, void *g, s32 h, s32 i, s32 j, s32 k);

static inline u16 Ov013_Dur(Ov013Actor *self) {
    u16 v = 0;
    if (FLD(Ov013Flags8, self, 0xce).b1) {
        v = FLD(u16, self, 0xd2);
    } else if (FLD(u8 *, self, 0xd8) != NULL) {
        v = FLD(u16, FLD(u8 *, self, 0xd8), 0xe);
    }
    return v;
}

#define OV013_CLAMP(x, lo, hi) ((x) > (hi) ? (hi) : ((x) < (lo) ? (lo) : (x)))

static inline s32 Ov013_Clamp(s32 v, s32 lo, s32 hi) {
    if (v > hi) {
        return hi;
    }
    if (v < lo) {
        return lo;
    }
    return v;
}

static inline void Ov013_VecSub(Ov013Vec *o, const Ov013Vec *a, const Ov013Vec *b) {
    o->x = a->x - b->x;
    o->y = a->y - b->y;
    o->z = a->z - b->z;
}

static inline s32 Ov013_Dot(const Ov013Vec *a, const Ov013Vec *b) {
    return (s32)(((s64)a->x * b->x + (s64)a->y * b->y + (s64)a->z * b->z + 0x800) >> 12);
}

void func_ov013_02205098(Ov013Actor *self) {
    Ov013Vec tp;
    Ov013Vec d;
    Ov013Vec f;
    Ov013Vec dv;
    if (self->unk_40->state != 100 && FLD(Ov013Prm *, self, 0xd8) == NULL) {
        self->unk_40->state = 100;
    }
    switch (self->unk_40->state) {
    case 0: {
        Ov013Actor *a = Ov013_FindActor(self->unk_90);
        Ov013Sub48 *m;
        Ov013Sub44 *n;
        if (a == NULL) {
            self->unk_40->state = 100;
            break;
        }
        self->unk_84 = a->pos;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
        self->unk_9c = FLD(Ov013Prm *, self, 0xd8)->v2;
        self->rot[1] = self->unk_98;
        self->unk_38->unk_c2_0 = 1;
        m = self->unk_48;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        func_0203f324(m);
        m = self->unk_48;
        m->unk_9a_1 = 1;
        m->unk_9a_4 = 1;
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        self->unk_40->state = 10;
        break;
    }
    case 10: {
        Ov013Actor *t = (Ov013Actor *)func_ov000_02199ba0(FLD(void *, self, 0x4c));
        s32 dist;
        BOOL ahead;
        Ov013Prm *p;
        if (t == NULL) {
            self->unk_40->state = 100;
            break;
        }
        tp = t->pos;
        d.x = self->unk_84.x - self->pos.x;
        d.y = self->unk_84.y - self->pos.y;
        d.z = self->unk_84.z - self->pos.z;
        VEC_Normalize(&d, &d);
        func_ov003_021d9980(&f, self->unk_98, data_ov013_0220b2cc);
        dist = VEC_Distance(&tp, &self->pos);
        ahead = Ov013_Dot(&d, &f) < 0x800;
        if (dist > 0x6000 && ahead) {
            self->unk_40->state = 20;
        } else {
            p = FLD(Ov013Prm *, self, 0xd8);
            if (p->b2 && dist >= p->v18) {
                self->unk_40->state = 20;
            }
        }
        func_ov000_0218dbe0(self, 0);
        self->unk_9c += FLD(Ov013Prm *, self, 0xd8)->v4;
        self->unk_9c = OV013_CLAMP(self->unk_9c, 0, FLD(Ov013Prm *, self, 0xd8)->v6);
        break;
    }
    case 20: {
        Ov013V *o = func_02065f88(0x192, &self->pos);
        o->v0c(0x4000);
        o->v34(0, self->rot[1], 0);
        self->unk_40->state = 21;
    }
    case 21: {
        Ov013Prm *p = FLD(Ov013Prm *, self, 0xd8);
        if (p->b1 && self->unk_9c >= p->v10) {
            self->unk_9c = p->v10;
        }
        p = FLD(Ov013Prm *, self, 0xd8);
        self->unk_a4 = p->v12;
        if (self->unk_9c < p->v14) {
            self->unk_40->state = 30;
            break;
        }
        func_ov000_0218dbe0(self, 0);
        break;
    }
    case 30: {
        if (self->unk_40->timer % 12 == 0) {
            func_02049f44(data_02097e4c, 100, &self->pos, 0);
        }
        if (!Ov013_PrmB0(self)) {
            s32 lim = Ov013_Dur(self) - 0x6e;
            lim = OV013_CLAMP(lim, 0, Ov013_Dur(self));
            if (lim < self->unk_40->timer && self->unk_40->timer % 8 == 0) {
                Ov013Sub38 *m = self->unk_38;
                if (FLD(u8, m, 0xbe) == 0x10) {
                    FLD(u8, m, 0xbe) = 0x1f;
                } else {
                    FLD(u8, m, 0xbe) = 0x10;
                    m = self->unk_38;
                    FLD(u16, m, 0xb6) = 0x318c;
                    FLD(u16, m, 0xb8) = 0x7fff;
                    FLD(u16, m, 0xba) = 9;
                    FLD(u16, m, 0xbc) = 8;
                }
            }
        }
        if (self->unk_40->timer >= Ov013_Dur(self)) {
            self->unk_40->timer = 0;
            if (FLD(Ov013Prm *, self, 0xd8)->b0) {
                self->unk_40->state = 40;
            } else {
                self->unk_40->state = 100;
                break;
            }
        } else {
            self->unk_40->timer = Ov013Sub40_Timer(self->unk_40) + 1;
            break;
        }
    }
    case 40:
    case 41: {
        Ov013Actor *a;
        Ov013Sub40 *s = self->unk_40;
        if (s->state == 40) {
            self->unk_9c = 0;
            self->unk_a0 = 0;
            self->unk_a4 = 0;
            self->unk_a8 = 0;
            FLD(Ov013Flags8, self, 0xce).b0 = 1;
            self->unk_9c = FLD(Ov013Prm *, self, 0xd8)->v8;
            s->state = 41;
        } else {
            self->unk_9c += FLD(Ov013Prm *, self, 0xd8)->va;
            self->unk_9c = OV013_CLAMP(self->unk_9c, 0, FLD(Ov013Prm *, self, 0xd8)->vc);
        }
        func_ov000_0218dbe0(self, 0);
        a = Ov013_FindActor(FLD(u16, FLD(void *, self, 0x4c), 0x1c));
        if (a == NULL) {
            self->unk_40->state = 100;
            break;
        }
        {
            s32 x = a->pos.x;
            s32 y = a->pos.y;
            s32 z = a->pos.z;
            dv.x = x - self->pos.x;
            dv.y = y - self->pos.y;
            dv.z = z - self->pos.z;
        }
        self->unk_98 = func_ov003_021d9c38(&dv);
        self->rot[1] = self->unk_98 + 0x7fff;
        break;
    }
    case 100:
        func_ov000_02198360(self->unk_40, 0x15, 1);
        FLD(Ov013Prm *, self, 0xd8) = NULL;
        break;
    }
    {
        Ov013Rot r = data_ov013_0220b290.r;
        r.y = self->rot[1] + 0x4000;
        Ov013Blk12 v = data_ov013_0220b2b4;
        func_ov000_0219aae8(self, self, FLD(u16, FLD(void *, self, 0x4c), 8), FLD(u16, FLD(void *, self, 0x4c), 0xa), 2, &v, &r, 0x5800, 0x1000, 100, 0x1000);
    }
}

}
