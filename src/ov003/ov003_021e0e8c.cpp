#pragma pool_strings on
#pragma dont_reuse_strings off
#include "types.h"
#include "ov003/ActorApi.h"
#include "Main/Math/Rot16.h"
#include "Main/Snd/SndMgr.h"
#include "Main/Effect/Effect.h"
#include "nnsys/g3d.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ActorParts.h"
#include "ov003/Unit.h"
#include "nitro/std.h"
#include "Main/Sys/SysState.h"
#include "ov000/ObjLayouts.h"
#include "ov003/ActEx.h"
#include "ov000/Group.h"
#include "ov000/TwlRequest.h"

// The spawn point (vtable 021f8a60, 0x20c bytes: Factory_New4000, kinds 0x4009 and 0x4058).
// Ov003ActVt_021f8a60_State0e spawns actor 0x4801 at pos and keeps its id.
class Ov003SpawnPt : public Ov003ActExRes {
public:
    u16 spawnId; // id of the spawned actor, 0xffff: none
};
SIZE_ASSERT(Ov003SpawnPt, 0x20c);

// One step of a spawner's table: up to eight actors (ids, with delays[i] frames before ids[i] and
// args[i] passed in the spawn info), then the step to go to (next; -1 and -2 end the spawner).
typedef struct Ov003SpawnStep {
    u8 group; // ActorMgr_GetGroup(group << 12) counts the actors alive, when not 0
    u8 max; // at most this many alive (0: no limit)
    u8 mode; // 1: wait until the actors spawned are gone; 3: start again from state 0
    s8 next;
    u16 wait; // frames before the next step
    u16 delays[8];
    u16 ids[8]; // 0xffff ends the list
    s16 args[8];
} Ov003SpawnStep;

// A spawner's table (data_ov003_021f5fac[Actor::unk_1a]): it starts when the player is in the box
// [min, max] around pos and spawns at pos + ofs.
typedef struct Ov003SpawnTable {
    VecFx32 min;
    VecFx32 max;
    VecFx32 ofs;
    Ov003SpawnStep *steps;
} Ov003SpawnTable;

// The spawner (vtable 021f8638, 0x218 bytes: Factory_New4000); Actor::unk_18 is the step.
class Ov003Spawner : public Ov003ActExRes {
public:
    Ov003SpawnTable *table;
    u16 slot; // index in the step's ids
    u16 spawned[5]; // ids of the actors spawned, 0xffff: free
};
SIZE_ASSERT(Ov003Spawner, 0x218);

// Vtable 021f8768 (0x214 bytes: Factory_New4000). When Actor::unk_1c is not 0, Init names
// the texture resource (res entry 4) after the kind and, on TWL, loads a second texture into tex
// (Twl0214b570_Init); Start binds the texture to the model.
class Ov003ActExTex : public Ov003ActExRes {
public:
    Twl0214b570 *tex; // freed by the dtor
    u8 texFailed; // set when the loader reports state 2; Ov003ActVt_021f8768_StateIdle then opens msgWin
    Lo021cad50 *msgWin;
};
SIZE_ASSERT(Ov003ActExTex, 0x214);

// Takes the current animation off the model and clears its controller.
static inline void Model_StopAnim(Model0218fe1c *m) {
    AnimCtrl *a = m->unk_10;
    if (a != NULL) {
        NNS_G3dRenderObjRemoveAnmObj((NNSG3dRenderObj *)m->renderObj, (NNSG3dAnmObj *)a->cur);
        a->name[0] = 0;
        a->index = 0xff;
        a->playing = 0;
        a->same = 0;
    }
}

static inline void Model_SetScale(Model0218fe1c *m, s32 s) {
    m->scale.x = s;
    m->scale.y = s;
    m->scale.z = s;
}

static inline void Model_SetScale3(Model0218fe1c *m, s32 x, s32 y, s32 z) {
    m->scale.x = x;
    m->scale.y = y;
    m->scale.z = z;
}

// Vtable 021f8f20 (0xd4 bytes: Factory_New4000, kinds 0x4082 and 0x4090): it follows a
// path (ov003_021e0e8c.cpp, m_021e694c) and, in Ov003ActVt_021f8f20_StateHeld, counts frames until it
// goes (0x78).
class Ov003ActExPath : public ActorEx {
public:
    u16 frames;
};
SIZE_ASSERT(Ov003ActExPath, 0xd4);

// ---- merged from ov003_021e0e8c.c
namespace m_021e0e8c {
extern "C" {

// Records of data_ov003_021f62f0 (0x34 bytes; passed to func_ov000_0219b808).
typedef struct {
    u8 unk_00[0x34];
} Ov003Table34;

extern void *gGroup;
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);
extern Actor *Target_Get(ActorSub4c *p);
extern Actor *Actor_SpawnKind(s32 id, VecFx32 *pos, ActorRot *rot, u16 a, u16 b);
extern BOOL Stage_UseScaledStats(void);
extern void func_ov000_0219bebc(Actor *p, s32 v);
extern BOOL History_SetState(ActorSub40 *p, s32 a, s32 b);
extern s32 Ov003CntSelf_CountLiving(ActorSub4c *p);
extern s32 StageRes_HasQueued(void);
extern Robo021ca458 *ActorMgr_FindPlayer(void);
extern Ov003Table34 data_ov003_021f62f0[];
extern Ov003SpawnTable *data_ov003_021f5fac[];
extern void func_ov000_0219b808(u16 id, VecFx32 *pos, Ov003Table34 *entry, s32 a, s32 b);
extern void func_ov000_02193e5c(ActorRes *res, s32 id);
extern void Ov003Res_SetNames(ActorRes *res, u16 id);

static inline BOOL Ov003Event_SetMode(ActorEx *self, s16 mode) {
    if (self->unk_18 != mode) {
        self->unk_18 = mode;
        return TRUE;
    }
    return FALSE;
}

extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *p, const char *name, s32 a, s32 b);
extern BOOL ResSet_UpdateLoad(ActorRes *p);

BOOL Ov003ActVt_021f8a60_IsReady(Ov003SpawnPt *self) {
    BOOL r = ActorEx_IsReady(self);
    if (self->res.unk_00 >= 0) {
        if (!ResSet_UpdateLoad(&self->res)) {
            r = FALSE;
        }
    }
    return r;
}

void Ov003ActVt_021f8a60_State0e(Ov003SpawnPt *self) {
    Actor *p;
    ActorSub4c *part;
    u16 a = 0xffff;
    u16 b;
    u16 v;
    self->spawnId = a;
    p = Target_Get(self->targetObj);
    b = a;
    if (p != NULL) {
        a = p->id;
        b = p->target;
    }
    p = Actor_SpawnKind(0x4801, &self->pos, &self->rot, a, b);
    if (p != NULL) {
        s16 type = 2;
        if (self->kind == 0x4058) {
            type = 3;
        }
        p->unk_18 = type;
        self->spawnId = p->id;
        if (Stage_UseScaledStats() && (self->targetObj->target >> 12) == 5) {
            func_ov000_0219bebc(p, 0x1800);
        }
    }
    part = self->targetObj;
    if (part->unk_1e <= 1) {
        part->unk_01 = 1;
        v = 0;
    } else {
        v = part->unk_1e - 1;
    }
    self->targetObj->unk_1e = v;
    History_SetState(self->fsm, 9, 0);
}

void Ov003ActVt_021f8a60_StateThrown(Ov003SpawnPt *self) {
    if (self->fsm->st == 0) {
        if (self->kind == 0x4058) {
            if (self->target != 0xffff) {
                self->hit->unk_30 = 0;
            }
        }
        self->targetObj->unk_01 = 1;
    }
    ActorEx_StateThrown(self);
}

void Ov003ActVt_021f9050_Init(ActorEx *self) {
    Ov003Unit *unit;
    ActorEx_Init(self);
    unit = Group_FindNode(gGroup, self->unk_20);
    if (unit != NULL) {
        unit->unk_a2_0 = 0;
    }
}

void Ov003ActVt_021f9050_Start(ActorEx *self) {
    ActorEx_Start(self);
    Obj02197d80_LoadValue(self);
    if (self->unk_1a == 0) {
        self->unk_18 = 2;
        return;
    }
    switch (self->unk_18) {
    case 2:
        if (self->model != NULL) {
            Model0218fe1c_SetAnim(self->model, "op02", 0x1000, 0);
        }
        break;
    case 0:
    case 1:
    case 3:
        if (self->model != NULL) {
            Model0218fe1c_SetAnim(self->model, "op00", 0x1000, 0);
        }
        break;
    }
}

void Ov003ActVt_021f9050_Update(ActorEx *self) {
    BOOL changed = FALSE;
    Robo021ca458 *player;
    switch (self->unk_1a) {
    case 3:
        switch (Ov003CntSelf_CountLiving(self->targetObj)) {
        case 3:
        case 4:
            changed = Ov003Event_SetMode(self, 2);
            break;
        case 1:
        case 2:
            changed = Ov003Event_SetMode(self, 0);
            break;
        }
        break;
    case 5:
        switch (Ov003CntSelf_CountLiving(self->targetObj)) {
        case 3:
        case 4:
            changed = Ov003Event_SetMode(self, 0);
            break;
        case 1:
        case 2:
            changed = Ov003Event_SetMode(self, 2);
            break;
        }
        break;
    }
    if (!changed) {
        return;
    }
    func_ov000_02197dec(self, self->unk_18, self->unk_18);
    if (StageRes_HasQueued() != 1) {
        return;
    }
    player = ActorMgr_FindPlayer();
    if (player == NULL) {
        return;
    }
    if (player->unk_b28_0 != 0) {
        return;
    }
    player->mode = 3;
    player->unk_b28_0 = 0;
    player->unk_b28_2 = 1;
}

void Ov003ActVt_021f9050_StateIdle(ActorEx *self) {
    if (self->unk_18 == 0) {
        return;
    }
    func_ov000_0219b808(self->id, &self->pos, &data_ov003_021f62f0[self->unk_1c], 0, 0);
}

void Ov003ActVt_021f8638_Init(Ov003Spawner *self) {
    Ov003SpawnStep *e;
    Ov003Unit *unit;
    ActorEx_Init(self);
    self->table = data_ov003_021f5fac[(u16)self->unk_1a];
    e = &self->table->steps[self->unk_18];
    if (e->delays[0] == 0) {
        u16 id = e->ids[0];
        u16 kind = (u16)(id >> 12);
        if (kind == 4) {
            func_ov000_02193e5c(&self->res, id);
        } else if (kind == 5) {
            Ov003Res_SetNames(&self->res, id);
        }
    }
    unit = Group_FindNode(gGroup, self->unk_20);
    if (unit != NULL) {
        unit->unk_a2_0 = 0;
    }
    self->unk_cc_3 = 0;
    self->unk_cc_4 = 0;
}
}
}  // namespace m_021e0e8c

// ---- merged from ov003_021e12b0.cpp
namespace m_021e12b0 {

extern "C" {

// The group record ActorMgr_GetGroup returns: unk_16 is the number of its actors.
typedef struct {
    u8 unk_00[0x16];
    u16 unk_16;
} Ov003EvGroup;

typedef struct {
    u8 unk_00[0x34];
} Ov003Table34;

extern void *gGroup;
extern Robo021ca458 *ActorMgr_FindPlayer(void);

extern BOOL ResSet_UpdateLoad(ActorRes *p);

BOOL Ov003ActVt_021f8638_IsReady(Ov003Spawner *self) {
    BOOL r = ActorEx_IsReady(self);
    if (self->res.unk_00 >= 0) {
        if (!ResSet_UpdateLoad(&self->res)) {
            r = FALSE;
        }
    }
    return r;
}

void Ov003ActVt_021f8638_Start(Ov003Spawner *self) {
    int i;
    ActorEx_Start(self);
    self->slot = 0;
    for (i = 0; i < 5; i++) {
        self->spawned[i] = 0xffff;
    }
    self->fsm->timer = self->table->steps[self->unk_18].delays[0];
}

extern void *gActorMgr;
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern Ov003EvGroup *ActorMgr_GetGroup(void *mgr, u16 key);
extern BOOL Hit_DiffInBox(VecFx32 *a, VecFx32 *b, VecFx32 *min, VecFx32 *max);
extern Actor *Group_SpawnActor(void *mgr, GroupActorDesc *desc, VecFx32 *pos, ActorRot *rot, u16 a);
extern void Group_UpdateActor(void *mgr, s32 a, Actor *obj);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);

static inline Actor *Ov003Ev_GetUnit(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

static inline BOOL Ov003Ev_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov003Ev_IsIdle(FieldState *g) {
    if (Ov003Ev_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003Ev_GameIdle(void) {
    FieldState *g = gSceneCmd;
    if (g != NULL) {
        return Ov003Ev_IsIdle(g);
    }
    return TRUE;
}

static inline void Ov003Ev_CheckNext(Ov003Spawner *self, Ov003SpawnStep *e) {
    if (!self->unk_93_4 && e->next >= 0) {
        if ((self->table->steps[e->next].ids[0] >> 12) == 5 && self->unk_1e == 0) {
            self->unk_93_4 = 1;
        }
    }
}

void Ov003ActVt_021f8638_StateIdle(Ov003Spawner *self) {
    Ov003SpawnStep *e;
    u16 cnt;
    s32 i;
    s32 alive;
    if (self->unk_1c != 0) {
        return;
    }
    e = &self->table->steps[self->unk_18];
    self->unk_93_4 = 0;
    cnt = 0;
    for (i = 0; i < 5; i++) {
        if (self->spawned[i] != 0xffff) {
            Actor *u = Ov003Ev_GetUnit(self->spawned[i]);
            if (u != NULL) {
                u16 k;
                cnt++;
                k = u->id & 0xf000;
                if (k == 0x5000) {
                    if (Ov003Ev_GameIdle()) {
                        if (self->unk_1e == 0) {
                            self->unk_93_4 = 1;
                        }
                    }
                }
            } else {
                self->spawned[i] = 0xffff;
            }
        }
    }
    alive = cnt;
    if (e->group != 0) {
        Ov003EvGroup *g = ActorMgr_GetGroup(gActorMgr, (u16)(e->group << 12));
        if (g != NULL) {
            alive = g->unk_16;
        }
    }
    switch (self->fsm->st) {
    case 0: {
        Robo021ca458 *pl = ActorMgr_FindPlayer();
        if (!Hit_DiffInBox(&pl->pos, &self->pos, &self->table->min, &self->table->max)) {
            return;
        }
    }
        self->fsm->st = 10;
    case 10: {
        ActorSub40 *w;
        if (e->max != 0 && alive >= e->max) {
            return;
        }
        if (!Ov003Ev_GameIdle() && self->fsm->timer != 0) {
            return;
        }
        if ((e->ids[self->slot] >> 12) == 5 && self->unk_1e == 0) {
            self->unk_93_4 = 1;
        }
        w = self->fsm;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer != 0) {
            return;
        }
        {
            GroupActorDesc desc;
            VecFx32 pos;
            Actor *u;
            s32 j;
            desc.kind = e->ids[self->slot];
            desc.group = desc.kind & 0xf000;
            for (j = 0; j < 4; j++) {
                desc.args[j] = 0;
            }
            desc.unk_0c = -1;
            desc.args[1] = e->args[self->slot];
            VEC_Add(&self->pos, &self->table->ofs, &pos);
            u = Group_SpawnActor(gGroup, &desc, &pos, &self->rot, 0xffff);
            if (u == NULL) {
                return;
            }
            u->flags_0 = 1;
            for (j = 0; j < 5; j++) {
                if (self->spawned[j] == 0xffff) {
                    self->spawned[j] = u->id;
                    break;
                }
            }
            self->slot++;
            if (self->slot >= 8 || e->ids[self->slot] == 0xffff) {
                self->fsm->st++;
                return;
            }
            self->fsm->timer = e->delays[self->slot];
        }
        return;
    }
    case 11: {
        BOOL ok;
        Ov003Ev_CheckNext(self, e);
        ok = FALSE;
        switch (e->mode) {
        case 0:
        case 3:
            ok = TRUE;
            break;
        case 1:
            if (cnt == 0) {
                ok = TRUE;
            }
            break;
        }
        if (!ok) {
            return;
        }
        self->fsm->timer = e->wait;
        self->fsm->st++;
        return;
    }
    case 12: {
        ActorSub40 *w;
        s32 nx;
        Ov003Ev_CheckNext(self, e);
        w = self->fsm;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer != 0) {
            return;
        }
        self->slot = 0;
        nx = e->next;
        if (nx == -2) {
            self->fsm->st = 0x15;
            nx = 0xf;
        } else if (nx == -1) {
            self->fsm->st = 0x14;
            nx = 0xf;
        } else if (e->mode == 3) {
            self->fsm->st = 0;
        } else {
            self->fsm->st = 10;
        }
        self->unk_18 = nx;
        func_ov000_02197dec(self, nx, -1);
        return;
    }
    case 0x14:
        if (cnt != 0) {
            return;
        }
    case 0x15:
        func_ov000_02197dec(self, 0xf, 1);
        Group_UpdateActor(gGroup, 0, self);
        self->vfunc_08();
        return;
    }
}
}
}  // namespace m_021e12b0

