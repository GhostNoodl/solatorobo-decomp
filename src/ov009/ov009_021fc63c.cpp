#include "ov009/ov009.h"
#include "Main/Gfx/SlidePanel.h"

extern "C" {

extern void SndMgr_LoadHeapState(SndMgr *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(void *p, s32 a);
void func_ov009_021fc63c(Ov003Actor *self) {
    func_ov003_021d0fc0(self);
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
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
