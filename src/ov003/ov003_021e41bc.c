#include "types.h"

typedef struct {
    u8 unk_00[0xc];
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
} Ov003Part44;

typedef struct {
    u8 unk_00[0x44];
    Ov003Part44 *unk_44;
} Ov003Prop;

extern void func_ov000_02194758(void *self);

void func_ov003_021e41bc(Ov003Prop *self) {
    Ov003Part44 *p;
    func_ov000_02194758(self);
    p = self->unk_44;
    p->unk_0c = 0;
    p->unk_10 = -0x1800;
    p->unk_14 = 0x3000;
}
