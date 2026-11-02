#include "ov000/Actor.h"

extern "C" {

extern char data_ov000_021cc5e3[];
void func_ov000_021b0db0(Actor *self, s32 id);

void func_ov000_021b0860(Actor *self) {
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov000_021cc5e3, 0x89, 0);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
    case 1:
        func_ov000_021b0db0(self, 0);
        break;
    }
}

}
