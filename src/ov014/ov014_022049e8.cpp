#include "ov014/ov014.h"

struct Ov014eDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

struct Ov014eRot {
    u16 x;
    u16 y;
    u16 z;
};

extern "C" {

extern void *data_ov014_02216500[];
extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern void *data_0214a420;
extern Ov014Vec data_ov014_022165a0;
extern Ov014Vec data_ov014_02216624;
extern Ov014Actor *func_ov000_0218d240(Ov014Actor *self);
extern void *func_0204a028(void *a, s32 b, Ov014Vec *c, s32 d);
extern s32 func_ov003_021d9edc(s32 a);
extern void func_01ffc9fc(Ov014Vec *a, Ov014Vec *b, u16 ang);
extern void VEC_Add(const Ov014Vec *a, const Ov014Vec *b, Ov014Vec *out);
extern void func_ov000_0218d918(Ov014Actor *self, Ov014Vec *v, s32 a);
extern void func_ov000_0218d9e8(Ov014Actor *self, Ov014Vec *v, s32 a);
extern Ov014V *func_02065f88(s32 id, Ov014Vec *pos);
extern void func_ov003_021da9ac(void *p, u8 id, void *obj);
extern Ov014Actor *func_ov000_0218bf1c(void *mgr, Ov014eDesc *d, Ov014Vec *pos, u16 *rot, u16 a);
extern void func_ov000_0219bebc(Ov014Actor *a, s32 b);
extern void func_ov000_0218ddd4(Ov014Actor *self, Ov014Vec *v, s32 a);
extern u16 FX_Atan2(s32 x, s32 z);
extern void *func_ov003_021daa3c(void *p, u8 id);
extern Ov014V *func_020657b0(void *a, void *b);

#define OV014E_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014E_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014E_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline void Ov014e_RotX(Ov014Vec *out, const Ov014Vec *in, u16 ang) {
    s32 y = 0;
    s32 z = 0;
    s32 idx = ang >> 4;
    s32 s = FX_SinCosTable_[idx * 2];
    s32 c = FX_SinCosTable_[idx * 2 + 1];
    if (in->y != 0) {
        y += (s32)(((s64)c * in->y + 0x800) >> 12);
        z += (s32)(((s64)s * in->y + 0x800) >> 12);
    }
    if (in->z != 0) {
        y += (s32)(((s64)-s * in->z + 0x800) >> 12);
        z += (s32)(((s64)c * in->z + 0x800) >> 12);
    }
    out->x = in->x;
    out->y = y;
    out->z = z;
}

// Same rotation as Ov014e_RotX, written with the table reads first (codegen differs).
static inline void Ov014e_RotX2(Ov014Vec *out, const Ov014Vec *in, u16 ang) {
    s32 idx = ang >> 4;
    s32 c;
    s32 s;
    s = FX_SinCosTable_[idx * 2];
    c = FX_SinCosTable_[idx * 2 + 1];
    s32 y = 0;
    s32 z = 0;
    if (in->y != 0) {
        y += (s32)(((s64)c * in->y + 0x800) >> 12);
        z += (s32)(((s64)s * in->y + 0x800) >> 12);
    }
    if (in->z != 0) {
        y += (s32)(((s64)-s * in->z + 0x800) >> 12);
        z += (s32)(((s64)c * in->z + 0x800) >> 12);
    }
    out->x = in->x;
    out->y = y;
    out->z = z;
}

static inline void Ov014e_Target(Ov014Actor *self, s32 n, Ov014Vec &v) {
    v.x = 0 - self->pos.x;
    v.y = 0x4719a - self->pos.y;
    v.z = 0xf000 - self->pos.z;
    v.y += 0x1000;
    func_01ffc9fc(&v, &v, (u16)(func_02040528(n) * 0xb6));
    VEC_Add(&v, &self->pos, &v);
    self->unk_84 = v;
}

