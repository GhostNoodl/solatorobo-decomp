#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_022179b4[];
extern void Shared_SetEventActor(u16 kind, u16 id);
extern void StageVars_SetEventScript(s32 a);

void Ov009ActVt_02217aac_State20(Ov009ActVt_02217aac *self) {
    VecFx32 d;
    if (self->fsm->st == 0) {
        Model0218fe1c_SetAnim(self->model, data_ov009_022179b4, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        self->unk_f0 = self->pos;
        self->pos.y += 0xa000;
        self->fsm->st++;
        self->fsm->timer = 0;
    }
    if (VEC_Distance(&self->pos, &self->unk_f0) <= 0xf6) {
        self->pos = self->unk_f0;
        Shared_SetEventActor(self->kind, self->id);
        StageVars_SetEventScript(4);
        gSceneCmd->stageFlags = 1;
        History_SetState(self->fsm, 1, 0);
    }
    d.x = self->unk_f0.x - self->pos.x;
    d.y = self->unk_f0.y - self->pos.y;
    d.z = self->unk_f0.z - self->pos.z;
    VEC_Normalize(&d, &d);
    VEC_MultAdd(0xf6, &d, &self->pos, &self->pos);
}

}
