#include "ov000/LoCommon.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"
#include "ov000/MsgEntry.h"

extern "C" {

Robo021ca458 *ActorMgr_FindPlayer(void);
void func_020627fc(u16 a);
void func_0206280c(u16 a);
void SceneStage_StartScript(void *p);

void MsgEntry_Release(MsgEntry *self) {
    LO_FREE_V(self, 0x1c);
    LO_FREE_V(self, 0x20);
    self->unk_00 = 0;
    self->unk_04 = 0;
    self->id = 0;
    self->unk_08 = 0xffff;
    self->unk_0a = 0xffff;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = NULL;
    self->unk_20 = NULL;
    self->unk_24 = 0;
    self->prev = NULL;
    self->next = NULL;
}

}
