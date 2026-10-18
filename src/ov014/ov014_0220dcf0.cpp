#include "ov014/ov014.h"

extern "C" {

extern void *data_0214a420;
extern u8 data_ov014_02217b44[];
extern void func_ov000_02194074(void *self);
extern void func_ov000_02194758(void *self);
extern void func_ov000_02194c08(void *self);
extern void func_02065804(void *a, void *b);
extern void func_0203f364(Ov014Sub48 *p);
extern void func_ov000_02191690(void *p);
extern void func_ov000_02191618(void *p);

void func_ov014_0220dcf0(void) {
}

#pragma force_active on
Ov014Actor *func_ov014_0220dcf4(Ov014Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov014_02217b44;
    FLD(void *, self, 0xd0) = NULL;
    FLD(u8, self, 0xd4) = 0;
    FLD(s16, self, 0xd6) = 0;
    FLD(s16, self, 0xd8) = 0;
    FLD(s16, self, 0xda) = 0;
    return self;
}
#pragma force_active reset

Ov014Actor *func_ov014_0220dd2c(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217b44;
    func_02065804(data_0214a420, FLD(void *, self, 0xd0));
    func_ov000_0219429c(self);
    return self;
}

Ov014Actor *func_ov014_0220dd64(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217b44;
    func_02065804(data_0214a420, FLD(void *, self, 0xd0));
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov014_0220dda4(Ov014Actor *self) {
    func_ov000_02194c08(self);
}

void func_ov014_0220ddb0(Ov014Actor *self) {
    Ov014Sub44 *n;
    Ov014Sub48 *m;
    func_ov000_02194758(self);
    n = self->unk_44;
    n->unk_22_0 = 0;
    n->unk_22_1 = 0;
    m = self->unk_48;
    m->unk_9a_0 = 0;
    m->unk_9a_3 = 0;
    func_0203f364(m);
    func_ov000_02198360(self->unk_40, 1, 0);
    func_ov000_02191690(self->unk_38);
    func_ov000_02191618(self->unk_38);
    FLD(u8, self, 0xd4) = self->unk_18 != 0 ? 1 : 0;
}

}
