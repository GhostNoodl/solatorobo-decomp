#include "ov012/ov012.h"

extern "C" {
void func_ov012_02208fd4(Ov012Actor *self) {
    if (self->unk_40->state == 0) {
        if (*self->unk_50 == 0) {
            if (self->unk_1a == 0) {
                func_02049f44(data_02097e4c, 0x603, &self->pos, 0);
            }
        } else {
            if (self->unk_1a == 0) {
                func_02049f44(data_02097e4c, 0x602, &self->pos, 0);
            }
        }
    }
    func_ov003_021d5900(self);
}
}

extern "C" {
void func_ov012_0220904c(Ov012Actor *self) {
    if (self->unk_40->state == 0 && self->unk_1a == 0) {
        func_02049f44(data_02097e4c, 0x602, &self->pos, 0);
    }
    func_ov003_021d4fd8(self);
}
}

extern "C" {
void func_ov012_02209098(Ov012Actor *self) {
    if (self->unk_40->state == 0 && self->unk_1a == 0) {
        func_02049f44(data_02097e4c, 0x603, &self->pos, 0);
    }
    func_ov003_021d5348(self);
}
}

extern "C" {
void func_ov012_022090e4(Ov012Actor *self) {
    if (self->unk_40->state == 0) {
        Ov012V *e;
        func_ov000_0218e8ec(data_ov000_021ccd68, 0x480e, 0x15);
        e = func_02065f88(0x69, &self->pos);
        if (e != NULL) {
            e->v0c(0x2400);
            e->v24(0, FLD(s32, self, 0x6c), 0);
        }
    }
    func_ov003_021d6054(self);
}
}

extern "C" {
void *func_ov012_02209164(void *self) {
    func_ov000_0218ea20((u8 *)self + 0xf0);
    func_ov003_021d0edc(self);
    return self;
}
}

extern "C" {
void *func_ov012_02209184(void *self) {
    func_ov000_0218ea20((u8 *)self + 0xf0);
    func_ov003_021d0edc(self);
    func_0203de1c(self);
    return self;
}
}

extern "C" {
void func_ov012_022091ac(Ov012Actor *self) {
    func_ov003_021d0fc0(self);
    func_02049564(data_02097e4c, 1, 1);
    func_02049678(data_02097e4c, 4, 7, -1);
}
}

extern "C" {
BOOL func_ov012_022091e4(Ov012Actor *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (r && !func_0204985c(data_02097e4c)) {
        r = FALSE;
    }
    return r;
}
}

extern "C" {
extern const u8 data_ov012_0220a8d0[];
extern const u8 data_ov012_0220a8c8[];
void func_ov012_02209214(Ov012Actor *self) {
    func_ov003_021d112c(self);
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov012_0220a8d0);
        return;
    }
    if (self->kind == 0x5036) {
        func_ov003_021d6bac(self, data_ov012_0220a8c8);
    }
}
}
