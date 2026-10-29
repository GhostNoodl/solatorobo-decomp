#include "ov000/LoCommon.h"

extern "C" {

extern void *data_0208cb84;
extern void *data_0208cc8c;
extern void *data_0208cb74;
extern void *data_0208cca0;
extern void *data_0208cc88;
extern void *data_0208cc94;
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void func_02041c20(void *model, s32 a, void *b);
void func_02041c5c(void *model, void *cb);
void STD_CopyString(void *dst, void *src);
void *func_ov000_02160e28(void);

#define LO_MODEL_NEW(out, NAME, ARC)                 \
    do {                                             \
        u8 *m_ = (u8 *)func_0203dd9c(0x160);         \
        if (m_) {                                    \
            void *arc_;                              \
            void *name_;                             \
            name_ = NAME;                            \
            arc_ = ARC;                              \
            func_02041218(m_ + 0x88);                \
            func_02041440(m_, name_, 0);             \
            STD_CopyString(m_ + 0x2c, arc_);          \
        }                                            \
        out = m_;                                    \
    } while (0)

static inline BOOL EnsureModel(void *self) {
    if (LFLD(void *, self, 0x10)) {
        return TRUE;
    }
    if (LBIT(self, 0xc).b6 ? TRUE : FALSE) {
        LO_MODEL_NEW(LFLD(u8 *, self, 0x10), data_0208cb84, data_0208cc8c);
    } else {
        LO_MODEL_NEW(LFLD(u8 *, self, 0x10), data_0208cb74, data_0208cca0);
    }
    {
        void *a = func_02035d5c(LFLD(u8 *, self, 0x10) + 0x2c);
        void *b = func_02034d88(a, LFLD(u8 *, self, 0x10) + 0x4c);
        func_020417e0(LFLD(u8 *, self, 0x10), b);
    }
    LFLD(u32, LFLD(u8 *, self, 0x10), 0x6c) |= 2;
    func_02041d9c(LFLD(u8 *, self, 0x10), 0, 7);
    return TRUE;
}

void func_ov000_02160ff8(void *self) {
    LFLD(s32, self, 0x24) = 0x50;
    LFLD(s32, self, 0x28) = 0x1e;
    LFLD(u16, self, 0x64) = 0x80;
    LFLD(u16, self, 0x66) = 0x60;
    LFLD(s32, self, 0x2c) = 0;
    LFLD(u16, self, 0x48) = 0x294a;
    LO_MODEL_NEW(LFLD(u8 *, self, 0x84), data_0208cc88, data_0208cc94);
    func_020417e0(LFLD(u8 *, self, 0x84), func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88));
    LFLD(u32, LFLD(u8 *, self, 0x84), 0x6c) |= 2;
    func_02041d9c(LFLD(u8 *, self, 0x84), 0, 6);
    func_02041c20(LFLD(u8 *, self, 0x84), 6, self);
    func_02041d9c(LFLD(u8 *, self, 0x84), 0, 8);
    func_02041c5c(LFLD(u8 *, self, 0x84), (void *)func_ov000_02160e28);
    if (EnsureModel(self)) {
        func_02041d9c(LFLD(u8 *, self, 0x10), 0, 10);
        LFLD(u32, LFLD(u8 *, self, 0x10), 0x6c) |= 0x80000;
    }
}

}
