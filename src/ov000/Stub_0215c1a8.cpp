#include "ov000/VObj.h"

extern "C" {

void func_ov000_0215c1a8(void *self, s32 *msg) {
    if (msg[0] == 0x10) {
        *(s32 *)self = msg[1];
    }
}

}
