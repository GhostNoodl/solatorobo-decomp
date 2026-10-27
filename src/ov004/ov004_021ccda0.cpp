#include "ov004/ov004.h"

extern "C" {

// This file's .bss: the active callback and the object it is called with.
Ov004Cb data_ov004_021cf860;
Ov004V *data_ov004_021cf864;

#pragma force_active on

void *func_ov004_021ccda0(s32 a, s32 b) {
    Ov004V *o = data_ov004_021cf864;
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
    Ov004V *o = data_ov004_021cf864;
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
    Ov004V *o = data_ov004_021cf864;
    if (a == o) {
        FLD(u16, o, 0x22) = 1;
    }
    if ((Ov004V *)b == o) {
        FLD(u16, o, 0x22) = 2;
    }
    return o;
}

void *func_ov004_021cce88(void) {
    Ov004V *o;
    u32 k;
    func_ov004_021ce50c();
    o = (Ov004V *)func_0203dd9c(0xac);
    if (o != NULL) {
        func_ov000_0218c2d4(o);
        *(u8 **)o = data_ov004_021cf808;
    }
    data_ov004_021cf864 = o;
    k = *(u32 *)0x2fffc3c & 1;
    data_ov004_021cf86c[k] = (void *)func_ov004_021ccdfc;
    data_ov004_021cf868 = k;
    data_ov004_021cf86c[k ^ 1] = (void *)func_ov004_021ccda0;
    data_ov004_021cf860 = func_ov004_021cce5c;
    return o;
}

void func_ov004_021ccf10(void) {
    u32 saved;
    if (data_ov004_021cf860 != NULL) {
        data_ov004_021cf860(data_ov004_021cf864, 0x2010000);
    }
    data_ov004_021cf860 = NULL;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (data_ov004_021cf864 != NULL) {
        Ov004V *p = data_ov004_021cf864;
        if (p != NULL) {
            p->v24();
        }
        data_ov004_021cf864 = NULL;
    }
    data_02097dd0->cur = saved;
}

void *func_ov004_021ccf94(void *p) {
    func_ov000_0218c928(p);
    func_0203de1c(p);
    return p;
}

void func_ov004_021ccfb0(void *p) {
    if (FLD(void *, p, 0x44) != NULL) {
        func_ov000_021984f4(FLD(void *, p, 0x44), 0, 0);
    }
}

void func_ov004_021ccfd0(void *p) {
    if (FLD(void *, p, 0x48) != NULL) {
        func_ov000_0219864c(FLD(void *, p, 0x48), 0, 0);
    }
}

void func_ov004_021ccff0(void *p) {
    if (FLD(void *, p, 0x38) != NULL) {
        func_ov000_02190a80(FLD(void *, p, 0x38), func_0203db40((u8 *)p + 0x24));
    }
}

void func_ov004_021cd01c(void) {}
void func_ov004_021cd020(void) {}
void func_ov004_021cd024(void) {}
void func_ov004_021cd028(void) {}
void func_ov004_021cd02c(void) {}
void func_ov004_021cd030(void) {}
void func_ov004_021cd034(void) {}
void func_ov004_021cd038(void) {}

void *func_ov004_021cd03c(void *p) {
    func_ov000_0218c928(p);
    return p;
}

#pragma force_active reset

}
