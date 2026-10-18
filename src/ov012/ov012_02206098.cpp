#include "ov012/ov012.h"

extern "C" {

extern void func_ov012_022065d8(Ov012Actor *self);

void func_ov012_02206098(Ov012Actor *self) {
    Ov012Vec d;
    switch (self->unk_40->state) {
    case 0: {
        Ov012Vec *p;
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
                OV012_SQRTCNT = 1;
                OV012_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV012_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV012_SQRT_RESULT + 1) >> 1;
            d.x = Ov012_FxMul(r, OV012_SIN(self->rot[1]));
            d.z = Ov012_FxMul(r, OV012_COS(self->rot[1]));
            VEC_Normalize(&d, &d);
            self->unk_9c = Ov012_FxMul(d.x, 0x4cd);
            FLD(s32, self, 0xa0) = Ov012_FxMul(d.y, 0x4cd);
            FLD(s32, self, 0xa4) = Ov012_FxMul(d.z, 0x4cd);
            FX_Atan2(r, self->unk_84.y - self->pos.y);
            self->rot[0] = FX_Atan2(self->pos.y - self->unk_84.y, r);
            if (!(FLD(u32, self, 0xd0) & 0x100000)) {
                func_ov000_02190758((u8 *)self + 0x210, self->rot, 0);
            }
            FLD(u32, self, 0xd0) |= 0x400000;
        } else {
            self->unk_9c = 0x4cd;
            self->unk_98 = self->rot[1];
        }
        {
            Ov012Sub48 *m = self->unk_48;
            m->unk_50 = 0;
            m->unk_54 = 0;
            FLD(u32, m, 0x58) = 0;
        }
        self->unk_40->state++;
        break;
    }
    case 1:
        if (FLD(u32, self, 0xd0) & 0x400000) {
            func_ov000_0218d918(self, &self->unk_84, 0x1000);
            VEC_Add(&self->pos, (Ov012Vec *)&self->unk_9c, &self->pos);
        } else {
            func_ov000_0218dbe0(self, 0);
        }
        func_ov012_022065d8(self);
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (self->unk_48->unk_50 & 0x60000000) {
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
        break;
    }
}

}
