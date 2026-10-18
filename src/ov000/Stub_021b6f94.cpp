#include "ov000/VObj.h"

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    u8 unk_28[0x54];
    s32 unk_7c;
    s32 unk_80;
    s32 unk_84;
    u8 unk_88[0x24];
    s32 unk_ac;
    s32 unk_b0;
    s32 unk_b4;
    u16 unk_b8;
    u8 unk_ba;
    u8 unk_bb;
    u8 unk_bc;
    u8 unk_bd;
} Obj021b6f94;

extern "C" {

void MTX_Identity33_(void *mtx);
void func_0203df0c(void *p);

#define FREE_FIELD(f)          \
    if ((f) != 0) {            \
        func_0203df0c((void *)(f)); \
        (f) = 0;               \
    }

Obj021b6f94 *func_ov000_021b6f94(Obj021b6f94 *self) {
    self->unk_00 = 0;
    self->unk_04 = 0;
    self->unk_08 = 0;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
    self->unk_20 = 0;
    self->unk_24 = 0;
    self->unk_7c = 0;
    self->unk_80 = 0;
    self->unk_84 = 0;
    MTX_Identity33_(self->unk_88);
    self->unk_ac = 0x1000;
    self->unk_b0 = 0x1000;
    self->unk_b4 = 0x1000;
    self->unk_b8 = 0x1000;
    self->unk_ba = 0;
    self->unk_bb = 0;
    self->unk_bc = 0x1f;
    self->unk_bd = 0;
    return self;
}

Obj021b6f94 *func_ov000_021b700c(Obj021b6f94 *self) {
    FREE_FIELD(self->unk_04);
    FREE_FIELD(self->unk_08);
    FREE_FIELD(self->unk_0c);
    FREE_FIELD(self->unk_10);
    FREE_FIELD(self->unk_14);
    FREE_FIELD(self->unk_18);
    FREE_FIELD(self->unk_1c);
    FREE_FIELD(self->unk_24);
    return self;
}

}
