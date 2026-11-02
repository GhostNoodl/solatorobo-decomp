#include "ov010/ov010.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"

// The state-handler class: complete, so that the dispatcher reads its fields by name.
class Ov010Cls : public Ov010Obj0220ffe4 {
};
typedef void (Ov010Cls::*Ov010Fn)();
struct Ov010StEnt {
    u8 key;
    Ov010Fn fn;
};


struct Ov010Query {
    VecFx32 pos;
    u16 rot;
    u16 kind;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    u16 unk_28;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 5;

    Ov010Query() {
        kind = 0;
        unk_10 = 0xffff;
        unk_12 = 0;
        unk_14 = 0;
        unk_18 = 0;
        unk_1c = 0;
        unk_20 = 0;
        unk_24 = 0;
        unk_28 = 0xffff;
        *(u8 *)((u8 *)this + 0x2a) = 0;
    }
};

struct Ov010U16x6 {
    u16 v[6];
};

extern "C" {


}

// Deletes the object a field points to (vfunc_04) and clears the field.
template <class T> static inline void Ov010_FreeV(T **pp) {
    void *saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (*pp != NULL) {
        VObj *p = *pp;
        if (p != NULL) {
            p->vfunc_04();
        }
        *pp = NULL;
    }
    data_02097dd0->cur = saved;
}

