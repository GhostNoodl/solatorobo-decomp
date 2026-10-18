#include "ov006/Anim.h"

typedef struct ov006_Unk021e1e6c {
    u8 unk0[0x24];
    ov006_AnimHolder *unk24;
} ov006_Unk021e1e6c;

extern "C" {

void func_ov006_021e1e6c(ov006_Unk021e1e6c *self, int a) {
    ov006_AnimHolder_Play(self->unk24, a, 4);
}

}
