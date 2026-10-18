#include "ov014/ov014.h"

extern "C" {

extern Ov014Actor *func_ov000_02199ba0(void *p);
extern void func_0203f364(Ov014Sub48 *p);
extern void func_ov000_0218d918(Ov014Actor *self, Ov014Vec *v, s32 a);
extern void func_ov000_0218dbe0(Ov014Actor *self, s32 a);
extern u16 FX_Atan2(s32 x, s32 z);
extern Ov014Actor *func_02065f88(s32 id, Ov014Vec *pos);
extern void func_ov014_02208a9c(Ov014Actor *self);
extern void func_ov014_02208fe4(Ov014Actor *self);

#define OV014_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014_SQRT_PARAM (*(volatile u64 *)0x40002b8)

void func_ov014_022087a8(Ov014Actor *self) {
    Ov014Actor *o = func_ov000_02199ba0(FLD(void *, self, 0x4c));
    if (o != NULL) {
        {
            Ov014Sub48 *m = o->unk_48;
            if (m != NULL && m->unk_9a_3) {
                m->unk_9a_3 = 0;
                func_0203f364(m);
            }
        }
        if (o->kind == 0x1000) {
            func_ov014_02208a9c(self);
            return;
        }
        switch (self->unk_40->state) {
        case 0: {
            s32 r;
            s32 dx;
            s32 dz;
            u16 a;
            {
                Ov014Sub44 *n = self->unk_44;
                n->unk_22_0 = 1;
                n->unk_22_1 = 1;
            }
            {
                s64 sq;
                dx = self->pos.x - self->unk_84.x;
                dz = self->pos.z - self->unk_84.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                OV014_SQRTCNT = 1;
                OV014_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV014_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014_SQRT_RESULT + 1) >> 1;
            a = FX_Atan2(r, self->unk_84.y - self->pos.y);
            FLD(s32, self, 0x9c) = Ov014_FxMul(OV014_SIN(a), 0x666);
            FLD(s32, self, 0xa0) = Ov014_FxMul(OV014_COS(a), 0x666);
            self->rot[0] = FX_Atan2(self->pos.y - self->unk_84.y, r);
            func_ov000_0218d918(self, &self->unk_84, 0x1000);
            FLD(u16, self, 0x98) = self->rot[1];
            {
                Ov014Sub48 *m = self->unk_48;
                m->unk_50 = 0;
                m->unk_54 = 0;
                FLD(u32, m, 0x58) = 0;
            }
            FLD(u8, self, 0xd4) = 0;
            self->unk_40->state++;
            break;
        }
        case 1:
            func_ov000_0218dbe0(self, 0);
            func_ov014_02208fe4(self);
            if ((self->unk_48->unk_50 & 0x20000000) || ++FLD(u8, self, 0xd4) >= 200) {
                FLD(u32, self, 0xd0) |= 0x1000;
                func_ov000_02198360(self->unk_40, 0x15, 0);
            }
            if (self->unk_48->unk_50 & 0x20000000) {
                Ov014Vec v;
                Ov014Actor *e;
                v = self->pos;
                v.y = 0x47800;
                e = func_02065f88(0x67, &v);
                e->v0c(0x2000);
                e->v34(0, (u16)(self->rot[1] + 0x7fff), 0);
            }
            break;
        }
    } else {
        FLD(u32, self, 0xd0) |= 0x1000;
        func_ov000_02198360(self->unk_40, 0x15, 0);
    }
}

}
