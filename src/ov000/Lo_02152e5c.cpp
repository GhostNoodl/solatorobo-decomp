#include "ov000/LoCommon.h"

typedef struct {
    u32 a : 8;
    u32 b : 8;
    u32 c : 9;
    u32 d : 7;
    u32 f : 10;
    u32 rest : 22;
} LoGlyphEnt;

extern "C" {

extern void *data_02149ef8;
void *func_0204c0e8(void *a, s32 b);
extern u8 data_ov000_021cac60[];
extern u8 data_ov000_021caec8[];
extern u8 data_ov000_021cb1b0[];
extern u8 data_ov000_021cb0b8[];
extern void *data_0208cb84;
extern void *data_0208cc8c;
extern void *data_0208cb74;
extern void *data_0208cca0;
void func_02041218(void *a);
void func_02041440(void *p, void *name, s32 c);
void *func_02035d5c(void *a);
void *func_02034d88(void *a, void *b);
void func_020417e0(void *model, void *a);
void func_02041d9c(void *model, s32 a, s32 b);
void STD_CopyString(void *dst, void *src);

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

BOOL func_ov000_02152e5c(void *self) {
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

}
