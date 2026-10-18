#include "ov009/ov009.h"

extern "C" {

extern void func_ov009_0220189c(Ov009Actor *self);
extern void func_ov009_02201eac(Ov009Actor *self);

void func_ov009_02201848(Ov009Actor *self) {
    if (self->unk_40->state == 0) {
        FLD(u16, self, 0xf0) = 0;
        FLD(u8, self, 0xf4) = 1;
    }
    func_ov003_021d3524(self);
}

void func_ov009_02201870(Ov009Actor *self) {
    switch (FLD(s8, self, 0xf5)) {
    case 0:
        func_ov009_0220189c(self);
        break;
    case 1:
        func_ov009_02201eac(self);
        break;
    }
}

}
