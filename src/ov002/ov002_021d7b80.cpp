#include "ov002/ov002.h"

extern "C" {

void Obj021efeb8_Init(Obj021efeb8 *self) {
    self->trans.x = 0;
    self->trans.z = 0;
    self->trans.y = -0x3000;
    self->unk_10 = 0;
    self->unk_12 = 0;
    self->unk_14 = 0;
    MTX_Identity33_(&self->rot);
    self->scale.x = 0x1000;
    self->scale.y = 0x1000;
    self->scale.z = 0x1000;
    self->unk_48 = 0;
    self->unk_4a = 0;
    self->unk_4b = 0;
    MI_CpuFill8(&self->shape, 0, 8);
    self->unk_54 = 0;
    self->unk_58 = 0;
    self->unk_5c[0] = 0;
    self->unk_5c[1] = 0;
    self->unk_64 = 0;
    self->unk_68 = 0;
    self->unk_6c = 0;
    self->next = NULL;
    self->prev = NULL;
}

void Ov002Vt_021efeb8_Setup(Obj021efeb8 *self) {
    u8 *info = Param_GetEntry(self->unk_48);
    Ov002Shape *v;
    self->unk_4a = info[0] == 0x80 ? 2 : 1;
    v = ParamKind_GetShape(self->unk_4b = info[1]);
    MI_CpuCopy8(v, &self->shape, sizeof(self->shape));
    Ov002Shape_GetOrigin(self->unk_5c, v);
}

}
