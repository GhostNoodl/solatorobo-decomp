#include "types.h"

typedef struct {
    u8 unk_00[0x18];
    s16 unk_18;
    s16 unk_1a;
    u8 unk_1c[0x2];
    s16 unk_1e;
    u8 unk_20[0x2c];
    u8 *unk_4c;
    u8 unk_50[0x2e];
    u16 unk_7e;
    u8 unk_80[0x18];
    u16 unk_98;
} Ov003Prop;

extern void func_ov000_02194758(void *self);

void func_ov003_021e3a90(Ov003Prop *self) {
    func_ov000_02194758(self);
    if (self->unk_18 >= self->unk_1a) {
        *self->unk_4c = 0x10;
        if (self->unk_1e == 0) {
            self->unk_7e += 0x8000;
        }
    }
    self->unk_98 = self->unk_7e;
}
