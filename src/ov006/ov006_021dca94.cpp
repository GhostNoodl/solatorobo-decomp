#include "ov006/Model.h"
#include "ov006/Racer.h"
#include "nitro/fx.h"

extern "C" {

void func_02041c18(Model *m, int a);

void Ov006Marker_Draw(Ov006Marker *self) {
    VecFx32 v;
    s32 y;
    s32 z;
    u32 x;
    if (!self->active) {
        return;
    }
    VEC_Add(&self->cur, &self->ofs, &v);
    y = v.y >> 12;
    x = v.x & ~0xfff;
    z = v.z;
    ov006_Model_SetPos(self->model, 0, x, y << 12);
    self->model->unk_150 = z;
    Model_PlayPart(self->model, 0x11);
    ov006_Model_SetPos(self->model, 0, x, (y - 12) << 12);
    self->model->unk_150 = z;
    if (!self->alt) {
        Model_PlayPart(self->model, (u16)(self->frame + 0xb));
    } else {
        func_02041c18(self->model, self->frame);
        Model_PlayPart(self->model, 0xf);
    }
}

}
