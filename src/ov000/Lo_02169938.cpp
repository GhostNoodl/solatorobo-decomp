#include "ov000/LoCommon.h"

extern "C" {

void func_ov000_0215eab4(void *p);

void func_ov000_02169938(void *self) {
    LO_FREE_M(self, 0xa4);
    LO_FREE_M(self, 0xa0);
    LBIT(self, 0xc).b3 = 0;
}

}
