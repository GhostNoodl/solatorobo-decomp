#include "ov009/ov009.h"

extern "C" {

extern void func_ov000_021984f4(void *a, void *b, s32 c);

void func_ov009_02212668(Ov003Actor *self) {
    if (self->unk_44 == NULL) {
        return;
    }
    func_ov000_021984f4(self->unk_44, (u8 *)self + 0x11c, 0);
}

extern char data_ov009_022179b4[];
extern void func_ov000_021911c8(void *model, s32 a);

void func_ov009_0221268c(Ov009ActSpin *self) {
    VecFx32 d;
    s32 x, y, z;
    int s;
    x = self->unk_134.x;
    self->unk_f2 += 0x60;
    y = self->unk_134.y + OV009_SIN(self->unk_f2);
    z = self->unk_134.z;
    d.x = x - self->pos.x;
    d.y = y - self->pos.y;
    d.z = z - self->pos.z;
    VEC_MultAdd(0x7b, &d, &self->pos, &self->pos);
    func_ov000_02190cb0(self->model, data_ov009_022179b4, 0x2ab, 0);
    func_ov000_021915a0(self->model);
    func_ov000_021911c8(self->model, 0x99a);
}

}
