#include "ov002/ov002.h"

extern "C" {

typedef struct {
    u16 lo : 8;
    u16 rot : 2;
    u16 hi : 6;
} Rot7c54;


void Obj021efe9c_SetRot(Obj021efe9c *self, u16 rot) {
    self->shape.rot = rot;
    switch (rot) {
    case 0:
        self->unk_10 = 0;
        self->unk_12 = 0;
        self->unk_14 = 0;
        MTX_Identity33_(&self->rot);
        break;
    case 1:
        self->unk_10 = 0;
        self->unk_12 = 0x3fff;
        self->unk_14 = 0;
        MTX_Identity33_(&self->rot);
        MTX_RotY33_(&self->rot, FX_SINCOS(0x3ff * 2), FX_SINCOS(0x3ff * 2 + 1));
        break;
    case 2:
        self->unk_10 = 0;
        self->unk_12 = 0x7fff;
        self->unk_14 = 0;
        MTX_Identity33_(&self->rot);
        MTX_RotY33_(&self->rot, FX_SINCOS(0x7ff * 2), FX_SINCOS(0x7ff * 2 + 1));
        break;
    case 3:
        self->unk_10 = 0;
        self->unk_12 = 0xbffd;
        self->unk_14 = 0;
        MTX_Identity33_(&self->rot);
        MTX_RotY33_(&self->rot, FX_SINCOS(0xbff * 2), FX_SINCOS(0xbff * 2 + 1));
        break;
    }
}

void Obj021efe9c_ClampToBoard(Obj021efe9c *self, Ov002Shape *b) {
    Vec2 out;
    while (func_ov002_021e3dac((Vec2 *)&self->unk_54, b, &self->shape, &out)) {
        if (out.x < 0) {
            self->unk_54 -= out.x;
        } else if (out.x >= b->w) {
            self->unk_54 = self->unk_54 - (out.x + 1 - b->w);
        } else if (out.y < 0) {
            self->unk_58 -= out.y;
        } else if (out.y >= b->h) {
            self->unk_58 = self->unk_58 - (out.y + 1 - b->h);
        } else if (self->unk_54 != out.x) {
            self->unk_54 = self->unk_54 > out.x ? self->unk_54 + 1 : self->unk_54 - 1;
        } else {
            self->unk_58 = self->unk_58 > out.y ? self->unk_58 + 1 : self->unk_58 - 1;
        }
    }
}

}
