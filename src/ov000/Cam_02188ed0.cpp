#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 2;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
} Bits02188ed0;

typedef struct {
    u8 unk_00[0x9c];
    Bits02188ed0 f9c;
    u8 unk_9d[0x3d];
    Bits02188ed0 fda;
    u8 unk_db[0xd];
    VecFx32 pos;
    s32 unk_f4;
    u16 unk_f8;
    u16 unk_fa;
} Cam02188ed0;

typedef struct {
    u8 unk_00[4];
    u8 *unk_04;
} Data021ccd50b;

typedef struct {
    u8 unk_00[0xb28];
    u8 lo : 2;
    u8 hi : 6;
    u8 unk_b29[5];
    u8 unk_b2e;
} Player02188ed0;

extern "C" {
extern Data021ccd50b data_ov000_021ccd50;
extern u8 *data_ov000_021ccd30;
Player02188ed0 *func_ov000_0219bf90(void);
BOOL func_ov000_0216f674(void *mgr, s32 a);
BOOL func_ov000_021700c4(void *p);
void func_ov000_0218a358(Cam02188ed0 *s, void *a, void *b, s32 c, s32 d, s32 e, s32 f, s32 g);

static inline BOOL IsBusy(void) {
    u8 *c = data_ov000_021ccd30;
    if (c == NULL) {
        return FALSE;
    }
    if (func_ov000_0216f674(c, 6)) {
        return TRUE;
    }
    if (LFLD(void *, c, 0x11c) == NULL) {
        return FALSE;
    }
    return func_ov000_021700c4(LFLD(void *, c, 0x11c));
}

void func_ov000_02188ed0(u8 *self) {
    Cam02188ed0 *s = (Cam02188ed0 *)(data_ov000_021ccd50.unk_04 + 0xf4);
    if (LFLD(u8, self, 0xd3)) {
        s->pos = LFLD(VecFx32, self, 0xd8);
        s->fda.b1 = 1;
        s->unk_f8 = LFLD(u16, self, 0xe4);
        s->fda.b4 = 1;
        s->unk_fa = LFLD(u16, self, 0xe6);
        s->fda.b5 = 1;
        s->unk_f4 = LFLD(s32, self, 0xec);
        s->fda.b2 = 1;
        s->f9c.b0 = 0;
        s->f9c.b6 = 0;
        return;
    }
    s->f9c.b0 = 1;
    if (LFLD(s32, self, 0xd4) > 0) {
        Player02188ed0 *p = func_ov000_0219bf90();
        if (p != NULL && p->lo == 0 && p->unk_b2e < 2) {
            p->unk_b2e = 2;
        }
        if (LFLD(s32, self, 0xd4) != 0xffff && --LFLD(s32, self, 0xd4) == 0) {
            if (IsBusy()) {
                LFLD(s32, self, 0xd4) = 1;
            }
        }
        func_ov000_0218a358(s, self + 0xd8, self + 0xe4, LFLD(s32, self, 0xec), 0, LFLD(s16, self, 0xf0), LFLD(s16, self, 0xf0), 4);
    } else {
        LFLD(s32, self, 0xd4) = 0;
    }
}
}
