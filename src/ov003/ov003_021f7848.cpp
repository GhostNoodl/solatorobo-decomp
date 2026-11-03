#include <nitro/fx.h>
#include "Main/Math/Rot16.h"
#include "Main/Snd/SndMgr.h"
#include "ov003/Vec.h"
#include "Main/Effect/Effect.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ActorParts.h"
#include "nitro/mi.h"
#include "ov003/ActorApi.h"
#include "ov003/Unit.h"

// Vtable 021f95d4 (0xd4 bytes: Factory_New4000). When its model's animation state is 1 or 2
// it fires shot ActorEx::unk_ce_s8 (data_ov003_021f6b44; -1: none) for dur frames.
class Ov003Cannon : public ActorEx {
public:
    s16 dur;
};
SIZE_ASSERT(Ov003Cannon, 0xd4);

// Vtable 021f9374 (0xf0 bytes: Factory_New4000, kinds 0x4076 and 0x4086). It turns about y by
// turnSpeed in direction ActorEx::unk_ce_s8 (+-1), reversing once it is swingRange / 2 away from
// baseAngle, and keeps an effect (ActorEx::unk_bc) at fxBase turned by rot.y (ActorEx::fxOffset),
// scaled by fxScale; it fires a shot from fxBase.
class Ov003Swing : public ActorEx {
public:
    u16 turnSpeed;
    u16 swingRange; // Actor::unk_1c degrees (* 0xb6); 0: it turns all the way
    u16 baseAngle; // rot.y at Start
    u16 frames; // 0x4086: the effect scale cycles with it
    VecFx32 fxBase;
    VecFx32 fxScale;
};
SIZE_ASSERT(Ov003Swing, 0xf0);

// Vtable 021f91ac (0xd4 bytes: Factory_New4000, kinds 0x405c, 0x407b, 0x407c, 0x407d). Its
// type (ActorEx::unk_ce_u) is 0 for 0x405c/0x407b, which fire after wait frames, and 1 for the
// others, which fire when the model's animation state is 1.
class Ov003Mover : public ActorEx {
public:
    s16 wait;
};
SIZE_ASSERT(Ov003Mover, 0xd4);

// Vtable 021f9114 (0xd4 bytes: Factory_New4000). It counts (Actor::unk_18, up to unk_1a)
// the kind-0xb actors that come near it; ActorEx::unk_ce is the id of the last one, and flash the
// frames left of the model's colour blend after each.
class Ov003Gate : public ActorEx {
public:
    u16 flash;
};
SIZE_ASSERT(Ov003Gate, 0xd4);

// Vtable 021f94a4 (0xdc bytes: Factory_New4000): it hovers about Actor::unk_84 (pos at Start,
// raised by 0x800), easing toward target, a new random point near it every 0x3c frames.
class Ov003Hover : public ActorEx {
public:
    VecFx32 target;
};
SIZE_ASSERT(Ov003Hover, 0xdc);

// Vtable 021f940c (0x104 bytes: Factory_New4000): it moves back and forth between ends[0]
// (pos at Start) and ends[1] (data_ov003_021f6b5c[Actor::unk_1a].dist ahead), from `from` toward
// Actor::unk_84; Draw draws the model at pos + mdlOfs.
class Ov003Patrol : public ActorEx {
public:
    VecFx32 ends[2];
    VecFx32 from;
    VecFx32 mdlOfs;
    u16 baseYaw; // rot.y at Start
    u8 endIdx; // the end taken next
};
SIZE_ASSERT(Ov003Patrol, 0x104);

// A header's zero rotation and vector, plus copies made at startup, among this TU's motion
// names, the pointers to them, two angle tables and six vectors. Other functions read the
// pointers, the tables and the named vectors; the unnamed ones are read through offsets.
// The functions after the data, Ov003ActExMdl_DoAttack to Ov003ActVt_021f92dc_State06, are part of this TU:
// Ov003ActExMdl_DoAttack and Ov003ActVt_021f92dc_State06 copy data_ov003_021f6ae4 through the .rodata base
// plus an offset. The files in between were merged in, each in its own namespace so that their
// local types and inlines keep their names; their functions are extern "C" either way.
// Round dtB: ov003_021e7780.cpp and ov003_021e8030.cpp (0x021e7780..0x021e83d0) were merged in
// front, and the merged functions read the name pointers and the zero rotation by their names
// (data_ov003_021f6a80/6a84/6a88/6a8c, data_ov003_021f6a90, typed as an Rot16) instead of
// namespace-local redeclarations of data_ov003_021f6a80 as an array or struct. The two angle
// tables are u16 (every reader loads them with ldrh), so the u16 redeclarations are gone too.

// 12-byte block: assigning one copies with ldm/stm (as Ov010Blk12 / Ov011Blk12)
typedef struct {
    s32 w[3];
} Ov003Blk12;

extern const char *const data_ov003_021f6a80;
extern const u16 data_ov003_021f6a96[4];
extern const u16 data_ov003_021f6a9e[5];
extern const Ov003Blk12 data_ov003_021f6aa8;
extern const Ov003Blk12 data_ov003_021f6ab4;
extern const Ov003Blk12 data_ov003_021f6ac0;
extern const VecFx32 data_ov003_021f6acc;
extern const VecFx32 data_ov003_021f6ad8;
extern char data_ov003_021f90e0[];
extern char data_ov003_021f90e6[];
extern char data_ov003_021f90ec[];
extern char data_ov003_021f90f8[];
const u16 data_ov003_021f6a9e[5] = {0x2d, 0x5b, 0xb6, 0x16c, 0x2d8};
static const char *const data_ov003_021f6a88 = data_ov003_021f90e0;
static const char *const data_ov003_021f6a8c = data_ov003_021f90ec;
const VecFx32 data_ov003_021f6ad8 = {0, 0, 0};
const char *const data_ov003_021f6a80 = data_ov003_021f90f8;
static const char *const data_ov003_021f6a84 = data_ov003_021f90e6;
const u16 data_ov003_021f6a96[4] = {0x5b, 0xb6, 0x16c, 0x2d8};
const Ov003Blk12 data_ov003_021f6ab4 = {0xe66, 0xe66, 0xe66};
char data_ov003_021f90f8[] = "act00";
const VecFx32 data_ov003_021f6acc = {0, FX32_ONE, 0};
char data_ov003_021f90e6[] = "run00";
char data_ov003_021f90ec[] = "att00";
const Ov003Blk12 data_ov003_021f6aa8 = {0x2000, 0x1000, 0x2000};
const Ov003Blk12 data_ov003_021f6ac0 = {0x8cd, 0x8cd, 0x8cd};
char data_ov003_021f90e0[] = "nut00";
static const VecFx32 data_ov003_021f6ae4 = {0, 0, 0};
static const Rot16 data_ov003_021f6a90 = {0, 0, 0};
static const Rot16 data_ov003_021f90f2 = data_ov003_021f6a90;
static const VecFx32 data_ov003_021f9100 = data_ov003_021f6ae4;

