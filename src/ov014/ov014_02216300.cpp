#include "ov014/ov014.h"

extern "C" {

extern void func_ov000_02195d88(void *self);
extern Ov014Actor *func_ov000_02199ba0(void *p);
extern Ov014Actor *func_ov000_0219bf90(void);
extern s32 func_ov000_0219a510(Ov014Actor *self, u16 mask, Ov014Vec *pos, s32 r, s32 a, Ov014Actor **list);
extern Ov014Actor *func_ov000_021985c0(Ov014Actor *p);

extern void func_ov000_021911c8(void *a, s32 b);
extern Ov014Vec *func_ov000_0218d2e0(void *self);
extern void VEC_Normalize(Ov014Vec *a, Ov014Vec *b);
extern void VEC_Add(const Ov014Vec *a, const Ov014Vec *b, Ov014Vec *out);
extern void func_ov003_021f0c60(Ov014Actor *self, s32 a);
extern BOOL func_ov014_02216324(Ov014Actor *self);

#define OV014Z_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014Z_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014Z_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline s32 Ov014z_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov014_02215ffc(Ov014Actor *self) {
    func_ov000_02199ba0(FLD(void *, self, 0x4c));
    switch (self->unk_40->state) {
    case 0: {
        Ov014Vec *p;
        func_ov000_021911c8(self->unk_38, 0x1000);
        {
            u8 *m = FLD(u8 *, self, 0x4c);
            FLD(s32, m, 0x50) = 0x1000;
            FLD(s32, m, 0x54) = 0x29;
            FLD(s32, m, 0x58) = 0;
        }
        FLD(s32, self->unk_48, 0x30) = 0;
        p = func_ov000_0218d2e0(self);
        if (p != NULL) {
            Ov014Vec d;
            s32 r;
            s32 dx;
            s32 dz;
            d = *p;
            d.y = d.y - self->pos.y;
            {
                s64 sq;
                dx = self->pos.x - d.x;
                dz = self->pos.z - d.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                OV014Z_SQRTCNT = 1;
                OV014Z_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV014Z_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014Z_SQRT_RESULT + 1) >> 1;
            d.x = Ov014_FxMul(r, OV014_SIN(self->rot[1]));
            d.z = Ov014_FxMul(r, OV014_COS(self->rot[1]));
            VEC_Normalize(&d, &d);
            self->unk_9c = Ov014z_FxMul64(d.x, 0x39a);
            self->unk_a0 = Ov014z_FxMul64(d.y, 0x39a);
            self->unk_a4 = Ov014z_FxMul64(d.z, 0x39a);
        } else {
            self->unk_9c = OV014_SIN(self->rot[1]);
            self->unk_a4 = OV014_COS(self->rot[1]);
            self->unk_9c = Ov014z_FxMul64(self->unk_9c, 0x39a);
            self->unk_a0 = Ov014z_FxMul64(self->unk_a0, 0x39a);
            self->unk_a4 = Ov014z_FxMul64(self->unk_a4, 0x39a);
        }
        {
            Ov014Sub48 *m = self->unk_48;
            m->unk_50 = 0;
            m->unk_54 = 0;
            FLD(u32, m, 0x58) = 0;
        }
        FLD(s32, self, 0xec) = 0;
        self->unk_40->state++;
        break;
    }
    case 1:
        VEC_Add(&self->pos, (Ov014Vec *)&self->unk_9c, &self->pos);
        FLD(s32, self, 0xf4)++;
        if ((self->unk_48->unk_50 & 0xe0000000) || func_ov014_02216324(self) || FLD(s32, self, 0xf4) >= 0xf0) {
            func_ov003_021f0c60(self, 0);
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
        break;
    }
    FLD(s32, self->unk_3c, 0x14) = 0x2000;
}

void func_ov014_02216300(Ov014Actor *self) {
    func_ov000_02195d88(self);
}

void func_ov014_0221630c(Ov014Actor *self) {
    func_ov000_02198360(self->unk_40, 0x15, 0);
}

BOOL func_ov014_02216324(Ov014Actor *self) {
    Ov014Actor *list[0x20];
    BOOL r = FALSE;
    Ov014Actor *o;
    Ov014Actor *p;
    u16 k;
    s32 i;
    u16 mask;
    s32 rad;
    s32 n;
    o = func_ov000_02199ba0(FLD(void *, self, 0x4c));
    p = func_ov000_0219bf90();
    k = o->id & 0xf000;
    mask = ~(1 << (k >> 12));
    rad = self->unk_64;
    if (o->kind == 0x1000) {
        rad = rad + 0x4cd;
    } else if (p != NULL && FLD(u16, p, 0xb1e) == self->id) {
        rad >>= 1;
    }
    n = func_ov000_0219a510(self, mask, &self->pos, rad, 0, list);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            Ov014Actor *q;
            if (list[i] != NULL && (q = func_ov000_021985c0(list[i])) != NULL) {
                u8 *s = FLD(u8 *, q, 0x4c);
                if (s == NULL || k != (u16)(FLD(u16, s, 0x1c) & 0xf000)) {
                    r = TRUE;
                    break;
                }
            }
        }
    }
    return r;
}

void func_ov014_0221641c(Ov014Actor *self) {
    self->v74();
}

}
