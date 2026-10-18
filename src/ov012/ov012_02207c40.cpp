#include "ov012/ov012.h"

extern "C" {
void func_ov012_02207b7c(Ov012Names *n, void *res);
void func_ov012_02207c40(Ov012Actor *self) {
    FLD(void *, self, 0xd8) = (void *)func_ov012_02207b7c;
    func_ov003_021d0fc0(self);
    func_ov000_0218f074((u8 *)self + 0xf0, func_0207011c((void *)0x480e), 1, 0, 0, 0);
    FLD(s16, self, 0xf0) = 0;
    func_02049564(data_02097e4c, 1, 1);
    if (self->kind == 0x5029 || self->kind == 0x5057) {
        self->unk_1a = 1;
        return;
    }
    func_02049678(data_02097e4c, 4, 6, -1);
    self->unk_1a = 0;
}
}

extern "C" {
BOOL func_ov012_02207cf0(Ov012Actor *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (FLD(s16, self, 0xf0) >= 0 && !func_ov000_0218f110((u8 *)self + 0xf0)) {
        r = FALSE;
    }
    if (r && !func_0204985c(data_02097e4c)) {
        r = FALSE;
    }
    return r;
}
}

extern "C" {
extern const u8 data_ov012_0220a870[];
extern const u8 data_ov012_0220a878[];
void func_ov012_02207d44(Ov012Actor *self) {
    func_ov003_021d112c(self);
    self->unk_ea_3 = 0;
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov012_0220a870);
        return;
    }
    if (self->kind == 0x5039 || self->kind == 0x5057) {
        func_ov003_021d6bac(self, data_ov012_0220a878);
    }
}
}
