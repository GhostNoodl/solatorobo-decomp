#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#include "ov000/HeapScope.h"

extern "C" {

extern u8 data_ov000_021cc774[];
void func_ov000_0218fee4(void *p);
void func_ov000_0218ea20(void *p);
void func_ov000_021bd228(void *p);
void func_0203f2b8(void *p);
void func_ov000_0218c928(void *p);

u8 *func_ov000_0219c24c(u8 *self) {
    LFLD(void *, self, 0) = data_ov000_021cc774;
    HEAP_DELETE_FN(LFLD(void *, self, 0x998), func_ov000_0218fee4);
    HEAP_DELETE_FN(LFLD(void *, self, 0x99c), func_ov000_0218ea20);
    HEAP_DELETE_FN(LFLD(void *, self, 0x9b0), func_ov000_021bd228);
    HEAP_DELETE_FN(LFLD(void *, self, 0x9b4), func_ov000_021bd228);
    LFLD(s32, self, 0x38) = 0;
    LFLD(s32, self, 0x34) = 0;
    LFLD(s32, self, 0x48) = 0;
    func_ov000_0218ea20(self + 0x860);
    func_ov000_0218fee4(self + 0x778);
    func_0203f2b8(self + 0x6c0);
    func_ov000_0218ea20(self + 0x588);
    func_ov000_0218ea20(self + 0x450);
    func_ov000_0218fee4(self + 0x368);
    func_0203f2b8(self + 0x2cc);
    func_ov000_0218ea20(self + 0x194);
    func_ov000_0218fee4(self + 0xac);
    func_ov000_0218c928(self);
    return self;
}

u8 *func_ov000_0219c3c8(u8 *self) {
    LFLD(void *, self, 0) = data_ov000_021cc774;
    HEAP_DELETE_FN(LFLD(void *, self, 0x998), func_ov000_0218fee4);
    HEAP_DELETE_FN(LFLD(void *, self, 0x99c), func_ov000_0218ea20);
    HEAP_DELETE_FN(LFLD(void *, self, 0x9b0), func_ov000_021bd228);
    HEAP_DELETE_FN(LFLD(void *, self, 0x9b4), func_ov000_021bd228);
    LFLD(s32, self, 0x38) = 0;
    LFLD(s32, self, 0x34) = 0;
    LFLD(s32, self, 0x48) = 0;
    func_ov000_0218ea20(self + 0x860);
    func_ov000_0218fee4(self + 0x778);
    func_0203f2b8(self + 0x6c0);
    func_ov000_0218ea20(self + 0x588);
    func_ov000_0218ea20(self + 0x450);
    func_ov000_0218fee4(self + 0x368);
    func_0203f2b8(self + 0x2cc);
    func_ov000_0218ea20(self + 0x194);
    func_ov000_0218fee4(self + 0xac);
    func_ov000_0218c928(self);
    func_0203de1c(self);
    return self;
}

}
