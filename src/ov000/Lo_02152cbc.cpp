#include "ov000/LoCommon.h"
#include "ov000/UiObj.h"

extern "C" {

extern void *SndMgr_PlayVolume(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *gSndMgr;
void StageVars_ClearChoice(void);
u32 Rand_GetGlobal(void);
extern const s16 FX_SinCosTable_[];
typedef BOOL (*LoMsgFn)(void *, void *);


void UiObj_Init(UiObj *self) {
    self->state = 0;
    self->owner = 0;
    self->flags = 0;
    self->model = 0;
    self->title = 0;
    self->caption = 0;
    self->scrollPos = 0;
    self->scrollLen = 0;
    self->font = 8;
    self->rows = 1;
    self->width = 0x80;
    self->height = 0;
    self->slideMode = 0;
    self->openTime = 0;
    self->openLen = 0xc000;
    self->openRatio = 0;
    self->fadeTime = 0;
    self->fadeLen = 0xc000;
    self->fadeRatio = 0;
    self->color = 0;
    self->unk_4a = 0xb;
    self->slideX = 0;
    self->slideY = 0;
    self->slideZ = 0;
    self->posX = 0;
    self->posY = 0;
    self->posZ = 0;
    self->unk_54 = 0x14;
    self->shape = 0;
    self->shapeCount = 0;
    self->child = 0;
    self->onState = 0;
    self->onDraw = 0;
    self->onDrawItem = 0;
}

}
