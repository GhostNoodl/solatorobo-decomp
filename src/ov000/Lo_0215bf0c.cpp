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

typedef struct {
    u8 pad[0x98];
    VObj *arr[12];
} LoArr98;

void Lo021cadcc_Release(Lo021cadcc *self) {
    LO_FREE_V(self, 0x84);
}

}
