#include "ov014/ov014.h"

struct Ov014Vec16 {
    s16 x;
    s16 y;
    s16 z;
};

extern "C" {

extern void *data_0214a420;
extern u8 data_ov014_02217bdc[];
extern u8 data_ov014_02217b44[];
extern void func_ov000_02194074(void *self);
extern void func_ov000_02194758(void *self);
extern void func_ov000_02194c08(void *self);
extern void func_02065804(void *a, void *b);
extern Ov014Actor *func_ov000_0218d240(Ov014Actor *self);

void func_ov014_0220d6f8(Ov014Actor *self) {
    self->v7c();
}

#pragma force_active on
Ov014Actor *func_ov014_0220d70c(Ov014Actor *self) {
    func_ov000_02194074(self);
    FLD(void *, self, 0) = data_ov014_02217bdc;
    FLD(void *, self, 0xd0) = NULL;
    FLD(void *, self, 0xd4) = NULL;
    FLD(s16, self, 0xd8) = 0;
    FLD(s16, self, 0xda) = 0;
    FLD(s16, self, 0xdc) = 0;
    return self;
}
#pragma force_active reset

Ov014Actor *func_ov014_0220d744(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217bdc;
    if (FLD(void *, self, 0xd0) != NULL) {
        func_02065804(data_0214a420, FLD(void *, self, 0xd0));
    }
    if (FLD(void *, self, 0xd4) != NULL) {
        func_02065804(data_0214a420, FLD(void *, self, 0xd4));
    }
    func_ov000_0219429c(self);
    return self;
}

Ov014Actor *func_ov014_0220d79c(Ov014Actor *self) {
    FLD(void *, self, 0) = data_ov014_02217bdc;
    if (FLD(void *, self, 0xd0) != NULL) {
        func_02065804(data_0214a420, FLD(void *, self, 0xd0));
    }
    if (FLD(void *, self, 0xd4) != NULL) {
        func_02065804(data_0214a420, FLD(void *, self, 0xd4));
    }
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void func_ov014_0220d7fc(Ov014Actor *self) {
    func_ov000_02194c08(self);
}

void func_ov014_0220d808(Ov014Actor *self) {
    func_ov000_02194758(self);
    FLD(Ov014Vec16, self, 0xd8) = FLD(Ov014Vec16, self, 0x18);
    if (self->unk_1e == 0) {
        func_ov000_02198360(self->unk_40, 1, 0);
    } else {
        func_ov000_02198360(self->unk_40, 0xb, 0);
    }
    if (self->unk_90 != 0xffff) {
        Ov014Actor *a = func_ov000_0218d240(self);
        if (a != NULL) {
            self->unk_84 = a->pos;
        }
    }
}

}
