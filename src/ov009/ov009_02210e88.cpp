#include "ov009/ov009.h"

extern "C" {

extern void func_ov000_021911c8(void *model, s32 a);
extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_02199f48(void *p, Ov009Actor *a);

void func_ov009_02210e88(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        self->unk_64 += self->unk_64 >> 1;
        func_ov000_021911c8(self->unk_38, 0x400);
        func_ov000_02199f48(self->unk_50, func_ov000_0219bf90());
    }
    func_ov003_021d6054(self);
    self->pos.y -= 0x29;
}

}
