#include "ov009/ov009.h"
#include "Main/Gfx/SlidePanel.h"

extern "C" {

extern Ov003Actor *ActorMgr_FindPlayer(void);
extern void Target_SetActor(void *p, Ov003Actor *a);

void Ov009ActVt_02217594_StateDie(Ov009ActVt_02217594 *self) {
    if (self->fsm->st != 0) {
        return;
    }
    Target_SetActor(self->hp, ActorMgr_FindPlayer());
    Ov003Actor_Defeat(self, 0, 1, 1);
    self->fsm->st++;
}

void Ov009ActVt_02217594_State21(Ov009ActVt_02217594 *self) {
    if (self->fsm->st == 0) {
        self->unk_312 = 1;
    }
    switch (self->unk_1a) {
    case 0:
    case 1:
        self->unk_93_4 = 1;
        self->vfunc_64();
        break;
    case 2:
        self->unk_93_4 = 1;
        self->vfunc_68();
        break;
    }
}


extern char data_ov009_022172b5[];
extern s16 *Model0218fe1c_SetAnimFrame(Model0218fe1c *m, s32 a);
extern void Model0218fe1c_SetReverse(Model0218fe1c *p);
extern void Model0218fe1c_ClearReverse(Model0218fe1c *p);
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *p, s16 a);
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern EffectObj *Spawn_ScatterEffect(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, u8 d);
extern void Shared_SetEventActor(u16 kind, u16 id);
extern void StageVars_SetEventScript(s32 a);

void Ov009ActVt_02217594_State22(Ov009ActVt_02217594 *self) {
    VecFx32 p;
    VecFx32 v;
    VecFx32 p2;
    VecFx32 v2;
    switch (self->unk_1a) {
    case 0:
    case 1:
        switch (self->fsm->st) {
        case 0: {
            ActorSub48 *s48;
            ActorSub44 *s44;
            Model0218fe1c_SetAnim(self->model, data_ov009_022172b5, 0x1000, 0);
            Model0218fe1c_SetAnimFrame(self->model, 0x40000);
            Model0218fe1c_SetReverse(self->model);
            self->fsm->timer = 0xc;
            self->fsm->st++;
            s48 = self->hit;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(s48);
            s44 = self->unk_44;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
            self->step = 1;
            break;
        }
        case 1:
            {
                ActorSub40 *s = self->fsm;
                if (s->timer != 0) {
                    s->timer--;
                }
                if (s->timer != 0) {
                    break;
                }
            }
            if (self->step % 2 == 0) {
                Model0218fe1c_SetReverse(self->model);
            } else {
                Model0218fe1c_ClearReverse(self->model);
            }
            self->step++;
            self->fsm->timer = 0xc;
            if (self->step % 2 == 0) {
                p = self->pos;
                if (self->unk_1a == 0) {
                    p.x += self->radius;
                } else {
                    p.x -= self->radius;
                }
                v.x = self->radius * 2;
                v.y = self->height;
                v.z = self->radius;
                Spawn_ScatterEffect(&p, &v, 0x99a, 0x1333, 0x38b, 0x32);
                SndMgr_PlayVolume(gSndMgr, 0x35, -1, -1, -1);
            }
            if (self->step > 0xd) {
                self->fsm->st++;
                self->fsm->timer = 0;
                self->step = 0;
                Model0218fe1c_ClearReverse(self->model);
            }
            break;
        case 2:
            if (Model0218fe1c_IsAnimDone(self->model)) {
                Shared_SetEventActor(self->kind, self->id);
                StageVars_SetEventScript(4);
                gSceneCmd->stageFlags = 1;
                Group_UpdateActor(gGroup, 0, self);
                self->vfunc_08();
            }
            break;
        }
        break;
    case 2:
        switch (self->fsm->st) {
        case 0: {
            ActorSub48 *s48;
            ActorSub44 *s44;
            s48 = self->hit;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(s48);
            s44 = self->unk_44;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
            self->fsm->timer = 0x18;
            self->fsm->st++;
            Model0218fe1c_SetAnimSpeed(self->model, 0x800);
            break;
        }
        case 1: {
            ActorSub40 *s = self->fsm;
            if (s->timer != 0) {
                s->timer--;
            }
            if (s->timer == 0) {
                self->fsm->timer = 0x18;
                p2 = self->pos;
                p2.y += 0x5000;
                v2.x = self->radius;
                v2.y = self->height * 2;
                v2.z = self->radius;
                Spawn_ScatterEffect(&p2, &v2, 0x99a, 0x1333, 0x38b, 0x32);
                SndMgr_PlayVolume(gSndMgr, 0x35, -1, -1, -1);
            }
            if (Model0218fe1c_IsAnimDone(self->model)) {
                Model0218fe1c_SetAnimSpeed(self->model, 0x1000);
                Shared_SetEventActor(self->kind, self->id);
                StageVars_SetEventScript(4);
                gSceneCmd->stageFlags = 1;
                Group_UpdateActor(gGroup, 0, self);
                self->vfunc_08();
            }
            break;
        }
        }
        break;
    }
}

}
