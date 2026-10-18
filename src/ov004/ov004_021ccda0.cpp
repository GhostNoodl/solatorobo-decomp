#include "ov004/ov004.h"

extern "C" {

#pragma force_active on

void *func_ov004_021ccda0(s32 a, s32 b) {
    Ov004V *o = data_ov004_021cf860.obj;
    u8 *x = (u8 *)func_ov000_0219bf90();
    u32 v = (FLD(u8, o, 0x16) |= 4);
    if (x != NULL) {
        v |= x[0x16];
    }
    v |= 0x1200;
    if (x != NULL) {
        x[0x16] = v;
    }
    if (a != b) {
        FLD(u8, o, 0x16) = v;
    }
    FLD(u16, o, 0x22) = v;
    func_ov000_02176264(o);
    return o;
}

void *func_ov004_021ccdfc(s32 a, s32 b) {
    Ov004V *o = data_ov004_021cf860.obj;
    u8 *x = (u8 *)func_ov000_0219bf90();
    u32 v = (FLD(u8, o, 0x16) = FLD(u8, o, 0x16) & ~4);
    if (x != NULL) {
        v &= x[0x16];
    }
    v |= 0x3400;
    if (x != NULL) {
        x[0x16] = v;
    }
    if (a != b) {
        FLD(u8, o, 0x16) = v;
    }
    FLD(u16, o, 0x22) = v;
    func_ov000_021761f0(o);
    return NULL;
}

void *func_ov004_021cce5c(void *a, s32 b) {
    Ov004V *o = data_ov004_021cf860.obj;
    if (a == o) {
        FLD(u16, o, 0x22) = 1;
    }
    if ((Ov004V *)b == o) {
        FLD(u16, o, 0x22) = 2;
    }
    return o;
}


#pragma force_active reset

}
