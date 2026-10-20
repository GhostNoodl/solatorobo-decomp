#include "ov000/LoCommon.h"

extern "C" {

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
void func_02041c5c(void *m, void *fn);
void func_02041c20(void *m, s32 a, void *b);
void STD_CopyString(void *dst, void *src);
void func_ov000_02153c48(void *node, void *a, s32 b, s32 c, s32 d);
void func_ov000_0215a088(void *self);
void *func_ov000_02159998(void *self, u16 *msg, void *arr, u16 *cnt);

typedef s32 (*VFn9aac)(void *);


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

static inline BOOL LoadModel9aac(void *self) {
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

void func_ov000_02159aac(u8 *self) {
    s32 w2;
    u8 *n;
    s32 maxw;
    s32 x;
    s32 y;
    s32 lim;
    s32 w;
    u32 fl;

    maxw = 0;
    LFLD(s32, self, 0x20) = 1;
    for (n = LFLD(u8 *, self, 0x94); n != NULL; n = LFLD(u8 *, n, 0x2c)) {
        func_ov000_02153c48(n, LFLD(void *, self, 0x1c), 1, 0, 0);
        w = LFLD(s32, LFLD(u8 *, n, 0x1c), 0x44);
        if (w > maxw) {
            maxw = w;
        }
    }
    if (LFLD(s32, self, 0xd4) == -1) {
        LFLD(s32, self, 0xd4) = maxw + 0x14;
    }
    fl = LFLD(u32, self, 0xc);
    if (fl & 0x4000000) {
        if (!(fl & 0x8000000)) {
            LFLD(s32, self, 0x24) = -1;
        } else {
            LFLD(s32, self, 0x24) = LFLD(s32, self, 0xd4) + ((VObj *)self)->vfunc_30() * 2 - 8;
        }
    }
    if (LFLD(s32, self, 0x24) != -1) {
        lim = LFLD(s32, self, 0x24) - ((VObj *)self)->vfunc_30() * 2;
    } else {
        LFLD(s32, self, 0x24) = ((VObj *)self)->vfunc_30() * 2 - 8;
        lim = 9999;
    }
    y = 0;
    x = 0;
    for (n = LFLD(u8 *, self, 0x94); n != NULL; n = LFLD(u8 *, n, 0x2c)) {
        w2 = LFLD(s32, LFLD(u8 *, n, 0x1c), 0x44) + 0x14;
        if (x != 0 && x + w2 > lim) {
            x = 0;
            y += ((VObj *)self)->vfunc_40();
            LFLD(s32, self, 0x20)++;
        } else if (lim == 9999) {
            LFLD(s32, self, 0x24) += w2;
        }
        LFLD(s32, n, 0x14) = x;
        LFLD(s32, n, 0x18) = y;
        x += w2;
    }
    {
        s32 a = LFLD(s32, self, 0x20) * ((VObj *)self)->vfunc_40();
        s32 b = ((VObj *)self)->vfunc_34();
        LFLD(s32, self, 0x28) = a + b + ((VObj *)self)->vfunc_38();
    }
    if (LoadModel9aac(self)) {
        func_02041d9c(LFLD(void *, self, 0x10), 0, 8);
        func_02041d9c(LFLD(void *, self, 0x10), 0, 2);
        func_02041c5c(LFLD(void *, self, 0x10), (void *)func_ov000_02159998);
        func_02041c20(LFLD(void *, self, 0x10), 8, self);
        func_02041c20(LFLD(void *, self, 0x10), 2, self);
    }
    func_ov000_0215a088(self);
    fl = LFLD(u32, self, 0xc);
    if (fl & 0x10000000) {
        LFLD(s16, self, 0x64) = 2;
    } else if (fl & 0x20000000) {
        LFLD(s16, self, 0x64) = 0xfd - LFLD(s32, self, 0x24);
    }
    fl = LFLD(u32, self, 0xc);
    if (fl & 0x40000000) {
        LFLD(s16, self, 0x66) = 2;
    } else if (fl & 0x80000000) {
        LFLD(s16, self, 0x66) = 0xbd - LFLD(s32, self, 0x28);
    }
    LBIT(self, 0xc).b0 = 1;
}

}
