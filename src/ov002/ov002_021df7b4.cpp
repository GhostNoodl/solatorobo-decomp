#include "ov002/ov002.h"

extern "C" {

void Obj021efe9c_SetCell(Obj021efe9c *self, Vec2 *pos) {
    u16 y = pos->y;
    u16 x = pos->x;
    self->unk_54 = x;
    self->unk_58 = y;
    Ov002_CellToPos(&self->trans.x, &self->unk_54, &self->unk_64);
}

}
