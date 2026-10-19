#include "ov012/ov012.h"

extern "C" {
void func_ov012_02206374(Ov012Actor *self) {
    if (FLD(u16, func_ov000_02199ba0(FLD(void *, self, 0x4c)), 0xe) == 0x1000 && self->unk_40->state == 0 &&
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
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
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
        o = func_ov000_0218bf1c(data_ov000_021ccd64, &d, &self->pos, self->rot, 0xffff);
        if (o != NULL) {
            void *p;
            FLD(Ov012Flags8, o, 0x16).b0 = 1;
            FLD(u16, o, 0x18) = i;
            FLD(u16, o, 0x7e) = FLD(u16, self, 0x7e);
            o->unk_90 = self->unk_90;
            p = FLD(void *, o, 0x4c);
            if (p != NULL) {
                func_ov000_02199b88(p, func_ov000_02199ba0(FLD(void *, self, 0x4c)));
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
    k = FLD(u16, func_ov000_02199ba0(FLD(void *, self, 0x4c)), 0xc) & 0xf000;
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
void func_ov012_022066d8(Ov012Actor *self) {
    func_ov000_02194758(self);
    FLD(s32, self, 0xdc) = 0;
    FLD(u8, self, 0xe0) = 0;
    FLD(s32, self, 0xd0) = 0x1000;
    FLD(s32, self, 0xd4) = 0x1000;
    FLD(s32, self, 0xd8) = 0x1000;
    self->unk_48->unk_30 = 0;
    func_ov000_02198360(self->unk_40, 0xb, 0);
}
}

extern "C" {
extern u8 data_ov012_0220a810[];
extern void func_ov012_02206bb0(Ov012Actor *self);
extern void func_ov012_02206f18(Ov012Actor *self);
extern void func_ov000_0219aca8(Ov012Actor *a, Ov012Actor *b, u16 c, u8 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);

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

void func_ov012_02206718(Ov012Actor *self) {
    u8 *m = (u8 *)func_ov000_02199ba0(FLD(void *, self, 0x4c));
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
        func_ov000_0218d240(self);
        func_01ffc9fc(&v, (Ov012Vec *)data_ov012_0220a810, self->rot[1]);
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
        FLD(u8, self, 0xe0) = 0;
        self->unk_40->state++;
        return;
    }
    case 1:
        func_ov000_0218d918(self, &self->unk_84, 0x1000);
        self->unk_98 = self->rot[1];
        func_ov000_0218dbe0(self, 0);
        func_ov012_02206f18(self);
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (self->unk_48->unk_50 & 0x20000000) {
            Ov012V *e;
            FLD(u32, self, 0xdc) |= 0x200000;
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
        if (++FLD(u8, self, 0xe0) < 100) {
            return;
        }
        func_ov000_02198360(self->unk_40, 0x15, 0);
        return;
    case 10: {
        Ov012V *e;
        self->pos.y = 0;
        e = func_02065f88(0x66, &self->pos);
        FLD(s32, e, 0x3c) = 0x800;
        FLD(s32, self, 0xe4) = FLD(s32, e, 0x24);
        self->unk_40->state++;
        return;
    }
    case 11: {
        Ov012V *e = (Ov012V *)func_020657b0(data_0214a420, FLD(void *, self, 0xe4));
        u8 *p;
        if (e != NULL) {
            Ov012Rot16V r;
            FLD(s32, self, 0xd0) += 0x19a;
            FLD(s32, self, 0xd8) += 0x19a;
            e->v10((u8 *)self + 0xd0);
            r = FLD(Ov012Rot16V, e, 0x64);
            r.y += 0xb6;
            e->v30(&r);
        }
        if (FLD(s32, self, 0xd0) >= 0x4000 || e == NULL) {
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
        p = FLD(u8 *, self, 0x4c);
        func_ov000_0219aca8(self, self, FLD(u16, p, 8), FLD(u16, p, 0xa), 0, 0, Ov012_FxMul64(FLD(s32, self, 0xd0), 0x1666), 0x1000, 100, 0x1000);
        return;
    }
    }
}
}
