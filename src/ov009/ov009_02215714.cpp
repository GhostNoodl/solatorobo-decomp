#include "ov009/ov009.h"

extern "C" {

extern Ov009Vec *func_ov000_0218d2e0(void *self);
extern void VEC_Normalize(Ov009Vec *a, Ov009Vec *b);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);
extern void func_ov000_0218d918(Ov009Actor *self, Ov009Vec *v, s32 a);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 a);
extern void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
extern u16 FX_Atan2(s32 x, s32 z);
extern void func_0203f324(Ov009Sub48 *p);
extern void func_ov009_02215a6c(Ov009Actor *self);

#define OV009_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV009_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV009_SQRT_PARAM (*(volatile u64 *)0x40002b8)

void func_ov009_02215714(Ov009Actor *self) {
    Ov009Vec d;
    switch (self->unk_40->state) {
    case 0: {
        Ov009Vec *p;
        {
            Ov009Sub44 *n = self->unk_44;
            n->unk_22_0 = 1;
            n->unk_22_1 = 1;
        }
        {
            Ov009Sub48 *m = self->unk_48;
            m->unk_9a_0 = 1;
            m->unk_9a_3 = 1;
            func_0203f324(m);
        }
        self->unk_48->unk_30 = 0x40000000;
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
                OV009_SQRTCNT = 1;
                OV009_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV009_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV009_SQRT_RESULT + 1) >> 1;
            d.x = Ov009_FxMul(r, OV009_SIN(self->rot[1]));
            d.z = Ov009_FxMul(r, OV009_COS(self->rot[1]));
            VEC_Normalize(&d, &d);
            self->unk_9c = Ov009_FxMul(d.x, 0x666);
            FLD(s32, self, 0xa0) = Ov009_FxMul(d.y, 0x666);
            FLD(s32, self, 0xa4) = Ov009_FxMul(d.z, 0x666);
            FX_Atan2(r, self->unk_84.y - self->pos.y);
            self->rot[0] = FX_Atan2(self->pos.y - self->unk_84.y, r);
            FLD(u32, self, 0xd0) |= 0x200000;
            self->unk_48->unk_30 = 0x20000000;
        } else {
            self->unk_9c = 0x4cd;
            self->unk_98 = self->rot[1];
        }
        {
            Ov009Sub48 *m = self->unk_48;
            m->unk_50 = 0;
            m->unk_54 = 0;
            FLD(u32, m, 0x58) = 0;
        }
        FLD(u8, self, 0xd4) = 0;
        self->unk_40->state++;
        break;
    }
    case 1:
        if (FLD(u32, self, 0xd0) & 0x200000) {
            func_ov000_0218d918(self, &self->unk_84, 0x1000);
            VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
        } else {
            func_ov000_0218dbe0(self, 0);
        }
        func_ov009_02215a6c(self);
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if ((self->unk_48->unk_50 & 0x60000000) || ++FLD(u8, self, 0xd4) >= 150) {
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
        break;
    }
}

}
