#include "ov000/LoCommon.h"
#include "nitro/std.h"

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

LoGlyphEnt *func_ov000_02159998(void *self, u16 *msg, LoGlyphEnt *arr, u16 *cnt) {
    u16 n = *cnt;
    LoGlyphEnt *e = &arr[n - 1];
    if (*msg == 2) {
        u32 v = e[0].f;
        u32 fl = LFLD(u32, self, 0x70);
        n = 1;
        if (fl & 1) {
            arr[0].f = v;
        }
        if (fl & 2) {
            arr[0].f = v - 1;
        }
        if (fl & 0x400) {
            arr[0].f = v - 2;
        }
        if (fl & 0x800) {
            arr[0].f = v - 3;
        }
        if (fl & 0x200) {
            arr[0].f = v - 4;
        }
        if (fl & 0x100) {
            arr[0].f = v - 5;
        }
        arr[0].c = 0;
        arr[0].a = 0;
    }
    *cnt = n;
    return arr;
}

}
