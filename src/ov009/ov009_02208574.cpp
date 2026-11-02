#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_022172c1[];
extern char data_ov009_022172af[];
extern Ov009Path data_ov009_02215fbc[];
extern void func_ov000_021911c8(Model0218fe1c *m, s16 a);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void Actor_TurnClamped(Ov003Actor *self, u16 ang, u16 b, s32 c, s32 d);
extern void func_0203f2b8(void *p);

static inline Ov003Actor *Ov009_FindActor(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

extern char data_ov009_022172bb[];
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);

static inline u16 Ov009_AngTo(Ov003Actor *self, Ov003Actor *a) {
    if (a == NULL || a == self) {
        return self->rot_y;
    }
    return FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
}

void func_ov009_02208204(Ov009Multi *self) {
    VecFx32 off;
    VecFx32 d;
    s32 k = 0x66;
    BOOL moved = FALSE;
    u16 ang = self->unk_492;
    switch (self->fsm->st) {
    case 0:
        if (self->unk_490 < 4) {
            self->fsm->st = 10;
            self->fsm->timer = 0xf0;
            off.x = 0;
            off.y = 0;
            off.z = 0;
            k = 0x19a;
            moved = TRUE;
            break;
        }
        func_ov000_02190cb0(self->model, data_ov009_022172bb, 0x200, 0);
        func_ov000_021915a0(self->model);
        self->fsm->st++;
    case 1: {
        Ov003Actor *a;
        u16 a2 = self->unk_492;
        a = Actor_GetTarget(self);
        if (a != NULL) {
            a2 = Ov009_AngTo(self, a);
        }
        Actor_TurnClamped(self, a2, self->unk_492, 0x3000, self->unk_b0->unk_02);
        {
            ActorSub40 *s = self->fsm;
            if (s->timer != 0) {
                s->timer--;
            }
            if (s->timer == 0) {
                s32 x;
                s32 y;
                s32 z;
                self->fsm->timer = 0x2d;
                z = Rand_PlusMinus(0x59a);
                y = Rand_PlusMinus(0x59a);
                x = Rand_PlusMinus(0x4cd);
                off.x = x;
                off.y = y;
                off.z = z;
                ang = self->rot_y;
                moved = TRUE;
            }
        }
        break;
    }
    case 10: {
        ActorSub40 *s = self->fsm;
        k = 0x59a;
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer <= 0x19) {
            func_ov000_02190cb0(self->model, data_ov009_022172bb, 0xa4, 0);
            func_ov000_021915a0(self->model);
            self->fsm->st++;
        }
        self->rot_y = func_01ffc128(self->unk_492, self->rot_y, self->unk_b0->unk_02 << 1, 1, 0x8000);
        break;
    }
    case 11: {
        ActorSub40 *s = self->fsm;
        k = 0xcd;
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            off.x = 0;
            off.y = 0;
            off.z = 0;
            moved = TRUE;
            if (++self->unk_490 < 4) {
                self->fsm->timer = 0x2d;
            } else {
                self->unk_490 = 4;
                func_ov000_02190cb0(self->model, data_ov009_022172bb, 0x200, 0);
                func_ov000_021915a0(self->model);
                self->fsm->st = 1;
            }
        }
        self->rot_y = func_01ffc128(self->unk_492, self->rot_y, self->unk_b0->unk_02 << 1, 1, 0x8000);
        break;
    }
    }
    if (moved) {
        s32 r = self->unk_490 * 0xc00;
        self->unk_4a0.y = self->unk_494.y;
        self->unk_4a0.x = self->unk_494.x + FX_Mul(r, OV009_SIN(ang));
        self->unk_4a0.z = self->unk_494.z + FX_Mul(r, OV009_COS(ang));
        VEC_Add(&self->unk_4a0, &off, &self->unk_4a0);
    }
    d.x = self->unk_4a0.x - self->pos.x;
    d.y = self->unk_4a0.y - self->pos.y;
    d.z = self->unk_4a0.z - self->pos.z;
    VEC_MultAdd(k, &d, &self->pos, &self->pos);
}

void func_ov009_02208574(Ov009Multi *self) {
    if (self->unk_490 > 1) {
        self->unk_490 -= 2;
    } else {
        self->unk_490 = 0;
    }
    func_ov000_02190cb0(self->model, data_ov009_022172c1, 0x1000, 1);
    func_ov000_021911c8(self->model, 0xe66);
    func_ov000_02198360(self->fsm, 1, 0);
}

void func_ov009_022085d0(Ov009Multi *self) {
    if (self->unk_490 > 1) {
        self->unk_490 -= 2;
    } else {
        self->unk_490 = 0;
    }
    func_ov000_02190cb0(self->model, data_ov009_022172c1, 0x1000, 1);
    func_ov000_021911c8(self->model, 0xe66);
    func_ov000_02198360(self->fsm, 1, 0);
}

void func_ov009_0220862c(Ov009Multi *self) {
    Ov003Actor *a;
    u16 ang;
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov009_022172af, 0x200, 1);
        self->fsm->st++;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        break;
    case 1:
        a = Ov009_FindActor(self->target);
        if (a == NULL || a == self) {
            ang = self->rot_y;
        } else {
            ang = FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
        }
        Actor_TurnClamped(self, ang, self->unk_492, 0x3800, self->unk_b0->unk_02 << 1);
        if (self->model->anim_state == 1) {
            self->fsm->st++;
        }
        break;
    case 2:
        if (func_ov000_02191120(self->model)) {
            func_ov000_02198360(self->fsm, 1, 0);
        }
        break;
    }
    Actor_Move(self, 0);
}

BOOL func_ov009_02208764(Ov003Actor *self) {
    BOOL r = func_ov003_021d16cc(self);
    if (self->unk_18 == 1 && r == FALSE) {
        self->unk_18 = 2;
    }
    return r;
}

void func_ov009_02208788(Ov003Actor *self) {
    GroupNode *p;
    func_ov003_021d0fc0(self);
    p = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (p != NULL) {
        GroupNodeFlags *b = &p->flags;
        b->unk_0 = 0;
        b->unk_5 = 1;
    }
}

void func_ov009_022087c4(Ov003Actor *self) {
    void *saved;
    func_ov003_021d112c(self);
    {
        VecFx32 v = data_ov009_02215fbc[self->unk_1a].start;
        v.x = self->pos.x;
        self->unk_84 = v;
    }
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_3c != NULL) {
        if (self->unk_3c != NULL) {
            self->unk_3c->vfunc_04();
        }
        self->unk_3c = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->hit != NULL) {
        ActorSub48 *p = self->hit;
        if (p != NULL) {
            func_0203f2b8(p);
            Heap_Free(p);
        }
        self->hit = NULL;
    }
    data_02097dd0->cur = saved;
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_44 != NULL) {
        Heap_Free(self->unk_44);
        self->unk_44 = NULL;
    }
    data_02097dd0->cur = saved;
}


}
