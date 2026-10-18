#include "types.h"

typedef struct {
    u8 unk_00[0x8b0];
    u8 unk_8b0[3];
    u8 unk_8b3;
} Ov003Save;

typedef struct {
    u8 unk_00[0xc1];
    u8 unk_c1;
} Ov003Model;

typedef struct {
    u8 unk_00[0x38];
    Ov003Model *unk_38;
    u8 unk_3c[0x4];
    void *unk_40;
} Ov003Prop;

extern Ov003Save *data_02097d48;
extern void func_02043d9c(void *p);
extern void func_ov000_02194c08(void *self);
extern void func_ov000_02194758(void *self);
extern void func_ov000_02198360(void *p, s32 a, s32 b);
extern void func_ov000_02191008(void *p);

void func_ov003_021e0b20(Ov003Prop *self) {
    Ov003Save *s = data_02097d48;
    u8 v = s->unk_8b3;
    func_02043d9c(s->unk_8b0);
    self->unk_38->unk_c1 = v;
    func_ov000_02194c08(self);
}

void func_ov003_021e0b54(Ov003Prop *self) {
    func_ov000_02194758(self);
    func_ov000_02198360(self->unk_40, 0x20, 0);
    func_ov000_02191008(self->unk_38);
}
