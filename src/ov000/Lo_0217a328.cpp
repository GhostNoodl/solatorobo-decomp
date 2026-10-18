#include "ov000/LoCommon.h"

extern "C" {
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021cad50[];
extern void *data_02149ef8;
void *func_0204c0e8(void *p, u16 a);
void func_ov000_0215c1bc(void *a, s32 b, void *c);
void func_ov000_0215ce8c(void *a, s32 b);

void func_ov000_0217a328(u8 *self, s32 a, s32 b) {
    if (LFLD(VObj *, self, 0x48) == NULL) {
        VObj *o = (VObj *)func_0203dd9c(0xe8);
        if (o != NULL) {
            VOBJ_SET_VTABLE(o, data_ov000_021cac60);
            o->vfunc_28();
            VOBJ_SET_VTABLE(o, data_ov000_021cad50);
            o->vfunc_28();
        }
        LFLD(VObj *, self, 0x48) = o;
    }
    if (a == 0x79 || b == 0x77) {
        LFLD(u32, LFLD(VObj *, self, 0x48), 0xc) |= 0x10000;
    } else {
        LFLD(u32, LFLD(VObj *, self, 0x48), 0xc) &= ~0x10000;
    }
    if (LFLD(s32, self, 0xc) != 1) {
        LFLD(u16, LFLD(VObj *, self, 0x48), 0x48) = 0x2803;
    } else {
        VObj *o = LFLD(VObj *, self, 0x48);
        LFLD(u32, o, 0xc) |= 8;
        LFLD(u16, o, 0x48) = 0x14a5;
        LFLD(s32, o, 0x54) = 0x1c;
    }
    LFLD(s32, LFLD(VObj *, self, 0x48), 0x1c) = 4;
    LFLD(VObj *, self, 0x48)->vfunc_08();
    if (b != -1) {
        func_ov000_0215c1bc(LFLD(VObj *, self, 0x48), 0x8000, func_0204c0e8(data_02149ef8, b));
    } else {
        func_ov000_0215ce8c(LFLD(VObj *, self, 0x48), a);
    }
    LFLD(s16, LFLD(VObj *, self, 0x48), 0x68) = -0x1ccd;
    LFLD(VObj *, self, 0x48)->vfunc_70();
}
}