extern "C" {

extern u8 data_ov010_0220f024[];

void Ov010Obj02210154_ClearFields(Ov010Obj02210154 *self) {
    self->unk_f0 = 0;
    self->unk_f1 = 0;
    self->unk_f2 = 0;
    self->unk_f3 = 0;
    self->unk_f4 = 0;
    self->arena = 0;
    self->unk_fc = 0;
    self->unk_100 = 0;
    self->unk_104 = 0;
    self->unk_108 = 0;
    self->unk_10c = 0;
    self->unk_110 = 0;
    self->unk_114 = 0;
    self->unk_118 = 0;
    self->unk_11c = 0;
    self->unk_120 = 0;
    self->unk_124 = 0;
    self->sndBank = -1;
    MI_CpuFill8(self->sfx, 0, sizeof(self->sfx));
    self->moveDir = FLD(VecFx32, data_ov010_0220f024, 0x84);
    self->unk_15c = -1;
    self->step.a = 0;
    self->step.b = 0xff;
}

void Ov010Obj02210154_Release(Ov010Obj02210154 *self) {
    void *saved;
    func_ov003_021cf404(0);
    func_ov003_021cf400(0);
    Ov010_FreeV(&self->unk_104);
    Ov010_FreeV(&self->unk_108);
    Ov010_FreeV(&self->unk_10c);
    Ov010_FreeV(&self->unk_110);
    Ov010_FreeV(&self->unk_114);
    Ov010_FreeV(&self->unk_118);
    Ov010_FreeV(&self->unk_11c);
    Ov010_FreeV(&self->unk_120);
    saved = data_02097dd0->cur;
    data_02097dd0->cur = data_02097dd0->heapHi;
    if (self->unk_124 != NULL) {
        Heap_Free(self->unk_124);
        self->unk_124 = NULL;
    }
    data_02097dd0->cur = saved;
    Ov003Flag_Stop_021d8fa8(&self->seq);
    Ov010Coll_Release(&self->coll);
    self->ticker.vfunc_08();
    self->timer.vfunc_08();
    data_ov000_021ccd54->cam.unk_d8_0 = 0;
    Ov010Obj02210154_ClearFields(self);
    func_ov003_021cf400(0);
}

extern s32 Finder_CollectActors(s32 *out, Ov010Query *q, Actor **list, s32 max);

extern s32 VEC_Distance(const VecFx32 *a, const VecFx32 *b);
extern BOOL Ov003Vec_Equal(VecFx32 *a, VecFx32 *b);
extern void Ov003Vec_MultAdd(VecFx32 *a, VecFx32 *b, VecFx32 *c, s32 d, s32 e);

static inline s32 Ov010_Clamp(s32 v, s32 lo, s32 hi) {
    if (v > hi) {
        return hi;
    }
    if (v < lo) {
        return lo;
    }
    return v;
}

static inline void Ov010_Move(Ov010Obj02210154 *self) {
    Ov003Vec_MultAdd(&self->pos, &self->moveDir, &self->pos, self->speed, self->velY);
    Ov003Actor_SetMotion(self, self->speed, self->velY, self->friction, self->gravity);
}

void Ov010Obj02210154_MoveToDest(Ov010Obj02210154 *self) {
    VecFx32 t;
    t.x = self->unk_b8.x;
    t.y = self->unk_b8.y;
    t.z = self->unk_b8.z;
    if (VEC_Distance(&t, &self->pos) >= 0x3000) {
        self->speed += 0x180;
        self->speed = Ov010_Clamp(self->speed, 0, 0xd00);
        Ov010_Move(self);
        return;
    } else {
        BOOL slow = TRUE;
        if (self->speed >= 0x40) {
            slow = FALSE;
        }
        if (Ov003Vec_Equal(&self->pos, &t) || slow) {
            self->speed = 0;
            return;
        }
        self->friction = 0xf00;
        if (self->speed >= 0x400) {
            self->speed = 0x400;
        }
    }
    Ov010_Move(self);
}

static inline void Ov010Query_Set(Ov010Query *q, const VecFx32 *pos, u16 rot, u16 kind, s32 r) {
    q->pos.x = pos->x;
    q->pos.y = pos->y;
    q->pos.z = pos->z;
    q->rot = rot;
    q->kind = kind;
    q->unk_10 = 0xffff;
    q->unk_18 = 0;
    q->unk_1c = r;
    q->b2 = 0;
}

BOOL Ov010_FindActorInCone(Actor *self) {
    Actor *list[0x20];
    Ov010Query q;
    s32 out;
    BOOL found = FALSE;
    s32 n;
    s32 i;
    Ov010Query_Set(&q, &self->pos, self->rot_y, 0x10, 0x5000);
    out = 0;
    n = Finder_CollectActors(&out, &q, list, 0x20);
    for (i = 0; i < n; i++) {
        Actor *a = list[i];
        if (a != NULL) {
            u8 st;
            if (a->fsm != NULL) {
                st = a->fsm->current;
            } else {
                st = 0;
            }
            if (st == 0xb && a->target == self->id) {
                found = TRUE;
            }
        }
    }
    return found;
}

extern u8 data_ov010_02210154[];
extern u8 data_ov010_0220ffe4[];
extern char data_ov010_0220ff84[];
extern char data_ov010_0220ff91[];
extern char data_ov010_0220ffa1[];
extern char data_ov010_0220ffae[];
extern void *Ov003Vt_021f7d10_Ctor(void *p);
extern void *Ov003Vt_021f7cd8_Ctor(void *p);
extern void Ov010Obj02210154_ClearFields(Ov010Obj02210154 *self);

static inline void Ov010_02204204_Body(Ov010Obj02210154 *self) {
    Ov003Actor_Ctor(self);
    *(void * *)self = data_ov010_02210154;
    Ov003Flag_Deactivate(&self->seq);
    Ov010Coll_Ctor(&self->coll);
    Ov003Vt_021f7d10_Ctor(&self->ticker);
    Ov003Vt_021f7cd8_Ctor(&self->timer);
    Ov003_DupString(data_ov010_0220ff84);
    func_ov003_021cf3fc(1);
    Ov003_DupString2(2, data_ov010_0220ff91);
    Ov003_DupString2(0, data_ov010_0220ffa1);
    Ov003_DupString2(1, data_ov010_0220ffae);
    Ov010Obj02210154_ClearFields(self);
}

u16 func_ov010_02207a44(s32 i) {
    Ov010U16x6 t = FLD(Ov010U16x6, data_ov010_0220f024, 0xb4);
    if (i < 6) {
        return t.v[i];
    }
    return t.v[5] + (u16)((i - 5) * 0x5a);
}

void *Ov010ActVt_0220ffe4_Ctor(Ov010Obj0220ffe4 *self) {
    Ov010_02204204_Body(self);
    self->unk_1fc = 0;
    self->unk_200 = 0;
    *(void * *)self = data_ov010_0220ffe4;
    return self;
}

void Ov010ActVt_0220ffe4_Start(Ov010Obj0220ffe4 *self) {
    Ov010ActVt_02210154_Start(self);
    self->unk_f3 = self->unk_18 == 3;
}

void Ov010ActVt_0220ffe4_HandleMsg(Ov010Obj0220ffe4 *self, ActorMsg *msg) {
    if (msg != NULL && msg->type == 2) {
        self->unk_1fc = 0;
    }
    Ov010Obj02210154_HandleMsg(self, msg);
}

extern const Ov010StEnt data_ov010_0220f188[];
extern const Ov010Blk12 data_ov010_0220f0b4;
extern Robo021ca458 *ActorMgr_FindPlayer(void);
extern void VEC_MultAdd(s32 a, const VecFx32 *b, const VecFx32 *c, VecFx32 *out);


void Ov010ActVt_0220ffe4_RunState(Ov010Cls *self) {
    u32 i;
    Robo021ca458 *pl;
    s16 *p;
    u8 key;
    if (self->unk_1fc != 0) {
        return;
    }
    key = self->fsm->current;
    for (i = 0; i < 6; i++) {
        if (key == data_ov010_0220f188[i].key && *(s32 *)&data_ov010_0220f188[i].fn != 0) {
            (self->*data_ov010_0220f188[i].fn)();
            break;
        }
    }
    Ov003Actor_RunState(self);
    if (func_ov003_021cf408()) {
        self->mode = func_ov003_021cf408();
    }
    pl = ActorMgr_FindPlayer();
    if (pl != NULL) {
        Ov010_VecCopy(&pl->unk_b90, &self->pos);
        pl->unk_b9c = 0x800;
    }
    p = self->unk_124;
    if (p != NULL) {
        VecFx32 v;
        *(Ov010Blk12 *)&v = data_ov010_0220f0b4;
        Ov003Vec_RotateY(&v, p[0], &v);
        VEC_MultAdd(p[1], &v, &self->pos, &self->pos);
        p[1] = Ov010_FxMul(p[1], p[2]);
    }
    Ov010Coll_Prune(&self->coll);
    self->ticker.vfunc_0c();
    self->timer.vfunc_0c();
    if (self->unk_118 != NULL) {
        self->unk_118->vfunc_0c();
    }
}

extern void *data_02097e4c;
extern const VecFx32 data_ov010_0220f0fc;
extern BOOL Model0218fe1c_SetAnim(Model0218fe1c *a, const char *b, s16 c, u8 d);
extern void Model0218fe1c_SetLoop(Model0218fe1c *a);
extern void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);
extern u16 FX_Atan2(s32 y, s32 x);

