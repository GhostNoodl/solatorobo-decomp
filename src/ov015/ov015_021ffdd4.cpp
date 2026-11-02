#include "ov015/ov015.h"

extern "C" {

BOOL func_ov015_0220a028(Ov015Fish *self, void *a);
void func_ov015_021fd00c(Ov015CamPair *self, s32 mode, const Ov015VecC *v);
BOOL func_ov015_02209790(Ov015Fish *self, s32 a);
void func_ov015_0221234c(Ov015Obj292c *self);
void func_ov015_022123c4(Ov015Obj292c *self);
Ov015Fish *func_ov015_021fffc4(Ov015Obj30 *self);
BOOL func_ov015_02209ff0(Ov015Fish *self, void *a);
Ov015V *func_02065f88(s32 id, void *pos);

BOOL func_ov015_021ffdd4(Ov015Obj30 *self) {
    BOOL r = FALSE;
    Ov015Fish *found;
    u8 *n;
    if (self->unk_0c != 0) return r;
    func_ov015_021fd00c(self->unk_20, 7, (const Ov015VecC *)&self->unk_10->unk_0c);
    VCALL(self->unk_14)->v18();
    self->unk_18 = func_ov015_021fffc4(self);
    if (VCALL(self->unk_14)->v20() || self->unk_18 != NULL) {
        if (self->unk_18 != NULL) {
            Ov015CamPair *p = self->unk_20;
            p->cam0.unk_99 = 200;
            p->cam0.unk_9a = 20;
            p->cam0.unk_9b = 20;
            p->cam0.unk_9c.b2 = 1;
            p->cam0.unk_9c.b3 = 1;
            p->cam0.unk_9c.b4 = 0;
            p = self->unk_20;
            p->cam1.unk_99 = 20;
            p->cam1.unk_9a = 20;
            p->cam1.unk_9b = 20;
            p->cam1.unk_9c.b2 = 1;
            p->cam1.unk_9c.b3 = 1;
            p->cam1.unk_9c.b4 = 0;
        }
        r = TRUE;
    }
    found = NULL;
    n = FLD(u8 *, self->unk_24, 0x4);
    while (n != NULL) {
        Ov015Fish *obj = FLD(Ov015Fish *, n, 0x4);
        Ov015Vec v;
        n = FLD(u8 *, n, 0xc);
        v = self->unk_10->unk_0c;
        if (func_ov015_0220a028(obj, &v)) {
            found = obj;
            break;
        }
    }
    if (found != NULL) {
        s32 d = Ov015_FxMul(found->unk_70, 0x14000);
        Ov015VecC t(*(Ov015VecC *)&found->unk_40);
        t.y += d;
        if (t.y < 0) t.y = 0;
        FLD(Ov015VecC, self->unk_10, 0x24) = t;
        func_ov015_0221234c(self->unk_10);
    } else {
        func_ov015_022123c4(self->unk_10);
    }
    self->unk_1c->unk_d3e = 0x1000;
    for (n = FLD(u8 *, self->unk_24, 0x4); n != NULL; n = FLD(u8 *, n, 0xc)) {
        func_ov015_02209790(FLD(Ov015Fish *, n, 0x4), 1);
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
Ov015Fish *func_ov015_021fffc4(Ov015Obj30 *self) {
    Ov015Fish *found = NULL;
    u8 *n = FLD(u8 *, self->unk_24, 0x4);
    while (n != NULL) {
        Ov015Fish *obj = FLD(Ov015Fish *, n, 0x4);
        n = FLD(u8 *, n, 0xc);
        if (func_ov015_02209ff0(obj, &self->unk_14->unk_234)) {
            Ov015Vec v;
            Ov015Eff *e;
            v = FLD(Ov015Vec, self->unk_14, 0x240);
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
