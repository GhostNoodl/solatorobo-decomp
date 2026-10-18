#include "ov010/ov010.h"

class Ov010Cls;
typedef void (Ov010Cls::*Ov010Fn)();

struct Ov010StEnt {
    u8 key;
    Ov010Fn fn;
};

struct Ov010B2 {
    u8 a;
    u8 b;
};

extern "C" {

extern void func_ov003_021da40c(void *p);
extern void func_ov000_0218d7e8(void *self, u8 a);
extern BOOL func_ov003_021da03c(void *self);
extern void func_ov003_021d8fc0(void *p);
extern BOOL func_ov003_021d9878(void *p);
extern Ov010B2 func_ov003_021d9644(void *p);
extern void func_ov000_02198360(void *a, s32 b, s32 c);

void func_ov010_02204aac(void *self) {
    func_ov003_021da40c(FLD(void *, self, 0x40));
    func_ov000_0218d7e8(self, FLD(u8, FLD(u8 *, self, 0x40), 0x13));
}

void func_ov010_02204ad0(void) {
}

void func_ov010_02204ad4(void *self) {
    BOOL go = FALSE;
    FLD(Ov010Flags8, self, 0x93).b4 = 0;
    if (func_ov003_021da03c(self) || FLD(u8, self, 0xf2) != 0) {
        go = TRUE;
    }
    FLD(u8, self, 0xf2) = 0;
    if (!go) {
        return;
    }
    FLD(s32, self, 0xc4) = 0;
    FLD(Ov010Flags8, self, 0x93).b4 = 1;
    func_ov003_021d8fc0((u8 *)self + 0x160);
    if (func_ov003_021d9878((u8 *)self + 0x160)) {
        Ov010B2 r = func_ov003_021d9644((u8 *)self + 0x160);
        FLD(Ov010B2, self, 0x170) = r;
        func_ov000_02198360(FLD(void *, self, 0x40), r.a, 1);
    }
}

extern const Ov010StEnt data_ov010_0220f188[];
extern const Ov010Blk12 data_ov010_0220f0b4;
extern void func_ov003_021d3008(void *self);
extern u8 func_ov003_021cf408(void);
extern u8 *func_ov000_0219bf90(void);
extern void VEC_MultAdd(s32 a, const Ov010Vec *b, const Ov010Vec *c, Ov010Vec *out);
extern void func_ov010_0220d858(void *p);


void func_ov010_02204b74(Ov010Cls *self) {
    u32 i;
    u8 *pl;
    s16 *p;
    u8 key;
    key = FLD(u8, FLD(u8 *, self, 0x40), 0x13);
    for (i = 0; i < 6; i++) {
        if (key == data_ov010_0220f188[i].key && *(s32 *)&data_ov010_0220f188[i].fn != 0) {
            (self->*data_ov010_0220f188[i].fn)();
            break;
        }
    }
    func_ov003_021d3008(self);
    if (func_ov003_021cf408()) {
        FLD(u8, self, 0x15) = func_ov003_021cf408();
    }
    pl = func_ov000_0219bf90();
    if (pl != NULL) {
        Ov010_VecCopy(&FLD(Ov010Vec, pl, 0xb90), &FLD(Ov010Vec, self, 0x70));
        FLD(s32, pl, 0xb9c) = 0x800;
    }
    p = FLD(s16 *, self, 0x124);
    if (p != NULL) {
        Ov010Vec v;
        *(Ov010Blk12 *)&v = data_ov010_0220f0b4;
        func_ov003_021d9980(&v, p[0], &v);
        VEC_MultAdd(p[1], &v, &FLD(Ov010Vec, self, 0x70), &FLD(Ov010Vec, self, 0x70));
        p[1] = Ov010_FxMul(p[1], p[2]);
    }
    func_ov010_0220d858((u8 *)self + 0x174);
    ((Ov010V *)((u8 *)self + 0x1b0))->v0c();
    ((Ov010V *)((u8 *)self + 0x1dc))->v0c();
    if (FLD(Ov010V *, self, 0x118) != NULL) {
        FLD(Ov010V *, self, 0x118)->v0c();
    }
}

}
