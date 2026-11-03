#include "ov009/ov009.h"


// A header's zero rotation and vector, plus copies made at startup, among this TU's motion
// names, the pointers to them, a 6-byte table and offsets. Other functions read all but the
// zero objects.
// The functions of 0x0220b70c..0x0220d034 (eight files, merged in round dtB, each in its own
// namespace) are part of this TU: they read the name pointers through the .rodata base plus an
// offset, and name them (data_ov009_02215ee4/ee8/eec) instead of a data_ov009_02215ee4[n] array
// view; the vectors they pass are taken by address (&data_ov009_02215efc, &...f14) instead of u8[]
// externs. The readers before 0x0220acb8 (022088d8.cpp) are cut off by the unmatched 0220acb8.
extern const char *const data_ov009_02215ee4;
extern const u16 data_ov009_02215ef0[3];
extern const VecFx32 data_ov009_02215efc;
extern const VecFx32 data_ov009_02215f08;
extern const VecFx32 data_ov009_02215f14;
extern char data_ov009_0221727e[];
extern char data_ov009_02217284[];
extern char data_ov009_0221728a[];
static const VecFx16 data_ov009_02215ef6 = {0, 0, 0};
static const VecFx16 data_ov009_02217278 = data_ov009_02215ef6;
static const char *const data_ov009_02215ee8 = data_ov009_02217284;
const char *const data_ov009_02215ee4 = data_ov009_0221727e;
char data_ov009_0221727e[] = "nut00";
char data_ov009_0221728a[] = "att00";
const VecFx32 data_ov009_02215f14 = {0, 0x1800, -0xa000};
char data_ov009_02217284[] = "run00";
static const char *const data_ov009_02215eec = data_ov009_0221728a;
const VecFx32 data_ov009_02215f08 = {0, 0, 0x3000};
static const VecFx32 data_ov009_02215f20 = {0, 0, 0};
const VecFx32 data_ov009_02215efc = {0, 0x4000, -0x8000};
static const VecFx32 data_ov009_02217290 = data_ov009_02215f20;
const u16 data_ov009_02215ef0[3] = {0x1a0a, 0x0d05, 0};

// ---- merged from ov009_0220b70c.cpp
namespace m_0220b70c {
extern "C" {

extern const VecFx32 data_ov009_02215f74[];
extern VecFx32 data_ov009_02215f78[];
extern VecFx32 data_ov009_02215f7c[];
extern void Vec_RotateY(VecFx32 *out, const void *a, s32 b);
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);

static inline void Ov009_SetPos(Ov009ActVt_02217640 *self, s32 x, s32 y, s32 z) {
    self->pos.x = x;
    self->pos.y = y;
    self->pos.z = z;
}

void Ov009ActVt_02217640_Start(Ov009ActVt_02217640 *self) {
    ActorSub48 *s48;
    Ov003Actor_Start(self);
    if (self->unk_1a != 0) {
        Ov009_SetPos(self, data_ov009_02215f74[self->unk_1a - 1].x, data_ov009_02215f74[self->unk_1a - 1].y, data_ov009_02215f74[self->unk_1a - 1].z);
    }
    switch (self->kind) {
    case 0x5808:
    case 0x580a:
        self->unk_f7 = 0;
        break;
    case 0x5809:
    case 0x580b: {
        ActorSub48 *p;
        self->unk_f7 = 1;
        Vec_RotateY(&self->unk_fc, &data_ov009_02215efc, (u16)(Rand_PlusMinus(0x3c) * 0xb6));
        self->pos = self->unk_fc;
        self->unk_f2 = self->kind == 0x5809 ? 0x78 : 0xa0;
        p = self->hit;
        self->unk_f8 = p->radius << 1;
        p->unk_30 = 0;
        self->unk_93_4 = 1;
        break;
    }
    }
    switch (self->kind) {
    case 0x580b:
        self->unk_f6 = 0x96;
        self->unk_f4 = 0x64;
        break;
    case 0x5809:
        self->unk_f6 = 0xaa;
        self->unk_f4 = 0x96;
        break;
    }
    self->unk_f0 = 0;
    s48 = self->hit;
    s48->unk_9a_0 = 0;
    s48->unk_9a_3 = 0;
    HitSphere_Unlink_0203f364(s48);
    self->model->alpha = 0;
    self->unk_ea_14 = 1;
}


extern u8 data_ov009_02215f38[];
extern void *gSndMgr;
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern void Actor_PitchToPos(Actor *self, VecFx32 *v, s32 a);
extern void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);

