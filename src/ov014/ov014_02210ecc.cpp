#include "ov014/ov014.h"

struct Ov014Wave {
    s16 kind;
    u16 wait;
    u16 count;
};

struct Ov014SpawnDescB {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

static inline void Ov014SpawnB_Init(Ov014SpawnDescB *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

extern "C" {

extern char data_ov014_02217d3a[];
extern char data_ov014_02217d40[];
extern char data_ov014_02217d46[];
extern void func_ov000_021911c8(void *a, s32 b);
extern Ov003Actor *func_ov000_0219bf90(void);
extern char data_ov014_02217d4c[];
extern void *func_ov000_02191318(void *a, s32 b);
extern void *func_ov014_02210878(Ov014Act_0220f9d0 *self);
extern char data_ov014_02217d1d[];
extern char data_ov014_02217d52[];
extern char data_ov014_02217d5e[];
extern char data_ov014_02217d64[];
extern void func_ov000_02191618(void *a);
extern s32 **func_ov000_02190a30(void *a, s32 b);
extern Ov003Actor *func_ov014_02210d9c(Ov014Act_0220f9d0 *self);
extern Ov003Actor *func_ov014_02210a78(Ov014Act_0220f9d0 *self);
extern Ov003Actor *func_ov014_02210c5c(Ov014Act_0220f9d0 *self);

static inline void Ov014_TimerTick(ActorSub40 *s) {
    if (s->timer != 0) {
        s->timer--;
    }
}

void func_ov014_02210ecc(Ov014Act_0220f9d0 *self) {
    self->fsm->st = 0xffff;
}

void func_ov014_02210ee0(Ov014Act_0220f9d0 *self) {
    switch (self->fsm->st) {
    case 0: {
        ActorSub44 *n = self->unk_44;
        n->unk_22_0 = 1;
        n->unk_22_1 = 1;
        FLD(Ov014Flags, self->unk_44, 0x22).b4 = 1;
        self->fsm->st = 40;
        break;
    }
    case 10:
        func_ov000_02190cb0(self->model, data_ov014_02217d3a, 0xcd, 0);
        func_ov000_021911c8(self->model, 0x1000);
        func_ov000_021915a0(self->model);
        self->fsm->st = 40;
        break;
    case 20:
        func_ov000_02190cb0(self->model, data_ov014_02217d40, 0xcd, 0);
        func_ov000_021911c8(self->model, 0x1000);
        func_ov000_021915a0(self->model);
        self->fsm->st = 40;
        break;
    case 30:
        func_ov000_02190cb0(self->model, data_ov014_02217d46, 0xcd, 0);
        func_ov000_021911c8(self->model, 0x1000);
        func_ov000_021915a0(self->model);
        self->fsm->st = 40;
        break;
    case 40:
        if (func_ov000_02191120(self->model)) {
            Ov003Actor *a = func_ov000_0219bf90();
            u16 ang;
            if (a == NULL || a == self) {
                ang = self->rot_y;
            } else {
                ang = FX_Atan2(a->pos.x - self->pos.x, a->pos.z - self->pos.z);
            }
            if (ang < 0x71c || ang > 0xf8e3) {
                self->fsm->st = 10;
            } else if (ang < 0x3fff) {
                self->fsm->st = 20;
            } else {
                self->fsm->st = 30;
            }
        }
        break;
    }
}

void func_ov014_022110bc(Ov014Act_0220f9d0 *self) {
    ActorSub40 *s = self->fsm;
    Ov014Wave *p = ((Ov014Wave *)self->unk_140);
    switch (ActorSub40_State(s)) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov014_02217d4c, 0x19a, 0);
        func_ov000_021915a0(self->model);
        func_ov000_02191318(self->model, 0);
        self->fsm->st = 20;
        self->unk_14c = p->count;
        self->unk_144 = Rand_UpTo(0xffff);
        break;
    case 20:
        if (self->model->anim_state != 1) {
            return;
        }
        switch (p->kind) {
        case 0:
            func_ov014_02210878(self);
            break;
        case 1:
            func_ov014_02210a78(self);
            break;
        case 2:
            func_ov014_02210c5c(self);
            break;
        default:
            func_ov014_02210878(self);
            break;
        }
        self->model->anim_state = 0;
        self->unk_14c--;
        if (self->unk_14c == 0) {
            self->fsm->st = 30;
            self->fsm->timer = 30;
        } else {
            self->fsm->st++;
            self->fsm->timer = p->wait;
        }
        break;
    case 21:
        if (ActorSub40_Timer(s) != 0) {
            Ov014_TimerTick(s);
            return;
        }
        func_ov000_02190cb0(self->model, data_ov014_02217d4c, 0x19a, 0);
        func_ov000_021915a0(self->model);
        if (p->wait <= 35) {
            func_ov000_02191318(self->model, 0x24000);
        } else {
            func_ov000_02191318(self->model, 0);
        }
        self->fsm->st--;
        break;
    case 30:
        if (ActorSub40_Timer(s) == 0) {
            s->st = 0xffff;
        } else {
            Ov014_TimerTick(s);
        }
        break;
    default:
        s->st = 0xffff;
        break;
    }
}

void func_ov014_022112b8(Ov014Act_0220f9d0 *self) {
    switch (self->fsm->st) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov014_02217d4c, 0xcd, 0);
        func_ov000_02191318(self->model, 0);
        func_ov000_02191618(self->model);
        self->fsm->st++;
        self->fsm->timer = 0xcd;
    case 1: {
        VecFx32 v;
        u16 t = self->fsm->timer;
        if (t != 0) {
            if (t == 200) {
                EffectObj *e;
                v.x = self->unk_118.x;
                v.y = self->unk_118.y;
                v.z = self->unk_118.z + 0x3000;
                e = func_02065f88(0x5e2, &v);
                e->SetScaleXYZ(0x3000, 0x3000, 0x3000);
                e->loopCount = 1;
            } else if (t == 100) {
                v.x = self->unk_118.x;
                v.y = self->unk_118.y;
                v.z = self->unk_118.z + 0x3000;
                Effect3D_Create(data_ov014_02217d1d, data_ov014_02217d52, 0, &v)->SetScaleXYZ(0x3000, 0x3000, 0x3000);
                func_02049f44(data_02097e4c, 0x5b, (VecFx32 *)((u8 *)self + 0x118), 0);
                func_02049f44(data_02097e4c, 0x50, (VecFx32 *)((u8 *)self + 0x118), 0);
            }
            Ov014_TimerTick(self->fsm);
        } else {
            func_ov000_02190cb0(self->model, data_ov014_02217d5e, 0x1000, 0);
            func_ov000_02191318(self->model, 0);
            func_ov000_02191618(self->model);
            self->fsm->st++;
        }
        break;
    }
    case 2:
        if (self->model->anim_state != 1) {
            return;
        }
        func_ov014_02210d9c(self);
        Effect3D_Create(data_ov014_02217d1d, data_ov014_02217d64, 0, (VecFx32 *)((u8 *)self + 0x118));
        func_02049f44(data_02097e4c, 0x1b, (VecFx32 *)((u8 *)self + 0x118), 0);
        func_02049f44(data_02097e4c, 0x3e, (VecFx32 *)((u8 *)self + 0x118), 0);
        self->model->anim_state = 0;
        self->fsm->st++;
        break;
    case 3: {
        s32 t = 0;
        s32 **q = func_ov000_02190a30(self->model, 0);
        if (*q != NULL) {
            t = **q;
        }
        if (t >= 0x3c000) {
            self->fsm->st = 0xffff;
        }
        break;
    }
    }
}


