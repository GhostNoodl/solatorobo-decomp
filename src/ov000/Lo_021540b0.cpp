#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/SceneRes.h"
#include "Main/Gfx/TexObj.h"

extern "C" {

extern void *gDataRes;
extern void *gSndMgr;
void *DataRes_GetTable(void *a, s32 b);
u32 DataRes_GetCount(void *a, s32 b);
u32 func_ov000_0214bf2c(u16 a);
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

// The OAM callback of a UiList's frame model (UiList_Setup registers it with the list as the
// argument of entries 2 and 6): entry 2 places the bottom edge by the list's height.
LoOam *func_ov000_021540b0(TexObj *self, TexObjEntry *msg, LoOam *g, u16 *count) {
    u16 n = *count;
    if (msg->index == 2) {
        s32 v = ((UiList *)msg->unk_08)->height - 8;
        v -= 6;
        g[0].x = 0;
        g[0].y = (u16)v & 0x1ff;
        g[1].x = 0;
        g[1].y = 0xfc;
        n = 2;
    }
    *count = n;
    return g;
}

}
