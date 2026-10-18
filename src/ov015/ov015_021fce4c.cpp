#include "ov015/ov015.h"

extern "C" {

void func_0204b420(void *p);

void *func_ov015_021fce4c(u8 *self) {
    func_0204b420(self + 0xc0);
    func_0204b420(self + 0x4);
    return self;
}

void *func_ov015_021fce6c(u8 *self) {
    func_0204b420(self + 0xc0);
    func_0204b420(self + 0x4);
    func_0203de1c(self);
    return self;
}

}
