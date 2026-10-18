#include "ov006/ov006.h"

typedef struct ov006_Unk021dd2d8 {
    void *vtbl;
    u8 unk4;
    u8 unk5;
} ov006_Unk021dd2d8;

extern "C" {

void func_ov006_021dd2d8(ov006_Unk021dd2d8 *self, u8 value) {
    self->unk5 = value;
    self->unk4 = 4;
}

}
