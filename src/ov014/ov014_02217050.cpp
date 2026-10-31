#include "ov014/ov014.h"

typedef s16 fx16;
typedef Ov014Vec VecFx32;
struct VecFx16 { fx16 x, y, z; };
#define FX32_ONE 0x1000

// A header's zero rotation and vector, plus copies made at startup, with this TU's offset
// between them. Other functions read all three constants.
// The functions of 0x022054f8..0x02206050 (four files, merged in round dtB, each in its own
// namespace) are part of this TU: they read the zero vector through the .rodata base plus an
// offset, and name it (data_ov014_022169d4) instead of an FLD view of data_ov014_022169c0.
extern const VecFx16 data_ov014_022169c0;
extern const VecFx32 data_ov014_022169c8;
extern const VecFx32 data_ov014_022169d4;
const VecFx16 data_ov014_022169c0 = {0, 0, 0};
const VecFx32 data_ov014_022169c8 = {0, 0x333, 0};
static const VecFx16 data_ov014_0221762c = data_ov014_022169c0;
const VecFx32 data_ov014_022169d4 = {0, 0, 0};
static const VecFx32 data_ov014_02217634 = data_ov014_022169d4;

// ---- merged from ov014_022054f8.cpp
namespace m_022054f8 {
extern "C" {

extern void func_ov000_02194758(void *self);
extern void func_0203f364(Ov014Sub48 *p);
extern BOOL func_ov000_02199ba0(void *p);

void func_ov014_022054f8(void) {
}

void func_ov014_022054fc(Ov014Actor *self) {
    Ov014Sub38 *m;
    func_ov000_02194758(self);
    FLD(s32, self, 0xd0) = 0;
    FLD(s32, self, 0xe0) = 0;
    FLD(u8, self, 0xe4) = 0;
    {
        Ov014Sub48 *s48 = self->unk_48;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
    }
    self->unk_48->unk_30 = 0;
    {
        Ov014Sub44 *n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
    }
    m = self->unk_38;
    Ov014_VecCopyYZ(&FLD(Ov014Vec, self, 0xd4), &FLD(Ov014Vec, m, 0xa8));
    FLD(Ov014Vec, m, 0xa8) = data_ov014_022169d4;
    func_ov000_02198360(self->unk_40, 1, 0);
}

void func_ov014_022055ac(Ov014Actor *self) {
    Ov014Sub38 *m;
    s32 s;
    if (!func_ov000_02199ba0(FLD(void *, self, 0x4c))) {
        FLD(u32, self, 0xd0) |= 0x1000;
        func_ov000_02198360(self->unk_40, 0x15, 0);
        return;
    }
    if (self->unk_40->state != 0) {
        return;
    }
    if (FLD(s32, self, 0xe0) < FLD(s32, self, 0xd4)) {
        FLD(s32, self, 0xe0) += 0xcd;
    } else {
        FLD(s32, self, 0xe0) = FLD(s32, self, 0xd4);
        func_ov000_02198360(self->unk_40, 0xb, 0);
    }
    m = self->unk_38;
    s = FLD(s32, self, 0xe0);
    FLD(Ov014Vec, m, 0xa8).x = s;
    FLD(Ov014Vec, m, 0xa8).y = s;
    FLD(Ov014Vec, m, 0xa8).z = s;
}

}
}  // namespace m_022054f8