// The 0x10-byte records of data_ov003_021f6b5c, indexed by Actor::unk_1a: the hover distance and
// speed, the patrol's y offset (unk_08) and its z spin per frame (unk_0c).
struct Ov003FlyParam {
    s32 dist;
    s32 speed;
    s32 unk_08;
    u16 unk_0c;
};

// ---- merged from ov003_021e7780.cpp
namespace m_021e7780 {

extern "C" {

extern BOOL History_SetState(ActorSub40 *p, s32 a, s32 b);
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *p, const char *name, s32 a, s32 b);
extern void Model0218fe1c_SetLoop(Model0218fe1c *p);
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *model, s32 a);
BOOL func_ov003_021e7ee4(ActorEx *self);
extern s32 Actor_FindInRadius(Actor *self, s32 a, VecFx32 *pos, s32 b, s32 c, void **list);
extern BOOL Obj021984c8_GetActor(void *p);
extern Robo021ca458 *ActorMgr_FindPlayer(void);
extern const VecFx32 data_ov003_021f6b44[];
extern void func_01ffc9fc(VecFx32 *src, VecFx32 *dst, u16 angle);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern BOOL Model0218fe1c_IsAnimDone(Model0218fe1c *p);

static inline BOOL Ov003Game_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov003Game_IsIdle(FieldState *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return true;
}

void Ov003ActVt_021f966c_Start(ActorEx *self) {
    ActorEx_Start(self);
    self->unk_ce = self->unk_18;
    if (self->unk_18 == 0) {
        self->unk_ce = 0x64;
    }
    History_SetState(self->fsm, 1, 0);
}

void Ov003ActVt_021f966c_StateIdle(ActorEx *self) {
    void *list[0x20];
    s32 n;
    s32 i;
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov003_021f6a88, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
    case 1:
        if (!Ov003_GameIdle()) {
            return;
        }
        n = Actor_FindInRadius(self, 2, &self->pos, self->radius, self->height, list);
        if (n == 0) {
            return;
        }
        for (i = 0; i < n; i++) {
            if (list[i] != NULL && Obj021984c8_GetActor(list[i])) {
                History_SetState(self->fsm, 6, 0);
                return;
            }
        }
        break;
    }
}

void Ov003ActVt_021f966c_State06(ActorEx *self) {
    ActorSub40 *w = self->fsm;
    switch (w->st) {
    case 0:
        if (!Ov003_GameIdle()) {
            History_SetState(w, 1, 0);
            return;
        }
        w->timer++;
        if (w->timer > (s16)self->unk_ce) {
            Model0218fe1c_SetAnim(self->model, data_ov003_021f6a8c, 0x1000, 0);
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    case 1:
        w->timer++;
        if (w->timer > 0x40 && ActorMgr_FindPlayer()->hp[0] != 0 && Ov003_GameIdle()) {
            Hit_ApplyInArea(self, self, self->targetObj->unk_08, (u8)self->targetObj->unk_0a, 2, NULL, NULL, self->radius, self->height, 100, 0x1000);
        }
        if (Model0218fe1c_IsAnimDone(self->model)) {
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    case 2:
        w->timer++;
        if (w->timer > 0xf) {
            Model0218fe1c_SetAnim(self->model, data_ov003_021f6a88, 0x111, 0);
            self->fsm->timer = 0;
            self->fsm->st = 0x1e;
        }
        break;
    case 0x1e:
        w->timer++;
        if (w->timer > 0x78) {
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
}

void Ov003ActVt_021f95d4_StateIdle(Ov003Cannon *self) {
    switch (self->fsm->st) {
    case 0:
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        Model0218fe1c_SetAnim(self->model, data_ov003_021f6a88, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        self->unk_ce_s8 = -1;
        self->fsm->st++;
        break;
    case 1: {
        VecFx32 v;
        switch (self->model->anim_state) {
        case 1:
            self->unk_ce_s8 = 0;
            self->dur = 0x32;
            break;
        case 2:
            self->unk_ce_s8 = 1;
            self->dur = 0x28;
            break;
        }
        if (self->unk_ce_s8 == -1) {
            return;
        }
        // A 12-byte block copy (ldm/stm), as Ov003Blk12; a VecFx32 assignment copies word by word.
        *(Ov003Blk12 *)&v = *(const Ov003Blk12 *)&data_ov003_021f6b44[self->unk_ce_s8];
        func_01ffc9fc(&v, &v, self->rot.y);
        VEC_Add(&v, &self->pos, &v);
        SndMgr_PlayAt(data_02097e4c, 0x50, &v, 0);
        self->fsm->st++;
        break;
    }
    case 2: {
        ActorSub40 *w;
        if (ActorMgr_FindPlayer()->hp[0] != 0 && Ov003_GameIdle()) {
            Rot16 r;
            r = self->rot;
            r.x += 0x4000;
            Hit_ApplyInArea(self, self, self->targetObj->unk_08, (u8)self->targetObj->unk_0a, 2, &data_ov003_021f6b44[self->unk_ce_s8], &r, 0x14cd, 0x3800, 100, 0x1000);
        }
        w = self->fsm;
        w->timer++;
        if (w->timer > self->dur) {
            self->unk_ce_s8 = -1;
            self->fsm->timer = 0;
            self->fsm->st = 1;
        }
        break;
    }
    }
}

void Ov003ActVt_021f9244_StateIdle(ActorEx *self) {
    switch (self->fsm->st) {
    case 0:
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        Model0218fe1c_SetAnim(self->model, data_ov003_021f6a88, 0x1000, 0);
        Model0218fe1c_SetAnimSpeed(self->model, self->unk_1a > 0 ? self->unk_1a : 0x1000);
        Model0218fe1c_SetLoop(self->model);
        self->model->boxTest = 0;
        self->fsm->st++;
    case 1: {
        s32 k = self->model->anim_state;
        if (!(k != 1 && k != 2)) {
            SndMgr_PlayAt(data_02097e4c, 0x65, &self->pos, 0);
        }
        func_ov003_021e7ee4(self);
        break;
    }
    }
}
}
}  // namespace m_021e7780

// ---- merged from ov003_021e8030.cpp
namespace m_021e8030 {

extern "C" {

extern void *data_ov000_021ccd64;
extern const VecFx32 data_ov003_021f6afc;
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);
extern BOOL Model0218fe1c_SetRes(Model0218fe1c *anim, void *res, s32 a, s32 b);
extern BOOL History_SetState(ActorSub40 *p, s32 a, s32 b);
extern void Obj02190758_SetRot(Model0218fe1c *anim, Rot16 *rot, s32 a);
extern void func_01ffc9fc(VecFx32 *dst, const VecFx32 *src, u16 angle);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern BOOL Model021903b4_Draw(Model0218fe1c *anim);
extern Robo021ca458 *ActorMgr_FindPlayer(void);
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *p, const char *name, s32 a, s32 b);
extern void Model0218fe1c_SetLoop(Model0218fe1c *p);
extern s32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);
extern void Field_ShakeCamera(s32 a, s32 b);
BOOL Ov003ActExMdl_DoAttack(Ov003ActExMdl *self);

extern s32 **Model0218fe1c_GetAnimCtrl(Model0218fe1c *model, s32 a);

static inline BOOL Ov003Game54_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov003Game54_IsIdle(FieldState *g) {
    if (Ov003Game54_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_Game54Idle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game54_IsIdle(g);
    }
    return TRUE;
}

BOOL func_ov003_021e7ee4(ActorEx *self) {
    Rot16 rot;
    VecFx32 v;
    s32 d;
    s32 t;
    s32 *p;
    if (ActorMgr_FindPlayer()->hp[0] != 0 && Ov003_Game54Idle()) {
        rot = self->rot;
        rot.x += 0x4000;
        d = 0;
        p = *Model0218fe1c_GetAnimCtrl(self->model, 0);
        if (p != NULL) {
            d = *p;
        }
        if (d > 0x32000) {
            d = 0x64000 - d;
        }
        t = d - 0x19000;
        v.x = (t >> 1) - (t >> 3) + 0x1800;
        v.y = 0x3333;
        v.z = -0x667;
        return Hit_ApplyInArea(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, 2, &v, &rot, 0x3333 - 0x1000, 0x4000 - 0x3333, 100, 0x1000);
    }
    return FALSE;
}

void Ov003ActVt_021f953c_Init(Ov003ActExMdl *self) {
    Ov003Unit *u;
    ActorEx_Init(self);
    u = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_0 = 0;
    }
}

void Ov003ActVt_021f953c_Start(Ov003ActExMdl *self) {
    s16 m;
    ActorEx_Start(self);
    Model0218fe1c_SetRes(&self->mdl, self->unk_34, 1, 0);
    self->mdl.scale.x = 0x1000;
    self->mdl.visible = 0;
    self->count = self->unk_18;
    self->mdl.scale.y = 0x1000;
    self->mdl.scale.z = 0;
    if (self->count == 0) {
        self->count = 1;
    } else if (self->count > 3) {
        self->count = 3;
    }
    m = self->unk_1a;
    if (m > 4) {
        m = 4;
    }
    self->turnSpeed = data_ov003_021f6a9e[m];
    self->turnAngle = 0;
    self->turnStep = 0x10000 / self->count;
    self->unk_cc_2 = 1;
    History_SetState(self->fsm, 1, 0);
}

BOOL Ov003ActVt_021f953c_Draw(Ov003ActExMdl *self) {
    BOOL r = ActorEx_Draw(self);
    if (r) {
        Rot16 rot;
        VecFx32 v;
        u8 i;
        rot.x = self->rot.x;
        rot.y = self->rot.y;
        rot.z = self->rot.z;
        rot.y += self->turnAngle;
        for (i = 0; i < self->count; i++) {
            Obj02190758_SetRot(&self->mdl, &rot, 0);
            func_01ffc9fc(&v, &data_ov003_021f6afc, rot.y);
            VEC_Add(&self->pos, &v, &v);
            self->mdl.trans.x = v.x;
            self->mdl.trans.y = v.y;
            self->mdl.trans.z = v.z;
            Model021903b4_Draw(&self->mdl);
            rot.y += self->turnStep;
        }
    }
    return r;
}

void Ov003ActExMdl_StateIdle(Ov003ActExMdl *self) {
    Robo021ca458 *pl = ActorMgr_FindPlayer();
    ActorSub40 *w = self->fsm;
    switch (w->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov003_021f6a88, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
    case 1: {
        VecFx32 p;
        p.x = pl->pos.x;
        p.y = pl->pos.y;
        p.z = pl->pos.z;
        p.y = self->pos.y;
        if (VEC_Distance(&self->pos, &p) >= 0x5800) {
            return;
        }
        SndMgr_PlayAt(data_02097e4c, 0x71, &self->pos, 0);
        self->mdl.visible = 1;
        self->fsm->st++;
        break;
    }
    case 2: {
        s32 s = self->mdl.scale.z;
        if (s >= 0x1000) {
            return;
        }
        s += 0x11f;
        if (s >= 0x1000) {
            s = 0x1000;
            Field_ShakeCamera(4, 4);
            SndMgr_PlayAt(data_02097e4c, 0x66, &self->pos, 0);
            self->fsm->st++;
        }
        self->mdl.scale.x = s;
        self->mdl.scale.y = s;
        self->mdl.scale.z = s;
        break;
    }
    case 3:
        self->turnAngle += self->turnSpeed;
        Ov003ActExMdl_DoAttack(self);
        break;
    }
}

void Ov003ActExMdl_StateFly(Ov003ActExMdl *self) {
    ActorEx_StateFly(self);
    if (!(self->hit->unk_50 & 0x60000000)) {
        return;
    }
    History_SetState(self->fsm, 0x15, 0);
}

}
}  // namespace m_021e8030

