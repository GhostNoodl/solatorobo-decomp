#include "ov000/LoCommon.h"
#include "Main/Gfx/GfxMgr.h"
#include "Main/Gfx/PlttRes.h"
#include "ov000/ObjLayouts.h"

extern "C" {

extern void *data_02097e4c;
extern void *data_02149ef8;
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);
BOOL Model_IsReady(void *p, s32 a);
u16 func_02061d54(u16 a);
s32 MsgRes_GetString(void *p, s32 a);
void Obj0215c1bc_SetText(Lo021cad50 *self, s32 flags, s32 str);
s32 Text_Measure(s32 a, s32 b, s32 c, void *d, void *e, s32 f);

void Obj0215c1bc_SetMsg(Lo021cad50 *self, s32 id) {
    Obj0215c1bc_SetText(self, id, MsgRes_GetString(data_02149ef8, func_02061d54(id & 0x3ff)));
}

}