// ---- merged from ov003_021e1914.cpp
namespace m_021e1914 {

extern "C" {

typedef struct {
    u8 unk_00[0xc];
    u8 unk_0c[0xc];
    VecFx32 unk_18;
    VecFx32 unk_24;
    VecFx32 unk_30;
    s32 speed;
    u16 unk_40;
    u16 unk_42;
    s16 unk_44;
    u8 unk_46[2];
} Ov003SpotDef;

typedef struct {
    VecFx32 pos;
    u16 rx;
    u16 ry;
    u16 rz;
    s32 unk_14;
} Ov003SpotMsg;

extern void *gGroup;
extern const Ov003SpotDef data_ov003_021f6428[];
extern BOOL History_SetState(ActorSub40 *p, s32 a, s32 b);
extern void Shared_SetEventActor(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern Robo021ca458 *ActorMgr_FindPlayer(void);
extern BOOL Hit_DiffInBox(VecFx32 *a, VecFx32 *b, const void *c, const void *d);
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);

void Ov003ActVt_021f8638_State21(ActorEx *self) {
    self->unk_1c = 0;
    History_SetState(self->fsm, 1, 0);
    Shared_SetEventActor(self->kind, self->id);
    func_020627dc(4);
    gSceneCmd->stageFlags = 1;
}

void Ov003ActVt_021f8df0_Init(ActorEx *self) {
    const Ov003SpotDef *def;
    Robo021ca458 *pl;
    VecFx32 v;
    ActorEx_Init(self);
    def = &data_ov003_021f6428[self->unk_1a];
    if ((def->unk_42 >> 12) != 5) {
        return;
    }
    pl = ActorMgr_FindPlayer();
    if (pl == NULL) {
        return;
    }
    v.x = pl->pos.x;
    v.y = pl->pos.y;
    v.z = pl->pos.z;
    if (Hit_DiffInBox(&v, &self->pos, def, def->unk_0c)) {
        self->unk_93_4 = 1;
    }
}

void Ov003ActVt_021f8df0_Start(ActorEx *self) {
    Ov003Unit *u;
    ActorEx_Start(self);
    u = Group_FindNode(gGroup, self->unk_20);
    if (u != NULL) {
        u->unk_a2_5 = 1;
    }
    self->unk_84.x = self->pos.x;
    self->unk_84.y = self->pos.y;
    self->unk_84.z = self->pos.z;
    VEC_Add(&self->pos, &data_ov003_021f6428[self->unk_1a].unk_18, &self->pos);
    self->model->visible = 0;
}

extern void *gActorMgr;
extern void VEC_Normalize(const VecFx32 *a, VecFx32 *out);
extern Actor *Group_SpawnActor(void *mgr, GroupActorDesc *desc, VecFx32 *pos, Rot16 *rot, u16 a);
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern BOOL Hit_DiffInSphere(VecFx32 *a, VecFx32 *b, s32 r);
extern void Field_ShakeCamera(s32 a, s32 b);
extern void Actor_SendMsg(Actor *u, u16 id, u8 type, BOOL notify, u32 size, const void *data);
extern void Actor_SendMsgU8(Actor *u, u16 id, s32 m);
extern void HitMesh_Unlink_0203f920(void *p);
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *model, const char *name, s32 a, s32 b);
extern void Group_UpdateActor(void *mgr, s32 a, Actor *obj);

static inline BOOL Ov003Spot_IsBusy(FieldState *g) {
    return g->head != g->tail;
}

static inline BOOL Ov003Spot_IsIdle(FieldState *g) {
    if (Ov003Spot_IsBusy(g)) {
        return FALSE;
    }
    if (g->state != 3) {
        return FALSE;
    }
    return TRUE;
}

static inline BOOL Ov003Spot_GameIdle(void) {
    FieldState *g = gSceneCmd;
    if (g != NULL) {
        return Ov003Spot_IsIdle(g);
    }
    return TRUE;
}

static inline Actor *Ov003Spot_GetUnit(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

static inline BOOL Ov003Spot_IsLocked(Actor *u) {
    if (u->fsm != NULL) {
        return u->fsm->current;
    }
    return FALSE;
}

void Ov003ActVt_021f8df0_StateIdle(ActorEx *self) {
    const Ov003SpotDef *def;
    VecFx32 v;
    if (!Ov003Spot_GameIdle()) {
        return;
    }
    def = &data_ov003_021f6428[self->unk_1a];
    switch (self->fsm->st) {
    case 0: {
        Robo021ca458 *pl = ActorMgr_FindPlayer();
        if (pl == NULL) {
            return;
        }
        v.x = pl->pos.x;
        v.y = pl->pos.y;
        v.z = pl->pos.z;
        if (Hit_DiffInBox(&v, &self->unk_84, def, def->unk_0c)) {
            GroupActorDesc desc;
            VecFx32 pos;
            Rot16 rot;
            Actor *u;
            s32 i;
            u16 k;
            self->model->visible = 1;
            k = def->unk_42;
            if ((k >> 12) == 5) {
                self->unk_93_4 = 1;
            }
            desc.kind = k;
            desc.group = k & 0xf000;
            for (i = 0; i < 4; i++) {
                desc.args[i] = 0;
            }
            desc.unk_0c = -1;
            desc.args[1] = def->unk_44;
            pos.x = self->pos.x;
            pos.y = self->pos.y;
            pos.z = self->pos.z;
            rot.x = 0;
            rot.y = def->unk_40;
            rot.z = 0;
            u = Group_SpawnActor(gGroup, &desc, &pos, &rot, 0xffff);
            if (u == NULL) {
                return;
            }
            u->flags_0 = 1;
            u->vfunc_18();
            self->unk_ce = u->id;
            VEC_Add(&self->unk_84, &def->unk_24, &v);
            self->vel.x = v.x - self->pos.x;
            self->vel.y = v.y - self->pos.y;
            self->vel.z = v.z - self->pos.z;
            VEC_Normalize(&self->vel, &self->vel);
            {
                s32 spd = def->speed;
                self->vel.x = (s32)(((s64)self->vel.x * spd + 0x800) >> 12);
                self->vel.y = (s32)(((s64)self->vel.y * spd + 0x800) >> 12);
                self->vel.z = (s32)(((s64)self->vel.z * spd + 0x800) >> 12);
            }
            self->fsm->st++;
        } else {
            self->unk_93_4 = 0;
        }
        return;
    }
    case 1: {
        Actor *u;
        Ov003SpotMsg msg;
        VEC_Add(&self->unk_84, &def->unk_24, &v);
        if (Hit_DiffInSphere(&self->pos, &v, def->speed + 0x19a + self->radius)) {
            SndMgr_PlayAt(gSndMgr, 0x47, &self->pos, 0);
            Field_ShakeCamera(6, 0xc);
            self->fsm->st++;
        }
        VEC_Add(&self->pos, &self->vel, &self->pos);
        u = Ov003Spot_GetUnit(self->unk_ce);
        if (u == NULL) {
            return;
        }
        if (Ov003Spot_IsLocked(u)) {
            return;
        }
        msg.pos.x = u->pos.x;
        msg.pos.y = u->pos.y;
        msg.pos.z = u->pos.z;
        msg.pos.x = self->pos.x;
        msg.pos.y = self->pos.y;
        msg.pos.z = self->pos.z;
        msg.rx = u->rot_x;
        msg.ry = u->rot_y;
        msg.rz = u->rot_z;
        msg.unk_14 = 0;
        Actor_SendMsg(u, self->id, 7, 1, sizeof(msg), &msg);
        return;
    }
    case 2: {
        ActorSub40 *w = self->fsm;
        Actor *u;
        w->timer++;
        if (w->timer <= 0x3c) {
            return;
        }
        u = Ov003Spot_GetUnit(self->unk_ce);
        if (u != NULL && !Ov003Spot_IsLocked(u)) {
            Actor_SendMsgU8(u, self->id, 4);
        }
        if (self->hitMesh != NULL) {
            HitMesh_Unlink_0203f920(self->hitMesh);
        }
        Model0218fe1c_SetAnim(self->model, "act00", 0x19a, 0);
        SndMgr_PlayAt(gSndMgr, 0xe, &self->pos, 0);
        self->fsm->timer = 0;
        self->fsm->st++;
        return;
    }
    case 3: {
        ActorSub40 *w = self->fsm;
        w->timer++;
        if (w->timer <= 0x3c) {
            return;
        }
        VEC_Add(&self->unk_84, &def->unk_30, &v);
        self->vel.x = v.x - self->pos.x;
        self->vel.y = v.y - self->pos.y;
        self->vel.z = v.z - self->pos.z;
        VEC_Normalize(&self->vel, &self->vel);
        {
            s32 spd = def->speed;
            self->vel.x = (s32)(((s64)self->vel.x * spd + 0x800) >> 12);
            self->vel.y = (s32)(((s64)self->vel.y * spd + 0x800) >> 12);
            self->vel.z = (s32)(((s64)self->vel.z * spd + 0x800) >> 12);
        }
        Model0218fe1c_SetAnim(self->model, "nut00", 0x111, 0);
        SndMgr_PlayAt(gSndMgr, 0xf, &self->pos, 0);
        Group_UpdateActor(gGroup, 0, self);
        self->fsm->timer = 0;
        self->fsm->st++;
        return;
    }
    case 4:
        VEC_Add(&self->unk_84, &def->unk_30, &v);
        if (Hit_DiffInSphere(&self->pos, &v, def->speed + 0x19a + self->radius)) {
            self->vfunc_08();
            return;
        }
        VEC_Add(&self->pos, &self->vel, &self->pos);
        break;
    }
}

}
}  // namespace m_021e1914

// ---- merged from ov003_021e2148.c
namespace m_021e2148 {
extern "C" {

extern void *gGroup;
extern char *Tbl_GetResFile(u16 id);
extern char *Path_SkipDir(char *p);
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);

void Ov003ActVt_021f8c28_Init(Ov003ActExRes *self) {
    ActorExParam *def;
    Ov003Unit *u;
    ActorEx_Init(self);
    def = self->param;
    if (def->unk_02_3 && def->unk_01 == 1) {
        char buf[0x18];
        char *name = Tbl_GetResFile(self->kind);
        STD_CopyString(buf, Path_SkipDir(name));
        STD_ConcatenateString(buf, "e");
        STD_CopyString(self->res.unk_88, name);
        STD_CopyString(self->res.unk_a8, buf);
        self->res.unk_03_3 = 1;
        self->res.unk_00 = 0;
    }
    u = Group_FindNode(gGroup, self->unk_20);
    if (u != NULL) {
        u->unk_a2_5 = 1;
    }
}

extern BOOL ResSet_UpdateLoad(ActorRes *p);

BOOL Ov003ActVt_021f8c28_IsReady(Ov003ActExRes *self) {
    BOOL r = ActorEx_IsReady(self);
    ActorExParam *def = self->param;
    if (def->unk_02_3 && def->unk_01 == 1 && self->res.unk_00 >= 0) {
        if (!ResSet_UpdateLoad(&self->res)) {
            r = FALSE;
        }
    }
    return r;
}

typedef struct {
    s32 m[9];
    VecFx32 t;
} Ov003LtMtx;

typedef struct {
    VecFx32 ofs;
    s32 speed;
    const char *name;
    const char *name1;
    const char *name2;
    const char *name3;
    u8 shape;
    u8 sfx;
    s16 fx0;
    s16 fx0arg;
    s16 fx1;
    s16 fx1arg;
    u8 unk_2a[2];
} Ov003LtDef;

typedef struct {
    s16 v[6];
} Ov003LtShape;

typedef struct {
    s32 box[6];
    u16 rot[3];
    u16 kind;
    s32 unk_20;
    VecFx32 ofs;
    s32 unk_30;
} Ov003LtHit;

typedef struct {
    u8 unk_00[0x10];
    s16 unk_10;
} Ov003LtInfo;

extern const s16 FX_SinCosTable_[];
extern const Ov003LtDef data_ov003_021f67c0[];
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void MTX_Identity43_(Ov003LtMtx *m);
extern void MTX_RotX43_(Ov003LtMtx *m, s32 s, s32 c);
extern void MTX_RotY43_(Ov003LtMtx *m, s32 s, s32 c);
extern void MTX_RotZ43_(Ov003LtMtx *m, s32 s, s32 c);
extern void MTX_Concat43(Ov003LtMtx *a, Ov003LtMtx *b, Ov003LtMtx *out);
extern void HitMesh_SetMtx(void *obj, Ov003LtMtx *m);
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *model, const char *name, s32 a, s32 b);
extern void Model0218fe1c_SetLoop(Model0218fe1c *model);

#define OV003LT_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003LT_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

void Ov003ActVt_021f8c28_Start(Ov003ActExRes *self) {
    const Ov003LtDef *def;
    void *obj;
    ActorEx_Start(self);
    self->unk_84.x = self->pos.x;
    self->unk_84.y = self->pos.y;
    self->unk_84.z = self->pos.z;
    def = &data_ov003_021f67c0[self->unk_1a];
    if (self->unk_18 != 0) {
        VEC_Add(&self->pos, &def->ofs, &self->pos);
    }
    obj = self->hitMesh;
    if (obj != NULL) {
        Ov003LtMtx t;
        Ov003LtMtx m;
        u16 rx;
        u16 ry;
        u16 rz;
        BOOL set = FALSE;
        rz = self->rot_z;
        ry = self->rot_y;
        rx = self->rot_x;
        MTX_Identity43_(&m);
        if (rz != 0) {
            MTX_RotZ43_(&m, OV003LT_SIN(rz), OV003LT_COS(rz));
            set = TRUE;
        }
        if (ry != 0) {
            if (set) {
                MTX_RotY43_(&t, OV003LT_SIN(ry), OV003LT_COS(ry));
                MTX_Concat43(&t, &m, &m);
            } else {
                MTX_RotY43_(&m, OV003LT_SIN(ry), OV003LT_COS(ry));
                set = TRUE;
            }
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX43_(&t, OV003LT_SIN(rx), OV003LT_COS(rx));
                MTX_Concat43(&t, &m, &m);
            } else {
                MTX_RotX43_(&m, OV003LT_SIN(rx), OV003LT_COS(rx));
                set = TRUE;
            }
        }
        m.t.x = self->pos.x;
        m.t.y = self->pos.y;
        m.t.z = self->pos.z;
        HitMesh_SetMtx(obj, &m);
    }
    Model0218fe1c_SetAnim(self->model, def->name, 0x1000, 0);
    Model0218fe1c_SetLoop(self->model);
}

