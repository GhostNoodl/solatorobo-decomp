#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void func_02049564(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(Ov009Game54 *g, s32 a);

void func_ov009_022136fc(Ov009Actor *self) {
    func_ov003_021d0fc0(self);
    func_02049564(data_02097e4c, 1, 1);
    switch (self->kind) {
    case 0x504e:
    case 0x5056:
        self->unk_1a = 0;
        func_ov000_02187a20(data_ov000_021ccd54, 0xd);
        break;
    case 0x501b:
    case 0x5037:
        self->unk_1a = 1;
        func_ov000_02187a20(data_ov000_021ccd54, 0xe);
        break;
    }
    FLD(u16, self, 0xea) |= 0x400;
}

}
