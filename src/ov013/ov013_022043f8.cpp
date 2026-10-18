#include "ov013/ov013.h"

struct Ov013Pair32 {
    s32 a;
    s32 b;
};

extern "C" {

extern void *data_ov013_0220bbb8[];
extern char data_ov013_0220ba58[];
extern char data_ov013_0220ba60[];
extern void func_ov003_021d9980(Ov013Vec *out, u16 rot, const Ov013Vec *v);
extern void func_ov000_02194074(void *self);
extern void func_ov003_021cf2bc(void *p);
extern void func_ov003_021cf2d8(void *p);
extern void func_ov000_0218ea20(void *p);
extern void func_ov000_0218fee4(void *p);
extern void *func_ov000_0218e9c4(void *p);
extern void func_ov000_0219433c(void *self);
extern BOOL func_ov000_021946f8(void *self);
extern BOOL func_ov000_0218f110(void *p);

void func_ov013_022043f8(void *self, u32 *p) {
    if (p != NULL) {
        FLD(u32, self, 0x24) = *p;
    }
}

void func_ov013_02204408(Ov013Vec *out, const Ov013Vec *v, Ov013Actor *a) {
    if (a != NULL) {
        func_ov003_021d9980(out, a->rot[1], v);
    }
}

void func_ov013_02204428(Ov013Vec *dst, const Ov013Vec *src) {
    *dst = *src;
}

void func_ov013_02204444(void) {
}

BOOL func_ov013_02204448(void) {
    return TRUE;
}

void func_ov013_02204450(void) {
}

}
