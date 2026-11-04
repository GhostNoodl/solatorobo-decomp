#include "ov009/ov009.h"
#include "ov000/FieldCam.h"
#include "Main/Res/ResArc.h"
#include "nitro/mi.h"


// A header's zero rotation and vector, plus copies made at startup, among this TU's motion
// and effect names, the 16 pointers to them, and the offsets and sizes other functions read.
// The functions of 0x021ff730..0x0220413c (19 files, merged in round dtB, each in its own
// namespace) are part of this TU: they read the 16 name pointers through the .rodata base plus an
// offset, and name them (data_ov009_02215d0c..02215d48) instead of a data_ov009_02215d0c[n] array
// view. Round dtD merged 0x0220413c..0x02204a10 (five files) too: Ov009ActVt_02216bc8_Start copies the
// zero vector data_ov009_02215d90 (base + 0x84) with struct assignments, into each trail entry and
// then into the model's position. Written as x/y/z field reads its y/z loads are CSE'd (42 lines).

extern const char *const data_ov009_02215d0c;
extern const s32 data_ov009_02215d54[2];
extern const s32 data_ov009_02215d5c[2];
extern const s16 data_ov009_02215d64[4];
extern const Ov009Blk12 data_ov009_02215d6c;
extern const VecFx32 data_ov009_02215d78;
extern const VecFx32 data_ov009_02215d84;
extern char data_ov009_02216ad4[];
extern char data_ov009_02216ada[];
extern char data_ov009_02216ae0[];
extern char data_ov009_02216ae6[];
extern char data_ov009_02216aec[];
extern char data_ov009_02216af2[];
extern char data_ov009_02216afe[];
extern char data_ov009_02216b04[];
extern char data_ov009_02216b0a[];
extern char data_ov009_02216b10[];
extern char data_ov009_02216b17[];
extern char data_ov009_02216b1e[];
extern char data_ov009_02216b25[];
extern char data_ov009_02216b2f[];
extern char data_ov009_02216b39[];
extern char data_ov009_02216b43[];
extern char data_ov009_02216b4f[];
static const char *const data_ov009_02215d44 = data_ov009_02216b17;
static const char *const data_ov009_02215d40 = data_ov009_02216b1e;
static const char *const data_ov009_02215d10 = data_ov009_02216b25;
char data_ov009_02216afe[] =
#include "romdata/ov009/02216afe.inc"
;
const char *const data_ov009_02215d0c = data_ov009_02216ae0;
static const char *const data_ov009_02215d38 = data_ov009_02216b39;
char data_ov009_02216b2f[] =
#include "romdata/ov009/02216b2f.inc"
;
static const char *const data_ov009_02215d48 = data_ov009_02216b2f;
static const char *const data_ov009_02215d18 = data_ov009_02216aec;
const s32 data_ov009_02215d54[2] = {0xe02, 0xf02};
char data_ov009_02216b4f[] =
#include "romdata/ov009/02216b4f.inc"
;
const s16 data_ov009_02215d64[4] = {0x1000, 0x1000, 0x2000, 0x1000};
char data_ov009_02216b0a[] =
#include "romdata/ov009/02216b0a.inc"
;
static const char *const data_ov009_02215d34 = data_ov009_02216af2;
char data_ov009_02216ada[] =
#include "romdata/ov009/02216ada.inc"
;
static const char *const data_ov009_02215d28 = data_ov009_02216ada;
char data_ov009_02216b43[] =
#include "romdata/ov009/02216b43.inc"
;
char data_ov009_02216b17[] =
#include "romdata/ov009/02216b17.inc"
;
const Ov009Blk12 data_ov009_02215d6c = {0x02520000, 0, 0xffff};
char data_ov009_02216ae6[] =
#include "romdata/ov009/02216ae6.inc"
;
char data_ov009_02216af2[] =
#include "romdata/ov009/02216af2.inc"
;
static const char *const data_ov009_02215d1c = data_ov009_02216ae6;
const VecFx32 data_ov009_02215d84 = {0, 0x2f33, 0x2733};
char data_ov009_02216b1e[] =
#include "romdata/ov009/02216b1e.inc"
;
static const VecFx32 data_ov009_02215d90 = {0, 0, 0};
char data_ov009_02216b39[] =
#include "romdata/ov009/02216b39.inc"
;
const s32 data_ov009_02215d5c[2] = {0xd02, 0x1002};
static const VecFx16 data_ov009_02215d4c = {0, 0, 0};
char data_ov009_02216ad4[] =
#include "romdata/ov009/02216ad4.inc"
;
char data_ov009_02216b10[] =
#include "romdata/ov009/02216b10.inc"
;
char data_ov009_02216b25[] =
#include "romdata/ov009/02216b25.inc"
;
static const char *const data_ov009_02215d30 = data_ov009_02216ad4;
static const VecFx16 data_ov009_02216af8 = data_ov009_02215d4c;
static const char *const data_ov009_02215d3c = data_ov009_02216b04;
static const char *const data_ov009_02215d20 = data_ov009_02216afe;
static const char *const data_ov009_02215d2c = data_ov009_02216b0a;
char data_ov009_02216ae0[] =
#include "romdata/ov009/02216ae0.inc"
;
char data_ov009_02216aec[] =
#include "romdata/ov009/02216aec.inc"
;
static const char *const data_ov009_02215d14 = data_ov009_02216b10;
static const char *const data_ov009_02215d24 = data_ov009_02216ad4;
const VecFx32 data_ov009_02215d78 = {0, 0x3800, 0};
char data_ov009_02216b04[] =
#include "romdata/ov009/02216b04.inc"
;
static const VecFx32 data_ov009_02216b5c = data_ov009_02215d90;

// ---- merged from ov009_021ff730.cpp
namespace m_021ff730 {
extern "C" {


void Ov009ActVt_022171d4_State20(Ov009ActVt_022171d4 *self) {
    if (self->unk_f4 != 0) {
        self->unk_f4--;
    } else {
        History_SetState(self->fsm, 1, 0);
    }
    self->vfunc_50();
}

void Ov009ActVt_022171d4_StateIdle(Ov009ActVt_022171d4 *self) {
    VecFx32 d;
    ActorSub40 *st;
    VecFx32 *f8 = &self->unk_f8;
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov009_02215d30, 0x111, 0);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->unk_b8 = self->pos;
        self->unk_f0 = 1;
        self->fsm->timer = 0;
        self->fsm->st++;
    case 1:
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            self->fsm->timer = 0x3c;
            *f8 = self->unk_b8;
            f8->x += Rand_PlusMinus(0x800);
            f8->z += Rand_PlusMinus(0x800);
            Geom_SnapToGround(f8, self->pos.y + 0x2000, -0xa000);
            f8->y = f8->y + Rand_PlusMinus(0x800) + 0x3000;
        }
        d.x = f8->x - self->pos.x;
        d.y = f8->y - self->pos.y;
        d.z = f8->z - self->pos.z;
        VEC_MultAdd(0x52, &d, &self->pos, &self->pos);
        break;
    }
    Body_Update(self->hit, 1, 0, 0);
}

extern void Actor_MoveToPos(Ov003Actor *self, VecFx32 *v, s32 a);

void Ov009ActVt_022171d4_StateMove(Ov009ActVt_022171d4 *self) {
    VecFx32 v;
    VecFx32 p;
    s32 d;
    if (self->fsm->st == 0) {
        Model0218fe1c_SetAnim(self->model, data_ov009_02215d30, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
    }
    v = self->unk_b8;
    self->speed = self->unk_b0->unk_00;
    Actor_MoveToPos(self, &v, self->unk_b0->unk_02);
    Body_Update(self->hit, 1, 0, 0);
    p = self->pos;
    d = self->pos.y + 0x2000;
    Geom_SnapToGround(&p, d, -0xa000);
    d = p.y + 0x3000;
    d -= self->pos.y;
    self->pos.y += FX_Mul(d, 0xcd);
    p.y += 0x3000;
    VEC_Distance(&self->pos, &p);
}

}
}  // namespace m_021ff730