// ---- merged from ov014_02205634.cpp
namespace m_02205634 {
extern "C" {

extern void func_ov000_0218d918(Ov014Actor *self, Ov014Vec *v, s32 a);
extern void func_ov000_0218dbe0(Ov014Actor *self, s32 a);
extern u16 FX_Atan2(s32 x, s32 z);
extern void func_ov014_02205d70(Ov014Actor *self);

extern Ov014Actor *func_ov000_02199ba0(void *p);
extern Ov014Actor *func_ov000_0218d240(Ov014Actor *self);
extern void func_0203f364(Ov014Sub48 *p);
extern void func_ov014_02205924(Ov014Actor *self);
extern Ov014V *func_02065f88(s32 id, Ov014Vec *v);
extern void *func_0204a028(void *a, s32 b, Ov014Vec *c, s32 d);
extern void *data_02097e4c;

#define OV014_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014_SQRT_RESULT (*(volatile u32 *)0x40002b4)

// Like the SDK's CP_SetSqrt64: the parameter is written through a plain (non-volatile)
// u64 pointer, so the scheduler may still move other stores around it.
static inline void Ov014_SetSqrt64(u64 param) {
    OV014_SQRTCNT = 1;
    *(u64 *)0x40002b8 = param;
}

static inline s32 Ov014g_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov014_02205634(Ov014Actor *self) {
    Ov014Actor *t = func_ov000_02199ba0(FLD(void *, self, 0x4c));
    if (t != NULL) {
        {
            Ov014Sub48 *m = t->unk_48;
            if (m != NULL && m->unk_9a_3) {
                m->unk_9a_3 = 0;
                func_0203f364(m);
            }
        }
        if (t->kind == 0x1000) {
            func_ov014_02205924(self);
            return;
        }
        switch (self->unk_40->state) {
        case 0: {
            Ov014Actor *g;
            s32 r;
            u16 a;
            Ov014V *e;
            {
                Ov014Sub44 *n = self->unk_44;
                n->unk_22_0 = 1;
                n->unk_22_1 = 1;
            }
            g = func_ov000_0218d240(self);
            {
                s64 sq;
                s32 dx;
                s32 dz;
                Ov014Vec p;
                Ov014_VecCopyYZ(&p, &g->pos);
                dx = self->pos.x - p.x; dz = self->pos.z - p.z; sq = (s64)dx * dx; sq += (s64)dz * dz;
                self->unk_84.x = p.x;
                self->unk_84.y = p.y + 0x1000;
                self->unk_84.z = p.z;
                Ov014_SetSqrt64((u64)(sq * 4));
            }
            while (OV014_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014_SQRT_RESULT + 1) >> 1;
            a = FX_Atan2(r, self->unk_84.y - self->pos.y);
            self->unk_9c = Ov014g_FxMul64(OV014_SIN(a), 0x666);
            FLD(s32, self, 0xa0) = Ov014g_FxMul64(OV014_COS(a), 0x666);
            self->rot[0] = FX_Atan2(self->pos.y - self->unk_84.y, r);
            e = func_02065f88(0x68, &self->pos);
            e->v0c(0xb33);
            e->v34(0xbfff, self->rot[1], 0);
            func_02065f88(0x6b, &self->pos);
            func_0204a028(data_02097e4c, 0x35, &self->pos, 5);
            {
                Ov014Sub48 *m = self->unk_48;
                m->unk_50 = 0;
                m->unk_54 = 0;
                FLD(u32, m, 0x58) = 0;
            }
            FLD(u8, self, 0xe4) = 0;
            self->unk_40->state++;
            break;
        }
        case 1:
            if (self->pos.y - self->unk_84.y > 0x1000) {
                func_ov000_0218d918(self, &self->unk_84, 0x266);
                self->unk_98 = self->rot[1];
            }
            func_ov000_0218dbe0(self, 0);
            func_ov014_02205d70(self);
            if ((self->unk_48->unk_50 & 0x20000000) || ++FLD(u8, self, 0xe4) >= 100) {
                FLD(u32, self, 0xd0) |= 0x1000;
                func_ov000_02198360(self->unk_40, 0x15, 0);
            }
            break;
        }
    } else {
        FLD(u32, self, 0xd0) |= 0x1000;
        func_ov000_02198360(self->unk_40, 0x15, 0);
    }
}

}
}  // namespace m_02205634

