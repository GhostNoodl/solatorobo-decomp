#include "ov013/ov013.h"

extern "C" {

extern void *data_ov013_0220bf4c;
extern void func_ov000_02194074(void *self);
extern void func_ov000_02194758(void *self);

void func_ov013_0220a428(Ov013Actor *self) {
    self->v80();
}

Ov013Actor *func_ov013_0220a43c(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov013Actor *func_ov013_0220a458(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

void func_ov013_0220a46c(Ov013Actor *self) {
    self->v7c();
}

Ov013Actor *func_ov013_0220a480(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov013Actor *func_ov013_0220a494(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov013Actor *func_ov013_0220a4b0(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    return self;
}

Ov013Actor *func_ov013_0220a4c4(Ov013Actor *self) {
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}

Ov013Actor *func_ov013_0220a4e0(Ov013Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = &data_ov013_0220bf4c;
    FLD(u16, self, 0xce) = 0;
    FLD(s32, self, 0xd0) = 0;
    FLD(s32, self, 0xd4) = 0;
    FLD(s32, self, 0xd8) = 0;
    FLD(s32, self, 0xdc) = 0;
    return self;
}

void func_ov013_0220a518(Ov013Actor *self) {
    func_ov000_02194758(self);
    func_ov000_02198360(self->unk_40, 0xb, 0);
    self->unk_48->unk_60 = -0x800;
    self->unk_48->unk_48 = self->unk_64;
}

}
