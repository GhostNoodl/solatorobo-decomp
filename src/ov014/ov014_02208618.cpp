#include "ov014/ov014.h"

extern "C" {

extern u8 data_ov014_02217708[];
extern void func_ov000_02194074(void *self);
extern void func_ov000_02194758(void *self);
extern void func_0203f364(Ov014Sub48 *p);

#pragma force_active on
Ov014Actor *func_ov014_02208618(Ov014Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov014_02217708;
    FLD(s32, self, 0xd0) = 0;
    FLD(void *, self, 0xd8) = NULL;
    FLD(u8, self, 0xd4) = 0;
    return self;
}
#pragma force_active reset

Ov014Actor *func_ov014_02208648(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217708;
    Ov014_FreeFx(self, 0xd8);
    func_ov000_0219429c(self);
    return self;
}

Ov014Actor *func_ov014_022086b8(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217708;
    Ov014_FreeFx(self, 0xd8);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov014_02208730(Ov014Actor *self) {
    Ov014Sub48 *m;
    func_ov000_02194758(self);
    FLD(s32 *, self, 0xd8) = Ov014_NewFx();
    m = self->unk_48;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    self->unk_48->unk_30 = 0;
    func_ov000_02198360(self->unk_40, 0xb, 0);
}

void func_ov014_02208790(Ov014Actor *self) {
    func_ov000_021953b4(self);
    func_ov003_021dacfc(FLD(void *, self, 0xd8));
}

}