// ---- merged from ov014_02205924.cpp
namespace m_02205924 {
extern "C" {

extern Ov014Vec *func_ov000_0218d2e0(void *self);
extern void VEC_Normalize(Ov014Vec *a, Ov014Vec *b);
extern void VEC_Add(const Ov014Vec *a, const Ov014Vec *b, Ov014Vec *out);
extern void func_ov000_0218d918(Ov014Actor *self, Ov014Vec *v, s32 a);
extern void func_ov000_0218dbe0(Ov014Actor *self, s32 a);
extern u16 FX_Atan2(s32 x, s32 z);
extern void func_ov014_02205d70(Ov014Actor *self);

#define OV014_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014_SQRT_PARAM (*(volatile u64 *)0x40002b8)

void func_ov014_02205924(Ov014Actor *self) {
    Ov014Vec d;
    switch (self->unk_40->state) {
    case 0: {
        Ov014Vec *p;
        {
            Ov014Sub44 *n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
        }
        self->unk_9c = 0;
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        p = func_ov000_0218d2e0(self);
        if (p != NULL) {
            s32 r;
            s32 dx;
            s32 dz;
            d = *p;
            self->unk_84.x = d.x;
            self->unk_84.y = d.y;
            self->unk_84.z = d.z;
            d.y = d.y - self->pos.y;
            {
                s64 sq;
                dx = self->pos.x - d.x;
                dz = self->pos.z - d.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                OV014_SQRTCNT = 1;
                OV014_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV014_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014_SQRT_RESULT + 1) >> 1;
            d.x = Ov014_FxMul(r, OV014_SIN(self->rot[1]));
            d.z = Ov014_FxMul(r, OV014_COS(self->rot[1]));
            VEC_Normalize(&d, &d);
            self->unk_9c = Ov014_FxMul(d.x, 0x59a);
            FLD(s32, self, 0xa0) = Ov014_FxMul(d.y, 0x59a);
            FLD(s32, self, 0xa4) = Ov014_FxMul(d.z, 0x59a);
            FX_Atan2(r, self->unk_84.y - self->pos.y);
            self->rot[0] = FX_Atan2(self->pos.y - self->unk_84.y, r);
            FLD(u32, self, 0xd0) |= 0x200000;
        } else {
            self->unk_9c = 0x4cd;
            self->unk_98 = self->rot[1];
        }
        {
            Ov014Sub48 *m = self->unk_48;
            m->unk_50 = 0;
            m->unk_54 = 0;
            FLD(u32, m, 0x58) = 0;
        }
        FLD(u8, self, 0xe4) = 0;
        self->unk_40->state++;
        break;
    }
    case 1:
        if (FLD(u32, self, 0xd0) & 0x200000) {
            func_ov000_0218d918(self, &self->unk_84, 0x1000);
            VEC_Add(&self->pos, (Ov014Vec *)&self->unk_9c, &self->pos);
        } else {
            func_ov000_0218dbe0(self, 0);
        }
        func_ov014_02205d70(self);
        if ((self->unk_48->unk_50 & 0x20000000) || ++FLD(u8, self, 0xe4) >= 100) {
            FLD(u32, self, 0xd0) |= 0x1000;
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
        break;
    }
}

}
}  // namespace m_02205924

// ---- merged from ov014_02205c1c.cpp
namespace m_02205c1c {
extern "C" {

extern void *data_ov000_021ccd64;
extern void *data_02097e4c;
extern void *data_0214a420;
extern void func_ov000_02198c8c(void *p, s32 a);
extern void func_0203f364(Ov014Sub48 *p);
extern Ov014Actor *func_02065f88(s32 id, Ov014Vec *pos);
extern void *func_02049f44(void *a, s32 b, Ov014Vec *c, s32 d);
extern void func_ov000_0218bed8(void *a, s32 b, void *c);
extern Ov014Actor *func_ov000_02199ba0(void *p);
extern s32 func_ov000_0219a510(Ov014Actor *self, u16 mask, Ov014Vec *pos, s32 r, s32 a, Ov014Actor **list);
extern Ov014Actor *func_ov000_021985c0(Ov014Actor *p);
extern void func_ov003_021f0c60(Ov014Actor *self, s32 a);
extern void func_ov000_02194758(void *self);
extern BOOL func_020657b0(void *a, void *b);

void func_ov014_02205c1c(Ov014Actor *self) {
    FLD(u32, self, 0xd0) |= 0x1000;
    func_ov000_02198360(self->unk_40, 0x15, 0);
}

void func_ov014_02205c40(Ov014Actor *self) {
    switch (self->unk_40->state) {
    case 0:
        if (self->unk_44 != NULL) {
            Ov014Sub44 *n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
        }
        if (self->unk_48 != NULL) {
            Ov014Sub48 *m;
            func_ov000_02198c8c(self->unk_48, 0xffff);
            m = self->unk_48;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
            m = self->unk_48;
            m->unk_9a_1 = 0;
            m->unk_9a_4 = 0;
        }
        self->unk_38->unk_c2_0 = 0;
        if (FLD(u32, self, 0xd0) & 0x1000) {
            func_02065f88(0x38f, &self->pos);
        } else {
            func_02065f88(4, &self->pos);
        }
        func_02049f44(data_02097e4c, 0x19, &self->pos, 0);
        self->unk_40->state++;
        break;
    case 1:
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->v08();
        break;
    }
}

void func_ov014_02205d70(Ov014Actor *self) {
    Ov014Actor *list[0x20];
    s32 r;
    s32 n;
    u16 k;
    s32 i;
    r = self->unk_64 + 0x4cd;
    if (r < 0xccd) {
        r = 0xccd;
    }
    self->unk_48->unk_44 = r;
    k = func_ov000_02199ba0(FLD(void *, self, 0x4c))->id & 0xf000;
    n = func_ov000_0219a510(self, ~(1 << (k >> 12)), &self->pos, r, 0, list);
    if (n == 0) {
        return;
    }
    for (i = 0; i < n; i++) {
        Ov014Actor *q;
        if (list[i] != NULL && (q = func_ov000_021985c0(list[i])) != NULL) {
            u8 *s = FLD(u8 *, q, 0x4c);
            if (s == NULL || k != (u16)(FLD(u16, s, 0x1c) & 0xf000)) {
                func_ov003_021f0c60(self, 0);
                FLD(u32, self, 0xd0) |= 0x1000;
                func_ov000_02198360(self->unk_40, 0x15, 0);
                return;
            }
        }
    }
}

void func_ov014_02205e7c(Ov014Actor *self) {
    Ov014Sub38 *m;
    func_ov000_02194758(self);
    FLD(s32, self, 0xd0) = 0;
    FLD(s32, self, 0xe0) = 0;
    FLD(u8, self, 0xe4) = 0;
    {
        Ov014Sub48 *s48 = self->unk_48;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        func_0203f364(s48);
    }
    self->unk_48->unk_30 = 0;
    {
        Ov014Sub44 *n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
    }
    m = self->unk_38;
    Ov014_VecCopyYZ(&FLD(Ov014Vec, self, 0xd4), &FLD(Ov014Vec, m, 0xa8));
    FLD(Ov014Vec, m, 0xa8) = data_ov014_022169d4;
    func_ov000_02198360(self->unk_40, 1, 0);
}

static inline void Ov014_SetScale(Ov014Actor *self) {
    Ov014Sub38 *m = self->unk_38;
    s32 s = FLD(s32, self, 0xe0);
    FLD(Ov014Vec, m, 0xa8).x = s;
    FLD(Ov014Vec, m, 0xa8).y = s;
    FLD(Ov014Vec, m, 0xa8).z = s;
}

void func_ov014_02205f2c(Ov014Actor *self) {
    if (!func_ov000_02199ba0(FLD(void *, self, 0x4c))) {
        FLD(u32, self, 0xd0) |= 0x1000;
        func_ov000_02198360(self->unk_40, 0x15, 0);
        return;
    }
    switch (self->unk_40->state) {
    case 0:
        if (FLD(s32, self, 0xe0) < FLD(s32, self, 0xd4) + 0x1000) {
            FLD(s32, self, 0xe0) += 0xcd;
        } else {
            FLD(void *, self, 0xe8) = FLD(void *, func_02065f88(0x648, &self->pos), 0x24);
            self->unk_40->state++;
        }
        Ov014_SetScale(self);
        break;
    case 1:
        if (FLD(s32, self, 0xe0) <= FLD(s32, self, 0xd4)) {
            FLD(s32, self, 0xe0) = FLD(s32, self, 0xd4);
            self->unk_40->state++;
        } else {
            FLD(s32, self, 0xe0) -= 0xcd;
        }
        Ov014_SetScale(self);
        break;
    case 2:
        if (!func_020657b0(data_0214a420, FLD(void *, self, 0xe8))) {
            func_ov000_02198360(self->unk_40, 0xb, 0);
        }
        break;
    }
}

}
}  // namespace m_02205c1c
