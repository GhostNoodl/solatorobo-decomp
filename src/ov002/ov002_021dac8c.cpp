#include "ov002/ov002.h"

extern "C" {

int func_ov002_021dac8c(void *self, void *arg) {
    void *p = FIELD(self, 0x8, void *);
    if (arg == NULL) {
        FIELD(p, 0x1c, u32) |= 2;
        return 1;
    }
    FIELD(p, 0x1c, u32) |= 1;
    return 1;
}

}
