#include "ov012/ov012.h"

extern "C" {
void func_ov012_02207a38(Ov012ActEx_02207018 *self) {
    if (self->unk_d0 & 0x200000) {
        if (!Ov003FxList_Has(self->fxList, 0xfe) && !Ov003FxList_Has(self->fxList, 0xff)) {
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->vfunc_08();
        }
        func_ov003_021dacfc(self->fxList);
        return;
    }
    if (self->fsm->st == 0) {
        self->radius = 0x3000;
        Ov003FxList_Kill(self->fxList, 0xfa);
        func_02065f88(0x69, &self->pos)->SetScaleAll(0x2000);
    }
    func_ov000_0219763c(self);
}
}

extern "C" {
Ov012ActExVt_0220b150 *Ov012ActExVt_0220b150_DtorDelete(Ov012ActExVt_0220b150 *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}
}

extern "C" {
Ov012ActExVt_0220b150 *Ov012ActExVt_0220b150_Dtor(Ov012ActExVt_0220b150 *self) {
    func_ov000_0219429c(self);
    return self;
}
}

extern "C" {
Ov012ActExVt_0220b1e8 *func_ov012_02207b24(Ov012ActExVt_0220b1e8 *self) {
    func_ov000_0218fee4(&self->mdl);
    func_ov000_0218ea20(&self->unk_d8);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}
}

extern "C" {
Ov012ActExVt_0220b1e8 *func_ov012_02207b54(Ov012ActExVt_0220b1e8 *self) {
    func_ov000_0218fee4(&self->mdl);
    func_ov000_0218ea20(&self->unk_d8);
    func_ov000_0219429c(self);
    return self;
}
}
