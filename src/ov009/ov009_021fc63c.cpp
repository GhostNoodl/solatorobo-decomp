#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void func_02049564(void *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(void *p, s32 a);
void func_ov009_021fc63c(Ov009Actor *self) {
    func_ov003_021d0fc0(self);
    func_02049564(data_02097e4c, 1, 1);
    switch (self->kind) {
    case 0x5000:
    case 0x5001:
    case 0x5002:
    case 0x5004:
    case 0x5005:
    case 0x5007:
    case 0x5008:
    case 0x500a:
    case 0x500c:
    case 0x500d:
    case 0x500f:
    case 0x501f:
    case 0x503c:
        func_ov000_02187a20(data_ov000_021ccd54, 0xd);
        break;
    case 0x5003:
    case 0x5006:
    case 0x5009:
    case 0x500b:
    case 0x500e:
    case 0x503a:
    case 0x503b:
    case 0x503d:
        func_ov000_02187a20(data_ov000_021ccd54, 0xe);
        break;
    case 0x502a:
    case 0x502d:
        func_ov000_02187a20(data_ov000_021ccd54, 0xf);
        break;
    }
}

}
