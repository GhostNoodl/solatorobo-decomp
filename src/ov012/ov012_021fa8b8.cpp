#include "ov012/ov012.h"

extern "C" {
BOOL func_ov012_021fa8b8(Ov012Actor *self) {
    BOOL r = func_ov000_0218cf5c(self);
    r = (r & func_02035b90(data_ov012_0220aaf9, 7)) ? TRUE : FALSE;
    if (FLD(s16, self, 0xf0) == 1 && FLD(s16, self, 0x174) >= 0) {
        r = (r & func_ov000_0218f110((u8 *)self + 0x174)) ? TRUE : FALSE;
    }
    return r;
}
}

struct Ov012_021fa91c {
    u8 unk_00[0x324];
    Ov012Vec cur;
    u8 unk_330[0x64];
    Ov012Vec arr[2];
};
extern "C" {
BOOL func_ov012_021fa91c(Ov012Actor *self) {
    if (FLD(s16, self, 0xf0) == 1) {
        u8 i;
        for (i = 0; i < 2; i++) {
            ((Ov012_021fa91c *)self)->cur = ((Ov012_021fa91c *)self)->arr[i];
            func_ov000_021903b4((u8 *)self + 0x2ac);
        }
    }
    return func_ov003_021d16cc(self);
}
}

extern "C" {
void func_ov012_021fa978(Ov012Actor *self, Ov012Msg *msg) {
    switch (msg->type) {
    case 6:
        FLD(s16, self, 0x112) = msg->idx;
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        break;
    case 0xe:
        FLD(u16, self, 0x16c) = FLD(u16, msg, 6);
        FLD(u8, self, 0x3af) = FLD(s32, msg, 8);
        self->unk_30 |= 1 << msg->type;
        msg->type = 0;
        break;
    }
    func_ov003_021d1c00(self, msg);
}
}

struct Ov012_021fa9e8 {
    u8 unk_00[0x394];
    Ov012Vec arr[2];
    u8 unk_3ac[2];
};
extern "C" {
extern const u8 data_ov012_0220a498[];
extern const u8 data_ov012_0220a480[];
extern const Ov012Vec data_ov012_0220a4bc[];
extern const u8 data_ov012_0220a3f8[];

void func_ov012_021fa9e8(Ov012Actor *self) {
    Ov012Actor *o;
    Ov012Sub48 *m;
    func_ov003_021d112c(self);
    o = func_ov000_0218bd5c(data_ov000_021ccd64, self->unk_20);
    if (o != NULL) {
        FLD(Ov012Flags8, o, 0xa2).b0 = 0;
    }
    VEC_Add(&self->pos, data_ov012_0220a498, &self->pos);
    VEC_Add(&self->pos, data_ov012_0220a480, (u8 *)self + 0x100);
    FLD(Ov012Vec, self, 0xf4) = self->pos;
    self->pos.y -= 0x11000;
    m = self->unk_48;
    FLD(s32, m, 0x5c) = 0;
    FLD(s32, m, 0x60) = 0x3000;
    FLD(s32, m, 0x64) = 0;
    m = self->unk_48;
    m->unk_9a_1 = 0;
    m->unk_9a_4 = 0;
    m = self->unk_48;
    m->unk_9a_2 = 0;
    m->unk_9a_5 = 0;
    self->unk_48->unk_30 = 0;
    if (FLD(s16, self, 0xf0) == 1) {
        u8 i;
        for (i = 0; i < 2; i++) {
            ((Ov012_021fa9e8 *)self)->arr[i] = data_ov012_0220a4bc[i];
            ((Ov012_021fa9e8 *)self)->unk_3ac[i] = 0;
        }
        func_ov000_0218ffdc((u8 *)self + 0x2ac, (u8 *)self + 0x174, 0, 0);
        FLD(s32, self, 0x354) = 0x1000;
        FLD(s32, self, 0x358) = 0x1000;
        FLD(s32, self, 0x35c) = 0x1333;
        FLD(Ov012Flags, self, 0x36e).b0 = 1;
    }
    if (func_020621c4()) {
        func_ov003_021d6bac(self, data_ov012_0220a3f8);
        FLD(s16, self, 0x170) = 0x1800;
    }
}
}