void Ov010ActVt_0220ffe4_State20(Ov010Obj0220ffe4 *self) {
    self->model->visible = 1;
    switch (self->unk_18) {
    case 0: {
        ActorSub40 *st = self->fsm;
        switch (st->st) {
        case 0:
            Model0218fe1c_SetAnim(self->model, FLD(const char *, data_ov010_0220f024, 0x2c), 0x1000, 0);
            Model0218fe1c_SetLoop(self->model);
            Ov010_VecSet(&self->pos, 0x19a, 0x1b3b, -0x3a77);
            self->rot_x = FLD(u16, data_ov010_0220f024, 0x50);
            self->rot_y = FLD(u16, data_ov010_0220f024, 0x52);
            self->rot_z = FLD(u16, data_ov010_0220f024, 0x54);
            self->pos.y += 0x5000;
            self->speed = 0xcd;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            SndMgr_PlayAt(data_02097e4c, 0x51, &self->pos, 0);
            self->fsm->st = 1;
            return;
        case 1:
            if (self->speed >= 0x20) {
                const VecFx32 *t = &data_ov010_0220f0fc;
                if (self->friction == 0) {
                    if (VEC_Distance(t, &self->pos) < 0x333) {
                        self->friction = 0xe66;
                    }
                }
                Ov003Vec_ApproachWithin(&self->pos, t, &self->pos, self->speed, self->velY);
                Ov003Actor_SetMotion(self, self->speed, self->velY, self->friction, self->gravity);
                self->moveYaw = FX_Atan2(t->x - self->pos.x, t->z - self->pos.z);
                return;
            }
            Effect_SpawnId(0x12f, &self->pos)->SetScaleAll(0xe66);
            self->fsm->st = 2;
            return;
        case 2:
            st->timer++;
            if (self->fsm->timer <= 0x5a) {
                return;
            }
            self->speed = 0;
            self->velY = 0;
            self->friction = 0;
            self->gravity = 0;
            Ov003Actor_State20(self);
            return;
        }
        return;
    }
    case 1:
        Ov010_VecSet(&self->pos, 0x19a, 0x1b3b, -0x3a77);
        self->rot_x = FLD(u16, data_ov010_0220f024, 0x50);
        self->rot_y = FLD(u16, data_ov010_0220f024, 0x52);
        self->rot_z = FLD(u16, data_ov010_0220f024, 0x54);
        Ov003Actor_State20(self);
        return;
    case 2:
        Ov010_VecSet(&self->pos, 0x1da2, -0xb42d, 0x266f);
        self->rot_x = 0;
        self->rot_y = 0x7fff;
        self->rot_z = 0;
        Ov003Actor_State20(self);
        return;
    case 3:
        Ov010_VecSet(&self->pos, 0x1da2, -0xb42d, 0x266f);
        self->rot_x = 0;
        self->rot_y = 0x7fff;
        self->rot_z = 0;
        Ov003Actor_State20(self);
        return;
    }
}

