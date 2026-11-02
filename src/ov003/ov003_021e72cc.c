#include "types.h"

typedef void (*VFunc)(void *);

extern void __cxa_vec_cleanup(void *arr, int count, int size, void *dtor);
extern void *func_ov000_0218fee4(void *p);
void *func_ov003_021e75bc(void *self);

extern void Heap_Free(void *p);
extern void func_0203f864(void *p);
extern void *func_ov000_0218ea20(void *p);
extern void *func_ov000_0219429c(void *p);

void func_ov003_021e72cc(void *self) {
    (*(VFunc *)(*(u32 *)self + 0x60))(self);
}

void func_ov003_021e72e0(void *self) {
    (*(VFunc *)(*(u32 *)self + 0x60))(self);
}

void *Ov003ActVt_021f8a60_Dtor(void *self) {
    func_ov000_0218ea20((u8 *)self + 0xd0);
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f8a60_DtorDelete(void *self) {
    func_ov000_0218ea20((u8 *)self + 0xd0);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f9050_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f9050_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f8638_Dtor(void *self) {
    func_ov000_0218ea20((u8 *)self + 0xd0);
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f8638_DtorDelete(void *self) {
    func_ov000_0218ea20((u8 *)self + 0xd0);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f8df0_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f8df0_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f8c28_Dtor(void *self) {
    func_ov000_0218ea20((u8 *)self + 0xd0);
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f8c28_DtorDelete(void *self) {
    func_ov000_0218ea20((u8 *)self + 0xd0);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f89c8_Dtor(void *self) {
    func_ov000_0218ea20((u8 *)self + 0xd0);
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f89c8_DtorDelete(void *self) {
    func_ov000_0218ea20((u8 *)self + 0xd0);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f8800_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f8800_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f8fb8_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f8fb8_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f8cc0_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f8cc0_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f8b90_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f8b90_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f8af8_Dtor(void *self) {
    __cxa_vec_cleanup((u8 *)self + 0x92c, 3, 0x98, func_ov003_021e75bc);
    __cxa_vec_cleanup((u8 *)self + 0x6cc, 4, 0x98, func_ov003_021e75bc);
    __cxa_vec_cleanup((u8 *)self + 0x46c, 4, 0x98, func_ov003_021e75bc);
    func_ov000_0218fee4((u8 *)self + 0x340);
    func_ov000_0218ea20((u8 *)self + 0x208);
    func_ov000_0218ea20((u8 *)self + 0xd0);
    func_ov000_0219429c(self);
    return self;
}

void *func_ov003_021e75bc(void *self) {
    func_0203f864(self);
    return self;
}

void *Ov003ActVt_021f8af8_DtorDelete(void *self) {
    __cxa_vec_cleanup((u8 *)self + 0x92c, 3, 0x98, func_ov003_021e75bc);
    __cxa_vec_cleanup((u8 *)self + 0x6cc, 4, 0x98, func_ov003_021e75bc);
    __cxa_vec_cleanup((u8 *)self + 0x46c, 4, 0x98, func_ov003_021e75bc);
    func_ov000_0218fee4((u8 *)self + 0x340);
    func_ov000_0218ea20((u8 *)self + 0x208);
    func_ov000_0218ea20((u8 *)self + 0xd0);
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f8930_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f8930_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f8898_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f8898_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f86d0_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f86d0_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f8f20_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f8f20_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f8e88_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f8e88_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

void *Ov003ActVt_021f8d58_Dtor(void *self) {
    func_ov000_0219429c(self);
    return self;
}

void *Ov003ActVt_021f8d58_DtorDelete(void *self) {
    func_ov000_0219429c(self);
    Heap_Free(self);
    return self;
}

