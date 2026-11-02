#include "ov009/ov009.h"

extern "C" {

extern void func_ov000_021911c8(Model0218fe1c *model, s16 a);
extern Ov003Actor *func_ov000_0219bf90(void);
extern void func_ov000_02199f48(void *p, Ov003Actor *a);

void Ov009ActVt_02217c04_StateDie(Ov009ActVt_02217c04 *self) {
    if (self->fsm->st == 0) {
        self->radius += self->radius >> 1;
        func_ov000_021911c8(self->model, 0x400);
        func_ov000_02199f48(self->hp, func_ov000_0219bf90());
    }
    Ov003Actor_StateDie(self);
    self->pos.y -= 0x29;
}

}
