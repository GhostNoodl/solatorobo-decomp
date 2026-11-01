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

struct Obj021c2d48 {
    u8 unk_00[0x30];
    VObj *unk_30;
    u8 unk_34[0x4];
    s32 unk_38;
    s32 unk_3c;
    u8 unk_40;
};

void func_ov000_021c2d48(Obj021c2d48 *self) {
    if (self->unk_40 == 0) {
        VObj *o = (VObj *)func_0203dd9c(0x9c);
        if (o != NULL) {
            VOBJ_SET_VTABLE(o, data_ov000_021cac0c);
            o->vfunc_14();
            VOBJ_SET_VTABLE(o, data_ov000_021cca88);
        }
        self->unk_30 = o;
        LFLD(s32, o, 0x28) = 2;
        LFLD(s32, self->unk_30, 0x58) = 3;
        LFLD(s32, self->unk_30, 0x50) = 0x4a;
        LFLD(s32, self->unk_30, 0x54) = 6;
        func_ov000_0215fdfc(self->unk_30, 0, data_ov000_021cc998);
        func_ov000_0215fdfc(self->unk_30, 1, data_ov000_021cc99e);
        func_ov000_0215fdfc(self->unk_30, 2, data_ov000_021cc998 + ((self->unk_3c * 3) / self->unk_38 + 2) * 6);
        LFLD(u8, self->unk_30, 0x98) = 0x1f;
        SetClamped(self->unk_30, self->unk_3c, self->unk_38);
        LFLD(u32, self->unk_30, 0xc) |= 8;
        self->unk_40 = 1;
    } else {
        self->unk_30->vfunc_0c();
    }
}
}