extern Ov003LtShape data_ov003_021f5c70[];
extern void VEC_Normalize(const VecFx32 *a, VecFx32 *out);
extern void HitMesh_SetRes(void *obj, u32 a);
extern void HitMesh_SetScale(void *obj, s32 a);
extern Ov003LtInfo *Tbl_FindEntry_0206fef8(u16 id);
extern void func_ov000_0219b808(u16 id, void *pos, Ov003LtHit *entry, s32 a, s32 b);
extern BOOL Model0218fe1c_IsAnimDone(Model0218fe1c *model);
extern s32 Ov003CntSelf_CountLiving(ActorSub4c *p);
extern void func_020627b4(void);
extern s32 StageRes_HasQueued(void);
extern Robo021ca458 *ActorMgr_FindPlayer(void);
extern void Field_ShakeCamera(s32 a, s32 b);
extern BOOL Hit_DiffInSphere(VecFx32 *a, VecFx32 *b, s32 r);

void Ov003ActVt_021f8c28_StateIdle(Ov003ActExRes *self) {
    const Ov003LtDef *def = &data_ov003_021f67c0[self->unk_1a];
    VecFx32 v;
    Ov003LtHit hit;
    Ov003LtMtx t;
    Ov003LtMtx m;
    switch (self->fsm->st) {
    case 0: {
        s32 r = 3;
        if (self->unk_1c != 0) {
            r = Ov003CntSelf_CountLiving(self->targetObj);
        }
        if (r == 3 || r == 4) {
            ActorExParam *pd;
            s16 n;
            self->unk_93_1 = 1;
            Model0218fe1c_SetAnim(self->model, def->name1, 0x1000, 0);
            n = (s16)(self->unk_18 + 1) & 1;
            self->unk_18 = n;
            func_020627b4();
            func_ov000_02197dec(self, n, 1);
            if (StageRes_HasQueued() == 1) {
                Robo021ca458 *pl = ActorMgr_FindPlayer();
                if (pl != NULL && pl->unk_b28_0 == 0) {
                    pl->mode = 3;
                    pl->unk_b28_0 = 0;
                    pl->unk_b28_2 = 1;
                }
            }
            pd = self->param;
            if (pd->unk_02_3 && pd->unk_01 == 1) {
                Ov003LtInfo *info = Tbl_FindEntry_0206fef8(self->kind);
                HitMesh_SetRes(self->hitMesh, self->res.unk_84 != NULL ? *self->res.unk_84 : 0);
                HitMesh_SetScale(self->hitMesh, info->unk_10);
            }
            self->vel.x = 0;
            self->vel.y = 0;
            self->vel.z = 0;
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        break;
    }
    case 1:
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            break;
        }
        Model0218fe1c_SetAnim(self->model, def->name2, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        v.x = self->unk_84.x;
        v.y = self->unk_84.y;
        v.z = self->unk_84.z;
        if (self->unk_18 != 0) {
            VEC_Add(&v, &def->ofs, &v);
        }
        self->vel.x = v.x - self->pos.x;
        self->vel.y = v.y - self->pos.y;
        self->vel.z = v.z - self->pos.z;
        VEC_Normalize(&self->vel, &self->vel);
        {
            s32 spd = def->speed;
            self->vel.x = (s32)(((s64)self->vel.x * spd + 0x800) >> 12);
            self->vel.y = (s32)(((s64)self->vel.y * spd + 0x800) >> 12);
            self->vel.z = (s32)(((s64)self->vel.z * spd + 0x800) >> 12);
        }
        if (def->sfx != 0) {
            Field_ShakeCamera(5, 0xf);
        }
        if (def->fx0 >= 0) {
            SndMgr_PlayAtPitch(gSndMgr, def->fx0, &self->pos, def->fx0arg);
        }
        self->fsm->st++;
    case 2: {
        void *obj;
        if (self->unk_1a == 14) {
            ActorSub40 *ww = self->fsm;
            if (ww->timer != 0) {
                ww->timer--;
            }
            if (ww->timer == 0) {
                self->fsm->timer = 0x3c;
                SndMgr_PlayAtPitch(gSndMgr, 0x27, &self->pos, -8);
            }
        }
        v.x = self->unk_84.x;
        v.y = self->unk_84.y;
        v.z = self->unk_84.z;
        if (self->unk_18 != 0) {
            VEC_Add(&v, &def->ofs, &v);
        }
        if (Hit_DiffInSphere(&self->pos, &v, def->speed + 0x19a + self->radius)) {
            if (self->unk_1c != 0) {
                self->unk_93_1 = 0;
            }
            if (def->sfx != 0) {
                Field_ShakeCamera(5, 0xf);
            }
            if (def->fx1 >= 0) {
                SndMgr_PlayAtPitch(gSndMgr, def->fx1, &self->pos, def->fx1arg);
            }
            self->vel.x = v.x - self->pos.x;
            self->vel.y = v.y - self->pos.y;
            self->vel.z = v.z - self->pos.z;
            Model0218fe1c_SetAnim(self->model, def->name3, 0x1000, 0);
            self->fsm->st++;
        }
        VEC_Add(&self->pos, &self->vel, &self->pos);
        obj = self->hitMesh;
        if (obj != NULL) {
            u16 rx;
            u16 ry;
            u16 rz;
            BOOL set = FALSE;
            rz = self->rot_z;
            ry = self->rot_y;
            rx = self->rot_x;
            MTX_Identity43_(&m);
            if (rz != 0) {
                MTX_RotZ43_(&m, OV003LT_SIN(rz), OV003LT_COS(rz));
                set = TRUE;
            }
            if (ry != 0) {
                if (set) {
                    MTX_RotY43_(&t, OV003LT_SIN(ry), OV003LT_COS(ry));
                    MTX_Concat43(&t, &m, &m);
                } else {
                    MTX_RotY43_(&m, OV003LT_SIN(ry), OV003LT_COS(ry));
                    set = TRUE;
                }
            }
            if (rx != 0) {
                if (set) {
                    MTX_RotX43_(&t, OV003LT_SIN(rx), OV003LT_COS(rx));
                    MTX_Concat43(&t, &m, &m);
                } else {
                    MTX_RotX43_(&m, OV003LT_SIN(rx), OV003LT_COS(rx));
                    set = TRUE;
                }
            }
            m.t.x = self->pos.x;
            m.t.y = self->pos.y;
            m.t.z = self->pos.z;
            HitMesh_SetMtx(obj, &m);
        }
        break;
    }
    case 3:
        self->vel.x = 0;
        self->vel.y = 0;
        self->vel.z = 0;
        self->fsm->st++;
    case 4:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            ActorExParam *pd;
            if (self->unk_1c != 0) {
                self->fsm->st = 0;
            } else {
                self->fsm->st = 0xffff;
            }
            pd = self->param;
            if (pd->unk_02_3 && pd->unk_01 == 1) {
                Ov003LtInfo *info = Tbl_FindEntry_0206fef8(self->kind);
                u32 *p = ((ActorRes *)self->unk_34)->unk_84;
                HitMesh_SetRes(self->hitMesh, p != NULL ? *p : 0);
                HitMesh_SetScale(self->hitMesh, info->unk_10);
            }
        }
        break;
    }
    if (self->fsm->st != 0 && self->fsm->st != 0xffff) {
        Ov003LtShape *sh = &data_ov003_021f5c70[def->shape];
        hit.box[0] = sh->v[0] << 4;
        hit.box[1] = sh->v[1] << 4;
        hit.box[2] = sh->v[2] << 4;
        hit.box[3] = sh->v[3] << 4;
        hit.box[4] = sh->v[4] << 4;
        hit.box[5] = sh->v[5] << 4;
        hit.rot[0] = self->rot_x;
        hit.rot[1] = self->rot_y;
        hit.rot[2] = self->rot_z;
        hit.kind = 0x32;
        hit.unk_20 = 0x20040000;
        hit.ofs.x = self->vel.x;
        hit.ofs.y = self->vel.y;
        hit.ofs.z = self->vel.z;
        hit.unk_30 = -1;
        func_ov000_0219b808(self->id, &self->pos, &hit, 0, 0);
    }
}
}
}  // namespace m_021e2148
#undef OV003LT_SIN
#undef OV003LT_COS

// ---- merged from ov003_021e2afc.c
namespace m_021e2afc {
extern "C" {

extern void *gGroup;
extern char *Tbl_GetResFile(u16 id);
extern char *Path_SkipDir(char *p);
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);

void Ov003ActVt_021f89c8_Init(Ov003ActExRes *self) {
    ActorExParam *def;
    Ov003Unit *u;
    ActorEx_Init(self);
    def = self->param;
    if (def->unk_02_3 && def->unk_01 == 1) {
        char buf[0x18];
        char *name = Tbl_GetResFile(self->kind);
        STD_CopyString(buf, Path_SkipDir(name));
        STD_ConcatenateString(buf, "e");
        STD_CopyString(self->res.unk_88, name);
        STD_CopyString(self->res.unk_a8, buf);
        self->res.unk_03_3 = 1;
        self->res.unk_00 = 0;
    }
    u = Group_FindNode(gGroup, self->unk_20);
    if (u != NULL) {
        u->unk_a2_5 = 1;
    }
}

extern BOOL ResSet_UpdateLoad(ActorRes *p);

BOOL Ov003ActVt_021f89c8_IsReady(Ov003ActExRes *self) {
    BOOL r = ActorEx_IsReady(self);
    ActorExParam *def = self->param;
    if (def->unk_02_3 && def->unk_01 == 1 && self->res.unk_00 >= 0) {
        if (!ResSet_UpdateLoad(&self->res)) {
            r = FALSE;
        }
    }
    return r;
}
}
}  // namespace m_021e2afc

// ---- merged from ov003_021e2b50.c
namespace m_021e2b50 {
extern "C" {

typedef struct {
    s32 m[9];
    VecFx32 t;
} Ov003LtMtx;

typedef struct {
    VecFx32 ofs;
    s32 speed;
    const char *name;
    const char *name1;
    const char *name2;
    const char *name3;
    u8 shape;
    u8 sfx;
    s16 fx0;
    s16 fx0arg;
    s16 fx1;
    s16 fx1arg;
    u8 unk_2a[2];
} Ov003LtDef;

typedef struct {
    s16 v[6];
} Ov003LtShape;

typedef struct {
    s32 box[6];
    u16 rot[3];
    u16 kind;
    s32 unk_20;
    VecFx32 ofs;
    s32 unk_30;
} Ov003LtHit;

typedef struct {
    u8 unk_00[0x1f0];
    u16 unk_1f0;
} Ov003LtField;

typedef struct {
    u8 unk_00[0x10];
    s16 unk_10;
} Ov003LtInfo;

extern const s16 FX_SinCosTable_[];
extern const Ov003LtDef data_ov003_021f67c0[];
extern Ov003LtShape data_ov003_021f5c70[];
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void VEC_Normalize(const VecFx32 *a, VecFx32 *out);
extern void MTX_Identity43_(Ov003LtMtx *m);
extern void MTX_RotX43_(Ov003LtMtx *m, s32 s, s32 c);
extern void MTX_RotY43_(Ov003LtMtx *m, s32 s, s32 c);
extern void MTX_RotZ43_(Ov003LtMtx *m, s32 s, s32 c);
extern void MTX_Concat43(Ov003LtMtx *a, Ov003LtMtx *b, Ov003LtMtx *out);
extern void HitMesh_SetMtx(void *obj, Ov003LtMtx *m);
extern void HitMesh_Link(void *obj);
extern void HitMesh_SetRes(void *obj, u32 a);
extern void HitMesh_SetScale(void *obj, s32 a);
extern Ov003LtInfo *Tbl_FindEntry_0206fef8(u16 id);
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *model, const char *name, s32 a, s32 b);
extern void Model0218fe1c_SetLoop(Model0218fe1c *model);
extern s32 func_ov000_0219b808(u16 id, void *pos, Ov003LtHit *entry, u16 *ids, s32 max);
extern BOOL History_SetState(ActorSub40 *p, s32 a, s32 b);
extern BOOL Model0218fe1c_IsAnimDone(Model0218fe1c *model);
extern void Field_ShakeCamera(s32 a, s32 b);
extern BOOL Hit_DiffInSphere(VecFx32 *a, VecFx32 *b, s32 r);
extern Ov003LtField *gFieldMgr;
extern void *gActorMgr;
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);
extern void FieldMgr_SetIdVec(Ov003LtField *f, u16 id, VecFx32 *v);
extern Robo021ca458 *ActorMgr_FindPlayer(void);

#define OV003LT_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003LT_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

void Ov003ActVt_021f89c8_Start(Ov003ActExRes *self) {
    const Ov003LtDef *def;
    u16 rx;
    u16 ry;
    u16 rz;
    BOOL set;
    void *obj;
    ActorEx_Start(self);
    self->unk_84.x = self->pos.x;
    self->unk_84.y = self->pos.y;
    self->unk_84.z = self->pos.z;
    def = &data_ov003_021f67c0[self->unk_1a];
    Model0218fe1c_SetAnim(self->model, def->name, 0x1000, 0);
    Model0218fe1c_SetLoop(self->model);
    if (self->unk_18 != 0) {
        ActorExParam *pd;
        Ov003LtShape *sh;
        Ov003LtHit hit;
        if (self->unk_18 == 1) {
            VEC_Add(&self->pos, &def->ofs, &self->pos);
        } else {
            self->pos.x = self->pos.x - def->ofs.x;
            self->pos.y = self->pos.y - def->ofs.y;
            self->pos.z = self->pos.z - def->ofs.z;
        }
        Model0218fe1c_SetAnim(self->model, def->name2, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        self->vel.x = self->unk_84.x - self->pos.x;
        self->vel.y = self->unk_84.y - self->pos.y;
        self->vel.z = self->unk_84.z - self->pos.z;
        VEC_Normalize(&self->vel, &self->vel);
        {
            s32 spd = def->speed;
            self->vel.x = (s32)(((s64)self->vel.x * spd + 0x800) >> 12);
            self->vel.y = (s32)(((s64)self->vel.y * spd + 0x800) >> 12);
            self->vel.z = (s32)(((s64)self->vel.z * spd + 0x800) >> 12);
        }
        pd = self->param;
        if (pd->unk_02_3 && pd->unk_01 == 1) {
            Ov003LtInfo *info = Tbl_FindEntry_0206fef8(self->kind);
            u32 v = 0;
            if (self->res.unk_84 != NULL) {
                v = *self->res.unk_84;
            }
            HitMesh_SetRes(self->hitMesh, v);
            HitMesh_SetScale(self->hitMesh, info->unk_10);
        }
        sh = &data_ov003_021f5c70[def->shape];
        hit.box[0] = sh->v[0] << 4;
        hit.box[1] = sh->v[1] << 4;
        hit.box[2] = sh->v[2] << 4;
        hit.box[3] = sh->v[3] << 4;
        hit.box[4] = sh->v[4] << 4;
        hit.box[5] = sh->v[5] << 4;
        hit.rot[0] = self->rot_x;
        hit.rot[1] = self->rot_y;
        hit.rot[2] = self->rot_z;
        hit.kind = 0x12;
        hit.unk_20 = 0;
        hit.ofs.x = self->pos.x - self->unk_84.x;
        hit.ofs.y = self->pos.y - self->unk_84.y;
        hit.ofs.z = self->pos.z - self->unk_84.z;
        hit.unk_30 = -1;
        func_ov000_0219b808(self->id, &self->unk_84, &hit, NULL, 0);
        History_SetState(self->fsm, 1, 0);
        self->fsm->st = 10;
    }
    obj = self->hitMesh;
    if (obj != NULL) {
        Ov003LtMtx t;
        Ov003LtMtx m;
        set = FALSE;
        rz = self->rot_z;
        ry = self->rot_y;
        rx = self->rot_x;
        MTX_Identity43_(&m);
        if (rz != 0) {
            MTX_RotZ43_(&m, OV003LT_SIN(rz), OV003LT_COS(rz));
            set = TRUE;
        }
        if (ry != 0) {
            if (set) {
                MTX_RotY43_(&t, OV003LT_SIN(ry), OV003LT_COS(ry));
                MTX_Concat43(&t, &m, &m);
            } else {
                MTX_RotY43_(&m, OV003LT_SIN(ry), OV003LT_COS(ry));
                set = TRUE;
            }
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX43_(&t, OV003LT_SIN(rx), OV003LT_COS(rx));
                MTX_Concat43(&t, &m, &m);
            } else {
                MTX_RotX43_(&m, OV003LT_SIN(rx), OV003LT_COS(rx));
                set = TRUE;
            }
        }
        m.t.x = self->pos.x;
        m.t.y = self->pos.y;
        m.t.z = self->pos.z;
        HitMesh_SetMtx(obj, &m);
        HitMesh_Link(self->hitMesh);
    }
}

