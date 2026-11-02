#include "ov002/ov002.h"

extern "C" {

void func_ov002_021df7b4(Obj021efe9c *self, Vec2 *pos) {
    u16 y = pos->y;
    u16 x = pos->x;
    self->unk_54 = x;
    self->unk_58 = y;
    func_ov002_021e3b0c(&self->trans.x, &self->unk_54, &self->unk_64);
}

}
