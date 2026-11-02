#include "ov015/ov015.h"

extern "C" {

extern u8 data_ov015_0221292c[];
void func_ov015_022120fc(Ov015Obj292c *self);
extern u8 data_ov015_022132e0[];
void func_ov015_02211a18(void);
void *func_ov000_0218fee4(void *p);
void *func_ov000_0218ea20(void *p);

void func_ov015_021ff350(Ov015Obj30 *self) {
    Ov015Obj30_Clear(self);
}

void func_ov015_021ff380(Ov015Obj30 *self) {
    u32 saved;
    HEAP_PUSH(saved);
    DELETE_V(self->unk_10);
    HEAP_POP(saved);
    HEAP_PUSH(saved);
    DELETE_V(self->unk_14);
    HEAP_POP(saved);
    Ov015Obj30_Clear(self);
}

void *func_ov015_021ff440(Ov015Obj292c *self) {
    SET_VT(self, data_ov015_0221292c);
    func_ov015_022120fc(self);
    func_0203de1c(self);
    return self;
}

void *func_ov015_021ff468(Ov015Obj290 *self) {
    SET_VT(self, data_ov015_022132e0);
    func_ov015_02211a18();
    func_ov000_0218fee4(&self->unk_14c);
    func_ov000_0218ea20(&self->unk_14);
    func_0203de1c(self);
    return self;
}

}
