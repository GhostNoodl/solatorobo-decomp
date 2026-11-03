#include "ov009/ov009.h"
#include "Main/Gfx/SlidePanel.h"

extern "C" {

extern void SndMgr_LoadHeapState(SndMgr *mgr, s32 a, s32 b);
extern void SceneCmd_Push25(FieldState *g, s32 a);

void Ov009ActVt_02217cb0_Init(Ov009ActVt_02217cb0 *self) {
    Ov003Actor_Init(self);
    SndMgr_LoadHeapState(gSndMgr, 1, 1);
    switch (self->kind) {
    case 0x504e:
    case 0x5056:
        self->unk_1a = 0;
        SceneCmd_Push25(gSceneCmd, 0xd);
        break;
    case 0x501b:
    case 0x5037:
        self->unk_1a = 1;
        SceneCmd_Push25(gSceneCmd, 0xe);
        break;
    }
    self->unk_ea |= 0x400;
}

}
