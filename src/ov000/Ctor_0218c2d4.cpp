#include "ov000/LoCommon.h"
#include "ov000/ActorBase.h"
#include "types.h"


extern "C" {
extern u8 data_ov000_021cc3b4[];
void PauseNode_Init(void *p);

Actor *Actor_Ctor(Actor *self) {
    s32 i;
    VOBJ_SET_VTABLE(self, data_ov000_021cc3b4);
    PauseNode_Init(&self->pause);
    self->prev = NULL;
    self->next = NULL;
    self->id = 0xffff;
    self->kind = 0xffff;
    self->unk_20 = 0xffff;
    self->unk_10 = 0;
    self->state = 1;
    self->mode = 2;
    self->unk_16 = 0;
    self->unk_17 = 0xff;
    for (i = 0; i < 4; i++) {
        (&self->unk_18)[i] = 0;
    }
    self->unk_22 = -1;
    self->msgs = NULL;
    self->msg_flags = 0;
    self->unk_34 = NULL;
    self->model = NULL;
    self->unk_3c = NULL;
    self->fsm = NULL;
    self->unk_44 = NULL;
    self->hit = NULL;
    self->targetObj = NULL;
    self->hp = NULL;
    self->unk_54 = NULL;
    self->hitMesh = NULL;
    self->unk_5c = NULL;
    self->unk_60 = NULL;
    self->radius = 0;
    self->height = 0;
    self->centerY = 0;
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = 0;
    self->rot_x = 0;
    self->rot_y = 0;
    self->rot_z = 0;
    self->target = 0xffff;
    self->unk_92 = 0;
    self->unk_93 = 0;
    self->unk_94 = 0;
    self->unk_96 = 0;
    self->moveYaw = 0;
    self->speed = 0;
    self->velY = 0;
    self->friction = 0;
    self->gravity = 0;
    return self;
}
}
