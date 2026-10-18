#include "ov009/ov009.h"

extern "C" {

extern void *data_ov009_02215d0c[];
extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
extern u8 *func_ov000_0218bd5c(void *mgr, u16 id);
extern void func_02049564(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(Ov009Game54 *g, s32 a);

struct Ov009Byte {
    u8 b0 : 1;
    u8 b1 : 4;
    u8 b5 : 1;
    u8 b6 : 2;
};

void func_ov009_0220397c(Ov009Names *self, void *res);

void func_ov009_0220413c(Ov009Actor *self) {
    u8 *p;
    if (self->kind != 0x5810 && self->kind != 0x5811) {
        FLD(void *, self, 0xd8) = (void *)func_ov009_0220397c;
    }
    func_ov003_021d0fc0(self);
    p = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        Ov009Byte *bb = (Ov009Byte *)(p + 0xa2);
        bb->b0 = 0;
        bb->b5 = 1;
    }
    func_02049564(data_02097e4c, 1, 1);
    switch (self->kind) {
    case 0x503e:
        FLD(u16, self, 0xea) |= 0x400;
    case 0x504d:
        func_ov000_02187a20(data_ov000_021ccd54, 0xd);
        break;
    case 0x5027:
        func_ov000_02187a20(data_ov000_021ccd54, 0xf);
        FLD(u16, self, 0xea) |= 0x400;
        break;
    }
    FLD(s32, self, 0xf8) = 0;
}

}
