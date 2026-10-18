#include "ov010/ov010.h"

extern "C" {
extern void func_ov010_02206784(void *self);
extern void func_ov010_02206974(void *self);

void func_ov010_02206758(void *self) {
    switch (FLD(u8, self, 0x171)) {
    case 1:
        func_ov010_02206784(self);
        break;
    case 2:
        func_ov010_02206974(self);
        break;
    }
}

extern void *data_02097e4c;
extern u8 data_ov010_0220f024[];
extern void func_ov010_02204030(Ov010Vec *out, void *c, const Ov010Vec *target, s32 n, u16 ang);
extern void VEC_Normalize(Ov010Vec *a, Ov010Vec *b);
extern u16 FX_Atan2(s32 y, s32 x);
extern Ov010V *func_ov010_0220eaf0(void *self, Ov010Vec *pos, Ov010Vec *p);
extern void func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern void func_ov000_02190cb0(void *a, const char *b, s32 c, s32 d);
extern void func_ov010_02207828(void *self);
extern void func_ov000_0218d918(void *self, void *t, s32 a);
extern void func_ov003_021d969c(void *p, s32 a);

void func_ov010_02206784(void *self) {
    switch (FLD(u16, FLD(void *, self, 0x40), 0)) {
    case 0: {
        Ov010Vec p;
        Ov010V *e;
        u16 d;
        func_ov010_02204030(&p, FLD(void *, self, 0xf8), &FLD(Ov010Vec, self, 0x70), 4, 0);
        Ov010_VecCopy(&FLD(Ov010Vec, self, 0xb8), &p);
        FLD(s32, self, 0x150) = p.x - FLD(s32, self, 0x70);
        FLD(s32, self, 0x154) = p.y - FLD(s32, self, 0x74);
        FLD(s32, self, 0x158) = p.z - FLD(s32, self, 0x78);
        VEC_Normalize(&FLD(Ov010Vec, self, 0x150), &FLD(Ov010Vec, self, 0x150));
        FLD(u16, self, 0x98) = FX_Atan2(FLD(s32, self, 0x150), FLD(s32, self, 0x158));
        FLD(s32, self, 0x9c) = 0;
        FLD(s32, self, 0xa0) = 0;
        FLD(s32, self, 0xa4) = 0;
        FLD(s32, self, 0xa8) = 0;
        e = func_ov010_0220eaf0(self, &FLD(Ov010Vec, self, 0x70), &p);
        e->v0c(0x2000);
        func_02049f44(data_02097e4c, 0x29, &FLD(Ov010Vec, self, 0x70), 0);
        FLD(u16, FLD(void *, self, 0x40), 0) = 1;
        d = FLD(u16, e, 0x66) - FLD(u16, self, 0x7e);
        if (d >= 0x1400 && d <= 0x6c00) {
            func_ov000_02190cb0(FLD(void *, self, 0x38), FLD(const char *, data_ov010_0220f024, 0x24), 0x800, 0);
            return;
        }
        if (d >= 0x9400 && d <= 0xec00) {
            func_ov000_02190cb0(FLD(void *, self, 0x38), FLD(const char *, data_ov010_0220f024, 0x20), 0x800, 0);
        }
        break;
    }
    case 1:
        func_ov010_02207828(self);
        func_ov000_0218d918(self, FLD(void *, self, 0xf8), 0x400);
        if (FLD(s32, self, 0x9c) == 0) {
            FLD(u16, FLD(void *, self, 0x40), 0) = 0x100;
        }
        break;
    case 0x100:
        func_ov000_02190cb0(FLD(void *, self, 0x38), FLD(const char *, data_ov010_0220f024, 0x2c), 0xcd, 0);
        func_ov003_021d969c((u8 *)self + 0x160, 1);
        break;
    }
}

}