static inline BOOL Ov009Game_IsPausedB(FieldState *g) {
    return g->event != 0;
}

void Ov009ActVt_02217640_Update(Ov009ActVt_02217640 *self) {
    Ov003Actor *pl;
    VecFx32 d;
    VecFx32 v;
    u8 k;
    self->target = 0xffff;
    {
        pl = ActorMgr_FindPlayer();
        if (pl != NULL) {
            self->target = pl->id;
        }
    }
    k = self->fsm->current;
    if (self->unk_f7 == 0) {
        Ov003Actor_Update(self);
        if (k == 1 || k == 0x20 || k == 2 || k == 0xf || (u8)(k + 0xee) <= 1) {
            Body_Update(self->hit, 1, 0, 0);
            v = self->pos;
            Geom_SnapToGround(&v, self->pos.y + 0x1800, -0xa000);
            self->pos.y += FX_Mul(*(volatile s32 *)&v.y + 0x1800 - self->pos.y, 0x19a);
            v.y += 0x1800;
            VEC_Distance(&self->pos, &v);
        }
    }
    if (self->unk_f7 == 1) {
        if (!Ov009_GameIdle()) {
            return;
        }
        if (Ov009Game_IsPausedB(gSceneCmd)) {
            return;
        }
        if (k == 1) {
            if (self->unk_f0 == 0) {
                self->unk_f0 = 4;
                self->fsm->flags |= 0x8000;
            } else if (self->unk_f0 & 1) {
                self->unk_b6++;
                if (self->unk_b6 > self->unk_f4) {
                    self->unk_f0 = 0;
                    self->unk_b6 = 0;
                }
            }
        } else if (k != 0xf && k != 0x11) {
            Vec_RotateY(&d, data_ov009_02215f38, self->rot_y);
            VEC_Add(&self->pos, &d, &d);
            Actor_PitchToPos(self, &d, 0x29);
        }
        Body_Update(self->hit, 1, 0, 0);
        if (self->pos.y <= -0x2000) {
            History_SetState(self->fsm, 0x11, 0);
        }
    }
    if ((self->msg_flags & 0x200) && *self->hp != 0) {
        SndMgr_PlayAt(gSndMgr, 0x40, &self->pos, 0);
    }
    if (self->pos.y <= -0x8000) {
        self->fsm->flags |= 0x200000;
    }
}

}
}  // namespace m_0220b70c