static inline void Ov014e_Spawn(Ov014eDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

static inline Ov014Actor *Ov014e_SpawnAt(Ov014Actor *self, u16 kind, const Ov014Vec *off) {
    Ov014eDesc d;
    Ov014e_Spawn(&d, kind);
    Ov014Vec w = *off;
    Ov014e_RotX2(&w, &w, self->rot[0]);
    func_01ffc9fc(&w, &w, self->rot[1]);
    VEC_Add(&self->pos, &w, &w);
    return func_ov000_0218bf1c(data_ov000_021ccd64, &d, &w, self->rot, 0xffff);
}

static inline void Ov014e_Toward(Ov014Actor *self, const Ov014Vec *t, s32 sp) {
    Ov014Vec dd;
    dd.x = t->x - self->pos.x;
    dd.y = t->y - self->pos.y;
    dd.z = t->z - self->pos.z;
    VEC_MultAdd(sp, &dd, &self->pos, &self->pos);
}

void func_ov014_022049e8(Ov014Actor *self) {
    Ov014Vec t;
    Ov014Vec pl;
    Ov014Vec tv;
    {
        Ov014Actor *p = func_ov000_0218d240(self);
        pl.x = p->pos.x;
        pl.y = p->pos.y;
        pl.z = p->pos.z;
    }
    Ov014Sub40 *s = self->unk_40;
    switch (s->state) {
    case 10: {
        func_ov000_02190cb0(self->unk_38, data_ov014_02216500[1], 0x400, 0);
        func_0204a028(data_02097e4c, 0x35, &self->pos, 0xa);
        s32 c = 0;
        c += func_ov003_021d9edc(0x580c);
        c += func_ov003_021d9edc(0x580d);
        if (c != 0) {
            Ov014e_Target(self, 0x14, tv);
            FLD(u32, self, 0xf4) |= 0x1000000;
        }
        FLD(u8, self, 0x12f) = 0;
        self->unk_40->state++;
    }
    case 11:
        if (FLD(u32, self, 0xf4) & 0x1000000) {
            func_ov000_0218d918(self, &self->unk_84, 0x11f);
            self->unk_98 = self->rot[1];
            func_ov000_0218d9e8(self, &self->unk_84, 0x11f);
        } else {
            func_ov000_0218d918(self, &pl, 0x11f);
            self->unk_98 = self->rot[1];
            func_ov000_0218d9e8(self, &pl, 0x11f);
        }
        if (func_ov000_02191120(self->unk_38)) {
            self->unk_40->state++;
        }
        break;
    case 12: {
        Ov014eRot r = {0, 0, 0};
        r.x = self->rot[0] + 0x4000;
        r.y = self->rot[1];
        Ov014Vec v = data_ov014_022165a0;
        Ov014e_RotX(&v, &v, self->rot[0]);
        func_01ffc9fc(&v, &v, self->rot[1]);
        Ov014V *e = func_02065f88(0x66, &self->pos);
        e->v30(&r);
        e->v20(&v);
        e->v0c(0x40);
        func_ov003_021da9ac(FLD(void *, self, 0xfc), 0xfd, e);
        if (!(FLD(u32, self, 0xf4) & 0x1000000)) {
            self->unk_84 = pl;
            self->unk_84.y += 0x1000;
        }
        {
            Ov014Actor *a = Ov014e_SpawnAt(self, 0x482a, &data_ov014_02216624);
            if (a != NULL) {
                FLD(u8, a, 0x16) = (FLD(u8, a, 0x16) & ~1) | 1;
                a->unk_84 = self->unk_84;
                func_ov000_0219bebc(a, FLD(s16, self, 0x12c));
                if (FLD(void *, a, 0x4c) != NULL) {
                    FLD(u16, FLD(void *, a, 0x4c), 0x1c) = self->id;
                }
            }
        }
        func_0204a028(data_02097e4c, 0x32, &self->pos, 0xa);
        {
            Ov014Vec o;
            o.x = 0;
            o.y = 0;
            o.z = -0x1800;
            Ov014e_RotX(&o, &o, self->rot[0]);
            func_01ffc9fc(&o, &o, self->rot[1]);
            VEC_Add(&self->pos, &o, &t);
        }
        self->unk_b8 = t;
        self->unk_84 = self->pos;
        self->unk_40->state++;
        break;
    }
    case 13: {
        t = self->unk_b8;
        Ov014e_Toward(self, &t, 0x4cd);
        if (VEC_Distance(&self->pos, &self->unk_b8) <= 0x4cd) {
            s32 r;
            u16 ang;
            {
                s64 sq;
                s32 dx;
                s32 dz;
                dx = self->pos.x - self->unk_84.x;
                dz = self->pos.z - self->unk_84.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                self->unk_9c = 0;
                self->unk_a0 = 0;
                self->unk_a4 = 0;
                self->unk_a8 = 0;
                OV014E_SQRTCNT = 1;
                OV014E_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV014E_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014E_SQRT_RESULT + 1) >> 1;
            ang = FX_Atan2(r, self->unk_84.y - self->pos.y);
            self->unk_9c = (s32)(((s64)OV014_SIN(ang) * (s64)0x19a + 0x800) >> 12);
            self->unk_a0 = (s32)(((s64)OV014_COS(ang) * (s64)0x19a + 0x800) >> 12);
            self->unk_b8 = self->unk_84;
            self->unk_40->state++;
        }
        break;
    }
    case 14:
        t = self->unk_b8;
        func_ov000_0218ddd4(self, &t, 0);
        if (VEC_Distance(&self->pos, &self->unk_b8) <= 0x19a) {
            s32 n = 0;
            self->pos = t;
            if (FLD(u16 *, self, 0x130) != NULL) {
                n = FLD(u16 *, self, 0x130)[3];
            }
            if (++FLD(u8, self, 0x12f) < n) {
                if (FLD(u32, self, 0xf4) & 0x1000000) {
                    Ov014e_Target(self, 0x32, tv);
                }
                self->unk_40->state++;
            } else {
                self->unk_40->state = 16;
            }
        }
        break;
    case 15:
        if (FLD(u32, self, 0xf4) & 0x1000000) {
            func_ov000_0218d918(self, &self->unk_84, 0x266);
            self->unk_98 = self->rot[1];
            func_ov000_0218d9e8(self, &self->unk_84, 0x266);
        } else {
            func_ov000_0218d918(self, &pl, 0x266);
            self->unk_98 = self->rot[1];
            func_ov000_0218d9e8(self, &pl, 0x266);
        }
        s = self->unk_40;
        s->timer++;
        if (s->timer == 30) {
            self->unk_40->timer = 0;
            self->unk_40->state = 12;
        }
        break;
    case 16:
        s->timer++;
        if (s->timer == 30) {
            if (FLD(u32, self, 0xf4) & 0x1000000) {
                FLD(u32, self, 0xf4) ^= 0x1000000;
            }
            self->unk_40->timer = 0;
            self->unk_40->state = 20;
        }
        break;
    }
    {
        Ov014V *x = func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0xfc), 0xfd));
        if (x != NULL) {
            x->v0c(FLD(s32, x, 0x40) + 0x266);
        }
    }
}

}
