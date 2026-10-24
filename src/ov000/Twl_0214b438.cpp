#include "ov000/HeapScope.h"

extern "C" {

BOOL OS_IsRunOnTwl(void);
void OS_Terminate(void);
void *func_0203dd9c(u32 size);

/* TWL-only code (absolute symbols, config/usa/arm9/abs_symbols.txt). */
void *func_0222ebc4(void *self);
void func_0222ec00(void *self);
void func_0222ec1c(void);
void func_0222edbc(void *self);
void func_0222edf4(void *self);
BOOL func_0222edf8(void *self);

extern void *data_ov000_021ccd20;

/* Nothing in the NDS build calls these, so keep the linker from stripping them. */
#pragma force_active on

void func_ov000_0214b438(void) {
    void *p;
    if (data_ov000_021ccd20 != NULL) {
        return;
    }
    if (!OS_IsRunOnTwl()) {
        return;
    }
    if (!OS_IsRunOnTwl()) {
        OS_Terminate();
    }
    p = func_0203dd9c(0x14);
    if (p != NULL) {
        p = func_0222ebc4(p);
    }
    data_ov000_021ccd20 = p;
    func_0222ec1c();
}

void func_ov000_0214b490(void) {
    if (data_ov000_021ccd20 == NULL) {
        return;
    }
    HEAP_DELETE_FN(data_ov000_021ccd20, func_0222ec00);
}

BOOL func_ov000_0214b4fc(void) {
    if (data_ov000_021ccd20 != NULL) {
        func_0222edbc(data_ov000_021ccd20);
    }
    return TRUE;
}

void func_ov000_0214b520(void) {
    if (data_ov000_021ccd20 == NULL) {
        return;
    }
    func_0222edf4(data_ov000_021ccd20);
}

BOOL func_ov000_0214b540(void) {
    BOOL ret = TRUE;
    if (OS_IsRunOnTwl()) {
        ret = func_0222edf8(data_ov000_021ccd20);
    }
    return ret;
}

#pragma force_active reset

}
