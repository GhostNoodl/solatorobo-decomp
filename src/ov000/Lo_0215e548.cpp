#include "ov000/LoCommon.h"
#include "Main/Res/StageVars.h"
#include "ov000/UiObj.h"

extern "C" {

extern void *SndMgr_PlayVolume(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *gSndMgr;
void func_0206281c(void);
u32 Rand_GetGlobal(void);
extern const s16 FX_SinCosTable_[];
typedef BOOL (*LoMsgFn)(void *, void *);


BOOL Lo021cb0b8_OnDecide(UiList *self, void *msg) {
    LoMsgFn fn = ((LoMsgFn)self->onDecide);
    if (fn) {
        return fn(self, msg);
    }
    if (msg == NULL) {
        if (self->flags & 0x4000000) {
            SndMgr_PlayVolume(gSndMgr, 0x20, -1, -1, -1);
            return TRUE;
        }
        func_0206281c();
        SndMgr_PlayVolume(gSndMgr, 0x1f, -1, -1, -1);
        return FALSE;
    }
    data_02fe1534.unk_7c = LFLD(u16, msg, 6);
    SndMgr_PlayVolume(gSndMgr, 0x1e, -1, -1, -1);
    return FALSE;
}

}