#define OV003LT_MTX(obj, MM, TT)                                                   \
    {                                                                            \
        u16 rx;                                                                  \
        u16 ry;                                                                  \
        u16 rz;                                                                  \
        BOOL set = FALSE;                                                        \
        rz = self->rot_z;                                                       \
        ry = self->rot_y;                                                       \
        rx = self->rot_x;                                                       \
        MTX_Identity43_(&MM);                                                     \
        if (rz != 0) {                                                           \
            MTX_RotZ43_(&MM, OV003LT_SIN(rz), OV003LT_COS(rz));                   \
            set = TRUE;                                                          \
        }                                                                        \
        if (ry != 0) {                                                           \
            if (set) {                                                           \
                MTX_RotY43_(&TT, OV003LT_SIN(ry), OV003LT_COS(ry));               \
                MTX_Concat43(&TT, &MM, &MM);                                        \
            } else {                                                             \
                MTX_RotY43_(&MM, OV003LT_SIN(ry), OV003LT_COS(ry));               \
                set = TRUE;                                                      \
            }                                                                    \
        }                                                                        \
        if (rx != 0) {                                                           \
            if (set) {                                                           \
                MTX_RotX43_(&TT, OV003LT_SIN(rx), OV003LT_COS(rx));               \
                MTX_Concat43(&TT, &MM, &MM);                                        \
            } else {                                                             \
                MTX_RotX43_(&MM, OV003LT_SIN(rx), OV003LT_COS(rx));               \
                set = TRUE;                                                      \
            }                                                                    \
        }                                                                        \
        MM.t.x = self->pos.x;                                                     \
        MM.t.y = self->pos.y;                                                     \
        MM.t.z = self->pos.z;                                                     \
        HitMesh_SetMtx(obj, &MM);                                                  \
    }

#define OV003LT_HIT(hit)                                                         \
    {                                                                            \
        const Ov003LtShape *sh = &data_ov003_021f5c70[def->shape];               \
        hit.box[0] = sh->v[0] << 4;                                              \
        hit.box[1] = sh->v[1] << 4;                                              \
        hit.box[2] = sh->v[2] << 4;                                              \
        hit.box[3] = sh->v[3] << 4;                                              \
        hit.box[4] = sh->v[4] << 4;                                              \
        hit.box[5] = sh->v[5] << 4;                                              \
        hit.rot[0] = self->rot_x;                                               \
        hit.rot[1] = self->rot_y;                                               \
        hit.rot[2] = self->rot_z;                                               \
        hit.kind = 0x12;                                                         \
        hit.unk_20 = 0x20040000;                                                 \
        hit.ofs.x = self->vel.x;                                                 \
        hit.ofs.y = self->vel.y;                                                 \
        hit.ofs.z = self->vel.z;                                                 \
        hit.unk_30 = -1;                                                         \
    }

static inline Actor *Ov003Lt_GetUnit(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

void Ov003ActVt_021f89c8_StateIdle(Ov003ActExRes *self) {
    const Ov003LtDef *def = &data_ov003_021f67c0[self->unk_1a];
    VecFx32 v;
    Ov003LtHit hitB;
    u16 ids[0x20];
    VecFx32 d;
    Ov003LtHit hitA;
    Ov003LtMtx tB;
    Ov003LtMtx mB;
    Ov003LtMtx tA;
    Ov003LtMtx mA;
    switch (self->fsm->st) {
    case 0: {
        ActorExParam *pd;
        if (self->unk_18 == 0) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, def->name1, 0x1000, 0);
        func_ov000_02197dec(self, self->unk_18, -1);
        pd = self->param;
        if (pd->unk_02_3 && pd->unk_01 == 1) {
            Ov003LtInfo *info = Tbl_FindEntry_0206fef8(self->kind);
            u32 x = 0;
            if (self->res.unk_84 != NULL) {
                x = *self->res.unk_84;
            }
            HitMesh_SetRes(self->hitMesh, x);
            HitMesh_SetScale(self->hitMesh, info->unk_10);
        }
        self->fsm->timer = 0;
        self->fsm->st++;
        return;
    }
    case 1:
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        Model0218fe1c_SetAnim(self->model, def->name2, 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        if (self->unk_18 == 1) {
            VEC_Add(&self->pos, &def->ofs, &v);
        } else {
            v.x = self->pos.x - def->ofs.x;
            v.y = self->pos.y - def->ofs.y;
            v.z = self->pos.z - def->ofs.z;
        }
        self->vel.x = v.x - self->pos.x;
        self->vel.y = v.y - self->pos.y;
        self->vel.z = v.z - self->pos.z;
        VEC_Normalize(&self->vel, &self->vel);
        {
            s32 spd = def->speed;
            self->vel.x = (s32)(((s64)self->vel.x * spd + 0x800) >> 12);
            self->vel.y = (s32)(((s64)self->vel.y * spd + 0x800) >> 12);
            self->vel.z = (s32)(((s64)self->vel.z * spd + 0x800) >> 12);
        }
        if (def->sfx != 0) {
            Field_ShakeCamera(5, 0xf);
        }
        if (def->fx0 >= 0) {
            SndMgr_PlayAtPitch(gSndMgr, def->fx0, &self->pos, def->fx0arg);
        }
        self->fsm->st++;
        return;
    case 2: {
        void *obj;
        Robo021ca458 *pl;
        u16 plId;
        s32 i;
        s32 n;
        VEC_Add(&self->pos, &self->vel, &self->pos);
        obj = self->hitMesh;
        if (obj != NULL) {
            OV003LT_MTX(obj, mB, tB);
        }
        OV003LT_HIT(hitB);
        n = func_ov000_0219b808(self->id, &self->pos, &hitB, ids, 0x20);
        if (n == 0) {
            return;
        }
        gFieldMgr->unk_1f0 = self->kind;
        pl = ActorMgr_FindPlayer();
        if (n > sizeof(ids) / sizeof(ids[0])) {
            n = 0x20;
        }
        plId = pl->id;
        for (i = 0; i < n; i++) {
            Actor *u = Ov003Lt_GetUnit(ids[i]);
            if (u != NULL && u->kind != 0x4cc1) {
                u16 id = u->id;
                if (id == plId) {
                    d.x = pl->unk_75c.x;
                    d.y = pl->unk_75c.y;
                    d.z = pl->unk_75c.z;
                } else {
                    d.x = u->pos.x;
                    d.y = u->pos.y;
                    d.z = u->pos.z;
                    u->unk_16 |= 2;
                }
                d.x -= self->pos.x;
                d.y -= self->pos.y;
                d.z -= self->pos.z;
                FieldMgr_SetIdVec(gFieldMgr, id, &d);
            }
        }
        return;
    }
    case 10: {
        void *obj;
        if (Hit_DiffInSphere(&self->pos, &self->unk_84, def->speed + 0x19a + self->radius)) {
            if (def->sfx != 0) {
                Field_ShakeCamera(5, 0xf);
            }
            if (def->fx1 >= 0) {
                SndMgr_PlayAtPitch(gSndMgr, def->fx1, &self->pos, def->fx1arg);
            }
            self->vel.x = self->unk_84.x - self->pos.x;
            self->vel.y = self->unk_84.y - self->pos.y;
            self->vel.z = self->unk_84.z - self->pos.z;
            Model0218fe1c_SetAnim(self->model, def->name3, 0x1000, 0);
            self->fsm->st++;
        }
        VEC_Add(&self->pos, &self->vel, &self->pos);
        obj = self->hitMesh;
        if (obj != NULL) {
            OV003LT_MTX(obj, mA, tA);
        }
        OV003LT_HIT(hitA);
        func_ov000_0219b808(self->id, &self->pos, &hitA, NULL, 0);
        return;
    }
    case 11:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            ActorExParam *pd;
            self->fsm->st = 0;
            self->unk_18 = 0;
            func_ov000_02197dec(self, 0, -1);
            pd = self->param;
            if (pd->unk_02_3 && pd->unk_01 == 1) {
                Ov003LtInfo *info = Tbl_FindEntry_0206fef8(self->kind);
                u32 *p = ((ActorRes *)self->unk_34)->unk_84;
                u32 x = 0;
                if (p != NULL) {
                    x = *p;
                }
                HitMesh_SetRes(self->hitMesh, x);
                HitMesh_SetScale(self->hitMesh, info->unk_10);
            }
        }
        return;
    }
}

}
}  // namespace m_021e2b50
#undef OV003LT_SIN
#undef OV003LT_COS
#undef OV003LT_MTX
#undef OV003LT_HIT

// ---- merged from ov003_021e3a90.c
namespace m_021e3a90 {
extern "C" {

extern void Model0218fe1c_SetLoop(Model0218fe1c *model);
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *model, s32 v);
extern u16 Angle_Approach(u16 target, u16 cur, s32 step, s32 a, s32 b);
extern void func_ov000_021975b4(Actor *self);
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *model, const void *name, s32 a, s32 b);

void Ov003ActVt_021f8800_Start(ActorEx *self) {
    s16 a;
    s16 b;
    ActorEx_Start(self);
    a = self->unk_18;
    b = self->unk_1a;
    if (a != 0 && a < b) {
        switch (self->param->unk_01) {
        case 1:
            Model0218fe1c_SetAnim(self->model, "op01", 0x1000, 0);
            break;
        case 2:
            Model0218fe1c_SetAnim(self->model, "op01", 0x1000, 0);
            break;
        }
    }
}

void Ov003ActVt_021f8800_State20(ActorEx *self) {
    s16 n;
    s16 lim;
    func_ov000_021975b4(self);
    n = self->unk_18 + 1;
    lim = self->unk_1a;
    self->unk_18 = n;
    switch (self->param->unk_01) {
    case 1:
        if (n >= lim) {
            if (self->model != NULL) {
                Model0218fe1c_SetAnim(self->model, "op02", 0x1000, 0);
            }
            self->unk_cc_0 = 0;
        } else if (self->model != NULL) {
            Model0218fe1c_SetAnim(self->model, "op01", 0x1000, 0);
        }
        break;
    case 2:
        if (n >= lim) {
            ActorSub44 *p;
            if (self->model != NULL) {
                Model0218fe1c_SetAnim(self->model, "op02", 0x1000, 0);
            }
            self->targetObj->unk_02 = 5;
            p = self->unk_44;
            if (p != NULL) {
                p->unk_22_0 = 0;
                p->unk_22_1 = 0;
            }
        } else if (self->model != NULL) {
            Model0218fe1c_SetAnim(self->model, "op01", 0x1000, 0);
        }
        break;
    case 4:
        if (self->model != NULL) {
            Model0218fe1c_SetAnim(self->model, "act00", 0x1000, 0);
        }
        break;
    case 5:
        if (self->targetObj != NULL) {
            self->targetObj->unk_1e = self->unk_1c;
        }
        SndMgr_PlayAt(gSndMgr, 0x73, &self->pos, 0);
        break;
    case 6:
        SndMgr_PlayAtPitch(gSndMgr, 8, &self->pos, -5);
        break;
    }
}

void Ov003ActVt_021f8fb8_Start(ActorEx *self) {
    ActorEx_Start(self);
    if (self->unk_18 >= self->unk_1a) {
        self->targetObj->type = 0x10;
        if (self->unk_1e == 0) {
            self->rot_y += 0x8000;
        }
    }
    self->moveYaw = self->rot_y;
}

void Ov003ActVt_021f8fb8_StateIdle(ActorEx *self) {
    ActorSub40 *w = self->fsm;
    switch (w->st) {
    case 0:
        if (self->unk_18 >= self->unk_1a) {
            Model0218fe1c_SetAnim(self->model, "fly00", 0x1000, 0);
        } else {
            Model0218fe1c_SetAnim(self->model, "nut00", 0x1000, 0);
        }
        Model0218fe1c_SetLoop(self->model);
        Model0218fe1c_SetAnimSpeed(self->model, 0xccd);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        if (self->unk_18 >= self->unk_1a) {
            self->fsm->st = 10;
        } else {
            self->fsm->st++;
        }
        break;
    case 10:
        w->timer++;
        if (w->timer > 0x5a) {
            ActorSub44 *p = self->unk_44;
            p->unk_22_0 = 1;
            p->unk_22_1 = 1;
            self->unk_44->unk_22_4 = 0;
            self->targetObj->type = 0x10;
            self->fsm->st++;
        }
        if (self->fsm->timer > 0x2d) {
            self->rot_y = Angle_Approach(self->moveYaw, self->rot_y, 0x100, 1, 0x8000);
            self->rot_x = Angle_Approach(0, self->rot_x, 0x400, 1, 0x8000);
        }
        break;
    case 11:
        self->rot_y = Angle_Approach(self->moveYaw, self->rot_y, 0x100, 1, 0x8000);
        break;
    }
}

}
}  // namespace m_021e3a90

// ---- merged from ov003_021e3d34.cpp
namespace m_021e3d34 {

extern "C" {

extern void *gGroup;
extern BOOL History_SetState(ActorSub40 *p, s32 a, s32 b);
extern void Group_UpdateActor(void *mgr, s32 a, Actor *obj);
extern void Model0218fe1c_SetLoop(Model0218fe1c *model);
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *model, s32 v);
extern u16 Angle_Approach(u16 target, u16 cur, s32 step, s32 a, s32 b);
extern void func_ov000_021975b4(Actor *self);
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *model, const void *name, s32 a, s32 b);

extern void *gActorMgr;
extern void *Model0218fe1c_SetAnimFrame(Model0218fe1c *m, s32 a);
extern void Model0218fe1c_PauseAnim(Model0218fe1c *model);
extern BOOL Model0218fe1c_IsAnimDone(Model0218fe1c *model);
extern void *Model0218fe1c_GetAnimCtrl(Model0218fe1c *m, s32 a);
extern BOOL AnimCtrl_IsDone(void *a);
extern void ActorMgr_BroadcastKind(void *mgr, s32 a, s32 b);
extern void Field_ShakeCamera(s32 a, s32 b);
extern void *Heap_Alloc(u32 size);
extern Robo021ca458 *ActorMgr_FindPlayer(void);

void Ov003ActVt_021f8fb8_State20(ActorEx *self) {
    s16 n;
    func_ov000_021975b4(self);
    if (self->unk_18 >= self->unk_1a) {
        return;
    }
    n = self->unk_18 + 1;
    self->unk_18 = n;
    if (self->unk_1a <= n) {
        ActorSub44 *p;
        Model0218fe1c_SetAnim(self->model, "fly00", 0x2ab, 0);
        Model0218fe1c_SetLoop(self->model);
        p = self->unk_44;
        p->unk_22_0 = 0;
        p->unk_22_1 = 0;
        self->moveYaw = self->rot_y + 0x8000;
        self->unk_1e = 1;
        func_ov000_02197dec(self, self->unk_18, -1);
    } else {
        Model0218fe1c_SetAnim(self->model, "joy00", 0x1000, 0);
    }
}

