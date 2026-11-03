#include "ov000/TextList.h"

extern "C" {

extern const s16 FX_SinCosTable_[];
void func_ov000_021c67e4(TextList *self);
void func_ov000_021c69e4(TextList *self);

void func_ov000_021c6714(TextList *self) {
    if (self->state == 2) {
        s32 t;
        if (self->hidden) {
            self->state = 1;
        }
        func_ov000_021c67e4(self);
        t = (self->bounceTime + 1) % 60;
        self->bounceTime = t;
        self->bounce = (FX_SinCosTable_[((t * (0x10000 / 60)) >> 4) * 2] + 0x800) >> 12;
    }
    func_ov000_021c69e4(self);
    if (self->listFlags.raise) {
        if (++self->lift >= 6) {
            self->lift = 6;
        }
    } else {
        if (--self->lift < 0) {
            self->lift = 0;
        }
    }
}

}
