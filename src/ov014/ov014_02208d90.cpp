#include "ov014/ov014.h"

extern "C" {

void Ov014ActEx_02208618_StateFly(Ov014ActEx_02208618 *self) {
    self->unk_d0 |= 0x1000;
    func_ov000_02198360(self->fsm, 0x15, 0);
}
extern void func_ov000_02198c8c(void *p, s32 a);
extern void func_0203f364(ActorSub48 *p);
extern void func_ov000_0218996c(u8 a, u8 b);

void Ov014ActEx_02208618_StateDie(Ov014ActEx_02208618 *self) {
    switch (self->fsm->st) {
    case 0: {
        EffectObj *a;
        if (self->unk_44 != NULL) {
            ActorSub44 *n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
        }
        if (self->hit != NULL) {
            ActorSub48 *m;
            func_ov000_02198c8c(self->hit, 0xffff);
            m = self->hit;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            func_0203f364(m);
            m = self->hit;
            m->unk_9a_1 = 0;
            m->unk_9a_4 = 0;
        }
        self->model->visible = 0;
        a = func_02065f88(0x69, &self->pos);
        a->SetScaleAll(0x40);
        Ov003FxList_Add(((Ov003FxList *)self->unk_d8), 0xff, a);
        a = func_02065f88(5, &self->pos);
        a->SetScaleAll(0x40);
        Ov003FxList_Add(((Ov003FxList *)self->unk_d8), 0xfe, a);
        func_ov000_0218996c(0xf, 0xf);
        func_02049f44(data_02097e4c, 0x7f, &self->pos, 0);
        func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
        self->fsm->st++;
        break;
    }
    case 1: {
        EffectObj *o;
        o = func_020657b0(data_0214a420, Ov003FxList_Get(((Ov003FxList *)self->unk_d8), 0xff));
        if (o != NULL) {
            o->SetScaleAll(o->scale.x + 0x148);
        }
        o = func_020657b0(data_0214a420, Ov003FxList_Get(((Ov003FxList *)self->unk_d8), 0xfe));
        if (o != NULL) {
            o->SetScaleAll(o->scale.x + 0xcd);
        }
        if (!Ov003FxList_Has(((Ov003FxList *)self->unk_d8), 0xff)) {
            self->fsm->st++;
        }
        break;
    }
    case 2:
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->vfunc_08();
        break;
    }
}

}
