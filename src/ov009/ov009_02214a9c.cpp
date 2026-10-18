#include "ov009/ov009.h"

extern "C" {

void func_ov009_02214a9c(Ov009Actor *self) {
    FLD(u16, self, 0xd2) = 0xffff;
    func_ov000_02198360(self->unk_40, 4, 0);
}

}
