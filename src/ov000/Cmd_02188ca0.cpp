#include "ov000/SceneCmd.h"
#include "Main/Snd/SndMgr.h"
#include "ov000/SceneCmdPool.h"

extern "C" {

void func_ov000_02188ca0(FieldId *id, s32 arg) {
    gSndQueue.queue->flag1 = 1;
    CmdObj_Push(data_ov000_021ccd50.scene, 9, arg);
    if (id != NULL) {
        data_ov000_021ccd50.scene->unk_cd = *id;
    }
}
}