extern "C" {
extern Robo021ca458 *ActorMgr_FindPlayer(void);

static inline BOOL Ov003Game54_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov003Game54_IsIdle(FieldState *g) {
    if (Ov003Game54_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_Game54Idle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game54_IsIdle(g);
    }
    return TRUE;
}

BOOL Ov003ActExMdl_DoAttack(Ov003ActExMdl *self) {
    BOOL r = FALSE;
    if (ActorMgr_FindPlayer()->hp[0] != 0 && Ov003_Game54Idle()) {
        VecFx32 v;
        Rot16 rot;
        u8 i;
        v = data_ov003_021f6ae4;
        v.y = 0x1666;
        rot = self->rot;
        rot.x += 0x4000;
        rot.y += self->turnAngle;
        for (i = 0; i < self->count; i++) {
            r = Hit_ApplyInArea(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, 2, &v, &rot, 0x400, 0x3000, 100, 0x1000);
            if (r) {
                return r;
            }
            rot.y += self->turnStep;
        }
    }
    return r;
}
}

// ---- from ov003_021e8544.cpp
namespace m_021e8544 {

extern "C" {

extern void *data_ov000_021ccd64;
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);
extern BOOL History_SetState(ActorSub40 *p, s32 a, s32 b);
extern void func_01ffc9fc(VecFx32 *dst, const VecFx32 *src, u16 angle);
extern Robo021ca458 *ActorMgr_FindPlayer(void);

void Ov003ActVt_021f9374_Start(Ov003Swing *self) {
    Ov003Unit *u;
    s16 m;
    ActorEx_Start(self);
    u = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_5 = 1;
        u->unk_a2_6 = 0;
    }
    self->baseAngle = self->rot.y;
    switch (self->unk_18) {
    case 0:
        self->unk_ce_s8 = -1;
        break;
    case 1:
        self->unk_ce_s8 = 1;
        break;
    }
    m = self->unk_1a;
    if (m > 3) {
        m = 3;
    }
    self->turnSpeed = data_ov003_021f6a96[m];
    self->swingRange = self->unk_1c * 0xb6;
    self->unk_84.x = self->pos.x;
    self->unk_84.y = self->pos.y;
    self->unk_84.z = self->pos.z;
    switch (self->kind) {
    case 0x4076:
        self->fxBase.x = 0;
        self->fxBase.y = 0x12e1;
        self->fxBase.z = 0xb33;
        self->fxScale.x = 0x1800;
        self->fxScale.y = 0x1800;
        self->fxScale.z = 0x1800;
        break;
    case 0x4086:
        self->fxBase.x = 0;
        self->fxBase.y = 0x4cd;
        self->fxBase.z = 0x800;
        self->fxScale.x = 0x2000;
        self->fxScale.y = 0x1000;
        self->fxScale.z = 0x2000;
        self->hit->offset.y = -0x19a;
        break;
    }
    self->frames = 0;
    History_SetState(self->fsm, 1, 0);
}

