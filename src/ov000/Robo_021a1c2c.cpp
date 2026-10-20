#include "ov000/LoCommon.h"
#include "nitro/fx.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 2;
    u32 b4 : 1;
    u32 b5 : 2;
    u32 b7 : 5;
    u32 b12 : 2;
    u32 b14 : 2;
    u32 b16 : 1;
    u32 b17 : 1;
    u32 b18 : 1;
    u32 b19 : 1;
    u32 b20 : 2;
    u32 b22 : 2;
    u32 rest : 8;
} B24_021a1c2c;

typedef struct {
    u16 b0 : 3;
    u16 b3 : 1;
    u16 rest : 12;
} B22_021a1c2c;

typedef struct {
    u16 b0 : 8;
    u16 b8 : 1;
    u16 b9 : 1;
    u16 rest : 6;
} G18_021a1c2c;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Bits8_021a1c2c;

typedef struct {
    u16 st;
    u16 timer;
} State_021a1c2c;

#define B24(self) LFLD(B24_021a1c2c, self, 0xb24)
#define B22(self) LFLD(B22_021a1c2c, self, 0xb22)

extern "C" {
extern char data_ov000_021cc630[];
extern char *data_ov000_021ca060[];
extern char *data_ov000_021ca070[];
extern char data_ov000_021cc618[];
extern char data_ov000_021cc62a[];
extern char data_ov000_021cc636[];
extern char data_ov000_021cc5e3[];
extern void *data_02097e4c;
extern u8 *data_ov000_021ccd54;
extern void *data_02097dc8;
extern u8 *data_0214a424;
void func_ov000_021b1dd8(u8 *self, s32 target, s32 rate, s32 speed, s32 turn, u8 anim);
void func_ov000_0218dbe0(void *self, s32 a);
void func_ov000_021b1fac(void *self, BOOL a, s32 b);
void func_ov000_02198360(void *st, s32 state, s32 x);
s32 func_ov003_021ce5b8(u32 color);
void func_ov000_021915a0(void *a);
void func_02049f44(void *a, s32 b, void *c, s32 d);
VObj *func_02065f88(s32 id, void *pos);
void func_ov000_02190cb0(void *a, void *b, s32 c, s32 d);
BOOL func_ov000_021b468c(void *self);
u16 func_0204bfa8(void *cam);
s32 func_0203d434(void *rng, void *p);
s32 func_01ffbd6c(VecFx32 *a, VecFx32 *b, u32 mask, s32 c, s32 d, s32 e);
void func_02062764(s32 a, s32 b);
void NNS_G3dRenderObjRemoveAnmObj(void *obj, void *anm);
void func_ov000_02198d28(void *body, VecFx32 *pos, u32 angle);
BOOL func_ov000_02191120(void *a);

static inline u16 CamYaw_021a1c2c(u8 *cam) {
    if (LFLD(u16, cam, 0x40) != 0) {
        return LFLD(u16, cam, 0x44);
    }
    return func_0204bfa8(cam);
}

void func_ov000_021a1c2c(u8 *self) {
    VecFx32 p;
    VecFx32 a;
    VecFx32 b;
    BOOL turned;
    char *name;
    s32 se;

    switch (LFLD(State_021a1c2c *, self, 0x40)->st) {
    case 0:
        (*(volatile u16 *)&LFLD(State_021a1c2c *, self, 0x40)->st)++;
        LFLD(u8, self, 0xb2b) = 0;
        B24(self).b16 = 0;
        B24(self).b18 = 0;
    case 1:
        if (LFLD(s32, self, 0xa8) == 0) {
            LFLD(s32, self, 0xa8) = 0x52;
        }
        if (!B24(self).b16 && !B24(self).b17 && !B24(self).b18) {
            s32 target = LFLD(s32, self, 0xb08);
            if (target > 0x252) {
                target = 0x252;
            }
            func_ov000_021b1dd8(self, target, 0x200, 0xf00, 0x466, LFLD(u8, self, 0xb2b) < 8);
        } else if (B24(self).b18) {
            func_ov000_0218dbe0(self, 0);
        } else {
            s32 f = 1;
            if (B24(self).b17 || LFLD(u8, self, 0xb2b) >= 8) {
                f = 0;
            }
            func_ov000_021b1fac(self, FALSE, f);
        }
        turned = FALSE;
        if (B24(self).b1 && (LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x400)) {
            LFLD(u16, self, 0x98) = FX_Atan2(LFLD(s32, self, 0xaf0) - LFLD(s32, self, 0x70), LFLD(s32, self, 0xaf8) - LFLD(s32, self, 0x78));
            LFLD(s32, self, 0x9c) = 0x66;
            LFLD(s32, self, 0xa4) = 0;
            if (!B24(self).b17 || (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x40000000)) {
                LFLD(s32, self, 0xa0) = 0x200;
            }
            LFLD(s32, self, 0xa8) = 0x52;
            B24(self).b17 = 1;
            turned = TRUE;
        }
        if (turned) {
            func_ov000_02198360(LFLD(void *, self, 0x40), 4, 1);
            return;
        }
        if (LFLD(s32, self, 0xa0) > 0) {
            if (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x80000000) {
                LFLD(s32, self, 0xa0) = -0xcd;
            }
            return;
        }
        if (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x20000000) {
            LFLD(State_021a1c2c *, self, 0x40)->timer = 6;
            B24(self).b19 = 0;
            name = data_ov000_021cc630;
            se = func_ov003_021ce5b8(LFLD(u32, LFLD(u8 *, self, 0x48), 0x50));
            if (B24(self).b1) {
                name = data_ov000_021ca060[B24(self).b5];
                if (B24(self).b5 != 0) {
                    B24(self).b22 = 0;
                    func_ov000_021915a0(LFLD(void *, self, 0x38));
                }
                func_02049f44(data_02097e4c, 8, self + 0x70, 0);
                if (B24(self).b12 == 1) {
                    VObj *o = func_02065f88(0x6d, self + 0x70);
                    o->vfunc_0c(0x99a);
                    o->vfunc_34(0xf000, 0, 0);
                } else if (!B22(self).b3 && (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0xf0f0f0) != 0xe0e000) {
                    func_02065f88(0x12f, self + 0x70)->vfunc_0c(0x666);
                }
            } else if (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x400) {
                se = 0x2bc;
                name = data_ov000_021cc618;
                func_02065f88(se, self + 0x70);
                func_02065f88(se + 1, self + 0x70);
                LFLD(State_021a1c2c *, self, 0x40)->timer = 0xc;
                se = -1;
            }
            func_ov000_02190cb0(LFLD(void *, self, 0x38), name, 0x1000, 0);
            if (se >= 0) {
                func_02049f44(data_02097e4c, se, self + 0x70, -5);
                if ((LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0xf0f0f0) == 0xe0e000) {
                    p = LFLD(VecFx32, self, 0x70);
                    p.y += 0xccd;
                    func_02065f88(0x2bc, &p);
                    func_02065f88(0x2bd, &p)->vfunc_0c(0x1800);
                }
            }
            LFLD(State_021a1c2c *, self, 0x40)->st++;
            LFLD(s32, self, 0xa0) = 0;
            LFLD(s32, self, 0xa8) = 0;
            LFLD(s32, self, 0xa4) = 0x800;
            return;
        }
        if (func_ov000_021b468c(self) && LFLD(u8, self, 0x15) == 1 && B24(self).b12 == 0 && !B24(self).b1 &&
            (LFLD(u16, self, 0xb68) & 3) && (LFLD(u16, self, 0xb68) & 0xf0)) {
            if (LFLD(u8, self, 0xb2b) <= 0x10) {
                LFLD(u8, self, 0xb2b)++;
            }
        } else {
            LFLD(u8, self, 0xb2b) = 0;
        }
        if (!B24(self).b1) {
            if (LFLD(u8, self, 0xb2b) >= 8 && LFLD(u8, self, 0xb2b) <= 0x10) {
                u16 yaw = CamYaw_021a1c2c(data_ov000_021ccd54 + 0xf4);
                u16 ang = yaw + func_0203d434(data_02097dc8, self + 0xb70);
                s32 h;
                s32 r;
                a = LFLD(VecFx32, self, 0x70);
                b = LFLD(VecFx32, self, 0x70);
                b.y += LFLD(s32, self, 0x68) + 0x10;
                r = func_01ffbd6c(&a, &b, 0xc0000000, 0, 0, -1);
                if (r == -0x1000) {
                    h = LFLD(s32, self, 0x68);
                } else {
                    h = r - 0x10;
                }
                a = LFLD(VecFx32, self, 0x70);
                a.y += h;
                b = LFLD(VecFx32, self, 0x70);
                b.y += h;
                b.x += (s32)(((s64)(LFLD(s32, self, 0x64) * 2) * FX_SinCosTable_[(ang >> 4) * 2] + 0x800) >> 12);
                b.z += (s32)(((s64)(LFLD(s32, self, 0x64) * 2) * FX_SinCosTable_[(ang >> 4) * 2 + 1] + 0x800) >> 12);
                if (func_01ffbd6c(&a, &b, 0x40000000, 0, 0, -1) == -0x1000) {
                    LFLD(u16, self, 0x98) = ang;
                    func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc62a, 0x800, 1);
                    if (LFLD(s32, self, 0xa0) < 0x148) {
                        LFLD(s32, self, 0xa0) = 0x148;
                    }
                } else {
                    func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc636, 0x200, 0);
                }
            } else {
                func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021cc636, 0x200, 0);
            }
        } else {
            func_ov000_02190cb0(LFLD(void *, self, 0x38), data_ov000_021ca070[B24(self).b5], 0x200, 0);
        }
        if (B22(self).b3 && LFLD(s32, self, 0xa8) > 0x14) {
            LFLD(s32, self, 0xa8) = 0x14;
        }
        {
            s32 lim;
            BOOL fall = FALSE;
            if (!(LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x20000000)) {
                lim = -0xf000;
                if (B22(self).b0 || B24(self).b12 || B24(self).b19) {
                    lim = -0x2d000;
                }
                if (LFLD(s32, self, 0x74) - LFLD(s32, self, 0xb00) < lim) {
                    fall = TRUE;
                }
            }
            if (!fall) {
                return;
            }
        }
        LFLD(u16, LFLD(u8 *, self, 0x50), 0xa) = 0xf0;
        func_02049f44(data_02097e4c, 0x34, self + 0x70, 0);
        if (B22(self).b0) {
            if (!B24(self).b1) {
                u8 *q;
                B24(self).b1 = 1;
                B24(self).b2 = 0;
                ((VObj *)self)->vfunc_18();
                LFLD(VecFx32, self, 0x75c) = LFLD(VecFx32, self, 0x70);
                LFLD(u16, self, 0x76c) = LFLD(u16, self, 0x7c);
                LFLD(u16, self, 0x76e) = LFLD(u16, self, 0x7e);
                LFLD(u16, self, 0x770) = LFLD(u16, self, 0x80);
                func_ov000_02190cb0(self + 0x368, data_ov000_021cc5e3, 0x1000, 1);
                q = LFLD(u8 *, self, 0x384);
                if (q != NULL) {
                    NNS_G3dRenderObjRemoveAnmObj(self + 0x38c, LFLD(void *, q, 0));
                    LFLD(u8, q, 0x108) = 0;
                    LFLD(u8, q, 0x110) = 0xff;
                    LFLD(Bits8_021a1c2c, q, 0x111).b0 = 0;
                    LFLD(Bits8_021a1c2c, q, 0x111).b1 = 0;
                }
                LFLD(s16, self, 0x178) = -1;
                LFLD(G18_021a1c2c, data_0214a424, 0x18).b8 = 0;
                LFLD(G18_021a1c2c, data_0214a424, 0x18).b9 = 0;
                func_02062764(3, 1);
                LFLD(u8, data_ov000_021ccd54, 0xac) = 1;
            }
            if (LFLD(u16, self, 0x9ac) < 0xb4) {
                LFLD(u16, self, 0x9ac) = 0xb4;
            }
        }
        {
            s32 y = LFLD(s32, self, 0xaf4);
            s32 z = LFLD(s32, self, 0xaf8);
            LFLD(s32, self, 0x70) = LFLD(s32, self, 0xaf0);
            LFLD(s32, self, 0x74) = y + 0x159a;
            LFLD(s32, self, 0x78) = z;
        }
        func_ov000_02198d28(LFLD(void *, self, 0x48), (VecFx32 *)(self + 0x70), LFLD(u16, self, 0x7e));
        LFLD(s32, self, 0x9c) = 0;
        LFLD(s32, self, 0xa0) = 0x333;
        LFLD(s32, self, 0xa4) = 0;
        LFLD(s32, self, 0xa8) = 0x29;
        LFLD(u32, self, 0xb24) |= 0x50000;
        return;
    case 2: {
        State_021a1c2c *s;
        { s32 f = 1; if (B24(self).b17) f = 0; func_ov000_021b1fac(self, TRUE, f); }
        turned = FALSE;
        if (B24(self).b1 && (LFLD(u32, LFLD(u8 *, self, 0x48), 0x54) & 0x400)) {
            LFLD(u16, self, 0x98) = FX_Atan2(LFLD(s32, self, 0xaf0) - LFLD(s32, self, 0x70), LFLD(s32, self, 0xaf8) - LFLD(s32, self, 0x78));
            LFLD(s32, self, 0x9c) = 0x66;
            LFLD(s32, self, 0xa4) = 0;
            if (!B24(self).b17 || (LFLD(u32, LFLD(u8 *, self, 0x48), 0x50) & 0x40000000)) {
                LFLD(s32, self, 0xa0) = 0x200;
            }
            LFLD(s32, self, 0xa8) = 0x52;
            B24(self).b17 = 1;
            turned = TRUE;
        }
        if (turned) {
            func_ov000_02198360(LFLD(void *, self, 0x40), 4, 1);
            return;
        }
        s = LFLD(State_021a1c2c *, self, 0x40);
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer != 0) {
            return;
        }
        if (!func_ov000_02191120(LFLD(void *, self, 0x38)) && LFLD(s64, LFLD(u8 *, self, 0x40), 4) == 0) {
            return;
        }
        func_ov000_02198360(LFLD(void *, self, 0x40), 1, 0);
        B24(self).b16 = 0;
        B24(self).b17 = 0;
        B24(self).b18 = 0;
        break;
    }
    }
}
}
