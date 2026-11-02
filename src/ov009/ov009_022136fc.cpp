#include "ov009/ov009.h"
#include "Main/Gfx/SlidePanel.h"

extern "C" {

extern void SndMgr_LoadHeapState(SndMgr *mgr, s32 a, s32 b);
extern void func_ov000_02187a20(FieldState *g, s32 a);

void Ov009ActVt_02217cb0_Init(Ov009ActVt_02217cb0 *self) {
    func_ov003_021d0fc0(self);
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
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
    self->unk_ea |= 0x400;
}

}
