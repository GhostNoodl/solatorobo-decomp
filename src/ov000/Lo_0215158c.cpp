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

struct Obj0215158c {
    u8 unk_00[0x4];
    s32 unk_04;
};

void func_ov000_0215158c(Obj0215158c *self) {
    void *t = Task_FindById(0xe);
    Robo021ca458 *m;
    void *s;
    if (t == NULL) {
        return;
    }
    m = ActorMgr_FindPlayer();
    s = LFLD(void *, t, 0x50);
    switch (self->unk_04) {
    case 0:
        LFLD(u32, s, 0xc) |= 0x20;
        break;
    case 3:
        m->unk_b28_3 = 1;
        break;
    case 1:
        m->unk_b28_3 = 0;
        break;
    case 2:
        break;
    case 4:
        LFLD(u32, s, 0xc) &= ~0x20;
        break;
    }
}

}