// ---- merged from ov009_0220bb70.cpp
namespace m_0220bb70 {
extern "C" {

extern void HitSphere_Link(ActorSub48 *p);
extern void *NNS_G3dGlbGetInvV(void);
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *other, s32 a);

static inline BOOL Ov009Game_IsPaused3(FieldState *g) {
    return g->event != 0;
}

void Ov009ActVt_02217640_State20(Ov009ActVt_02217640 *self) {
    VecFx32 p;
    VecFx32 v;
    ActorSub40 *st;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (Ov009Game_IsPaused3(gSceneCmd)) {
        return;
    }
    switch (self->fsm->st) {
    case 0: {
        ActorSub44 *s44;
        Model0218fe1c_SetAnim(self->model, data_ov009_02215ee4, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->fsm->timer = 0;
        self->fsm->st++;
    }
    case 1: {
        Model0218fe1c *m;
        u8 b;
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            s32 w;
            s32 y;
            s32 x;
            s32 r;
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            p.y -= self->centerY;
            w = self->radius;
            y = Rand_PlusMinus(self->height << 1);
            x = Rand_PlusMinus(w << 1);
            v.x = x;
            v.y = y;
            v.z = w;
            MTX_MultVec33(&v, (MtxFx33 *)NNS_G3dGlbGetInvV(), &v);
            VEC_Add(&v, &p, &v);
            r = Rand_UpTo(0x1000);
            Effect_SpawnId(0x389, &v)->SetScaleAll(r + 0x1000);
            self->fsm->timer = 5;
        }
        m = self->model;
        b = m->alpha;
        if (b < 0x1f) {
            b++;
            if (b >= 0x1f) {
                b = 0x1f;
            }
            m->alpha = b;
        } else {
            self->fsm->timer = 0;
            self->fsm->st = 0x1e;
        }
        break;
    }
    case 0x1e:
        st = self->fsm;
        st->timer++;
        if (st->timer >= 0x1e) {
            self->fsm->timer = 0;
            if (self->unk_f7 == 0) {
                ActorSub44 *s44 = self->unk_44;
                ActorSub48 *s48;
                s44->unk_22_0 = 1;
                s44->unk_22_1 = 1;
                s48 = self->hit;
                s48->unk_9a_0 = 1;
                s48->unk_9a_3 = 1;
                HitSphere_Link(s48);
            }
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
    Actor_TurnToActor(self, Actor_GetTarget(self), self->unk_b0->unk_02);
}

}
}  // namespace m_0220bb70

// ---- merged from ov009_0220be20.cpp
namespace m_0220be20 {
extern "C" {

extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *other, s32 a);

void Ov009ActVt_02217640_StateIdle(Ov009ActVt_02217640 *self) {
    VecFx32 d;
    switch (self->fsm->st) {
    case 0:
        {
            Model0218fe1c *m = self->model;
            const char *an = data_ov009_02215ee4;
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            Model0218fe1c_SetAnim(m, an, 0x89, 0);
        }
        Model0218fe1c_SetLoop(self->model);
        self->fsm->timer = 0;
        self->fsm->st++;
    case 1:
        if (self->unk_f7 == 1) {
            ActorSub40 *st = self->fsm;
            if (st->timer != 0) {
                st->timer--;
            }
            if (st->timer == 0) {
                self->fsm->timer = 0x32;
                self->unk_108 = self->unk_fc;
                self->unk_108.x += Rand_PlusMinus(0x800);
                self->unk_108.y += Rand_PlusMinus(0x800);
                self->unk_108.z += Rand_PlusMinus(0x800);
            }
            d.x = self->unk_108.x - self->pos.x;
            d.y = self->unk_108.y - self->pos.y;
            d.z = self->unk_108.z - self->pos.z;
            VEC_MultAdd(0xcd, &d, &self->pos, &self->pos);
        }
        break;
    }
    if (self->unk_f7 != 1) {
        return;
    }
    if (VEC_Distance(&self->pos, &self->unk_fc) > 0x6000) {
        self->unk_f0 = 0x10;
        History_SetState(self->fsm, 0x11, 0);
    }
    Actor_TurnToActor(self, Actor_GetTarget(self), self->unk_b0->unk_02);
}

}
}  // namespace m_0220be20

// ---- merged from ov009_0220bfcc.cpp
namespace m_0220bfcc {
extern "C" {

extern void Actor_MoveToPos(Ov003Actor *self, const VecFx32 *v, s32 a);

void Ov009ActVt_02217640_StateMove(Ov009ActVt_02217640 *self) {
    u8 k = self->unk_f7;
    if (k == 0) {
        VecFx32 v;
        Ov003Param *p;
        if (self->fsm->st == 0) {
            Model0218fe1c_SetAnim(self->model, data_ov009_02215ee8, 0x2ab, 0);
            Model0218fe1c_SetLoop(self->model);
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            self->fsm->st++;
        }
        v = self->unk_b8;
        p = self->unk_b0;
        self->speed = p->unk_00;
        Actor_MoveToPos(self, &v, p->unk_02);
    } else if (k == 1) {
        Ov003Actor_StateMove(self);
    }
}

}
}  // namespace m_0220bfcc

