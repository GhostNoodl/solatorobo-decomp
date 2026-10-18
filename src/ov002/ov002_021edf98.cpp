#include "ov002/ov002.h"

extern "C" {

static inline void func_ov002_021edf98_setC(void *p, s32 v) {
    if (FIELD(p, 0xc, s32) != v) {
        FIELD(p, 0xc, s32) = v;
    }
}
void func_ov002_021edf98(void *arg) {
    void *p = func_0203dd9c(0x30);
    int i;
    if (p != NULL) {
        FIELD(p, 0x4, s32) = 0;
        FIELD(p, 0x8, s32) = 0;
        FIELD(p, 0xc, s32) = 0;
        FIELD(p, 0x10, s32) = 0;
        FIELD(p, 0x14, s32) = 0;
        FIELD(p, 0x18, s32) = 0;
        FIELD(p, 0x1c, s32) = 0x1000;
        FIELD(p, 0x0, void *) = arg;
        FIELD(p, 0x20, s32) = 0x1000;
        FIELD(p, 0x24, s32) = 0;
        func_ov002_021edf98_setC(p, 1);
    }
    data_ov002_021f0fa0[1] = p;
    data_ov002_021f0fa0[0] = NULL;
    data_ov002_021f0fa0[2] = NULL;
    for (i = 0; i < 9; i++) {
        data_ov002_021f0fac[i] = NULL;
    }
}

}
