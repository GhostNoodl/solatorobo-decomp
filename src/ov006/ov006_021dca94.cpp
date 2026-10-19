#include "ov006/Model.h"
#include "nitro/fx.h"

typedef struct ov006_Marker021dca94 {
    void *vtbl;
    u8 active : 1;
    u8 unk4_1 : 1;
    u8 alt : 1;
    u8 unk4_3 : 5;
    u8 frame;
    u8 unk6[0xe];
    VecFx32 pos;
    VecFx32 ofs;
    ov006_Model *model;
} ov006_Marker021dca94;

extern "C" {

void func_02041c18(ov006_Model *m, int a);

void func_ov006_021dca94(void *p) {
    ov006_Marker021dca94 *self = (ov006_Marker021dca94 *)p;
    VecFx32 v;
    s32 y;
    s32 z;
    u32 x;
    if (!self->active) {
        return;
    }
    VEC_Add(&self->pos, &self->ofs, &v);
    y = v.y >> 12;
    x = v.x & ~0xfff;
    z = v.z;
    ov006_Model_SetPos(self->model, 0, x, y << 12);
    self->model->unk150 = z;
    ov006_Model_PlayPart(self->model, 0x11);
    ov006_Model_SetPos(self->model, 0, x, (y - 12) << 12);
    self->model->unk150 = z;
    if (!self->alt) {
        ov006_Model_PlayPart(self->model, (u16)(self->frame + 0xb));
    } else {
        func_02041c18(self->model, self->frame);
        ov006_Model_PlayPart(self->model, 0xf);
    }
}

}