// ---- merged from ov009_021ffa40.cpp
namespace m_021ffa40 {
extern "C" {

extern void *gSndMgr;
extern const VecFx32 data_ov009_02215da8;
extern const VecFx32 data_ov009_02215d9c;
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern void Actor_MoveToPos(Ov003Actor *self, VecFx32 *v, s32 a);
extern void *SndMgr_PlayAt(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern void Field_ShakeCameraY(s32 a, s32 b);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern BOOL Hit_ApplyInArea(void *a, void *b, u16 c, u8 d, u16 mask, const VecFx32 *v, s32 e, s32 f, s32 g, s32 h, s32 i);
extern void Model0218fe1c_PauseAnim(void *p);

static inline s32 Ov009_FxMulL(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline void Ov009_Ground(VecFx32 *out, Ov003Actor *self) {
    *out = self->pos;
    Geom_SnapToGround(out, self->pos.y + 0x2000, -0xa000);
}

static inline s32 Ov009_Hover(Ov009ActVt_022171d4 *self, s32 h, s64 rate) {
    VecFx32 p;
    Ov009_Ground(&p, self);
    s32 d = p.y + h;
    d -= self->pos.y;
    self->pos.y += Ov009_FxMulL(d, rate);
    p.y += h;
    return VEC_Distance(&self->pos, &p);
}

void Ov009ActVt_022171d4_StateAttack(Ov009ActVt_022171d4 *self) {
    VecFx32 tp;
    VecFx32 b;
    VecFx32 p3;
    Ov003Actor *t;
    Ov003Param *prm;
    ActorSub40 *st;
    t = Actor_GetTarget(self);
    tp.x = t->pos.x;
    tp.y = t->pos.y;
    tp.z = t->pos.z;
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov009_02215d2c, 0x400, 0);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->timer = 0;
        self->fsm->st++;
    case 1:
        prm = self->unk_b0;
        self->speed = prm->unk_00 * 2;
        Actor_MoveToPos(self, &tp, prm->unk_02);
        Ov009_Hover(self, 0x4800, 0xcd);
        tp.y = self->pos.y;
        if (VEC_Distance(&self->pos, &tp) < 0x1000) {
            Model0218fe1c_SetAnim(self->model, data_ov009_02215d0c, 0x400, 0);
            self->unk_b8.x = tp.x;
            self->unk_b8.y = tp.y;
            self->unk_b8.z = tp.z;
            SndMgr_PlayAt(gSndMgr, 0x39, &self->pos, 0x280);
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        st = self->fsm;
        st->timer++;
        if (st->timer > 200) {
            self->fsm->timer = 0;
            History_SetState(self->fsm, 1, 0);
        }
        break;
    case 2:
        b.x = self->unk_b8.x;
        b.y = self->unk_b8.y;
        b.z = self->unk_b8.z;
        prm = self->unk_b0;
        self->speed = prm->unk_00;
        Actor_MoveToPos(self, &b, prm->unk_02);
        Ov009_Hover(self, 0x6000, 0x148);
        if (self->model->anim_state == 1) {
            Ov009_Ground(&self->unk_84, self);
            SndMgr_PlayAt(gSndMgr, 0x54, &self->pos, 0);
            self->speed = 0;
            self->friction = 0;
            self->gravity = 0;
            self->velY = -0x800;
            self->fsm->st++;
        }
        break;
    case 3:
        if (self->pos.y <= self->unk_84.y + 0x1b33) {
            Field_ShakeCameraY(0xf, 0xf);
            Ov009_Ground(&p3, self);
            Effect_SpawnId(0x68, &p3)->AddPos(&data_ov009_02215da8);
            SndMgr_PlayAt(gSndMgr, 0x7b, &self->pos, 0);
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            self->fsm->st++;
        } else {
            Actor_Move(self, 0);
            if (*ActorMgr_FindPlayer()->hp != 0 && Ov009_GameIdle()) {
                Hit_ApplyInArea(self, self, self->unk_f2, self->targetObj->unk_0a, 2, &data_ov009_02215d9c, 0, 0x800, 0x2000, 0x64, 0x1000);
            }
        }
        break;
    case 4: {
        u16 tm;
        st = self->fsm;
        st->timer++;
        tm = st->timer;
        if (tm > 200) {
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        if (tm == 0xbe) {
            Model0218fe1c_PauseAnim(self->model);
        }
        break;
    }
    case 5:
        if (Ov009_Hover(self, 0x5000, 0x333) <= 0x333) {
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
    Body_Update(self->hit, 1, 0, 0);
}

}
}  // namespace m_021ffa40

// ---- merged from ov009_021ffff4.cpp
namespace m_021ffff4 {
extern "C" {

extern void *gSndMgr;
extern u8 data_ov009_02215dc0[];
extern void *SndMgr_PlayAt(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern void Vec_RotateY(VecFx32 *out, const void *a, u16 ang);
extern void HitSphere_Unlink_0203f2b8(void *p);

void Ov009ActVt_022171d4_StateDown(Ov009ActVt_022171d4 *self) {
    if (self->fsm->st == 0) {
        SndMgr_PlayAt(gSndMgr, 0x6b, &self->pos, 0);
    }
    Ov003Actor_StateDown(self);
}

void Ov009ActVt_02217128_Init(Ov009ActVt_02217128 *self) {
    GroupNode *p;
    Ov003Actor_Init(self);
    p = Group_FindNode(gGroup, self->unk_20);
    if (p != NULL) {
        GroupNodeFlags *b = &p->flags;
        b->unk_0 = 0;
        b->unk_5 = 1;
    }
}

void Ov009ActVt_02217128_Start(Ov009ActVt_02217128 *self) {
    VecFx32 t;
    void *saved;
    Ov003Actor_Start(self);
    self->unk_f8 = self->pos;
    self->unk_84 = self->pos;
    self->unk_f0 = 0;
    Vec_RotateY(&t, data_ov009_02215dc0, 0x5554);
    VEC_Add(&self->unk_84, &t, &self->pos);
    self->unk_b8 = self->pos;
    switch (self->kind) {
    case 0x5423:
        self->unk_f4 = 0x32000;
        break;
    case 0x5424:
        self->unk_f4 = 0x6000;
        break;
    }
    saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (self->unk_3c != NULL) {
        if (self->unk_3c != NULL) {
            self->unk_3c->vfunc_04();
        }
        self->unk_3c = NULL;
    }
    gSysState->cur = saved;
    saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (self->hit != NULL) {
        ActorSub48 *p = self->hit;
        if (p != NULL) {
            HitSphere_Unlink_0203f2b8(p);
            Heap_Free(p);
        }
        self->hit = NULL;
    }
    gSysState->cur = saved;
    saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (self->unk_44 != NULL) {
        Heap_Free(self->unk_44);
        self->unk_44 = NULL;
    }
    gSysState->cur = saved;
}

extern Ov003Actor *ActorMgr_FindPlayer(void);
extern void *SndMgr_PlayAtPitch(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern BOOL Hit_ApplyInArea(void *a, void *b, u16 c, u8 d, s32 e, VecFx32 *v, s32 f, s32 g, s32 h, s32 i, s32 j);

struct Ov009HitMsg2 {
    u8 a;
    u16 b;
    u16 c;
};

static inline s32 Ov009_StateOf(ActorSub40 *s) {
    return s != NULL ? s->current : 0;
}

void Ov009ActVt_02217128_Update(Ov009ActVt_02217128 *self) {
    VecFx32 v;
    Ov009HitMsg2 msg;
    Ov003Actor *pl;
    Ov003Actor_Update(self);
    pl = ActorMgr_FindPlayer();
    if (pl == NULL || *pl->hp == 0) {
        return;
    }
    if (!(self->unk_f0 & 1)) {
        return;
    }
    if (Ov009_StateOf(pl->fsm) == 7 || Ov009_StateOf(pl->fsm) == 0x16 || Ov009_StateOf(pl->fsm) == 0x10) {
        self->unk_f0 ^= 1;
        History_SetState(self->fsm, 0x13, 0);
    } else if (((Robo021ca458 *)ActorMgr_FindPlayer())->unk_b22_0 == 4) {
        self->unk_f0 ^= 1;
        History_SetState(self->fsm, 0x13, 0);
    } else if (Ov009_GameIdle()) {
        s16 cnt = self->unk_18;
        switch (self->kind) {
        case 0x5424:
            msg.a = 1;
            msg.b = 0x333;
            msg.c = 0xf;
            Actor_SendMsg(pl, self->id, 0xb, TRUE, 6, &msg);
            cnt++;
            if (cnt % 200 == 0) {
                EffectObj *e;
                cnt = 0;
                Hit_ApplyInArea(self, self, 0xa, 1, 2, NULL, 0, 0x2000, 0, -1, 0x1000);
                v.x = pl->pos.x;
                v.y = pl->pos.y;
                v.z = pl->pos.z;
                e = Effect_SpawnId(0x38b, &v);
                e->SetScaleAll(0xb33);
                e->AddPosXYZ(0, 0x1000, 0);
                SndMgr_PlayAtPitch(gSndMgr, 0x54, &v, -5);
            }
            self->unk_18 = cnt;
            break;
        case 0x5423:
            if (((Robo021ca458 *)pl)->unk_b24_1) {
                cnt++;
                if (cnt % 100 == 0) {
                    cnt = 0;
                    SndMgr_PlayAtPitch(gSndMgr, 0x36, &self->pos, -10);
                }
                self->unk_18 = cnt;
                msg.a = 2;
                msg.c = 8;
                Actor_SendMsg(pl, self->id, 0xb, TRUE, 6, &msg);
            }
            break;
        }
    }
    if (self->kind == 0x5423 && VEC_Distance(&self->pos, &self->unk_f8) > self->unk_f4) {
        self->unk_f0 ^= 1;
        History_SetState(self->fsm, 0x13, 0);
    }
}

extern u8 data_ov009_02215dcc[];
extern void Actor_TurnToPos(Ov003Actor *self, const VecFx32 *v, s32 a);

static inline s32 Ov009_Sqrt64(s64 v) {
    *(volatile u16 *)0x40002b0 = 1;
    *(volatile u64 *)0x40002b8 = (u64)v << 2;
    while (*(volatile u16 *)0x40002b0 & 0x8000) {
    }
    return (*(volatile s32 *)0x40002b4 + 1) >> 1;
}

static inline BOOL Ov009_TickTimer(ActorSub40 *s) {
    if (s->timer != 0) {
        s->timer--;
    }
    return s->timer == 0;
}

static inline BOOL Ov009Game_IsPaused(FieldState *g) {
    return g->event != 0;
}

void Ov009ActVt_02217128_StateIdle(Ov009ActVt_02217128 *self) {
    VecFx32 plpos;
    VecFx32 off;
    VecFx32 d;
    Ov003Actor *pl;
    ActorSub40 *st;
    s32 speed;
    u16 ang;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (Ov009Game_IsPaused(gSceneCmd)) {
        return;
    }
    pl = ActorMgr_FindPlayer();
    if (pl == NULL) {
        return;
    }
    plpos = pl->pos;
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov009_02215d30, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    case 1:
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            self->fsm->timer = 0x3c;
            self->unk_104 = self->unk_b8;
            self->unk_104.x += Rand_PlusMinus(0x800);
            self->unk_104.z += Rand_PlusMinus(0x800);
            self->unk_104.y += Rand_PlusMinus(0x800);
        }
        d.x = self->unk_104.x - self->pos.x;
        d.y = self->unk_104.y - self->pos.y;
        d.z = self->unk_104.z - self->pos.z;
        VEC_MultAdd(0x52, &d, &self->pos, &self->pos);
        if (VEC_Distance(&self->unk_84, &plpos) <= self->unk_f4) {
            self->fsm->st++;
        }
        break;
    case 2: {
        s64 sq;
        s32 dz;
        s32 dx;
        self->unk_84 = self->pos;
        Vec_RotateY(&off, data_ov009_02215dcc, 0x5554);
        VEC_Add(&plpos, &off, &plpos);
        dz = self->pos.z - plpos.z;
        dx = self->pos.x - plpos.x;
        sq = (s64)dx * dx;
        sq += (s64)dz * dz;
        ang = FX_Atan2(Ov009_Sqrt64(sq), plpos.y - self->pos.y);
        switch (self->kind) {
        case 0x5423:
            speed = 0x800;
            break;
        case 0x5424:
            speed = 0x333;
            break;
        }
        self->speed = FX_Mul(speed, OV009_SIN(ang));
        self->velY = FX_Mul(speed, OV009_COS(ang));
        Actor_TurnToPos(self, &plpos, 0x1000);
        self->moveYaw = self->rot_y;
        Actor_Move(self, 0);
        if (VEC_Distance(&self->pos, &plpos) > 0x1000) {
            return;
        }
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        if (self->kind == 0x5423) {
            self->speed = 0x4cd;
        } else {
            self->speed = speed;
        }
        self->fsm->st++;
        self->fsm->timer = 0;
        self->unk_f0 |= 1;
        break;
    }
    case 3:
        Actor_Move(self, 0);
        self->pos.y = plpos.y + 0x2000;
        Actor_TurnToPos(self, &plpos, 0x19a);
        self->moveYaw = self->rot_y;
        self->unk_84 = plpos;
        st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer != 0) {
            return;
        }
        {
            s32 se = 0x80;
            if (self->kind == 0x5423) {
                se = 0xa;
            }
            SndMgr_PlayAt(gSndMgr, se, &self->pos, 0);
        }
        self->fsm->timer = 0x1e;
        break;
    }
}

}
}  // namespace m_021ffff4

// ---- merged from ov009_022009c8.cpp
namespace m_022009c8 {
extern "C" {

extern void *gSndMgr;
extern u8 data_ov009_02215dc0[];
extern void *Ov009Act_02200b48_vtbl;
extern char data_ov009_02216b89[];
extern char data_ov009_02216b90[];
extern void *SndMgr_PlayAt(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern void Vec_RotateY(VecFx32 *out, const void *a, s32 b);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern Ov003Actor *Factory_New4000(void *desc);
extern s32 Model_FindResIdxByName(Model0218fe1c *m, const char *a, const char *b);
extern void NNS_G3dRenderObjSetInitFunc(void *p, void *cb);
extern void Ov009Part_StartCapture(Ov003Actor *self);

struct Ov009SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

void Ov009ActVt_02217128_StateKnockBack(Ov009ActVt_02217128 *self) {
    VecFx32 t;
    VecFx32 d;
    u8 msg;
    Ov003Actor *a;
    switch (self->fsm->st) {
    case 0:
        if (self->kind == 0x5423) {
            self->unk_84 = self->unk_f8;
            msg = 2;
            a = ActorMgr_FindPlayer();
            if (a != NULL) {
                Actor_SendMsg(a, self->id, 0xc, TRUE, 1, &msg);
            }
        }
        Vec_RotateY(&t, data_ov009_02215dc0, 0x5554);
        VEC_Add(&self->unk_84, &t, &t);
        self->unk_b8 = t;
        SndMgr_PlayAt(gSndMgr, 0x35, &self->pos, 0);
        self->fsm->st++;
        break;
    case 1:
        t = self->unk_b8;
        d.x = t.x - self->pos.x;
        d.y = t.y - self->pos.y;
        d.z = t.z - self->pos.z;
        VEC_MultAdd(0x29, &d, &self->pos, &self->pos);
        if (VEC_Distance(&self->pos, &t) <= 0x1000) {
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
}

#pragma force_active on
Ov009Act_02200b48 *Ov009Act_02200b48_Ctor(Ov009Act_02200b48 *self) {
    Ov003Actor_Ctor(self);
    *(void **)self = &Ov009Act_02200b48_vtbl;
    MIi_CpuClear32(0, &self->joint, sizeof(self->joint));
    return self;
}
#pragma force_active reset

void Ov009Act_02200b48_Init(Ov009Act_02200b48 *self) {
    Ov009SpawnDesc desc;
    Ov003Actor *o;
    s32 i;
    GroupNode *p;
    Ov003Actor_Init(self);
    self->unk_f4 = 0xffff;
    desc.kind = 0x408f;
    desc.flags = 0x4000;
    for (i = 0; i < 4; i++) {
        desc.unk_04[i] = 0;
    }
    desc.parent = -1;
    o = Factory_New4000(&desc);
    if (o != NULL) {
        self->unk_f4 = o->id;
        o->pos.x = self->pos.x;
        o->pos.y = self->pos.y;
        o->pos.z = self->pos.z;
        o->vfunc_04();
        o->flags_0 = 1;
        if (o->targetObj != NULL) {
            o->targetObj->target = self->id;
        }
    }
    p = Group_FindNode(gGroup, self->unk_20);
    if (p != NULL) {
        GroupNodeFlags *b = &p->flags;
        b->unk_0 = 0;
        b->unk_5 = 1;
    }
}

void Ov009Act_02200b48_Start(Ov009Act_02200b48 *self) {
    Model0218fe1c *m;
    Ov003Actor_Start(self);
    self->joint.joint = Model_FindResIdxByName(self->model, data_ov009_02216b89, data_ov009_02216b90);
    MTX_Identity43_(&self->joint.mtx);
    m = self->model;
    NNS_G3dRenderObjSetInitFunc(m->unk_24, (void *)Ov009Part_StartCapture);
    m->clearInit = 0;
    self->model->flushVP = 1;
    self->model->renderUser = &self->joint;
    self->unk_f0 = 0;
    self->unk_f6 = 0x1000;
}

void Ov009Act_02200b48_Update(Ov009Act_02200b48 *self) {
    if (self->unk_f0 & 1) {
        self->unk_ee_7 = 1;
    } else {
        self->unk_ee_7 = 0;
    }
    Ov003Actor_Update(self);
}

extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);

struct Ov009EaBits {
    u16 b0 : 3;
    u16 b3 : 8;
    u16 b11 : 1;
    u16 b12 : 1;
    u16 b13 : 1;
    u16 b14 : 2;
};

struct Ov009PosMsg {
    VecFx32 pos;
    u16 rot[3];
    u32 unk_14;
};

static inline Ov003Actor *Ov009_FindActor(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

static inline s32 Ov009_Mode(Ov003Actor *a) {
    return a->fsm != NULL ? a->fsm->current : 0;
}

void Ov009Act_02200b48_RunState(Ov009Act_02200b48 *self) {
    Ov009PosMsg msg;
    u8 mtx[0x30];
    Ov003Actor *a;
    u32 zero = 0;
    s16 t;
    if (!(self->unk_f0 & 1)) {
        u16 *p = self->hp;
        u16 v = self->unk_b0->unk_08;
        if (*p < v) {
            *p = v;
            self->fsm->flags = zero;
            History_SetState(self->fsm, 0x11, zero);
        }
        ((Ov009EaBits *)&self->unk_ea)->b11 = 0;
        a = Ov009_FindActor(self->unk_f4);
        if (a != NULL) {
            if (Ov009_Mode(a) == 9) {
                ActorSub44 *s = self->unk_44;
                if (!(s->unk_22_0 == 1 && s->unk_22_1 == 1)) {
                    s->unk_22_0 = 1;
                    s->unk_22_1 = 1;
                }
                Model0218fe1c_SetAnim(self->model, data_ov009_02215d34, 0x1000, zero);
                Ov009Pair_SetB((Ov009Pair *)&self->hp[4], 0x31);
                History_SetState(self->fsm, 0x13, zero);
            } else {
                if (((Ov009EaBits *)&self->unk_ea)->b13) {
                    MI_Copy48B(&self->joint.mtx, mtx);
                    Actor_SendMsg(a, self->id, 8, TRUE, 0x30, mtx);
                    msg.pos = self->joint.trans;
                } else {
                    msg.pos = self->pos;
                }
                msg.rot[0] = self->rot_x;
                msg.rot[1] = self->rot_y;
                msg.rot[2] = self->rot_z;
                msg.unk_14 = zero;
                Actor_SendMsg(a, self->id, 7, TRUE, 0x18, &msg);
                ((Ov009EaBits *)&self->unk_ea)->b0 = 3;
                goto tail;
            }
        }
        self->unk_f4 = 0xffff;
        self->unk_f0 |= 1;
        self->unk_f6 = 0x1800;
    }
tail:
    Ov003Actor_RunState(self);
    if (!(self->unk_f0 & 1)) {
        self->unk_94_1 = 1;
    }
    if (!(self->hit->unk_50 & 0x20000000)) {
        return;
    }
    if (!(self->hit->unk_50 & 0x400)) {
        return;
    }
    t = self->unk_1a + 1;
    if (t % 20 == 0) {
        t = 0;
        Effect_SpawnId(0x2bd, &self->pos)->SetScaleAll(FX_Mul(self->model->scale.x, 0x199a));
    }
    self->unk_1a = t;
}

}
}  // namespace m_022009c8

// ---- merged from ov009_02200fd4.cpp
namespace m_02200fd4 {
extern "C" {

extern void *gSndMgr;
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *m, s32 a);
extern void Actor_MoveToPos(Ov003Actor *self, VecFx32 *v, s32 a);
extern void *Model0218fe1c_SetAnimFrame(Model0218fe1c *m, s32 a);
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void Actor_SendMsgU8(Ov003Actor *a, u16 id, s32 msg);
extern BOOL AnimCtrl_SetAnim(AnimCtrl *ctrl, void *obj, ResSet *res, void *file, const void *anim, s32 blend, s32 force);
extern void SndMgr_LoadHeapState(void *mgr, s32 a, s32 b);
extern void SceneCmd_Push25(void *p, s32 a);
extern void Ov009ActVt_0221707c_StateAttackPhase0(Ov009ActVt_0221707c *self);
extern void Ov009ActVt_0221707c_StateAttackPhase1(Ov009ActVt_0221707c *self);

void Ov009Act_02200b48_StateMove(Ov009Act_02200b48 *self) {
    VecFx32 v;
    s32 a;
    if (self->fsm->st == 0) {
        Model0218fe1c_SetAnim(self->model, data_ov009_02215d2c, 0x400, 0);
        Model0218fe1c_SetAnimSpeed(self->model, ((s16)self->unk_f6));
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
    }
    self->hit->unk_9a_5 = 1;
    a = self->unk_b0->unk_00;
    self->speed = a;
    if ((self->unk_f0 & 1) && !(self->hit->unk_50 & 0x400)) {
        self->speed = a << 1;
    }
    v = self->unk_b8;
    Actor_MoveToPos(self, &v, self->unk_b0->unk_02);
    Body_Update(self->hit, 1, 0, 0);
    if (!(self->hit->unk_50 & 0x20000000)) {
        History_SetState(self->fsm, 4, 0);
    }
}

void Ov009Act_02200b48_StateShoot(Ov009Act_02200b48 *self) {
    switch (self->fsm->st) {
    case 0:
        self->unk_f2 = Rand_UpTo(0xf);
        break;
    case 1:
        if (self->unk_f2++ == 0x2d) {
            Model0218fe1c_SetAnimFrame(self->model, 0x10000);
        }
        break;
    }
    Ov003Actor_StateShoot(self);
}


extern void Model0218fe1c_SetReverse(Model0218fe1c *m);
extern void ActorMgr_SendMsg(u16 a, u16 b, s32 c, s32 d, s32 e, u8 *f);

static inline void Ov009_Msg(Ov009Act_02200b48 *self, u8 v) {
    u8 f = v;
    ActorMgr_SendMsg(self->unk_f4, self->kind, 6, 1, 1, &f);
}

void Ov009Act_02200b48_StateAttack3(Ov009Act_02200b48 *self) {
    Ov003Actor *a;
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov009_02215d28, 0x400, 0);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        {
            u16 id = self->unk_f4;
            a = gActorMgr == NULL ? NULL : ActorMgr_GetActor(gActorMgr, id);
        }
        if (a != NULL) {
            ActorSub44 *q = self->unk_44;
            q->unk_22_0 = 0;
            q->unk_22_1 = 0;
            q = a->unk_44;
            q->unk_22_0 = 1;
            q->unk_22_1 = 1;
            Ov009_Msg(self, 0);
            self->fsm->timer = 0;
            self->fsm->st = 0x1e;
        } else {
            ActorSub44 *q = self->unk_44;
            q->unk_22_0 = 1;
            q->unk_22_1 = 1;
            self->unk_f4 = 0xffff;
            self->unk_f0 |= 1;
            self->unk_f6 = 0x1800;
        }
    case 0x1e: {
        ActorSub40 *w = self->fsm;
        w->timer++;
        if (w->timer == 0x96) {
            Model0218fe1c_SetAnim(self->model, data_ov009_02215d28, 0x1000, 0);
            Model0218fe1c_SetReverse(self->model);
            {
                ActorSub44 *q = self->unk_44;
                q->unk_22_0 = 1;
                q->unk_22_1 = 1;
            }
            {
                u16 id = self->unk_f4;
                a = gActorMgr == NULL ? NULL : ActorMgr_GetActor(gActorMgr, id);
            }
            if (a != NULL) {
                ActorSub44 *q = a->unk_44;
                q->unk_22_0 = 0;
                q->unk_22_1 = 0;
                Ov009_Msg(self, 1);
            } else {
                self->unk_f4 = 0xffff;
                self->unk_f0 |= 1;
                self->unk_f6 = 0x1800;
            }
        } else if (w->timer >= 0xa5) {
            self->fsm->timer = 0;
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
    }
}

}
}  // namespace m_02200fd4

// ---- merged from ov009_022013ac.cpp
namespace m_022013ac {
extern "C" {

extern void *gSndMgr;
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void Actor_SendMsgU8(Ov003Actor *a, u16 id, s32 msg);
extern BOOL AnimCtrl_SetAnim(AnimCtrl *ctrl, void *obj, ResSet *res, void *file, const void *anim, s32 blend, s32 force);
extern void SndMgr_LoadHeapState(void *mgr, s32 a, s32 b);
extern void SceneCmd_Push25(void *p, s32 a);
extern void Ov009ActVt_0221707c_StateAttackPhase0(Ov009ActVt_0221707c *self);
extern void Ov009ActVt_0221707c_StateAttackPhase1(Ov009ActVt_0221707c *self);

static inline Ov003Actor *Ov009_FindActor(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

void Ov009Act_02200b48_StateDie(Ov009Act_02200b48 *self) {
    Ov003Actor *a = Ov009_FindActor(self->unk_f4);
    if (a != NULL) {
        Actor_SendMsgU8(a, self->unk_f4, 0x15);
        self->unk_f4 = 0xffff;
    }
    Ov003Actor_StateDie(self);
}

static inline void Ov009_PlayAnim(Model0218fe1c *m, const void *anim) {
    if (m->unk_1c != NULL) {
        AnimCtrl_SetAnim(m->unk_1c, m->renderObj, m->res, m->res->anims->list[4], anim, 0x1000, 0);
    }
}

void Ov009ActVt_0221707c_Animate(Ov009ActVt_0221707c *self) {
    Model0218fe1c *m = self->model;
    const char *anim = self->unk_f4 != 0 ? data_ov009_02215d24 : data_ov009_02215d3c;
    Ov009_PlayAnim(m, anim);
    Ov003Actor_Animate(self);
}

}
}  // namespace m_022013ac

// ---- merged from ov009_02201470.cpp
namespace m_02201470 {
extern "C" {

extern void *gSndMgr;
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void Actor_SendMsgU8(Ov003Actor *a, u16 id, s32 msg);
extern BOOL AnimCtrl_SetAnim(AnimCtrl *ctrl, void *obj, ResSet *res, void *file, const void *anim, s32 blend, s32 force);
extern void SndMgr_LoadHeapState(void *mgr, s32 a, s32 b);
extern void SceneCmd_Push25(void *p, s32 a);
extern void Ov009ActVt_0221707c_StateAttackPhase0(Ov009ActVt_0221707c *self);
extern void Ov009ActVt_0221707c_StateAttackPhase1(Ov009ActVt_0221707c *self);

void Ov009ActVt_0221707c_Init(Ov009ActVt_0221707c *self) {
    Ov003Actor_Init(self);
    SndMgr_LoadHeapState(gSndMgr, 1, 1);
    switch (self->kind) {
    case 0x5047:
        SceneCmd_Push25(gSceneCmd, 0xd);
        self->unk_1a = 0;
        break;
    case 0x503f:
    case 0x5048:
        SceneCmd_Push25(gSceneCmd, 0xe);
        self->unk_1a = 1;
        break;
    case 0x5035:
        SceneCmd_Push25(gSceneCmd, 0xf);
        self->unk_1a = 2;
        break;
    case 0x5054:
        SceneCmd_Push25(gSceneCmd, 0x10);
        self->unk_1a = 3;
        break;
    }
    self->unk_ea_10 = 1;
    self->unk_108 = -1;
}

void Ov009ActVt_0221707c_Start(Ov009ActVt_0221707c *self) {
    u32 *p;
    Ov003Actor_Start(self);
    p = (u32 *)Heap_Alloc(4);
    if (p != NULL) {
        *p = 0;
    }
    self->unk_104 = p;
    self->unk_f0 = 0;
    switch (self->kind) {
    case 0x503f:
    case 0x5048:
        self->unk_f5 = 0;
        self->unk_f2 = 0x78;
        break;
    case 0x5035:
    case 0x5047:
    case 0x5054:
        self->unk_f5 = 1;
        switch (self->kind) {
        case 0x5047:
            self->unk_f2 = 0x78;
            break;
        case 0x5035:
            self->unk_f2 = 0x96;
            break;
        case 0x5054:
            self->unk_f2 = 0x50;
            break;
        }
        self->unk_c8 = 0x16000;
        self->unk_cc = 0xc000;
        break;
    }
}

extern VecFx32 data_ov009_02215dd8;
extern void SndMgr_StopSeqArc(void *mgr, s32 id);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern BOOL Ov003FxList_Has(void *mgr, s32 id);
extern void Ov003FxList_Add(void *mgr, s32 id, void *obj);
extern void Ov003FxList_Kill(void *mgr, s32 id);
extern void Ov003FxList_Place(void *mgr, s32 id, const VecFx32 *pos, s32 a, s32 b, const void *c, s32 d);
extern void Ov003FxList_Prune(void *mgr);
void Ov009ActVt_0221707c_Update(Ov009ActVt_0221707c *self) {
    EffectObj *obj;
    VecFx32 v;
    Ov003Actor_Update(self);
    if (self->unk_f4 != 0) {
        self->unk_94_1 = 1;
        if (self->unk_f5 == 1) {
            if (!Ov003FxList_Has(self->unk_104, 0xfd)) {
                if (self->fsm->current != 0x15) {
                    obj = Effect_SpawnId(0x322, &self->pos);
                    obj->AddPos(&data_ov009_02215dd8);
                    obj->SetScaleAll(0xccd);
                    obj->loopCount = -1;
                    EffectObj_AddSndCue(obj, 0x78, 0);
                    Ov003FxList_Add(self->unk_104, 0xfd, obj);
                }
            } else {
                Ov003FxList_Place(self->unk_104, 0xfd, &self->pos, 0, 0, &data_ov009_02215dd8, 0);
            }
            if (self->fsm->current != 0xf && Ov003FxList_Has(self->unk_104, 0xfb)) {
                Ov003FxList_Kill(self->unk_104, 0xfb);
                SndMgr_StopSeqArc(gSndMgr, self->unk_108);
                self->unk_108 = -1;
            }
            if (Ov003FxList_Has(self->unk_104, 0xfa)) {
                v = ActorMgr_FindPlayer()->pos;
                Ov003FxList_Place(self->unk_104, 0xfa, &v, 0, 0, 0, 0);
            }
        }
    } else if (self->unk_f5 == 1 && Ov003FxList_Has(self->unk_104, 0xfd)) {
        Ov003FxList_Kill(self->unk_104, 0xfd);
    }
    Ov003FxList_Prune(self->unk_104);
}

}
}  // namespace m_02201470

// ---- merged from ov009_02201848.cpp
namespace m_02201848 {
extern "C" {

extern void Ov009ActVt_0221707c_StateAttackPhase0(Ov009ActVt_0221707c *self);
extern void Ov009ActVt_0221707c_StateAttackPhase1(Ov009ActVt_0221707c *self);

void Ov009ActVt_0221707c_StateIdle(Ov009ActVt_0221707c *self) {
    if (self->fsm->st == 0) {
        self->unk_f0 = 0;
        self->unk_f4 = 1;
    }
    Ov003Actor_StateIdle(self);
}

void Ov009ActVt_0221707c_StateAttack(Ov009ActVt_0221707c *self) {
    switch (self->unk_f5) {
    case 0:
        Ov009ActVt_0221707c_StateAttackPhase0(self);
        break;
    case 1:
        Ov009ActVt_0221707c_StateAttackPhase1(self);
        break;
    }
}

}
}  // namespace m_02201848

// ---- merged from ov009_0220189c.cpp
namespace m_0220189c {
struct Ov009Rot {
    u16 x, y, z;
};

extern "C" {

extern void *gSndMgr;
extern s32 data_ov009_02215e14[];
extern VecFx32 data_ov009_02215de4;
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *other, s32 a);
extern void *SndMgr_PlayAt(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern void Vec_RotateY(VecFx32 *dst, const VecFx32 *src, u16 angle);
extern void Ov003FxList_Add(void *mgr, s32 id, void *obj);
extern void Ov003FxList_Kill(void *mgr, s32 id);
extern void Ov003FxList_Place(void *mgr, s32 id, const VecFx32 *pos, const void *a, s32 b, const void *c, const void *d);
extern s32 SndMgr_StartSeqArc(void *mgr, s32 id);
extern void SndMgr_StopSeqArc(void *mgr, s32 id);
extern void Actor_TurnToPos(Ov003Actor *self, VecFx32 *v, s32 a);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern BOOL Hit_ApplyInArea(void *a, void *b, u16 c, u8 d, s32 e, const void *f, const void *g, s32 h, s32 i, s32 j, s32 k);
extern void Model0218fe1c_PauseAnim(void *p);
extern void Model0218fe1c_ResumeAnim(void *p);

static inline void Ov009_VSet(VecFx32 *v, s32 x, s32 y, s32 z) { v->x = x; v->y = y; v->z = z; }
void Ov009ActVt_0221707c_StateAttackPhase0(Ov009ActVt_0221707c *self) {
    VecFx32 v;
    Ov009Rot r;
    EffectObj *o;
    u16 tm;
    Ov003Actor *t;
    t = Actor_GetTarget(self);
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov009_02215d0c, 0x400, 0);
        self->unk_f4 = 1;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->timer = 0;
        self->fsm->st++;
    case 1:
        Actor_TurnToActor(self, t, self->unk_b0->unk_02);
        if (self->model->anim_state == 1) {
            SndMgr_PlayAt(gSndMgr, data_ov009_02215e14[self->unk_1a], &self->pos, 0);
            self->fsm->st++;
        }
        break;
    case 2:
        if (self->model->anim_state == 2) {
            o = Effect_SpawnId(0x25a, &self->pos);
            o->SetRot(&self->rot);
            Vec_RotateY(&v, &data_ov009_02215de4, self->rot_y);
            o->AddPos(&v);
            o->SetScaleAll(0x1800);
            Ov003FxList_Add(self->unk_104, 0xff, o);
            self->unk_108 = SndMgr_StartSeqArc(gSndMgr, 0x4c);
            self->fsm->st++;
        }
        break;
    case 3: {
        ActorSub40 *st = self->fsm;
        st->timer++;
        tm = st->timer;
        if (tm % 50 == 0 || tm == 1) {
            v.x = 0x3000;
            v.y = 0;
            v.z = 0x3000;
            self->unk_f0 ^= 4;
            if (self->unk_f0 & 4) {
                v.x = -v.x;
            }
            Vec_RotateY(&v, &v, self->rot_y);
            VEC_Add(&self->pos, &v, &self->unk_84);
        }
        Actor_TurnToPos(self, &self->unk_84, 0x52);
        Ov003FxList_Place(self->unk_104, 0xff, &self->pos, &self->rot_x, 0, &data_ov009_02215de4, &self->rot_x);
        if (*ActorMgr_FindPlayer()->hp != 0) {
            r.x = self->rot_x;
            r.y = self->rot_y;
            r.z = self->rot_z;
            r.x += 0x4000;
            Hit_ApplyInArea(self, self, self->unk_f2, self->targetObj->unk_0a, 2, &data_ov009_02215de4, &r, 0x99a, 0x6000, 0x258, 0x2800);
        }
        if (t->hp != NULL && *t->hp == 0) {
            tm = 200;
        }
        if (!Ov009_GameIdle()) {
            tm = 200;
        }
        if (tm >= 200) {
            u8 i;
            Ov003FxList_Kill(self->unk_104, 0xff);
            SndMgr_StopSeqArc(gSndMgr, self->unk_108);
            self->unk_108 = -1;
            Model0218fe1c_PauseAnim(self->model);
            for (i = 0; i < 2; i++) {
                o = Effect_SpawnId(0x25e, &self->pos);
                o->SetRotXYZ(0x8aaa, self->rot_y, 0);
                v.x = 0x1000;
                v.y = 0x4000;
                v.z = 0xb33;
                if (i == 1) {
                    v.x = -v.x;
                }
                Vec_RotateY(&v, &v, self->rot_y);
                o->AddPos(&v);
                Ov003FxList_Add(self->unk_104, 0xfe, o);
            }
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    }
    case 4: {
        ActorSub40 *st = self->fsm;
        st->timer++;
        if (st->timer == 100) {
            Ov003FxList_Kill(self->unk_104, 0xfe);
            Model0218fe1c_ResumeAnim(self->model);
            Model0218fe1c_SetAnim(self->model, data_ov009_02215d30, 0x400, 0);
            Model0218fe1c_SetLoop(self->model);
            o = Effect_SpawnId(0x12f, &self->pos);
            o->AddPosXYZ(0, 0x2000, 0);
            o->SetScaleAll(0x99a);
            self->unk_f4 = 0;
            SndMgr_PlayAt(gSndMgr, 0x73, &self->pos, 0);
        } else if (st->timer == 300) {
            Model0218fe1c *m = self->model;
            self->unk_f8 = m->scale.x;
            self->unk_fc = m->scale.y;
            self->unk_100 = m->scale.z;
            self->unk_f4 = 1;
            o = Effect_SpawnId(0x12f, &self->pos);
            o->AddPosXYZ(0, 0x2000, 0);
            o->SetScaleAll(0x99a);
            {
                s32 a = FX_Mul(self->unk_f8, 0x14cd);
                s32 b = self->unk_fc;
                Model0218fe1c *mm = self->model;
                mm->scale.x = a;
                mm->scale.y = b;
                mm->scale.z = a;
            }
            SndMgr_PlayAt(gSndMgr, 0x72, &self->pos, 0);
            self->fsm->st = 0x1e;
        }
        break;
    }
    case 0x1e: {
        s32 x = self->model->scale.x;
        if (x > self->unk_f8) {
            x -= 0x19a;
            if (x <= self->unk_f8) {
                x = self->unk_f8;
                History_SetState(self->fsm, 1, 0);
            }
            Ov009_VSet(&self->model->scale, x, self->unk_fc, x);
        }
        break;
    }
    }
    if ((s32)self->fsm->st >= 1) {
        self->unk_ea_0 = 3;
    }
}

extern VecFx32 data_ov009_02215dd8;
extern BOOL Ov003FxList_Has(void *mgr, s32 id);
extern s32 Ov003FxList_Get(void *mgr, s32 id);
extern void NNSi_G3dModifyPolygonAttrMask(void *p, s32 a, s32 b);
extern s32 Actor_FindInRadius(Actor *self, u16 mask, VecFx32 *pos, s32 r, s32 a, Ov003Actor **list);
extern Ov003Actor *Obj021984c8_GetActor(Ov003Actor *p);
extern Ov003Actor *Target_Get(void *p);
extern void Actor_SendMsgU8(Ov003Actor *a, u16 id, s32 msg);

void Ov009ActVt_0221707c_StateAttackPhase1(Ov009ActVt_0221707c *self) {
    Ov003Actor *list[32];
    VecFx32 v;
    VecFx32 w;
    EffectObj *o;
    Model0218fe1c *m;
    s32 i;
    s32 n;
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov009_02215d0c, 0x400, 0);
        self->unk_f4 = 1;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->timer = 0;
        self->fsm->st++;
    case 1:
        if (self->model->anim_state != 1) {
            return;
        }
        o = Effect_SpawnId(0x5e2, &self->pos);
        o->AddPos(&data_ov009_02215dd8);
        Ov003FxList_Add(self->unk_104, 0xfc, o);
        self->fsm->timer = 0;
        self->fsm->st++;
        return;
    case 2:
        if (Ov003FxList_Has(self->unk_104, 0xfc)) {
            return;
        }
        SndMgr_PlayAt(gSndMgr, data_ov009_02215e14[self->unk_1a], &self->pos, 0);
        o = Effect_SpawnId(0x321, &self->pos);
        o->AddPos(&data_ov009_02215d78);
        o->SetScaleAll(0x19a);
        o->alpha = FX_Div(0x10000, 0x1f000);
        Ov003FxList_Add(self->unk_104, 0xfb, o);
        self->fsm->st++;
        return;
    case 3: {
        s32 a;
        o = Effect_Find_020657b0(gEffectMgr, Ov003FxList_Get(self->unk_104, 0xfb));
        if (o == NULL) {
            return;
        }
        a = o->scale.x;
        o->SetScaleAll(a + 0x666);
        if (a + 0x666 < 0x3333) {
            return;
        }
        self->unk_108 = SndMgr_StartSeqArc(gSndMgr, 0x76);
        m = self->model;
        m->color = 0x7c00;
        m->color2 = 0x7c00;
        m->blend = 0xc9;
        m->blendMax = 0xc8;
        m = self->model;
        m->cull = 2;
        NNSi_G3dModifyPolygonAttrMask(m->mdl, 0, 0xc0);
        self->fsm->st++;
        return;
    }
    case 4:
        if (*ActorMgr_FindPlayer()->hp != 0 && Ov009_GameIdle()) {
            if (Hit_ApplyInArea(self, self, self->unk_f2, self->targetObj->unk_0a, 2, &data_ov009_02215d78, NULL, 0x4ccd, 0, 0x322, 0xccd)) {
                v = ActorMgr_FindPlayer()->pos;
                SndMgr_PlayAt(gSndMgr, 0x77, &v, 0);
            }
        } else {
            self->fsm->timer = 200;
            m = self->model;
            m->color = 0x7c00;
            m->color2 = 0x7c00;
            m->blend = 2;
            m->blendMax = 1;
        }
        {
        ActorSub40 *st = self->fsm;
        st->timer++;
        if (st->timer > 200) {
            Ov003FxList_Kill(self->unk_104, 0xfb);
            SndMgr_StopSeqArc(gSndMgr, self->unk_108);
            self->unk_108 = -1;
            o = Effect_SpawnId(0x69, &self->pos);
            o->AddPos(&data_ov009_02215d78);
            o->SetScaleAll(0x2000);
            Model0218fe1c_SetAnim(self->model, data_ov009_02215d30, 0x400, 0);
            Model0218fe1c_SetLoop(self->model);
            m = self->model;
            m->cull = 3;
            NNSi_G3dModifyPolygonAttrMask(m->mdl, 1, 0xc0);
            self->unk_f4 = 0;
            SndMgr_PlayAt(gSndMgr, 0x73, &self->pos, 0);
            self->fsm->timer = 0;
            self->fsm->st = 0x1e;
        }
        }
        VEC_Add(&self->pos, &data_ov009_02215d78, &w);
        n = Actor_FindInRadius(self, 0x10, &w, 0x4ccd, 0, list);
        if (n != 0) {
        for (i = 0; i < n; i++) {
            Ov003Actor *q;
            if (list[i] != NULL && (q = Obj021984c8_GetActor(list[i])) != NULL) {
                ActorSub4c *s = q->targetObj;
                if (s != NULL && (u8)(s->unk_02 + 0xff) <= 1) {
                    Ov003Actor *b = Target_Get(s);
                    if (b != NULL && b->kind == 0x1000 && ((Robo021ca458 *)ActorMgr_FindPlayer())->unk_b24_5 == 0) {
                        Actor_SendMsgU8(q, q->id, 0x15);
                    }
                }
            }
        }
        }
        return;
    case 0x1e: {
        ActorSub40 *st = self->fsm;
        st->timer++;
        if (st->timer > 300) {
            self->fsm->timer = 0;
            History_SetState(self->fsm, 1, 0);
        }
        return;
    }
    }
}

}
}  // namespace m_0220189c

// ---- merged from ov009_0220244c.cpp
namespace m_0220244c {
extern "C" {

extern void *gSndMgr;
extern void Ov003FxList_KillAll(void *p);
extern void SndMgr_StopSeqArc(void *mgr, s32 id);
extern void NNSi_G3dModifyPolygonAttrMask(void *p, s32 a, s32 b);
extern void Model0218fe1c_ClearLoop(Model0218fe1c *m);
extern void *Ov009Act_02202788_vtbl;
extern char data_ov009_02216b98[];
extern BOOL Actor_IsReady(Ov003Actor *self);
extern void ActorSub48_UpdatePos(void *a, s32 b, s32 c);
extern void HitMesh_Link(void *p);
extern void *ActorMgr_FindPlayer(void);

static inline void Ov009_StopEffect(Ov009ActVt_0221707c *self) {
    Model0218fe1c *m;
    self->unk_f4 = 0;
    Ov003FxList_KillAll(self->unk_104);
    SndMgr_StopSeqArc(gSndMgr, self->unk_108);
    self->unk_108 = -1;
    m = self->model;
    m->cull = 3;
    NNSi_G3dModifyPolygonAttrMask(m->mdl, 1, 0xc0);
}

void Ov009ActVt_0221707c_StateMove(Ov009ActVt_0221707c *self) {
    if (self->fsm->st == 0) {
        self->unk_f4 = 1;
    }
    Ov003Actor_StateMove(self);
}

void Ov009ActVt_0221707c_StateDown(Ov009ActVt_0221707c *self) {
    if (self->fsm->st == 0) {
        Ov009_StopEffect(self);
    }
    Ov003Actor_StateDown(self);
    if (self->fsm->current == 4) {
        self->unk_f0 |= 0x800;
    }
}

void Ov009ActVt_0221707c_StateFly(Ov009ActVt_0221707c *self) {
    Ov003Actor_StateFly(self);
    if (self->fsm->st < 1) {
        return;
    }
    if (!(self->unk_f0 & 0x800)) {
        return;
    }
    Model0218fe1c_SetAnim(self->model, data_ov009_02215d20, 0x1000, 0);
    self->unk_f4 = 0;
    Model0218fe1c_ClearLoop(self->model);
    if (self->fsm->st == 2) {
        self->unk_f0 = 0;
    }
}

void Ov009ActVt_0221707c_StateDie(Ov009ActVt_0221707c *self) {
    if (self->fsm->st == 0) {
        Ov009_StopEffect(self);
        self->radius >>= 2;
    }
    Ov003Actor_StateDie(self);
}

void Ov009ActVt_0221707c_StateHurt(Ov009ActVt_0221707c *self) {
    if (self->fsm->st == 0) {
        Ov009_StopEffect(self);
    }
    Ov003Actor_StateHurt(self);
}

void Ov009ActVt_0221707c_StateKnockBack(Ov009ActVt_0221707c *self) {
    if (self->fsm->st == 0) {
        Ov009_StopEffect(self);
    }
    Ov003Actor_StateKnockBack(self);
}

void Ov009Names_Fill_022026c8(Ov009Names *self, u16 kind) {
    char *a = Tbl_GetResFile(kind);
    char *b = func_020701d4(kind);
    TblActorParam *c = Tbl_GetActorParam(kind);
    const char *s;
    char *t;
    STD_CopyString(self->mdlDir, a);
    STD_CopyString(self->mdlName, b);
    self->ownMdl = 1;
    s = data_ov009_02215d10;
    STD_CopyString(self->anmDir, s);
    STD_CopyString(self->anmName, data_ov009_02215d14);
    self->ownAnm = 1;
    t = c->evName;
    if (t != NULL) {
        STD_CopyString(self->evDir, s);
        STD_CopyString(self->evName, t);
        self->ownEv = 1;
    }
    self->unk_00 = 0;
}

#pragma force_active on
Ov009Act_02202788 *Ov009Act_02202788_Ctor(Ov009Act_02202788 *self) {
    Ov003Actor_Ctor(self);
    *(void **)self = &Ov009Act_02202788_vtbl;
    MIi_CpuClear32(0, &self->joint, sizeof(self->joint));
    return self;
}
#pragma force_active reset

Ov009Act_02202788 *Ov009Act_02202788_Dtor(Ov009Act_02202788 *self) {
    *(void **)self = &Ov009Act_02202788_vtbl;
    if (self->kind == 0x5055 && ResMgr_IsLoaded(data_ov009_02216b98, 7)) {
        ResMgr_ReleaseByName(gResMgr, data_ov009_02216b98, 7, 0);
    }
    Ov003Actor_DtorBase(self);
    return self;
}

Ov009Act_02202788 *Ov009Act_02202788_DtorDelete(Ov009Act_02202788 *self) {
    *(void **)self = &Ov009Act_02202788_vtbl;
    if (self->kind == 0x5055 && ResMgr_IsLoaded(data_ov009_02216b98, 7)) {
        ResMgr_ReleaseByName(gResMgr, data_ov009_02216b98, 7, 0);
    }
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}

BOOL Ov009Act_02202788_Draw(Ov009Act_02202788 *self) {
    BOOL r = Ov003Actor_Draw(self);
    self->unk_1e = r ? 1 : 0;
    return r;
}

}
}  // namespace m_0220244c

// ---- merged from ov009_022028c8.cpp
namespace m_022028c8 {
extern "C" {

extern void *gSndMgr;
extern char data_ov009_02216b98[];
extern Ov003Actor *Factory_New4000(void *desc);
extern void SndMgr_LoadHeapState(void *mgr, s32 a, s32 b);
extern void SceneCmd_Push25(void *p, s32 a);
void Ov009Names_Fill_022026c8(Ov009Names *self, u16 kind);

struct Ov009SpawnDesc {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
    Ov009SpawnDesc() {
        s32 i;
        kind = 0xffff;
        flags = 0xf000;
        for (i = 0; i < 4; i++) {
            unk_04[i] = 0;
        }
    }
};

void Ov009Act_02202788_Init(Ov009Act_02202788 *self) {
    Ov009Names *n;
    Ov003Actor *o;
    GroupNode *p;
    u16 kind;
    char *a;
    char *b;
    u32 k;
    if (self->kind == 0x5055) {
        self->unk_d8 = (void *)Ov009Names_Fill_022026c8;
    }
    Ov003Actor_Init(self);
    kind = self->kind;
    a = Tbl_GetResFile(kind);
    b = func_020701d4(kind);
    n = ((Ov009Names *)self->unk_34);
    STD_CopyString(n->unk_88, a);
    STD_CopyString(n->unk_a8, b);
    n->unk_03_3 = 1;
    ((Ov009Names *)self->unk_34)->unk_00 = 0;
    k = 0x4083;
    if (self->kind == 0x5055) {
        k += 0x13;
    }
    {
        Ov009SpawnDesc desc;
        desc.parent = -1;
        desc.kind = k;
        desc.flags = k & 0xf000;
        o = Factory_New4000(&desc);
    }
    if (o != NULL) {
        self->unk_f0 = o->id;
        o->pos.x = self->pos.x;
        o->pos.y = self->pos.y;
        o->pos.z = self->pos.z;
        o->vfunc_04();
        o->flags_0 = 1;
        if (o->targetObj != NULL) {
            o->targetObj->target = self->id;
        }
    }
    p = Group_FindNode(gGroup, self->unk_20);
    if (p != NULL) {
        GroupNodeFlags *bb = &p->flags;
        bb->unk_0 = 0;
        bb->unk_5 = 1;
    }
    if (self->kind == 0x5055) {
        ResMgr_Load(data_ov009_02216b98, 7, 0);
    }
    SndMgr_LoadHeapState(gSndMgr, 1, 1);
    switch (self->kind) {
    case 0x5049:
        SceneCmd_Push25(gSceneCmd, 0xe);
        self->unk_1a = 0;
        break;
    case 0x5055:
        SceneCmd_Push25(gSceneCmd, 0xf);
        self->unk_1a = 1;
        break;
    }
}

}
}  // namespace m_022028c8

// ---- merged from ov009_02202acc.cpp
namespace m_02202acc {
extern "C" {

extern char data_ov009_02216b98[];
extern BOOL Actor_IsReady(Ov003Actor *self);
extern void ActorSub48_UpdatePos(void *a, s32 b, s32 c);
extern void HitMesh_Link(void *p);

BOOL Ov009Act_02202788_IsReady(Ov009Act_02202788 *self) {
    BOOL r = Actor_IsReady(self);
    if (self->kind == 0x5055) {
        r = (r & ResMgr_IsLoaded(data_ov009_02216b98, 7)) ? TRUE : FALSE;
    }
    return r;
}

void Ov009Act_02202788_UpdateHit(Ov009Act_02202788 *self) {
    if (self->hit != NULL) {
        ActorSub48_UpdatePos(self->hit, 0, 0);
    }
    if (self->hitMesh != NULL) {
        HitMesh_Link(self->hitMesh);
    }
}

extern char data_ov009_02216ba7[];
extern void HitMesh_Init(void *p);
extern void HitMesh_SetRes(void *p, s32 v);
extern void HitMesh_SetScale(void *p, s32 v);
extern s32 Model_FindResIdxByName(Model0218fe1c *m, const char *a, const char *b);
extern void NNS_G3dRenderObjSetInitFunc(void *p, void *cb);
extern void Ov009Part_StartCapture(Ov003Actor *self);
extern u8 *Tbl_FindEntry_0206fef8(s32 id);
extern void HitMesh_SetMtx(void *mesh, const void *mtx);
struct Ov009Mtx43 {
    s32 m[9];
    VecFx32 t;
};

void Ov009Act_02202788_Start(Ov009Act_02202788 *self) {
    Model0218fe1c *m;
    u8 *c;
    u32 *o;
    u32 v;
    Ov003Actor_Start(self);
    {
        ActorSub48 *s48 = self->hit;
        s48->offset.x = 0;
        s48->offset.y = 0x1800;
        s48->offset.z = 0;
    }
    self->joint.joint = Model_FindResIdxByName(self->model, func_020701d4(self->kind), data_ov009_02216ba7);
    MTX_Identity43_(&self->joint.mtx);
    m = self->model;
    NNS_G3dRenderObjSetInitFunc(m->unk_24, (void *)Ov009Part_StartCapture);
    m->clearInit = 0;
    self->model->flushVP = 1;
    self->model->renderUser = &self->joint;
    {
        ActorSub44 *s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
    }
    self->unk_ea_6 = 1;
    c = Tbl_FindEntry_0206fef8(self->kind);
    o = ((Ov009Names *)self->unk_34)->unk_84;
    v = o != NULL ? *o : 0;
    if (v != 0) {
        void *p = Heap_Alloc(0x98);
        if (p != NULL) {
            HitMesh_Init(p);
        }
        self->hitMesh = p;
        o = ((Ov009Names *)self->unk_34)->unk_84;
        HitMesh_SetRes(self->hitMesh, o != NULL ? *o : 0);
        HitMesh_SetScale(self->hitMesh, FLD(s16, c, 0x10));
        {
            void *obj;
            Ov009Mtx43 t;
            Ov009Mtx43 mt;
            u16 rx;
            u16 ry;
            u16 rz;
            BOOL set = FALSE;
            rz = self->rot_z;
            obj = self->hitMesh;
            ry = self->rot_y;
            rx = self->rot_x;
            MTX_Identity43_((MtxFx43 *)&mt);
            if (rz != 0) {
                MTX_RotZ43_((MtxFx43 *)&mt, OV009_SIN(rz), OV009_COS(rz));
                set = TRUE;
            }
            if (ry != 0) {
                if (set) {
                    MTX_RotY43_((MtxFx43 *)&t, OV009_SIN(ry), OV009_COS(ry));
                    MTX_Concat43((MtxFx43 *)&t, (MtxFx43 *)&mt, (MtxFx43 *)&mt);
                } else {
                    MTX_RotY43_((MtxFx43 *)&mt, OV009_SIN(ry), OV009_COS(ry));
                    set = TRUE;
                }
            }
            if (rx != 0) {
                if (set) {
                    MTX_RotX43_((MtxFx43 *)&t, OV009_SIN(rx), OV009_COS(rx));
                    MTX_Concat43((MtxFx43 *)&t, (MtxFx43 *)&mt, (MtxFx43 *)&mt);
                } else {
                    MTX_RotX43_((MtxFx43 *)&mt, OV009_SIN(rx), OV009_COS(rx));
                    set = TRUE;
                }
            }
            mt.t.x = self->pos.x;
            mt.t.y = self->pos.y;
            mt.t.z = self->pos.z;
            HitMesh_SetMtx(obj, &mt);
        }
    }
    self->unk_cc = 0xc000;
}

}
}  // namespace m_02202acc

// ---- merged from ov009_02202db4.cpp
namespace m_02202db4 {
extern "C" {

extern void *ActorMgr_FindPlayer(void);

void Ov009Act_02202788_Update(Ov009Act_02202788 *self) {
    u16 *p;
    u16 v;
    Model0218fe1c *m;
    Ov003Actor_Update(self);
    if (!self->unk_93_4) {
        return;
    }
    ActorMgr_FindPlayer();
    p = self->hp;
    v = self->unk_b0->unk_08;
    if (*p >= v) {
        return;
    }
    *p = v;
    m = self->model;
    m->color = 0x14bf;
    m->color2 = 0x14bf;
    m->blend = 1;
    m->blendMax = 0;
}

extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void HitMesh_SetMtx(void *mesh, const void *mtx);
static inline Ov003Actor *Ov009_FindActor(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

static inline s32 Ov009_Mode(Ov003Actor *a) {
    return a->fsm != NULL ? a->fsm->current : 0;
}

struct Ov009PosMsg {
    VecFx32 pos;
    u16 rot[3];
    u32 unk_14;
};

void Ov009Act_02202788_RunState(Ov009Act_02202788 *self) {
    Ov009PosMsg msg;
    u8 mtx[0x30];
    Ov003Actor *a;
    Ov003Actor_RunState(self);
    a = Ov009_FindActor(self->unk_f0);
    if (a == NULL || Ov009_Mode(a) == 9) {
        History_SetState(self->fsm, 0x15, 0);
    }
    if (a == NULL || self->fsm->current == 0x15) {
        return;
    }
    if (self->hitMesh != NULL) {
        HitMesh_SetMtx(self->hitMesh, &self->joint.mtx);
    }
    if (Ov009_Mode(a) != 1) {
        return;
    }
    if (self->unk_1e == 0) {
        return;
    }
    msg.pos = self->joint.trans;
    msg.rot[0] = self->rot_x;
    msg.rot[1] = self->rot_y;
    msg.rot[2] = self->rot_z;
    msg.unk_14 = 0;
    Actor_SendMsg(a, self->id, 7, TRUE, 0x18, &msg);
    MI_Copy48B(&self->joint.mtx, mtx);
    Actor_SendMsg(a, self->id, 8, TRUE, 0x30, mtx);
}

}
}  // namespace m_02202db4

// ---- merged from ov009_02202f68.cpp
namespace m_02202f68 {
extern "C" {

extern void *gSndMgr;
extern const VecFx32 data_ov009_02215db4;
extern u8 data_ov009_02215e60[];
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void Vec_RotateY(VecFx32 *out, const void *a, s32 b);
extern void *SndMgr_PlayAt(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *other, s32 a);
extern void Field_ShakeCamera(s32 a, s32 b);
extern void Actor_SendMsgU8(Ov003Actor *a, u16 id, s32 msg);
extern void Model0218fe1c_PauseAnim(void *p);
extern void Model0218fe1c_ResumeAnim(void *p);
extern void Ov009Act_02202788_SpawnShot(Ov009Act_02202788 *self);
extern void Actor_TurnToPos(Ov003Actor *self, const VecFx32 *v, s32 a);

static inline Ov003Actor *Ov009_FindActor(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

static inline s32 Ov009_FxMulL(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void Ov009Act_02202788_StateShoot(Ov009Act_02202788 *self) {
    VecFx32 tmp;
    VecFx32 tp;
    VecFx32 off;
    Ov003Actor *t;
    s32 lim;
    u16 id;
    EffectObj *e;
    TblActorParam *c;
    ActorSub40 *st;
    Ov003Actor *a;
    t = Ov009_FindActor(self->target);
    tp.x = t->pos.x;
    tp.y = t->pos.y;
    tp.z = t->pos.z;
    Vec_RotateY(&off, &data_ov009_02215d84, self->rot_y);
    st = self->fsm;
    lim = self->pos.y + self->height;
    switch (st->st) {
    case 0:
        if (self->kind == 0x5055 && tp.y <= lim) {
            e = Effect_SpawnId(0x640, &self->pos);
            e->SetScaleAll(0xccd);
            e->AddPos(&off);
            self->unk_f4 = e->id;
        }
        SndMgr_PlayAt(gSndMgr, 0x46, &self->pos, 0);
        self->fsm->timer = 0;
        self->fsm->st++;
    case 1:
        Actor_TurnToActor(self, t, self->unk_b0->unk_02);
        e = Effect_Find_020657b0(gEffectMgr, self->unk_f4);
        if (e != NULL) {
            VEC_Add(&off, &self->pos, &tmp);
            e->SetPos(&tmp);
        }
        st = self->fsm;
        st->timer++;
        if (st->timer > 0x32) {
            SndMgr_PlayAt(gSndMgr, 0x73, &self->pos, 0);
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        if (tp.y > lim) {
            self->fsm->timer = 0;
            History_SetState(self->fsm, 1, 0);
        }
        break;
    case 2:
        st->timer++;
        if (st->timer > 10) {
            SndMgr_PlayAt(gSndMgr, data_ov009_02215d54[self->unk_1a], &self->pos, 0);
            Field_ShakeCamera(10, 0xf);
            self->fsm->timer = 0;
            if (self->kind == 0x5055) {
                self->fsm->st = 10;
            } else {
                self->fsm->st++;
            }
        }
        break;
    case 3:
        c = Tbl_GetActorParam(self->kind);
        if (c != NULL) {
            u16 *p = &c->spawn.id;
            if (p != NULL) {
                u16 k = *p;
                if (k != 0xffff) {
                    id = k;
                }
                VEC_Add(&off, &self->pos, &tmp);
                a = static_cast<Ov003Actor *>(Ov003Actor_SpawnChild(self, id, &tmp, &self->rot_x, t));
                if (a != NULL) {
                    a->unk_60 = data_ov009_02215e60;
                    Actor_SendMsgU8(a, self->id, 0xb);
                }
            }
        }
        self->fsm->st = 0x1e;
        break;
    case 10: {
        Model0218fe1c_PauseAnim(self->model);
        Ov009Act_02202788_SpawnShot(self);
        tp.x -= self->pos.x;
        tp.y -= self->pos.y;
        tp.z -= self->pos.z;
        Vec_RotateY(&tp, &tp, (u16)(0xffff - self->rot_y));
        VecFx32 v = data_ov009_02215db4;
        if (tp.x <= 0) {
            v.x = Ov009_FxMulL(v.x, -0x1000);
        }
        Vec_RotateY(&v, &v, self->rot_y);
        VEC_Add(&v, &self->pos, &v);
        self->unk_84.x = v.x;
        self->unk_84.y = v.y;
        self->unk_84.z = v.z;
        self->fsm->st++;
    }
    case 11:
        st = self->fsm;
        st->timer++;
        if (st->timer > 0xf) {
            Actor_TurnToPos(self, &self->unk_84, 0x3d);
            a = Ov009_FindActor(self->target_id);
            if (a != NULL) {
                a->rot_y = self->rot_y;
            } else {
                Model0218fe1c_ResumeAnim(self->model);
                self->fsm->st = 0x1e;
            }
        }
        break;
    case 0x1e:
        st->timer++;
        if (st->timer >= 200) {
            self->fsm->timer = 0;
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
    self->unk_ea_0 = 3;
}

}
}  // namespace m_02202f68

// ---- merged from ov009_02203428.cpp
namespace m_02203428 {
extern "C" {

extern void *gSndMgr;
extern Ov003Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void HitMesh_Unlink_0203f920(void *p);
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern void Actor_SendMsgU8(Ov003Actor *a, u16 id, s32 msg);
extern void ActorMgr_BroadcastKind(void *mgr, s32 a, s32 b);
extern void Field_ShakeCamera(s32 a, s32 b);
extern void *Spawn_ScatterEffect(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, s32 d);
extern void *SndMgr_PlayAt(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern void Drop_SpawnWeighted(void *a, void *b, s32 c, VecFx32 *pos, u16 *rot, s32 d);
extern void func_ov000_0219b5dc(u16 id, const VecFx32 *pos, const u16 *rot);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern void Target_SetActor(void *p, Ov003Actor *a);

static inline Ov003Actor *Ov009_FindActor(u16 id) {
    Ov003Actor *a = NULL;
    if (gActorMgr != NULL) {
        a = ActorMgr_GetActor(gActorMgr, id);
    }
    return a;
}

void Ov009Act_02202788_StateDie(Ov009Act_02202788 *self) {
    EffectObj *e;
    Ov003Actor *a;
    ActorSub40 *st;
    TblActorParam *c;
    if (self->hitMesh != NULL) {
        HitMesh_Unlink_0203f920(self->hitMesh);
    }
    switch (self->fsm->st) {
    case 0: {
        ActorSub48 *m;
        ActorSub44 *s;
        *self->hp = 0;
        m = self->hit;
        m->unk_9a_0 = 0;
        m->unk_9a_3 = 0;
        HitSphere_Unlink_0203f364(m);
        s = self->unk_44;
        s->unk_22_0 = 0;
        s->unk_22_1 = 0;
        self->targetObj->target = 0xffff;
        e = Effect_SpawnId(0x322, &self->pos);
        e->AddPosXYZ(0, self->centerY, 0);
        e->SetScaleAll(0x2000);
        e->loopCount = -1;
        self->unk_f4 = e->id;
        switch (self->kind) {
        case 0x5049:
            a = Ov009_FindActor(self->target_id);
            if (a != NULL) {
                Actor_SendMsgU8(a, self->id, 0x15);
            }
            break;
        case 0x5055:
            a = Ov009_FindActor(self->target_id);
            if (a != NULL) {
                a->unk_1a = 1;
            }
            ActorMgr_BroadcastKind(gActorMgr, 0x4003, 0x15);
            break;
        }
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    }
    case 1: {
        u16 t;
        st = self->fsm;
        st->timer++;
        t = st->timer;
        if (t >= 0x78) {
            Field_ShakeCamera(10, 0x3c);
            EffectMgr_Kill(gEffectMgr, self->unk_f4);
            Effect_SpawnId(1, &self->pos)->AddPosXYZ(0, self->centerY, 0);
            e = Effect_SpawnId(5, &self->pos);
            e->AddPosXYZ(0, self->centerY, 0);
            e->SetScaleAll(0x4000);
            a = Ov009_FindActor(self->unk_f0);
            if (a != NULL) {
                Actor_SendMsgU8(a, self->unk_f0, 0x15);
            }
            self->fsm->st = 10;
            break;
        }
        if (t >= 0x28 && t % 10 == 0) {
            VecFx32 p;
            VecFx32 v;
            p.x = self->pos.x;
            p.y = self->pos.y;
            p.z = self->pos.z;
            p.y += self->centerY;
            v.x = self->radius;
            v.y = self->height >> 2;
            v.z = self->radius;
            Spawn_ScatterEffect(&p, &v, 0x733, 0xccd, 4, 0x32);
            Field_ShakeCamera(8, 8);
            SndMgr_PlayAt(gSndMgr, 0x35, &p, 0);
        }
        break;
    }
    case 10:
        c = Tbl_GetActorParam(self->kind);
        Drop_SpawnWeighted(c->dropIds, c->dropRates, 2, &self->pos, &self->rot_x, 1);
        func_ov000_0219b5dc(self->unk_b0->unk_06, &self->pos, &self->rot_x);
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    case 11:
        st = self->fsm;
        st->timer++;
        if (st->timer > 0x3c) {
            Target_SetActor(self->hp, ActorMgr_FindPlayer());
            Ov003Actor_Defeat(self, 1, 1, 1);
            break;
        }
        Ov003Actor_SetAlpha(self, 0x1f - (self->fsm->timer >> 1));
        break;
    }
}

}
}  // namespace m_02203428

// ---- merged from ov009_0220387c.cpp
namespace m_0220387c {
struct Ov009SpawnDesc2 {
    u16 kind;
    u16 flags;
    u16 unk_04[4];
    s16 parent;
};

struct Ov009Rot16 {
    u16 x;
    u16 y;
    u16 z;
};

struct Ov009Flag8 {
    u8 b0 : 1;
    u8 b1 : 7;
};

static inline void Ov009Spawn_Init(Ov009SpawnDesc2 *d, u16 k) {
    s32 i;
    d->kind = k;
    d->flags = k & 0xf000;
    for (i = 0; i < 4; i++) {
        d->unk_04[i] = 0;
    }
    d->parent = -1;
}

extern "C" {

extern u8 data_ov009_02215e9c[];
extern Ov003Actor *Group_SpawnActor(void *mgr, Ov009SpawnDesc2 *d, VecFx32 *pos, Ov009Rot16 *rot, u16 a);

void Ov009Act_02202788_SpawnShot(Ov009Act_02202788 *self) {
    Ov009SpawnDesc2 desc;
    VecFx32 p;
    Ov003Actor *o;
    u8 *tmpl = data_ov009_02215e9c;
    Ov009Spawn_Init(&desc, 0x483c);
    {
        s32 z;
        p.x = self->pos.x;
        p.y = self->pos.y;
        z = self->pos.z;
        p.y += 0x4e66;
        p.z = z;
    }
    Ov009Rot16 r = *(Ov009Rot16 *)&self->rot_x;
    r.x = 0x1c70;
    o = Group_SpawnActor(gGroup, &desc, &p, &r, 0xffff);
    if (o == NULL) {
        return;
    }
    o->unk_60 = tmpl;
    o->target = self->target;
    if (o->targetObj != NULL) {
        o->targetObj->target = self->id;
    }
    self->target_id = o->id;
    ((Ov009Flag8 *)((u8 *)o + 0x16))->b0 = 1;
}

}
}  // namespace m_0220387c

// ---- merged from ov009_0220397c.cpp
namespace m_0220397c {
extern "C" {

extern void *gSndMgr;
extern void SndMgr_LoadHeapState(void *mgr, s32 a, s32 b);
extern void SceneCmd_Push25(FieldState *g, s32 a);

void Ov009Names_Fill_0220397c(Ov009Names *self, u16 kind) {
    char *a = Tbl_GetResFile(kind);
    char *b = func_020701d4(kind);
    TblActorParam *c = Tbl_GetActorParam(kind);
    const char *s;
    char *t;
    STD_CopyString(self->mdlDir, a);
    STD_CopyString(self->mdlName, b);
    self->ownMdl = 1;
    s = data_ov009_02215d38;
    STD_CopyString(self->anmDir, s);
    STD_CopyString(self->anmName, data_ov009_02215d40);
    self->ownAnm = 1;
    t = c->evName;
    if (t != NULL) {
        STD_CopyString(self->evDir, s);
        STD_CopyString(self->evName, t);
        self->ownEv = 1;
    }
    self->unk_00 = 0;
}


void Ov009ActVt_02216c74_Init(Ov009ActVt_02216c74 *self) {
    GroupNode *p;
    if (self->kind == 0x5053) {
        self->unk_d8 = (void *)Ov009Names_Fill_0220397c;
    }
    Ov003Actor_Init(self);
    p = Group_FindNode(gGroup, self->unk_20);
    if (p != NULL) {
        GroupNodeFlags *bb = &p->flags;
        bb->unk_0 = 0;
        bb->unk_5 = 1;
    }
    SndMgr_LoadHeapState(gSndMgr, 1, 1);
    switch (self->kind) {
    case 0x502e:
    case 0x5033:
    case 0x504c:
        SceneCmd_Push25(gSceneCmd, 0xd);
        self->unk_1a = 0;
        break;
    case 0x5053:
        SceneCmd_Push25(gSceneCmd, 0x10);
        self->unk_1a = 1;
        break;
    case 0x5059:
        SceneCmd_Push25(gSceneCmd, 0xd);
        self->unk_1a = 0;
        Ov003Actor_ScaleStats(self, data_ov009_02215d64);
        break;
    }
    self->unk_c8 = 0x1e000;
    self->unk_cc = 0xc000;
    self->unk_f0 = 0;
}

}
}  // namespace m_0220397c

// ---- merged from ov009_02203b8c.cpp
namespace m_02203b8c {
extern "C" {


void Ov009ActVt_02216c74_Update(Ov009ActVt_02216c74 *self) {
    Ov003Actor_Update(self);
    if (self->fsm->current == 0xf) {
        return;
    }
    EffectMgr_Kill(gEffectMgr, self->unk_f0);
    self->unk_f0 = NULL;
}

extern void *gSndMgr;
extern const VecFx32 data_ov009_02215e08;
extern char data_ov009_02216bae[];
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern void *SndMgr_PlayAt(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *other, s32 a);
extern void Field_ShakeCamera(s32 a, s32 b);

void Ov009ActVt_02216c74_StateAttack(Ov009ActVt_02216c74 *self) {
    Ov003Actor *t;
    s32 state;
    ActorSub40 *st;
    EffectObj *e;
    state = self->fsm->st;
    t = Actor_GetTarget(self);
    switch (state) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov009_02215d0c, 0x400, 0);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        e = Effect_SpawnId(0x3ea, &self->pos);
        e->AddPos(&data_ov009_02215e08);
        e->SetRot(&self->rot);
        e->SetScaleAll(0x5800);
        e->speed = 0x1800;
        e->loopCount = -1;
        self->unk_f0 = e->id;
        SndMgr_PlayAt(gSndMgr, data_ov009_02215d5c[self->unk_1a], &self->pos, 0);
        self->fsm->timer = 0;
        self->fsm->st++;
    case 1:
        if (EffectMgr_FindByKey(gEffectMgr, 0x2bd) == 0) {
            e = Effect_SpawnId(0x2bd, &self->pos);
            e->AddPosXYZ(0, 0x19a, 0);
            e->SetScaleAll(0x2000);
            e->speed = 0x4000;
        }
        st = self->fsm;
        st->timer++;
        if (st->timer > 0x50) {
            self->velY = 0x266;
            self->gravity = 0x29;
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        Actor_TurnToActor(self, t, 0x400);
        self->moveYaw = self->rot_y;
        break;
    case 2:
        if (self->hit->unk_50 & 0x20000000) {
            SndMgr_PlayAt(gSndMgr, 0x7e, &self->pos, 0);
            Field_ShakeCamera(3, 5);
            self->velY = 0x666;
            self->speed = 0x266;
            self->gravity = 0x52;
            self->fsm->st++;
        }
        Actor_TurnToActor(self, t, 0x400);
        self->moveYaw = self->rot_y;
        break;
    case 3:
        if (!(self->hit->unk_50 & 0x20000000)) {
            break;
        }
        SndMgr_PlayAt(gSndMgr, 0x7e, &self->pos, 0);
        Field_ShakeCamera(3, 5);
        Effect_SpawnId(0x12f, &self->pos)->SetScaleAll(0x800);
        st = self->fsm;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        st->st++;
        break;
    case 4: {
        u16 tm;
        st = self->fsm;
        st->timer++;
        tm = st->timer;
        if (tm == 0x32) {
            EffectMgr_Kill(gEffectMgr, self->unk_f0);
            self->unk_f0 = NULL;
            Model0218fe1c_SetAnim(self->model, data_ov009_02215d1c, 0x400, 0);
        }
        if (tm > 0x32 && self->model->anim_state == 1) {
            self->fsm->timer = 0;
            if (Rand_UpTo(9) > 1) {
                e = Effect_SpawnId(0x44d, &self->pos);
                e->AddPosXYZ(0, 0x1800, 0);
                e->loopCount = 1;
                st = self->fsm;
                st->st++;
            } else {
                self->fsm->st = 10;
            }
        }
        break;
    }
    case 5:
        if (self->model->anim_state == 2) {
            self->fsm->st++;
        }
        break;
    case 6:
        st = self->fsm;
        st->timer++;
        if (st->timer > 0xc8) {
            Model0218fe1c_SetAnim(self->model, data_ov009_02216bae, 0x111, 0);
            self->fsm->timer = 0;
            self->fsm->st = 0x1e;
        }
        break;
    case 10:
        if (self->model->anim_state == 2) {
            Effect_SpawnId(0x68, &self->pos)->AddPosXYZ(0, 0x19a, 0);
            SndMgr_PlayAt(gSndMgr, 8, &self->pos, 0);
            History_SetState(self->fsm, 1, 0);
        }
        break;
    case 0x1e:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
    Actor_Move(self, 0);
    Body_Update(self->hit, 1, 0, 0);
    e = Effect_Find_020657b0(gEffectMgr, self->unk_f0);
    if (e != NULL) {
        e->SetPos(&self->pos);
        e->AddPos(&data_ov009_02215e08);
        e->SetRot(&self->rot);
    }
    if (state < 4) {
        self->unk_94_1 = 1;
    }
}

}
}  // namespace m_02203b8c

// ---- merged from ov009_022040f0.cpp
namespace m_022040f0 {
extern "C" {


void Ov009ActVt_02216c74_StateDie(Ov009ActVt_02216c74 *self) {
    if (self->fsm->st == 0) {
        self->radius >>= 1;
        EffectMgr_Kill(gEffectMgr, self->unk_f0);
        self->unk_f0 = NULL;
    }
    Ov003Actor_StateDie(self);
}

}
}  // namespace m_022040f0

// ---- merged from ov009_0220413c.cpp
namespace m_0220413c {
extern "C" {

extern void *gSndMgr;
extern void SndMgr_LoadHeapState(void *mgr, s32 a, s32 b);
extern void SceneCmd_Push25(FieldState *g, s32 a);

void Ov009Names_Fill_0220397c(Ov009Names *self, u16 kind);

void Ov009ActVt_02216bc8_Init(Ov009ActVt_02216bc8 *self) {
    GroupNode *p;
    if (self->kind != 0x5810 && self->kind != 0x5811) {
        self->unk_d8 = (void *)Ov009Names_Fill_0220397c;
    }
    Ov003Actor_Init(self);
    p = Group_FindNode(gGroup, self->unk_20);
    if (p != NULL) {
        GroupNodeFlags *bb = &p->flags;
        bb->unk_0 = 0;
        bb->unk_5 = 1;
    }
    SndMgr_LoadHeapState(gSndMgr, 1, 1);
    switch (self->kind) {
    case 0x503e:
        self->unk_ea |= 0x400;
    case 0x504d:
        SceneCmd_Push25(gSceneCmd, 0xd);
        break;
    case 0x5027:
        SceneCmd_Push25(gSceneCmd, 0xf);
        self->unk_ea |= 0x400;
        break;
    }
    self->unk_f8 = 0;
}

extern const VecFx32 data_ov009_02215e24[];
struct Ov009Trail {
    u8 unk_00[0x10c];
    VecFx32 trail[5];
};

void Ov009ActVt_02216bc8_Start(Ov009ActVt_02216bc8 *self) {
    s16 n;
    u8 i;
    Ov003Actor_Start(self);
    self->unk_f3 = 0;
    if (!(self->kind != 0x5810 && self->kind != 0x5811)) {
        self->unk_f2 = 1;
        self->unk_f6 = 0x50;
        self->unk_fc = 0x2000;
    } else {
        self->unk_f2 = 0;
        self->unk_fc = 0x3000;
        self->unk_c8 = 0x16800;
        self->unk_cc = 0xc000;
    }
    n = self->unk_1a;
    if (n != 0) {
        if (n >= 10 && n < 15) {
            n = n - 10;
            self->unk_f3 = 1;
            if (self->unk_f2 == 1 && self->unk_18 != 0) {
                self->pos = data_ov009_02215e24[n];
            }
        }
        self->unk_18 = n;
    }
    self->unk_f1 = self->unk_18;
    self->unk_100 = self->model->scale;
    for (i = 0; i < 5; i++) {
        ((Ov009Trail *)self)->trail[i] = data_ov009_02215d90;
    }
    if (self->unk_f2 != 1) {
        self->hit->offset.y = 0x1000;
    } else {
        self->hit->offset.y = -0x400;
        self->hit->unk_48 = 0x1000;
        VecFx32 *dst = &self->model->scale;
        *dst = data_ov009_02215d90;
        self->pos.y += 0x2000;
        self->unk_ea_6 = 1;
        History_SetState(self->fsm, 0x20, 0);
    }
    self->unk_f0 = 0;
    self->unk_1c = 0x38e;
}

}
}  // namespace m_0220413c

// ---- merged from ov009_02204410.cpp
namespace m_02204410 {
extern "C" {

struct Ov009Msg {
    u8 unk_00[0x5];
    u8 type;
    u8 unk_06[0x2];
    u8 idx;
    u8 unk_09[0x3];
    VecFx32 v;
};

extern BOOL Ov003Actor_HandleMsg(Ov003Actor *self, Ov009Msg *msg);

void Ov009ActVt_02216bc8_HandleMsg(Ov009ActVt_02216bc8 *self, Ov009Msg *msg) {
    if (msg->type == 0xe) {
        VecFx32 *dst = (VecFx32 *)((u8 *)self + msg->idx * 0xc + 0x10c);
        dst->x = msg->v.x;
        dst->y = msg->v.y;
        dst->z = msg->v.z;
        self->msg_flags |= 1 << msg->type;
        msg->type = 0;
    }
    Ov003Actor_HandleMsg(self, msg);
}

extern void Vec_RotateY(VecFx32 *out, const void *a, s32 b);
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern void HitSphere_Link(ActorSub48 *p);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern void Actor_TurnToActor(Ov003Actor *self, Ov003Actor *other, s32 a);
static inline BOOL Ov009Game_IsPaused(FieldState *g) {
    return g->event != 0;
}

// Read through a const view: MWCC does not merge it with the compare's read just before.
static inline s32 Ov009_MaxScaleX(const Ov009ActVt_02216bc8 *a) {
    return a->unk_100.x;
}

void Ov009ActVt_02216bc8_State20(Ov009ActVt_02216bc8 *self) {
    VecFx32 v;
    EffectObj *obj;
    s32 ang;
    s32 h;
    ActorSub44 *s44;
    ActorSub48 *s48;
    ActorSub40 *st;
    switch (self->fsm->st) {
    case 0:
        if (!Ov009_GameIdle()) {
            return;
        }
        if (Ov009Game_IsPaused(gSceneCmd)) {
            return;
        }
        obj = Effect_SpawnId(0x389, &self->pos);
        obj->SetScaleAll(0x3000);
        ang = FieldCam_GetYaw(&gSceneCmd->cam);
        v.x = 0;
        v.y = 0;
        v.z = -0x800;
        Vec_RotateY(&v, &v, ang);
        obj->AddPos(&v);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        s48 = self->hit;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        HitSphere_Unlink_0203f364(s48);
        self->model->visible = 1;
        self->fsm->timer = 0;
        self->fsm->st++;
    case 1:
        st = self->fsm;
        st->timer++;
        if (st->timer >= 0x32) {
            h = self->model->scale.x + 0x266;
            if (h >= self->unk_100.x) {
                h = Ov009_MaxScaleX(self);
                Effect_SpawnId(0x69, &self->pos);
                Effect_SpawnId(0x38a, &self->pos);
                s44 = self->unk_44;
                s44->unk_22_0 = 1;
                s44->unk_22_1 = 1;
                s48 = self->hit;
                s48->unk_9a_0 = 1;
                s48->unk_9a_3 = 1;
                HitSphere_Link(s48);
                self->fsm->timer = 0;
                History_SetState(self->fsm, 1, 0);
            }
            {
                VecFx32 *s = &self->model->scale;
                s->x = h;
                s->y = h;
                s->z = h;
            }
        }
        break;
    }
    Actor_TurnToActor(self, ActorMgr_FindPlayer(), 0x400);
}

}
}  // namespace m_02204410

// ---- merged from ov009_022046cc.cpp
namespace m_022046cc {
extern "C" {

void Ov009ActVt_02216bc8_StateIdle(Ov009ActVt_02216bc8 *self) {
    VecFx32 p;
    ActorSub40 *st;
    if (self->fsm->st == 0) {
        self->unk_f0 = 0;
        self->hit->unk_30 = 0x40000000;
    }
    if (self->unk_f2 == 0) {
        Ov003Actor_StateIdle(self);
        return;
    }
    if (self->fsm->st == 0) {
        Model0218fe1c_SetAnim(self->model, data_ov009_02215d30, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->timer = 0;
        self->fsm->st++;
    }
    Body_Update(self->hit, 1, 0, 0);
    p = self->pos;
    if (Geom_SnapToGround(&p, 0x3800, -0xa000) != -0x1000) {
        p.y += 0x2000;
    }
    {
        s32 y = self->pos.y;
        self->pos.y = y + FX_Mul(p.y - y, 0x19a);
    }
    VEC_Distance(&self->pos, &p);
    if (self->hit->unk_50 & 0x20000000) {
        return;
    }
    st = self->fsm;
    st->timer++;
    if (st->timer > 0x46) {
        self->fsm->timer = 0x46;
        if (!(self->hit->unk_54 & 0x20000000)) {
            History_SetState(self->fsm, 0x15, 0);
        }
    }
}

}
}  // namespace m_022046cc

// ---- merged from ov009_0220487c.cpp
namespace m_0220487c {
extern "C" {

extern void Actor_MoveToPos(Ov003Actor *self, VecFx32 *v, s32 a);

void Ov009ActVt_02216bc8_StateMove(Ov009ActVt_02216bc8 *self) {
    VecFx32 v;
    VecFx32 p;
    if (self->unk_f2 == 0) {
        Ov003Actor_StateMove(self);
        return;
    }
    if (self->fsm->st == 0) {
        Model0218fe1c_SetAnim(self->model, data_ov009_02215d30, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
    }
    v = self->unk_b8;
    self->speed = self->unk_b0->unk_00;
    Actor_MoveToPos(self, &v, self->unk_b0->unk_02);
    p = self->pos;
    if (Geom_SnapToGround(&p, 0x3800, -0xa000) != -0x1000) {
        if (p.y < v.y) {
            p.y = v.y;
        }
        p.y += 0x2000;
    }
    {
        s32 y = self->pos.y;
        self->pos.y = y + FX_Mul(p.y - y, 0x19a);
    }
    VEC_Distance(&self->pos, &p);
    Body_Update(self->hit, 1, 0, 0);
}

}
}  // namespace m_0220487c

// ---- merged from ov009_022049e4.cpp
namespace m_022049e4 {
extern "C" {

void Ov009ActVt_02216bc8_StateThrown(Ov009ActVt_02216bc8 *self) {
    if (self->fsm->st == 0 && self->unk_f3 == 1) {
        self->hit->unk_30 = 0;
    }
    Ov003Actor_StateThrown(self);
}

}

#ifdef NONMATCHING
// Status (round drA): Ov009ActVt_02216bc8_StateAttack is 295 / 283 (raw / register-masked, dsi/1.3 with the project flags); this
// is the best clean draft. Blocker: the hoisted self + 0x10c base is kept in fp, the ROM spills it (every stack
// offset from 0x10 up is 4 low); the 57-67 drafts need a volatile base pointer. History: docs/MATCHING.md rounds
// qpD, qpG, qpL, svB, cvA (search for the address); the full list is docs/UNMATCHED.md.
// Ov009ActVt_02216bc8_StateAttack: 153 / 279 (register-masked / raw, honest_search scorer; was 151 / 379),
// no fake parameters, volatile or junk locals. Round qpD: the trail loop reads self->trail[i]
// directly, which gives the ROM's code shape there (one i * 12 shared by the VEC_Distance
// argument and the [self + i * 12, #0x10c] loads, with self + 0x10c hoisted). What is left:
// - the ROM spills that hoisted self + 0x10c to [sp, #0x10] (frame 0x104, no pushed r3); our
//   colouring keeps it in fp and spills the hoisted &v instead, so every stack offset from
//   0x10 up is 4 bytes low. In our graph &v costs 13 and the base 17; the ROM needs one more
//   value live across the loop (or a base cost of 13 or less). The ROM's
//   "mov r0, #0; mov r4, r0" before the loop suggests that value is a hoisted zero.
// - the 0x666 block after VEC_Normalize(&d, &d): the ROM loads d.z into the register of the
//   stored d.x (so it is not hoisted after allocation) and stores d.y between them.
// Round qpG: the three trail-loop zeros (g.y and the two mla high words of x * 0x666) stay separate
// nodes because the ROM-like merge is refused twice: local CSE will not merge cheap constants in a
// loop preheader, and move-constant-loads stops reusing at the multi-def `i = 0` zero in block 64.
// Merging them by hand under gdb puts the zero in fp, not a spill (42 aligned, worse). "mov r0, #0;
// mov r4, r0" is post-allocation CSE of a constant move. See docs/MATCHING.md, round qpG.
// See docs/MATCHING.md, round qpD.
// Round qpL: a toy loop (Normalize, x/z * 0x666, y = 0, VEC_Add) also keeps the g.y zero and the
// two lowered high-word zeros as three preheader nodes, and no matched object has the ROM's
// "mov rA, #0; mov rB, rA; <rA redefined>" shape, so no source for the merged zero was found. A
// `tr = trail` base local set before the 0219a510 call (raH: a call between def and use keeps the
// object vreg) is 31 aligned / 326 raw, but tr is then live across the list loop and stays in fp.
// Reusing v for g (wrong layout, diagnostic only) does flip the spill to the base at [sp, #0x10].
extern "C" {

extern void Vec_RotateY(VecFx32 *dst, const VecFx32 *src, s32 angle);
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern void Actor_MoveToPos(Ov003Actor *self, VecFx32 *v, s32 a);
extern s32 Actor_FindInRadius(Actor *self, u16 mask, VecFx32 *pos, s32 r, s32 a, Ov003Actor **list);
extern Ov003Actor *Obj021984c8_GetActor(Ov003Actor *p);
extern void ActorMgr_SendToKindOthers(u16 a, u16 b, s32 c, s32 d, s32 e, void *f);
extern void Model0218fe1c_PauseAnim(void *model);

static inline BOOL Ov009Game_IsPaused(FieldState *g) {
    return g->event != 0;
}

static inline void Ov009_VecSub(const VecFx32 *a, const VecFx32 *b, VecFx32 *o) {
    o->x = a->x - b->x;
    o->y = a->y - b->y;
    o->z = a->z - b->z;
}

struct Ov009Trail {
    u8 unk_00[0x10c];
    VecFx32 trail[5];
};

struct Ov009HitMsg {
    u8 idx;
    VecFx32 pos;
};

void Ov009ActVt_02216bc8_StateAttack(Ov009ActVt_02216bc8 *self) {
    VecFx32 v;
    VecFx32 pp;
    VecFx32 d;
    VecFx32 f;
    VecFx32 g;
    Ov009HitMsg msg;
    VecFx32 x;
    VecFx32 d2;
    VecFx32 w;
    Ov003Actor *list[32];
    Ov003Actor *pl;
    ActorSub40 *st;
    EffectObj *o;
    ActorSub44 *s44;
    ActorSub48 *s48;
    s32 h;
    if (!Ov009_GameIdle()) {
        return;
    }
    if (Ov009Game_IsPaused(gSceneCmd)) {
        return;
    }
    pl = ActorMgr_FindPlayer();
    pp = pl->pos;
    st = self->fsm;
    switch (st->st) {
    case 0: {
        s32 t;
        Model0218fe1c_SetAnim(self->model, data_ov009_02215d0c, 0x400, 0);
        v = self->pos;
        v.y += 0x2000;
        self->unk_b8 = v;
        t = 0x3c;
        if (self->unk_f2 == 1) {
            t = 0x28;
        }
        self->unk_f4 = t + Rand_UpTo(0x32);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        if (self->unk_f2 == 0) {
            self->fsm->st++;
        } else {
            self->fsm->st = 10;
        }
    }
    case 1:
        st = self->fsm;
        st->timer++;
        if (st->timer == 5) {
            o = Effect_SpawnId(0x192, &self->pos);
            o->AddPosXYZ(0, 0x4000, 0);
            o->SetRotXYZ(0xbfff, 0, 0);
            EffectObj_AddSndCue(o, 0x54, 0);
            o = Effect_SpawnId(0x68, &self->pos);
            o->AddPosXYZ(0, 0x400, 0);
            o->alpha = FX_Div(0x1e000, 0x1f000);
            Effect_SpawnId(0x12f, &self->pos)->SetScaleAll(0x800);
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    case 2: {
        s32 sy;
        Model0218fe1c *m = self->model;
        h = m->scale.x;
        sy = m->scale.y;
        h -= 0x19a;
        if (h <= 0) {
            h = 0;
            s48 = self->hit;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(s48);
            s44 = self->unk_44;
            s44->unk_22_0 = 0;
            s44->unk_22_1 = 0;
            Model0218fe1c_SetAnim(self->model, data_ov009_02215d30, 0x1000, 0);
            self->model->visible = 0;
            self->fsm->timer = 0;
            self->fsm->st = 0x14;
        }
        m = self->model;
        m->scale.x = h;
        m->scale.y = sy + 0xcd;
        m->scale.z = h;
        v = self->unk_b8;
        Ov009_VecSub(&v, &self->pos, &d2);
        VEC_MultAdd(0x19a, &d2, &self->pos, &self->pos);
        break;
    }
    case 10:
        o = Effect_SpawnId(0x389, &self->pos);
        o->SetScaleAll(0x3000);
        h = FieldCam_GetYaw(&gSceneCmd->cam);
        v.x = 0;
        v.y = 0;
        v.z = -0x800;
        Vec_RotateY(&v, &v, h);
        o->AddPos(&v);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    case 11: {
        Model0218fe1c *m;
        h = self->model->scale.x - 0x52;
        if (h <= 0) {
            Effect_SpawnId(0x38a, &self->pos);
            h = 0;
            s48 = self->hit;
            s48->unk_9a_0 = 0;
            s48->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(s48);
            self->model->visible = 0;
            self->fsm->timer = 0;
            self->fsm->st = 0x14;
        }
        m = self->model;
        m->scale.x = h;
        m->scale.y = h;
        m->scale.z = h;
        break;
    }
    case 0x14: {
        u32 t;
        s32 dist;
        st->timer++;
        t = st->timer;
        if (!(self->hit->unk_50 & 0x40000000)) {
            s32 off;
            s32 n;
            u8 i;
            dist = VEC_Distance(&self->pos, &pp);
            self->speed = 0x1ec;
            if (dist < 0x2800) {
                self->speed = -self->speed;
            }
            Actor_MoveToPos(self, &pp, 0x1000);
            off = 0x2333;
            if (self->unk_f2 == 1) {
                off = 0x2000;
            }
            w = self->pos;
            if (Geom_SnapToGround(&w, off + 0x1800, -0xa000) != -0x1000) {
                if (w.y < pp.y) {
                    w.y = pp.y;
                }
                w.y += off;
            }
            self->pos.y += FX_Mul(w.y - self->pos.y, 0x1000);
            VEC_Distance(&self->pos, &w);
            Ov009_VecSub(&self->pos, &pp, &d);
            Vec_RotateY(&d, &d, (u16)(self->unk_1c + 0xffff));
            VEC_Add(&d, &pp, &d);
            d.y = self->pos.y;
            Ov009_VecSub(&d, &self->pos, &d);
            VEC_Normalize(&d, &d);
            d.x = FX_Mul(d.x, 0x666);
            d.z = FX_Mul(d.z, 0x666);
            d.y = 0;
            VEC_Add(&self->pos, &d, &self->pos);
            n = Actor_FindInRadius(self, 0x20, &self->pos, 0x2000, 0, list);
            if (n != 0) {
                s32 k;
                for (k = 0; k < n; k++) {
                    Ov003Actor *q;
                    if (list[k] != NULL && (q = Obj021984c8_GetActor(list[k])) != NULL) {
                        v = q->pos;
                        Ov009_VecSub(&self->pos, &v, &v);
                        VEC_Normalize(&v, &v);
                        f.x = FX_Mul(v.x, 0x666);
                        f.y = 0;
                        f.z = FX_Mul(v.z, 0x666);
                        VEC_Add(&self->pos, &f, &self->pos);
                        break;
                    }
                }
            }
            for (i = 0; i < 5; i++) {
                if (self->unk_f1 == i) {
                    continue;
                }
                if (VEC_Distance(&self->pos, &((Ov009Trail *)self)->trail[i]) <= self->unk_fc) {
                    v.x = self->pos.x - ((Ov009Trail *)self)->trail[i].x;
                    v.y = self->pos.y - ((Ov009Trail *)self)->trail[i].y;
                    v.z = self->pos.z - ((Ov009Trail *)self)->trail[i].z;
                    VEC_Normalize(&v, &v);
                    g.x = FX_Mul(v.x, 0x666);
                    g.y = 0;
                    g.z = FX_Mul(v.z, 0x666);
                    VEC_Add(&self->pos, &g, &self->pos);
                    self->unk_1c = -self->unk_1c;
                }
            }
            msg.idx = self->unk_f1;
            msg.pos = self->pos;
            ActorMgr_SendToKindOthers(self->kind, self->kind, 0xe, 1, 0x10, &msg);
            if (t >= self->unk_f4 && dist <= 0x3000) {
                History_SetState(self->fsm, 0x10, 0);
            }
        } else {
            self->unk_1c = -self->unk_1c;
        }
        if (t >= 0xd2) {
            History_SetState(self->fsm, 0x10, 0);
        }
        if (self->unk_f2 == 0) {
            GroupNode *b = Group_FindNode(gGroup, self->unk_20);
            if (b != NULL) {
                x = b->pos;
            }
            x.y = self->pos.y;
            if (VEC_Distance(&self->pos, &x) > self->unk_c8 + 0x4800) {
                if (b != NULL) {
                    x = b->pos;
                }
                x.y += 0x2000;
                self->pos = x;
                self->unk_f0 = 1;
                History_SetState(self->fsm, 0x10, 0);
            }
        }
        Body_Update(self->hit, 0, 0, 0);
        break;
    }
    }
    self->unk_ea_0 = 3;
    self->unk_94_1 = 1;
    if ((s32)self->fsm->st <= 2 && self->model->anim_state == 1) {
        Model0218fe1c_PauseAnim(self->model);
    }
}

}
#endif
}  // namespace m_022049e4
