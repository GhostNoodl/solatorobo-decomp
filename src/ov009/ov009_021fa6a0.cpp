#include "ov009/ov009.h"

extern "C" {

extern Ov003Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(Ov003Actor *a);
extern void func_0203f364(ActorSub48 *p);
extern s32 func_01ffbd6c(VecFx32 *a, VecFx32 *b, s32 c, s32 d, s32 e, s32 f);
extern Ov003Actor *ActorMgr_GetGroup(void *mgr, u16 id);
void Ov009ActVt_02216a00_Update(Ov009ActVt_02216a00 *self) {
    s32 dist;
    Ov003Actor *o;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (self->hp != NULL && *self->hp == 0) {
        return;
    }
    dist = 0x7fffffff;
    o = func_ov000_0219bf90();
    if (o != NULL) {
        if (func_ov000_021b4738(o)) {
            return;
        }
        self->target = o->id;
        dist = VEC_Distance(&self->pos, &o->pos);
    }
    if (dist > 0x12000) {
        self->unk_93_4 = 0;
        return;
    }
    if (self->unk_1a == 1) {
        if (dist > 0xa000) {
            ActorSub48 *s48;
            func_ov000_02198360(self->fsm, 0, 0);
            self->model->visible = 0;
            s48 = self->hit;
            s48->unk_9a_3 = 0;
            func_0203f364(s48);
            self->unk_44->unk_22_1 = 0;
            self->unk_93_4 = 0;
            return;
        }
        self->fsm->flags |= 2;
        self->unk_1a = 0;
        self->model->visible = 1;
    } else if (self->unk_1a == 2) {
        if (!self->unk_93_4) {
            VecFx32 a;
            VecFx32 b;
            a.x = o->pos.x;
            a.y = o->pos.y;
            a.z = o->pos.z;
            b.x = self->pos.x;
            b.y = self->pos.y;
            b.z = self->pos.z;
            a.y += o->centerY;
            b.y += self->centerY;
            if (func_01ffbd6c(&a, &b, -1, 0, 0, -1) != -0x1000) {
                return;
            }
        }
    }
    self->unk_93_4 = 1;
    if (self->fsm->current != 1) {
        return;
    }
    {
        Ov003Actor *e = ActorMgr_GetGroup(data_ov000_021ccd68, 0x5000);
        if (e != NULL && FLD(u16, e, 0x16) <= 3) {
            if (self->unk_b6 != 0) {
                self->unk_b6--;
            }
        }
    }
    if (self->unk_b6 != 0 && dist > 0x4000) {
        return;
    }
    self->fsm->flags |= 0x8000;
    self->unk_b6 = 0x5a;
}
extern char data_ov009_02216aa4[];
extern char data_ov009_02216aaa[];
extern char data_ov009_02216ab0[];
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *other, s32 a);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void func_ov000_021911c8(void *model, s32 a);
extern BOOL func_ov000_0219aae8(void *a, void *b, u16 c, u8 d, s32 e, void *f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern Ov003Actor *func_ov003_021d69a0(Ov003Actor *self, u16 kind, s32 a);
extern void func_01ffc9fc(VecFx32 *out, const void *a, s32 b);
extern Ov009V *func_02065f88(s32 id, const VecFx32 *pos);
static inline Ov003Actor *Ov009_FindActor5b(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

void func_ov009_021fa934(Ov009ActVt_02216a00 *self) {
    Ov003Actor *t = Ov009_FindActor5b(self->target);
    ActorSub40 *st = self->fsm;
    switch (st->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov009_02216aa4, 0x400, 0);
        self->unk_f0 = 100;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
        self->fsm->timer = 0x2d;
        if (self->kind == 0x5422) {
            self->fsm->timer = 0x1e;
        }
        break;
    case 1:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            func_ov000_02190cb0(self->model, data_ov009_02216aaa, 0x400, 0);
            func_ov000_021915a0(self->model);
            self->velY = 0x59a;
            self->gravity = 0x52;
            self->fsm->st++;
            self->fsm->timer = 0;
            return;
        }
        Actor_TurnToActor(self, t, self->unk_b0->unk_02);
        break;
    case 2: {
        u16 flag;
        u16 a;
        Ov003Actor *g;
        u16 lim;
        Actor_Move(self, 0);
        func_ov000_021987b8(self->hit, 0, 0, 0);
        if (!(self->hit->unk_50 & 0x20000000)) {
            return;
        }
        func_ov000_02190cb0(self->model, data_ov009_02216ab0, 0x800, 0);
        if (t != NULL) {
            func_ov000_0219aae8(self, self, self->unk_f0, 0x20, (u16)(1 << (t->id >> 12)), NULL, 0, 0x3400, 0x2800, 0x64, 0x1000);
        }
        func_02065f88(0x66, &self->pos)->v0c(0x1c00);
        g = ActorMgr_GetGroup(data_ov000_021ccd68, 0x5000);
        lim = 4;
        if (data_ov000_021ccd54->unk_ca.c[0] == 2) {
            lim = 3;
        }
        if (g != NULL && FLD(u16, g, 0x16) < lim) {
            u16 k = 0x5401;
            Ov003Actor *o;
            flag = 0;
            if (self->kind == 0x5422) {
                k = 0x541f;
                flag = 1;
            }
            o = func_ov003_021d69a0(self, k, 4);
            if (o != NULL) {
                VecFx32 v;
                s32 z = self->radius;
                v.y = 0x2000;
                v.x = 0;
                v.z = z;
                a = self->rot_y + 0xe800 + Rand_UpTo(0x3000);
                func_01ffc9fc(&v, &v, a);
                VEC_Add(&v, &self->pos, &v);
                o->pos.x = v.x;
                o->pos.y = v.y;
                o->pos.z = v.z;
                o->speed = Rand_UpTo(0x80) + 0x19a;
                o->velY = 0x333;
                o->friction = 0;
                o->gravity = 0x52;
                o->moveYaw = a;
                if (flag) {
                    o->unk_1a = flag;
                }
            }
        }
        self->fsm->st++;
        self->fsm->timer = 0;
        if (self->kind == 0x5422) {
            func_ov000_02198360(self->fsm, 1, 0);
            self->unk_b6 = 1;
        }
        break;
    }
    case 3:
        st->timer++;
        if (st->timer > 0x28) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        self->hit->unk_9a_5 = 1;
        break;
    }
}

}
