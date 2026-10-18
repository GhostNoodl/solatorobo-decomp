#include "ov006/ov006.h"

typedef struct ov006_Unk021cf350 {
    void *vtbl;
    u32 unk4_0 : 7;
    u32 unk4_7 : 1;
    u32 unk4_8 : 24;
} ov006_Unk021cf350;

extern "C" {

void func_ov006_021cf350(ov006_Unk021cf350 *self) {
    self->unk4_7 = 1;
}

}