void Ov003ActVt_021f9374_Update(Ov003Swing *self) {
    ActorEx_Update(self);
    if (self->fsm->current != 1 && self->unk_bc != NULL) {
        EffectMgr_Kill(data_0214a420, self->unk_bc);
        self->unk_bc = NULL;
    }
}

static inline BOOL Ov003Game54_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov003Game54_IsIdle(FieldState *g) {
    if (Ov003Game54_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_Game54Idle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game54_IsIdle(g);
    }
    return TRUE;
}

static inline s32 Ov003_FxMulL(s32 a, s64 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

void Ov003ActVt_021f9374_StateIdle(Ov003Swing *self) {
    switch (self->fsm->st) {
    case 0: {
        EffectObj *fx = Effect_SpawnId(0x25a, &self->pos);
        fx->SetRot(&self->rot);
        func_01ffc9fc(&self->fxOffset, &self->fxBase, self->rot.y);
        fx->AddPos(&self->fxOffset);
        fx->SetScale(&self->fxScale);
        self->unk_bc = fx->id;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
    }
    case 1: {
        EffectObj *fx;
        if (!Ov003_Game54Idle()) {
            return;
        }
        self->pos.x = self->unk_84.x;
        self->pos.y = self->unk_84.y;
        self->pos.z = self->unk_84.z;
        self->rot.y = self->rot.y + self->turnSpeed * self->unk_ce_s8;
        if (self->swingRange != 0) {
            u16 d = self->rot.y - self->baseAngle;
            if (d >= (self->swingRange >> 1) && d <= 0xffff - (self->swingRange >> 1)) {
                self->unk_ce_s8 = -self->unk_ce_s8;
            }
        }
        if (self->kind == 0x4086) {
            self->frames++;
            if (self->frames < 0x5a) {
                self->fxScale.x = 0x2000;
                self->fxScale.y = 0x1000;
                self->fxScale.z = 0x2000;
            } else if (self->frames < 0xfa) {
                self->fxScale.x = 0xe66;
                self->fxScale.y = 0xe66;
                self->fxScale.z = 0xe66;
            } else if (self->frames < 0x118) {
                self->fxScale.x = 0x8cd;
                self->fxScale.y = 0x8cd;
                self->fxScale.z = 0x8cd;
            } else {
                SndMgr_PlayAtPitch(data_02097e4c, 0x35, &self->pos, -0xc);
                self->frames = 0;
            }
        }
        fx = Effect_Find_020657b0(data_0214a420, self->unk_bc);
        if (fx != NULL) {
            fx->SetRot(&self->rot);
            fx->SetScale(&self->fxScale);
            func_01ffc9fc(&self->fxOffset, &self->fxBase, self->rot.y);
        }
        if (ActorMgr_FindPlayer()->hp[0] == 0) {
            return;
        }
        if (!Ov003_Game54Idle()) {
            return;
        }
        {
            Rot16 r;
            r.x = self->rot.x;
            r.y = self->rot.y;
            r.z = self->rot.z;
            r.x += 0x4000;
            Hit_ApplyInArea(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, 2, &self->fxBase, &r, Ov003_FxMulL(self->fxScale.x, 0x19a), Ov003_FxMulL(self->fxScale.z, 0x3ccd), 600, 0x2800);
        }
        break;
    }
    }
}
}
}  // namespace m_021e8544

// ---- from ov003_021e8a70.cpp
namespace m_021e8a70 {

extern "C" {

extern void *data_ov000_021ccd64;
extern BOOL History_SetState(ActorSub40 *p, s32 a, s32 b);
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);
extern s32 Rand_UpTo(s32 max);

void Ov003ActVt_021f9374_StateFly(ActorEx *self) {
    ActorEx_StateFly(self);
    if (!(self->hit->unk_50 & 0x60000000)) {
        return;
    }
    History_SetState(self->fsm, 0x15, 0);
}

void Ov003ActVt_021f91ac_Start(Ov003Mover *self) {
    ActorEx_Start(self);
    switch (self->kind) {
    case 0x405c:
    case 0x407b: {
        Ov003Unit *u = Group_FindNode(data_ov000_021ccd64, self->unk_20);
        if (u != NULL) {
            u->unk_a2_5 = 1;
            u->unk_a2_0 = 0;
            u->unk_a2_6 = 0;
        }
        self->unk_ce_u = 0;
        self->wait = self->unk_18;
        if (self->unk_18 == 0) {
            self->wait = Rand_UpTo(10) + 0x32;
        }
        break;
    }
    case 0x407c:
    case 0x407d:
        self->unk_ce_u = 1;
        break;
    }
    History_SetState(self->fsm, 1, 0);
}

extern const VecFx32 data_ov003_021f6ad8;
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *p, const char *name, s32 a, s32 b);
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *p, s32 a);
extern void Model0218fe1c_SetLoop(Model0218fe1c *p);
extern Robo021ca458 *ActorMgr_FindPlayer(void);

static inline BOOL Ov003Game_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov003Game_IsIdle(FieldState *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}

static inline void Ov003_SetSqrtImm64(u64 param) {
    *(volatile u64 *)0x040002b8 = param;
}

static inline void Ov003_SetSqrt64(u64 param) {
    *(volatile u16 *)0x040002b0 = 1;
    Ov003_SetSqrtImm64(param);
}

static inline void Ov003_WaitSqrt(void) {
    while (*(volatile u16 *)0x040002b0 & 0x8000) {
    }
}

static inline u32 Ov003_GetSqrtResult32(void) {
    return *(volatile u32 *)0x040002b4;
}

static inline s32 Ov003_Dist2D(s64 sq) {
    Ov003_SetSqrt64((u64)(sq << 2));
    Ov003_WaitSqrt();
    return (s32)(Ov003_GetSqrtResult32() + 1) >> 1;
}

static inline s32 Ov003_DistXZ(const VecFx32 *a, const VecFx32 *b) {
    s32 dx = a->x - b->x;
    s32 dz = a->z - b->z;
    s64 sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    return Ov003_Dist2D(sq);
}

