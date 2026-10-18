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
s32 FX_Div(s32 a, s32 b);
void func_02043d20(void *a, s32 b);
void NNS_G3dGeBufferOP_N(s32 cmd, void *data, s32 count);
void func_ov000_0217558c(void *self);

void func_ov000_02174ea0(void *self) {
    LFLD(s32, self, 0x20) = 0x10000;
    LFLD(s32, self, 0x3c) = 0;
    LFLD(s32, self, 0x40) = 0;
    LFLD(s32, self, 0x44) = 0;
    LFLD(s32, self, 0x48) = 0;
    LFLD(s32, self, 0x4c) = -1;
    LFLD(s32, self, 0x50) = 0;
    LFLD(s32, self, 0x54) = 0;
    LFLD(s32, self, 0x58) = 0;
    LFLD(s32, self, 0x5c) = 0;
}

void func_ov000_02174ed8(void *self) {
    VOBJ_AT(self, 0x60)->vfunc_08();
    VOBJ_AT(self, 0x118)->vfunc_08();
    VOBJ_AT(self, 0x1d0)->vfunc_08();
    VOBJ_AT(self, 0x288)->vfunc_08();
    VOBJ_AT(self, 0x340)->vfunc_08();
    VOBJ_AT(self, 0x3f8)->vfunc_08();
    LO_FREE_M(self, 0x58);
    LO_FREE_M(self, 0x5c);
    LO_FREE_V(self, 0x40);
    LO_FREE_V(self, 0x44);
    LO_FREE_V(self, 0x48);
}

void func_ov000_02175080(VObj *self, s32 kind) {
    switch (kind) {
    case 0x1a: {
        void *t;
        t = LoSwitchTask(0x1a);
        LFLD(s32, t, 0x2c) = 0;
        LFLD(s32, t, 0x3c) = LFLD(s32, self, 0x14);
        self->vfunc_50();
        LFLD(u32, self, 4) |= 6;
        func_0203cc58(LFLD(s32, self, 0x20), 2, -1);
        return;
    }
    case 0xf:
        LoSwitchTaskC(kind, 0xffff);
        return;
    case 7:
        data_0214a424[9] = 0xff;
    default:
        LoSwitchTask(kind);
        break;
    }
}

}
