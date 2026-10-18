#include "ov010/ov010.h"

struct Ov010B2 {
    u8 a;
    u8 b;
};

extern "C" {

extern void func_ov003_021da40c(void *p);
extern void func_ov000_0218d7e8(void *self, u8 a);
extern BOOL func_ov003_021da03c(void *self);
extern void func_ov003_021d8fc0(void *p);
extern BOOL func_ov003_021d9878(void *p);
extern Ov010B2 func_ov003_021d9644(void *p);
extern void func_ov000_02198360(void *a, s32 b, s32 c);

void func_ov010_02204aac(void *self) {
    func_ov003_021da40c(FLD(void *, self, 0x40));
    func_ov000_0218d7e8(self, FLD(u8, FLD(u8 *, self, 0x40), 0x13));
}

void func_ov010_02204ad0(void) {
}

void func_ov010_02204ad4(void *self) {
    BOOL go = FALSE;
    FLD(Ov010Flags8, self, 0x93).b4 = 0;
    if (func_ov003_021da03c(self) || FLD(u8, self, 0xf2) != 0) {
        go = TRUE;
    }
    FLD(u8, self, 0xf2) = 0;
    if (!go) {
        return;
    }
    FLD(s32, self, 0xc4) = 0;
    FLD(Ov010Flags8, self, 0x93).b4 = 1;
    func_ov003_021d8fc0((u8 *)self + 0x160);
    if (func_ov003_021d9878((u8 *)self + 0x160)) {
        Ov010B2 r = func_ov003_021d9644((u8 *)self + 0x160);
        FLD(Ov010B2, self, 0x170) = r;
        func_ov000_02198360(FLD(void *, self, 0x40), r.a, 1);
    }
}

}
