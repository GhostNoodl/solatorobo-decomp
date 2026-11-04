#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/UiObj.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/PlttRes.h"
#include "Main/Gfx/TextWin.h"

extern "C" {

extern void *gSndMgr;
extern void *gMsgRes;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL Model_IsReady(void *p, s32 a);
u16 StageId_Strip(u16 a);
s32 MsgRes_GetString(void *p, s32 a);
s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, s32 f);

typedef struct {
    u8 pad[0x98];
    VObj *arr[12];
} LoArr98;

void Ov000Vt_021cb1b0_Release(LoBase021cafc0_021cb0b8 *self) {
    HEAP_DELETE(TextWin *, self->title2, p->unk_vf04());
}


void LoBase021cafc0_021cb0b8_PreUpdate(UiList *self) {
    switch (self->state) {
    case 0:
        self->openLen = 0x8000;
        SndMgr_PlayVolume(gSndMgr, 0x28, -1, -1, -1);
        break;
    case 1:
        self->openLen = 0x8000;
        SndMgr_PlayVolume(gSndMgr, 0x28, -1, -1, -1);
        break;
    }
}

}
