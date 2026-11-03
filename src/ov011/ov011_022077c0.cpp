#include "ov011/ov011.h"


// A header's zero rotation and vector, plus copies made at startup, between this TU's resource
// names and the pointers to them. The first pointer and a scale are read by other functions.
// The functions of 0x021ffb58..0x02200aac (three files, merged in rounds dtB and jkL, each in its
// own namespace) are part of this TU: they read the name pointers and the zero vector through the
// .rodata base plus an offset, and name them (data_ov011_02207258/725c/7260/7264, 7278.x/y/z)
// instead of a data_ov011_02207258[n] array view. With the TU's own objects func_ov011_021fff38
// keeps the ROM's load order without a volatile. The other readers (021fc0b8..021ff8fc) are cut
// off from this range by the unmatched Ov011SceneActor_Update.
extern const char *const data_ov011_02207258;
extern const fx16 data_ov011_0220726e[4];
extern const VecFx32 data_ov011_02207278;
extern char data_ov011_022078c0[];
extern char data_ov011_022078cf[];
extern char data_ov011_022078a0[];
extern char data_ov011_022078ac[];
static const char *const data_ov011_02207260 = data_ov011_022078c0;
static const char *const data_ov011_0220725c = data_ov011_022078cf;
static const char *const data_ov011_02207264 = data_ov011_022078a0;
const char *const data_ov011_02207258 = data_ov011_022078ac;
const fx16 data_ov011_0220726e[4] = {0x1800, 0x1800, 0x1800, 0x1800};
static const VecFx16 data_ov011_02207268 = {0, 0, 0};
const VecFx32 data_ov011_02207278 = {0, 0, 0};
char data_ov011_022078ac[] = "nut00";
char data_ov011_022078a0[] = "run00";
static const VecFx16 data_ov011_022078a6 = data_ov011_02207268;
static const VecFx32 data_ov011_022078b4 = data_ov011_02207278;


