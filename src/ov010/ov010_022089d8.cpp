#include "ov010/ov010.h"

extern "C" {

extern void *data_02097e4c;
extern u8 data_ov010_0220f024[];
extern const Ov010Vec data_ov010_0220f144;
extern BOOL func_ov000_02190cb0(void *a, const char *b, s32 c, s32 d);
extern void func_ov000_021915a0(void *a);
extern void *func_02049f44(void *a, s32 b, Ov010Vec *c, s32 d);
extern Ov010V *func_02065f88(s32 id, Ov010Vec *pos);
extern void func_ov003_021d9dbc(Ov010Vec *out, const Ov010Vec *a, const Ov010Vec *b, s32 dist, s32 yoff);
extern void func_ov003_021d64f0(void *self);
extern u16 FX_Atan2(s32 y, s32 x);
extern s32 VEC_Distance(const Ov010Vec *a, const Ov010Vec *b);
extern void func_ov003_021da2c8(void *self, s32 a, s32 b, s32 c, s32 d);
extern BOOL func_ov000_02198360(void *a, s32 b, s32 c);

static inline BOOL Ov010_Begin(u16 *st) {
    if (*st == 0) {
        (*st)++;
        return TRUE;
    }
    return FALSE;
}

void func_ov010_022089d8(void *self) {
    BOOL anim = FALSE;
    switch (FLD(s16, self, 0x18)) {
    case 0: {
        u16 *st = FLD(u16 *, self, 0x40);
        if (st[0] == 0) {
            Ov010_VecSet(&FLD(Ov010Vec, self, 0x70), -0xd9e, 0x2a35, -0x8687);
            FLD(s32, self, 0x74) += 0xd000;
            FLD(u16, self, 0x7c) = 0;
            FLD(u16, self, 0x7e) = 0xff;
            FLD(u16, self, 0x80) = 0;
            FLD(s32, self, 0xa0) = 0;
            FLD(s32, self, 0xa4) = 0;
            FLD(s32, self, 0xa8) = 0;
            FLD(s32, self, 0x9c) = 0x200;
            anim = TRUE;
            func_02049f44(data_02097e4c, 0x51, &FLD(Ov010Vec, self, 0x70), 0);
            FLD(u16 *, self, 0x40)[0]++;
        } else {
            const Ov010Vec *t = &data_ov010_0220f144;
            if (FLD(s32, self, 0x9c) >= 0x40) {
                if (FLD(s32, self, 0xa4) == 0) {
                    if (VEC_Distance(t, &FLD(Ov010Vec, self, 0x70)) < 0x2000) {
                        FLD(s32, self, 0xa4) = 0xf00;
                    }
                }
                func_ov003_021d9dbc(&FLD(Ov010Vec, self, 0x70), t, &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x9c), FLD(s32, self, 0xa0));
                func_ov003_021da2c8(self, FLD(s32, self, 0x9c), FLD(s32, self, 0xa0), FLD(s32, self, 0xa4), FLD(s32, self, 0xa8));
                FLD(u16, self, 0x98) = FX_Atan2(t->x - FLD(s32, self, 0x70), t->z - FLD(s32, self, 0x78));
            } else {
                if (st[1] == 0) {
                    func_02065f88(0x12f, &FLD(Ov010Vec, self, 0x70))->v0c(0xe66);
                }
                FLD(u16 *, self, 0x40)[1]++;
                if (FLD(u16 *, self, 0x40)[1] > 0x5a) {
                    FLD(s32, self, 0x9c) = 0;
                    FLD(s32, self, 0xa0) = 0;
                    FLD(s32, self, 0xa4) = 0;
                    FLD(s32, self, 0xa8) = 0;
                    func_ov003_021d64f0(self);
                } else {
                    func_ov003_021d9dbc(&FLD(Ov010Vec, self, 0x70), t, &FLD(Ov010Vec, self, 0x70), FLD(s32, self, 0x9c), FLD(s32, self, 0xa0));
                    func_ov003_021da2c8(self, FLD(s32, self, 0x9c), FLD(s32, self, 0xa0), FLD(s32, self, 0xa4), FLD(s32, self, 0xa8));
                    FLD(u16, self, 0x98) = FX_Atan2(t->x - FLD(s32, self, 0x70), t->z - FLD(s32, self, 0x78));
                }
            }
        }
        break;
    }
    case 1:
    case 2: {
        if (FLD(const u16 *, self, 0x40)[0] == 0) {
            FLD(u16 *, self, 0x40)[0]++;
            anim = TRUE;
        }
        Ov010_VecSet(&FLD(Ov010Vec, self, 0x70), -0xd9e, 0x2a35, -0x8687);
        FLD(u16, self, 0x7c) = 0;
        FLD(u16, self, 0x7e) = 0xff;
        FLD(u16, self, 0x80) = 0;
        func_ov000_02198360(FLD(void *, self, 0x40), 1, 0);
        break;
    }
    }
    if (anim) {
        func_ov000_02190cb0(FLD(void *, self, 0x38), FLD(const char *, data_ov010_0220f024, 0x2c), 0x1000, 0);
        func_ov000_021915a0(FLD(void *, self, 0x38));
        FLD(Ov010Flags, FLD(void *, self, 0x38), 0xc2).b0 = 1;
    }
}
}
