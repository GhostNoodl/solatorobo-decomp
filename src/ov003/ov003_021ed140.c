#include "types.h"

typedef struct {
    u8 unk_00[0x60];
    void *unk_60;
} Ov003Obj;

extern u32 data_ov003_021f6c04;
extern void func_ov003_021dae58(void *self);

void func_ov003_021ed140(Ov003Obj *self) {
    func_ov003_021dae58(self);
    self->unk_60 = &data_ov003_021f6c04;
}
