#include "ov000/LoCommon.h"
#include "ov000/ObjLayouts.h"
#include "ov000/Task.h"
#include "ov000/SceneRes.h"

extern "C" {

extern void *data_02fe152c;
extern void *data_02097e4c;
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
    if (!StageRes_IsAllLoaded(data_ov000_021ccd24.unk_08)) {
        r = FALSE;
    }
    return r;
}

void Lo021caa44_Draw(Lo021caa44 *self) {
    s32 s;
    if (self->fadeRatio == 0 || (s = self->state) == 0) {
        return;
    }
    if (s != 0xc && s != 0xd) {
        return;
    }
    if (self->unk_4c != NULL) {
        self->unk_4c->vfunc_20();
    }
    if ((VObj *)self->unk_50 != NULL) {
        ((VObj *)self->unk_50)->vfunc_20();
    }
    if (self->unk_5c != NULL) {
        self->unk_5c->vfunc_20();
    }
    self->vfunc_78();
    if (self->unk_60 != NULL) {
        self->unk_60->vfunc_20();
    }
}

}
