#include "ov010/ov010.h"

struct Ov010Trig {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_05;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0a;
    u16 unk_0c;
    u16 unk_0e;
    s32 unk_10;
};

extern "C" {

extern u8 data_ov010_022102a0[];
extern void func_ov000_02198328(void *p);
extern void func_ov003_021da48c(void *p, s32 a);

void func_ov010_02209928(Ov010Trig *self) {
    if (self->b0) {
        self->b0 = 0;
        self->b1 = 0;
    }
}

}
