#include "ov000/SceneCmd.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Res/StageVars.h"
#include "ov000/SceneCmdPool.h"
#include "ov000/ObjLayouts.h"

extern "C" {
extern void *gDataRes;
Robo021ca458 *ActorMgr_FindPlayer(void);
u16 DataRes_ReadEntry(void *a, int b, int c, int d);
u32 DataRes_GetCount(void *a, int idx);
void *DataRes_GetTable(void *a, int idx);
u16 DataRes_ReadBitsAt_02059544(void *a, void *b, void *c, u16 d, u16 e);
BOOL func_020624d8(void);

void func_ov000_02188d28(FieldId *id) {
    if (!ActorMgr_FindPlayer()) {
        CmdObj_Push(data_ov000_021ccd50.scene, 0xb, 0);
    }
    gSndQueue.queue->flag1 = 1;
    CmdObj_Push(data_ov000_021ccd50.scene, 0xa, 0);
    if (id != NULL) {
        data_ov000_021ccd50.scene->unk_cd = *id;
    }
}

BOOL func_ov000_02188dfc(void) {
    u8 *base;
    s32 n;
    u16 i;
    u16 *tbl;
    u32 count;
    if (DataRes_ReadEntry(gDataRes, 5, 1, 2) == 1) {
        return TRUE;
    }
    if (func_020624d8()) {
        n = 0;
        base = *(u8 **)((u8 *)gDataRes + 0x4c);
        tbl = (u16 *)DataRes_GetTable(gDataRes, 0);
        count = DataRes_GetCount(gDataRes, 0);
        for (i = 0; i < count; i++) {
            if (!DataRes_ReadBitsAt_02059544(gDataRes, base + 0x10, tbl, 1, i)) {
                if (data_02fe1534.unk_52 != tbl[i * 2 + 1]) {
                    n++;
                }
            }
        }
        if (n == 0) {
            return TRUE;
        }
    }
    return FALSE;
}
}
