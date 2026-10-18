#include "types.h"

class Mgr021b5054Cls;
typedef void (Mgr021b5054Cls::*Mgr021b5054Pmf)();

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Slot021b5054;

typedef struct {
    void *unk_00;
    u8 pad_04[4];
    u8 unk_08;
    u8 unk_09;
    u8 unk_0a;
    u8 unk_0b;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    u8 pad_24[0xc];
    u16 unk_30[0x20];
    Slot021b5054 unk_70[0x20];
    u16 unk_1f0;
    u16 unk_1f2;
    u8 unk_1f4[0x98];
    Mgr021b5054Pmf unk_28c;
} Mgr021b5054;


extern "C" {

extern u8 *data_ov000_021ccd54;
void func_0203db10(void *node);
void func_0203f80c(void *p);

Mgr021b5054 *func_ov000_021b5054(Mgr021b5054 *self) {
    s32 i;

    func_0203db10(self);
    func_0203f80c(self->unk_1f4);
    if (data_ov000_021ccd54 != NULL) {
        self->unk_00 = data_ov000_021ccd54 + 8;
    }
    self->unk_08 = 0;
    self->unk_0c = 0;
    self->unk_10 = 0;
    self->unk_14 = 0;
    self->unk_18 = 0;
    self->unk_1c = 0;
    self->unk_20 = 0;
    self->unk_09 = 0xff;
    self->unk_0a = 0xff;
    self->unk_0b = 0xff;
    for (i = 0; i < 0x20; i++) {
        self->unk_30[i] = 0xffff;
        self->unk_70[i].x = 0;
        self->unk_70[i].y = 0;
        self->unk_70[i].z = 0;
    }
    self->unk_1f0 = 0xffff;
    self->unk_28c = NULL;
    self->unk_1f2 = 0;
    return self;
}

}
