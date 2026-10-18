#include "ov010/ov010.h"

extern "C" {

extern u8 data_ov010_02210378[];
extern void func_ov000_02194074(void *self);
extern void func_ov003_021d79d0(void *p);
extern void func_ov000_02198328(void *p);
extern void func_ov010_0220c49c(void *self);

BOOL func_ov010_0220a6a0(void *self) {
    return FLD(Ov010Flags8, self, 4).b0;
}

void *func_ov010_0220a6b0(void *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov010_02210378;
    func_ov003_021d79d0((u8 *)self + 0x120);
    func_ov000_02198328((u8 *)self + 0x158);
    func_ov000_02198328((u8 *)self + 0x16c);
    func_ov010_0220c49c(self);
    return self;
}

}
