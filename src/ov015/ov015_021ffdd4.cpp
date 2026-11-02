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
    Ov015Node *n;
    if (self->unk_0c != 0) return r;
    func_ov015_021fd00c(self->cam, 7, (const Ov015Vec *)&self->unk_10->pos);
    self->unk_14->vfunc_18();
    self->fish = func_ov015_021fffc4(self);
    if (self->unk_14->vfunc_20() || self->fish != NULL) {
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
    n = self->fishList->head;
    while (n != NULL) {
        Ov015Fish *obj = n->fish;
        Ov015Vec v;
        n = n->next;
        v = self->unk_10->pos;
        if (func_ov015_0220a028(obj, &v)) {
            found = obj;
            break;
        }
    }
    if (found != NULL) {
        s32 d = FX_Mul(found->scale.x, 0x14000);
        Ov015Vec t(found->pos);
        t.y += d;
        if (t.y < 0) t.y = 0;
        self->unk_10->unk_24 = t;
        func_ov015_0221234c(self->unk_10);
    } else {
        func_ov015_022123c4(self->unk_10);
    }
    self->ship->unk_d3e = 0x1000;
    for (n = self->fishList->head; n != NULL; n = n->next) {
        func_ov015_02209790(n->fish, 1);
    }
    return r;
}

BOOL func_ov015_021fffb0(Ov015Obj30 *self) {
    return self->timer >= 2 ? TRUE : FALSE;
}

Ov015Fish *func_ov015_021fffc4(Ov015Obj30 *self) {
    Ov015Fish *found = NULL;
    Ov015Node *n = self->fishList->head;
    while (n != NULL) {
        Ov015Fish *obj = n->fish;
        n = n->next;
        if (func_ov015_02209ff0(obj, &self->unk_14->unk_234)) {
            Ov015Vec v;
            EffectObj *e;
            v = FLD(Ov015Vec, self->unk_14, 0x240);
            found = obj;
            e = func_02065f88(0x69, &v);
            e->SetParam(1);
            e->SetScaleXYZ(0x5800, 0x5800, 0x5800);
            e = func_02065f88(0x69, &v);
            e->SetParam(1);
            e->SetScaleXYZ(0x3800, 0x3800, 0x3800);
            e = func_02065f88(0x6c, &v);
            e->unk_50 = -0x64000;
            e->SetParam(1);
            e->SetScaleXYZ(0x6800, 0x6800, 0x6800);
            e->speed = 0x1800;
            v.y += 0x5000;
            e = func_02065f88(0x44c, &v);
            e->SetParam(1);
            e->unk_50 = -0xa000;
            e->SetScaleAll(0x1400);
            break;
        }
    }
    return found;
}

}
