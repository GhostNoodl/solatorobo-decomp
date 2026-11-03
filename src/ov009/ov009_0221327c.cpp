#include "ov009/ov009.h"
#include "Main/Gfx/SlidePanel.h"

extern "C" {
extern void ActorMgr_BroadcastKind(void *mgr, u16 a, s32 b);
extern void Field_ShakeCamera(u8 a, u8 b);

void Ov009ActVt_02217d5c_StateDie(Ov009ActVt_02217d5c *self) {
    VecFx32 p;
    EffectObj *e;
    ActorSub40 *st;
    switch (self->fsm->st) {
    case 0: {
        ActorSub44 *s44;
        self->unk_ea_6 = 1;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        ActorMgr_BroadcastKind(gActorMgr, 0x483f, 0x15);
        Field_ShakeCamera(10, 0x28);
        SndMgr_PlayVolume(gSndMgr, 0x56, -1, -1, -1);
        e = Effect_SpawnId(5, &self->pos);
        e->SetScaleXYZ(0x7800, 0x7800, 0x7800);
        self->fsm->st++;
        break;
    }
    case 1:
        Ov003Actor_Defeat(self, 0, 1, 1);
        self->fsm->st++;
        break;
    }
    self->vfunc_50();
    st = self->fsm;
    st->timer++;
    if (st->timer != 0x5a) {
        return;
    }
    p.x = self->pos.x;
    p.y = self->pos.y;
    p.z = self->pos.z;
    {
        s32 w = self->radius;
        p.x += Rand_UpTo(w >> 1) + (w >> 1);
    }
    p.y += Rand_PlusMinus(self->height);
    p.z += Rand_PlusMinus(0x4000) + 0x3000;
    e = Effect_SpawnId(0x325, &p);
    e->SetRotXYZ(0, (u16)(self->rot_y + 0x8000), 0);
    e->SetScaleXYZ(0x1ccd, 0x1ccd, 0x1ccd);
    self->fsm->timer = 0;
}

extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void Actor_SendMsgU8(Ov003Actor *a, u16 id, s32 msg);
extern EffectObj *Spawn_ScatterEffect(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, u8 d);
extern void Shared_SetEventActor(u16 kind, u16 id);
extern void func_020627dc(s32 a);
static inline Ov003Actor *Ov009_FindActor4(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

void Ov009ActVt_02217d5c_State21(Ov009ActVt_02217d5c *self) {
    VecFx32 p;
    VecFx32 v;
    ActorSub40 *st = self->fsm;
    u16 t;
    switch (st->st) {
    case 0:
        self->speed = 0;
        self->velY = -0x71;
        self->friction = 0;
        *self->hp = 0;
        self->fsm->st++;
        self->fsm->timer = 0;
        break;
    case 1:
        st->timer++;
        t = st->timer;
        if (t > 0xb4) {
            Ov003Actor *a = Ov009_FindActor4(self->unk_f0);
            if (a != NULL) {
                Actor_SendMsgU8(a, self->unk_f0, 0x15);
            }
            Field_ShakeCamera(0xf, 0x50);
            SndMgr_PlayVolume(gSndMgr, 0x56, -1, -1, -1);
            Effect_SpawnId(5, &self->pos)->SetScaleXYZ(0x8000, 0x8000, 0x8000);
            self->fsm->timer = 0x29;
            self->fsm->st++;
            return;
        }
        if (t % 20 == 0) {
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            v.x = 0x1333;
            v.y = 0x2000;
            v.z = 0x7800;
            Spawn_ScatterEffect(&p, &v, 0x666, 0x1000, 3, 0x46);
            Field_ShakeCamera(8, 8);
            SndMgr_PlayVolume(gSndMgr, 0x35, -1, -1, -1);
        }
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        break;
    case 2:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            Shared_SetEventActor(self->kind, self->id);
            func_020627dc(4);
            gSceneCmd->stageFlags = 1;
            Group_UpdateActor(gGroup, 0, self);
            self->vfunc_08();
            return;
        }
        if ((u8)self->fsm->timer < 0x1f) {
            Ov003Actor_SetAlpha(self, self->fsm->timer);
        }
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        break;
    }
}

}
