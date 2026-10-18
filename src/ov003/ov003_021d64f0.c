#include "types.h"

typedef struct {
    u8 pad_00[0xa];
    u16 unk_0a_0 : 5;
    u16 unk_0a_5 : 1;
    u16 unk_0a_6 : 10;
} Ov003Flags;

typedef struct {
    u8 pad_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 pad_10[0x30];
    void *unk_40;
    u8 pad_44[0x6c];
    Ov003Flags *unk_b0;
} Ov003Ev;

typedef struct {
    u8 pad_00[0xac];
    u8 unk_ac;
} Ov003G54;

extern Ov003G54 *data_ov000_021ccd54;
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_ov000_02198360(void *p, s32 a, s32 b);

void func_ov003_021d64f0(Ov003Ev *self) {
    if (self->unk_b0->unk_0a_5) {
        func_020627a0(self->unk_0e, self->unk_0c);
        func_020627dc(4);
        data_ov000_021ccd54->unk_ac = 1;
    }
    func_ov000_02198360(self->unk_40, 1, 0);
}
