#include "ov000/VObj.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
extern void *data_0208cca0;
extern void *data_0208ccc0;
void *func_0203dd9c(u32 size);
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_02041c20(void *model, s32 a, void *b);
void func_0201e520(void *dst, void *src);
void func_ov000_02173d9c(void);
void func_ov000_02173648(VObj *self);

static inline void Init(u8 *m, void *s, void *nm) {
    func_02041218(m + 0x88);
    func_02041440(m, nm, 0);
    func_0201e520(m + 0x2c, s);
}

void func_ov000_021738d4(VObj *self) {
    void *res;
    u8 *m;
    LFLD(u32, self, 4) &= ~2;
    if (self->vfunc_28() != 0) {
        return;
    }
    res = func_02034d88(func_02035d5c(data_0208cca0), data_0208ccc0);
    m = (u8 *)func_0203dd9c(0x160);
    if (m) {
        Init(m, data_0208cca0, data_0208ccc0);
    }
    LFLD(void *, self, 0x4c) = m;
    func_020417e0(m, res);
    LFLD(u32, LFLD(void *, self, 0x4c), 0x6c) |= 2;
    func_02041d9c(LFLD(void *, self, 0x4c), 0, 0);
    LFLD(void *, LFLD(void *, self, 0x4c), 0x158) = (void *)func_ov000_02173d9c;
    func_02041c20(LFLD(void *, self, 0x4c), 0, self);
    LFLD(s32, self, 0x3c) = -0xcd;
    func_ov000_02173648(self);
}

}
