#include "ov009/ov009.h"

extern "C" {

struct Ov009Bits16 {
    u16 b0 : 1;
    u16 b1 : 15;
};

void func_ov009_022093b4(Ov009ActVt_02217594 *self) {
    if (self->fsm->st != 0) {
        return;
    }
    self->model->visible = 0;
    self->modelObj.visible = 0;
    self->fsm->st++;
}

extern void *data_02097e4c;
extern char data_ov009_022172b5[];
extern void func_0203f364(ActorSub48 *p);
extern void HitSphere_Link(ActorSub48 *p);
extern void func_ov000_02191780(Model0218fe1c *m);
extern void func_ov000_021917f8(Model0218fe1c *m);
extern void *func_02049f44(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
void func_ov009_022093f8(Ov009ActVt_02217594 *self) {
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov009_022172b5, 0x1000, 1);
        self->model->visible = 1;
        func_ov000_02190e98(&self->modelObj, 1, 0x1000, 1);
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
                func_ov000_02191780(self->model);
            } else {
                func_ov000_021917f8(self->model);
            }
            if (self->step == 1 || self->step == 5) {
                func_02049f44(data_02097e4c, 0x41, &self->pos, 0);
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
            func_0203f364(s48);
        }
        if (func_ov000_02191120(self->model)) {
            func_ov000_02198360(self->fsm, 1, 0);
            if (self->unk_312 != 0) {
                func_020627a0(self->kind, self->id);
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
extern void *data_0214a420;
extern void func_ov000_021911c8(void *model, s32 a);
extern Ov009V *func_02065f88(s32 id, const VecFx32 *pos);
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern BOOL Hit_DiffInCylinder(const VecFx32 *a, const VecFx32 *b, s32 r, s32 h);
extern void *func_020657b0(void *mgr, s32 id);

void func_ov009_02209668(Ov009ActVt_02217594 *self) {
    Ov009Vec3x3 tbl = data_ov009_02215f50;
    VecFx32 v1;
    Ov003Actor *pl = Actor_GetTarget(self);
    if (pl == NULL) {
        return;
    }
    switch (self->fsm->st) {
    case 0: {
        u8 i;
        Ov009V *e;
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
        e = func_02065f88(0x2bd, &v1);
        e->v0c(0x5000);
        FLD(s32, e, 0xc8) = -1;
        self->unk_314 = FLD(s32, e, 0x24);
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
        func_ov000_02190cb0(self->model, data_ov009_022172af, 0x1000, 1);
        self->model->visible = 1;
        self->pos = tbl.v[self->unk_318];
        self->fsm->st = 2;
        break;
    }
    case 2:
        if (self->model->anim_state == 1) {
            void *e = func_020657b0(data_0214a420, self->unk_314);
            ActorSub44 *s44;
            ActorSub48 *s48;
            if (e != NULL) {
                FLD(s32, e, 0xc8) = 1;
                self->unk_314 = 0;
            }
            s44 = self->unk_44;
            s44->unk_22_0 = 1;
            s44->unk_22_1 = 1;
            s48 = self->hit;
            s48->unk_9a_0 = 1;
            s48->unk_9a_3 = 1;
            HitSphere_Link(s48);
            func_ov000_021911c8(self->model, 0x99a);
        }
        if (self->model->anim_state == 2) {
            ActorSub44 *s44 = self->unk_44;
            ActorSub48 *s48;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
            s48 = self->hit;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            func_0203f364(s48);
            func_ov000_021911c8(self->model, 0x1000);
            {
                VecFx32 t = tbl.v[self->unk_318];
                t.y = 0x7000;
                self->modelObj.trans = t;
            }
            self->modelObj.scale.x = 0xccd;
            self->modelObj.scale.y = 0xccd;
            self->modelObj.scale.z = 0xccd;
            func_ov000_02190e98(&self->modelObj, 0, 0x1000, 1);
            self->modelObj.visible = 1;
        }
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        func_ov000_02198360(self->fsm, 1, 0);
        if (self->unk_312 == 0) {
            return;
        }
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
        self->unk_312 = 0;
        self->unk_b6 = 0xb4;
        break;
    }
}

}
