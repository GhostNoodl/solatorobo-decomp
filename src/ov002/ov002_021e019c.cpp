#include "ov002/ov002.h"

static inline void ov002_CamMove(Obj021efe6c *c, s32 px, s32 py, s32 pz, s32 tx, s32 ty, s32 tz) {
    c->unk_90 = 15;
    c->unk_94 = 15;
    c->unk_98 = c->cam->eye;
    c->unk_a4 = c->cam->at;
    c->unk_b0.x = px;
    c->unk_b0.y = py;
    c->unk_b0.z = pz;
    c->unk_bc.x = tx;
    c->unk_bc.y = ty;
    c->unk_bc.z = tz;
}

extern "C" {

void func_ov002_021e019c(Obj021eff30 *self, u8 a, u8 b) {
    s32 dx;
    s32 dy;
    s32 px;
    s32 py;
    s32 pz;
    s32 tx;
    s32 tz;
    Obj021efe6c *c;
    c = self->owner->board;
    dx = a - c->field->map->ox;
    dy = b - c->field->map->oy;
    px = *(s32 *)(data_ov002_021eef74 + 0x40);
    py = *(s32 *)(data_ov002_021eef74 + 0x44);
    pz = *(s32 *)(data_ov002_021eef74 + 0x48);
    tx = 0;
    tz = 0xa4;
    if (dy < -1) {
        pz -= 0x1ec;
        tz -= 0x1ec;
    } else if (dy > 1) {
        pz += 0x1ec;
        tz += 0x1ec;
    }
    if (dx < -1) {
        px -= 0x1ec;
        tx -= 0x1ec;
    } else if (dx > 1) {
        px += 0x1ec;
        tx += 0x1ec;
    }
    ov002_CamMove(c, px, py, pz, tx, 0, tz);
}

}