void Ov003ActVt_021f91ac_StateIdle(Ov003Mover *self) {
    ActorSub40 *w = self->fsm;
    switch (w->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov003_021f6a88, 0x1000, 0);
        if (self->unk_ce_u == 1) {
            Model0218fe1c_SetAnimSpeed(self->model, self->unk_18 > 0 ? self->unk_18 : 0x1000);
        }
        Model0218fe1c_SetLoop(self->model);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->timer = 0;
        self->fsm->st++;
    case 1:
        switch (self->unk_ce_u) {
        case 0:
            w = self->fsm;
            w->timer++;
            if (w->timer > self->wait) {
                self->fsm->st++;
            }
            break;
        case 1:
            if (self->model->anim_state == 1) {
                self->fsm->st++;
            }
            break;
        }
        break;
    case 2: {
        EffectObj *fx;
        FieldCam *t = &data_ov000_021ccd54->cam;
        if (t != NULL && Ov003_DistXZ(&t->base.at, &self->pos) > 0xa000) {
            self->fsm->timer = 0;
            self->fsm->st = 1;
            return;
        }
        fx = Effect_SpawnId(0x130, &self->pos);
        fx->AddPos(&data_ov003_021f6ad8);
        if (self->unk_ce_u == 0) {
            fx->SetScaleAll(0xc00);
        }
        self->unk_bc = fx->id;
        SndMgr_PlayAtPitch(data_02097e4c, 0x54, &self->pos, 3);
        self->fsm->timer = 0;
        self->fsm->st++;
        break;
    }
    case 3:
        w->timer++;
        if (w->timer > 10 && ActorMgr_FindPlayer()->hp[0] != 0 && Ov003_GameIdle()) {
            Hit_ApplyInArea(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, 2, &data_ov003_021f6ad8, NULL, self->unk_ce_u != 0 ? 0x3000 : 0x2400, 0x1800, 0x25f, 0x2800);
        }
        if (Effect_Find_020657b0(data_0214a420, self->unk_bc) == NULL) {
            self->unk_bc = NULL;
            self->fsm->timer = 0;
            self->fsm->st = 1;
        }
        break;
    }
}

}
}  // namespace m_021e8a70

// ---- from ov003_021e8eb0.cpp
namespace m_021e8eb0 {

extern "C" {

extern void *data_ov000_021ccd64;
extern BOOL History_SetState(ActorSub40 *p, s32 a, s32 b);
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);

void Ov003ActVt_021f9114_Start(Ov003Gate *self) {
    Ov003Unit *u = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    ActorSub44 *p;
    if (u != NULL) {
        u->unk_a2_0 = 0;
    }
    ActorEx_Start(self);
    if (self->unk_1a == 0) {
        self->unk_1a = 3;
    }
    p = self->unk_44;
    p->unk_22_0 = 0;
    p->unk_22_1 = 0;
    History_SetState(self->fsm, 6, 0);
}

extern void *data_ov000_021ccd68;
extern const VecFx32 data_ov003_021f6af0;
extern const VecFx32 data_ov003_021f6b08;
extern Robo021ca458 *ActorMgr_FindPlayer(void);
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *p, const char *name, s32 a, s32 b);
extern void Model0218fe1c_PauseAnim(Model0218fe1c *p);
extern void Model0218fe1c_ResumeAnim(Model0218fe1c *p);
extern void *Model0218fe1c_SetAnimFrame(Model0218fe1c *p, s32 a);
extern BOOL Model0218fe1c_SetRes(Model0218fe1c *anim, void *res, s32 a, s32 b);
extern s32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void *ActorMgr_FindKind(void *mgr, s32 a, s32 b);
extern s32 func_ov000_0219a7bc(Actor *self, s32 a, VecFx32 *pos, s32 r, s32 b, Actor **list);
extern Actor *Target_Get(ActorSub4c *p);
extern void Field_ShakeCamera(s32 a, s32 b);
extern void Actor_SendMsgU8(Actor *o, u16 id, s32 a);

static inline BOOL Ov003Game_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov003Game_IsIdle(FieldState *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}

static inline Actor *Ov003_FindActor(s32 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return (Actor *)ActorMgr_FindKind(data_ov000_021ccd68, 0x5000, id);
}

static inline Actor *Ov003GtObj_GetSub(Actor *o) {
    Actor *s = NULL;
    if (o->targetObj != NULL) {
        s = Target_Get(o->targetObj);
    }
    return s;
}

static inline s32 Ov003GtObj_GetKind(Actor *o) {
    return o->fsm != NULL ? o->fsm->current : 0;
}

static inline void Ov003Gate_Anim(Ov003Gate *self, s32 a) {
    Model0218fe1c *m = self->model;
    if (m->unk_c0 != a) {
        Model0218fe1c_SetRes(m, m->res, a, m->unk_c2_1 ? 1 : 0);
    }
}

void Ov003ActVt_021f9114_State06(Ov003Gate *self) {
    Robo021ca458 *pl = ActorMgr_FindPlayer();
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov003_021f6a80, 0x1000, 0);
        Model0218fe1c_PauseAnim(self->model);
        self->unk_ce = 0;
        self->flash = 0;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
    case 1: {
        VecFx32 p;
        p.x = pl->pos.x;
        p.y = pl->pos.y;
        p.z = pl->pos.z;
        if (VEC_Distance(&self->pos, &p) > 0x8000) {
            return;
        }
        Model0218fe1c_ResumeAnim(self->model);
        SndMgr_PlayAt(data_02097e4c, 0x46, &self->pos, 0);
        self->fsm->st++;
        break;
    }
    case 2: {
        VecFx32 v;
        Actor *list[0x20];
        s32 n;
        s32 i;
        pl = ActorMgr_FindPlayer();
        if (pl->hp[0] != 0 && Ov003_GameIdle()) {
            Rot16 r;
            s32 h = 0x1400;
            r.x = self->rot.x;
            r.y = self->rot.y;
            r.z = self->rot.z;
            r.x += 0x2d80;
            if (pl->unk_b22_6 == 4) {
                h += 0x800;
            }
            Hit_ApplyInArea(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, 2, &data_ov003_021f6b08, &r, 0x2000, h, 100, 0x1000);
        }
        if (Ov003_FindActor(0x504a) == NULL && Ov003_FindActor(0x504b) == NULL) {
            History_SetState(self->fsm, 0x15, 0);
            return;
        }
        VEC_Add(&data_ov003_021f6af0, &self->pos, &v);
        n = func_ov000_0219a7bc(self, 0x10, &v, 0x299a, 0, list);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                Actor *sub;
                if (list[i] == NULL) {
                    continue;
                }
                sub = Ov003GtObj_GetSub(list[i]);
                if (sub == NULL || self->unk_ce == list[i]->id) {
                    continue;
                }
                if (sub->kind != 0x1000) {
                    continue;
                }
                if (Ov003GtObj_GetKind(list[i]) != 0xb) {
                    continue;
                }
                if (ActorMgr_FindPlayer()->unk_b24_5 != 0) {
                    continue;
                }
                self->unk_ce = list[i]->id;
                Field_ShakeCamera(10, 10);
                SndMgr_PlayAt(data_02097e4c, 0x56, &self->pos, 0);
                s16 c = self->unk_18 + 1;
                self->unk_18 = c;
                if (self->unk_1a <= c) {
                    History_SetState(self->fsm, 0x15, 0);
                } else {
                    Ov003Gate_Anim(self, 1);
                    Model0218fe1c_SetAnim(self->model, data_ov003_021f6a80, 0, 1);
                    Model0218fe1c_SetAnimFrame(self->model, -1);
                    {
                        Model0218fe1c *m = self->model;
                        m->color = 0x14bf;
                        m->color2 = 0x739f;
                        m->blend = 0xb;
                        m->blendMax = 10;
                    }
                    self->flash = 10;
                }
                Actor_SendMsgU8(list[i], self->unk_ce, 0x15);
                break;
            }
        }
        if (self->flash == 0) {
            return;
        }
        if (self->flash == 1) {
            Ov003Gate_Anim(self, 0);
            Model0218fe1c_SetAnim(self->model, data_ov003_021f6a80, 0, 1);
            Model0218fe1c_SetAnimFrame(self->model, -1);
        }
        self->flash--;
        break;
    }
    }
}

}
}  // namespace m_021e8eb0

