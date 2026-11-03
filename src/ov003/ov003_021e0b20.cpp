#include "types.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ActorParts.h"
#include "Main/Gfx/GfxMgr.h"
#include "ov000/ObjLayouts.h"
#include "ov003/ActorApi.h"

extern "C" {

extern int func_02043d9c(void *p);
extern BOOL History_SetState(ActorSub40 *p, u8 a, BOOL b);
extern void Model0218fe1c_StopAnim(void *p);

void Ov003ActVt_021f8058_Draw(ActorEx *self) {
    GfxSys *s = data_02097d48;
    u8 v = s->unk_8b0[3];
    func_02043d9c(s->unk_8b0);
    self->model->polyId = v;
    ActorEx_Draw(self);
}

void Ov003ActVt_021f82b8_Start(ActorEx *self) {
    ActorEx_Start(self);
    History_SetState(self->fsm, 0x20, 0);
    Model0218fe1c_StopAnim(self->model);
}

extern char data_ov003_021f8531[];
extern BOOL Model0218fe1c_SetAnim(void *model, const void *name, s32 a, s32 b);
extern BOOL Model0218fe1c_IsAnimDone(void *model);
extern void Shared_SetEventActor(u16 a, u16 b);
extern void func_020627dc(s32 a);

void Ov003ActVt_021f82b8_State20(ActorEx *self) {
    switch (self->fsm->st) {
    case 0: {
        ActorSub44 *p;
        Model0218fe1c_SetAnim(self->model, data_ov003_021f8531, 0x1000, 0);
        p = self->unk_44;
        if (p != NULL) {
            p->unk_22_0 = 0;
            p->unk_22_1 = 0;
        }
        self->fsm->st++;
    }
    case 1: {
        ActorSub44 *p;
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        Shared_SetEventActor(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
        p = self->unk_44;
        if (p != NULL) {
            p->unk_22_0 = 1;
            p->unk_22_1 = 1;
        }
        History_SetState(self->fsm, 1, 0);
        break;
    }
    }
}

} // extern "C"
