#include "ov012/ov012.h"


// A header's zero rotation and vector, plus copies made at startup, around this TU's offsets
// and scale. Two of the offsets are read by the functions of 0x02206374..0x02207a38 (four files,
// merged in round dtD, each in its own namespace).
extern const VecFx32 data_ov012_0220a810;
extern const VecFx32 data_ov012_0220a81c;
static const VecFx16 data_ov012_0220a808 = {0, 0, 0};
static const VecFx32 data_ov012_0220a828 = {FX32_ONE, FX32_ONE, FX32_ONE};
const VecFx32 data_ov012_0220a81c = {0, 0, 9 * FX32_ONE};
static const VecFx32 data_ov012_0220a834 = {0, 0, 0};
const VecFx32 data_ov012_0220a810 = {0, 0, 2 * FX32_ONE};
static const VecFx16 data_ov012_0220b088 = data_ov012_0220a808;
static const VecFx32 data_ov012_0220b090 = data_ov012_0220a834;

// ---- merged from ov012_02206374.cpp
namespace m_02206374 {
extern "C" {
void func_ov012_02206374(Ov012Actor *self) {
    if (Target_Get(self->unk_4c)->kind == 0x1000 && self->unk_40->state == 0 &&
        !(FLD(u32, self, 0xd0) & 0x100000)) {
        u8 b = 2;
        func_ov000_0219bd20(0x5c03, self->kind, 6, 1, 1, &b);
    }
    func_ov000_02195d88(self);
}
}

extern "C" {
void func_ov012_022063e8(Ov012Actor *self) {
    func_ov000_02198360(self->unk_40, 0x15, 0);
}
}

extern "C" {
void func_ov012_02206400(Ov012Actor *self) {
    Ov012V *e;
    if (FLD(u32, self, 0xd0) & 0x100000) {
        if (self->unk_1a != 0) {
            return;
        }
        self->unk_38->unk_c2_0 = 0;
        func_02049de8(data_02097e4c, 0x4f);
        e = func_02065f88(4, &self->pos);
        e->v0c(0xe66);
        func_020639d4(e, 0x56, 0);
        func_02065f88(0x6b, &self->pos);
        e = func_02065f88(0x57c, &self->pos);
        e->v0c(0x1b33);
        func_020639d4(e, 0x79, 0);
        func_ov000_0218996c(10, 10);
        func_ov000_0218bed8(data_ov000_021ccd64, 0, (Actor *)self);
        self->v08();
        self->unk_1a = 1;
    } else {
        func_ov000_0219763c(self);
    }
}
}

extern "C" {
void func_ov012_02206508(Ov012Actor *self) {
    u8 i;
    for (i = 1; i < 3; i++) {
        Ov012SpawnDesc d;
        Ov012Actor *o;
        Ov012Spawn_Init(&d, 0x4824);
        o = Group_SpawnActor(data_ov000_021ccd64, &d, &self->pos, self->rot, 0xffff);
        if (o != NULL) {
            void *p;
            o->unk_16.b0 = 1;
            o->unk_18 = i;
            o->rot[1] = self->rot[1];
            o->unk_90 = self->unk_90;
            p = o->unk_4c;
            if (p != NULL) {
                Target_Set(p, Target_Get(self->unk_4c));
            }
        }
    }
}
}

extern "C" {
void func_ov012_022065d8(Ov012Actor *self) {
    void *list[0x20];
    s32 r = self->unk_64 + 0x4cd;
    u16 k;
    s32 n;
    s32 i;
    if (r < 0xccd) {
        r = 0xccd;
    }
    self->unk_48->unk_44 = r;
    k = Target_Get(self->unk_4c)->id & 0xf000;
    n = func_ov000_0219a510(self, ~(1 << (k >> 12)), &self->pos, r, 0, list);
    if (n == 0) {
        return;
    }
    for (i = 0; i < n; i++) {
        if (list[i] != NULL) {
            void *o = func_ov000_021985c0(list[i]);
            if (o != NULL) {
                void *p = FLD(void *, o, 0x4c);
                if (p == NULL || k != (u16)(FLD(u16, p, 0x1c) & 0xf000)) {
                    func_ov003_021f0c60(self, 0);
                    func_ov000_02198360(self->unk_40, 0x15, 0);
                    return;
                }
            }
        }
    }
}
}

extern "C" {
void Ov012ActExVt_0220b150_Start(Ov012ActExVt_0220b150 *self) {
    func_ov000_02194758(self);
    self->unk_dc = 0;
    self->unk_e0 = 0;
    self->unk_d0 = 0x1000;
    self->unk_d4 = 0x1000;
    self->unk_d8 = 0x1000;
    self->unk_48->unk_30 = 0;
    func_ov000_02198360(self->unk_40, 0xb, 0);
}
}

extern "C" {
extern void func_ov012_02206bb0(Ov012ActExVt_0220b150 *self);
extern void func_ov012_02206f18(Ov012ActExVt_0220b150 *self);
extern BOOL func_ov000_0219aca8(Ov012Obj *a, Ov012Obj *b, u16 c, u8 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);

#define OV012U_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV012U_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV012U_SQRT_PARAM (*(volatile u64 *)0x40002b8)

struct Ov012Rot16V {
    u16 x;
    u16 y;
    u16 z;
};

static inline s32 Ov012_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov012_02206718(Ov012ActExVt_0220b150 *self) {
    u8 *m = (u8 *)Target_Get(self->unk_4c);
    if (m == NULL) {
        return;
    }
    {
        Ov012Sub48 *q = FLD(Ov012Sub48 *, m, 0x48);
        if (q != NULL && q->unk_9a_3) {
            q->unk_9a_3 = 0;
            func_0203f364(q);
        }
    }
    if (FLD(u16, m, 0xe) == 0x1000) {
        func_ov012_02206bb0(self);
        return;
    }
    switch (self->unk_40->state) {
    case 0: {
        Ov012Vec v;
        s32 r;
        u16 a;
        Actor_GetTarget(self);
        func_01ffc9fc(&v, &data_ov012_0220a810, self->rot[1]);
        VEC_Add(&self->pos, &v, &self->unk_84);
        self->unk_84.y = 0;
        {
            s64 sq;
            s32 dx = self->pos.x - self->unk_84.x;
            s32 dz = self->pos.z - self->unk_84.z;
            sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            OV012U_SQRTCNT = 1;
            OV012U_SQRT_PARAM = (u64)(sq * 4);
        }
        while (OV012U_SQRTCNT & 0x8000) {
        }
        r = (s32)(OV012U_SQRT_RESULT + 1) >> 1;
        a = FX_Atan2(r, self->unk_84.y - self->pos.y);
        self->unk_9c = Ov012_FxMul64(FX_SinCosTable_[(a >> 4) * 2], 0x266);
        self->unk_a0 = Ov012_FxMul64(FX_SinCosTable_[(a >> 4) * 2 + 1], 0x266);
        self->rot[0] = FX_Atan2(self->pos.y - self->unk_84.y, r);
        {
            Ov012Sub48 *q = self->unk_48;
            q->unk_50 = 0;
            q->unk_54 = 0;
            FLD(s32, q, 0x58) = 0;
        }
        self->unk_e0 = 0;
        self->unk_40->state++;
        return;
    }
    case 1:
        Actor_TurnToPos(self, &self->unk_84, 0x1000);
        self->unk_98 = self->rot[1];
        Actor_Move((Actor *)self, 0);
        func_ov012_02206f18(self);
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (self->unk_48->unk_50 & 0x20000000) {
            Ov012V *e;
            self->unk_dc |= 0x200000;
            {
                Ov012Sub44 *q = self->unk_44;
                q->unk_22_0 = 0;
                q->unk_22_1 = 0;
            }
            {
                Ov012Sub48 *q = self->unk_48;
                q->unk_9a_1 = 0;
                q->unk_9a_4 = 0;
            }
            self->unk_38->unk_c2_0 = 0;
            func_ov000_0218996c(0x14, 0x1e);
            e = func_02065f88(0x65, &self->pos);
            e->v0c(0x1800);
            func_020639d4(e, 0x56, 0);
            func_020639d4(e, 0x32, 5);
            self->unk_40->state = 10;
        }
        if (++self->unk_e0 < 100) {
            return;
        }
        func_ov000_02198360(self->unk_40, 0x15, 0);
        return;
    case 10: {
        Ov012V *e;
        self->pos.y = 0;
        e = func_02065f88(0x66, &self->pos);
        FLD(s32, e, 0x3c) = 0x800;
        self->unk_e4 = FLD(s32, e, 0x24);
        self->unk_40->state++;
        return;
    }
    case 11: {
        Ov012V *e = (Ov012V *)func_020657b0(data_0214a420, ((void *)self->unk_e4));
        Ov012Target *p;
        if (e != NULL) {
            Ov012Rot16V r;
            self->unk_d0 += 0x19a;
            self->unk_d8 += 0x19a;
            e->v10((u8 *)self + 0xd0);
            r = FLD(Ov012Rot16V, e, 0x64);
            r.y += 0xb6;
            e->v30(&r);
        }
        if (self->unk_d0 >= 0x4000 || e == NULL) {
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
        p = self->unk_4c;
        func_ov000_0219aca8(self, self, p->unk_08, p->unk_0a, 0, 0, Ov012_FxMul64(self->unk_d0, 0x1666), 0x1000, 100, 0x1000);
        return;
    }
    }
}
}
}  // namespace m_02206374

// ---- merged from ov012_02206bb0.cpp
namespace m_02206bb0 {
extern "C" {

extern void func_ov012_02206f18(Ov012ActExVt_0220b150 *self);

void func_ov012_02206bb0(Ov012ActExVt_0220b150 *self) {
    Ov012Vec d;
    switch (self->unk_40->state) {
    case 0: {
        Ov012Vec *p;
        self->unk_9c = 0;
        self->unk_a0 = 0;
        self->unk_a4 = 0;
        self->unk_a8 = 0;
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
                OV012_SQRTCNT = 1;
                OV012_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV012_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV012_SQRT_RESULT + 1) >> 1;
            d.x = FX_Mul(r, OV012_SIN(self->rot[1]));
            d.z = FX_Mul(r, OV012_COS(self->rot[1]));
            VEC_Normalize(&d, &d);
            self->unk_9c = FX_Mul(d.x, 0x4cd);
            self->unk_a0 = FX_Mul(d.y, 0x4cd);
            self->unk_a4 = FX_Mul(d.z, 0x4cd);
            FX_Atan2(r, self->unk_84.y - self->pos.y);
            self->rot[0] = FX_Atan2(self->pos.y - self->unk_84.y, r);
            self->unk_dc |= 0x400000;
        } else {
            self->unk_9c = 0x4cd;
            self->unk_98 = self->rot[1];
        }
        {
            Ov012Sub48 *m = self->unk_48;
            m->unk_50 = 0;
            m->unk_54 = 0;
            m->unk_58 = 0;
        }
        self->unk_e0 = 0;
        self->unk_40->state++;
        break;
    }
    case 1:
        if (self->unk_dc & 0x400000) {
            Actor_TurnToPos(self, &self->unk_84, 0x1000);
            VEC_Add(&self->pos, (Ov012Vec *)&self->unk_9c, &self->pos);
        } else {
            Actor_Move((Actor *)self, 0);
        }
        func_ov012_02206f18(self);
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (self->unk_48->unk_50 & 1) {
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
        if (++self->unk_e0 >= 100) {
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
        break;
    }
}

}
}  // namespace m_02206bb0

// ---- merged from ov012_02206e9c.cpp
namespace m_02206e9c {
extern "C" {
void func_ov012_02206e9c(Ov012ActExVt_0220b150 *self) {
    func_ov000_02198360(self->unk_40, 0x15, 0);
}
}

extern "C" {
void func_ov012_02206eb4(Ov012ActExVt_0220b150 *self) {
    if (self->unk_dc & 0x200000) {
        if (func_020657b0(data_0214a420, ((void *)self->unk_e4)) != NULL) {
            return;
        }
        func_ov000_0218bed8(data_ov000_021ccd64, 0, (Actor *)self);
        self->v08();
    } else {
        func_ov000_0219763c(self);
    }
}
}

extern "C" {
void func_ov012_02206f18(Ov012ActExVt_0220b150 *self) {
    void *list[0x20];
    s32 r = self->unk_64 + 0x4cd;
    u16 k;
    s32 n;
    s32 i;
    if (r < 0xccd) {
        r = 0xccd;
    }
    self->unk_48->unk_44 = r;
    k = Target_Get(self->unk_4c)->id & 0xf000;
    n = func_ov000_0219a510(self, ~(1 << (k >> 12)), &self->pos, r, 0, list);
    if (n == 0) {
        return;
    }
    for (i = 0; i < n; i++) {
        if (list[i] != NULL) {
            void *o = func_ov000_021985c0(list[i]);
            if (o != NULL) {
                void *p = FLD(void *, o, 0x4c);
                if (p == NULL || k != (u16)(FLD(u16, p, 0x1c) & 0xf000)) {
                    func_ov003_021f0c60(self, 0);
                    func_ov000_02198360(self->unk_40, 0x15, 0);
                    return;
                }
            }
        }
    }
}
}

extern "C" {
extern u8 data_ov012_0220b0b8[];
#pragma force_active on
Ov012ActEx_02207018 *Ov012ActEx_02207018_Ctor(Ov012ActEx_02207018 *self) {
    ActorEx_Ctor(self);
    FLD(void *, self, 0) = data_ov012_0220b0b8;
    self->unk_d0 = 0;
    self->unk_d4 = 0;
    return self;
}
#pragma force_active reset
}

extern "C" {
extern u8 data_ov012_0220b0b8[];
void *Ov012ActEx_02207018_Dtor(void *self) {
    FLD(void *, self, 0) = data_ov012_0220b0b8;
    Ov012_FreeFx(self, 0xd4);
    func_ov000_0219429c(self);
    return self;
}
}

extern "C" {
extern u8 data_ov012_0220b0b8[];
void *Ov012ActEx_02207018_DtorDelete(void *self) {
    FLD(void *, self, 0) = data_ov012_0220b0b8;
    Ov012_FreeFx(self, 0xd4);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}
}

extern "C" {
void Ov012ActEx_02207018_Start(Ov012ActEx_02207018 *self) {
    func_ov000_02194758(self);
    FLD(s32 *, self, 0xd4) = Ov012_NewFx();
    func_ov000_02198360(self->unk_40, 0xb, 0);
}
}

extern "C" {
void Ov012ActEx_02207018_Update(Ov012ActEx_02207018 *self) {
    func_ov000_021953b4(self);
    func_ov003_021dacfc(((void *)self->unk_d4));
}
}
}  // namespace m_02206e9c

// ---- merged from ov012_0220717c.cpp
namespace m_0220717c {
extern "C" {

extern void func_ov003_021daae4(void *p, s32 a, Ov012Vec *v, void *b, void *c, void *d, s32 e);
extern BOOL func_ov000_0219aca8(Ov012Obj *a, Ov012Obj *b, u16 c, u8 d, Ov012Vec *e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern const Ov012Vec data_ov012_0220a840;

struct Ov012Rot {
    u16 x;
    u16 y;
    u16 z;
};

void func_ov012_0220717c(Ov012ActEx_02207018 *self) {
    void *list[0x20];
    Ov012Vec off;
    Ov012Vec d;
    Ov012Vec v;
    switch (self->unk_40->state) {
    case 0: {
        Ov012Sub38 *g = self->unk_38;
        Ov012V *e;
        Ov012Rot rr;
        s32 r;
        g->unk_b6 = 0x1f;
        g->unk_b8 = 0x1f;
        g->unk_ba = 0x12d;
        g->unk_bc = 0x12c;
        func_01ffc9fc(&off, &data_ov012_0220a81c, self->rot[1]);
        VEC_Add(&self->pos, &off, &d);
        d.y = 0;
        if (VEC_Distance(&self->pos, &d) < VEC_Distance(&self->pos, &self->unk_84)) {
            d.x = self->unk_84.x;
            d.y = self->unk_84.y;
            d.z = self->unk_84.z;
        }
        d.y = d.y - self->pos.y;
        {
            s32 dx;
            s32 dz;
            s64 sq;
            dx = self->pos.x - d.x;
            dz = self->pos.z - d.z;
            sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            OV012_SQRTCNT = 1;
            OV012_SQRT_PARAM = (u64)(sq * 4);
        }
        while (OV012_SQRTCNT & 0x8000) {
        }
        r = (s32)(OV012_SQRT_RESULT + 1) >> 1;
        d.x = FX_Mul(r, OV012_SIN(self->rot[1]));
        d.z = FX_Mul(r, OV012_COS(self->rot[1]));
        VEC_Normalize(&d, &d);
        self->unk_9c = FX_Mul(d.x, 0x400);
        self->unk_a0 = FX_Mul(d.y, 0x400);
        self->unk_a4 = FX_Mul(d.z, 0x400);
        self->rot[0] = FX_Atan2(self->pos.y - self->unk_84.y, r);
        e = func_02065f88(0x4b0, &self->pos);
        e->v0c(0x800);
        e->v30(self->rot);
        FLD(s32, e, 0x7c) = FX_Div(0x1e000, 0x1f000);
        func_ov003_021da9ac(((void *)self->unk_d4), 0xfa, e);
        e = func_02065f88(0x25d, &self->pos);
        rr.x = self->rot[0] + 0x7fff;
        rr.y = self->rot[1];
        rr.z = self->rot[2];
        e->v30(&rr);
        e->v2c(0, 0, -0x800);
        e->v0c(0x2000);
        func_ov003_021da9ac(((void *)self->unk_d4), 0xfa, e);
        {
            Ov012Sub48 *m = self->unk_48;
            m->unk_50 = 0;
            m->unk_54 = 0;
            m->unk_58 = 0;
        }
        self->unk_40->state++;
        break;
    }
    case 1: {
        s32 r;
        u16 k;
        s32 n;
        s32 i;
        VEC_Add(&self->pos, (VecFx32 *)(&self->unk_9c), &self->pos);
        r = self->unk_64 + 0x4cd;
        if (r < 0xccd) {
            r = 0xccd;
        }
        self->unk_48->unk_44 = r;
        k = Target_Get(self->unk_4c)->id & 0xf000;
        n = func_ov000_0219a510(self, ~(1 << (k >> 12)), &self->pos, r, 0, list);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                Ov012Actor *q;
                if (list[i] != NULL && (q = (Ov012Actor *)func_ov000_021985c0(list[i])) != NULL) {
                    Ov012Target *s = q->unk_4c;
                    if (s == NULL || k != (u16)(s->target & 0xf000)) {
                        func_ov003_021f0c60(self, 0);
                        func_ov000_02198360(self->unk_40, 0x15, 0);
                        break;
                    }
                }
            }
        }
        func_ov003_021daae4(((void *)self->unk_d4), 0xfa, &self->pos, 0, 0, 0, 0);
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (self->unk_48->unk_50 & 0x60000000) {
            self->unk_d0 |= 0x200000;
            func_ov003_021daa6c(((void *)self->unk_d4), 0xfa);
            self->unk_40->state = 10;
        }
        break;
    }
    case 10: {
        Ov012V *e;
        u8 i;
        self->pos.y = 0;
        self->unk_38->unk_c2_0 = 0;
        func_02049f44(data_02097e4c, 0x1b, &self->pos, 0);
        func_ov000_0218996c(0x1e, 0x28);
        if (self->unk_18 == 0) {
            e = func_02065f88(0x1f7, &self->pos);
            e->v0c(0xb33);
            MIi_CpuClear32(-1, (u8 *)e + 0x84, 0x40);
        }
        e = func_02065f88(0x66, &self->pos);
        FLD(s32, e, 0x3c) = 0x800;
        func_020639d4(e, 0x3e, 0);
        func_ov003_021da9ac(((void *)self->unk_d4), 0xff, e);
        for (i = 0; i < 3; i++) {
            s32 a;
            s32 b;
            e = func_02065f88(0x68, &self->pos);
            FLD(s32, e, 0x3c) = 0x800;
            e->v24(0, 0x800, 0);
            e->v0c(0x1b33);
            a = Rand_UpTo(0xffff);
            b = Rand_UpTo(0xffff);
            e->v34((u16)a, (u16)b, 0);
            func_ov003_021da9ac(((void *)self->unk_d4), (u8)(0xfd - i), e);
        }
        self->unk_40->state++;
    }
    case 11: {
        Ov012V *e = func_02065f88(5, &self->pos);
        e->v24(0, 0x800, 0);
        e->v0c(0x4000);
        FLD(s32, e, 0x7c) = FX_Div(0x1e000, 0x1f000);
        func_ov003_021da9ac(((void *)self->unk_d4), 0xfe, e);
        self->unk_40->state++;
        break;
    }
    case 12: {
        Ov012Sub40 *s = self->unk_40;
        s->timer++;
        if (s->timer > 11) {
            self->unk_40->timer = 0;
            self->unk_40->state = 11;
        }
        break;
    }
    }
    if (self->unk_40->state >= 11) {
        Ov012Vec c = data_ov012_0220a840;
        Ov012V *o;
        u8 i;
        Ov012Rot rr;
        func_ov000_0219aca8(self, self, self->unk_4c->unk_08, self->unk_4c->unk_0a, &c, 0, 0x4000, 0, 100, 0x1000);
        o = (Ov012V *)func_020657b0(data_0214a420, func_ov003_021daa3c(((void *)self->unk_d4), 0xff));
        if (o != NULL) {
            v = FLD(Ov012Vec, o, 0x40);
            v.x += 0x266;
            v.z += 0x266;
            o->v10(&v);
            func_ov000_0219aca8(self, self, self->unk_4c->unk_08, self->unk_4c->unk_0a, 0, 0, FX_Mul(v.x, 0x1666), 0x1000, 100, 0x1000);
            if (v.x >= 0x7800) {
                func_ov000_02198360(self->unk_40, 0x15, 0);
            }
        } else {
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
        for (i = 0; i < 3; i++) {
            o = (Ov012V *)func_020657b0(data_0214a420, func_ov003_021daa3c(((void *)self->unk_d4), (u8)(0xfd - i)));
            if (o != NULL) {
                v = FLD(Ov012Vec, o, 0x40);
                v.x += 0xcd;
                o->v0c(v.x);
                rr.x = FLD(u16, o, 0x64);
                rr.y = FLD(u16, o, 0x66);
                rr.z = FLD(u16, o, 0x68);
                rr.x += 0x38e;
                rr.y += 0x38e;
                o->v30(&rr);
            }
        }
    }
}

}
}  // namespace m_0220717c