extern char data_ov014_02217d70[];
extern u8 data_ov014_02216d30[];
extern Ov003Actor *Group_SpawnActor(void *mgr, Ov014SpawnDescB *d, VecFx32 *pos, Ov014Rot16 *rot, u16 a);

void func_ov014_02211538(Ov014Act_0220f9d0 *self) {
    switch (ActorSub40_State(self->fsm)) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov014_02217d4c, 0xcd, 0);
        func_ov000_02191318(self->model, 0);
        func_ov000_02191618(self->model);
        self->fsm->st++;
        self->fsm->timer = 0x91;
    case 1:
        if (self->fsm->timer != 0) {
            if (self->fsm->timer == 0x8c) {
                VecFx32 v;
                v.x = self->unk_118.x;
                v.y = self->unk_118.y;
                v.z = self->unk_118.z + 0x3000;
                func_02065f88(0x5dd, &v)->SetScaleXYZ(0x3000, 0x3000, 0x3000);
                func_02049f44(data_02097e4c, 0x5b, &v, 0);
            }
            if (self->fsm->timer == 0x5a) {
                VecFx32 v;
                v.x = self->unk_118.x;
                v.y = self->unk_118.y;
                v.z = self->unk_118.z + 0x3000;
                func_02065f88(0x5dd, &v)->SetScaleXYZ(0x3000, 0x3000, 0x3000);
                func_02049f44(data_02097e4c, 0x5b, &v, 0);
            }
            if (self->fsm->timer == 0x28) {
                VecFx32 v;
                v.x = self->unk_118.x;
                v.y = self->unk_118.y;
                v.z = self->unk_118.z + 0x3000;
                func_02065f88(0x196, &v)->SetScaleXYZ(0x2ccd, 0x2ccd, 0x2ccd);
                func_02049f44(data_02097e4c, 0x44, &v, 0);
            }
            {
                ActorSub40 *s = self->fsm;
                if (s->timer != 0) {
                    s->timer--;
                }
            }
            break;
        }
        func_ov000_02190cb0(self->model, data_ov014_02217d70, 0xcd, 0);
        func_ov000_02191318(self->model, 0);
        func_ov000_02191618(self->model);
        self->fsm->timer = 0;
        self->fsm->st++;
    case 2: {
        VecFx32 p;
        VecFx32 w;
        VecFx32 v;
        Ov014SpawnDescB desc;
        Ov014Rot16 rot;
        Ov003Actor *o;
        FieldState *g;
        if (self->model->anim_state != 1) {
            break;
        }
        self->model->anim_state = 0;
        p = self->unk_118;
        p.y -= 0x800;
        v.x = 0;
        v.y = 0;
        v.z = 0x1000;
        MTX_MultVec43(&v, (MtxFx43 *)((u8 *)self + 0xf4), &v);
        w.x = v.x;
        w.y = 0;
        w.z = v.z;
        VEC_Mag(&w);
        rot.x = 0xf00;
        rot.y = FX_Atan2(w.x, w.z);
        rot.z = 0;
        Ov014SpawnB_Init(&desc, 0x4838);
        o = Group_SpawnActor(data_ov000_021ccd64, &desc, &p, &rot, 0xffff);
        o->unk_60 = data_ov014_02216d30;
        o->target = self->target;
        if (o->targetObj != NULL) {
            o->targetObj->target = self->id;
        }
        o->flags_0 = 1;
        self->target_id = o->id;
        g = data_ov000_021ccd54;
        g->cam.base.flags |= 0x1c;
        g->cam.base.shakeTime = 0x1e;
        g->cam.base.shakeLen = 0x78;
        g->cam.base.shakeCur = 0x78;
        self->fsm->st++;
        self->fsm->timer = 0xa0;
        break;
    }
    case 3: {
        ActorSub40 *s = self->fsm;
        if (ActorSub40_Timer(s) == 0) {
            s->st++;
            break;
        }
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer > 0x28 && s->timer % 40 == 0) {
            func_02049f44(data_02097e4c, 0x5c, &self->pos, 0);
        }
        break;
    }
    case 4:
        self->fsm->st = 0xffff;
        break;
    }
}

