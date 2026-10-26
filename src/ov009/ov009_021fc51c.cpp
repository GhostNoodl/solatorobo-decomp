#include "ov009/ov009.h"

extern "C" {

extern void *data_02097e4c;
extern void func_0204a028(void *mgr, s32 id, const Ov009Vec *pos, s32 a);
extern void func_ov000_0218dbe0(Ov009Actor *self, s32 turn);

void func_ov009_021fc51c(Ov009Actor *self) {
    Ov009Sub40 *st;
    switch (Ov009Sub40_State(self->unk_40)) {
    case 0:
        self->unk_40->state++;
        if (self->unk_a8 == 0) {
            self->unk_a8 = 0x52;
        }
    case 1:
        if (self->unk_a0 < 0) {
            if (self->unk_48->unk_50 & 0x20000000) {
                if (self->unk_a0 < -0xcd) {
                    func_0204a028(data_02097e4c, 0x1e, &self->pos, 0xc);
                }
                func_ov000_02198360(self->unk_40, 1, 0);
                self->unk_a0 = 0;
                self->unk_a8 = 0;
                self->unk_a4 = 0x800;
            } else {
                st = self->unk_40;
                st->timer++;
                if (st->timer > 0x46) {
                    self->unk_40->timer = 0x46;
                    if (!(self->unk_48->unk_54 & 0x20000000)) {
                        func_ov000_02198360(self->unk_40, 0x15, 0);
                    }
                }
            }
        }
        break;
    }
    func_ov000_0218dbe0(self, 0);
    if (self->unk_48 != NULL) {
        func_ov000_021987b8(self->unk_48, 1, 0, 0);
    }
}

}
