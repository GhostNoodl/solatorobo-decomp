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
void STD_CopyString(void *dst, void *src);
VObj *func_ov000_02176208(void);

static inline void ModelInit(u8 *m, void *s, void *nm) {
    func_02041218(m + 0x88);
    func_02041440(m, nm, 0);
    STD_CopyString(m + 0x2c, s);
}

class Model {
public:
    u8 data[0x160];
    static void *operator new(unsigned long size) { return func_0203dd9c(size); }
    Model(void *nm, void *s) {
        func_02041218(data + 0x88);
        func_02041440(data, nm, 0);
        STD_CopyString(data + 0x2c, s);
    }
};

void func_ov000_0215bd88(VObj *self) {
    LFLD(s32, self, 0x28) = self->vfunc_44();
    if (LFLD(s32, self, 0x14) != 0 && LFLD(u8 *, self, 0x10) == NULL) {
        if (LBIT(self, 0xc).b6 ? TRUE : FALSE) {
            LFLD(Model *, self, 0x10) = new Model(data_0208cb84, data_0208cc8c);
        } else {
            LFLD(Model *, self, 0x10) = new Model(data_0208cb74, data_0208cca0);
        }
        {
            void *a = func_02035d5c(LFLD(u8 *, self, 0x10) + 0x2c);
            func_020417e0(LFLD(u8 *, self, 0x10), func_02034d88(a, LFLD(u8 *, self, 0x10) + 0x4c));
        }
        LFLD(u32, LFLD(u8 *, self, 0x10), 0x6c) |= 2;
        func_02041d9c(LFLD(u8 *, self, 0x10), 0, 7);
    }
    if (LFLD(u32, self, 0xc) & 0x10000) {
        LFLD(s16, self, 0x64) = (0x100 - LFLD(s32, self, 0x24)) >> 1;
    }
    if (LFLD(u32, self, 0xc) & 0x20000) {
        LFLD(s16, self, 0x66) = (0xc0 - LFLD(s32, self, 0x28)) >> 1;
    }
    LBIT(self, 0xc).b0 = 1;
}

}
