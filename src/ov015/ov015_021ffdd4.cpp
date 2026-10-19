#include "ov015/ov015.h"

extern "C" {

BOOL func_ov015_0220a028(u8 *self, void *a);
void func_ov015_021fd00c(u8 *self, s32 mode, const Ov015VecC *v);
void func_ov015_02209790(u8 *self, s32 a);
void func_ov015_0221234c(u8 *self);
void func_ov015_022123c4(u8 *self);
void *func_ov015_021fffc4(u8 *self);
BOOL func_ov015_02209ff0(u8 *self, void *a);
Ov015V *func_02065f88(s32 id, void *pos);

struct Ov015Bits8a0 {
    u8 b0 : 2;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 rest : 3;
};
BOOL func_ov015_021ffdd4(u8 *self) {
    BOOL r = FALSE;
    u8 *found;
    u8 *n;
    if (FLD(u8, self, 0xc) != 0) return r;
    func_ov015_021fd00c(FLD(u8 *, self, 0x20), 7, (const Ov015VecC *)(FLD(u8 *, self, 0x10) + 0xc));
    VCALL(FLD(void *, self, 0x14))->v18();
    FLD(void *, self, 0x18) = func_ov015_021fffc4(self);
    if (VCALL(FLD(void *, self, 0x14))->v20() || FLD(void *, self, 0x18) != NULL) {
        if (FLD(void *, self, 0x18) != NULL) {
            u8 *p = FLD(u8 *, self, 0x20);
            FLD(u8, p, 0x9d) = 200;
            FLD(u8, p, 0x9e) = 20;
            FLD(u8, p, 0x9f) = 20;
            FLD(Ov015Bits8a0, p, 0xa0).b2 = 1;
            FLD(Ov015Bits8a0, p, 0xa0).b3 = 1;
            FLD(Ov015Bits8a0, p, 0xa0).b4 = 0;
            p = FLD(u8 *, self, 0x20);
            FLD(u8, p, 0x159) = 20;
            FLD(u8, p, 0x15a) = 20;
            FLD(u8, p, 0x15b) = 20;
            FLD(Ov015Bits8a0, p, 0x15c).b2 = 1;
            FLD(Ov015Bits8a0, p, 0x15c).b3 = 1;
            FLD(Ov015Bits8a0, p, 0x15c).b4 = 0;
        }
        r = TRUE;
    }
    found = NULL;
    n = FLD(u8 *, FLD(u8 *, self, 0x24), 0x4);
    while (n != NULL) {
        u8 *obj = FLD(u8 *, n, 0x4);
        Ov015Vec v;
        n = FLD(u8 *, n, 0xc);
        v = FLD(Ov015Vec, FLD(u8 *, self, 0x10), 0xc);
        if (func_ov015_0220a028(obj, &v)) {
            found = obj;
            break;
        }
    }
    if (found != NULL) {
        s32 d = Ov015_FxMul(FLD(s32, found, 0x70), 0x14000);
        Ov015VecC t(FLD(Ov015VecC, found, 0x40));
        t.y += d;
        if (t.y < 0) t.y = 0;
        FLD(Ov015VecC, FLD(u8 *, self, 0x10), 0x24) = t;
        func_ov015_0221234c(FLD(u8 *, self, 0x10));
    } else {
        func_ov015_022123c4(FLD(u8 *, self, 0x10));
    }
    FLD(u16, FLD(u8 *, self, 0x1c), 0xd3e) = 0x1000;
    for (n = FLD(u8 *, FLD(u8 *, self, 0x24), 0x4); n != NULL; n = FLD(u8 *, n, 0xc)) {
        func_ov015_02209790(FLD(u8 *, n, 0x4), 1);
    }
    return r;
}

BOOL func_ov015_021fffb0(Ov015Obj30 *self) {
    return self->unk_08 >= 2 ? TRUE : FALSE;
}

class Ov015Eff {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08(s32 a);
    virtual void v0c(s32 a);
    virtual void v10();
    virtual void v14(s32 x, s32 y, s32 z);
};
void *func_ov015_021fffc4(u8 *self) {
    u8 *found = NULL;
    u8 *n = FLD(u8 *, FLD(u8 *, self, 0x24), 0x4);
    while (n != NULL) {
        u8 *obj = FLD(u8 *, n, 0x4);
        n = FLD(u8 *, n, 0xc);
        if (func_ov015_02209ff0(obj, FLD(u8 *, self, 0x14) + 0x234)) {
            Ov015Vec v;
            Ov015Eff *e;
            v = FLD(Ov015Vec, FLD(u8 *, self, 0x14), 0x240);
            found = obj;
            e = (Ov015Eff *)func_02065f88(0x69, &v);
            e->v08(1);
            e->v14(0x5800, 0x5800, 0x5800);
            e = (Ov015Eff *)func_02065f88(0x69, &v);
            e->v08(1);
            e->v14(0x3800, 0x3800, 0x3800);
            e = (Ov015Eff *)func_02065f88(0x6c, &v);
            FLD(s32, e, 0x50) = -0x64000;
            e->v08(1);
            e->v14(0x6800, 0x6800, 0x6800);
            FLD(s32, e, 0x3c) = 0x1800;
            v.y += 0x5000;
            e = (Ov015Eff *)func_02065f88(0x44c, &v);
            e->v08(1);
            FLD(s32, e, 0x50) = -0xa000;
            e->v0c(0x1400);
            break;
        }
    }
    return found;
}

}
