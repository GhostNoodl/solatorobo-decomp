#include "ov009/ov009.h"

extern "C" {

extern Ov009Actor *func_ov000_0219bf90(void);
extern void func_ov000_02199f48(void *p, Ov009Actor *a);
extern void func_ov003_021d6a3c(Ov009Actor *self, s32 a, s32 b, s32 c);

void func_ov009_02209b20(Ov009Actor *self) {
    if (self->unk_40->state != 0) {
        return;
    }
    func_ov000_02199f48(self->unk_50, func_ov000_0219bf90());
    func_ov003_021d6a3c(self, 0, 1, 1);
    self->unk_40->state++;
}

void func_ov009_02209b70(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        FLD(u8, self, 0x312) = 1;
    }
    switch (self->unk_1a) {
    case 0:
    case 1:
        self->unk_93_4 = 1;
        self->v64();
        break;
    case 2:
        self->unk_93_4 = 1;
        self->v68();
        break;
    }
}

}
