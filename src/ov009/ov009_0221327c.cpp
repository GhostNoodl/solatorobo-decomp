#include "ov009/ov009.h"
#include "Main/Gfx/SlidePanel.h"

extern "C" {
extern void ActorMgr_BroadcastKind(void *mgr, u16 a, s32 b);
extern void func_ov000_0218996c(u8 a, u8 b);

void func_ov009_0221327c(Ov009ActVt_02217d5c *self) {
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
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x483f, 0x15);
        func_ov000_0218996c(10, 0x28);
        func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
        e = func_02065f88(5, &self->pos);
        e->SetScaleXYZ(0x7800, 0x7800, 0x7800);
        self->fsm->st++;
        break;
    }
    case 1:
        func_ov003_021d6a3c(self, 0, 1, 1);
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
    e = func_02065f88(0x325, &p);
    e->SetRotXYZ(0, (u16)(self->rot_y + 0x8000), 0);
    e->SetScaleXYZ(0x1ccd, 0x1ccd, 0x1ccd);
    self->fsm->timer = 0;
}

extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void func_ov000_0218d46c(Ov003Actor *a, u16 id, s32 msg);
extern EffectObj *func_ov000_0219b71c(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, u8 d);
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
static inline Ov003Actor *Ov009_FindActor4(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void func_ov009_02213460(Ov009ActVt_02217d5c *self) {
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
                func_ov000_0218d46c(a, self->unk_f0, 0x15);
            }
            func_ov000_0218996c(0xf, 0x50);
            func_02049a48(data_02097e4c, 0x56, -1, -1, -1);
            func_02065f88(5, &self->pos)->SetScaleXYZ(0x8000, 0x8000, 0x8000);
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
            func_ov000_0219b71c(&p, &v, 0x666, 0x1000, 3, 0x46);
            func_ov000_0218996c(8, 8);
            func_02049a48(data_02097e4c, 0x35, -1, -1, -1);
        }
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        break;
    case 2:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            func_020627a0(self->kind, self->id);
            func_020627dc(4);
            data_ov000_021ccd54->stageFlags = 1;
            func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
            self->vfunc_08();
            return;
        }
        if ((u8)self->fsm->timer < 0x1f) {
            func_ov003_021d6954(self, self->fsm->timer);
        }
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        break;
    }
}

}
