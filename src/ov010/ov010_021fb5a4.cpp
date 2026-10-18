#include "ov010/ov010.h"

extern "C" {

extern void func_ov003_021da40c(void *p);
extern void func_ov000_0218d7e8(void *self, u8 a);

void func_ov010_021fb5a4(void *self) {
    func_ov003_021da40c(FLD(void *, self, 0x40));
    func_ov000_0218d7e8(self, FLD(u8, FLD(u8 *, self, 0x40), 0x13));
}

}