// ---- merged from ov011_021ffb58.cpp
namespace m_021ffb58 {

extern "C" {

extern void *gSndMgr;
void *SndMgr_PlayAt(void *a, s32 b, void *c, s32 d);

void ActorMgr_BroadcastKind(void *mgr, u16 id, s32 c);

static inline void Ov011_ChrKick(Ov011Scene *c, s32 v) {
    if (c->b0 && c->b2) {
        c->unk_04 = v;
        c->b2 = 0;
    }
}

static inline u32 Ov011_ChrBusy(Ov011Scene *c) {
    u32 r = 0;
    if (c->b0) {
        r = c->b2;
    }
    return r;
}

#pragma force_active on
void Ov011SceneActor_StateAttack(Ov011SceneActor *self) {
    switch (self->fsm->st) {
    case 0:
        if (self->unk_f0_1) {
            Ov011_ChrKick(self->scene, 2);
        } else {
            Ov011_ChrKick(self->scene, 3);
        }
        self->fsm->st = 1;
        break;
    case 1:
        if (Ov011_ChrBusy(self->scene)) {
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
    self->unk_f4.y = 0x3e69;
}

void Ov011SceneActor_StateAttack2(Ov011SceneActor *self) {
    switch (self->fsm->st) {
    case 0:
        Ov011_ChrKick(self->scene, 4);
        self->fsm->st = 1;
        break;
    case 1:
        if (Ov011_ChrBusy(self->scene)) {
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
}

void Ov011SceneActor_StateDown(Ov011SceneActor *self) {
    if (self->fsm->st == 0) {
        Ov011Scene *c;
        Ov011Sa108 *p;
        Ov011Sa104 *o;
        self->unk_f0_0 = 0;
        c = self->scene;
        if (c->b0) {
            c->b1 = 1;
        }
        p = self->unk_108;
        p->b0 = 0;
        p->b1 = 0;
        p->unk_02 = 0;
        p->unk_04 = 0x1000;
        o = self->unk_104;
        if (o != NULL) {
            Ov003ActorSub40_ForceState(o, 0);
            o->tw.v08();
            if (o->unk_38 != 0) {
                EffectMgr_Kill(gEffectMgr, o->unk_38);
                o->unk_38 = 0;
            }
        }
        self->unk_3c->unk_14 = self->radius << 1;
        self->unk_3c->unk_19 = 0xff;
        if (*self->hp == 0) {
            ActorMgr_BroadcastKind(gActorMgr, 0x4812, 0x15);
        }
    }
    Ov003Actor_StateDown(self);
}

void Ov011SceneActor_StateHurt(Ov011SceneActor *self) {
    if (self->fsm->st == 0) {
        SndMgr_PlayAt(gSndMgr, 0x42, &self->pos, 0);
    }
    Ov003Actor_StateHurt(self);
}

void Ov011SceneActor_StateKnockBack(Ov011SceneActor *self) {
    if (self->fsm->st == 0) {
        SndMgr_PlayAt(gSndMgr, 0x42, &self->pos, 0);
    }
    Ov003Actor_StateKnockBack(self);
}

void Ov011SceneActor_StateDie(Ov011SceneActor *self) {
    if (self->fsm->st == 0) {
        Ov011Sa104 *o;
        EffectObj *v;
        ActorMgr_BroadcastKind(gActorMgr, 0x4812, 0x15);
        o = self->unk_104;
        if (o != NULL) {
            Ov003ActorSub40_ForceState(o, 0);
            o->tw.v08();
            if (o->unk_38 != 0) {
                EffectMgr_Kill(gEffectMgr, o->unk_38);
                o->unk_38 = 0;
            }
        }
        self->unk_3c->unk_14 = self->radius << 1;
        self->unk_3c->unk_19 = 0xff;
        v = Effect_SpawnId(0x69, &self->pos);
        if (v != NULL) {
            v->SetScaleAll(0x2800);
            v->AddPosXYZ(0, 0x1000, 0);
        }
    }
    Ov003Actor_StateDie(self);
}

BOOL Ov011TwB_Start(void *self, const VecFx32 *to, const VecFx32 *from, s16 speed);

static inline void VSet_ff38(VecFx32 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void func_ov011_021fff38(Ov011SceneActor *self) {
    VecFx32 t;
    VecFx32 spawnPos;
    VecFx32 effPos;

    Ov011Sa104 *o;
    const VecFx32 *home;

    home = &data_ov011_02207278;
    t.x = data_ov011_02207278.x;
    t.y = data_ov011_02207278.y - 0x2000;
    t.z = data_ov011_02207278.z;
    o = self->unk_104;
    if (o == NULL) {
        return;
    }
    switch (o->seq.current) {
    case 0:
        break;
    case 1: {
        u8 n;
        s32 v = self->unk_3c->unk_14;
        n = self->unk_3c->unk_19;
        if (n == 0xff) {
            n = 0xf;
        }
        v += FX_Mul(0x8000 - v, 0x333);
        if (n >= 0x1e) {
            n = 0x1e;
        } else {
            n++;
        }
        self->unk_3c->unk_14 = v;
        self->unk_3c->unk_19 = n;
        break;
    }
    case 2:
        if (o->seq.st == 0) {
            EffectObj *g;
            o->tw.v08();
            Ov011TwB_Start(&self->unk_104->tw, &t, home, 0x19a);
            self->unk_104->seq.st++;
            spawnPos = self->hit->check;
            g = EffectGroup_Create(data_ov011_02207260, data_ov011_0220725c, &spawnPos);
            self->unk_104->unk_38 = g->id;
            g->loopCount = -1;
        }
        if (self->unk_104->unk_38 != 0) {
            EffectObj *e = Effect_Find_020657b0(gEffectMgr, self->unk_104->unk_38);
            if (e != NULL) {
                effPos = self->hit->check;
                e->SetPos(&effPos);
            }
        }
        self->unk_94_1 = 1;
        break;
    case 3:
        if (o->seq.st == 0) {
            o->tw.v08();
            Ov011TwB_Start(&self->unk_104->tw, home, &t, 0x19a);
            self->unk_104->seq.st++;
            if (self->unk_104->unk_38 != 0) {
                EffectMgr_StopLoop(gEffectMgr, self->unk_104->unk_38);
                self->unk_104->unk_38 = 0;
            }
            self->unk_f0_0 = 0;
        } else {
            s32 v;
            v = self->unk_3c->unk_14;
            u8 n = self->unk_3c->unk_19;
            if (n <= 0xf) {
                n = 0xf;
                if (o->tw.v14()) {
                    self->unk_104->tw.v08();
                    self->unk_94_1 = 0;
                    self->unk_104->seq.flags |= 1;
                }
            } else {
                n--;
                v += FX_Mul((self->radius << 1) - v, 0x59a);
            }
            self->unk_3c->unk_14 = v;
            self->unk_3c->unk_19 = n;
        }
        break;
    }
    Ov003ActorSub40_ApplyFlags(self->unk_104);
    self->unk_104->tw.v0c();
}
#pragma force_active reset
}
}  // namespace m_021ffb58

// ---- merged from ov011_0220023c.cpp
namespace m_0220023c {
extern "C" {

void Actor_TurnToActor(Actor *self, Actor *other, s32 step);
void Model0218fe1c_PauseAnim(void *a);
void Model0218fe1c_ResumeAnim(void *a);
void Model0218fe1c_SetAnimSpeed(void *a, s32 b);

#pragma force_active on
void func_ov011_0220023c(Ov011SceneActor *self) {
    Actor *pl;
    Ov003Param *q;
    s32 s;
    if (self->unk_108 == NULL) {
        return;
    }
    pl = (Actor *)ActorMgr_FindPlayer();
    q = self->unk_b0;
    if (q != NULL && pl != NULL && (s = self->unk_108->unk_02) != 0) {
        Actor_TurnToActor(self, pl, FX_Mul(q->unk_02, s));
    }
    if (self->unk_108->b1) {
        self->unk_ea_0 = 2;
    } else {
        self->unk_ea_0 = self->unk_b0->unk_0a_7;
    }
    if (self->unk_108->b0) {
        Model0218fe1c_PauseAnim(self->model);
    } else {
        Model0218fe1c_ResumeAnim(self->model);
    }
    Model0218fe1c_SetAnimSpeed(self->model, self->unk_108->unk_04);
}
#pragma force_active reset

struct Ov011Tbl6 {
    s32 v[6];
};

extern const Ov011Tbl6 data_ov011_022072c0;
extern void *gSndMgr;
void Model0218fe1c_ClearLoop(void *a);
u16 Ov003Vec_YawTo(VecFx32 *a, VecFx32 *b);
void *SndMgr_PlayAt(void *mgr, s32 id, const VecFx32 *pos, s32 a);
void Body_Update(void *a, s32 b, s32 c, s32 d);

static inline void Ov011_SetTw(Ov011Sa108 *q, s16 a, s16 b) {
    q->b0 = 0;
    q->b1 = 0;
    q->unk_02 = a;
    q->unk_04 = b;
}

void func_ov011_02200310(Ov011SceneActor *self) {
    Ov011Tbl6 tbl = data_ov011_022072c0;
    VecFx32 v;
    BOOL ok;
    u32 i;
    u8 st;
    Ov011Sa10c *p;
    st = self->fsm->current;
    ok = TRUE;
    for (i = 0; i < 6; i++) {
        s32 *e = &tbl.v[i];
        if (*e == st) {
            ok = FALSE;
            break;
        }
    }
    p = self->unk_10c;
    if (p == NULL || !ok) {
        return;
    }
    if (p->b0) {
        if (p->timer == 0) {
            EffectObj *e;
            u16 r;
            if (!p->b1) {
                Ov011_SetTw(self->unk_108, 0, 0x1000);
                p = self->unk_10c;
                p->b0 = 1;
                p->b1 = 1;
                p->b2 = 1;
                p->timer = 0x78;
                Model0218fe1c_SetAnim(self->model, data_ov011_02207264, 0x1000, 0);
                Model0218fe1c_ClearLoop(self->model);
                self->speed = 0;
                self->velY = 0;
                self->friction = 0;
                self->gravity = 0;
            } else {
                Ov011_SetTw(self->unk_108, 0x1000, 0x1000);
                p = self->unk_10c;
                p->b0 = 1;
                p->b1 = 0;
                p->b2 = 1;
                p->timer = 1;
                Model0218fe1c_SetAnim(self->model, data_ov011_02207258, 0x1000, 0);
                Model0218fe1c_SetLoop(self->model);
            }
            v = self->unk_b8;
            r = Ov003Vec_YawTo(&v, &self->pos);
            e = Effect_SpawnId(0x192, &self->pos);
            e->SetRotXYZ(0, r, 0);
            e->SetScaleXYZ(0x4000, 0x4000, 0x4000);
            SndMgr_PlayAt(gSndMgr, 0x32, &self->pos, 0);
        } else if (p->b1 == 1) {
            self->hit->unk_9a_5 = 1;
            self->unk_10c->b2 = 0;
            if (VEC_Distance(&self->pos, &self->unk_b8) < 0x4000) {
                if (self->speed >= 0x200) {
                    self->speed = 0x200;
                }
                self->friction = 0xf60;
            } else {
                self->speed += FX_Mul(self->unk_b0->unk_00, 0xcd);
                self->speed = self->speed > self->unk_b0->unk_00 ? self->unk_b0->unk_00 : (self->speed < 0 ? 0 : self->speed);
            }
            Actor_Move(self, 0);
            Body_Update(self->hit, 1, 0, 0);
            if (self->hit->unk_50 & 0x40000000) {
                self->speed = 0;
                self->velY = 0;
                self->friction = 0;
                self->gravity = 0;
                self->unk_10c->b0 = 0;
            }
        }
        self->unk_10c->timer--;
    }
    if (!self->unk_10c->b2) {
        return;
    }
    if (ActorMgr_FindPlayer() == NULL) {
        return;
    }
    {
        Actor *pl = (Actor *)ActorMgr_FindPlayer();
        VecFx32 t;
        t = pl->pos;
        self->unk_b8 = t;
        self->moveYaw = FX_Atan2(t.x - self->pos.x, t.z - self->pos.z);
    }
}
}
}  // namespace m_0220023c

// ---- merged from ov011_0220068c.cpp
namespace m_0220068c {
// Teardown of the scene object: inlines the whole destructor of the object at
// 0x100. Past the default inline size limit MWCC calls the helpers instead.
#pragma inline_max_size(512)


extern "C" {

void __cxa_vec_delete(void *arr, u32 size, u32 hdr, void *dtor);
void Ov003_FreeIfSet(void *p);
void Ov011Fx_Release(void *p);
void Ov011Chr_Reset_0220205c(void *p);
void Ov011Mov_Stop_02202fbc(void *p);
void Ov011Mgr_Release(void *p);
void Ov011Mov_Stop(void *p);
void *Ov011Chr_Dtor(void *p);
void *Ov011Fx_Dtor(void *p);
void *Ov011Vt_022079b0_Dtor(void *p);

static inline void Ov011B_FreeBuf(Ov011Scene *b) {
    if (b->ring.b0) {
        void *saved = gSysState->cur;
        gSysState->cur = gSysState->heapHi;
        if (b->ring.buf != NULL) {
            Heap_FreeArray(b->ring.buf);
            b->ring.buf = NULL;
        }
        gSysState->cur = saved;
        b->ring.b0 = 0;
    }
}

static inline void Ov011B_FreeVec(Ov011Scene *b) {
    if (b->mgr2.b0) {
        b->mgr2.b0 = 0;
        {
            void *saved = gSysState->cur;
            gSysState->cur = gSysState->heapHi;
            if (b->mgr2.arr8 != NULL) {
                __cxa_vec_delete(b->mgr2.arr8, 0x40, 8, Ov011E40_Dtor);
                b->mgr2.arr8 = NULL;
            }
            gSysState->cur = saved;
        }
        Ov011Chr_Reset_0220205c(b->mgr2.unk_28);
        Ov011Mov_Stop_02202fbc(&b->mgr2.mov);
    }
}

static inline void Ov011B_FreeList(Ov011Scene *b) {
    if (b->ent.active) {
        if (b->ent.active) {
            Ov011PNode *p = b->ent.nodes;
            while (p != NULL) {
                Ov011PNode *next = p->next;
                if (p != NULL) {
                    Heap_Free(p);
                }
                p = next;
            }
            b->ent.nodes = NULL;
        }
        b->ent.active = 0;
    }
}

static inline void Ov011B_Free(Ov011Scene *b) {
    if (b->b0) {
        Ov011Node *p;
        Ov011Node *next;
        b->b0 = 0;
        for (p = b->head; p != NULL; p = next) {
            next = p->next;
            Ov003_FreeIfSet(p);
        }
        Ov011B_FreeBuf(b);
        Ov011Fx_Release(&b->fx);
        Ov011B_FreeVec(b);
        if (b->s1b4.b0) {
            b->s1b4.b0 = 0;
        }
        Ov011Mgr_Release(&b->mgr);
        Ov011B_FreeList(b);
    }
}

static inline void Ov011B_Dtor(Ov011Scene *b) {
    Ov011B_Free(b);
    Ov011B_FreeList(b);
    Ov011Mgr_Release(&b->mgr);
    if (b->s1b4.b0) {
        b->s1b4.b0 = 0;
    }
    Ov011B_FreeVec(b);
    Ov011Mov_Stop(&b->mgr2.mov);
    Ov011Chr_Dtor(b->mgr2.unk_28);
    Ov011Fx_Dtor(&b->fx);
    Ov011B_FreeBuf(b);
}

void Ov011SceneActor_DtorBase(Ov011SceneActor *self) {
    Ov011Sa104 *a = self->unk_104;
    if (a != NULL) {
        Ov003ActorSub40_ForceState(a, 0);
        a->tw.v08();
        if (a->unk_38 != 0) {
            EffectMgr_Kill(gEffectMgr, a->unk_38);
            a->unk_38 = 0;
        }
    }
    if (self->unk_108 != NULL) {
        Ov011Sa108 *q = self->unk_108;
        q->b0 = 0;
        q->b1 = 0;
        q->unk_02 = 0x1000;
        q->unk_04 = 0x1000;
    }
    {
        void *saved = gSysState->cur;
        gSysState->cur = gSysState->heapHi;
        if (self->scene != NULL) {
            Ov011Scene *b = self->scene;
            if (b != NULL) {
                Ov011B_Dtor(b);
                Heap_Free(b);
            }
            self->scene = NULL;
        }
        gSysState->cur = saved;
    }
    {
        void *saved = gSysState->cur;
        gSysState->cur = gSysState->heapHi;
        if (self->unk_104 != NULL) {
            Ov011Sa104 *b = self->unk_104;
            if (b != NULL) {
                Ov011Vt_022079b0_Dtor(&b->tw);
                Heap_Free(b);
            }
            self->unk_104 = NULL;
        }
        gSysState->cur = saved;
    }
    {
        void *saved = gSysState->cur;
        gSysState->cur = gSysState->heapHi;
        if (self->unk_108 != NULL) {
            Heap_Free(self->unk_108);
            self->unk_108 = NULL;
        }
        gSysState->cur = saved;
    }
    {
        void *saved = gSysState->cur;
        gSysState->cur = gSysState->heapHi;
        if (self->unk_10c != NULL) {
            Heap_Free(self->unk_10c);
            self->unk_10c = NULL;
        }
        gSysState->cur = saved;
    }
    self->unk_f0_0 = 0;
    self->unk_f0_1 = 0;
    self->unk_f2 = 0;
    self->unk_f4.x = data_ov011_02207278.x;
    self->unk_f4.y = data_ov011_02207278.y;
    self->unk_f4.z = data_ov011_02207278.z;
    self->scene = NULL;
    self->unk_104 = NULL;
    self->unk_108 = NULL;
    self->unk_10c = NULL;
}

}
}  // namespace m_0220068c
