#include "ov002/ov002.h"

extern "C" {

void func_ov002_021e1cc8(Ov002Hud *self) {
    self->unk_04 = NULL;
    self->unk_08 = NULL;
    self->unk_0c = NULL;
    self->unk_10 = NULL;
    MIi_CpuClear32(0, self->captions, 0x14);
    self->info = NULL;
    MI_CpuFill8(self->unk_2c[0], 0, 10);
    MI_CpuFill8(self->unk_2c[1], 0, 10);
    self->row = 0;
    self->pending = 0;
}

}
