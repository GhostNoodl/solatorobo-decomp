#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/SceneRes.h"

extern "C" {

extern void *gDataRes;
extern void *gSndMgr;
void *DataRes_GetTable(void *a, s32 b);
u32 DataRes_GetCount(void *a, s32 b);
u32 Quest_GetOptFlags(u16 a);
u16 DataRes_ReadBitsAt_02059544(void *a, void *b, void *c, s32 d, s32 e);
BOOL StageRes_IsAllLoaded(void *p);
void TextWin_Init(void *p);
void *Task_FindById(s32 kind);
Robo021ca458 *ActorMgr_FindPlayer(void);
void *SndMgr_PlayVolume(void *p, s32 a, s32 b, s32 c, s32 d);

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
} LoBits8;

typedef struct {
    u32 y : 8;
    u32 a : 8;
    u32 x : 9;
    u32 b : 7;
    u32 unk_04;
} LoOam;

static inline BOOL LoIsLoaded24(void) {
    BOOL r = TRUE;
    if (!StageRes_IsAllLoaded(gSceneResSet.unk_08)) {
        r = FALSE;
    }
    return r;
}

BOOL Quest_AllCleared(void) {
    void *p = LFLD(void *, gDataRes, 0x4c);
    u8 *tbl = (u8 *)DataRes_GetTable(gDataRes, 1);
    u32 n = DataRes_GetCount(gDataRes, 1);
    u16 i;
    for (i = 0; i < n; i++) {
        u32 fl = Quest_GetOptFlags(LFLD(u16, tbl + i * 4, 2));
        if (!(fl & 0x100) && !(fl & 0x40)) {
            if (!DataRes_ReadBitsAt_02059544(gDataRes, (u8 *)p + 0x30, tbl, 0x301, i)) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

}
