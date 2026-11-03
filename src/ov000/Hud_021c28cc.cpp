#include "types.h"
#include "ov000/ObjLayouts.h"
#include "Main/Gfx/Model.h"
#include "ov000/ModelPart.h"

extern "C" {

static inline void SetPos021c28cc(Model *o, s32 x, s32 y) {
    o->x = x;
    o->y = y;
}

// World position to screen cell coordinates; x and y are adjusted in place
static inline void ScreenPos021c28cc(s32 *ox, s32 *oy, s32 x, s32 y, s32 h) {
    x += 0xa000;
    y += (h - 8) << 12;
    *ox = (x >> 12) - 0x80;
    *oy = (y >> 12) - 0x60;
}

void Hud021cca10_Draw(Hud021cca10 *self) {
    s32 x;
    s32 y;
    Model *m;
    s32 z;
    Model *n;
    if (self->built == 0) {
        return;
    }
    if (!self->shown) {
        return;
    }
    ScreenPos021c28cc(&x, &y, self->x, self->y, self->height);
    z = self->z;
    SetPos021c28cc(self->unk_34, x << 12, (y + 7) << 12);
    self->unk_34->unk_150 = z;
    m = self->unk_34;
    Model_PlayPart(m, 4);
    SetPos021c28cc(self->unk_30, (x + 0x10) << 12, (y - 2) << 12);
    self->unk_30->unk_150 = z;
    n = self->unk_30;
    Model_PlayPart(n, 6);
    self->text->unk_vf20((self->x + 0x40000) >> 12, (self->y + ((self->height - (s32)self->text->height) << 11)) >> 12);
    self->text->posZ = z;
    self->text->Render();
}
}
