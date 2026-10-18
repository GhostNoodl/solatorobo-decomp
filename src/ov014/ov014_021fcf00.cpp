#include "ov014/ov014.h"

extern "C" {

extern void *data_ov014_022164a0[];
extern Ov014Vec *func_ov000_0218d2e0(void *self);
extern Ov014Actor *func_ov000_02199ba0(void *p);
extern void VEC_Normalize(Ov014Vec *a, Ov014Vec *b);
extern void VEC_Add(const Ov014Vec *a, const Ov014Vec *b, Ov014Vec *out);
extern void func_ov000_0218d918(Ov014Actor *self, Ov014Vec *v, s32 a);
extern u16 FX_Atan2(s32 x, s32 z);
extern s32 func_ov000_0219a510(Ov014Actor *self, u16 mask, Ov014Vec *pos, s32 r, s32 a, Ov014Actor **list);
extern Ov014Actor *func_ov000_021985c0(Ov014Actor *p);
extern void func_ov003_021f0c60(Ov014Actor *self, s32 a);

#define OV014_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014_SQRT_PARAM (*(volatile u64 *)0x40002b8)

void func_ov014_021fcf00(Ov014Actor *self) {
    Ov014Vec d;
    Ov014Actor *list[0x20];
    switch (self->unk_40->state) {
    case 0: {
        Ov014Vec *p;
        s32 r;
        s32 dx;
        s32 dz;
        func_ov000_02190cb0(self->unk_38, data_ov014_022164a0[0], 0x1000, 0);
        func_ov000_021915a0(self->unk_38);
        self->unk_9c = 0;
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        p = func_ov000_0218d2e0(self);
        d = *p;
        FLD(Ov014Vec, self, 0xd0).x = d.x;
        FLD(Ov014Vec, self, 0xd0).y = d.y;
        FLD(Ov014Vec, self, 0xd0).z = d.z;
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
        d.x = Ov014_FxMul(r, OV014_SIN(self->rot[1])) - 0x2000;
        d.z = Ov014_FxMul(r, OV014_COS(self->rot[1]));
        VEC_Normalize(&d, &d);
        self->unk_9c = Ov014_FxMul(d.x, 0x400);
        FLD(s32, self, 0xa0) = Ov014_FxMul(d.y, 0x400);
        FLD(s32, self, 0xa4) = Ov014_FxMul(d.z, 0x400);
        FX_Atan2(r, FLD(s32, self, 0xd4) - self->pos.y);
        self->rot[0] = FX_Atan2(self->pos.y - FLD(s32, self, 0xd4), r);
        {
            Ov014Sub48 *m = self->unk_48;
            m->unk_50 = 0;
            m->unk_54 = 0;
            FLD(u32, m, 0x58) = 0;
        }
        FLD(u8, self, 0xfe) = 0;
        self->unk_40->state++;
        break;
    }
    case 1: {
        s32 rad;
        s32 n;
        u16 team;
        s32 i;
        d = FLD(Ov014Vec, self, 0xd0);
        d.x -= 0x2000;
        func_ov000_0218d918(self, &d, 0xcd);
        VEC_Add(&self->pos, (Ov014Vec *)&self->unk_9c, &self->pos);
        FLD(u8, self, 0xfe)++;
        rad = self->unk_64 + 0x4cd;
        if (rad < 0xccd) {
            rad = 0xccd;
        }
        self->unk_48->unk_44 = rad;
        team = func_ov000_02199ba0(FLD(void *, self, 0x4c))->id & 0xf000;
        n = func_ov000_0219a510(self, (u16)~(1 << (team >> 12)), &self->pos, rad, 0, list);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                Ov014Actor *a;
                if (list[i] != NULL && (a = func_ov000_021985c0(list[i])) != NULL) {
                    if (FLD(void *, a, 0x4c) == NULL || (u16)(FLD(u16, FLD(void *, a, 0x4c), 0x1c) & 0xf000) != team ||
                        ++FLD(u8, self, 0xfe) >= 200) {
                        func_ov003_021f0c60(self, 0);
                        func_ov000_02198360(self->unk_40, 0x15, 0);
                        break;
                    }
                }
            }
        }
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
        if (self->unk_48->unk_50 & 1) {
            func_ov000_02198360(self->unk_40, 0x15, 0);
        }
        break;
    }
    }
}

}
