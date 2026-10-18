#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e6508(void *self, void *out);

extern void *NNS_G3dRS;

extern u32 NNS_G3dGetJointScale_FuncArray;

void MIi_CpuClearFast(int v, void *dst, u32 size);

typedef void (*Func0208b000)(void *a, void *b, int c);

void func_ov002_021e63f0(void *self) {
    u8 buf[0x188];
    u32 fl;
    if (FIELD(self, 0x64, void *) != NULL) {
        func_ov002_021e6508(self, FIELD(self, 0x64, void *));
    }
    if (FIELD(self, 0x68, void *) != NULL) {
        func_ov002_021e6508(self, FIELD(self, 0x68, void *));
    }
    if (FIELD(self, 0x6c, void *) != NULL) {
        func_ov002_021e6508(self, FIELD(self, 0x6c, void *));
    }
    if (FIELD(self, 0x70, void *) != NULL) {
        func_ov002_021e6508(self, FIELD(self, 0x70, void *));
    }
    if (FIELD(self, 0x74, void *) != NULL) {
        func_ov002_021e6508(self, FIELD(self, 0x74, void *));
    }
    if (FIELD(self, 0x64, void *) == NULL) {
        return;
    }
    NNS_G3dRS = buf;
    MIi_CpuClearFast(0, buf, 0x188);
    FIELD(buf, 0xe8, u32) = NNS_G3dGetJointScale_FuncArray;
    ((Func0208b000)NNS_G3dFuncAnmJntNsBcaDefault)((u8 *)self + 0x90, FIELD(self, 0x64, void *), 0);
    fl = FIELD(self, 0x90, u32);
    if (fl & 2) {
        MTX_Identity33_((u8 *)self + 0xb8);
    }
    if (fl & 4) {
        FIELD(self, 0xdc, s32) = 0;
        FIELD(self, 0xe0, s32) = 0;
        FIELD(self, 0xe4, s32) = 0;
    }
    if (fl & 1) {
        FIELD(self, 0x94, s32) = 0x1000;
        FIELD(self, 0x98, s32) = 0x1000;
        FIELD(self, 0x9c, s32) = 0x1000;
    }
    NNS_G3dRS = NULL;
}

}
