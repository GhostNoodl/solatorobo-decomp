#include "ov015/ov015.h"

extern "C" {

extern u8 data_ov015_02212f64[];
extern u8 data_ov015_02212f3c[];
void func_ov002_021e4cd8(void *self);
void *func_ov000_0218e9c4(void *a);
void *func_ov000_0218fe1c(void *a);
void func_ov002_021e4d4c(void *self);
void *func_ov000_0218fee4(void *a);
void *func_ov000_0218ea20(void *a);

void *func_ov015_0220dde8(Ov015StageMdl *self) {
    s32 i;
    SET_VT(self, data_ov015_02212f64);
    func_ov002_021e4cd8(self);
    SET_VT(self, data_ov015_02212f3c);
    func_ov000_0218e9c4(&self->res0);
    func_ov000_0218fe1c(&self->mdl0);
    func_ov000_0218e9c4(&self->res1);
    func_ov000_0218fe1c(&self->mdl1);
    self->unk_490 = 0x1000;
    self->slot = -1;
    self->unk_498 = 0xffff;
    self->unk_4d0.x = 0;
    self->unk_4d0.y = 0;
    self->unk_4d0.z = 0;
    MTX_Identity33_(&self->unk_4dc);
    self->unk_3a4 = 0;
    self->unk_500.x = 0x1000;
    self->unk_500.y = 0x1000;
    self->unk_500.z = 0x1000;
    self->unk_50c = 0x1000;
    self->unk_510 = NULL;
    self->unk_514 = NULL;
    for (i = 0; i < 8; i++) {
        self->slots[i].anim = NULL;
        self->slots[i].endTime = 0;
    }
    self->unk_518 = NULL;
    self->unk_51c = NULL;
    self->unk_520 = NULL;
    return self;
}

void *func_ov015_0220deb8(Ov015StageMdl *self) {
    func_ov000_0218fee4(&self->mdl1);
    func_ov000_0218ea20(&self->res1);
    func_ov000_0218fee4(&self->mdl0);
    func_ov000_0218ea20(&self->res0);
    SET_VT(self, data_ov015_02212f64);
    func_ov002_021e4d4c(self);
    return self;
}

void *func_ov015_0220defc(Ov015StageMdl *self) {
    func_ov000_0218fee4(&self->mdl1);
    func_ov000_0218ea20(&self->res1);
    func_ov000_0218fee4(&self->mdl0);
    func_ov000_0218ea20(&self->res0);
    SET_VT(self, data_ov015_02212f64);
    func_ov002_021e4d4c(self);
    Heap_Free(self);
    return self;
}

}