// ---- from ov003_021e93d8.cpp
namespace m_021e93d8 {

extern "C" {

extern void *data_ov000_021ccd64;
extern const VecFx32 data_ov003_021f6b20;
extern const Ov003FlyParam data_ov003_021f6b5c[];
extern const s16 FX_SinCosTable_[];
extern void func_01ffc9fc(VecFx32 *dst, const VecFx32 *src, u16 angle);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
extern u16 FX_Atan2(s32 y, s32 x);
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);
extern BOOL History_SetState(ActorSub40 *p, s32 a, s32 b);
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *p, const char *name, s32 a, s32 b);
extern void Model0218fe1c_SetLoop(Model0218fe1c *p);
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *p, s32 a);
extern s32 Rand_PlusMinus(s32 max);
extern void VEC_MultAdd(s32 scale, const VecFx32 *dir, const VecFx32 *base, VecFx32 *out);
extern s32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);
extern Robo021ca458 *ActorMgr_FindPlayer(void);

static inline BOOL Ov003Game_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov003Game_IsIdle(FieldState *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return true;
}

void Ov003ActVt_021f94a4_Init(Ov003Hover *self) {
    Ov003Unit *u;
    ActorEx_Init(self);
    u = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_5 = 1;
    }
}

void Ov003ActVt_021f94a4_Start(Ov003Hover *self) {
    ActorEx_Start(self);
    self->unk_84.x = self->pos.x;
    self->unk_84.z = self->pos.z;
    self->unk_84.y = self->pos.y + 0x800;
    History_SetState(self->fsm, 1, 0);
}

void Ov003ActVt_021f94a4_StateIdle(Ov003Hover *self) {
    VecFx32 pp;
    VecFx32 d;
    ActorSub40 *w;
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov003_021f6a88, 0x89, 0);
        Model0218fe1c_SetLoop(self->model);
        self->fsm->timer = 0;
        self->fsm->st++;
    case 1: {
        w = self->fsm;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer == 0) {
            self->fsm->timer = 0x3c;
            self->target.x = self->unk_84.x;
            self->target.y = self->unk_84.y;
            self->target.z = self->unk_84.z;
            self->target.x += Rand_PlusMinus(0x800);
            self->target.y += Rand_PlusMinus(0x800);
            self->target.z += Rand_PlusMinus(0x800);
        }
        d.x = self->target.x - self->pos.x;
        d.y = self->target.y - self->pos.y;
        d.z = self->target.z - self->pos.z;
        VEC_MultAdd(0x3d, &d, &self->pos, &self->pos);
        break;
    }
    }
    if (!Ov003_GameIdle()) {
        return;
    }
    {
        Robo021ca458 *pl = ActorMgr_FindPlayer();
        if (pl == NULL) {
            return;
        }
        pp.x = pl->pos.x;
        pp.y = pl->pos.y;
        pp.z = pl->pos.z;
        if (VEC_Distance(&self->pos, &pp) >= 0x6000) {
            return;
        }
    }
    History_SetState(self->fsm, 6, 0);
}

void Ov003ActVt_021f94a4_State06(Ov003Hover *self) {
    ActorSub40 *w = self->fsm;
    s32 top = self->unk_84.y;
    switch (w->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov003_021f6a8c, 0x400, 0);
        Model0218fe1c_SetLoop(self->model);
        self->velY = -0x8f;
        self->fsm->timer = 0;
        self->fsm->st++;
    case 1:
        if (self->pos.y < top - 0x3000) {
            Model0218fe1c_SetAnimSpeed(self->model, 0x99a);
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        if (ActorMgr_FindPlayer()->hp[0] != 0 && Ov003_GameIdle()) {
            ActorSub4c *l = self->targetObj;
            Hit_ApplyInArea(self, self, l->unk_08, l->unk_0a, 2, &data_ov003_021f6b20, NULL, 0x1c00, 0x800, 0x64, 0x1000);
        }
        break;
    case 2:
        w->timer++;
        if (w->timer <= 0xf) {
            self->velY -= self->velY >> 2;
            break;
        }
        Model0218fe1c_SetAnim(self->model, data_ov003_021f6a88, 0x89, 0);
        Model0218fe1c_SetLoop(self->model);
        self->velY = 0x3d;
        self->fsm->st++;
        break;
    case 3:
        if (self->pos.y >= top) {
            History_SetState(w, 1, 0);
        }
        break;
    }
    Actor_Move(self, 0);
}

void Ov003ActVt_021f940c_Init(Ov003Patrol *self) {
    Ov003Unit *u;
    ActorEx_Init(self);
    u = Group_FindNode(data_ov000_021ccd64, self->unk_20);
    if (u != NULL) {
        u->unk_a2_5 = 1;
    }
}

static inline void Ov003_RotX(VecFx32 *out, const VecFx32 *in, u16 ang) {
    s32 y = 0;
    s32 z = 0;
    s32 idx = ang >> 4;
    s32 s = FX_SinCosTable_[idx * 2];
    s32 c = FX_SinCosTable_[idx * 2 + 1];
    if (in->y != 0) {
        y += (s32)(((s64)c * in->y + 0x800) >> 12);
        z += (s32)(((s64)s * in->y + 0x800) >> 12);
    }
    if (in->z != 0) {
        y += (s32)(((s64)-s * in->z + 0x800) >> 12);
        z += (s32)(((s64)c * in->z + 0x800) >> 12);
    }
    out->x = in->x;
    out->y = y;
    out->z = z;
}

static inline void Ov003_SetSqrt64(u64 param) {
    *(volatile u16 *)0x040002b0 = 1;
    *(volatile u64 *)0x040002b8 = param;
}

static inline s32 Ov003_Dist2D(s64 sq) {
    Ov003_SetSqrt64((u64)(sq << 2));
    while (*(volatile u16 *)0x040002b0 & 0x8000) {
    }
    return (s32)(*(volatile u32 *)0x040002b4 + 1) >> 1;
}

