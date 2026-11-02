#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d8b2c(Obj021efe9c *self, Vec2 *out) {
    out->x = self->unk_64;
    out->y = self->unk_68;
}

Ov002Shape *func_ov002_021d8b40(Obj021efe9c *self) {
    return &self->shape;
}

u8 func_ov002_021d8b48(Obj021efe9c *self) {
    return self->shape.rot;
}

void Ov002_MultVec33(void *a, void *b, void *c) {
    MTX_MultVec33((VecFx32 *)c, (MtxFx33 *)b, (VecFx32 *)a);
}

u8 func_ov002_021d8b74(Obj021efe9c *self) {
    return self->unk_4a;
}

void func_ov002_021d8b7c(Obj021efe9c *self) {
    if (self->unk_a4 == 0 && self->unk_ac == 1) {
        self->unk_a4 = 5;
        self->unk_a8 = 5;
        self->unk_ac = 6;
    }
}

void func_ov002_021d8ba4(Obj021efe9c *self) {
    if (self->unk_a4 == 0 && self->unk_ac == 2) {
        self->unk_a4 = 5;
        self->unk_a8 = 5;
        self->unk_ac = 7;
    }
}

void func_ov002_021d8bcc(Obj021efe9c *self) {
    if (self->unk_ac == 8) {
        return;
    }
    if (self->unk_a4 != 0) {
        return;
    }
    func_ov002_021e3b0c((s32 *)((u8 *)self + 0xbc), (s32 *)((u8 *)self + 0x54), (s32 *)((u8 *)self + 0x64));
    self->unk_bc.y = 0x400;
    self->unk_b0.x = 0xb33;
    self->unk_b0.z = 0;
    self->unk_b0.y = 0x400;
    self->unk_a4 = 0x14;
    self->unk_a8 = 0x14;
    self->unk_ac = 8;
}

}