void Ov003ActVt_021f8fb8_State0a(ActorEx *self) {
    if (self->unk_1c == 0) {
        ActorSub44 *p = self->unk_44;
        p->unk_22_0 = 0;
        p->unk_22_1 = 0;
        History_SetState(self->fsm, 1, 0);
        self->moveYaw = self->rot_y + 0x8000;
        return;
    }
    switch (self->fsm->st) {
    case 0: {
        ActorSub44 *p = self->unk_44;
        p->unk_22_0 = 0;
        p->unk_22_1 = 0;
        self->velY = 0;
        self->fsm->st++;
        break;
    }
    case 1: {
        ActorSub40 *w;
        s32 v = self->velY;
        v += (0x466 - v) >> 7;
        self->velY = v;
        self->pos.y += v;
        self->rot_x = Angle_Approach(0, self->rot_x, 0x400, 1, 0x8000);
        w = self->fsm;
        w->timer++;
        if (w->timer > 0xb4) {
            func_ov000_02197dec(self, 0xf, -1);
            Group_UpdateActor(gGroup, 0, self);
            self->vfunc_08();
        }
        break;
    }
    }
}

void Ov003ActVt_021f8cc0_Start(ActorEx *self) {
    s16 n;
    s16 lim;
    ActorHp *q;
    ActorEx_Start(self);
    n = self->unk_18;
    lim = self->unk_1a;
    if (n > lim) {
        n = lim;
    }
    Model0218fe1c_SetAnim(self->model, "nut00", 0x1000, 0);
    if (n >= lim) {
        ActorSub44 *p;
        History_SetState(self->fsm, 1, 0);
        self->fsm->st = 0xffff;
        Model0218fe1c_SetAnimFrame(self->model, -1);
        p = self->unk_44;
        p->unk_22_0 = 0;
        p->unk_22_1 = 0;
        self->unk_cc_0 = 0;
    } else {
        Model0218fe1c_PauseAnim(self->model);
    }
    self->unk_44->unk_22_2 = 2;
    q = (ActorHp *)Heap_Alloc(sizeof(ActorHp));
    if (q != NULL) {
        q->cur = 100;
        q->max = 100;
        q->unk_04 = 0xffff;
        q->unk_0a = 0;
        q->unk_0e = 0;
        q->unk_0c = 0;
        q->unk_10 = 0;
        q->unk_14 = 0;
        q->unk_18 = 0;
    }
    self->hpObj = q;
}

void Ov003ActVt_021f8cc0_StateIdle(ActorEx *self) {
    switch (self->fsm->st) {
    case 0: {
        s16 n;
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        n = self->unk_18;
        if (n >= self->unk_1a) {
            Robo021ca458 *p = ActorMgr_FindPlayer();
            ActorSub44 *s;
            if (p == NULL || p->unk_b24_12 != 0) {
                self->unk_18 = n - 1;
                return;
            }
            if (p->unk_b2e < 1) {
                p->unk_b2e = 1;
            }
            func_ov000_02197dec(self, self->unk_18, 5);
            Model0218fe1c_SetAnim(self->model, "nut00", 0x1000, 0);
            s = self->unk_44;
            s->unk_22_0 = 0;
            s->unk_22_1 = 0;
            ActorMgr_BroadcastKind(gActorMgr, 0x540b, 0x15);
            self->fsm->st++;
        } else {
            Model0218fe1c_SetAnim(self->model, "nut00", 0x1000, 0);
            Model0218fe1c_PauseAnim(self->model);
            self->fsm->st = 0xff;
        }
        break;
    }
    case 1: {
        void *a = Model0218fe1c_GetAnimCtrl(self->model, 0);
        if (a == NULL) {
            return;
        }
        if (!AnimCtrl_IsDone(a)) {
            return;
        }
        self->unk_cc_0 = 0;
        self->fsm->st = 0xff;
        break;
    }
    }
}

void Ov003ActVt_021f8cc0_State06(ActorEx *self) {
    Robo021ca458 *p = ActorMgr_FindPlayer();
    u16 x;
    s16 n;
    s16 lim;
    if (p == NULL) {
        return;
    }
    if (p->unk_b24_12 != 0) {
        return;
    }
    x = self->hpObj->unk_04;
    if (x == 0xffff || (x >> 12) != 5) {
        History_SetState(self->fsm, 1, 0);
        return;
    }
    n = self->unk_18 + 1;
    lim = self->unk_1a;
    if (n >= lim) {
        n = lim;
        if (p->unk_b2e < 0x78) {
            p->unk_b2e = 0x78;
        }
    }
    self->unk_18 = n;
    Model0218fe1c_SetAnim(self->model, "act00", 0x1000, 0);
    SndMgr_PlayAt(gSndMgr, 0x6a, &self->pos, 0);
    Field_ShakeCamera(8, 0xf);
    History_SetState(self->fsm, 1, 0);
}

void Ov003ActVt_021f8b90_Start(ActorEx *self) {
    ActorSub44 *p;
    ActorEx_Start(self);
    p = self->unk_44;
    p->unk_0c.x = 0;
    p->unk_0c.y = -0x1800;
    p->unk_0c.z = 0x3000;
}

extern Actor *Group_SpawnActor(void *mgr, GroupActorDesc *desc, VecFx32 *pos, ActorRot *rot, u16 a);
extern void *Spawn_ScatterEffect(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, s32 d);
extern s32 Rand_UpTo(s32 max);

void Ov003ActVt_021f8b90_StateHurt(ActorEx *self) {
    switch (self->fsm->st) {
    case 0: {
        ActorSub44 *s;
        Model0218fe1c_SetAnim(self->model, "dmg00", 0x333, 0);
        Model0218fe1c_SetAnimSpeed(self->model, 0x800);
        SndMgr_PlayAt(gSndMgr, 0x41, &self->pos, 0);
        s16 n;
        s16 lim;
        lim = self->unk_1a;
        n = self->unk_18 + 1;
        self->unk_18 = n;
        if (n >= lim) {
            self->unk_cc_0 = 0;
            s = self->unk_44;
            s->unk_22_0 = 0;
            s->unk_22_1 = 0;
            self->fsm->st = 10;
            return;
        }
        self->fsm->timer = 0;
        self->fsm->st++;
        return;
    }
    case 1: {
        ActorSub40 *w = self->fsm;
        w->timer++;
        if (w->timer <= 10) {
            return;
        }
        History_SetState(self->fsm, 1, 0);
        Model0218fe1c_SetAnim(self->model, "nut00", 0x111, 0);
        return;
    }
    case 10:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            if (self->unk_1c == 0) {
                GroupActorDesc desc;
                VecFx32 p;
                Actor *o;
                s32 id;
                s32 i;
                id = 0x5810;
                if (self->kind == 0x4056) {
                    id++;
                }
                desc.kind = id;
                desc.group = id & 0xf000;
                for (i = 0; i < 4; i++) {
                    desc.args[i] = 0;
                }
                desc.unk_0c = -1;
                p.x = self->unk_44->pos.x;
                p.y = self->unk_44->pos.y;
                p.z = self->unk_44->pos.z;
                o = Group_SpawnActor(gGroup, &desc, &p, &self->rot, 0xffff);
                if (o != NULL) {
                    o->flags_0 = 1;
                }
            }
            self->radius = 0x1000;
            History_SetState(self->fsm, 0x15, 0);
            return;
        }
        if ((self->fsm->timer & 0xf) == 0) {
            VecFx32 sc;
            VecFx32 p;
            sc.x = 0x3000;
            sc.y = 0x2000;
            sc.z = 0x3000;
            p.x = self->unk_44->pos.x;
            p.y = self->unk_44->pos.y;
            p.z = self->unk_44->pos.z;
            Spawn_ScatterEffect(&p, &sc, 0x99a, 0x1000, 0x38b, 0x32);
            Field_ShakeCamera(5, 10);
            SndMgr_PlayAt(gSndMgr, 0x3b, &self->pos, 0);
            if (Rand_UpTo(1)) {
                SndMgr_PlayAt(gSndMgr, 0x3c, &self->pos, 0);
            } else {
                SndMgr_PlayAt(gSndMgr, 0x3d, &self->pos, 0);
            }
        }
        self->fsm->timer++;
        return;
    }
}

}
}  // namespace m_021e3d34