void Ov003ActVt_021f940c_Start(Ov003Patrol *self) {
    const Ov003FlyParam *prm;
    s32 dx, dz;
    s64 sq;
    s32 dist;
    u16 ang;
    s32 idx;
    ActorEx_Start(self);
    self->unk_93 = 0;
    prm = &data_ov003_021f6b5c[(s16)self->unk_1a];
    self->baseYaw = self->rot_y;
    self->ends[0] = self->pos;
    VecFx32 v = {0, 0, 0};
    v.z = prm->dist;
    Ov003_RotX(&v, &v, self->rot_x);
    func_01ffc9fc(&v, &v, self->rot_y);
    VEC_Add(&v, &self->pos, &v);
    self->ends[1] = v;
    self->from = self->ends[0];
    self->unk_84 = self->ends[1];
    self->endIdx = 0;
    dx = self->pos.x - self->ends[1].x;
    dz = self->pos.z - self->ends[1].z;
    sq = (s64)dx * dx;
    sq += (s64)dz * dz;
    dist = Ov003_Dist2D(sq);
    ang = FX_Atan2(dist, self->ends[1].y - self->pos.y);
    idx = ang >> 4;
    {
    s32 spd = prm->speed;
    self->speed = (s32)(((s64)spd * FX_SinCosTable_[idx * 2] + 0x800) >> 12);
    self->velY = (s32)(((s64)spd * FX_SinCosTable_[idx * 2 + 1] + 0x800) >> 12);
    }
    self->moveYaw = self->rot_y;
    self->rot_x = data_ov003_021f6a90.x;
    self->rot_y = data_ov003_021f6a90.y;
    self->rot_z = data_ov003_021f6a90.z;
    self->rot_x = Group_FindNode(data_ov000_021ccd64, self->unk_20)->unk_94;
    History_SetState(self->fsm, 6, 0);
}

}
}  // namespace m_021e93d8

// ---- from ov003_021e9af4.c
namespace m_021e9af4 {
extern "C" {

extern void Ov003_BuildRotMtx(Actor *self, MtxFx33 *m, Rot16 *rot, s32 ang);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);

BOOL Ov003ActVt_021f940c_Draw(Ov003Patrol *self) {
    MtxFx33 m;
    VecFx32 v;
    Model0218fe1c *model;
    self->unk_93_0 = 1;
    Ov003_BuildRotMtx(self, &m, &self->rot, self->baseYaw);
    MI_Copy36B(&m, &self->model->rot);
    VEC_Add(&self->mdlOfs, &self->pos, &v);
    model = self->model;
    model->trans.x = v.x;
    model->trans.y = v.y;
    model->trans.z = v.z;
    return ActorEx_Draw(self);
}

}
}  // namespace m_021e9af4

// ---- from ov003_021e9b74.cpp
namespace m_021e9b74 {

extern "C" {

extern const Ov003FlyParam data_ov003_021f6b5c[];
extern const VecFx32 data_ov003_021f6acc;
extern const s16 FX_SinCosTable_[];
extern void func_01ffc9fc(VecFx32 *dst, const VecFx32 *src, u16 angle);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *p, const char *name, s32 a, s32 b);
extern void Model0218fe1c_SetLoop(Model0218fe1c *p);
extern s32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);
extern Robo021ca458 *ActorMgr_FindPlayer(void);

static inline BOOL Ov003Game_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov003Game_IsIdle(FieldState *g) {
    if (Ov003Game_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003_GameIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return true;
}

static inline void Ov003_RotX(VecFx32 *out, const VecFx32 *in, u16 ang) {
    s32 y = 0;
    s32 z = 0;
    s32 idx = ang >> 4;
    s32 s = FX_SinCosTable_[idx * 2];
    s32 c = FX_SinCosTable_[idx * 2 + 1];
    if (in->y != 0) {
        y += (s32)(((s64)c * in->y + 0x800) >> 12);
        z += (s32)(((s64)s * in->y + 0x800) >> 12);
    }
    if (in->z != 0) {
        y += (s32)(((s64)-s * in->z + 0x800) >> 12);
        z += (s32)(((s64)c * in->z + 0x800) >> 12);
    }
    out->x = in->x;
    out->y = y;
    out->z = z;
}

static inline void Ov003_RotZ(VecFx32 *out, const VecFx32 *in, u16 ang) {
    s32 x = 0;
    s32 y = 0;
    s32 idx = ang >> 4;
    s32 s = FX_SinCosTable_[idx * 2];
    s32 c = FX_SinCosTable_[idx * 2 + 1];
    if (in->y != 0) {
        y += (s32)(((s64)c * in->y + 0x800) >> 12);
        x += (s32)(((s64)-s * in->y + 0x800) >> 12);
    }
    if (in->x != 0) {
        y += (s32)(((s64)s * in->x + 0x800) >> 12);
        x += (s32)(((s64)c * in->x + 0x800) >> 12);
    }
    out->x = x;
    out->y = y;
    out->z = in->z;
}

static inline void Ov003_RotZ2(VecFx32 *out, const VecFx32 *in, u16 ang) {
    s32 y = 0;
    s32 x = 0;
    s32 idx = ang >> 4;
    s32 s = FX_SinCosTable_[idx * 2];
    s32 c = FX_SinCosTable_[idx * 2 + 1];
    if (in->y != 0) {
        y += (s32)(((s64)c * in->y + 0x800) >> 12);
        x += (s32)(((s64)-s * in->y + 0x800) >> 12);
    }
    if (in->x != 0) {
        y += (s32)(((s64)s * in->x + 0x800) >> 12);
        x += (s32)(((s64)c * in->x + 0x800) >> 12);
    }
    out->x = x;
    out->y = y;
    out->z = in->z;
}

void Ov003ActVt_021f940c_State06(Ov003Patrol *self) {
    const Ov003FlyParam *prm = &data_ov003_021f6b5c[self->unk_1a];
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov003_021f6a84, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        self->fsm->timer = 0;
        self->fsm->st++;
    case 1:
        self->rot_z += prm->unk_0c;
        Actor_Move(self, 0);
        if (VEC_Distance(&self->pos, &self->from) >= prm->dist) {
            self->from = self->unk_84;
            self->unk_84 = self->ends[self->endIdx];
            self->speed = -self->speed;
            self->velY = -self->velY;
            Model0218fe1c_SetAnim(self->model, data_ov003_021f6a88, 0x400, 0);
            Model0218fe1c_SetLoop(self->model);
            self->fsm->st++;
        }
        break;
    case 2: {
        VecFx32 d;
        ActorSub40 *w;
        d.x = self->unk_84.x - self->from.x;
        d.y = self->unk_84.y - self->from.y;
        d.z = self->unk_84.z - self->from.z;
        func_01ffc9fc(&d, &d, -self->baseYaw);
        VEC_Add(&d, &self->from, &d);
        Actor_TurnToPos(self, &d, 0x200);
        w = self->fsm;
        w->timer++;
        if (w->timer == 100) {
            self->endIdx = self->endIdx ? 0 : 1;
            self->fsm->st = 0;
        }
        break;
    }
    }
    VecFx32 v = {0, 0, 0};
    v.y = prm->unk_08;
    Ov003_RotZ(&v, &v, self->rot_z);
    Ov003_RotX(&v, &v, self->rot_x);
    func_01ffc9fc(&self->mdlOfs, &v, self->baseYaw);
    if (ActorMgr_FindPlayer()->hp[0] != 0 && Ov003_GameIdle()) {
        VecFx32 save = self->pos;
        VecFx32 o = data_ov003_021f6acc;
        ActorSub4c *l;
        Ov003_RotZ2(&o, &o, self->rot_z);
        Ov003_RotX(&o, &o, self->rot_x);
        func_01ffc9fc(&o, &o, self->baseYaw);
        VEC_Add(&o, &self->mdlOfs, &o);
        VEC_Add(&self->pos, &o, &self->pos);
        l = self->targetObj;
        Hit_ApplyInArea(self, self, l->unk_08, l->unk_0a, 2, NULL, NULL, (s32)(((s64)self->model->scale.x * self->radius + 0x800) >> 12), 0, 100, 0x1000);
        self->pos = save;
    }
    if (!Ov003_GameIdle()) {
        return;
    }
    if (self->model->anim_state != 1) {
        return;
    }
    SndMgr_PlayAtPitch(data_02097e4c, 0x48, &self->pos, -0xf);
}

}
}  // namespace m_021e9b74

