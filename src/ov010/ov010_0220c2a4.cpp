#include "ov010/ov010.h"

extern "C" {
extern void *data_02097e4c;
extern void *data_ov000_021ccd54;
extern void func_0203f324(void *p);
extern void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
extern void func_ov000_0218d398(void *obj, u16 id, s32 a, s32 b, s32 c, u8 *d);
extern void func_ov000_0218dbe0(void *self, s32 a);
extern void func_02049f44(void *a, s32 b, void *c, s32 d);
extern Ov010V *func_02065f88(s32 a, void *b);
extern void func_ov000_0219763c(void *self);
extern void func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, Ov010Vec *v, s32 e, s32 f, s32 g, s32 h, s32 i);

void func_ov010_0220c2a4(void *self) {
    void *m;
    switch (FLD(u16, FLD(void *, self, 0x40), 0)) {
    case 0:
        m = FLD(void *, self, 0x48);
        FLD(Ov010Flags, m, 0x9a).b0 = 1;
        FLD(Ov010Flags, m, 0x9a).b3 = 1;
        func_0203f324(m);
        m = FLD(void *, self, 0x44);
        FLD(Ov010Flags, m, 0x22).b0 = 0;
        FLD(Ov010Flags, m, 0x22).b1 = 0;
        FLD(s32, self, 0xa8) = 0x52;
        FLD(u16, FLD(void *, self, 0x40), 0)++;
        break;
    case 1:
        if (FLD(void *, self, 0x48) != NULL) {
            func_ov000_021987b8(FLD(void *, self, 0x48), 1, 0, 0);
            if (FLD(u32, FLD(void *, self, 0x48), 0x50) & 0x20000000) {
                u8 c = 1;
                func_ov000_0218d398(self, FLD(u16, self, 0xc), 0xe, 1, 1, &c);
            }
        }
        break;
    }
    func_ov000_0218dbe0(self, 0);
}

void func_ov010_0220c390(void *self) {
    if (FLD(u16, FLD(void *, self, 0x40), 0) == 0) {
        u8 *g;
        Ov010V *fx;
        if (FLD(u8, self, 0xcf) != 0) {
            func_02049f44(data_02097e4c, 0x19, (u8 *)self + 0x70, 0);
        }
        g = (u8 *)data_ov000_021ccd54;
        FLD(Ov010Flags8, g, 0x190).b2 = 1;
        FLD(Ov010Flags8, g, 0x190).b3 = 1;
        FLD(Ov010Flags8, g, 0x190).b4 = 1;
        g[0x18d] = 5;
        g[0x18e] = 0xf;
        g[0x18f] = 0xf;
        fx = func_02065f88(0x38f, (u8 *)self + 0x70);
        fx->v24(0, 0x800, 0);
        fx->v0c(0x1800);
    }
    func_ov000_0219763c(self);
    func_ov000_0219aae8(self, self, FLD(u16, FLD(void *, self, 0x4c), 0x8), FLD(u16, FLD(void *, self, 0x4c), 0xa), 2, NULL, 0, 0x1b33, 0, 0x57e, 0x1000);
}
}
