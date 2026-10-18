#include "ov007/ov007.h"

extern "C" {

void func_ov007_021cdff0(void *task) {
    u32 v;
    void *q;
    q = FLD(void *, task, 0xb0);
    v = FLD(u32, q, 0xc);
    FLD(u32, q, 0xc) = (v & ~0x3f000000) | (func_02043d48(data_02097d48 + 0x8b0) << 24);
}

void func_ov007_021ce020(void *task) {
    FLD(void *, task, 0x1c) = (void *)func_ov007_021cdff0;
    FLD(u8, task, 0x90) = 2;
}

}
