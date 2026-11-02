#include "types.h"

typedef void (*VFunc)(void *);

extern void Heap_Free(void *p);
extern u8 *func_ov000_0218c928(u8 *p);
extern void *func_ov000_0218ea20(void *p);
extern void *func_ov000_0218fee4(void *p);

void *Ov003ActVt_021fa5f8_Dtor(void *self) {
    func_ov000_0218fee4((u8 *)self + 0x1e8);
    func_ov000_0218ea20((u8 *)self + 0xb0);
    func_ov000_0218c928(self);
    return self;
}

void *Ov003ActVt_021fa5f8_DtorDelete(void *self) {
    func_ov000_0218fee4((u8 *)self + 0x1e8);
    func_ov000_0218ea20((u8 *)self + 0xb0);
    func_ov000_0218c928(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021fa5a0_Dtor(void *self) {
    func_ov000_0218fee4((u8 *)self + 0x1e8);
    func_ov000_0218ea20((u8 *)self + 0xb0);
    func_ov000_0218c928(self);
    return self;
}

void *Ov003ActVt_021fa5a0_DtorDelete(void *self) {
    func_ov000_0218fee4((u8 *)self + 0x1e8);
    func_ov000_0218ea20((u8 *)self + 0xb0);
    func_ov000_0218c928(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021fa548_Dtor(void *self) {
    func_ov000_0218ea20((u8 *)self + 0xb0);
    func_ov000_0218c928(self);
    return self;
}

void *Ov003ActVt_021fa548_DtorDelete(void *self) {
    func_ov000_0218ea20((u8 *)self + 0xb0);
    func_ov000_0218c928(self);
    Heap_Free(self);
    return self;
}

