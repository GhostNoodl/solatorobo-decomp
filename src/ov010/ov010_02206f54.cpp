#include "ov010/ov010.h"

extern "C" {

extern void *data_02097e4c;
extern void func_ov003_021d8a7c(void *p, s32 a);
extern void func_ov003_021d8afc(void *p);
extern void func_ov003_021d969c(void *p, s32 a);
extern void func_02049f44(void *a, s32 b, void *c, s32 d);
extern void func_ov010_0220d9c0(void *p, void *h);
extern BOOL func_ov010_0220da4c(void *p);
extern Ov010V *func_02065f88(s32 a, Ov010Vec *b);

static inline Ov010Vec Ov010_Center(void *self) {
    Ov010Vec p;
    p.x = FLD(s32, self, 0x70);
    p.y = FLD(s32, self, 0x74) + FLD(s32, self, 0x68) / 2;
    p.z = FLD(s32, self, 0x78);
    return p;
}

void func_ov010_02206f54(void *self) {
    FLD(u8, self, 0xf2) = 1;
    FLD(u8, self, 0xf1) = 1;
}

void func_ov010_02206f64(void *self) {
    FLD(u8, self, 0xf2) = 1;
    if (FLD(u16, FLD(void *, self, 0x40), 0) != 0) {
        return;
    }
    func_ov003_021d8a7c(FLD(void *, self, 0x118), 0);
    func_ov003_021d969c((u8 *)self + 0x160, 1);
    FLD(u16, FLD(void *, self, 0x40), 0)++;
    func_02049f44(data_02097e4c, FLD(s32, self, 0x144), (u8 *)self + 0x70, 0);
}

void func_ov010_02206fd0(void *self) {
    volatile u16 *m = FLD(volatile u16 *, self, 0x40);
    FLD(u8, self, 0xf2) = 1;
    if (m[0] != 0) {
        return;
    }
    m[0]++;
    func_ov003_021d8afc(FLD(void *, self, 0x118));
}

void func_ov010_02207004(void *self) {
    FLD(u8, self, 0xf2) = 1;
    if (FLD(u16, FLD(void *, self, 0x40), 0) == 0) {
        func_ov010_0220d9c0((u8 *)self + 0x174, FLD(void *, self, 0x114));
        FLD(u16, FLD(void *, self, 0x40), 0)++;
        return;
    }
    if (func_ov010_0220da4c((u8 *)self + 0x174)) {
        func_ov003_021d969c((u8 *)self + 0x160, 1);
    }
}

void func_ov010_02207064(void *self) {
    u16 *m = FLD(u16 *, self, 0x40);
    switch (m[0]) {
    case 0: {
        s32 sc = Ov010_FxMul(FLD(s32, self, 0x64), 0x1800);
        Ov010Vec q = Ov010_Center(self);
        Ov010V *fx = func_02065f88(0x196, &q);
        fx->v0c(sc);
        FLD(s32, fx, 0x3c) = 0x1000;
        func_02049f44(data_02097e4c, 0x44, (u8 *)self + 0x70, 0);
        FLD(u16, FLD(void *, self, 0x40), 0) = 1;
        break;
    }
    case 1:
        m[1]++;
        if (FLD(u16, FLD(void *, self, 0x40), 2) > 0x32) {
            FLD(u16, FLD(void *, self, 0x40), 2) = 0;
            FLD(u16, FLD(void *, self, 0x40), 0) = 2;
        }
        break;
    case 2:
        func_ov003_021d969c((u8 *)self + 0x160, 1);
        break;
    }
}

}
