#include "ov000/VObj.h"
#include "ov000/HeapScope.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {

extern u8 data_0208b318[];
void func_ov000_021bd09c(void *self);
void func_ov000_0216faac(void *self);
void func_ov000_021bbcac(void *p);
void func_ov000_0216bf90(void *p);
void func_ov000_0217006c(void *p);
void __cxa_vec_cleanup(void *arr, int n, u32 size, void (*dtor)(void *));
void func_020507d8(void *p);
void func_ov000_0216ad34(void *p);
void func_ov000_0216b490(void *p);
void func_ov000_0216c9b0(void *p);
void func_ov000_0216e5d0(void *p);
void func_ov000_021b8800(void *p);
void func_ov000_021b88d8(void *p);
void func_ov000_021b8ecc(void *p);
void func_ov000_021bacf4(void *p);
void func_ov000_021bb840(void *p);

void func_ov000_0216fb14(u8 *self) {
    func_ov000_021bd09c(self);
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x28), p->vfunc_04());
    HEAP_DELETE_FN(LFLD(void *, self, 0x2c), func_020507d8);
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x30), p->vfunc_04());
    HEAP_DELETE_FN(LFLD(void *, self, 0x34), func_ov000_021b8800);
    HEAP_DELETE_FN(LFLD(void *, self, 0x38), func_ov000_021b88d8);
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x48), p->vfunc_04());
    HEAP_DELETE_FN(LFLD(void *, self, 0x3c), func_ov000_021b8ecc);
    HEAP_DELETE_FN(LFLD(void *, self, 0x40), func_ov000_021bacf4);
    HEAP_DELETE(u8 *, LFLD(u8 *, self, 0x44), func_ov000_021bbcac(p); *(void **)(p + 4) = data_0208b318; ((VObj *)(p + 4))->vfunc_0c(); func_0203de1c(p));
    HEAP_DELETE_FN(LFLD(void *, self, 0x4c), func_ov000_021bb840);
    HEAP_DELETE_FN(LFLD(void *, self, 0x50), func_ov000_0216c9b0);
    HEAP_DELETE_FN(LFLD(void *, self, 0x54), func_ov000_0216e5d0);
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x58), p->vfunc_04());
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x5c), p->vfunc_04());
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x60), p->vfunc_04());
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x64), p->vfunc_04());
    HEAP_DELETE_FN(LFLD(void *, self, 0x68), func_ov000_0216b490);
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x6c), p->vfunc_04());
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x70), p->vfunc_04());
    HEAP_DELETE(VObj *, LFLD(VObj *, self, 0x74), p->vfunc_04());
    HEAP_DELETE_FN(LFLD(void *, self, 0x78), func_ov000_0216ad34);
    HEAP_DELETE(u8 *, LFLD(u8 *, self, 0x7c), func_ov000_0216bf90(p); __cxa_vec_cleanup(p + 0x360, 0xa, 0xc, func_ov000_0217006c); func_0203de1c(p));
    func_ov000_0216faac(self);
}

}