extern void VEC_Normalize(const VecFx32 *src, VecFx32 *dst);
extern void func_020627a0(u16 a, u16 b);
extern void func_020627dc(s32 a);
extern BOOL History_SetState(ActorSub40 *a, u8 b, BOOL c);

static inline void Ov010_VecSub(const VecFx32 *a, const VecFx32 *b, VecFx32 *o) {
    o->x = a->x - b->x;
    o->y = a->y - b->y;
    o->z = a->z - b->z;
}

void Ov010ActVt_0220ffe4_State21(Ov010Obj0220ffe4 *self) {
    if (self->fsm->st == 0) {
        Ov010_VecSet(&self->pos, 0x1da2, -0xb42d, 0x266f);
        self->rot_x = 0;
        self->rot_y = 0x7fff;
        self->rot_z = 0;
        self->pos.y += 0x8000;
        Ov010_VecSet(&self->unk_b8, 0x1da2, -0xb42d, 0x266f);
        Ov010_VecSub(&self->unk_b8, &self->pos, &self->moveDir);
        VEC_Normalize(&self->moveDir, &self->moveDir);
        self->moveYaw = FX_Atan2(self->moveDir.x, self->moveDir.z);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        SndMgr_PlayAt(data_02097e4c, 0x29, &self->pos, 0);
        self->fsm->st++;
        return;
    }
    Ov010Obj02210154_MoveToDest(self);
    if (self->speed == 0) {
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
        History_SetState(self->fsm, 1, 0);
    }
}

extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *a, s16 b);
extern BOOL Model0218fe1c_IsAnimDone(Model0218fe1c *a);
extern const VecFx32 data_ov010_0220f108;
extern VecFx32 data_ov010_0220f114;
extern VecFx32 data_ov010_0220f120;

struct Ov010Rot3 {
    s16 v[3];
};

