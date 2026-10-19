#include "ov000/LoCommon.h"

typedef struct {
    u32 b0 : 1;
    u32 b1 : 1;
    u32 pad : 5;
    u32 fade : 2;
    u32 rest : 23;
} Bits02152740;

typedef void (*LoCb02152740)(VObj *self);

extern "C" {
s32 FX_Div(s32 a, s32 b);

#define WB(self) LFLD(Bits02152740, self, 0xc)

BOOL func_ov000_02152740(VObj *self) {
    self->vfunc_54();
    switch (LFLD(s32, self, 4)) {
    case 5:
        if (!WB(self).b1) {
            LFLD(s32, self, 4) = 0;
            return TRUE;
        }
        return FALSE;
    case 0:
        WB(self).b0 = 1;
        if (WB(self).b1 == 1) {
            LFLD(s32, self, 4) = 5;
            break;
        }
        if (LFLD(LoCb02152740, self, 0x78) != NULL) {
            LFLD(LoCb02152740, self, 0x78)(self);
        }
        LFLD(s32, self, 4) = 3;
    case 3:
        if (!self->vfunc_4c()) {
            break;
        }
        LFLD(s32, self, 0x30) += 0x1000;
        LFLD(s32, self, 0x38) = FX_Div(LFLD(s32, self, 0x30), LFLD(s32, self, 0x34));
        if (LFLD(s32, self, 0x38) < 0x1000) {
            break;
        }
        if (LFLD(void *, self, 0x74) == NULL) {
            WB(self).b0 = 0;
        }
        LFLD(s32, self, 0x30) = LFLD(s32, self, 0x34);
        LFLD(s32, self, 0x38) = 0x1000;
        if (LFLD(LoCb02152740, self, 0x78) != NULL) {
            LFLD(LoCb02152740, self, 0x78)(self);
        }
        LFLD(s32, self, 4) = 2;
        break;
    case 1:
        WB(self).b0 = 1;
        if (LFLD(LoCb02152740, self, 0x78) != NULL) {
            LFLD(LoCb02152740, self, 0x78)(self);
        }
        LFLD(s32, self, 4) = 4;
    case 4:
        LFLD(s32, self, 0x30) -= 0x1000;
        LFLD(s32, self, 0x38) = FX_Div(LFLD(s32, self, 0x30), LFLD(s32, self, 0x34));
        if (LFLD(s32, self, 0x38) > 0) {
            break;
        }
        LFLD(s32, self, 0x30) = 0;
        LFLD(s32, self, 0x38) = 0;
        if (LFLD(LoCb02152740, self, 0x78) != NULL) {
            LFLD(LoCb02152740, self, 0x78)(self);
        }
        LFLD(s32, self, 4) = 5;
        return FALSE;
    case 2:
        LFLD(s32, self, 0x30) = LFLD(s32, self, 0x34);
        LFLD(s32, self, 0x38) = 0x1000;
        {
            u32 f = WB(self).fade;
            if (f == 0) {
            } else if (f == 1) {
                LFLD(s32, self, 0x3c) += 0x1000;
                LFLD(s32, self, 0x44) = FX_Div(LFLD(s32, self, 0x3c), LFLD(s32, self, 0x40));
                if (LFLD(s32, self, 0x44) >= 0x1000) {
                    LFLD(s32, self, 0x3c) = LFLD(s32, self, 0x40);
                    LFLD(s32, self, 0x44) = 0x1000;
                    WB(self).fade = 2;
                }
            } else if (f == 3) {
                LFLD(s32, self, 0x3c) -= 0x1000;
                LFLD(s32, self, 0x44) = FX_Div(LFLD(s32, self, 0x3c), LFLD(s32, self, 0x40));
                if (LFLD(s32, self, 0x44) <= 0) {
                    LFLD(s32, self, 0x3c) = 0;
                    LFLD(s32, self, 0x44) = 0;
                    WB(self).fade = 0;
                }
            }
        }
        break;
    }
    if (LFLD(VObj *, self, 0x74) != NULL && !LFLD(VObj *, self, 0x74)->vfunc_1c()) {
        LO_FREE_V(self, 0x74);
        if (LFLD(VObj *, self, 0x74) == NULL) {
            WB(self).b0 = 0;
        }
        if (!self->vfunc_50()) {
            WB(self).b1 = 1;
        }
    }
    self->vfunc_58();
    if (LFLD(s32, self, 0x50) != 0) {
        s32 n = LFLD(s32, self, 0x50) << 12;
        LFLD(s32, self, 0x4c) += 0x666;
        if (LFLD(s32, self, 0x4c) >= n + 0x7c000) {
            LFLD(s32, self, 0x4c) -= n;
        }
    }
    return TRUE;
}

}

