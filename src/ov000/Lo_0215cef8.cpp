#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/PlttRes.h"

extern "C" {

extern void *gSndMgr;
extern void *gMsgRes;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL Model_IsReady(void *p, s32 a);
u16 StageId_Strip(u16 a);
s32 MsgRes_GetString(void *p, s32 a);
s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, s32 f);

void Lo021cad50_Init(Lo021cad50 *self) {
    s32 i;
    self->font = 4;
    self->unk_84 = 0x854;
    self->unk_88 = 0;
    self->unk_8c = NULL;
    self->unk_90 = NULL;
    self->unk_94 = 0;
    for (i = 0; i < 12; i++) {
        self->unk_98[i] = NULL;
    }
}

void Lo021cad50_Release(Lo021cad50 *self) {
    s32 i;
    for (i = 0; i < 12; i++) {
        u32 saved;
        VObj *p;
        LO_HEAP_PUSH(saved);
        p = self->unk_98[(u32)i];
        if (p != NULL) {
            if (p != NULL) {
                p->vfunc_04();
            }
            self->unk_98[i] = NULL;
        }
        LO_HEAP_POP(saved);
    }
    if (self->unk_8c != NULL) {
        Heap_FreeHi(self->unk_8c);
        self->unk_8c = NULL;
    }
    if (self->unk_90 != NULL) {
        Heap_FreeHi(self->unk_90);
        self->unk_90 = NULL;
    }
}

}
