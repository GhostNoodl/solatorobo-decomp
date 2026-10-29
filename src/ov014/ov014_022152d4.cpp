#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_02217f18[];
extern void *func_ov000_02194074(void *self);
extern void func_ov000_02194758(void *self);
extern BOOL func_ov000_02194c08(void *self);

void func_ov014_022152d4(Ov014Actor *self) {
    self->v08();
}

#pragma force_active on
Ov014Actor *func_ov014_022152e8(Ov014Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov014_02217f18;
    FLD(s32, self, 0xd0) = 0;
    FLD(s32, self, 0xd4) = 0;
    FLD(s32, self, 0xd8) = 0;
    FLD(s32, self, 0xdc) = 0;
    FLD(s32, self, 0xe0) = 0;
    FLD(s32, self, 0xe4) = 0;
    FLD(s16, self, 0xf0) = 0;
    FLD(s32, self, 0xe8) = 0;
    FLD(s32, self, 0xec) = 0;
    FLD(s32, self, 0xf4) = 0;
    return self;
}
#pragma force_active reset

void *func_ov014_02215334(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *func_ov014_02215348(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov014_02215364(Ov014Actor *self) {
    func_ov000_02194c08(self);
}

void func_ov014_02215370(Ov014Actor *self) {
    Ov014Sub44 *n;
    func_ov000_02194758(self);
    func_ov000_02198360(self->unk_40, 0xb, 0);
    self->unk_44->unk_10 = 0;
    n = self->unk_44;
    n->unk_22_0 = 0;
    n->unk_22_1 = 0;
    self->unk_48->unk_30 = 0x60000000;
    FLD(s32, self->unk_48, 0x4c) = 0x9000;
    FLD(Ov014Flags, self->unk_38, 0xc2).b4 = 0;
}

}