// ---- merged from ov003_021e44dc.cpp
namespace m_021e44dc {

typedef struct {
    s32 m[9];
    s32 tx, ty, tz;
} Ov003BigMtx;

typedef struct {
    u16 unk_00;
    u16 ang;
    VecFx32 v;
} Ov003BigEnt;

extern "C" {

extern void ResSet_SetFile(ActorRes *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern BOOL ResSet_UpdateLoad(ActorRes *res);

void Ov003ActVt_021f8af8_Init(Ov003ActExMesh *self) {
    ActorEx_Init(self);
    const char *name = "gm/g1plt01";
    const char *ext;
    ResSet_SetFile(&self->res, (char *)name, 1, 0, 0, 1);
    ext = "g1plt01e";
    self->res.unk_00 = 0;
    STD_CopyString(self->res2.unk_88, name);
    STD_CopyString(self->res2.unk_a8, ext);
    self->res2.unk_00 = 0;
    self->res2.unk_03_3 = 1;
    self->unk_93_1 = self->unk_18;
    self->unk_b18 = 0;
    if (self->unk_93_1 != 0) {
        self->unk_b18 = self->unk_93_1 - 1;
    }
}
BOOL Ov003ActVt_021f8af8_IsReady(Ov003ActExMesh *self) {
    BOOL r = ActorEx_IsReady(self);
    if (self->res.unk_00 >= 0 && !ResSet_UpdateLoad(&self->res)) {
        r = FALSE;
    }
    if (self->res2.unk_00 >= 0 && !ResSet_UpdateLoad(&self->res2)) {
        r = FALSE;
    }
    return r;
}

extern const s16 FX_SinCosTable_[];
extern const Ov003BigEnt data_ov003_021f5bf0[];
extern BOOL Model0218fe1c_SetRes(Model0218fe1c *m, ActorRes *res, s32 a, s32 b);
extern void Obj02190758_SetRot(Model0218fe1c *m, ActorRot *rot, s32 a);
extern void NNSi_G3dModifyMatFlag(void *mdl, s32 on, u32 flag);
extern void NNSi_G3dModifyPolygonAttrMask(void *mdl, s32 on, u32 mask);
extern void Vec_RotateY(VecFx32 *dst, const VecFx32 *src, u16 angle);
extern void VEC_Add(VecFx32 *a, VecFx32 *b, VecFx32 *dst);
extern void HitMesh_SetRes(Ov003HitMesh *o, u32 res);
extern void MTX_Identity43_(Ov003BigMtx *m);
extern void MTX_RotX43_(Ov003BigMtx *m, s32 s, s32 c);
extern void MTX_RotY43_(Ov003BigMtx *m, s32 s, s32 c);
extern void MTX_RotZ43_(Ov003BigMtx *m, s32 s, s32 c);
extern void MTX_Concat43(Ov003BigMtx *a, Ov003BigMtx *b, Ov003BigMtx *out);
extern void HitMesh_SetMtx(Ov003HitMesh *o, Ov003BigMtx *m);
extern void HitMesh_Link(Ov003HitMesh *o);
extern void HitMesh_Unlink_0203f920(Ov003HitMesh *o);
extern void Ov003ActExMesh_UpdateCopies(Ov003ActExMesh *self, u32 a);

#define OV003BIG_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003BIG_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

static inline void Ov003Big_SetMtx(Ov003HitMesh *o, VecFx32 *v, u16 rx, u16 ry, u16 rz) {
    Ov003BigMtx m;
    Ov003BigMtx t;
    BOOL set = FALSE;
    MTX_Identity43_(&m);
    if (rz != 0) {
        MTX_RotZ43_(&m, OV003BIG_SIN(rz), OV003BIG_COS(rz));
        set = TRUE;
    }
    if (ry != 0) {
        if (set) {
            MTX_RotY43_(&t, OV003BIG_SIN(ry), OV003BIG_COS(ry));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotY43_(&m, OV003BIG_SIN(ry), OV003BIG_COS(ry));
            set = TRUE;
        }
    }
    if (rx != 0) {
        if (set) {
            MTX_RotX43_(&t, OV003BIG_SIN(rx), OV003BIG_COS(rx));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotX43_(&m, OV003BIG_SIN(rx), OV003BIG_COS(rx));
            set = TRUE;
        }
    }
    m.tx = v->x;
    m.ty = v->y;
    m.tz = v->z;
    HitMesh_SetMtx(o, &m);
}

static inline u32 Ov003Big_Res(ActorRes *r) {
    return r->unk_84 != NULL ? *r->unk_84 : 0;
}

void Ov003ActVt_021f8af8_Start(Ov003ActExMesh *self) {
    s32 i;
    ActorEx_Start(self);
    self->unk_cc_0 = 0;
    Model0218fe1c_SetRes(&self->mdl, &self->res, 0, 1);
    self->mdl.actor_id = self->id;
    Obj02190758_SetRot(&self->mdl, &self->rot, 0);
    NNSi_G3dModifyMatFlag(self->mdl.mdl, 1, 0x40);
    NNSi_G3dModifyMatFlag(self->mdl.mdl, 1, 0x80);
    NNSi_G3dModifyMatFlag(self->mdl.mdl, 1, 0x200);
    NNSi_G3dModifyMatFlag(self->mdl.mdl, 1, 0x400);
    self->mdl.restoreMat = 1;
    NNSi_G3dModifyPolygonAttrMask(self->mdl.mdl, 1, 0x1f0000);
    for (i = 0; i < 4; i++) {
        const Ov003BigEnt *e = &data_ov003_021f5bf0[i];
        VecFx32 v;
        u16 ry;
        u16 rz;
        u16 rx;
        u32 r;
        Vec_RotateY(&v, &e->v, self->rot_y);
        VEC_Add(&v, &self->pos, &v);
        ry = self->rot_y + e->ang;
        r = Ov003Big_Res((ActorRes *)self->unk_34);
        rz = self->rot_z;
        rx = self->rot_x;
        HitMesh_SetRes(&self->meshB[i], r);
        Ov003Big_SetMtx(&self->meshB[i], &v, rx, ry, rz);
        if (self->unk_1a == 0 || i <= 1) {
            HitMesh_Link(&self->meshB[i]);
        } else {
            HitMesh_Unlink_0203f920(&self->meshB[i]);
        }
        if (i != 0) {
            ry += 0x8000;
            HitMesh_SetRes(&self->meshC[i - 1], Ov003Big_Res((ActorRes *)self->unk_34));
            Ov003Big_SetMtx(&self->meshC[i - 1], &v, rx, ry, rz);
            HitMesh_Unlink_0203f920(&self->meshC[i - 1]);
            v.x += (s32)(((s64)OV003BIG_SIN(ry) * 0x400 + 0x800) >> 12);
            v.z += (s32)(((s64)OV003BIG_COS(ry) * 0x400 + 0x800) >> 12);
            self->meshCPos[i - 1].x = v.x;
            self->meshCPos[i - 1].y = v.y;
            self->meshCPos[i - 1].z = v.z;
        }
    }
    {
        u32 a = 0;
        if (self->unk_93_1) {
            a = 0xffff;
        }
        Ov003ActExMesh_UpdateCopies(self, a);
    }
}

}
}  // namespace m_021e44dc
#undef OV003BIG_SIN
#undef OV003BIG_COS

// ---- merged from ov003_021e4a94.cpp
namespace m_021e4a94 {

extern "C" {

extern BOOL Model021903b4_Draw(Model0218fe1c *m);

BOOL Ov003ActVt_021f8af8_Draw(Ov003ActExMesh *self) {
    BOOL r = ActorEx_Draw(self);
    s32 i;
    for (i = 0; i < 4; i++) {
        u8 a = self->copyAlpha[i];
        if (a != 0) {
            self->mdl.alpha = a;
            Model_SetScale(&self->mdl, self->copyScale[i]);
            self->mdl.trans.x = self->copyPos[i].x;
            self->mdl.trans.y = self->copyPos[i].y;
            self->mdl.trans.z = self->copyPos[i].z;
            if (Model021903b4_Draw(&self->mdl)) {
                r = TRUE;
            }
        }
    }
    return r;
}

}
}  // namespace m_021e4a94

// ---- merged from ov003_021e4b18.cpp
namespace m_021e4b18 {

typedef struct {
    s32 m[9];
    s32 tx, ty, tz;
} Ov003BigMtx;

typedef struct {
    u16 unk_00;
    u16 ang;
    VecFx32 v;
} Ov003BigEnt;

typedef struct {
    s16 unk_00;
    u16 ang;
    VecFx32 v;
} Ov003BigEnt2;

typedef struct {
    VecFx32 pos;
    u16 unk_0c;
    u16 mask;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    u16 unk_28;
    union { u8 flags; struct { u8 f_0 : 1; u8 f_1 : 1; u8 f_2 : 1; u8 f_3 : 1; } b; };
} Ov003BigQuery;

typedef struct {
    Ov003BigQuery *q;
} Ov003BigFinder;

typedef struct {
    VecFx32 pos;
    u8 unk_0c[4];
    s32 unk_10;
} Ov003BigHit;

typedef struct {
    VecFx32 pos;
    u16 rot[3];
    s32 unk_14;
} Ov003BigWarp;

extern "C" {

extern const s16 FX_SinCosTable_[];
extern const Ov003BigEnt2 data_ov003_021f6230[][4];
extern void Vec_RotateY(VecFx32 *dst, const VecFx32 *src, u16 angle);
extern void VEC_Add(VecFx32 *a, VecFx32 *b, VecFx32 *dst);
extern void HitMesh_SetRes(Ov003HitMesh *o, u32 res);
extern void MTX_Identity43_(Ov003BigMtx *m);
extern void MTX_RotX43_(Ov003BigMtx *m, s32 s, s32 c);
extern void MTX_RotY43_(Ov003BigMtx *m, s32 s, s32 c);
extern void MTX_RotZ43_(Ov003BigMtx *m, s32 s, s32 c);
extern void MTX_Concat43(Ov003BigMtx *a, Ov003BigMtx *b, Ov003BigMtx *out);
extern void HitMesh_SetMtx(Ov003HitMesh *o, Ov003BigMtx *m);
extern void HitMesh_SetScale(Ov003HitMesh *o, s32 a);
extern void HitMesh_Link(Ov003HitMesh *o);
extern void HitMesh_Unlink_0203f920(Ov003HitMesh *o);
extern s32 Geom_SnapToGround(VecFx32 *pos, s32 a, s32 b);
extern s32 Finder_CollectParts(Ov003BigFinder *f, Ov003BigQuery *q, Ov003BigHit **out, s32 max);
extern Actor *Obj021984c8_GetActor(Ov003BigHit *h);
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *model, const char *name, s32 a, s32 b);
extern void Actor_SendMsg(Actor *o, u16 id, s32 a, s32 b, s32 c, void *p);
extern void VEC_MultAdd(s32 a, VecFx32 *v1, VecFx32 *v2, VecFx32 *dst);
extern u16 Angle_Approach(u16 cur, u16 tgt, s32 step, s32 a, s32 b);
void Ov003ActExMesh_UpdateCopies(Ov003ActExMesh *self, u32 t);

static inline void Ov003BigQuery_Init(Ov003BigQuery *q) {
    q->mask = 0;
    q->unk_10 = 0xffff;
    q->unk_12 = 0;
    q->unk_14 = 0;
    q->unk_18 = 0;
    q->unk_1c = 0;
    q->unk_20 = 0;
    q->unk_24 = 0;
    q->unk_28 = 0xffff;
    q->flags = 0;
}

static inline void Ov003Big_Sub(VecFx32 *d, VecFx32 *a, VecFx32 *b) {
    d->x = a->x - b->x;
    d->y = a->y - b->y;
    d->z = a->z - b->z;
}

#define OV003BIG_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003BIG_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

static inline void Ov003Big_SetMtx(Ov003HitMesh *o, VecFx32 *v, u16 rx, u16 ry, u16 rz) {
    Ov003BigMtx m;
    Ov003BigMtx t;
    BOOL set = FALSE;
    MTX_Identity43_(&m);
    if (rz != 0) {
        MTX_RotZ43_(&m, OV003BIG_SIN(rz), OV003BIG_COS(rz));
        set = TRUE;
    }
    if (ry != 0) {
        if (set) {
            MTX_RotY43_(&t, OV003BIG_SIN(ry), OV003BIG_COS(ry));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotY43_(&m, OV003BIG_SIN(ry), OV003BIG_COS(ry));
            set = TRUE;
        }
    }
    if (rx != 0) {
        if (set) {
            MTX_RotX43_(&t, OV003BIG_SIN(rx), OV003BIG_COS(rx));
            MTX_Concat43(&t, &m, &m);
        } else {
            MTX_RotX43_(&m, OV003BIG_SIN(rx), OV003BIG_COS(rx));
            set = TRUE;
        }
    }
    m.tx = v->x;
    m.ty = v->y;
    m.tz = v->z;
    HitMesh_SetMtx(o, &m);
    HitMesh_SetScale(o, 0x119a);
    HitMesh_Link(o);
}

static inline u32 Ov003Big_Res(ActorRes *r) {
    return r->unk_84 != NULL ? *r->unk_84 : 0;
}

static inline void Ov003Big_Approach(Ov003BigWarp *w, Actor *o, Ov003ActExMesh *self) {
    VecFx32 d;
    w->pos.x = o->pos.x;
    w->pos.y = o->pos.y;
    w->pos.z = o->pos.z;
    Ov003Big_Sub(&d, &w->pos, &self->pos);
    VEC_MultAdd(0xc00, &d, &self->pos, &w->pos);
    w->rot[0] = o->rot_x;
    w->rot[1] = o->rot_y;
    w->rot[2] = o->rot_z;
    w->rot[1] = Angle_Approach(self->rot_y, w->rot[1], 0x400, 1, 0x8000);
}

void Ov003ActExMesh_StateIdle(Ov003ActExMesh *self) {
    Actor *found = NULL;
    switch (self->fsm->st) {
    case 0:
        self->target = 0xffff;
        self->fsm->st++;
        break;
    case 1: {
        Ov003BigHit *list[0x20];
        Ov003BigQuery q;
        Ov003BigWarp w;
        Ov003BigFinder f;
        u8 b;
        s32 n;
        u8 kind;
        s32 i;
        Ov003BigQuery_Init(&q);
        q.pos.x = self->pos.x;
        q.pos.y = self->pos.y;
        q.pos.z = self->pos.z;
        q.unk_0c = 0;
        q.unk_28 = self->id;
        q.unk_1c = self->radius + 0x400;
        q.unk_18 = 0;
        q.unk_20 = 0;
        q.unk_24 = 0x2800;
        q.b.f_1 = 1;
        q.b.f_2 = 1;
        q.b.f_3 = 1;
        q.mask = 0x10;
        q.unk_10 = 0xffff;
        f.q = NULL;
        n = Finder_CollectParts(&f, &q, list, 0x20);
        kind = 0;
        for (i = 0; i < n; i++) {
            Ov003BigHit *h = list[i];
            if (h != NULL && h->pos.y - h->unk_10 - self->pos.y - self->height <= 0x666) {
                Actor *o = Obj021984c8_GetActor(h);
                if (o != NULL) {
                    u8 k = 0;
                    if (o->kind == 0x404b) {
                        k = 1;
                    } else if (o->kind == 0x404c) {
                        k = 2;
                    } else if (o->kind == 0x404d) {
                        k = 3;
                    }
                    if (k != 0) {
                        if (self->target == o->id) {
                            kind = k;
                            found = o;
                            break;
                        }
                        if (k == self->unk_93_1) {
                            kind = k;
                            found = o;
                        } else if (kind == 0 && found == NULL) {
                            kind = k;
                            found = o;
                        }
                    }
                }
            }
        }
        if (self->unk_93_1 != kind) {
            if (kind != 0 && self->unk_93_1 == 0) {
                Model0218fe1c_SetAnim(self->model, "on00", 0x1000, 0);
                SndMgr_PlayAtPitch(gSndMgr, 0xd, &self->pos, -0xf);
                self->target = found->id;
                self->unk_93_1 = kind;
                self->unk_18 = kind;
                b = 0;
                Actor_SendMsg(found, self->id, 0xd, 1, 1, &b);
                self->unk_b18 = self->unk_93_1 - 1;
                self->fsm->st = 10;
            } else {
                Model0218fe1c_SetAnim(self->model, "off00", 0x1000, 0);
                SndMgr_PlayAtPitch(gSndMgr, 0xd, &self->pos, -0xf);
                self->unk_18 = 0;
                self->unk_93_1 = 0;
                self->target = 0xffff;
                for (i = 0; i < 3; i++) {
                    HitMesh_Unlink_0203f920(&self->meshC[i]);
                }
                for (i = 0; i < 4; i++) {
                    if (self->unk_1a == 0 || i <= 1) {
                        HitMesh_Link(&self->meshB[i]);
                    }
                }
                self->fsm->st = 20;
            }
        }
        if (self->unk_93_1 != 0 && found != NULL) {
            self->target = found->id;
            w.unk_14 = 0;
            Ov003Big_Approach(&w, found, self);
            Actor_SendMsg(found, self->id, 7, 1, 0x18, &w);
            HitMesh_Unlink_0203f920(&self->meshC[self->unk_b18]);
            if (Geom_SnapToGround(&self->meshCPos[self->unk_b18], 0x1000, -0x5000) == -0x1000) {
                HitMesh_Link(&self->meshC[self->unk_b18]);
            }
        }
        break;
    }
    case 10: {
        Ov003BigWarp w;
        Actor *o = Actor_GetTarget(self);
        ActorSub40 *wk;
        if (o == NULL) {
            self->fsm->st = 0;
            break;
        }
        w.unk_14 = 0;
        wk = self->fsm;
        wk->timer++;
        if (wk->timer < 6) {
            Ov003Big_Approach(&w, o, self);
        } else {
            w.pos.x = self->pos.x;
            w.pos.y = self->pos.y;
            w.pos.z = self->pos.z;
            w.pos.y -= 0x800;
            w.rot[0] = self->rot_x;
            w.rot[1] = self->rot_y;
            w.rot[2] = self->rot_z;
            self->fsm->st++;
            self->fsm->timer = 0;
        }
        Actor_SendMsg(o, self->id, 7, 1, 0x18, &w);
        break;
    }
    case 11: {
        ActorSub40 *wk = self->fsm;
        wk->timer++;
        if (wk->timer > 0x24) {
            Actor *o = Actor_GetTarget(self);
            if (o != NULL) {
                u8 b = 1;
                Actor_SendMsg(o, self->id, 0xd, 1, 1, &b);
            }
            self->fsm->timer = 0xffff;
            self->fsm->st = 1;
        }
        Ov003ActExMesh_UpdateCopies(self, self->fsm->timer);
        break;
    }
    case 20:
        self->fsm->timer = 0x24;
        self->fsm->st++;
    case 21: {
        ActorSub40 *wk = self->fsm;
        if (wk->timer != 0) {
            wk->timer--;
        }
        if (wk->timer == 0) {
            self->fsm->st = 0;
        }
        Ov003ActExMesh_UpdateCopies(self, self->fsm->timer);
        break;
    }
    }
}

void Ov003ActExMesh_UpdateCopies(Ov003ActExMesh *self, u32 t) {
    VecFx32 v;
    if (t == 0) {
        s32 i;
        for (i = 0; i < 4; i++) {
            self->copyPos[i].x = self->pos.x;
            self->copyPos[i].y = self->pos.y;
            self->copyPos[i].z = self->pos.z;
            self->copyScale[i] = 0;
            self->copyAlpha[i] = 0;
            HitMesh_Unlink_0203f920(&self->meshA[i]);
        }
        for (i = 0; i < 3; i++) {
            HitMesh_Unlink_0203f920(&self->meshC[i]);
        }
        for (i = 0; i < 4; i++) {
            if (self->unk_1a == 0 || i <= 1) {
                HitMesh_Link(&self->meshB[i]);
            }
        }
    } else if (t == 0xffff) {
        s32 i;
        HitMesh_Unlink_0203f920(&self->meshB[0]);
        HitMesh_Unlink_0203f920(&self->meshB[self->unk_b18 + 1]);
        HitMesh_Unlink_0203f920(&self->meshC[self->unk_b18]);
        if (Geom_SnapToGround(&self->meshCPos[self->unk_b18], 0x1000, -0x5000) == -0x1000) {
            HitMesh_Link(&self->meshC[self->unk_b18]);
        }
        for (i = 0; i < 4; i++) {
            const Ov003BigEnt2 *e = &data_ov003_021f6230[self->unk_b18][i];
            if (e->unk_00 >= 0) {
                u16 rz;
                u16 rx;
                u16 ry;
                u32 r;
                Vec_RotateY(&v, &e->v, self->rot_y);
                VEC_Add(&v, &self->pos, &v);
                self->copyPos[i].x = v.x;
                self->copyPos[i].y = v.y;
                self->copyPos[i].z = v.z;
                self->copyScale[i] = 0x1000;
                self->copyAlpha[i] = 0x1f;
                rz = self->rot_z;
                ry = self->rot_y + e->ang;
                rx = self->rot_x;
                {
                    ActorRes *q = &self->res;
                    if (e->unk_00 != 0) {
                        q = &self->res2;
                    }
                    r = Ov003Big_Res(q);
                }
                HitMesh_SetRes(&self->meshA[i], r);
                Ov003Big_SetMtx(&self->meshA[i], &v, rx, ry, rz);
            } else {
                self->copyAlpha[i] = 0;
            }
        }
    } else {
        if (t <= 12 && data_ov003_021f6230[self->unk_b18][0].unk_00 >= 0) {
            Vec_RotateY(&v, &data_ov003_021f6230[self->unk_b18][0].v, self->rot_y);
            VEC_Add(&v, &self->pos, &self->copyPos[0]);
            self->copyScale[0] = (s32)(t << 12) / 12;
            self->copyAlpha[0] = (s32)(t * 31) / 12;
        }
        if (t >= 6 && t <= 18 && data_ov003_021f6230[self->unk_b18][1].unk_00 >= 0) {
            Vec_RotateY(&v, &data_ov003_021f6230[self->unk_b18][1].v, self->rot_y);
            VEC_Add(&v, &self->pos, &self->copyPos[1]);
            self->copyScale[1] = (s32)((t - 6) << 12) / 12;
            self->copyAlpha[1] = (s32)((t - 6) * 31) / 12;
        }
        if (t >= 12 && t <= 24 && data_ov003_021f6230[self->unk_b18][2].unk_00 >= 0) {
            Vec_RotateY(&v, &data_ov003_021f6230[self->unk_b18][2].v, self->rot_y);
            VEC_Add(&v, &self->pos, &self->copyPos[2]);
            self->copyScale[2] = (s32)((t - 12) << 12) / 12;
            self->copyAlpha[2] = (s32)((t - 12) * 31) / 12;
        }
        if (t >= 18 && t <= 30 && data_ov003_021f6230[self->unk_b18][3].unk_00 >= 0) {
            Vec_RotateY(&v, &data_ov003_021f6230[self->unk_b18][3].v, self->rot_y);
            VEC_Add(&v, &self->pos, &self->copyPos[3]);
            self->copyScale[3] = (s32)((t - 18) << 12) / 12;
            self->copyAlpha[3] = (s32)((t - 18) * 31) / 12;
        }
    }
}

}
}  // namespace m_021e4b18
#undef OV003BIG_SIN
#undef OV003BIG_COS

// ---- merged from ov003_021e57b8.cpp
namespace m_021e57b8 {

typedef struct {
    u8 unk_00[0x2c];
    u32 unk_2c;
} Ov003ColState;

extern "C" {

extern Ov003ColState gHitResult;
extern char Ov003ActVt_021f8768_vtbl[];
extern s32 Geom_SnapToGround(VecFx32 *pos, s32 a, s32 b);
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *model, const char *name, s32 a, s32 b);
extern void Model0218fe1c_SetLoop(Model0218fe1c *model);
extern void Body_Update(ActorSub48 *ctl, s32 a, s32 b, s32 c);
extern BOOL History_SetState(ActorSub40 *p, s32 a, s32 b);
extern void Heap_Free(void *p);
extern const char *const data_ov003_021f4c64[2];
extern char *Tbl_GetResFile(u16 id);
extern char *Path_SkipDir(char *p);
extern BOOL OS_IsRunOnTwl(void);
extern void *Heap_Alloc(u32 size);
extern BOOL ResSet_UpdateLoad(ActorRes *res);
extern void ActorMarker_Draw(void *p);
extern void *gGroup;
extern void *NNS_G3dGetTex(void *p);
extern void *G3dRes_QueueTexUpload(void *a, void *b);
extern void *NNS_G3dGetMdlSet(void *p);
extern BOOL NNS_G3dBindMdlSet(void *a, void *b);
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);
extern s32 Rand_PlusMinus(s32 max);

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
    FieldState *g = gSceneCmd;
    if (g != NULL) {
        return Ov003Game_IsIdle(g);
    }
    return TRUE;
}

