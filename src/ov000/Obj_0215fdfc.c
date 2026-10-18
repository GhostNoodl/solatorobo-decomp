#include "types.h"

typedef struct {
    u8 unk_00[0xc];
    u32 unk_0c_0 : 7;
    u32 unk_0c_7 : 1;
    u32 unk_0c_8 : 24;
    void *unk_10[6];
    u8 unk_28[0x34];
    s32 unk_5c;
    s32 unk_60;
    s32 unk_64;
    s32 unk_68;
} Obj0215fdfc;

extern u8 data_ov000_021c9912[];

void func_ov000_0215fdfc(Obj0215fdfc *self, s32 index, void *entry) {
    if (entry == NULL) {
        entry = &data_ov000_021c9912[index * 6];
    }
    self->unk_10[index] = entry;
}

void func_ov000_0215fe1c(Obj0215fdfc *self, s32 lo, s32 hi) {
    self->unk_64 = lo << 12;
    self->unk_60 = hi << 12;
    if (self->unk_5c > self->unk_64) {
        self->unk_5c = self->unk_64;
    }
    if (self->unk_68 > self->unk_60) {
        self->unk_68 = self->unk_60;
    }
    if (!self->unk_0c_7) {
        self->unk_5c = self->unk_64;
    }
}
