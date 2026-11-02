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

void Lo021ca9c4_Init(Lo021ca9c4 *self) {
    self->fadeLen = 0x1000;
    self->unk_3c = 0;
    self->unk_44 = 0;
    self->unk_48 = 0;
    self->unk_4c = 0;
    self->unk_50 = 0;
    self->unk_54 = 0;
    self->unk_58 = 0;
    self->unk_5c = 0xffff;
    TextWin_Init(&self->text[0]);
    TextWin_Init(&self->text[1]);
    TextWin_Init(&self->text[2]);
    TextWin_Init(&self->text[3]);
    TextWin_Init(&self->text[4]);
    TextWin_Init(&self->text[5]);
    self->unk_40 = 0xffff;
    self->unk_42 = 0xffff;
}

}
