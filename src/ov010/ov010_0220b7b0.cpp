#include "ov010/ov010.h"

extern "C" {

extern u8 data_ov010_0220f534[];
extern void *data_ov000_021ccd68;
extern void *func_ov000_0218e640(void *mgr, u16 id);
extern Ov010V *func_02065f88(s32 a, Ov010Vec *b);
extern void func_ov010_02209074(void *p);
extern void func_ov000_0218d398(void *obj, u16 id, s32 a, s32 b, s32 c, u8 *d);
extern void func_ov000_02198360(void *a, s32 b, s32 c);
extern void func_ov000_02190cb0(void *p, s32 a, s32 b, s32 c);
extern void func_ov000_021915a0(void *p);
extern u8 *func_ov000_02190a30(void *p, s32 a);
extern void func_ov000_02195d88(void *self);

static inline void *Ov010_FindObjById(u16 id) {
    if (data_ov000_021ccd68 != NULL) {
        return func_ov000_0218e640(data_ov000_021ccd68, id);
    }
    return NULL;
}

void func_ov010_0220b7b0(void *self) {
    if (FLD(u16, FLD(void *, self, 0x40), 0) != 0) {
        return;
    }
    Ov010Vec p = FLD(Ov010Vec, self, 0x70);
    Ov010V *fx;
    void *obj;
    fx = func_02065f88(0x321, &p);
    fx->v0c(0x1000);
    FLD(void *, fx, 0xdc) = (void *)func_ov010_02209074;
    FLD(s32, fx, 4) = 6;
    obj = Ov010_FindObjById(FLD(u16, self, 0x180));
    if (obj != NULL) {
        u8 c = 1;
        func_ov000_0218d398(obj, FLD(u16, self, 0xc), 0xe, 1, 1, &c);
    }
    FLD(Ov010Flags, FLD(void *, self, 0x38), 0xc2).b0 = 0;
    FLD(u8, self, 0xcf) = 0;
    func_ov000_02198360(FLD(void *, self, 0x40), 0x15, 0);
}

void func_ov010_0220b890(void *self) {
    if (FLD(u16, FLD(void *, self, 0x40), 0) != 0) {
        return;
    }
    if (FLD(void *, self, 0x38) != NULL) {
        func_ov000_02190cb0(FLD(void *, self, 0x38), FLD(s32, data_ov010_0220f534, 0xc), 0x1000, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
    }
    FLD(u16, FLD(void *, self, 0x40), 0) = 1;
    FLD(s32, self, 0x9c) = 0;
    FLD(s32, self, 0xa0) = 0;
    FLD(s32, self, 0xa4) = 0;
    FLD(s32, self, 0xa8) = 0;
}

void func_ov010_0220b8f8(void *self) {
    u8 *p = func_ov000_02190a30(FLD(void *, self, 0x38), 0);
    FLD(Ov010Flags8, p, 0x111).b3 = 0;
    func_ov000_02195d88(self);
}

extern Ov010Vec data_ov010_0220f54c;
extern Ov010Vec data_ov010_0220f594;
extern void *data_02097e4c;
extern void *data_0214a420;
extern void func_0203f324(void *p);
extern void func_0203f364(void *p);
extern void func_ov000_0218dbe0(void *self, s32 a);
extern void MTX_RotY33_(void *m, s32 s, s32 c);
extern void MTX_MultVec33(const Ov010Vec *v, const void *m, Ov010Vec *out);
extern u16 func_ov003_021d9c38(Ov010Vec *v);
extern void VEC_Add(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *c);
extern void VEC_Normalize(const Ov010Vec *a, Ov010Vec *b);
extern void func_ov003_021d9e90(Ov010Vec *a, Ov010Vec *b, Ov010Vec *c, s32 d, s32 e);
extern void func_ov003_021da2c8(void *self, s32 a, s32 b, s32 c, s32 d);
extern void func_ov003_021d9f04(void *out, const void *p);
extern void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
extern s32 func_02040498(s32 max);
extern void *func_ov000_02199ba0(void *p);
extern u16 func_ov000_0219a874(void *a, void *b, s32 c);
extern Ov010V *func_ov003_021da7e8(s32 id, void *src, const Ov010Vec *ofs);
extern void func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern s32 func_ov003_021d9a80(const Ov010Vec &a, const Ov010Vec *b);
extern void *func_ov000_0218e4cc(void *mgr, s32 a);
extern void func_02065860(void *a, void *b);

#define OV010_FXMUL_K(a, k) ((s32)(((s64)(a) * (k) + 0x800) >> 12))

struct Ov010Mtx33 {
    s32 m[9];
};

struct Ov010HitMsg {
    u16 a;
    u8 b;
    u8 pad;
    u16 id;
};

static inline void Ov010_VecSubA(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out) {
    s32 ax = a->x;
    s32 ay = a->y;
    s32 az = a->z;
    out->x = ax - b->x;
    out->y = ay - b->y;
    out->z = az - b->z;
}

static inline void Ov010_VecSubB(const Ov010Vec *a, const Ov010Vec *b, Ov010Vec *out) {
    s32 bx = b->x;
    s32 by = b->y;
    s32 bz = b->z;
    out->x = a->x - bx;
    out->y = a->y - by;
    out->z = a->z - bz;
}

static inline void *Ov010_FindObjById2(u16 id) {
    void *o = NULL;
    if (data_ov000_021ccd68 != NULL) {
        o = func_ov000_0218e640(data_ov000_021ccd68, id);
    }
    return o;
}

static inline void *Ov010_FindObjById3(u16 id) {
    return data_ov000_021ccd68 != NULL ? func_ov000_0218e640(data_ov000_021ccd68, id) : NULL;
}

static inline Ov010Vec Ov010_TargetCenter(void *self) {
    Ov010Vec v;
    Ov010Vec *b = FLD(Ov010Vec *, self, 0xe4);
    s32 *a = FLD(s32 *, self, 0xe0);
    switch (FLD(s32, self, 0xdc)) {
    case 0:
        v.x = a[0] + ((a[2] - a[0]) >> 1);
        v.y = a[4];
        v.z = a[1] + ((a[3] - a[1]) >> 1);
        break;
    case 1:
        v.x = b->x;
        v.y = b->y;
        v.z = b->z;
        break;
    }
    return v;
}

void func_ov010_0220b924(void *self) {
    Ov010Vec d;
    Ov010Vec v1;
    Ov010Vec v2;
    Ov010Mtx33 m;
    Ov010Vec o;
    Ov010Vec p;
    Ov010Vec d2;
    Ov010HitMsg msg;
    void *s40 = FLD(void *, self, 0x40);
    switch (FLD(u16, s40, 0)) {
    case 0:
    case 0x10: {
        void *mm = FLD(void *, self, 0x48);
        FLD(Ov010Flags, mm, 0x9a).b0 = 1;
        FLD(Ov010Flags, mm, 0x9a).b3 = 1;
        func_0203f324(mm);
        FLD(s32, FLD(void *, self, 0x48), 0x30) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(u16, self, 0x98) = FLD(u16, self, 0x7e);
        FLD(s32, self, 0x9c) = 0x2b0;
        FLD(s32, self, 0xa0) = 0x80;
        FLD(s32, self, 0xa8) = 0x20;
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x11;
        break;
    }
    case 0x11:
        FLD(u16, s40, 2)++;
        if (FLD(u16, FLD(void *, self, 0x40), 2) >= 0xc) {
            FLD(u16, FLD(void *, self, 0x40), 2) = 0;
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x20;
        }
        func_ov000_0218dbe0(self, 0);
        break;
    case 0x20:
        FLD(s32, self, 0xa4) = 0xa00;
        func_ov000_0218dbe0(self, 0);
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x21;
        break;
    case 0x21: {
        s32 k;
        FLD(u16, s40, 2)++;
        FLD(u16, FLD(void *, self, 0x40), 2) = 0;
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x30;
        func_ov000_0218dbe0(self, 0);
        k = FLD(s32, self, 0xa4);
        if (k != 0 && k != 0x1000) {
            FLD(s32, self, 0xa0) = Ov010_FxMul(FLD(s32, self, 0xa0), k);
        }
        break;
    }
    case 0x30: {
        void *t;
        BOOL ok;
        FLD(u16, self, 0x98) = FLD(u16, self, 0x7e);
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        FLD(s32, self, 0x9c) = 0;
        t = Ov010_FindObjById2(FLD(u16, self, 0x90));
        ok = FALSE;
        if (t != NULL) {
            BOOL b;
            BOOL a;
            void *q;
            s32 dot;
            u16 ang;
            Ov010_VecSubA(&FLD(Ov010Vec, t, 0x70), &FLD(Ov010Vec, self, 0x70), &d);
            q = FLD(void *, t, 0x40);
            a = (q != NULL ? FLD(u8, q, 0x13) : 0) == 0x13;
            b = FALSE;
            MTX_RotY33_(&m, OV010_SIN(FLD(u16, self, 0x98)), OV010_COS(FLD(u16, self, 0x98)));
            MTX_MultVec33(&data_ov010_0220f54c, &m, &v1);
            ang = func_ov003_021d9c38(&d);
            MTX_RotY33_(&m, OV010_SIN(ang), OV010_COS(ang));
            MTX_MultVec33(&data_ov010_0220f54c, &m, &v2);
            dot = (s32)(((s64)v1.x * v2.x + (s64)v1.y * v2.y + (s64)v1.z * v2.z + 0x800) >> 12);
            if (dot > 0x1000) {
                dot = 0x1000;
            } else if (dot < -0x1000) {
                dot = -0x1000;
            }
            if (dot >= 0xf00) {
                b = TRUE;
            }
            if (!a && b) {
                ok = TRUE;
            }
        }
        if (ok) {
            OV010_BLKCPY(&o, &data_ov010_0220f594);
            o.y += OV010_FXMUL_K(FLD(s32, t, 0x68), 0x99a);
            p.x = FLD(s32, t, 0x70);
            p.y = FLD(s32, t, 0x74);
            p.z = FLD(s32, t, 0x78);
            VEC_Add(&p, &o, &p);
            FLD(s32, self, 0x108) = p.x - FLD(s32, self, 0x70);
            FLD(s32, self, 0x10c) = p.y - FLD(s32, self, 0x74);
            FLD(s32, self, 0x110) = p.z - FLD(s32, self, 0x78);
            VEC_Normalize(&FLD(Ov010Vec, self, 0x108), &FLD(Ov010Vec, self, 0x108));
        } else {
            func_ov003_021d9900(&FLD(Ov010Vec, self, 0x108), 0xfc71, &data_ov010_0220f54c);
            func_ov003_021d9980(&FLD(Ov010Vec, self, 0x108), FLD(u16, self, 0x7e), &FLD(Ov010Vec, self, 0x108));
        }
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x31;
        break;
    }
    case 0x31: {
        s32 sp;
        void *s48;
        sp = FLD(s32, self, 0x9c) + 0x180;
        FLD(s32, self, 0x9c) = sp;
        if (sp > 0x1666) {
            sp = 0x1666;
        } else if (sp < 0) {
            sp = 0;
        }
        FLD(s32, self, 0x9c) = sp;
        func_ov003_021d9e90(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0x108), &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x9c), FLD(s32, self, 0xa0));
        func_ov003_021da2c8(self, FLD(s32, self, 0x9c), FLD(s32, self, 0xa0), FLD(s32, self, 0xa4), FLD(s32, self, 0xa8));
        func_ov003_021d9f04(&FLD(u16, self, 0x7c), &FLD(Ov010Vec, self, 0x108));
        s48 = FLD(void *, self, 0x48);
        FLD(s32, s48, 0x44) = OV010_FXMUL_K(FLD(s32, s48, 0x38), 0x800);
        func_ov000_021987b8(FLD(void *, self, 0x48), 1, 0, 0);
        if (FLD(u32, FLD(void *, self, 0x48), 0x58) & 0x20) {
            void *t = Ov010_FindObjById2(FLD(u16, self, 0x90));
            void *q;
            Ov010V *e;
            if (t == NULL) {
                FLD(u16, FLD(void *, self, 0x40), 0) = 0x50;
                return;
            }
            FLD(u16, self, 0x180) = FLD(u16, t, 0xc);
            FLD(Ov010Flags8, func_ov000_02190a30(FLD(void *, self, 0x38), 0), 0x111).b3 = 1;
            FLD(u16, self, 0x7c) += (u16)(func_02040498(0x2000) - 0x1000);
            FLD(u16, self, 0x7e) += (u16)(func_02040498(0x2000) - 0x1000);
            q = func_ov000_02199ba0(FLD(void *, self, 0x4c));
            if (q != NULL) {
                FLD(u16, self, 0x182) = FLD(u16, q, 0xc);
                msg.a = func_ov000_0219a874(FLD(void *, t, 0x50), FLD(void *, q, 0x50), 0x14);
                msg.b = 0x10;
                msg.id = FLD(u16, self, 0xc);
                func_ov000_0218d398(t, FLD(u16, self, 0xc), 9, 0, 6, (u8 *)&msg);
            }
            Ov010_VecSubB(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, t, 0x70), &d2);
            func_ov003_021d9980(&d2, (u16)(0xffff - FLD(u16, t, 0x7e)), &d2);
            e = func_ov003_021da7e8(0x6c, t, &d2);
            e->v34((u16)(FLD(u16, self, 0x7c) + 0x4000), 0, 0);
            e->v0c(0x1800);
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x40;
            func_02049f44(data_02097e4c, 0x66, &FLD(Ov010Vec, self, 0x70), 0);
            return;
        }
        if (func_ov003_021d9a80(Ov010_TargetCenter(self), &FLD(Ov010Vec, self, 0x70)) > 0x190000) {
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x50;
        }
        break;
    }
    case 0x40: {
        void *t = Ov010_FindObjById3(FLD(u16, self, 0x180));
        u8 *ec;
        BOOL found;
        if (t == NULL) {
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x50;
            return;
        }
        Ov010_VecSubB(&FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, t, 0x70), &FLD(Ov010Vec, self, 0x184));
        FLD(u16, self, 0x190) = FLD(u16, t, 0x7c);
        FLD(u16, self, 0x192) = FLD(u16, t, 0x7e);
        FLD(u16, self, 0x194) = FLD(u16, t, 0x80);
        FLD(u16, self, 0x196) = FLD(u16, self, 0x7c);
        FLD(u16, self, 0x198) = FLD(u16, self, 0x7e);
        FLD(u16, self, 0x19a) = FLD(u16, self, 0x80);
        FLD(s32, self, 0xd8) = 7;
        {
            void *mm = FLD(void *, self, 0x48);
            FLD(Ov010Flags, mm, 0x9a).b0 = 0;
            FLD(Ov010Flags, mm, 0x9a).b3 = 0;
            func_0203f364(mm);
        }
        FLD(u16, FLD(void *, self, 0x40), 0) = 0x41;
        ec = FLD(u8 *, self, 0xec);
        if ((FLD(Ov010Flags8, ec, 0).b0 ? ec[0x6b] : 0) == 1) {
            return;
        }
        found = FALSE;
        {
            void *g = func_ov000_0218e4cc(data_ov000_021ccd68, 0x4000);
            void *it;
            for (it = FLD(void *, g, 0xc); it != NULL; it = FLD(void *, it, 8)) {
                if (it != self && FLD(u16, it, 0xe) == 0x4817 && FLD(s32, it, 0xd8) == 7) {
                    found = TRUE;
                    break;
                }
            }
        }
        if (found) {
            ec = FLD(u8 *, self, 0xec);
            if (!FLD(Ov010Flags8, ec, 0).b0) {
                return;
            }
            func_02065860(data_0214a420, FLD(void *, ec, 8));
            FLD(void *, ec, 8) = NULL;
            func_ov000_02198360(ec + 0x58, 1, 0);
            return;
        }
        func_ov000_02198360(FLD(void *, self, 0x40), 6, 0);
        break;
    }
    case 0x41:
        break;
    case 0x50: {
        func_ov000_02198360(s40, 0x15, 0);
        {
            void *mm = FLD(void *, self, 0x48);
            FLD(Ov010Flags, mm, 0x9a).b0 = 0;
            FLD(Ov010Flags, mm, 0x9a).b3 = 0;
            func_0203f364(mm);
        }
        {
            Ov010Flags *f = &FLD(Ov010Flags, FLD(void *, self, 0x44), 0x22);
            f->b0 = 0;
            f->b1 = 0;
        }
        break;
    }
    }
}

}