// ---- from ov003_021ea3d0.c
namespace m_021ea3d0 {
extern "C" {

extern BOOL History_SetState(ActorSub40 *p, s32 a, s32 b);

void Ov003_BuildRotMtx(Actor *self, MtxFx33 *m, Rot16 *rot, s32 ang) {
    MtxFx33 t;
    BOOL set = FALSE;
    MTX_Identity33_(m);
    if (ang != 0) {
        MTX_RotY33_(m, FX_SinIdx(ang), FX_CosIdx(ang));
        set = TRUE;
    }
    if (rot->x != 0) {
        if (set) {
            MTX_RotX33_(&t, FX_SinIdx(rot->x), FX_CosIdx(rot->x));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotX33_(m, FX_SinIdx(rot->x), FX_CosIdx(rot->x));
            set = TRUE;
        }
    }
    if (rot->z != 0) {
        if (set) {
            MTX_RotZ33_(&t, FX_SinIdx(rot->z), FX_CosIdx(rot->z));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotZ33_(m, FX_SinIdx(rot->z), FX_CosIdx(rot->z));
            set = TRUE;
        }
    }
    if (rot->y != 0) {
        if (set) {
            MTX_RotY33_(&t, FX_SinIdx(rot->y), FX_CosIdx(rot->y));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotY33_(m, FX_SinIdx(rot->y), FX_CosIdx(rot->y));
            set = TRUE;
        }
    }
}

BOOL Ov003ActVt_021f92dc_Draw(ActorEx *self) {
    BOOL r = ActorEx_Draw(self);
    if (self->unk_18 == 1 && r == FALSE) {
        History_SetState(self->fsm, 0x15, 0);
    }
    return r;
}

typedef struct {
    VecFx32 pos;
    u16 angle;
    u8 unk_0e[2];
} Ov003EaSpot;

extern const Ov003EaSpot data_ov003_021f6b8c[];
extern void HitSphere_Unlink_0203f364(ActorSub48 *hit);
extern u16 Camera_GetYaw(Camera *cam);
extern s32 Rand_PlusMinus(s32 n);

static inline s32 Ov003Ea_FxMul(s32 a, s32 b) {
    return (s32)(((s64)a * b + 0x800) >> 12);
}

static inline u16 Camera_Angle(Camera *cam) {
    if (cam->mode != 0) {
        return cam->yaw;
    }
    return Camera_GetYaw(cam);
}

void Ov003ActVt_021f92dc_Start(ActorEx *self) {
    ActorSub48 *hit;
    ActorEx_Start(self);
    hit = self->hit;
    hit->unk_9a_0 = 0;
    hit->unk_9a_3 = 0;
    HitSphere_Unlink_0203f364(hit);
    self->hit->unk_30 = 0;
    if (self->unk_1a == 0) {
        Camera *cam = &data_ov000_021ccd54->cam.base;
        u16 a = Camera_Angle(cam);
        a = a + (u16)(Rand_PlusMinus(3) * 0xb6);
        self->pos.x = cam->at.x;
        self->pos.y = cam->at.y;
        self->pos.z = cam->at.z;
        self->pos.x += Ov003Ea_FxMul(FX_SinCosTable_[(a >> 4) * 2], 0x14000);
        self->pos.z += Ov003Ea_FxMul(FX_SinCosTable_[(a >> 4) * 2 + 1], 0x14000);
        self->pos.y += 0x4000;
    } else {
        const Ov003EaSpot *sp = &data_ov003_021f6b8c[self->unk_1a - 1];
        self->pos.x = sp->pos.x;
        self->pos.y = sp->pos.y;
        self->pos.z = sp->pos.z;
        self->rot_y += (u16)(sp->angle * 0xb6);
    }
    self->moveYaw = self->rot_y;
    History_SetState(self->fsm, 6, 0);
}

}
}  // namespace m_021ea3d0

// ---- Ov003ActVt_021f92dc_State06
namespace m_021ea588 {
extern "C" {

extern s32 Geom_SnapToGround(VecFx32 *v, s32 y, s32 d);
extern void Field_ShakeCamera(s32 a, s32 b);

static inline s32 Ov003Eb_FxMul(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

static inline BOOL Ov003Eb_GameIdle(void) {
    FieldState *g = data_ov000_021ccd54;
    if (g != NULL) {
        BOOL busy = FALSE;
        if (g->head != g->tail) {
            busy = TRUE;
        }
        if (busy) {
            return FALSE;
        }
        if (g->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline void VecCopy_a588(const VecFx32 *src, VecFx32 *dst) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}

void Ov003ActVt_021f92dc_State06(ActorEx *self) {
    s32 y;
    ActorSub40 *w = self->fsm;
    if (w->st == 0) {
        self->speed = 0x333;
        self->velY = 0xcd - 0x333;
        self->unk_ce_s = 0xaab;
        w->timer = 0;
        self->fsm->st++;
    }
    Actor_Move(self, 0);
    self->rot.x += self->unk_ce_s;
    if (ActorMgr_FindPlayer()->hp[0] != 0 && Ov003Eb_GameIdle()) {
        VecFx32 v;
        Rot16 rot;
        s32 a;
        s32 b;
        a = Ov003Eb_FxMul(self->model->scale.y, 0xccd);
        b = Ov003Eb_FxMul(self->model->scale.x, 0x24cd);
        v.x = data_ov003_021f6ae4.x;
        v.y = data_ov003_021f6ae4.y;
        v.z = data_ov003_021f6ae4.z;
        v.x = b >> 1;
        rot = self->rot;
        rot.z += 0x4000;
        Hit_ApplyInArea(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, 2, &v, &rot, a, b, 100, 0x1000);
    }
    self->unk_ce_s -= 0x2d;
    if (self->unk_ce_s < 0x38e) {
        self->unk_ce_s = 0x38e;
    }
    VecCopy_a588(&self->pos, &self->unk_84);
    if (Geom_SnapToGround(&self->unk_84, self->pos.y, -0xa000) == -0x1000) {
        return;
    }
    y = self->unk_84.y + Ov003Eb_FxMul(self->model->scale.y, 0xccd);
    self->unk_84.y = y;
    if (self->pos.y >= y) {
        return;
    }
    self->pos.y = y;
    self->speed = 0x400;
    self->velY = 0x19a;
    self->gravity = 0x14;
    self->unk_ce_s = 0xaab;
    Field_ShakeCamera(5, 5);
    SndMgr_PlayAt(data_02097e4c, 0x7e, &self->pos, 0);
    if (self->unk_18 == 0) {
        self->unk_18 = 1;
    }
}
}
}  // namespace m_021ea588
