#include "ov013/ov013.h"
#include "Main/Gfx/SlidePanel.h"
#include "Main/Snd/SndMgr.h"

struct Ov013SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov013Spawn_Init(Ov013SpawnDesc *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

extern "C" {

extern char data_ov013_0220b5d0[];
extern char data_ov013_0220b5b8[];
extern VecFx32 data_ov013_0220ae70;
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void Actor_TurnToActor(Actor *self, Actor *other, s32 step);
extern void func_ov000_0219a210(VecFx32 *v, const VecFx32 *off, s32 rot);
extern Ov003Actor *Group_SpawnActor(void *mgr, Ov013SpawnDesc *d, VecFx32 *pos, u16 *rot, u16 a);

static inline Ov003Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void func_ov013_021fbd20(Ov013Boss *self) {
    ActorSub40 *w;
    Ov003Actor *a = Ov013_FindActor(self->target);
    if (a == NULL) {
        return;
    }
    w = self->fsm;
    switch (w->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov013_0220b5d0, 0x2ab, 1);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st = 0x14;
        self->fsm->timer = 0;
        break;
    case 0x14: {
        Ov013SpawnDesc d;
        VecFx32 pos;
        Ov003Actor *o;
        Actor_TurnToActor(self, a, self->unk_b0->unk_02);
        if (!func_ov000_02191120(self->model)) {
            return;
        }
        Ov013Spawn_Init(&d, 0x4820);
        pos.x = self->pos.x;
        pos.y = self->pos.y;
        pos.z = self->pos.z;
        func_ov000_0219a210(&pos, &data_ov013_0220ae70, self->rot_y);
        pos.y = 0;
        o = Group_SpawnActor(data_ov000_021ccd64, &d, &pos, &self->rot_x, 0xffff);
        o->flags_0 = 1;
        o->target = self->target;
        if (self->unk_f0 != 0) {
            o->speed = 0x11f;
            o->velY = 0;
            o->friction = 0;
            o->gravity = 0;
        }
        if (o->targetObj != NULL) {
            o->targetObj->target = self->id;
        }
        self->target_id = o->id;
        func_ov000_02190cb0(self->model, data_ov013_0220b5b8, 0x155, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st = 0x63;
        self->fsm->timer = 0;
        break;
    }
    case 0x63:
        if (self->unk_f1 != 0) {
            w->timer++;
            if (w->timer > 60) {
                self->unk_f1--;
                self->fsm->st = 0;
                self->fsm->timer = 0;
            }
        } else {
            w->timer++;
            if (w->timer > 20) {
            self->unk_f0 = 0;
                func_ov000_02198360(self->fsm, 1, 0);
            }
        }
        break;
    }
}

extern void ActorMgr_BroadcastKind(void *mgr, u16 a, s32 b);
extern void func_0203f364(ActorSub48 *p);
extern void func_ov000_0218996c(u8 a, u8 b);
extern EffectObj *func_ov000_0219b71c(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, u8 d);

void func_ov013_021fbf84(Ov013Boss *self) {
    ActorSub40 *w = self->fsm;
    switch (w->st) {
    case 0: {
        ActorSub48 *m48;
        ActorSub44 *n;
        EffectObj *o;
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x5c17, 0x15);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4823, 0x15);
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x4820, 0x15);
        func_ov000_02190cb0(self->model, data_ov013_0220b5b8, 0x2ab, 0);
        func_ov000_021915a0(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->hp[0] = 0;
        m48 = self->hit;
        m48->unk_9a_0 = 0;
        m48->unk_9a_3 = 0;
        func_0203f364(m48);
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->targetObj->target = 0xffff;
        o = func_02065f88(0x390, &self->pos);
        if (o != NULL) {
            self->unk_f8 = o->id;
            o->AddPosXYZ(0, self->height, 0);
            o->SetScaleAll(0x1800);
        }
        o = func_02065f88(0x69, &self->pos);
        if (o != NULL) {
            o->AddPosXYZ(0, self->height, 0);
            o->SetScaleAll(0x5000);
        }
        func_02049f44(data_02097e4c, 0x56, &self->pos, 0);
        func_ov000_0218996c(0xc, 0x28);
        self->fsm->st = 0x14;
        self->fsm->timer = 0;
        break;
    }
    case 0x14: {
        u16 t;
        w->timer++;
        t = w->timer;
        if (t >= 0x78) {
            if (t % 30 == 0) {
                VecFx32 v;
                v.x = self->radius << 1;
                v.y = self->height >> 1;
                v.z = self->radius;
                func_ov000_0219b71c(&self->pos, &v, 0x99a, 0x1333, 0x38b, 0x32);
                func_ov000_0218996c(8, 8);
                func_02049f44(data_02097e4c, 0x35, &self->pos, 0);
            }
            if (t >= 0x12b) {
                func_ov000_0218996c(0x14, 0x78);
                self->fsm->st = 0x63;
                self->fsm->timer = 0;
            }
            self->pos.y -= 0x66;
        } else {
            if (t % 25 == 0) {
                func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
            }
            if (t == 0x6e) {
                EffectMgr_StopLoop(data_0214a420, self->unk_f8);
                self->unk_f8 = 0;
            }
        }
        break;
    }
    case 0x63: {
        VecFx32 p;
        EffectObj *o;
        p.x = self->pos.x;
        p.y = self->pos.y;
        p.z = self->pos.z;
        p.y += self->height;
        o = func_02065f88(0x38b, &p);
        if (o != NULL) {
            o->SetScaleAll(0x3000);
        }
        o = func_02065f88(0x69, &p);
        if (o != NULL) {
            o->SetScaleAll(0x5000);
            o->speed = 0xccd;
        }
        func_0204a028(data_02097e4c, 0x56, &self->pos, -8);
        func_0204a028(data_02097e4c, 0x41, &self->pos, 4);
        self->fsm->st = 0x64;
        self->fsm->timer = 0;
        break;
    }
    case 0x64:
        w->timer++;
        if (w->timer > 0x78) {
            func_ov003_021d6a3c(self, 1, 1, 1);
            break;
        }
        if (self->fsm->timer <= 0x3c) {
            func_ov003_021d6954(self, 0x1f - (self->fsm->timer >> 1));
        } else {
            func_ov003_021d6954(self, 0);
        }
        break;
    }
}
}
