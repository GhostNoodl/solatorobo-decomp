#include "types.h"

typedef void (*VFunc)(void *);

extern void func_0203de1c(void *p);
extern void *func_ov000_0218ea20(void *p);
extern void *func_ov000_0218fee4(void *p);
extern void *func_ov000_0219429c(void *p);

void *Ov003ActVt_021f98cc_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f98cc_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *Ov003ActVt_021f9834_Dtor(void *self) {
    func_ov000_0218fee4((u8 *)self + 0x208);
    func_ov000_0218ea20((u8 *)self + 0xd0);
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f9834_DtorDelete(void *self) {
    func_ov000_0218fee4((u8 *)self + 0x208);
    func_ov000_0218ea20((u8 *)self + 0xd0);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *Ov003ActVt_021f9704_Dtor(void *self) {
    func_ov000_0218fee4((u8 *)self + 0x208);
    func_ov000_0218ea20((u8 *)self + 0xd0);
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f9704_DtorDelete(void *self) {
    func_ov000_0218fee4((u8 *)self + 0x208);
    func_ov000_0218ea20((u8 *)self + 0xd0);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

void *Ov003ActVt_021f979c_Dtor(void *self) {
    func_ov000_0218fee4((u8 *)self + 0x208);
    func_ov000_0218ea20((u8 *)self + 0xd0);
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f979c_DtorDelete(void *self) {
    func_ov000_0218fee4((u8 *)self + 0x208);
    func_ov000_0218ea20((u8 *)self + 0xd0);
    func_ov000_0219429c(self);
    func_0203de1c(self);
    return self;
}