// ---- merged from ov009_0220c93c.cpp
namespace m_0220c93c {
extern "C" {

extern const VecFx32 data_ov009_02215f2c;
extern const VecFx32 data_ov009_02215f44;
extern void Vec_RotateY(VecFx32 *out, const void *a, s32 b);
extern void Actor_PitchToPos(Actor *self, const VecFx32 *v, s32 a);
extern void Actor_TurnToPos(Ov003Actor *self, const VecFx32 *v, s32 a);

struct Ov009RotC {
    u16 x;
    u16 y;
    u16 z;
};

static inline s32 Ov009_Sqrt64c(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline s32 Ov009_DistXZc(const VecFx32 *a, const VecFx32 *b) {
    s64 sq;
    s32 dz = a->z - b->z;
    s32 dx = a->x - b->x;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov009_Sqrt64c(sq);
}

extern void *gSndMgr;
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern void HitSphere_Link(ActorSub48 *p);
extern void *SndMgr_PlayAtPitch(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern void *SndMgr_PlayAt(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *other, s32 a);
extern void Model0218fe1c_PauseAnim(void *p);
extern void Model0218fe1c_ResumeAnim(void *p);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern BOOL func_ov000_0219aca8(Ov003Actor *a, Ov003Actor *b, u16 c, u8 d, s32 e, Ov009RotC *f, s32 g, s32 h, s32 i, s32 j);
extern void Field_ShakeCamera(s32 a, s32 b);

void Ov009ActVt_02217640_StateAttack(Ov009ActVt_02217640 *self) {
    VecFx32 a;
    VecFx32 v;
    VecFx32 w;
    Ov009RotC r;
    Ov003Actor *t;
    s32 y0 = 0;
    if (self->unk_f7 == 0) {
        EffectObj *o;
        Ov003Actor_StateAttack(self);
        if (self->model->anim_state != 2) {
            return;
        }
        o = Effect_SpawnId(0x130, &self->pos);
        *(Ov009Blk12 *)&a = *(const Ov009Blk12 *)&data_ov009_02215f08;
        Vec_RotateY(&a, &a, self->rot_y);
        o->AddPos(&a);
        o->SetRotXYZ(0x4000, self->rot_y, self->rot_z);
        o->SetScaleAll(0xb33);
        EffectObj_AddSndCue(o, 0x82, 0);
        return;
    }
    t = Actor_GetTarget(self);
    v = t->pos;
    v.y = y0;
    switch (self->fsm->st) {
    case 0:
    {
        ActorSub48 *s48;
        Model0218fe1c_SetAnim(self->model, data_ov009_02215eec, 0x111, 0);
        s48 = self->hit;
        self->speed = 0xcd;
        self->velY = 0x7b;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        HitSphere_Unlink_0203f364(s48);
    }
        SndMgr_PlayAtPitch(gSndMgr, 0x5b, &self->pos, 2);
        self->fsm->timer = 0;
        self->fsm->st++;
    case 1:
        Actor_TurnToActor(self, t, self->unk_b0->unk_02);
        self->moveYaw = self->rot_y;
        v.y = -0x1000;
        Actor_PitchToPos(self, &v, self->unk_b0->unk_02);
        Actor_Move(self, 0);
        if (Model0218fe1c_IsAnimDone(self->model)) {
            Model0218fe1c_PauseAnim(self->model);
            self->fsm->st++;
        }
        break;
    case 2: {
        ActorSub40 *s = self->fsm;
        s->timer++;
        if (s->timer > 0x14) {
            s32 ang;
            Model0218fe1c_ResumeAnim(self->model);
            v.y = y0 - 0x1000;
            self->unk_84 = v;
            ang = FX_Atan2(Ov009_DistXZc(&self->pos, &self->unk_84), self->unk_84.y - self->pos.y);
            {
                s32 sn = OV009_SIN(ang);
                s32 cs = OV009_COS(ang);
                s32 spd = self->unk_b0->unk_00;
                self->speed = FX_Mul(spd, sn);
                self->velY = FX_Mul(spd, cs);
            }
            SndMgr_PlayAtPitch(gSndMgr, 0x32, &self->pos, 5);
            self->moveYaw = self->rot_y;
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    }
    case 3:
        Actor_Move(self, 0);
        if (*ActorMgr_FindPlayer()->hp != 0) {
            r = *(Ov009RotC *)&self->rot_x;
            r.x += 0x4000;
            func_ov000_0219aca8(self, self, self->unk_f2, self->targetObj->unk_0a, 0, &r, 0x99a, 0x2000, 100, 0x1000);
        }
        if (self->hit->unk_50 & 0x20000000) {
            Field_ShakeCamera(0xf, 0xf);
            SndMgr_PlayAt(gSndMgr, 0x52, &self->pos, 0);
            w = self->pos;
            w.y = 0;
            Effect_SpawnId(0x67, &w)->SetRotXYZ(0, (u16)(self->rot_y + 0x7fff), 0);
            {
                ActorSub48 *s48;
                ActorSub44 *s44;
                self->hit->radius = self->unk_f8 >> 1;
                s48 = self->hit;
                s48->unk_9a_0 = 1;
                s48->unk_9a_3 = 1;
                HitSphere_Link(s48);
                self->hit->unk_30 = 0x40000000;
                s44 = self->unk_44;
                s44->unk_22_0 = 1;
                s44->unk_22_1 = 1;
            }
            self->fsm->st++;
        }
        break;
    case 4: {
        ActorSub40 *s = self->fsm;
        s->timer++;
        if (s->timer > self->unk_f6) {
            self->fsm->timer = 0;
            History_SetState(self->fsm, 0x11, 0);
        }
        break;
    }
    }
    self->unk_ea_0 = 3;
}

void Ov009ActVt_02217640_StateAttack3(Ov009ActVt_02217640 *self) {
    VecFx32 t1;
    VecFx32 t2;
    VecFx32 d;
    self->unk_94_1 = 1;
    switch (self->fsm->st) {
    case 0: {
        ActorSub44 *s44;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->timer = 0;
        self->hit->radius = self->unk_f8;
        self->hit->unk_30 = 0;
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        if (self->unk_f0 & 4) {
            *(Ov009Blk12 *)&t1 = *(const Ov009Blk12 *)&data_ov009_02215f2c;
            t1.y = self->unk_fc.y + 0x1000;
            Vec_RotateY(&t1, &t1, self->rot_y);
            VEC_Add(&self->pos, &t1, &t1);
            self->unk_b8 = t1;
            self->fsm->st = 10;
        } else {
            Model0218fe1c_SetAnim(self->model, data_ov009_02215ee4, 0x400, 0);
            Model0218fe1c_SetLoop(self->model);
            self->rot_x = 0;
            self->fsm->st++;
        }
        break;
    }
    case 1:
        if (self->pos.y < 0x2800) {
            self->velY = 0x266;
            break;
        }
        if (self->pos.y >= 0x2800 && self->pos.y < self->unk_fc.y) {
            self->velY = 0x7b;
            break;
        }
        self->fsm->st = 0x14;
        break;
    case 10:
        {
            s32 bx = self->unk_b8.x;
            s32 by = self->unk_b8.y;
            s32 bz = self->unk_b8.z;
            d.x = bx - self->pos.x;
            d.y = by - self->pos.y;
            d.z = bz - self->pos.z;
        }
        VEC_MultAdd(0x19a, &d, &self->pos, &self->pos);
        if (VEC_Distance(&self->pos, &self->unk_b8) <= 0x1000) {
            Model0218fe1c_SetAnim(self->model, data_ov009_02215ee4, 0x89, 0);
            Model0218fe1c_SetLoop(self->model);
            self->fsm->st++;
        }
        break;
    case 11: {
        ActorSub40 *s;
        *(Ov009Blk12 *)&t2 = *(const Ov009Blk12 *)&data_ov009_02215f44;
        Vec_RotateY(&t2, &t2, self->rot_y);
        VEC_Add(&self->pos, &t2, &t2);
        Actor_PitchToPos(self, &t2, 0x11f);
        s = self->fsm;
        s->timer++;
        if (s->timer >= 0x32) {
            self->fsm->st = 0x14;
        }
        break;
    }
    case 0x14:
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->speed = 0x333;
        Vec_RotateY(&self->unk_fc, &data_ov009_02215efc, (u16)(Rand_PlusMinus(0x3c) * 0xb6));
        self->unk_b8 = self->unk_fc;
        Model0218fe1c_SetAnim(self->model, data_ov009_02215ee8, 0x111, 0);
        Model0218fe1c_SetLoop(self->model);
        self->fsm->st++;
    case 0x15:
        Actor_TurnToPos(self, &self->unk_fc, 0xcd);
        self->moveYaw = self->rot_y;
        if (VEC_Distance(&self->pos, &self->unk_b8) <= 0x4000) {
            self->friction = 0xf85;
            self->fsm->st++;
        }
        break;
    case 0x16:
        if (self->speed <= 0x52) {
            self->unk_f0 = 1;
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
    Actor_Move(self, 0);
}

void Ov009ActVt_02217640_StateDown(Ov009ActVt_02217640 *self) {
    if (self->fsm->st == 0 && self->unk_f7 == 1) {
        self->hit->radius = self->unk_f8;
        self->rot_x = 0;
    }
    Ov003Actor_StateDown(self);
}

}
}  // namespace m_0220c93c

// ---- merged from ov009_0220c970.cpp
namespace m_0220c970 {
extern "C" {

extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern void Actor_TurnToPos(Ov003Actor *self, const VecFx32 *v, s32 a);

void Ov009ActVt_02217640_StateDie(Ov009ActVt_02217640 *self) {
    switch (self->fsm->st) {
    case 0: {
        ActorSub48 *s48 = self->hit;
        ActorSub44 *s44;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        HitSphere_Unlink_0203f364(s48);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->targetObj->target = 0xffff;
        EffectObj_AddSndCue(Effect_SpawnId(0x38a, &self->pos), 0x40, 0);
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    }
    case 1: {
        ActorSub40 *st = self->fsm;
        st->timer++;
        if (st->timer > 0x3c) {
            Ov003Actor_Defeat(self, 1, 1, 1);
        } else {
            Ov003Actor_SetAlpha(self, 0x1f - (self->fsm->timer >> 1));
        }
        break;
    }
    }
}

extern void Vec_RotateY(VecFx32 *out, const void *a, s32 b);

void Ov009ActVt_022174e8_Start(Ov003Actor *self) {
    VecFx32 t;
    Ov003Actor *a;
    ActorSub44 *s44;
    void *saved;
    Ov003Actor_Start(self);
    self->speed = 0x52;
    Vec_RotateY(&t, &data_ov009_02215f14, (u16)(Rand_PlusMinus(0x1e) * 0xb6));
    VEC_Add(&self->pos, &t, &self->pos);
    a = ActorMgr_FindPlayer();
    {
        s32 x = a->pos.x;
        s32 z = a->pos.z;
        s32 y = self->pos.y;
        self->unk_b8.x = x;
        self->unk_b8.y = y;
        self->unk_b8.z = z;
    }
    self->model->alpha = 0;
    self->unk_ea_6 = 1;
    self->hit->unk_30 = 0;
    s44 = self->unk_44;
    s44->unk_22_0 = 0;
    s44->unk_22_1 = 0;
    saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (self->unk_3c != NULL) {
        if (self->unk_3c != NULL) {
            self->unk_3c->vfunc_04();
        }
        self->unk_3c = NULL;
    }
    gSysState->cur = saved;
}

}
}  // namespace m_0220c970

// ---- merged from ov009_0220cb64.cpp
namespace m_0220cb64 {
extern "C" {

extern Ov003Actor *ActorMgr_FindPlayer(void);
extern void Actor_TurnToPos(Ov003Actor *self, const VecFx32 *v, s32 a);

void Ov009ActVt_022174e8_State20(Ov003Actor *self) {
    VecFx32 v;
    if (self->fsm->st == 0) {
        u8 n = self->model->alpha;
        if (n < 0x1f) {
            n = n + 1;
            if (n >= 0x1f) {
                ActorSub44 *s44 = self->unk_44;
                s44->unk_22_0 = 1;
                s44->unk_22_1 = 1;
                n = 0x1f;
                History_SetState(self->fsm, 1, 0);
            }
            self->model->alpha = n;
        }
    }
    v = ActorMgr_FindPlayer()->pos;
    Actor_TurnToPos(self, &v, 0x1000);
    self->moveYaw = self->rot_y;
    Actor_Move(self, 0);
}

}
}  // namespace m_0220cb64

// ---- merged from ov009_0220cc24.cpp
namespace m_0220cc24 {
extern "C" {

extern s32 Actor_FindInRadius(Actor *self, s32 a, const VecFx32 *pos, s32 r, s32 b, void **out);
extern BOOL Obj021984c8_GetActor(void *p);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern void Actor_TurnToPos(Ov003Actor *self, const VecFx32 *v, s32 a);

void Ov009ActVt_022174e8_StateIdle(Ov003Actor *self) {
    VecFx32 v;
    void *list[32];
    s32 i;
    s32 n;
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov009_02215ee4, 0x111, 0);
        Model0218fe1c_SetLoop(self->model);
        self->fsm->timer = 0;
        self->fsm->st++;
    case 1:
        n = Actor_FindInRadius(self, 2, &self->pos, 0x1000, 0, list);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                if (list[i] != NULL && Obj021984c8_GetActor(list[i])) {
                    History_SetState(self->fsm, 0x15, 0);
                    break;
                }
            }
        }
        break;
    }
    v = ActorMgr_FindPlayer()->pos;
    Actor_TurnToPos(self, &v, 0x1000);
    self->moveYaw = self->rot_y;
    Actor_Move(self, 0);
}

extern void *gSndMgr;
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern void *NNS_G3dGlbGetInvV(void);
extern void *SndMgr_PlayAtPitch(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern BOOL Hit_ApplyInArea(void *a, void *b, u16 c, u8 d, s32 e, void *f, s32 g, s32 h, s32 i, s32 j, s32 k);
void Ov009ActVt_022174e8_StateDie(Ov003Actor *self) {
    VecFx32 p;
    VecFx32 v;
    ActorSub40 *st = self->fsm;
    switch (st->st) {
    case 0: {
        ActorSub48 *s48;
        ActorSub44 *s44;
        *self->hp = 0;
        s48 = self->hit;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        HitSphere_Unlink_0203f364(s48);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->targetObj->target = 0xffff;
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    }
    case 1:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            s32 w;
            s32 y;
            s32 x;
            s32 s;
            s16 n;
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            w = self->radius;
            y = Rand_PlusMinus(self->height);
            x = Rand_PlusMinus(w);
            v.x = x;
            v.y = y;
            v.z = w;
            MTX_MultVec33(&v, (MtxFx33 *)NNS_G3dGlbGetInvV(), &v);
            VEC_Add(&v, &p, &v);
            s = Rand_UpTo(0x4cd) + 0x4cd;
            n = self->unk_18;
            if (n % 3 == 0) {
                Effect_SpawnId(0x69, &self->pos)->SetScaleAll(0x1333);
                Effect_SpawnId(4, &self->pos);
                if (n >= 9) {
                    self->fsm->st++;
                }
            } else {
                Effect_SpawnId(0x69, &v)->SetScaleAll(s);
                if (n % 2 == 0) {
                    Effect_SpawnId(4, &v)->SetScaleAll(s);
                }
                self->fsm->timer = 5;
            }
            SndMgr_PlayAtPitch(gSndMgr, 0x2b, &v, -5);
            self->unk_18 = n + 1;
        }
        if (*ActorMgr_FindPlayer()->hp == 0) {
            return;
        }
        Hit_ApplyInArea(self, self, 0xc8, self->targetObj->unk_0a, 2, NULL, 0, 0x2000, 0, 0x64, 0x1000);
        break;
    case 2: {
        u8 b = self->model->alpha;
        if (b == 0) {
            return;
        }
        b--;
        if (b == 0) {
            st->st = 10;
            b = 0;
        }
        self->model->alpha = b;
        break;
    }
    case 10:
        Ov003Actor_Defeat(self, 1, 1, 1);
        break;
    }
}

}
}  // namespace m_0220cc24
