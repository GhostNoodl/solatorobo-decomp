#include "ov012/ov012.h"

extern "C" {
void func_ov012_02207a38(Ov012ActEx_02207018 *self) {
    if (self->unk_d0 & 0x200000) {
        if (!func_ov003_021daa0c(((void *)self->unk_d4), 0xfe) && !func_ov003_021daa0c(((void *)self->unk_d4), 0xff)) {
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->v08();
        }
        func_ov003_021dacfc(((void *)self->unk_d4));
        return;
    }
    if (self->unk_40->state == 0) {
        self->unk_64 = 0x3000;
        func_ov003_021daa6c(((void *)self->unk_d4), 0xfa);
        func_02065f88(0x69, &self->pos)->v0c(0x2000);
    }
    func_ov000_0219763c(self);
}
}

extern "C" {
void *Ov012ActExVt_0220b150_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}
}

extern "C" {
void *Ov012ActExVt_0220b150_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}
}

extern "C" {
void *func_ov012_02207b24(void *self) {
    func_ov000_0218fee4((u8 *)self + 0x210);
    func_ov000_0218ea20((u8 *)self + 0xd8);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}
}

extern "C" {
void *func_ov012_02207b54(void *self) {
    func_ov000_0218fee4((u8 *)self + 0x210);
    func_ov000_0218ea20((u8 *)self + 0xd8);
    func_ov000_0219429c(self);
    return self;
}
}