extern char data_ov014_02217d76[];
extern u8 data_ov014_02216d78[];
extern void func_ov000_02191780(void *a);
extern void func_ov000_021917f8(void *a);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);

struct Ov014WaveB {
    s16 kind;
    u16 wait;
    u16 count;
};

void func_ov014_02211980(Ov014Act_0220f9d0 *self) {
    switch (ActorSub40_State(self->fsm)) {
    case 0:
        func_ov000_02190cb0(self->model, data_ov014_02217d4c, 0xcd, 0);
        func_ov000_02191318(self->model, 0);
        func_ov000_02191618(self->model);
        self->fsm->st++;
        self->fsm->timer = 0xa0;
        self->unk_14c = ((Ov014WaveB *)self->unk_140)->count;
    case 1:
        if (self->fsm->timer != 0) {
            if (self->fsm->timer == 0x9b) {
                VecFx32 v;
                v.x = self->unk_118.x;
                v.y = self->unk_118.y;
                v.z = self->unk_118.z + 0x3000;
                func_02065f88(0x5dd, &v)->SetScaleXYZ(0x3000, 0x3000, 0x3000);
                func_02049f44(data_02097e4c, 0x5b, &v, 0);
            }
            if (self->fsm->timer == 0x69) {
                VecFx32 v;
                v.x = self->unk_118.x;
                v.y = self->unk_118.y;
                v.z = self->unk_118.z + 0x3000;
                func_02065f88(0x5dd, &v)->SetScaleXYZ(0x3000, 0x3000, 0x3000);
                func_02049f44(data_02097e4c, 0x5b, &v, 0);
            }
            if (self->fsm->timer == 0x37) {
                VecFx32 v;
                v.x = self->unk_118.x;
                v.y = self->unk_118.y;
                v.z = self->unk_118.z + 0x3000;
                func_02065f88(0x196, &v)->SetScaleAll(0x2ccd);
                func_02049f44(data_02097e4c, 0x44, &v, 0);
            }
            {
                ActorSub40 *s = self->fsm;
                if (s->timer != 0) {
                    s->timer--;
                }
            }
            break;
        }
        {
            s32 **q;
            s32 t;
            func_ov000_02190cb0(self->model, data_ov014_02217d76, 0xcd, 0);
            func_ov000_02191618(self->model);
            q = func_ov000_02190a30(self->model, 0);
            if (*q != NULL) {
                **q = (FLD(u16, FLD(u8 *, *q, 8), 4) << 12) - 1;
            }
            t = 0;
            q = func_ov000_02190a30(self->model, 0);
            if (*q != NULL) {
                t = **q;
            }
            self->unk_14a = 0x46;
            self->unk_148 = ((Ov014WaveB *)self->unk_140)->count * self->unk_14a + 0x2d;
            func_ov000_021911c8(self->model, (s16)FX_Div(t, self->unk_148 << 12));
            if (Rand_UpTo(1)) {
                func_ov000_02191780(self->model);
                func_ov000_02191318(self->model, t);
            } else {
                func_ov000_021917f8(self->model);
                func_ov000_02191318(self->model, 0);
            }
            self->fsm->st++;
            self->fsm->timer = self->unk_148;
        }
        break;
    case 2: {
        s32 i;
        VecFx32 p;
        VecFx32 w;
        VecFx32 v;
        Ov014SpawnDescB desc;
        Ov014Rot16 rot;
        u16 tm = self->fsm->timer;
        p = self->unk_118;
        p.y -= 0x800;
        v.x = 0;
        v.y = 0;
        v.z = 0x1000;
        MTX_MultVec43(&v, (MtxFx43 *)((u8 *)self + 0xf4), &v);
        w.x = v.x;
        w.y = 0;
        w.z = v.z;
        VEC_Mag(&w);
        rot.x = 0xf00;
        rot.y = FX_Atan2(w.x, w.z);
        rot.z = 0;
        if (tm % self->unk_14a == 0) {
            Ov003Actor *o;
            FieldState *g;
            EffectObj *e;
            desc.kind = 0x4839;
            desc.flags = 0x4839 & 0xf000;
            for (i = 0; i < 4; i++) {
                desc.unk_04[i] = 0;
            }
            desc.parent = -1;
            o = Group_SpawnActor(data_ov000_021ccd64, &desc, &p, &rot, 0xffff);
            o->unk_60 = data_ov014_02216d78;
            o->target = self->target;
            if (o->targetObj != NULL) {
                o->targetObj->target = self->id;
            }
            o->flags_0 = 1;
            self->target_id = o->id;
            self->target_id = o != NULL ? o->id : 0xffff;
            g = data_ov000_021ccd54;
            g->cam.base.flags |= 0x1c;
            g->cam.base.shakeTime = 0x1e;
            g->cam.base.shakeLen = 0x2d;
            g->cam.base.shakeCur = 0x2d;
            e = func_02065f88(0x579, &p);
            e->SetScaleAll(0x24cd);
            e->unk_50 = -0x64000;
            func_02049f44(data_02097e4c, 0x1b, &p, 0);
        }
        {
            ActorSub40 *s = self->fsm;
            Ov003Actor *a;
            if (s->timer != 0) {
                s->timer--;
            }
            if (s->timer > 10) {
                {
                    u16 id = self->target_id;
                    if (data_ov000_021ccd68 == NULL) {
                        a = NULL;
                    } else {
                        a = ActorMgr_GetActor(data_ov000_021ccd68, id);
                    }
                }
                if (a == NULL) {
                    self->target_id = 0xffff;
                    break;
                }
                a->pos = p;
                FLD(Ov014Rot16, a, 0x7c) = rot;
                break;
            }
            self->fsm->st++;
            self->fsm->timer = 0;
        }
        break;
    }
    case 3: {
        ActorSub40 *s = self->fsm;
        if (s->timer != 0) {
            s->timer--;
        }
        if (s->timer == 0) {
            self->fsm->st = 0xffff;
        }
        break;
    }
    }
}

}
