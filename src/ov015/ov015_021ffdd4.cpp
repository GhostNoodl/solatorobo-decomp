#include "ov015/ov015.h"

extern "C" {

BOOL func_ov015_0220a028(Ov015Fish *self, void *a);
void func_ov015_021fd00c(Ov015CamPair *self, s32 mode, const Ov015Vec *v);
BOOL func_ov015_02209790(Ov015Fish *self, s32 a);
void func_ov015_0221234c(Ov015Obj292c *self);
void func_ov015_022123c4(Ov015Obj292c *self);
Ov015Fish *func_ov015_021fffc4(Ov015Obj30 *self);
BOOL func_ov015_02209ff0(Ov015Fish *self, void *a);

BOOL func_ov015_021ffdd4(Ov015Obj30 *self) {
    BOOL r = FALSE;
    Ov015Fish *found;
    u8 *n;
    if (self->unk_0c != 0) return r;
    func_ov015_021fd00c(self->cam, 7, (const Ov015Vec *)&self->unk_10->pos);
    VCALL(self->unk_14)->v18();
    self->fish = func_ov015_021fffc4(self);
    if (VCALL(self->unk_14)->v20() || self->fish != NULL) {
        if (self->fish != NULL) {
            Ov015CamPair *p = self->cam;
            p->cam0.shakeTime = 200;
            p->cam0.shakeLen = 20;
            p->cam0.shakeCur = 20;
            p->cam0.flags.shakeX = 1;
            p->cam0.flags.shakeY = 1;
            p->cam0.flags.shakeZ = 0;
            p = self->cam;
            p->cam1.shakeTime = 20;
            p->cam1.shakeLen = 20;
            p->cam1.shakeCur = 20;
            p->cam1.flags.shakeX = 1;
            p->cam1.flags.shakeY = 1;
            p->cam1.flags.shakeZ = 0;
        }
        r = TRUE;
    }
    found = NULL;
    n = ((u8 *)self->fishList->head);
    while (n != NULL) {
        Ov015Fish *obj = FLD(Ov015Fish *, n, 0x4);
        Ov015Vec v;
        n = FLD(u8 *, n, 0xc);
        v = self->unk_10->pos;
        if (func_ov015_0220a028(obj, &v)) {
            found = obj;
            break;
        }
    }
    if (found != NULL) {
        s32 d = FX_Mul(found->scale.x, 0x14000);
        Ov015Vec t(*(Ov015Vec *)&found->pos);
        t.y += d;
        if (t.y < 0) t.y = 0;
        FLD(Ov015Vec, self->unk_10, 0x24) = t;
        func_ov015_0221234c(self->unk_10);
    } else {
        func_ov015_022123c4(self->unk_10);
    }
    self->ship->unk_d3e = 0x1000;
    for (n = ((u8 *)self->fishList->head); n != NULL; n = FLD(u8 *, n, 0xc)) {
        func_ov015_02209790(FLD(Ov015Fish *, n, 0x4), 1);
    }
    return r;
}

BOOL func_ov015_021fffb0(Ov015Obj30 *self) {
    return self->timer >= 2 ? TRUE : FALSE;
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
    u8 *n = ((u8 *)self->fishList->head);
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