static inline BOOL Ov003Game_HasEvent(FieldState *g) {
    return g->event != 0 ? TRUE : FALSE;
}

static inline BOOL Ov003_GameHasD4(void) {
    return Ov003Game_HasEvent(gSceneCmd) ? TRUE : FALSE;
}

void Ov003ActVt_021f8930_Start(ActorEx *self) {
    ActorEx_Start(self);
    if (Geom_SnapToGround(&self->pos, 0x1000, -0xa000) == -0x1000) {
        return;
    }
    self->hit->unk_54 |= gHitResult.unk_2c;
}

void Ov003ActVt_021f8898_Update(Ov003ActExWalk *self) {
    if (self->fsm->current == 9) {
        return;
    }
    func_ov000_02197ee0(self, &self->ai, 0x2cd, 0x333, 0x8800);
}

void Ov003ActExWalk_StateMove(Ov003ActExWalk *self) {
    VecFx32 v;
    if (self->fsm->st == 0) {
        Model0218fe1c_SetAnim(self->model, "run00", 0x2ab, 0);
        Model0218fe1c_SetLoop(self->model);
        self->fsm->st++;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
    }
    self->hit->unk_9a |= 0x20;
    self->speed = 0x2cd;
    v.x = self->ai.pos.x;
    v.y = self->ai.pos.y;
    v.z = self->ai.pos.z;
    Actor_MoveToPos(self, &v, 0x333);
    Body_Update(self->hit, 1, 0, 0);
    if (self->hit->unk_50 & 0x20000000) {
        return;
    }
    History_SetState(self->fsm, 4, 0);
}

Ov003ActExTex *Ov003ActVt_021f8768_Dtor(Ov003ActExTex *self) {
    void *old;
    Twl0214b570 *p;
    *(void **)self = Ov003ActVt_021f8768_vtbl;
    old = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    p = self->tex;
    if (p != NULL) {
        if (p != NULL) {
            Twl0214b570_Dtor(p);
            Heap_Free(p);
        }
        self->tex = NULL;
    }
    gSysState->cur = old;
    ResSet_ReleaseAll(&self->res);
    ActorEx_DtorBase(self);
    return self;
}

Ov003ActExTex *Ov003ActVt_021f8768_DtorDelete(Ov003ActExTex *self) {
    void *old;
    Twl0214b570 *p;
    *(void **)self = Ov003ActVt_021f8768_vtbl;
    old = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    p = self->tex;
    if (p != NULL) {
        if (p != NULL) {
            Twl0214b570_Dtor(p);
            Heap_Free(p);
        }
        self->tex = NULL;
    }
    gSysState->cur = old;
    ResSet_ReleaseAll(&self->res);
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

void Ov003ActVt_021f8768_Init(Ov003ActExTex *self) {
    char buf[0x20];
    ActorEx_Init(self);
    if (self->unk_1c != 0) {
        u16 id = self->kind;
        char *r;
        const char *t;
        if (self->unk_1c == 3) {
            id = 0x4053;
        }
        STD_CopyString(buf, Tbl_GetResFile(id));
        STD_ConcatenateString(buf, "c");
        r = Path_SkipDir(buf);
        STD_CopyString(self->res.unk_100, buf);
        STD_CopyString(self->res.unk_120, r);
        t = NULL;
        self->res.unk_00 = 0;
        self->res.unk_03_5 = 1;
        if (OS_IsRunOnTwl()) {
            if ((u16)(s16)(self->unk_1c - 1) <= 1) {
                if (id == 0x4053) {
                    t = data_ov003_021f4c64[1];
                } else if (id == 0x4054) {
                    t = data_ov003_021f4c64[0];
                }
                if (t != NULL) {
                    Twl0214b570 *p = (Twl0214b570 *)Heap_Alloc(sizeof(Twl0214b570));
                    if (p != NULL) {
                        p = Twl0214b570_Init(p);
                    }
                    self->tex = p;
                    Twl0214b570_Start(p, t);
                }
            }
        }
    }
    self->msgWin = NULL;
    self->texFailed = 0;
}

BOOL Ov003ActVt_021f8768_IsReady(Ov003ActExTex *self) {
    BOOL r = ActorEx_IsReady(self);
    if (self->unk_1c != 0 && self->texFailed == 0) {
        if (self->res.unk_00 >= 0 && !ResSet_UpdateLoad(&self->res)) {
            r = FALSE;
        }
        if (self->tex != NULL) {
            if (Twl0214b570_GetStatus(self->tex) == 2) {
                r = FALSE;
                self->texFailed = 1;
            }
            if (r && !Twl0214b570_IsDone(self->tex)) {
                Twl0214b570_Poll(self->tex);
                r = FALSE;
            }
        }
    }
    return r;
}

void Ov003ActVt_021f8768_Start(Ov003ActExTex *self) {
    Ov003Unit *u;
    ActorEx_Start(self);
    if (self->unk_1c != 0 && self->texFailed == 0) {
        void *h;
        if (self->res.unk_fc == NULL) {
            h = NULL;
        } else {
            h = NNS_G3dGetTex(*self->res.unk_fc);
        }
        if (h != NULL) {
            if (self->unk_1c != 3) {
                if (self->tex != NULL) {
                    void *x = Twl0214b570_GetResult(self->tex);
                    if (x != NULL) {
                        G3dRes_QueueTexUpload(*self->res.unk_fc, x);
                    }
                }
            } else if (self->unk_60 != NULL) {
                G3dRes_QueueTexUpload(*self->res.unk_fc, self->unk_60);
            }
            NNS_G3dBindMdlSet(NNS_G3dGetMdlSet(self->model->res->mdl_handle != NULL ? self->model->res->mdl_handle->unk_00 : NULL), h);
        }
    }
    u = Group_FindNode(gGroup, self->unk_20);
    if (u != NULL) {
        u->unk_a2_0 = 0;
    }
    self->unk_cc_3 = 0;
    if (self->unk_1e != 0) {
        s32 x;
        s32 y;
        s32 z;
        if (self->unk_44 != NULL) {
            void *old = gSysState->cur;
            gSysState->cur = gSysState->heapHi;
            if (self->unk_44 != NULL) {
                Heap_Free(self->unk_44);
                self->unk_44 = NULL;
            }
            gSysState->cur = old;
        }
        if (self->unk_1e == 2) {
            y = Rand_PlusMinus(0x4000) - 0x2000;
            x = Rand_PlusMinus(0x9000);
            z = -0x32000;
            self->unk_84.x = x;
            self->unk_84.y = y;
            self->unk_84.z = z;
        } else {
            y = Rand_PlusMinus(0x2000) - 0x4000;
            x = Rand_PlusMinus(0x6000);
            z = -0x14000;
            self->unk_84.x = x;
            self->unk_84.y = y;
            self->unk_84.z = z;
        }
    } else if (self->unk_18 <= 0) {
        self->model->visible = 0;
    } else {
        History_SetState(self->fsm, 6, 0);
        self->unk_93_1 = (u8)self->unk_18;
    }
    if (self->kind == 0x406a && gSceneCmd->unk_ca.c[0] == 0x10) {
        Model0218fe1c *m = self->model;
        m->scale.x = 0x1800;
        m->scale.y = 0x1800;
        m->scale.z = 0x1800;
    }
}

BOOL Ov003ActVt_021f8768_Draw(Ov003ActExTex *self) {
    BOOL r = ActorEx_Draw(self);
    if (self->unk_5c != NULL && Ov003_GameIdle() && !Ov003_GameHasD4()) {
        ActorMarker_Draw(self->unk_5c);
    }
    return r;
}

}
}  // namespace m_021e57b8

// ---- merged from ov003_021e5e70.cpp
namespace m_021e5e70 {

typedef struct {
    s32 m[9];
} Ov003BarMtx;

typedef struct {
    u8 unk_00[0x16];
    u16 unk_16;
} Ov003BarSnd;

extern "C" {

extern int gFadeState[];
extern void *UiObj_vtbl[];
extern void *Lo021cad50_vtbl[];
extern void *gMsgRes;
extern void *gActorMgr;
extern const VecFx32 data_02092a50;
extern void *Heap_Alloc(u32 size);
extern const char *MsgRes_GetString(void *mgr, s32 id);
extern void Obj0215c1bc_SetText(Lo021cad50 *a, s32 b, const char *c);
extern void SceneCmd_Push27(void *p, s32 a, s32 b, s32 c);
extern Ov003BarSnd *ActorMgr_GetGroup(void *mgr, u16 id);
extern BOOL AnimCtrl_SetAnimByIndex(AnimCtrl *self, void *obj, void *tex, void *file, s32 index, s16 blend, u8 force);
extern Ov003BarMtx *NNS_G3dGlbGetInvV(void);
extern void VEC_Add(VecFx32 *a, VecFx32 *b, VecFx32 *dst);

static inline BOOL Ov003Bar_FadeIdle(void) {
    if (gFadeState[3] == 0 && gFadeState[0] == 0) {
        return TRUE;
    }
    return FALSE;
}

static inline void Ov003Bar_Init(Lo021cad50 *b) {
    b->flags |= 8;
    b->color = 0x14a5;
    b->unk_54 = 0x1c;
}

void Ov003ActVt_021f8768_StateIdle(Ov003ActExTex *self) {
    if (self->texFailed != 0) {
        Lo021cad50 *b;
        if (!Ov003Bar_FadeIdle()) {
            return;
        }
        if (self->msgWin == NULL) {
            b = (Lo021cad50 *)Heap_Alloc(0xe8);
            if (b != NULL) {
                *(void ***)b = UiObj_vtbl;
                b->vfunc_28();
                *(void ***)b = Lo021cad50_vtbl;
                b->vfunc_28();
            }
            self->msgWin = b;
            b->flags |= 0x10000;
            Ov003Bar_Init(self->msgWin);
            self->msgWin->flags |= 0x20000;
            self->msgWin->font = 4;
            self->msgWin->vfunc_08();
            Obj0215c1bc_SetText(self->msgWin, 0x8000, MsgRes_GetString(gMsgRes, 0x76));
            self->msgWin->posZ = -0x299a;
            self->msgWin->vfunc_70();
            SceneCmd_Push27(gSceneCmd, 0xffff, 0, 0);
        } else {
            self->msgWin->vfunc_1c();
            self->msgWin->vfunc_20();
        }
        return;
    }
    switch (self->fsm->st) {
    case 0:
        if (self->unk_1e == 0) {
            Ov003BarSnd *s;
            ActorSub44 *p;
            if (self->unk_44 == NULL) {
                return;
            }
            s = ActorMgr_GetGroup(gActorMgr, 0x5000);
            if (s == NULL) {
                return;
            }
            p = self->unk_44;
            if (s->unk_16 != 0) {
                p->unk_22_0 = 0;
                p->unk_22_1 = 0;
                return;
            }
            p->unk_22_0 = 1;
            p->unk_22_1 = 1;
            return;
        }
        if (self->unk_1e == 2) {
            self->vel.x = 0;
            self->vel.y = 0;
            self->vel.z = 0x8cd;
        } else {
            self->vel.x = 0;
            self->vel.y = 0;
            self->vel.z = 0x59a;
        }
        self->fsm->st = 10;
    case 10: {
        s32 z = self->unk_84.z;
        Ov003BarMtx *m;
        s32 x;
        s32 y;
        if (z < 0x2800) {
        if (z > -0x1800) {
            self->model->alpha = ((0x2800 - z) * 31) / 0x4000;
            Model_StopAnim(self->model);
        } else if (z < -0xf000) {
            self->model->alpha = ((z + 0x14000) * 31) / 0x5000;
            Model_StopAnim(self->model);
        } else {
            Model0218fe1c *md = self->model;
            if (md->unk_10 != NULL) {
                AnimCtrl_SetAnimByIndex(md->unk_10, md->renderObj, md->tex, md->res->anims->list[1], 0, 0x1000, 0);
            }
        }
        VEC_Add(&self->unk_84, &self->vel, &self->unk_84);
        m = NNS_G3dGlbGetInvV();
        y = self->unk_84.y;
        x = self->unk_84.x;
        z = self->unk_84.z;
        self->pos.x = (s32)(((s64)x * m->m[0] + (s64)y * m->m[3] + (s64)z * m->m[6]) >> 12);
        self->pos.y = (s32)(((s64)x * m->m[1] + (s64)y * m->m[4] + (s64)z * m->m[7]) >> 12);
        self->pos.z = (s32)(((s64)x * m->m[2] + (s64)y * m->m[5] + (s64)z * m->m[8]) >> 12);
        VEC_Add(&self->pos, &data_02092a50, &self->pos);
        } else {
            self->vfunc_08();
        }
        break;
    }
    }
}

}
}  // namespace m_021e5e70

