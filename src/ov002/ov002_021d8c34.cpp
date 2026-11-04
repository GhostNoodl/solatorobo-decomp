#include "ov002/ov002.h"

extern "C" {


void Obj021efe9c_Rotate(Obj021efe9c *self, s32 d, Ov002Shape *arg) {
    s32 n;
    s32 r;
    if (self->unk_a4 != 0 && self->unk_ac != 1) {
        return;
    }
    n = self->shape.rot;
    self->unk_cc = n;
    n += d;
    r = (n < 0 ? -n : n) % 4;
    if (n < 0) {
        r = 4 - r;
    }
    self->shape.rot = (u8)r;
    Obj021efe9c_ClampToBoard(self, arg);
    Ov002_CellToPos((s32 *)((u8 *)self + 0x4), (s32 *)((u8 *)self + 0x54), (s32 *)((u8 *)self + 0x64));
    self->unk_c8 = ((d < 0 ? -d : d) % 4) * 0x3fff;
    if (d < 0) {
        self->unk_c8 = -self->unk_c8;
    }
    self->unk_a4 = 4;
    self->unk_a8 = 4;
    self->unk_ac = 5;
}

}
