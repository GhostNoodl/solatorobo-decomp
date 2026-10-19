#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

#define REG_SQRTCNT (*(volatile u16 *)0x40002b0)
#define REG_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define REG_SQRT_PARAM (*(volatile u64 *)0x40002b8)

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 2;
    u32 rest : 28;
} Bits021abc88;

typedef struct {
    u16 b0 : 8;
    u16 b8 : 1;
    u16 rest : 7;
} G18_021abc88;

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 rest : 14;
} Bits16_021abc88;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Bits8_021abc88;

extern "C" {
extern u8 data_ov000_021cc62a[];
extern u8 data_ov000_021cc6c0[];
extern u8 data_ov000_021cc5e3[];
extern u8 *data_0214a424;
extern u8 *data_ov000_021ccd54;
extern void *data_02097e4c;
void func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
void func_02062764(s32 a, s32 b);
void func_02049f44(void *a, s32 b, void *c, s32 d);
u16 func_01ffc128(u16 target, u16 cur, s32 rate, s32 a, s32 b);
void func_ov000_02198360(void *p, s32 a, s32 b);
void func_ov000_0218d918(void *self, void *v, s32 a);
void func_ov000_0218ddd4(void *self, const VecFx32 *target, s32 turn);
BOOL func_ov000_02191120(void *a);
void func_ov000_02198d28(void *body, VecFx32 *pos, u32 angle);
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *out);
void NNS_G3dRenderObjRemoveAnmObj(void *obj, void *anm);

void func_ov000_021abc88(u8 *self) {
    if (LFLD(u8, self, 0xb2f) == 0) {
        LFLD(u8, self, 0xb2f)++;
    }
    LFLD(Bits16_021abc88, LFLD(u8 *, self, 0x44), 0x22).b1 = 0;
    switch (LFLD(u16, LFLD(u8 *, self, 0x40), 0)) {
    case 0: {
        s32 dx;
        s32 dz;
        LFLD(Bits021abc88, self, 0xb24).b2 = 1;
        func_ov000_02190cb0(self + 0xac, data_ov000_021cc62a, 0x800, 0);
        dx = LFLD(s32, self, 0x75c) - LFLD(s32, self, 0x70);
        dz = LFLD(s32, self, 0x764) - LFLD(s32, self, 0x78);
        LFLD(s16, self, 0x178) = -1;
        {
            s64 sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            REG_SQRTCNT = 1;
            REG_SQRT_PARAM = (u64)(sq << 2);
        }
        while (REG_SQRTCNT & 0x8000) {
        }
        LFLD(s32, self, 0x9c) = (s32)(REG_SQRT_RESULT + 1) >> 5;
        LFLD(s32, self, 0xa0) = 0x53f;
        LFLD(s32, self, 0xa8) = 0x52;
        LFLD(u16, self, 0x90) = 0xffff;
        LFLD(s32, self, 0xa4) = 0;
        func_02049f44(data_02097e4c, 7, self + 0x70, 0);
        LFLD(u16, LFLD(u8 *, self, 0x40), 0)++;
        LFLD(u16, LFLD(u8 *, self, 0x40), 2) = 0;
        LFLD(G18_021abc88, data_0214a424, 0x18).b8 = 0;
        func_02062764(3, 1);
        LFLD(u8, data_ov000_021ccd54, 0xac) = 1;
        break;
    }
    case 1: {
        s32 d;
        u16 *s;
        func_ov000_0218d918(self, self + 0x75c, 0x59a);
        func_ov000_0218ddd4(self, (VecFx32 *)(self + 0x75c), 0);
        d = LFLD(s32, self, 0x74) - LFLD(s32, self, 0x760);
        if (d < 0x1800) {
            LFLD(s32, self, 0x74) += (LFLD(s32, self, 0x760) + 0x1800 - LFLD(s32, self, 0x74)) >> 2;
        } else if (d > 0x1ccd) {
            LFLD(s32, self, 0x74) += (LFLD(s32, self, 0x760) + 0x1ccd - LFLD(s32, self, 0x74)) >> 2;
        }
        s = LFLD(u16 *, self, 0x40);
        s[1]++;
        if (s[1] < 0x10) {
            return;
        }
        LFLD(u16, self, 0x7e) = func_01ffc128(LFLD(u16, self, 0x76e), LFLD(u16, self, 0x7e), 0x800, 1, 0x8000);
        LFLD(s32, self, 0x9c) = 0;
        LFLD(s32, self, 0xa0) = 0;
        LFLD(s32, self, 0xa4) = 0;
        LFLD(s32, self, 0xa8) = 0;
        func_ov000_02190cb0(self + 0xac, data_ov000_021cc6c0, 0x400, 0);
        LFLD(u16, LFLD(u8 *, self, 0x40), 0)++;
        break;
    }
    case 2:
        if (func_ov000_02191120(self + 0xac)) {
            u8 *p;
            LFLD(VecFx32, self, 0x70) = LFLD(VecFx32, self, 0x75c);
            LFLD(u16, self, 0x7c) = LFLD(u16, self, 0x76c);
            LFLD(u16, self, 0x7e) = LFLD(u16, self, 0x76e);
            LFLD(u16, self, 0x80) = LFLD(u16, self, 0x770);
            func_ov000_02198d28(self + 0x2cc, (VecFx32 *)(self + 0x70), LFLD(u16, self, 0x7e));
            func_ov000_02198d28(self + 0x6c0, (VecFx32 *)(self + 0x75c), LFLD(u16, self, 0x76e));
            LFLD(Bits021abc88, self, 0xb24).b2 = 0;
            LFLD(Bits021abc88, self, 0xb24).b1 = 1;
            LFLD(u16, self, 0xb36) = 0;
            func_ov000_02190cb0(self + 0x368, data_ov000_021cc5e3, 0x155, 0);
            p = LFLD(u8 *, self, 0x384);
            if (p != NULL) {
                NNS_G3dRenderObjRemoveAnmObj(self + 0x38c, LFLD(void *, p, 0));
                LFLD(u8, p, 0x108) = 0;
                LFLD(u8, p, 0x110) = 0xff;
                LFLD(Bits8_021abc88, p, 0x111).b0 = 0;
                LFLD(Bits8_021abc88, p, 0x111).b1 = 0;
            }
            func_02049f44(data_02097e4c, 0xe, self + 0x70, 0);
            func_ov000_02198360(LFLD(void *, self, 0x40), 1, 0);
        } else {
            VecFx32 d;
            s32 ty;
            LFLD(u16, self, 0x7e) = func_01ffc128(LFLD(u16, self, 0x76e), LFLD(u16, self, 0x7e), 0x59a, 1, 0x8000);
            ty = LFLD(s32, self, 0x760) + 0x119a;
            {
                s32 tx = LFLD(s32, self, 0x75c);
                s32 tz = LFLD(s32, self, 0x764);
                d.x = tx - LFLD(s32, self, 0x70);
                d.y = ty - LFLD(s32, self, 0x74);
                d.z = tz - LFLD(s32, self, 0x78);
            }
            VEC_MultAdd(0x400, &d, (VecFx32 *)(self + 0x70), (VecFx32 *)(self + 0x70));
        }
        break;
    }
}
}
