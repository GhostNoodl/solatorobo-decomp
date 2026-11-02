#include "ov013/ov013.h"

extern "C" {

extern void *data_02097e4c;
extern char data_ov013_0220b88d[];
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void HitSphere_Link(ActorSub48 *p);
extern void *func_02049f44(void *a, s32 b, VecFx32 *c, s32 d);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, u16 e, void *f, void *g, s32 h, s32 i, s32 j, s32 k);
extern void func_ov000_0218996c(s32 a, s32 b);
extern void func_ov000_021984f4(void *a, s32 b, s32 c);

static inline Ov003Actor *Ov013_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void func_ov013_021fdc30(Ov003Actor *self) {
    Ov003Actor *t = Ov013_FindActor(self->target);
    if (t == NULL) {
        return;
    }
    if (self->fsm->st == 0) {
        ActorSub48 *m;
        ActorSub44 *n;
        func_ov000_02190cb0(self->model, data_ov013_0220b88d, 0x2ab, 0);
        func_ov000_021915a0(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0x14;
        self->hit->unk_30 = 0;
        m = self->hit;
        m->unk_9a_0 = 1;
        m->unk_9a_3 = 1;
        HitSphere_Link(m);
        m = self->hit;
        m->unk_9a_1 = 1;
        m->unk_9a_4 = 1;
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        self->unk_94_1 = 1;
        func_02049f44(data_02097e4c, 0x34, &self->pos, 0);
        self->fsm->st++;
        self->fsm->timer = 0;
    }
    Actor_Move(self, 0);
    func_ov000_021987b8(self->hit, 1, 0, 0);
    func_ov000_0219aae8(self, self, self->targetObj->unk_08, 0x20, 1 << (t->id >> 12), NULL, NULL, self->radius, 0, 100, 0x1000);
    if (!(self->hit->unk_50 & 0x20000000)) {
        return;
    }
    {
        ActorSub44 *n;
        u16 w = self->targetObj->unk_08 * 0.8f;
        func_ov000_0219aae8(self, self, w, 0x20, 1 << (t->id >> 12), NULL, NULL, self->radius + 0x1000, 0xccd, 100, 0x1000);
        func_02065f88(0x66, &self->pos);
        func_02049f44(data_02097e4c, 0x17, &self->pos, 0);
        func_ov000_0218996c(0xc, 0x14);
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        func_ov000_021984f4(self->unk_44, 0, 0);
        self->unk_94_1 = 0;
        func_ov000_02198360(self->fsm, 1, 0);
    }
}

extern char data_ov013_0220b893[];
extern char data_ov013_0220aec4[];
extern Ov003Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(Ov003Actor *p);
extern void func_ov000_02191690(void *p);

struct Ov013Stat8 {
    u16 a;
    u16 b;
};

struct Ov013Stat {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u16 h4;
    u16 h6;
    Ov013Stat8 s;
    u32 c;
};

struct Ov013Blk12 {
    u32 w[3];
};

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

extern Ov003Actor *Group_SpawnActor(void *mgr, Ov013SpawnDesc *d, VecFx32 *pos, void *rot, u16 a);

void func_ov013_021fdedc(Ov013ActEx_021fdb70 *self) {
    ActorSub40 *q = self->fsm;
    switch (q->st) {
    case 0: {
        ActorSub44 *n;
        Ov003Actor *r;
        func_ov000_02190cb0(self->model, data_ov013_0220b88d, 0x2ab, 0);
        func_ov000_021915a0(self->model);
        self->unk_94_1 = 0;
        n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        self->target = 0xffff;
        r = func_ov000_0219bf90();
        if (r != NULL) {
            self->target = r->id;
        }
        if (self->unk_d4 == 0) {
            Ov013Stat *p;
            Ov013Stat v;
            func_ov000_02191690(self->model);
            p = ((Ov013Stat *)self->targetObj);
            v = *p;
            v.h4 = p->h4 * 1.3f;
            *p = v;
        }
        self->fsm->st = 0xa;
        self->fsm->timer = 0;
        break;
    }
    case 0xa: {
        Ov003Actor *r = func_ov000_0219bf90();
        if (r == NULL || func_ov000_021b4738(r)) {
            func_ov000_02198360(self->fsm, 0x15, 0);
            break;
        }
        self->unk_ce--;
        if (self->unk_ce != 0) {
            break;
        }
        func_ov000_02190cb0(self->model, data_ov013_0220b893, 0x2ab, 0);
        if (self->unk_d4 == 0) {
            func_ov000_02191690(self->model);
        }
        self->fsm->st = 0x14;
        self->fsm->timer = 0;
        break;
    }
    case 0x14:
        q->timer++;
        if (q->timer <= 0x4d) {
            break;
        }
        if (self->unk_d4 == 0) {
            ActorSub44 *n;
            VecFx32 v;
            EffectObj *o;
            self->targetObj->type = 1;
            self->unk_94_1 = 1;
            n = self->unk_44;
            n->unk_22_0 = 0;
            n->unk_22_1 = 0;
            func_ov000_02191690(self->model);
            v.x = self->pos.x;
            v.y = self->pos.y;
            v.z = self->pos.z;
            v.y += self->radius;
            o = func_02065f88(0x390, &v);
            self->unk_d0 = o->id;
            o->SetScaleXYZ(0x333, 0x333, 0x333);
            o->speed = 0x14cd;
            self->fsm->st = 0x28;
            self->fsm->timer = 0;
        } else {
            self->fsm->st = 0x15;
            self->fsm->timer = 0;
        }
        break;
    case 0x15: {
        ActorSub44 *n;
        VecFx32 v;
        if (self->model->anim_state != 2) {
            break;
        }
        self->targetObj->type = 1;
        self->unk_94_1 = 1;
        n = self->unk_44;
        n->unk_22_0 = 0;
        n->unk_22_1 = 0;
        v.x = self->pos.x;
        v.y = self->pos.y;
        v.z = self->pos.z;
        v.y += 0x1000;
        func_02065f88(0x12c, &v)->SetScaleXYZ(0x1800, 0x1800, 0x1800);
        func_02049f44(data_02097e4c, 0x11, &self->pos, 0);
        self->fsm->st = 0x1e;
        self->fsm->timer = 0;
        break;
    }
    case 0x1e: {
        Ov013SpawnDesc desc;
        VecFx32 v;
        Ov003Actor *o;
        q->timer++;
        if (q->timer <= 0xa) {
            break;
        }
        Ov013Spawn_Init(&desc, 0x5c17);
        v.x = self->pos.x;
        v.y = self->pos.y;
        v.z = self->pos.z;
        v.y += 0xccd;
        o = Group_SpawnActor(data_ov000_021ccd64, &desc, &v, &self->rot_x, 0xffff);
        o->flags_0 = 1;
        o->target = self->target;
        if (o->targetObj != NULL) {
            o->targetObj->target = self->targetObj->target;
        }
        self->fsm->st = 0x3c;
        self->fsm->timer = 0;
        break;
    }
    case 0x28: {
        void *p;
        VecFx32 v;
        EffectObj *o;
        q->timer++;
        if (q->timer <= 0x5a) {
            break;
        }
        p = func_020657b0(data_0214a420, self->unk_d0);
        if (p != NULL) {
            FLD(s32, p, 0x1c) = 4;
            self->unk_d0 = -1;
        }
        v.x = self->pos.x;
        v.y = self->pos.y;
        v.z = self->pos.z;
        v.y += 0x666;
        o = func_02065f88(0x196, &v);
        func_02049f44(data_02097e4c, 0x44, &self->pos, 0);
        o->SetScaleXYZ(0x800, 0x800, 0x800);
        self->unk_94_1 = 1;
        self->fsm->st = 0x29;
        self->fsm->timer = 0;
        break;
    }
    case 0x29:
        q->timer++;
        if (q->timer <= 0x38) {
            break;
        }
        self->fsm->st = 0x32;
        self->fsm->timer = 0;
        break;
    case 0x32: {
        VecFx32 v;
        v.x = self->pos.x;
        v.y = self->pos.y;
        v.z = self->pos.z;
        v.y += 0x666;
        func_02065f88(5, &v)->SetScaleXYZ(0x3000, 0x3000, 0x3000);
        func_02049f44(data_02097e4c, 0x19, &self->pos, 0);
        func_ov000_0218996c(0xa, 0xf);
        self->fsm->st = 0x33;
        self->fsm->timer = 0;
        break;
    }
    case 0x33: {
        Ov003Actor *t = Ov013_FindActor(self->target);
        if (t != NULL) {
            u16 w = self->targetObj->unk_08 * 1.2f;
            Ov013Blk12 b = *(Ov013Blk12 *)data_ov013_0220aec4;
            func_ov000_0219aae8(self, self, w, 0x20, 1 << (t->id >> 12), &b, NULL, 0x3000, 0, 100, 0x1000);
        }
        if (self->model != NULL && self->model->alpha != 0) {
            u8 a;
            ActorSub40 *r = self->fsm;
            r->timer++;
            a = 0x1f - r->timer * 2;
            if (a > 0x1f) {
                a = 0;
            }
            self->model->alpha = a;
        }
        {
            ActorSub40 *r = self->fsm;
            r->timer++;
            if (r->timer <= 0x14) {
                break;
            }
        }
        self->fsm->st = 0x3c;
        self->fsm->timer = 0;
        break;
    }
    case 0x3c:
        if (self->model == NULL) {
            break;
        }
        if (self->model->alpha != 0) {
            u8 a;
            q->timer++;
            a = 0x1f - q->timer * 4;
            if (a > 0x1f) {
                a = 0;
            }
            self->model->alpha = a;
        } else {
            self->targetObj->unk_02 = 0;
            func_ov000_02198360(self->fsm, 0x15, 0);
        }
        break;
    }
}
}