// ---- merged from ov003_021e6274.cpp
namespace m_021e6274 {

extern "C" {

extern void *gGroup;
extern Actor *Target_Get(ActorSub4c *p);
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *model, const char *name, s32 a, s32 b);
extern void Model0218fe1c_SetAnimByIndex(Model0218fe1c *model, s32 a, s32 b, s32 c);
extern void Model0218fe1c_SetLoop(Model0218fe1c *model);
extern void Model0218fe1c_ClearLoop(Model0218fe1c *model);
extern void *Model0218fe1c_SetAnimFrame(Model0218fe1c *model, s32 a);
extern BOOL Model0218fe1c_IsAnimDone(Model0218fe1c *model);
extern void Actor_SendMsg(Actor *p, u16 a, s32 b, s32 c, s32 d, s32 e);
extern void Shared_SetEventActor(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern void func_020627ec(s32 a);
extern s32 Rand_UpTo(s32 max);
extern void Group_UpdateActor(void *mgr, s32 a, Actor *obj);
extern BOOL History_SetState(ActorSub40 *p, s32 a, s32 b);
extern void Model0218fe1c_StopAnim(Model0218fe1c *p);

static inline void ActorSub44_Clear(ActorSub44 *s) {
    if (s != NULL) {
        s->unk_22_0 = 0;
        s->unk_22_1 = 0;
    }
}

static inline s32 Bit6274(ActorEx *o, u32 i) {
    return o->unk_1a & (1 << i);
}

void Ov003ActVt_021f8768_State06(ActorEx *self) {
    u8 n = 0;
    Actor *t;
    t = Target_Get(self->targetObj);
    switch (self->fsm->st) {
    case 0:
        if (self->unk_18 == 0) {
            self->unk_18 = 1;
            self->unk_93_1 = 1;
            func_ov000_02197dec(self, 1, -1);
            self->model->visible = 1;
            if (self->kind == 0x4057) {
                Model0218fe1c_SetAnim(self->model, "nut00", 0x1000, 0);
            } else {
                Model0218fe1c_SetAnimByIndex(self->model, n, 0x1000, 0);
            }
            if (self->unk_1a & 1) {
                Model0218fe1c_SetLoop(self->model);
            } else {
                Model0218fe1c_ClearLoop(self->model);
            }
            SndMgr_PlayAtPitch(gSndMgr, 0x85, &self->pos, -0xf);
        } else {
            n = self->unk_18 - 1;
            Model0218fe1c_SetAnimByIndex(self->model, n, 0x1000, 0);
            if (self->unk_1a & (1 << n)) {
                Model0218fe1c_SetLoop(self->model);
            } else {
                Model0218fe1c_ClearLoop(self->model);
                Model0218fe1c_SetAnimFrame(self->model, -1);
            }
        }
        ActorSub44_Clear(self->unk_44);
        self->fsm->st++;
        break;
    case 1:
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            return;
        }
        if (t != NULL) {
            Actor_SendMsg(t, self->id, 3, 1, 0, 0);
        }
        self->targetObj->target = 0xffff;
        Shared_SetEventActor(self->kind, self->id);
        func_020627dc(4);
        func_020627ec(self->unk_93_1);
        gSceneCmd->stageFlags = 1;
        self->fsm->st++;
        break;
    case 2:
        n = self->unk_18;
        if (n == self->unk_93_1 || n == 0) {
            return;
        }
        func_ov000_02197dec(self, n, -1);
        self->unk_93_1 = n;
        n--;
        Model0218fe1c_SetAnimByIndex(self->model, n, 0x1000, 0);
        if (Bit6274(self, n)) {
            Model0218fe1c_SetLoop(self->model);
        } else {
            Model0218fe1c_ClearLoop(self->model);
        }
        self->fsm->st = 1;
        break;
    }
}

void Ov003ActVt_021f8768_State21(ActorEx *self) {
    switch (self->fsm->st) {
    case 0:
        Model_StopAnim(self->model);
        self->model->alpha = 20;
        self->fsm->st++;
    case 1: {
        u8 a;
        ActorSub40 *w = self->fsm;
        u16 t;
        w->timer++;
        t = w->timer;
        a = 20 - t;
        a -= (u8)Rand_UpTo(5);
        self->model->alpha = a;
        if (t <= 12) {
            return;
        }
        func_020627ec(100);
        func_ov000_02197dec(self, 0xf, 4);
        Group_UpdateActor(gGroup, 0, self);
        self->vfunc_08();
        break;
    }
    }
}

void Ov003ActVt_021f86d0_Start(ActorEx *self) {
    ActorEx_Start(self);
    History_SetState(self->fsm, 0x20, 0);
    Model0218fe1c_StopAnim(self->model);
}

void Ov003ActVt_021f86d0_State20(ActorEx *self) {
    switch (self->fsm->st) {
    case 0:
        SndMgr_PlayAtPitch(gSndMgr, 0x25, &self->pos, -0xf);
        self->fsm->st++;
    case 1: {
        ActorSub40 *w = self->fsm;
        u16 t;
        w->timer++;
        t = w->timer;
        self->model->alpha = t;
        Model_SetScale(self->model, 0x3000 - t * 0x19a);
        if (t <= 20) {
            return;
        }
        Shared_SetEventActor(self->kind, self->id);
        func_020627dc(4);
        func_020627ec(1);
        gSceneCmd->stageFlags = 1;
        History_SetState(self->fsm, 1, 0);
        break;
    }
    }
}

void Ov003ActVt_021f86d0_State21(ActorEx *self) {
    switch (self->fsm->st) {
    case 0:
        Model_StopAnim(self->model);
        self->fsm->st++;
    case 1: {
        ActorSub40 *w = self->fsm;
        u16 t;
        s32 s;
        w->timer++;
        t = w->timer;
        s = t * 0x7b;
        self->model->alpha = 25 - t;
        Model_SetScale3(self->model, s + 0x1000, (s >> 1) + 0x1000, s + 0x1000);
        if (t <= 15) {
            return;
        }
        self->fsm->st++;
        self->fsm->timer = 0;
        break;
    }
    case 2: {
        ActorSub40 *w = self->fsm;
        u16 t;
        s32 s;
        w->timer++;
        t = w->timer;
        s = t * 0x252;
        self->model->alpha = 15 - t;
        Model_SetScale3(self->model, 0x1733 - s, s + 0x1733, 0x1733 - s);
        if (t <= 10) {
            return;
        }
        Shared_SetEventActor(self->kind, self->id);
        func_020627dc(4);
        func_020627ec(100);
        gSceneCmd->stageFlags = 1;
        Group_UpdateActor(gGroup, 0, self);
        self->vfunc_08();
        break;
    }
    }
}

}
}  // namespace m_021e6274

// ---- merged from ov003_021e694c.cpp
namespace m_021e694c {

extern "C" {

// A point of a path (data_ov003_021f85c0[Actor::unk_1a]): the actor moves to pos at speed, waits
// there and goes on to point next (ActorEx::unk_ce; negative: stop).
typedef struct {
    VecFx32 pos;
    s16 speed;
    u8 wait;
    s8 next;
} Ov003PathPt;

extern void *gGroup;
extern Ov003PathPt *data_ov003_021f85c0[];
extern Ov003Unit *Group_FindNode(void *mgr, u16 id);

void Ov003ActVt_021f8f20_Start(Ov003ActExPath *self) {
    Ov003Unit *u;
    Ov003PathPt *p;
    ActorEx_Start(self);
    u = Group_FindNode(gGroup, self->unk_20);
    if (u != NULL) {
        u->unk_a2_5 = 1;
        u->unk_a2_0 = 0;
        u->unk_a2_6 = 0;
    }
    if (self->targetObj != NULL) {
        self->targetObj->unk_18_5 = 1;
    }
    self->unk_ce_s = 0;
    p = data_ov003_021f85c0[self->unk_1a];
    if (p != NULL) {
        self->pos.x = p[self->unk_ce_s].pos.x;
        self->pos.y = p[self->unk_ce_s].pos.y;
        self->pos.z = p[self->unk_ce_s].pos.z;
    }
}

BOOL Ov003ActVt_021f8f20_Draw(Ov003ActExPath *self) {
    BOOL r = FALSE;
    if (self->model->alpha != 0) {
        r = ActorEx_Draw(self);
    }
    return r;
}

extern Robo021ca458 *ActorMgr_FindPlayer(void);
extern void HitSphere_Unlink_0203f364(ActorSub48 *hit);
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *model, const char *name, s32 a, s32 b);
extern void Model0218fe1c_SetLoop(Model0218fe1c *model);
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *model, s32 v);
extern void VEC_Normalize(VecFx32 *src, VecFx32 *dst);
extern void VEC_Add(VecFx32 *a, VecFx32 *b, VecFx32 *dst);
extern BOOL Hit_DiffInSphere(VecFx32 *a, VecFx32 *b, s32 r);
extern BOOL History_SetState(ActorSub40 *p, s32 a, s32 b);

void Ov003ActVt_021f8f20_StateIdle(Ov003ActExPath *self) {
    Robo021ca458 *pl;
    Ov003PathPt *pt;
    ActorSub40 *w;
    s32 snd;
    if (self->unk_ce_s < 0) {
        return;
    }
    pt = data_ov003_021f85c0[self->unk_1a];
    if (pt == NULL) {
        return;
    }
    pl = ActorMgr_FindPlayer();
    if (pl != NULL) {
        u8 a;
        self->target = pl->id;
        a = self->model->alpha;
        if (pl->unk_93_4) {
            ActorSub44 *s = self->unk_44;
            ActorSub48 *hit;
            if (s != NULL) {
                s->unk_22_1 = 0;
            }
            hit = self->hit;
            if (hit != NULL) {
                hit->unk_9a_3 = 0;
                HitSphere_Unlink_0203f364(hit);
            }
            if (a != 0) {
                self->model->alpha = a - 1;
            }
        } else if (a < 0x1f) {
            self->model->alpha = a + 1;
        }
    }
    pt = &pt[self->unk_ce_s];
    w = self->fsm;
    switch (w->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, "nut00", 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        Model0218fe1c_SetAnimSpeed(self->model, 0x2800);
        self->targetObj->target = 0xffff;
        self->unk_cc_8 = 0;
        self->fsm->st++;
    case 1: {
        VecFx32 *v = &self->vel;
        s32 sp;
        v->x = pt->pos.x - self->pos.x;
        v->y = pt->pos.y - self->pos.y;
        v->z = pt->pos.z - self->pos.z;
        VEC_Normalize(v, v);
        sp = pt->speed;
        v->x = (s32)(((s64)v->x * sp + 0x800) >> 12);
        v->y = (s32)(((s64)v->y * sp + 0x800) >> 12);
        v->z = (s32)(((s64)v->z * sp + 0x800) >> 12);
        VEC_Add(&self->pos, v, &self->pos);
        if (Hit_DiffInSphere(&self->pos, &pt->pos, pt->speed << 3)) {
            self->fsm->st++;
            self->fsm->timer = pt->wait;
            self->unk_ce_s = pt->next;
            Model0218fe1c_SetAnimSpeed(self->model, 0x1000);
        }
        break;
    }
    case 2: {
        VecFx32 *v = &self->vel;
        if (w->timer != 0) {
            w->timer--;
        }
        if (w->timer == 0) {
            self->fsm->st = 0;
        }
        v->x = (s32)(((s64)v->x * 0x59a + 0x800) >> 12);
        v->y = (s32)(((s64)v->y * 0x59a + 0x800) >> 12);
        v->z = (s32)(((s64)v->z * 0x59a + 0x800) >> 12);
        VEC_Add(&self->pos, v, &self->pos);
        break;
    }
    }
    snd = 0x133;
    if (self->unk_1c == 2) {
        if (pl != NULL && Hit_DiffInSphere(&pl->pos, &self->pos, pl->radius + 0x2000)) {
            History_SetState(self->fsm, 0xe, 0);
        }
        snd = 0xcd;
    }
    Actor_TurnToPos(self, &pt->pos, snd);
}

}
}  // namespace m_021e694c

// ---- merged from ov003_021e6cb8.cpp
namespace m_021e6cb8 {

extern "C" {

extern void *gGroup;
extern void *gActorMgr;
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *model, const char *name, s32 a, s32 b);
extern void Model0218fe1c_SetLoop(Model0218fe1c *model);
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *model, s32 a);
extern BOOL Model0218fe1c_IsAnimDone(Model0218fe1c *model);
extern void HitSphere_Link(ActorSub48 *hit);
extern BOOL History_SetState(ActorSub40 *p, s32 a, s32 b);
extern void Group_UpdateActor(void *mgr, s32 a, Actor *obj);
extern Actor *Target_Get(ActorSub4c *p);
extern s32 Rand_PlusMinus(s32 max);
extern Actor *ActorMgr_GetActor(void *mgr, u16 id);

static inline void ActorSub44_Set(ActorSub44 *s) {
    if (s != NULL) {
        s->unk_22_0 = 1;
        s->unk_22_1 = 1;
    }
}

static inline Actor *Ov003_FindObj(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

void Ov003ActVt_021f8f20_State0a(Ov003ActExPath *self) {
    switch (self->fsm->st) {
    case 0: {
        ActorSub48 *hit;
        EffectObj *fx;
        self->targetObj->target = 0xffff;
        Model0218fe1c_SetAnim(self->model, "nut00", 0x1000, 0);
        Model0218fe1c_SetLoop(self->model);
        Model0218fe1c_SetAnimSpeed(self->model, 0x2800);
        hit = self->hit;
        if (hit != NULL) {
            hit->unk_9a_0 = 1;
            hit->unk_9a_3 = 1;
            HitSphere_Link(hit);
        }
        ActorSub44_Set(self->unk_44);
        if (!self->unk_cc_8) {
            History_SetState(self->fsm, 1, 0);
            return;
        }
        self->unk_cc_8 = 0;
        fx = Effect_SpawnId(0x322, &self->pos);
        fx->AddPosXYZ(0, self->centerY, 0);
        fx->SetScaleXYZ(self->radius, self->radius, self->radius);
        self->fsm->st++;
        break;
    }
    case 1: {
        ActorSub40 *w = self->fsm;
        w->timer++;
        if (w->timer <= 0x4b) {
            return;
        }
        History_SetState(self->fsm, 1, 0);
        break;
    }
    }
}

void Ov003ActVt_021f8f20_StateHeld(Ov003ActExPath *self) {
    u16 t;
    if (self->fsm->st == 0) {
        self->frames = 0;
        Model0218fe1c_SetAnimSpeed(self->model, 0x5000);
    }
    ActorEx_StateHeld(self);
    self->frames++;
    t = self->frames;
    if (t > 0x78) {
        Actor *p;
        u8 k;
        if (self->unk_1c == 1) {
            Effect_SpawnId(0x12f, &self->pos)->SetScaleAll(0xa66);
            func_ov000_02197dec(self, 0xf, -1);
            Group_UpdateActor(gGroup, 0, self);
            self->vfunc_08();
            return;
        }
        p = Target_Get(self->targetObj);
        k = 0;
        if (p != NULL && p->fsm != NULL) {
            k = p->fsm->current;
        }
        if (k == 0 || k == 1 || k == 2 || k == 4) {
            SndMgr_PlayAt(gSndMgr, 0x83, &self->pos, 0);
            History_SetState(self->fsm, 10, 0);
        }
        return;
    }
    {
        s32 r = 0x78 - t;
        if (r <= 0x1f && self->unk_1c == 1) {
            self->model->alpha = r;
            return;
        }
    }
    if (t & 0xf) {
        return;
    }
    {
        EffectObj *fx = Effect_SpawnId(0x44d, &self->pos);
        s32 a = Rand_PlusMinus(0x4cd);
        s32 b = Rand_PlusMinus(0x4cd);
        fx->AddPosXYZ(a, -0x19a, b);
    }
}

void Ov003ActVt_021f8f20_State0e(Ov003ActExPath *self) {
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, "att00", 0x1000, 0);
        self->fsm->st++;
    case 1:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            Model0218fe1c_SetAnim(self->model, "nut00", 0x19a, 0);
            Model0218fe1c_SetLoop(self->model);
            Model0218fe1c_SetAnimSpeed(self->model, 0xccd);
            self->fsm->timer = 0;
            self->fsm->st++;
        } else {
            ActorSub40 *w = self->fsm;
            w->timer++;
            if (w->timer <= 0x50) {
                Actor *o = Ov003_FindObj(self->target);
                if (o != NULL) {
                    Actor_TurnToActor(self, o, 0x333);
                }
            }
        }
        break;
    case 2: {
        ActorSub40 *w = self->fsm;
        w->timer++;
        if (w->timer > 0x50) {
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
    }
    if (self->unk_cc_8) {
        History_SetState(self->fsm, 10, 0);
    }
}

extern Robo021ca458 *ActorMgr_FindPlayer(void);
extern s32 func_ov000_0219a7bc(Actor *self, s32 a, VecFx32 *pos, s32 r, s32 b, Actor **list);

static inline BOOL Ov003MapId_Equal(const FieldId *a, const FieldId *b) {
    BOOL r = FALSE;
    const u8 *x = (const u8 *)a;
    const u8 *y = (const u8 *)b;
    if (x[0] == y[0] && x[1] == y[1] && x[2] == y[2]) {
        r = TRUE;
    }
    return r;
}

void Ov003ActVt_021f8e88_State0a(ActorEx *self) {
    if (self->fsm->st == 0 && self->unk_cc_8) {
        Robo021ca458 *p;
        self->unk_cc_8 = 0;
        p = ActorMgr_FindPlayer();
        if (p != NULL && !Ov003MapId_Equal(&gSceneCmd->unk_ca, &p->fieldId)) {
            VecFx32 v;
            Actor *list[32];
            s32 n;
            s32 i;
            BOOL found;
            v = self->pos;
            v.y -= 0x2800;
            found = FALSE;
            n = func_ov000_0219a7bc(self, 0x10, &v, 0x8000, 0x5000, list);
            if (n != 0) {
                for (i = 0; i < n; i++) {
                    if (list[i] != NULL) {
                        u16 id = list[i]->kind;
                        if (id == 0x4008 || id == 0x4022 || id == 0x4031 || id == 0x4014) {
                            found = TRUE;
                            break;
                        }
                    }
                }
            }
            if (found) {
                self->targetObj->target = 0xffff;
                History_SetState(self->fsm, 1, 0);
                return;
            }
        }
    }
    ActorEx_State0a(self);
}

}
}  // namespace m_021e6cb8
