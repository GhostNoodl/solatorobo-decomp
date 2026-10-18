#include "ov006/SlotManager.h"

typedef struct ov006_Prop6a6c {
    u8 unk0[0x19f];
    u8 unk19F;
} ov006_Prop6a6c;

extern "C" {

int func_ov000_0218d17c(ov006_Prop6a6c *self);
u8 func_ov006_021d8cb8(void);

static inline BOOL ov006_Prop_IsOver(ov006_Prop6a6c *self) {
    BOOL result = FALSE;
    if (self->unk19F > data_ov006_021ec884->unk8->unkB) {
        result = TRUE;
    }
    return result;
}

int func_ov006_021e6a6c(ov006_Prop6a6c *self) {
    int r = func_ov000_0218d17c(self);
    if (r != 0) {
        if (ov006_Prop_IsOver(self) || func_ov006_021d8cb8() <= 1) {
            r = 0;
        }
    }
    return r;
}

}
