#include "ov006/Anim.h"

typedef struct ov006_Unk021e341c {
    u8 unk0[0x14];
    ov006_TextHolder *unk14;
} ov006_Unk021e341c;

extern "C" {

void func_ov006_021e341c(ov006_Unk021e341c *self, int a) {
    ov006_TextHolder_Play(self->unk14, a, 4);
}

}
