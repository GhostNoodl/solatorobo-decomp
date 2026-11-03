#include "ov009/ov009.h"

extern "C" {

struct Ov009Bits16 {
    u16 b0 : 1;
    u16 b1 : 15;
};

void Ov009ActVt_02217594_StateIdle(Ov009ActVt_02217594 *self) {
    if (self->fsm->st != 0) {
        return;
    }
    self->model->visible = 0;
    self->modelObj.visible = 0;
    self->fsm->st++;
}

extern void *data_02097e4c;
extern char data_ov009_022172b5[];
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern void HitSphere_Link(ActorSub48 *p);
extern void Model0218fe1c_SetReverse(Model0218fe1c *m);
extern void Model0218fe1c_ClearReverse(Model0218fe1c *m);
extern void *SndMgr_PlayAt(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern void Shared_SetEventActor(u16 kind, u16 id);
extern void func_020627dc(s32 a);
void Ov009ActVt_02217594_StateAttack(Ov009ActVt_02217594 *self) {
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov009_022172b5, 0x1000, 1);
        self->model->visible = 1;
        Model0218fe1c_SetAnimByIndex(&self->modelObj, 1, 0x1000, 1);
        self->modelObj.visible = 1;
        self->fsm->st++;
        self->fsm->timer = 0x41;
        break;
    case 1: {
        ActorSub40 *st;
        if (self->model->anim_state == 1) {
            ActorSub44 *s44 = self->unk_44;
            ActorSub48 *s48;
            s44->unk_22_0 = 1;
            s44->unk_22_1 = 1;
            s48 = self->hit;
            s48->unk_9a_0 = 1;
            s48->unk_9a_3 = 1;
            HitSphere_Link(s48);
        }
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            if (self->step % 2 == 0) {
                Model0218fe1c_SetReverse(self->model);
            } else {
                Model0218fe1c_ClearReverse(self->model);
            }
            if (self->step == 1 || self->step == 5) {
                SndMgr_PlayAt(data_02097e4c, 0x41, &self->pos, 0);
            }
            self->step++;
            self->fsm->timer = 0xc;
        }
        if (self->step > 7) {
            self->fsm->st++;
            self->fsm->timer = 0;
            self->step = 0;
        }
        break;
    }
    case 2:
        if (self->model->anim_state == 2) {
            ActorSub44 *s44 = self->unk_44;
            ActorSub48 *s48;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
            s48 = self->hit;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(s48);
        }
        if (Model0218fe1c_IsAnimDone(self->model)) {
            History_SetState(self->fsm, 1, 0);
            if (self->unk_312 != 0) {
                Shared_SetEventActor(self->kind, self->id);
                func_020627dc(4);
                data_ov000_021ccd54->stageFlags = 1;
                self->unk_312 = 0;
            }
        }
        break;
    }
}


struct Ov009Vec3x3 {
    VecFx32 v[3];
};

extern const Ov009Vec3x3 data_ov009_02215f50;
extern char data_ov009_022172af[];
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *model, s16 a);
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern BOOL Hit_DiffInCylinder(VecFx32 *a, VecFx32 *b, fx32 r, fx32 h);

void Ov009ActVt_02217594_StateAttack2(Ov009ActVt_02217594 *self) {
    Ov009Vec3x3 tbl = data_ov009_02215f50;
    VecFx32 v1;
    Ov003Actor *pl = Actor_GetTarget(self);
    if (pl == NULL) {
        return;
    }
    switch (self->fsm->st) {
    case 0: {
        u8 i;
        EffectObj *e;
        self->unk_318 = 3;
        for (i = 0; i < 3; i++) {
            if (Hit_DiffInCylinder(&pl->pos, &tbl.v[i], pl->radius + 0x2400, 0xf000)) {
                self->unk_318 = i;
            }
        }
        if (self->unk_312 != 0) {
            self->unk_318 = 1;
        }
        if (self->unk_318 == 3) {
            return;
        }
        {
            VecFx32 *p = &tbl.v[self->unk_318];
            v1.x = p->x;
            v1.z = p->z;
            v1.y = 0x7000;
        }
        e = Effect_SpawnId(0x2bd, &v1);
        e->SetScaleAll(0x5000);
        e->loopCount = -1;
        self->unk_314 = e->id;
        self->fsm->st = 1;
        self->fsm->timer = 0;
        break;
    }
    case 1: {
        ActorSub40 *s = self->fsm;
        s->timer++;
        if (s->timer <= 0x3c) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, data_ov009_022172af, 0x1000, 1);
        self->model->visible = 1;
        self->pos = tbl.v[self->unk_318];
        self->fsm->st = 2;
        break;
    }
    case 2:
        if (self->model->anim_state == 1) {
            EffectObj *e = Effect_Find_020657b0(data_0214a420, self->unk_314);
            ActorSub44 *s44;
            ActorSub48 *s48;
            if (e != NULL) {
                e->loopCount = 1;
                self->unk_314 = 0;
            }
            s44 = self->unk_44;
            s44->unk_22_0 = 1;
            s44->unk_22_1 = 1;
            s48 = self->hit;
            s48->unk_9a_0 = 1;
            s48->unk_9a_3 = 1;
            HitSphere_Link(s48);
            Model0218fe1c_SetAnimSpeed(self->model, 0x99a);
        }
        if (self->model->anim_state == 2) {
            ActorSub44 *s44 = self->unk_44;
            ActorSub48 *s48;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
            s48 = self->hit;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(s48);
            Model0218fe1c_SetAnimSpeed(self->model, 0x1000);
            {
                VecFx32 t = tbl.v[self->unk_318];
                t.y = 0x7000;
                self->modelObj.trans = t;
            }
            self->modelObj.scale.x = 0xccd;
            self->modelObj.scale.y = 0xccd;
            self->modelObj.scale.z = 0xccd;
            Model0218fe1c_SetAnimByIndex(&self->modelObj, 0, 0x1000, 1);
            self->modelObj.visible = 1;
        }
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        History_SetState(self->fsm, 1, 0);
        if (self->unk_312 == 0) {
            return;
        }
        Shared_SetEventActor(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
        self->unk_312 = 0;
        self->unk_b6 = 0xb4;
        break;
    }
}

}
