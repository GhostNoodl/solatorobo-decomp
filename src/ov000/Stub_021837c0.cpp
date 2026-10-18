#include "ov000/VObj.h"

extern "C" {

void func_ov000_02182190(void *p, s32 a, s32 b, s32 c, u16 d, u16 e, u16 f);
void func_ov000_02182374(void *p, s32 a, s32 b);

void func_ov000_021837c0(void *self) {
    s32 *index = (s32 *)((u8 *)self + 0x94);
    ((s32 *)((u8 *)self + 0x10))[*index] = 0x8;
    ((s32 *)((u8 *)self + 0x50))[*index] = 0;
    if (++*index >= 0x10) {
        *index = 0;
    }
}

void func_ov000_021837f8(void *self, s32 a, s32 b, s32 c, u16 d, u16 e, u16 f) {
    s32 *index = (s32 *)((u8 *)self + 0x94);
    ((s32 *)((u8 *)self + 0x10))[*index] = 0x7;
    ((s32 *)((u8 *)self + 0x50))[*index] = 0;
    if (++*index >= 0x10) {
        *index = 0;
    }
    func_ov000_02182190((u8 *)self + 0xac, a, b, c, d, e, f);
}

void func_ov000_02183858(void *self, s32 a) {
    func_ov000_02182374((u8 *)self + 0xac, a, 0);
}

void func_ov000_0218386c(void *self, s32 a) {
    func_ov000_02182374((u8 *)self + 0xac, a, 1);
}

}
