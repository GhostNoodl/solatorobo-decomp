#include "ov006/ov006.h"

typedef struct ov006_Unk021dcc9c {
    u8 unk0[4];
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;
    u8 unk5;
} ov006_Unk021dcc9c;

extern "C" {

void func_ov006_021dcc9c(ov006_Unk021dcc9c *self, int idx, u8 flag) {
    if (idx < 0 || idx > 4) {
        return;
    }
    self->unk5 = idx;
    self->b2 = flag;
}

}
