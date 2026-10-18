#include "ov000/LoCommon.h"

extern "C" {
extern void *data_0208cb84;
extern void *data_0208cc8c;
extern void *data_0208cb74;
extern void *data_0208cca0;
extern void *data_0208cb78;
extern void *data_0208cc9c;
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_0201e520(void *dst, void *src);
VObj *func_ov000_02176208(void);

static inline void ModelInit(u8 *m, void *s, void *nm) {
    func_02041218(m + 0x88);
    func_02041440(m, nm, 0);
    func_0201e520(m + 0x2c, s);
}

class Model {
public:
    u8 data[0x160];
    static void *operator new(unsigned long size) { return func_0203dd9c(size); }
    Model(void *nm, void *s) {
        func_02041218(data + 0x88);
        func_02041440(data, nm, 0);
        func_0201e520(data + 0x2c, s);
    }
};

void func_ov000_0217abd8(VObj *self) {
    u8 *m;
    VObj *o;
    LFLD(u32, self, 4) &= ~2;
    if (self->vfunc_28() != 0) {
        return;
    }
    {
        LoCreateFn fn = LFLD(LoCreateFn, data_ov000_021ccd34, 0x18);
        if (fn == NULL) {
            LFLD(LoCreateFn, data_ov000_021ccd34, 0x18) = fn = (LoCreateFn)func_ov000_02176208;
        }
        o = (VObj *)fn();
    }
    LFLD(VObj *, self, 0x5c) = o;
    o->vfunc_08();
    m = (u8 *)func_0203dd9c(0x160);
    if (m) {
        ModelInit(m, data_0208cc9c, data_0208cb78);
    }
    LFLD(u8 *, self, 0xa0) = m;
    func_020417e0(LFLD(u8 *, self, 0xa0), func_02034d88(func_02035d5c(m + 0x2c), LFLD(u8 *, self, 0xa0) + 0x4c));
    LFLD(u32, LFLD(u8 *, self, 0xa0), 0x6c) |= 2;
    func_02041d9c(LFLD(u8 *, self, 0xa0), 0, 1);
    func_02041d9c(LFLD(u8 *, self, 0xa0), 0, 2);
    func_02041d9c(LFLD(u8 *, self, 0xa0), 0, 3);
    func_02041d9c(LFLD(u8 *, self, 0xa0), 0, 4);
    LFLD(u32, LFLD(u8 *, self, 0xa0), 0x6c) |= 0x200000;
    LFLD(u32, LFLD(u8 *, self, 0xa0), 0x6c) |= 0x80000;
    LFLD(u32, LFLD(u8 *, self, 0xa0), 0x6c) = (LFLD(u32, LFLD(u8 *, self, 0xa0), 0x6c) & ~0x7c) | 0x78;
    func_ov000_02173648(self);
    LFLD(u32, self, 4) |= 0x10000;
    if (LFLD(s32, self, 0x44) != 7) {
        LFLD(s32, self, 0x44) = 1;
        LFLD(s32, self, 0x48) = 0;
    }
}

}
