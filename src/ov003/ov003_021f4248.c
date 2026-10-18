#include "types.h"

typedef void (*VFunc)(void *);

extern void func_0203de1c(void *p);
extern void func_ov000_0218c928(void *p);
extern void func_ov000_0218ea20(void *p);
extern void func_ov000_0218fee4(void *p);

void *func_ov003_021f4248(void *self) {
    func_ov000_0218fee4((u8 *)self + 0x1e8);
    func_ov000_0218ea20((u8 *)self + 0xb0);
    func_ov000_0218c928(self);
    return self;
}

void *func_ov003_021f4270(void *self) {
    func_ov000_0218fee4((u8 *)self + 0x1e8);
    func_ov000_0218ea20((u8 *)self + 0xb0);
    func_ov000_0218c928(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021f42a0(void *self) {
    func_ov000_0218fee4((u8 *)self + 0x1e8);
    func_ov000_0218ea20((u8 *)self + 0xb0);
    func_ov000_0218c928(self);
    return self;
}

void *func_ov003_021f42c8(void *self) {
    func_ov000_0218fee4((u8 *)self + 0x1e8);
    func_ov000_0218ea20((u8 *)self + 0xb0);
    func_ov000_0218c928(self);
    func_0203de1c(self);
    return self;
}

void *func_ov003_021f42f8(void *self) {
    func_ov000_0218ea20((u8 *)self + 0xb0);
    func_ov000_0218c928(self);
    return self;
}

void *func_ov003_021f4318(void *self) {
    func_ov000_0218ea20((u8 *)self + 0xb0);
    func_ov000_0218c928(self);
    func_0203de1c(self);
    return self;
}

