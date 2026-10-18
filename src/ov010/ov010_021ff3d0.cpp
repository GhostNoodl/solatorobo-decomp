#include "ov010/ov010.h"

extern "C" {

void func_ov010_021ff3d0(void *self, s32 *msg) {
    switch (msg[0]) {
    case 2:
        FLD(u8, self, 4) = (msg[1] == 1) ? TRUE : FALSE;
        break;
    case 3:
        FLD(s32, self, 8) = msg[1];
        break;
    }
}

}
