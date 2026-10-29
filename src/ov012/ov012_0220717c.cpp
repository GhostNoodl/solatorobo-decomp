#include "ov012/ov012.h"

extern "C" {

extern s32 FX_Div(s32 a, s32 b);
extern void MIi_CpuClear32(u32 data, void *dest, u32 size);
extern void func_ov003_021daae4(void *p, s32 a, Ov012Vec *v, void *b, void *c, void *d, s32 e);
extern BOOL func_ov000_0219aca8(Ov012Actor *a, Ov012Actor *b, u16 c, u8 d, Ov012Vec *e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern Ov012Vec data_ov012_0220a81c;
extern const Ov012Vec data_ov012_0220a840;

struct Ov012Rot {
    u16 x;
    u16 y;
    u16 z;
};

void func_ov012_0220717c(Ov012Actor *self) {
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
        FLD(u16, g, 0xb6) = 0x1f;
        FLD(u16, g, 0xb8) = 0x1f;
        FLD(u16, g, 0xba) = 0x12d;
        FLD(u16, g, 0xbc) = 0x12c;
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
        d.x = Ov012_FxMul(r, OV012_SIN(self->rot[1]));
        d.z = Ov012_FxMul(r, OV012_COS(self->rot[1]));
        VEC_Normalize(&d, &d);
        self->unk_9c = Ov012_FxMul(d.x, 0x400);
        self->unk_a0 = Ov012_FxMul(d.y, 0x400);
        self->unk_a4 = Ov012_FxMul(d.z, 0x400);
        self->rot[0] = FX_Atan2(self->pos.y - self->unk_84.y, r);
        e = func_02065f88(0x4b0, &self->pos);
        e->v0c(0x800);
        e->v30(self->rot);
        FLD(s32, e, 0x7c) = FX_Div(0x1e000, 0x1f000);
        func_ov003_021da9ac(FLD(void *, self, 0xd4), 0xfa, e);
        e = func_02065f88(0x25d, &self->pos);
        rr.x = self->rot[0] + 0x7fff;
        rr.y = self->rot[1];
        rr.z = self->rot[2];
        e->v30(&rr);
        e->v2c(0, 0, -0x800);
        e->v0c(0x2000);
        func_ov003_021da9ac(FLD(void *, self, 0xd4), 0xfa, e);
        {
            Ov012Sub48 *m = self->unk_48;
            m->unk_50 = 0;
            m->unk_54 = 0;
            FLD(u32, m, 0x58) = 0;
        }
        self->unk_40->state++;
        break;
    }
    case 1: {
        s32 r;
        u16 k;
        s32 n;
        s32 i;
        VEC_Add(&self->pos, &self->unk_9c, &self->pos);
        r = self->unk_64 + 0x4cd;
        if (r < 0xccd) {
            r = 0xccd;
        }
        self->unk_48->unk_44 = r;
        k = FLD(u16, func_ov000_02199ba0(FLD(void *, self, 0x4c)), 0xc) & 0xf000;
        n = func_ov000_0219a510(self, ~(1 << (k >> 12)), &self->pos, r, 0, list);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                Ov012Actor *q;
                if (list[i] != NULL && (q = (Ov012Actor *)func_ov000_021985c0(list[i])) != NULL) {
                    u8 *s = FLD(u8 *, q, 0x4c);
                    if (s == NULL || k != (u16)(FLD(u16, s, 0x1c) & 0xf000)) {
                        func_ov003_021f0c60(self, 0);
                        func_ov000_02198360(self->unk_40, 0x15, 0);
                        break;
                    }
                }
            }
        }
        func_ov003_021daae4(FLD(void *, self, 0xd4), 0xfa, &self->pos, 0, 0, 0, 0);
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (self->unk_48->unk_50 & 0x60000000) {
            FLD(u32, self, 0xd0) |= 0x200000;
            func_ov003_021daa6c(FLD(void *, self, 0xd4), 0xfa);
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
        func_ov003_021da9ac(FLD(void *, self, 0xd4), 0xff, e);
        for (i = 0; i < 3; i++) {
            s32 a;
            s32 b;
            e = func_02065f88(0x68, &self->pos);
            FLD(s32, e, 0x3c) = 0x800;
            e->v24(0, 0x800, 0);
            e->v0c(0x1b33);
            a = func_02040498(0xffff);
            b = func_02040498(0xffff);
            e->v34((u16)a, (u16)b, 0);
            func_ov003_021da9ac(FLD(void *, self, 0xd4), (u8)(0xfd - i), e);
        }
        self->unk_40->state++;
    }
    case 11: {
        Ov012V *e = func_02065f88(5, &self->pos);
        e->v24(0, 0x800, 0);
        e->v0c(0x4000);
        FLD(s32, e, 0x7c) = FX_Div(0x1e000, 0x1f000);
        func_ov003_021da9ac(FLD(void *, self, 0xd4), 0xfe, e);
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
        func_ov000_0219aca8(self, self, FLD(Ov012Param *, self, 0x4c)->unk_08, FLD(u16, FLD(Ov012Param *, self, 0x4c), 0xa), &c, 0, 0x4000, 0, 100, 0x1000);
        o = (Ov012V *)func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0xd4), 0xff));
        if (o != NULL) {
            v = FLD(Ov012Vec, o, 0x40);
            v.x += 0x266;
            v.z += 0x266;
            o->v10(&v);
            func_ov000_0219aca8(self, self, FLD(Ov012Param *, self, 0x4c)->unk_08, FLD(u16, FLD(Ov012Param *, self, 0x4c), 0xa), 0, 0, Ov012_FxMul(v.x, 0x1666), 0x1000, 100, 0x1000);
            if (v.x >= 0x7800) {
                func_ov000_02198360(self->unk_40, 0x15, 0);
            }
        } else {
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
        for (i = 0; i < 3; i++) {
            o = (Ov012V *)func_020657b0(data_0214a420, func_ov003_021daa3c(FLD(void *, self, 0xd4), (u8)(0xfd - i)));
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
