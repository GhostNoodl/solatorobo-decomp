#include "ov009/ov009.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Res/StageFlags.h"

extern "C" {


void func_ov009_021fc7c0(Ov003Actor *self) {
    GroupNode *p;
    func_ov003_021d112c(self);
    if (self->unk_1a == 0) {
        return;
    }
    self->pos.y += 0x4000;
    p = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        p->flags.unk_0 = 0;
    }
    self->fsm->flags |= 0x100000000ULL;
    self->targetObj->unk_18 |= 2;
}

void func_ov009_021fc834(Ov003Actor *self) {
    switch (self->fsm->st) {
    case 0:
        self->model->visible = 0;
        self->fsm->st++;
        break;
    case 1:
        if (Ov009_GameIdle()) {
            self->model->visible = 1;
            func_ov000_02198360(self->fsm, 4, 0);
        }
        break;
    }
}

extern char data_ov009_02216ac8[];
extern char data_ov009_02216ab0[];
extern void func_020627a0(u16 kind, u16 id);
extern void func_020627dc(s32 a);
extern void func_ov000_0218999c(u8 a, u8 b);
void func_ov009_021fc8f4(Ov003Actor *self) {
    ActorSub40 *st = self->fsm;
    Model0218fe1c *m;
    switch (st->st) {
    case 0:
        self->fsm->timer = Rand_UpTo(0x4b);
        self->fsm->st++;
        break;
    case 1:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
        m = self->model;
        m->visible = 1;
        func_ov000_02190cb0(self->model, data_ov009_02216ac8, 0x400, 0);
        func_ov000_021915a0(self->model);
        self->gravity = 0x52;
        self->fsm->st++;
        break;
    case 2:
        if (self->hit->unk_50 & 0x20000000) {
            func_ov000_02190cb0(self->model, data_ov009_02216ab0, 0x800, 0);
            func_02049a48(data_02097e4c, 8, -1, -1, -1);
            func_ov000_0218999c(8, 0xa);
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            self->fsm->st++;
        } else {
            Actor_Move(self, 0);
            func_ov000_021987b8(self->hit, 1, 0, 0);
        }
        break;
    case 3:
        self->hit->unk_9a_5 = 1;
        if (func_ov000_02191120(self->model)) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
}

extern void func_0203f364(ActorSub48 *p);
extern void NNSi_G3dModifyPolygonAttrMask(void *p, s32 a, s32 b);
extern void func_ov000_0218996c(u8 a, u8 b);
extern void func_ov000_0219b5dc(u16 id, const VecFx32 *pos, const u16 *rot);
extern void func_ov003_021ce9c4(u16 id);
void func_ov009_021fcad0(Ov003Actor *self) {
    VecFx32 p;
    ActorSub40 *st;
    if (self->unk_1a == 0) {
        func_ov003_021d6054(self);
        return;
    }
    st = self->fsm;
    switch (st->st) {
    case 0: {
        Model0218fe1c *m;
        EffectObj *o;
        u32 n;
        self->hp[0] = 0;
        if (self->hit != NULL) {
            ActorSub48 *s48 = self->hit;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            func_0203f364(s48);
        }
        if (self->unk_44 != NULL) {
            ActorSub44 *s44 = self->unk_44;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
        }
        self->targetObj->target = 0xffff;
        m = self->model;
        m->cull = 2;
        NNSi_G3dModifyPolygonAttrMask(m->mdl, 0, 0xc0);
        self->unk_ea_3 = 0;
        func_ov000_0218996c(8, 0xa);
        p = self->pos;
        p.y += (self->height >> 1) - (self->height >> 3);
        o = func_02065f88(3, &p);
        if (o != NULL) {
            s32 s = self->radius + (self->radius >> 3);
            o->SetScaleXYZ(s, s, s);
        }
        func_ov000_0219b5dc(self->unk_b0->unk_06, &p, &self->rot_x);
        func_ov003_021ce9c4(self->unk_b0->unk_04);
        n = data_0214a424->unk_00a + 1;
        if (n >= 0xffff) {
            n = 0xffff;
        }
        data_0214a424->unk_00a = n;
        self->hp[2] = 0xffff;
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    }
    case 1:
        st->timer++;
        if (st->timer > 0x78) {
            func_ov003_021d6a3c(self, 1, 1, 1);
        } else {
            u16 h = (u16)(self->fsm->timer >> 1);
            if (h > 0x1f) {
                h = 0x1f;
            }
            func_ov003_021d6954(self, 0x1f - h);
        }
        break;
    }
}

}
