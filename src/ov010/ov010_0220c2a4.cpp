#include "ov010/ov010.h"

extern "C" {
extern void *data_02097e4c;
extern void *data_ov000_021ccd54;
extern void func_0203f324(void *p);
extern void func_ov000_021987b8(void *a, s32 b, s32 c, s32 d);
extern void func_ov000_0218d398(void *obj, u16 id, s32 a, s32 b, s32 c, u8 *d);
extern void func_ov000_0218dbe0(void *self, s32 a);
extern void *func_02049f44(void *a, s32 b, void *c, s32 d);
extern Ov010V *func_02065f88(s32 a, void *b);
extern void func_ov000_0219763c(void *self);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 mask, Ov010Vec *v, s32 e, s32 f, s32 g, s32 h, s32 i);

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
struct Ov010Rot3 {
    u16 x;
    u16 y;
    u16 z;
};
extern u8 data_ov010_0220f534[];
extern void func_ov003_021da48c(void *p, s32 a);

void func_ov010_0220c49c(u8 *self) {
    s32 y;
    s32 z;
    s32 x;
    FLD(Ov010Flags8, self, 0xce).b0 = 0;
    FLD(Ov010Flags8, self, 0xce).b1 = 0;
    FLD(Ov010Flags8, self, 0xce).b2 = 0;
    FLD(Ov010Flags8, self, 0xce).b3 = 0;
    FLD(u8, self, 0xcf) = 0;
    FLD(u16, self, 0xd0) = 0xffff;
    FLD(u16, self, 0xd2) = 0xffff;
    FLD(u16, self, 0xd4) = 0;
    FLD(u16, self, 0xd6) = 0;
    FLD(s32, self, 0xd8) = 0;
    FLD(s32, self, 0xdc) = -1;
    FLD(s32, self, 0xe0) = 0;
    FLD(s32, self, 0xe4) = 0;
    FLD(s32, self, 0xe8) = 0;
    FLD(s32, self, 0xec) = 0;
    Ov010_VecCopy(&FLD(Ov010Vec, self, 0xf0), &FLD(Ov010Vec, data_ov010_0220f534, 0x60));
    x = FLD(Ov010Vec, self, 0xf0).x;
    y = FLD(Ov010Vec, self, 0xf0).y;
    z = FLD(Ov010Vec, self, 0xf0).z;
    Ov010_VecSet(&FLD(Ov010Vec, self, 0xfc), x, y, z);
    Ov010_VecSet(&FLD(Ov010Vec, self, 0x108), x, y, z);
    Ov010_VecSet(&FLD(Ov010Vec, self, 0x114), x, y, z);
    func_ov003_021da48c(self + 0x158, 0);
    func_ov003_021da48c(self + 0x16c, 0);
    FLD(u16, self, 0x180) = 0xffff;
    FLD(u16, self, 0x182) = 0xffff;
    Ov010_VecSet(&FLD(Ov010Vec, self, 0x184), x, y, z);
    {
        const Ov010Rot3 *s = &FLD(Ov010Rot3, data_ov010_0220f534, 0x10);
        u16 a, b, c;
        FLD(Ov010Rot3, self, 0x190).x = a = s->x;
        FLD(Ov010Rot3, self, 0x190).y = b = s->y;
        FLD(Ov010Rot3, self, 0x190).z = c = s->z;
        FLD(Ov010Rot3, self, 0x196).x = a;
        FLD(Ov010Rot3, self, 0x196).y = b;
        FLD(Ov010Rot3, self, 0x196).z = c;
    }
}

}
