#include "types.h"
#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

extern "C" {
extern void *data_0208cca0;
extern void *data_0208cb74;
extern void *data_0208cc94;
extern void *data_0208cc88;
extern void *data_0208cb7c;
extern char data_0214b105[];
extern u8 data_ov000_021ccd74[];
void *func_0203dd9c(u32 size);
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void *STD_CopyString(void *dst, void *src);

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

void func_ov000_021bce90(void) {
    void *res;
    void *m;
    res = func_02034d88(func_02035d5c(data_0208cca0), data_0208cb74);
    LO_MODEL_NEW(m, data_0208cb74, data_0208cca0);
    LFLD(void *, data_ov000_021ccd74, 0xc) = m;
    func_020417e0(m, res);
    LFLD(u32, LFLD(void *, data_ov000_021ccd74, 0xc), 0x6c) |= 2;
    func_02041d9c(LFLD(void *, data_ov000_021ccd74, 0xc), 0, 0);
    func_02041d9c(LFLD(void *, data_ov000_021ccd74, 0xc), 0, 1);
    func_02041d9c(LFLD(void *, data_ov000_021ccd74, 0xc), 0, 2);
    func_02041d9c(LFLD(void *, data_ov000_021ccd74, 0xc), 0, 3);
    func_02041d9c(LFLD(void *, data_ov000_021ccd74, 0xc), 0, 0xf);
    res = func_02034d88(func_02035d5c(data_0208cc94), data_0208cc88);
    LO_MODEL_NEW(m, data_0208cc88, data_0208cc94);
    LFLD(void *, data_ov000_021ccd74, 0x14) = m;
    func_020417e0(m, res);
    LFLD(u32, LFLD(void *, data_ov000_021ccd74, 0x14), 0x6c) |= 2;
    func_02041d9c(LFLD(void *, data_ov000_021ccd74, 0x14), 0, 2);
    res = func_02034d88(func_02035d5c(data_0214b105), data_0208cb7c);
    LO_MODEL_NEW(m, data_0208cb7c, data_0214b105);
    LFLD(void *, data_ov000_021ccd74, 0x4) = m;
    func_020417e0(m, res);
    LFLD(u32, LFLD(void *, data_ov000_021ccd74, 0x4), 0x6c) |= 2;
    func_02041d9c(LFLD(void *, data_ov000_021ccd74, 0x4), 0, 6);
}
}
