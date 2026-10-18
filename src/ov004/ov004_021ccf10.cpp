#include "ov004/ov004.h"

extern "C" {

#pragma force_active on

void func_ov004_021ccf10(void) {
    u32 saved;
    if (data_ov004_021cf860.cb != NULL) {
        data_ov004_021cf860.cb(data_ov004_021cf860.obj, 0x2010000);
    }
    data_ov004_021cf860.cb = NULL;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->def;
    if (data_ov004_021cf860.obj != NULL) {
        Ov004V *p = data_ov004_021cf860.obj;
        if (p != NULL) {
            p->v24();
        }
        data_ov004_021cf860.obj = NULL;
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
