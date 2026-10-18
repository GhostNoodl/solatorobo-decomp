#include "types.h"

typedef struct {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02_0 : 3;
    u16 unk_02_3 : 1;
} Ov003PropDef;

typedef struct {
    u8 unk_00[0xb0];
    Ov003PropDef *unk_b0;
    u8 unk_b4[0x1c];
    s16 unk_d0;
} Ov003Prop;

extern BOOL func_ov000_021946f8(void *self);
extern BOOL func_ov000_0218f110(s16 *p);

BOOL func_ov003_021e2148(Ov003Prop *self) {
    BOOL r = func_ov000_021946f8(self);
    Ov003PropDef *def = self->unk_b0;
    if (def->unk_02_3 && def->unk_01 == 1 && self->unk_d0 >= 0) {
        if (!func_ov000_0218f110(&self->unk_d0)) {
            r = FALSE;
        }
    }
    return r;
}
