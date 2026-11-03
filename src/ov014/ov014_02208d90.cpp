#include "ov014/ov014.h"

extern "C" {

void Ov014ActEx_02208618_StateFly(Ov014ActEx_02208618 *self) {
    self->unk_d0 |= 0x1000;
    History_SetState(self->fsm, 0x15, 0);
}
extern void Body_SetOwner(void *p, s32 a);
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern void Field_ShakeCamera(u8 a, u8 b);

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
            Body_SetOwner(self->hit, 0xffff);
            m = self->hit;
            m->unk_9a_0 = 0;
            m->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(m);
            m = self->hit;
            m->unk_9a_1 = 0;
            m->unk_9a_4 = 0;
        }
        self->model->visible = 0;
        a = Effect_SpawnId(0x69, &self->pos);
        a->SetScaleAll(0x40);
        Ov003FxList_Add(((Ov003FxList *)self->unk_d8), 0xff, a);
        a = Effect_SpawnId(5, &self->pos);
        a->SetScaleAll(0x40);
        Ov003FxList_Add(((Ov003FxList *)self->unk_d8), 0xfe, a);
        Field_ShakeCamera(0xf, 0xf);
        SndMgr_PlayAt(data_02097e4c, 0x7f, &self->pos, 0);
        SndMgr_PlayAt(data_02097e4c, 0x56, &self->pos, 0);
        self->fsm->st++;
        break;
    }
    case 1: {
        EffectObj *o;
        o = Effect_Find_020657b0(data_0214a420, Ov003FxList_Get(((Ov003FxList *)self->unk_d8), 0xff));
        if (o != NULL) {
            o->SetScaleAll(o->scale.x + 0x148);
        }
        o = Effect_Find_020657b0(data_0214a420, Ov003FxList_Get(((Ov003FxList *)self->unk_d8), 0xfe));
        if (o != NULL) {
            o->SetScaleAll(o->scale.x + 0xcd);
        }
        if (!Ov003FxList_Has(((Ov003FxList *)self->unk_d8), 0xff)) {
            self->fsm->st++;
        }
        break;
    }
    case 2:
        Group_UpdateActor(data_ov000_021ccd64, 0, self);
        self->vfunc_08();
        break;
    }
}

}
