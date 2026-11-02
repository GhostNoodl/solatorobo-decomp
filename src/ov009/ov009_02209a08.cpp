#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_022172b5[];
extern s16 *Model0218fe1c_SetAnimFrame(Model0218fe1c *m, s32 a);
extern void Model0218fe1c_ClearLoop(Model0218fe1c *model);
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);

void Ov009ActVt_02217594_StateHurt(Ov009ActVt_02217594 *self) {
    switch (self->fsm->st) {
    case 0: {
        ActorSub44 *s44;
        ActorSub48 *s48;
        switch (self->unk_1a) {
        case 0:
        case 1:
            Model0218fe1c_SetAnim(self->model, data_ov009_022172b5, 0x1000, 0);
            Model0218fe1c_SetAnimFrame(self->model, 0x49000);
            Model0218fe1c_ClearLoop(self->model);
            break;
        }
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        s48 = self->hit;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        HitSphere_Unlink_0203f364(s48);
        s48 = self->hit;
        s48->unk_9a_1 = 0;
        s48->unk_9a_4 = 0;
        s48 = self->hit;
        s48->unk_9a_2 = 0;
        s48->unk_9a_5 = 0;
        self->fsm->st++;
        break;
    }
    case 1:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            History_SetState(self->fsm, 1, 0);
            self->step = 0;
        }
        break;
    }
}

}
