#include "ov002/ov002.h"

extern "C" {

void func_ov002_021d7b80(Obj021efeb8 *self) {
    self->trans.x = 0;
    self->trans.z = 0;
    self->trans.y = -0x3000;
    self->unk_10 = 0;
    self->unk_12 = 0;
    self->unk_14 = 0;
    MTX_Identity33_((MtxFx33 *)((u8 *)self + 0x18));
    self->unk_3c = 0x1000;
    FIELD(self, 0x40, s32) = 0x1000;
    self->unk_44 = 0x1000;
    self->unk_48 = 0;
    self->unk_4a = 0;
    self->unk_4b = 0;
    MI_CpuFill8((u8 *)self + 0x4c, 0, 8);
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

void func_ov002_021d7c04(Obj021efeb8 *self) {
    u8 *info = func_0206ede8(self->unk_48);
    Ov002Shape *v;
    self->unk_4a = info[0] == 0x80 ? 2 : 1;
    v = func_02070dcc(self->unk_4b = info[1]);
    MI_CpuCopy8(v, &self->shape, sizeof(self->shape));
    func_ov002_021e38f8(self->unk_5c, v);
}

}
