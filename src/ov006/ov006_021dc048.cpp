#include "ov006/ov006.h"

typedef struct ov006_Unk021dc048 {
    u8 unk0[0xe8];
    u8 unkE8;
} ov006_Unk021dc048;

extern "C" {

void func_ov006_021dc048(ov006_Unk021dc048 *self) {
    self->unkE8 = 1;
}

}
