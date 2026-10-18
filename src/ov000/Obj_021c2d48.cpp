#include "ov000/LoCommon.h"

extern "C" {
extern u8 data_ov000_021cac0c[];
extern u8 data_ov000_021cca88[];
extern u8 data_ov000_021cc998[];
extern u8 data_ov000_021cc99e[];
void func_ov000_0215fdfc(void *p, s32 i, void *d);
void func_ov000_0215fe1c(void *p, s32 v);

static inline void SetClamped(VObj *o, s32 v, s32 max) {
    if (v > max) {
        v = max;
    }
    func_ov000_0215fe1c(o, v);
}

void func_ov000_021c2d48(u8 *self) {
    if (LFLD(u8, self, 0x40) == 0) {
        VObj *o = (VObj *)func_0203dd9c(0x9c);
        if (o != NULL) {
            VOBJ_SET_VTABLE(o, data_ov000_021cac0c);
            o->vfunc_14();
            VOBJ_SET_VTABLE(o, data_ov000_021cca88);
        }
        LFLD(VObj *, self, 0x30) = o;
        LFLD(s32, o, 0x28) = 2;
        LFLD(s32, LFLD(VObj *, self, 0x30), 0x58) = 3;
        LFLD(s32, LFLD(VObj *, self, 0x30), 0x50) = 0x4a;
        LFLD(s32, LFLD(VObj *, self, 0x30), 0x54) = 6;
        func_ov000_0215fdfc(LFLD(VObj *, self, 0x30), 0, data_ov000_021cc998);
        func_ov000_0215fdfc(LFLD(VObj *, self, 0x30), 1, data_ov000_021cc99e);
        func_ov000_0215fdfc(LFLD(VObj *, self, 0x30), 2, data_ov000_021cc998 + ((LFLD(s32, self, 0x3c) * 3) / LFLD(s32, self, 0x38) + 2) * 6);
        LFLD(u8, LFLD(VObj *, self, 0x30), 0x98) = 0x1f;
        SetClamped(LFLD(VObj *, self, 0x30), LFLD(s32, self, 0x3c), LFLD(s32, self, 0x38));
        LFLD(u32, LFLD(VObj *, self, 0x30), 0xc) |= 8;
        LFLD(u8, self, 0x40) = 1;
    } else {
        LFLD(VObj *, self, 0x30)->vfunc_0c();
    }
}
}