void Ov010ActVt_0220ffe4_State22(Ov010Obj0220ffe4 *self) {
    switch (self->fsm->st) {
    case 0:
        self->fsm->st = 10;
        return;
    case 10:
        Model0218fe1c_SetAnim(self->model, FLD(const char *, data_ov010_0220f024, 0x8), 0x266, 0);
        Model0218fe1c_SetAnimSpeed(self->model, 0x1800);
        self->fsm->st = 0xb;
    case 0xb:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            self->fsm->st = 0x14;
        }
        return;
    case 0x14: {
        FieldState *g;
        Model0218fe1c_SetAnim(self->model, FLD(const char *, data_ov010_0220f024, 0xc), 0x266, 0);
        Model0218fe1c_SetAnimSpeed(self->model, 0x1000);
        Model0218fe1c_SetLoop(self->model);
        self->moveYaw = self->rot_y;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        g = data_ov000_021ccd54;
        g->cam.base.flags |= 0x1c;
        g->cam.base.shakeTime = 0xf;
        g->cam.base.shakeLen = 0x28;
        g->cam.base.shakeCur = 0x28;
        Ov010_SpawnAimFx(self, 0, self->moveYaw)->SetScaleAll(0x2000);
        SndMgr_PlayAt(data_02097e4c, 0x32, &self->pos, 0);
        self->fsm->st = 0x15;
    }
    case 0x15:
        if (VEC_Distance(&self->pos, &data_ov010_0220f108) <= 0x14000) {
            self->speed += 0x333;
            self->speed = Ov010_Clamp(self->speed, 0, 0x1000);
            Actor_Move(self, 0x1000);
        }
        self->fsm->timer++;
        if (self->fsm->timer <= 0x5a) {
            return;
        }
        self->fsm->timer = 0;
        self->fsm->st = 0x1e;
        Ov010_VecSet(&self->pos, 0x19a, 0x1b3b, -0x3a77);
        return;
    case 0x1e:
        Effect_SpawnId(0x389, &data_ov010_0220f114)->SetScaleAll(0x2000);
        Effect_SpawnId(0x322, &data_ov010_0220f114)->SetScaleAll(0x1800);
        Effect_SpawnId(0x389, &data_ov010_0220f120)->SetScaleAll(0x2000);
        Effect_SpawnId(0x322, &data_ov010_0220f114)->SetScaleAll(0x1800);
        SndMgr_PlayAt(data_02097e4c, 0x79, &self->pos, 0);
        self->fsm->st = 0x1f;
        self->fsm->timer = 0x28;
        return;
    case 0x1f: {
        ActorSub40 *st = self->fsm;
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            self->fsm->st = 0x28;
        }
        return;
    }
    case 0x28: {
        Ov010Rot3 r;
        Actor *o;
        r = FLD(Ov010Rot3, data_ov010_0220f024, 0x5c);
        o = Ov003_SpawnById(0x5816);
        Ov010_VecSet(&o->pos, 0x2ee1, -0xc000, -0x2000);
        o->rot_x = r.v[0];
        o->rot_y = r.v[1];
        o->rot_z = r.v[2];
        o = Ov003_SpawnById(0x5816);
        Ov010_VecSet(&o->pos, -0x2571, -0xc000, -0x2000);
        o->rot_x = r.v[0];
        o->rot_y = r.v[1];
        o->rot_z = r.v[2];
        Effect_SpawnId(0x579, &data_ov010_0220f114)->SetScaleAll(0x2000);
        Effect_SpawnId(0x579, &data_ov010_0220f120)->SetScaleAll(0x2000);
        SndMgr_PlayAt(data_02097e4c, 0x5c, &self->pos, 0);
        self->fsm->st = 0x64;
        return;
    }
    case 0x64:
        func_020627a0(self->kind, self->id);
        func_020627dc(4);
        data_ov000_021ccd54->stageFlags = 1;
        self->fsm->st = 0x65;
        self->unk_1fc = 1;
        return;
    case 0x65:
        return;
    }
}

}
