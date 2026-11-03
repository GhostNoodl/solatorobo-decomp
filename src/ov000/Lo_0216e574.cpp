#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/LoTimer.h"

extern "C" {

void func_020627fc(s32 a);
void SceneStage_StartScript(void *p);
void SceneCmd_Push27(void *p, s32 a, s32 b, s32 c);

void LoTimer_Init(LoTimer *self) {
    self->flags = 0;
    self->state = 0;
    self->mode = 0;
    self->result = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->step = 1;
    self->time = 0;
    self->shownTime = 0;
    self->limit = 0;
    self->unk_28 = 0;
    self->slideTime = 0;
    self->slide = 0;
    self->unk_38 = 0;
    self->unk_3c = 0;
    self->unk_40 = 0;
    self->unk_44 = 0;
    self->unk_48 = 0;
    self->unk_4c = 0;
    self->unk_50 = 0;
}

}
