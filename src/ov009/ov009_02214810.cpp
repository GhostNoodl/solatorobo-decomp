#include "ov009/ov009.h"

extern "C" {

extern void func_ov000_02194758(Ov009Actor *self);

void func_ov009_02214810(Ov009Actor *self) {
    func_ov000_02194758(self);
    FLD(u16, self, 0xd0) = 0x5a;
    FLD(u16, self, 0xce) = 0xb4;
    FLD(u16, self, 0xd2) = 0xffff;
}

}
