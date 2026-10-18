#include "ov000/LoCommon.h"

extern "C" {

extern u8 data_ov000_021cc060[];
extern u8 data_ov000_021cbbe0[];
extern u8 data_0208ba70[];
extern u8 *data_0214a424;
extern u8 *data_02097d48;
extern const s16 FX_SinCosTable_[];
void func_0204c7d0(void *p);
void func_0203cc58(s32 a, s32 b, s32 c);
s32 func_02012ab8(s32 a, s32 b);
void func_02043d20(void *a, s32 b);
void func_0202a3ec(s32 cmd, void *data, s32 count);
void func_ov000_0217558c(void *self);

void func_ov000_021752f0(VObj *self) {
    switch (LFLD(s32, self, 8)) {
    case 8:
        LFLD(void *, self, 0x2c) = LoFindTask(1);
        if (LFLD(void *, self, 0x40) != NULL) {
            LBIT(LFLD(void *, self, 0x40), 0xc).b1 = 0;
        }
        if (LFLD(void *, self, 0x44) != NULL) {
            LBIT(LFLD(void *, self, 0x44), 0xc).b1 = 0;
        }
        if (LFLD(void *, self, 0x48) != NULL) {
            LBIT(LFLD(void *, self, 0x48), 0xc).b1 = 0;
        }
        break;
    case 0xa:
        if (self->vfunc_54()) {
            LFLD(s32, self, 0x4c) = 0;
        }
        break;
    }
}

void func_ov000_021753a0(void *self) {
    s32 m = LFLD(s32, self, 0x4c);
    if (m == 1) {
        s32 v;
        LFLD(s32, self, 0x50) += 0x1000;
        v = func_02012ab8(LFLD(s32, self, 0x50), LFLD(s32, LFLD(void *, self, 0x40), 0x34));
        LFLD(s32, self, 0x54) = v;
        if (v >= 0x1000) {
            LFLD(s32, self, 0x54) = 0x1000;
            LFLD(s32, self, 0x4c) = -1;
        }
    } else if (m == 0) {
        s32 v;
        LFLD(s32, self, 0x50) -= 0x1000;
        v = func_02012ab8(LFLD(s32, self, 0x50), LFLD(s32, LFLD(void *, self, 0x40), 0x34));
        LFLD(s32, self, 0x54) = v;
        if (v <= 0) {
            LFLD(s32, self, 0x54) = 0;
            LFLD(s32, self, 0x4c) = -1;
            if (LFLD(void *, self, 0x40) != NULL) {
                LBIT(LFLD(void *, self, 0x40), 0xc).b1 = 1;
            }
            if (LFLD(void *, self, 0x44) != NULL) {
                LBIT(LFLD(void *, self, 0x44), 0xc).b1 = 1;
            }
            if (LFLD(void *, self, 0x48) != NULL) {
                LBIT(LFLD(void *, self, 0x48), 0xc).b1 = 1;
            }
        }
    }
    if (LFLD(VObj *, self, 0x40) != NULL) {
        LFLD(VObj *, self, 0x40)->vfunc_1c();
        LBIT(LFLD(void *, self, 0x40), 0xc).b2 = 1;
    }
    if (LFLD(VObj *, self, 0x44) != NULL) {
        LFLD(VObj *, self, 0x44)->vfunc_1c();
    }
    if (LFLD(VObj *, self, 0x48) != NULL) {
        LFLD(VObj *, self, 0x48)->vfunc_1c();
    }
}

void func_ov000_021754bc(void *self) {
    s32 scale[3];
    if (LFLD(s32, self, 0x24) == 0) {
        return;
    }
    func_02043d20(data_02097d48 + 0x8b0, 0);
    scale[0] = 0x1000;
    scale[1] = 0x1000;
    scale[2] = 0x1000;
    func_0202a3ec(0x1b, scale, 3);
    LFLD(s32, self, 0x28) = FX_SinCosTable_[((LFLD(s32, self, 0x24) << 14) >> 16) * 2];
    if (LFLD(VObj *, self, 0x40) != NULL) {
        LFLD(VObj *, self, 0x40)->vfunc_20();
    }
    if (LFLD(VObj *, self, 0x44) != NULL) {
        LFLD(VObj *, self, 0x44)->vfunc_20();
    }
    func_ov000_0217558c(self);
    if (LFLD(VObj *, self, 0x48) != NULL) {
        LFLD(VObj *, self, 0x48)->vfunc_20();
    }
}

}
