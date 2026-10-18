#include "ov014/ov014.h"

extern "C" {

extern Ov014Vec *func_ov000_0218d2e0(void *self);
extern void VEC_Normalize(Ov014Vec *a, Ov014Vec *b);
extern void VEC_Add(const Ov014Vec *a, const Ov014Vec *b, Ov014Vec *out);
extern void func_ov000_0218d918(Ov014Actor *self, Ov014Vec *v, s32 a);
extern void func_ov000_0218dbe0(Ov014Actor *self, s32 a);
extern u16 FX_Atan2(s32 x, s32 z);
extern void func_ov014_02206b5c(Ov014Actor *self);

#define OV014_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014_SQRT_PARAM (*(volatile u64 *)0x40002b8)

void func_ov014_02206734(Ov014Actor *self) {
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
        func_ov014_02206b5c(self);
        if ((self->unk_48->unk_50 & 0x20000000) || ++FLD(u8, self, 0xe4) >= 100) {
            FLD(u32, self, 0xd0) |= 0x1000;
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
        break;
    }
}

}
