#include "ov011/ov011.h"


// A header's zero rotation and vector, plus copies made at startup, and two scales of this TU
// that other functions read. MWCC emits this order as zero rotation, scales, zero vector.
// The functions of 0x02200aac..0x022030b4 (four files, merged in round dtB, each in its own
// namespace) are part of this TU: they read the zero vector through the .rodata base plus an
// offset, and name it (data_ov011_02207438) instead of an FLD view of data_ov011_02207418.
extern const VecFx16 data_ov011_02207418;
extern const VecFx32 data_ov011_02207420;
extern const VecFx32 data_ov011_0220742c;
extern const VecFx32 data_ov011_02207438;
const VecFx32 data_ov011_02207420 = {FX32_ONE / 2, FX32_ONE / 2, FX32_ONE};
const VecFx32 data_ov011_0220742c = {0x14cd, 0x14cd, FX32_ONE};
const VecFx32 data_ov011_02207438 = {0, 0, 0};
const VecFx16 data_ov011_02207418 = {0, 0, 0};
static const VecFx16 data_ov011_02207994 = data_ov011_02207418;
static const VecFx32 data_ov011_0220799c = data_ov011_02207438;

// ---- merged from ov011_02200aac.cpp
namespace m_02200aac {
extern "C" {

s16 Ov003Ticker_GetValue(void *p);
void Obj021984c8_UpdatePos(void *p, s32 a, s32 b);
void ActorSub48_UpdatePos(void *p, s32 a, s32 b);
s32 Tbl_FindEntry_0206fef8(u32 id);
void *Model0218fe1c_Init(void *p);
BOOL Model0218fe1c_SetRes(void *a, void *b, s32 c, s32 d);
void Model0218fe1c_Setup(void *a, void *b, s32 c);

s32 Ov011Ticker_ScaledValue(void *p, s32 b) {
    return FX_Mul(Ov003Ticker_GetValue(p), b);
}

void Ov011ActorBase_UpdateSub44(Ov003Actor *self) {
    if (self->unk_44 != NULL) {
        Obj021984c8_UpdatePos(self->unk_44, 0, 0);
    }
}

void Ov011Actor_UpdateHit(Ov003Actor *self) {
    if (self->hit != NULL) {
        ActorSub48_UpdatePos(self->hit, 0, 0);
    }
}

void Ov011ActorBase_UpdateMode1(Ov003Actor *self) {
}

void Ov011ActorBase_UpdateMode3(Ov003Actor *self) {
}

void func_ov011_02200b18(Ov003Actor *self) {
}

void Ov011Actor_State25(Ov003Actor *self) {
}

void Ov011Actor_State24(Ov003Actor *self) {
}

void Ov011Actor_State23(Ov003Actor *self) {
}

void Ov011Actor_State22(Ov003Actor *self) {
}

void Ov011Actor_State21(Ov003Actor *self) {
}

void Ov011Actor_State16(Ov011V *self) {
    self->v54();
}

void Ov011Actor_Shoot2(Ov003Actor *self) {
    self->unk_ee_5 = 1;
    self->vfunc_70();
}

void Ov011Actor_StateAttack3(Ov003Actor *self) {
    self->unk_ee_2 = 2;
    self->vfunc_64();
}

BOOL Ov011Model2_Init(Ov011Model2 *self, void *a, void *b) {
    s32 r;
    void *p;
    self->b0 = 1;
    self->b1 = 0;
    self->b2 = 0;
    self->unk_02 = 0;
    self->unk_04 = 0;
    r = Tbl_FindEntry_0206fef8((u32)b);
    p = Heap_Alloc(0xe8);
    if (p != NULL) {
        p = Model0218fe1c_Init(p);
    }
    self->model = (Model0218fe1c *)p;
    Model0218fe1c_SetRes(p, a, 0, 1);
    self->model->actor_id = 0xffff;
    Model0218fe1c_Setup(self->model, a, r);
    self->model->visible = 1;
    return TRUE;
}

}


extern "C" {

extern const VecFx32 data_ov011_02207450;
extern const VecFx32 data_ov011_0220745c;

static inline void Ov011Tw_InitA(Ov011Tw *t, const VecFx32 *from, const VecFx32 *to) {
    s32 x;
    s32 y;
    s32 z;
    t->b0 = 1;
    t->b1 = 0;
    t->unk_04 = 0;
    x = from->x;
    t->v08.x = x;
    y = from->y;
    t->v08.y = y;
    z = from->z;
    t->v08.z = z;
    t->v14.x = to->x;
    t->v14.y = to->y;
    t->v14.z = to->z;
    t->v20.x = x;
    t->v20.y = y;
    t->v20.z = z;
    t->unk_02 = FX_Div(0x1000, VEC_Distance(to, from));
}

static inline void Ov011Tw_InitB(Ov011Tw *t, s32 from, s32 to, u16 speed, s32 mul) {
    t->b0 = 1;
    t->unk_02 = speed;
    t->v08.x = from;
    t->v08.y = from;
    t->v08.z = from;
    t->v14.x = to;
    t->v14.y = to;
    t->v14.z = to;
    t->unk_04 = FX_Mul(VEC_Distance(&t->v14, &t->v08), mul);
}

void Ov011Model2_Update(Ov011Model2 *self) {
    VecFx32 a;
    VecFx32 b;
    s16 v2;
    s16 v4;
    if (!self->b0) {
        return;
    }
    if (self->b1) {
        OV011_BLKCPY(&a, &data_ov011_02207450);
        OV011_BLKCPY(&b, &data_ov011_0220745c);
        self->b1 = 0;
        self->b2 = 1;
        v2 = self->unk_02;
        v4 = self->unk_04;
        OV011_TWV(self->m0c)->v08();
        OV011_TWV(self->m3c)->v08();
        Ov011Tw_InitA(OV011_TW(self->m0c), &a, &b);
        Ov011Tw_InitB(OV011_TW(self->m3c), v2, v4, 0x333, 0x14);
    } else if (self->b2) {
        if (OV011_TWV(self->m0c)->v14() && OV011_TWV(self->m3c)->v14()) {
            self->b1 = 0;
            self->b2 = 0;
            OV011_TWV(self->m0c)->v08();
            OV011_TWV(self->m3c)->v08();
        } else {
            self->model->alpha = *(s32 *)OV011_TWV(self->m0c)->v10() >> 12;
            self->model->scale = *(VecFx32 *)OV011_TWV(self->m3c)->v10();
        }
    }
    OV011_TWV(self->m0c)->v0c();
    OV011_TWV(self->m3c)->v0c();
}

}

extern "C" {

extern u8 Ov011Npc_vtbl[];
void *ActorEx_Ctor(void *p);
void *ActorEx_DtorBase(void *p);
void Ov003Ticker_Clear_021d7ca8(void *p);
void Ov003Ticker_Release_021d7d8c(void *p);
void Ov003Ticker_Release_021d7ce0(void *p);

void *Ov011Npc_Ctor(Ov011Npc *self) {
    ActorEx_Ctor(self);
    *(void **)self = Ov011Npc_vtbl;
    Ov003Ticker_Clear_021d7ca8(self->unk_d8);
    Ov003Ticker_Clear_021d7ca8(self->unk_e4);
    Ov003Ticker_Clear_021d7ca8(self->unk_f0);
    self->unk_ce_0 = 0;
    self->unk_ce_1 = 0;
    self->unk_d0 = 0xffff;
    self->unk_d4 = NULL;
    return self;
}

void *Ov011Npc_Dtor(Ov011Npc *self) {
    *(void **)self = Ov011Npc_vtbl;
    Ov003Ticker_Release_021d7d8c(self->unk_d8);
    Ov003Ticker_Release_021d7d8c(self->unk_e4);
    Ov003Ticker_Release_021d7d8c(self->unk_f0);
    self->unk_ce_0 = 0;
    self->unk_ce_1 = 0;
    self->unk_d0 = 0xffff;
    self->unk_d4 = NULL;
    Ov003Ticker_Release_021d7ce0(self->unk_f0);
    Ov003Ticker_Release_021d7ce0(self->unk_e4);
    Ov003Ticker_Release_021d7ce0(self->unk_d8);
    ActorEx_DtorBase(self);
    return self;
}

void *Ov011Npc_DtorDelete(Ov011Npc *self) {
    *(void **)self = Ov011Npc_vtbl;
    Ov003Ticker_Release_021d7d8c(self->unk_d8);
    Ov003Ticker_Release_021d7d8c(self->unk_e4);
    Ov003Ticker_Release_021d7d8c(self->unk_f0);
    self->unk_ce_0 = 0;
    self->unk_ce_1 = 0;
    self->unk_d0 = 0xffff;
    self->unk_d4 = NULL;
    Ov003Ticker_Release_021d7ce0(self->unk_f0);
    Ov003Ticker_Release_021d7ce0(self->unk_e4);
    Ov003Ticker_Release_021d7ce0(self->unk_d8);
    ActorEx_DtorBase(self);
    Heap_Free(self);
    return self;
}

extern u16 data_ov011_02207f00;
s32 Ov011Ticker_ScaledValue(void *p, s32 b);
s32 ActorEx_Draw(void *p);

#define OV011_ABS(x) ((x) < 0 ? -(x) : (x))

static inline void Ov011_ScaleV(VecFx32 *v, s32 x, s32 y, s32 z, s32 s) {
    v->x = FX_Mul(x, s);
    v->y = FX_Mul(y, s);
    v->z = FX_Mul(z, s);
}

s32 Ov011Npc_Draw(Ov011Npc *self) {
    s32 r;
    VecFx32 saved;
    VecFx32 v;
    Model0218fe1c *m;
    u8 be;
    s32 a8;
    s32 ac;
    s32 b0;
    s32 old;
    OV011_BLKCPY(&saved, &self->pos);
    m = self->model;
    be = m->alpha;
    a8 = m->scale.x;
    ac = m->scale.y;
    b0 = m->scale.z;
    if (self->unk_ce_1) {
        OV011_BLKCPY(&v, &saved);
        v.x += Ov011Ticker_ScaledValue(self->unk_e4, 0x266);
        v.y += Ov011Ticker_ScaledValue(self->unk_f0, 0x266);
        self->pos = v;
    }
    if (self->unk_ce_0) {
        Ov011_ScaleV(&self->model->scale, a8, ac, b0, FX_Mul(OV011_ABS(OV011_COS(data_ov011_02207f00)), 0xa00) + 0xd00);
    }
    old = self->unk_3c->unk_14;
    self->unk_3c->unk_14 = FX_Mul(old, 0x2800);
    self->model->trans = self->pos;
    r = ActorEx_Draw(self);
    self->unk_3c->unk_14 = old;
    self->pos = saved;
    m = self->model;
    m->scale.x = a8;
    m->scale.y = ac;
    m->scale.z = b0;
    self->model->alpha = be;
    return r;
}

void func_ov011_022011c0(Ov011Npc *self, u16 v) {
    self->unk_d0 = v;
}

void Ov011Npc_SetTracking(Ov011Npc *self, BOOL on) {
    if (on) {
        self->unk_ce_0 = 1;
        self->targetObj->target = self->unk_d0;
    } else {
        self->unk_ce_0 = 0;
        self->targetObj->target = 0xffff;
    }
}

void func_ov011_022011fc(Ov011Npc *self, u8 on) {
    self->unk_ce_1 = on;
}

void func_ov011_02201214(Ov011Npc *self, void *p) {
    self->unk_d4 = p;
}

void Ov011Npc_SetVisible(Ov011Npc *self, BOOL on) {
    Model0218fe1c *m = self->model;
    if (m == NULL) {
        return;
    }
    if (on) {
        m->visible = 1;
    } else {
        m->visible = 0;
    }
}

u32 Ov011Npc_IsTracking(Ov011Npc *self) {
    return self->unk_ce_0;
}

void *Ov011Npc_GetEntKey(Ov011Npc *self) {
    return self->unk_d4;
}

}


struct Ov011CVec {
    s32 x;
    s32 y;
    s32 z;
    Ov011CVec(s32 a, s32 b, s32 c) {
        x = a;
        y = b;
        z = c;
    }
};

struct Ov011Bits94 {
    u8 b0 : 1;
    u8 b1 : 2;
    u8 b3 : 5;
};

extern "C" {

void ActorEx_Start(void *p);
BOOL Ov003Ticker_Start_021d7d24(void *p, s32 a, s32 b, s32 c, s32 d);
void ActorEx_Update(void *p);
void Ov003Ticker_Update_021d7dd0(void *p);
void ActorEx_StateIdle(void *p);
void *Target_Get(void *p);
Actor *Actor_GetTarget(void *p);
BOOL Hit_ApplyInArea(void *a, void *b, u16 c, u8 d, u16 mask, VecFx32 *v, s32 e, s32 f, s32 g, s32 h, s32 i);
void ActorEx_StateFly(void *p);
void ActorEx_StateThrown(void *p);
void ActorEx_StateDie(void *p);
void *History_Init(void *p);
void Ov011Fx_Release(Ov011Fx *p);

void Ov011Npc_Start(Ov011Npc *self) {
    ActorSub44 *p;
    ActorEx_Start(self);
    Ov003Ticker_Start_021d7d24(self->unk_d8, 0, 0, 1, 1);
    Ov003Ticker_Start_021d7d24(self->unk_e4, 0, 0, 1, 1);
    Ov003Ticker_Start_021d7d24(self->unk_f0, 0, 0, 1, 1);
    self->unk_cc.b4 = 0;
    self->hit->unk_9a_7 = 1;
    self->hit->radius = 0x800;
    p = self->unk_44;
    p->unk_1c = FX_Mul(p->unk_1c, 0x1a00);
}

void Ov011Npc_Update(Ov011Npc *self) {
    ActorEx_Update(self);
    if (self->unk_ce_0) {
        self->fsm->flags |= 2;
        self->unk_44->unk_22_1 = 0;
        self->unk_94_1 = 1;
    } else if (self->unk_ce_1) {
        self->unk_94_1 = 1;
    } else {
        self->unk_94_1 = 0;
    }
    Ov003Ticker_Update_021d7dd0(self->unk_d8);
    Ov003Ticker_Update_021d7dd0(self->unk_e4);
    Ov003Ticker_Update_021d7dd0(self->unk_f0);
}

void Ov011Npc_StateIdle(Ov011Npc *self) {
    u16 mask;
    void *a;
    if (!self->unk_ce_0) {
        ActorEx_StateIdle(self);
    }
    mask = 0;
    a = Target_Get(self->targetObj);
    if (a != NULL) {
        Actor *b = Actor_GetTarget(a);
        if (b != NULL) {
            mask |= (u16)(1 << (b->id >> 12));
        }
        b = Actor_GetTarget(self);
        if (b != NULL) {
            mask |= (u16)(1 << (b->id >> 12));
        }
    }
    VecFx32 v = {0, 0, 0};
    v.y = -self->height / 2;
    if (mask == 0) {
        return;
    }
    Hit_ApplyInArea(self, self, self->targetObj->unk_08, self->targetObj->unk_0a, mask, &v, 0,
                        self->radius, self->height, 100, 0x1000);
}

void Ov011Npc_StateThrown(Ov011Npc *self) {
    if (self->fsm->st == 1) {
        self->friction = 0;
        self->gravity = 0;
        self->velY = 0;
        ActorEx_StateFly(self);
    } else {
        ActorEx_StateThrown(self);
    }
}

void Ov011Npc_StateDie(Ov011Npc *self) {
    if (self->fsm->st == 0) {
        self->unk_ce_0 = 0;
        self->radius = 0xb33;
    }
    ActorEx_StateDie(self);
}

void *Ov011Fx_Ctor(Ov011Fx *self) {
    History_Init(&self->state);
    Ov003Ticker_Clear_021d7ca8(self->s5c);
    Ov003Ticker_Clear_021d7ca8(self->s68);
    Ov003Ticker_Clear_021d7ca8(self->s74);
    self->b0 = 0;
    return self;
}

void *Ov011Fx_Dtor(Ov011Fx *self) {
    Ov011Fx_Release(self);
    Ov003Ticker_Release_021d7ce0(self->s74);
    Ov003Ticker_Release_021d7ce0(self->s68);
    Ov003Ticker_Release_021d7ce0(self->s5c);
    return self;
}

}


extern "C" {

void *ResSet_Init(void *p);
void *ResSet_ReleaseAll(void *p);
void *Model0218fe1c_FreeAnims(void *p);
void func_ov000_02193e5c(void *p, s32 a);
BOOL ResSet_UpdateLoad(void *p);

BOOL Ov011Fx_Init(Ov011Fx *self) {
    void *p;
    self->b0 = 1;
    self->b1 = 0;
    self->b2 = 0;
    self->unk_02 = 0;
    p = Heap_Alloc(0x138);
    if (p != NULL) {
        p = ResSet_Init(p);
    }
    self->anim = (Ov011Anim *)p;
    p = Heap_Alloc(0xe8);
    if (p != NULL) {
        p = Model0218fe1c_Init(p);
    }
    self->model = (Model0218fe1c *)p;
    {
        const VecFx32 *src = &data_ov011_02207438;
        s32 x;
        s32 y;
        s32 z;
        x = src->x;
        self->v0c.x = x;
        y = src->y;
        self->v0c.y = y;
        z = src->z;
        self->v0c.z = z;
        self->v18.x = x;
        self->v18.y = y;
        self->v18.z = z;
    }
    MTX_Identity33_(&self->mtx);
    Ov003ActorSub40_ForceState(&self->state, 0);
    func_ov000_02193e5c(self->anim, 0x4812);
    Ov003Ticker_Start_021d7d24(self->s5c, 0, 0, 1, 0);
    Ov003Ticker_Start_021d7d24(self->s68, 0, 0, 1, 0);
    Ov003Ticker_Start_021d7d24(self->s74, 0, 0, 1, 0);
    return TRUE;
}

static inline void Ov011_FreeAnim(Ov011Fx *self) {
    void *saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (self->anim != NULL) {
        Ov011Anim *p = self->anim;
        if (p != NULL) {
            ResSet_ReleaseAll(p);
            Heap_Free(p);
        }
        self->anim = NULL;
    }
    gSysState->cur = saved;
}

static inline void Ov011_FreeModel(Ov011Fx *self) {
    void *saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (self->model != NULL) {
        Model0218fe1c *p = self->model;
        if (p != NULL) {
            Model0218fe1c_FreeAnims(p);
            Heap_Free(p);
        }
        self->model = NULL;
    }
    gSysState->cur = saved;
}

void Ov011Fx_Release(Ov011Fx *self) {
    if (!self->b0) {
        return;
    }
    Ov011_FreeAnim(self);
    Ov011_FreeModel(self);
    Ov003Ticker_Release_021d7d8c(self->s5c);
    Ov003Ticker_Release_021d7d8c(self->s68);
    Ov003Ticker_Release_021d7d8c(self->s74);
    self->b0 = 0;
}

void Ov011Fx_Update(Ov011Fx *self) {
    VecFx32 a;
    VecFx32 b;
    if (!self->b0) {
        return;
    }
    if (!self->b1) {
        if (self->anim->unk_00 < 0) {
            s32 r;
            self->b1 = 1;
            r = Tbl_FindEntry_0206fef8(0x4812);
            self->model->actor_id = 0xffff;
            Model0218fe1c_Setup(self->model, self->anim, r);
        } else {
            ResSet_UpdateLoad(self->anim);
        }
    } else if (self->b2) {
        switch (self->state) {
        case 0:
            self->unk_02 = 0x4cd;
            self->state = 1;
            OV011_BLKCPY(&a, &data_ov011_02207420);
            MTX_MultVec33(&self->v0c, &self->mtx, &b);
            VEC_Add(&b, &self->v18, &b);
            Effect_SpawnId(0x648, &b)->SetScale(&a);
            break;
        case 1:
            self->timer++;
            if (self->timer > 30) {
                self->timer = 0;
                self->state = 2;
            }
            break;
        case 2:
            self->unk_02 += 0x1ae;
            self->timer++;
            if (self->timer > 10) {
                self->unk_02 = 0x159a;
                self->timer = 0;
                self->state = 3;
            }
            break;
        case 3:
            self->timer++;
            if (self->timer > 25) {
                self->timer = 0;
                self->b2 = 0;
            }
            break;
        }
        Ov003ActorSub40_ApplyFlags(&self->state);
    }
    Ov003Ticker_Update_021d7dd0(self->s5c);
    Ov003Ticker_Update_021d7dd0(self->s68);
    Ov003Ticker_Update_021d7dd0(self->s74);
}

}

extern "C" {

extern u8 data_ov011_02207468[];
BOOL Model021903b4_Draw(void *p);

void Ov011Fx_Draw(Ov011Fx *self) {
    VecFx32 p;
    VecFx32 q;
    VecFx32 s;
    s32 a8;
    s32 ac;
    s32 b0;
    if (!self->b0) {
        return;
    }
    if (!self->b1) {
        return;
    }
    if (!self->b2) {
        return;
    }
    MTX_MultVec33(&self->v0c, &self->mtx, &p);
    VEC_Add(&p, &self->v18, &p);
    a8 = self->model->scale.x;
    ac = self->model->scale.y;
    b0 = self->model->scale.z;
    OV011_BLKCPY(&q, &p);
    OV011_BLKCPY(&s, data_ov011_02207468);
    s.x = self->unk_02;
    s.y = self->unk_02;
    q.x += Ov011Ticker_ScaledValue(self->s68, 0x266);
    q.y += Ov011Ticker_ScaledValue(self->s74, 0x266);
    s.x += Ov011Ticker_ScaledValue(self->s5c, 0x333);
    s.y = s.x;
    if (s.x < 0) {
        s.x = 0;
    }
    if (s.y < 0) {
        s.y = 0;
    }
    self->model->trans = q;
    self->model->scale = s;
    Model021903b4_Draw(self->model);
    self->model->trans = p;
    {
        Model0218fe1c *m = self->model;
        m->scale.x = a8;
        m->scale.y = ac;
        m->scale.z = b0;
    }
}

void Ov011Fx_Start(Ov011Fx *self, const VecFx32 *pos) {
    if (!self->b0) {
        return;
    }
    if (self->b2) {
        return;
    }
    self->b2 = 1;
    self->v0c = *pos;
    self->v18 = data_ov011_02207438;
    MTX_Identity33_(&self->mtx);
    Ov003ActorSub40_ForceState(&self->state, 0);
}

void Ov011Fx_Stop(Ov011Fx *self) {
    if (self->b0) {
        self->b2 = 0;
    }
}

BOOL Ov011Fx_IsStopped(Ov011Fx *self) {
    BOOL r = FALSE;
    if (!self->b0) {
        return r;
    }
    if (!self->b2) {
        r = TRUE;
    }
    return r;
}

u32 Ov011Fx_IsLoaded(Ov011Fx *self) {
    u32 r = 0;
    if (self->b0) {
        r = self->b1;
    }
    return r;
}

void Ov011Fx_SetVec18(Ov011Fx *self, const VecFx32 *v) {
    if (!self->b0) {
        return;
    }
    self->v18 = *v;
}

void Ov011Fx_SetYaw(Ov011Fx *self, u16 ang) {
    MtxFx33 m;
    if (self == NULL) {
        return;
    }
    MTX_RotY33_(&m, OV011_SIN(ang), OV011_COS(ang));
    if (!self->b0) {
        return;
    }
    MI_Copy36B(&m, &self->mtx);
}

}
}  // namespace m_02200aac

// ---- merged from ov011_02201c18.cpp
namespace m_02201c18 {
struct Ov011Chr {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    s16 unk_02;
    s16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 id;
    s32 mode;
    VecFx32 off;
    Ov011Anim *anim;
    Model0218fe1c *model;
    s32 unk_24;
    Ov011Model2 m28;
    u8 s88[0xc];
    u8 s94[3][0xc];
};

typedef void (Ov011Chr::*Ov011ChrFn)();

struct Ov011ChrEntry {
    s32 key;
    Ov011ChrFn fn;
};

extern "C" {

extern u8 Ov011Vt_022079d0_vtbl[];
extern u8 Ov011Vt_022079b0_vtbl[];
extern const Ov011ChrEntry Ov011Chr_ModeTable[];
void Ov003Ticker_Clear_021d7ca8(void *p);
void Ov003Ticker_Release_021d7ce0(void *p);
void Ov003Ticker_Release_021d7d8c(void *p);
void Ov003Ticker_Update_021d7dd0(void *p);
BOOL Ov003Ticker_Start_021d7d24(void *p, s32 a, s32 b, s32 c, s32 d);
void __cxa_vec_ctor(void *arr, s32 count, u32 size, void *ctor, void *dtor);
void *ResSet_Init(void *p);
void *Model0218fe1c_Init(void *p);
void *ResSet_ReleaseAll(void *p);
void *Model0218fe1c_FreeAnims(void *p);
void func_ov000_02193e5c(void *p, s32 a);
BOOL ResSet_UpdateLoad(void *p);
s32 Tbl_FindEntry_0206fef8(u32 id);
void Model0218fe1c_Setup(void *a, void *b, s32 c);
BOOL Ov011Model2_Init(Ov011Model2 *self, void *a, u32 b);
void Ov011Model2_Update(Ov011Model2 *self);
s32 Ov011Ticker_ScaledValue(void *p, s32 b);
BOOL Model021903b4_Draw(void *p);
}

static inline void Ov011_FreeModelP(Model0218fe1c **pp) {
    void *saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (*pp != NULL) {
        Model0218fe1c *p = *pp;
        if (p != NULL) {
            Model0218fe1c_FreeAnims(p);
            Heap_Free(p);
        }
        *pp = NULL;
    }
    gSysState->cur = saved;
}

static inline void Ov011_FreeAnimP(Ov011Anim **pp) {
    void *saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (*pp != NULL) {
        Ov011Anim *p = *pp;
        if (p != NULL) {
            ResSet_ReleaseAll(p);
            Heap_Free(p);
        }
        *pp = NULL;
    }
    gSysState->cur = saved;
}

static inline Actor *Ov011_FindActorN(u16 id) {
    Actor *a = NULL;
    if (gActorMgr != NULL) {
        a = (Actor *)ActorMgr_GetActor(gActorMgr, id);
    }
    return a;
}

static inline void Ov011Model2_Reset(Ov011Model2 *m) {
    if (m->b0) {
        m->b0 = 0;
        Ov011_FreeModelP(&m->model);
        OV011_TWV(m->m0c)->v08();
        OV011_TWV(m->m3c)->v08();
    }
}

static inline void Ov011Chr_Reset(Ov011Chr *self) {
    u32 i;
    if (!self->b0) {
        return;
    }
    Ov011Model2_Reset(&self->m28);
    Ov003Ticker_Release_021d7d8c(self->s88);
    for (i = 0; i < 3; i++) {
        Ov003Ticker_Release_021d7d8c(self->s94[i]);
    }
    self->b0 = 0;
}

static inline void Ov011TwA_Ctor(void *obj) {
    *(void **)obj = Ov011Vt_022079d0_vtbl;
    OV011_TW(obj)->b0 = 0;
}

static inline void Ov011Tw_SetBoth(Ov011Tw *t, const VecFx32 *src) {
    s32 x;
    s32 y;
    s32 z;
    x = src->x;
    t->v08.x = x;
    y = src->y;
    t->v08.y = y;
    z = src->z;
    t->v08.z = z;
    t->v14.x = x;
    t->v14.y = y;
    t->v14.z = z;
}

static inline void Ov011TwB_Ctor(void *obj) {
    Ov011Tw *t;
    *(void **)obj = Ov011Vt_022079b0_vtbl;
    t = OV011_TW(obj);
    t->b0 = 0;
    t->b1 = 0;
    t->unk_02 = 0;
    Ov011Tw_SetBoth(t, &data_ov011_02207438);
}

extern "C" {

Ov011Chr *Ov011Chr_Ctor(Ov011Chr *self) {
    void *p;
    Ov011TwA_Ctor(self->m28.m0c);
    Ov011TwB_Ctor(self->m28.m3c);
    self->m28.b0 = 0;
    Ov003Ticker_Clear_021d7ca8(self->s88);
    __cxa_vec_ctor(self->s94, 3, 0xc, Ov003Ticker_Clear_021d7ca8, Ov003Ticker_Release_021d7ce0);
    self->b0 = 0;
    self->b1 = 0;
    p = Heap_Alloc(0x138);
    if (p != NULL) {
        p = ResSet_Init(p);
    }
    self->anim = (Ov011Anim *)p;
    p = Heap_Alloc(0xe8);
    if (p != NULL) {
        p = Model0218fe1c_Init(p);
    }
    self->model = (Model0218fe1c *)p;
    return self;
}

}

static inline void Ov011TwB_Dtor(void *obj) {
    *(void **)obj = Ov011Vt_022079b0_vtbl;
    OV011_TWV(obj)->v08();
}

static inline void Ov011TwA_Dtor(void *obj) {
    *(void **)obj = Ov011Vt_022079d0_vtbl;
    OV011_TWV(obj)->v08();
}

extern "C" {


Ov011Chr *Ov011Chr_Dtor(Ov011Chr *self) {
    Ov011Chr_Reset(self);
    Ov011_FreeAnimP(&self->anim);
    Ov011_FreeModelP(&self->model);
    __cxa_vec_cleanup(self->s94, 3, 0xc, Ov003Ticker_Release_021d7ce0);
    Ov003Ticker_Release_021d7ce0(self->s88);
    Ov011Model2_Reset(&self->m28);
    Ov011TwB_Dtor(self->m28.m3c);
    Ov011TwA_Dtor(self->m28.m0c);
    return self;
}

BOOL Ov011Chr_Init(Ov011Chr *self, u16 id, const VecFx32 *off, u16 c, s16 d, s16 e) {
    Actor *a;
    u32 i;
    self->id = id;
    self->b0 = 1;
    self->unk_02 = e;
    self->unk_04 = d;
    self->unk_06 = c;
    self->unk_08 = 0;
    self->mode = 0;
    self->off = *off;
    self->unk_24 = 0;
    func_ov000_02193e5c(self->anim, 0x4812);
    a = Ov011_FindActorN(self->id);
    if (a != NULL) {
        VecFx32 p;
        p = a->pos;
        VEC_Add(&p, &self->off, &p);
        self->model->trans = p;
    }
    Ov003Ticker_Start_021d7d24(self->s88, 0, 0, 1, 0);
    for (i = 0; i < 3; i++) {
        Ov003Ticker_Start_021d7d24(self->s94[i], 0, 0, 1, 0);
    }
    return TRUE;
}

void Ov011Chr_Reset_0220205c(Ov011Chr *self) {
    Ov011Chr_Reset(self);
}

void Ov011Chr_Update(Ov011Chr *self) {
    s32 key;
    u32 i;
    if (!self->b0) {
        return;
    }
    // Read through a const view (as CFLD did): a plain read lets MWCC reuse the b0 load.
    if (!((const Ov011Chr *)self)->b1) {
        if (self->anim->unk_00 < 0) {
            s32 r;
            self->b1 = 1;
            r = Tbl_FindEntry_0206fef8(0x4812);
            self->model->actor_id = 0xffff;
            Model0218fe1c_Setup(self->model, self->anim, r);
            self->model->visible = 0;
            Ov011Model2_Init(&self->m28, self->anim, 0x4812);
        } else {
            ResSet_UpdateLoad(self->anim);
        }
        return;
    }
    key = self->mode;
    for (i = 0; i < 6; i++) {
        if (key == Ov011Chr_ModeTable[i].key && *(s32 *)&Ov011Chr_ModeTable[i].fn != 0) {
            (self->*Ov011Chr_ModeTable[i].fn)();
            break;
        }
    }
    Ov003Ticker_Update_021d7dd0(self->s88);
    for (i = 0; i < 3; i++) {
        Ov003Ticker_Update_021d7dd0(self->s94[i]);
    }
    Ov011Model2_Update(&self->m28);
}

void Ov011Chr_Draw(Ov011Chr *self) {
    if (!self->b0) {
        return;
    }
    if (self->model != NULL) {
        VecFx32 p;
        VecFx32 sv;
        VecFx32 sa;
        VecFx32 q;
        VecFx32 s;
        Actor *a = Ov011_FindActor(self->id);
        if (a != NULL) {
            p = a->pos;
            VEC_Add(&p, &self->off, &p);
            self->model->trans = p;
        }
        sv = self->model->trans;
        sa = self->model->scale;
        OV011_BLKCPY(&q, &sv);
        OV011_BLKCPY(&s, &sa);
        q.x += Ov011Ticker_ScaledValue(self->s94[0], 0x19a);
        q.y += Ov011Ticker_ScaledValue(self->s94[1], 0x19a);
        q.z += Ov011Ticker_ScaledValue(self->s94[2], 0x19a);
        s.x += Ov011Ticker_ScaledValue(self->s88, 0x19a);
        s.y = s.x;
        self->model->trans = q;
        self->model->scale = s;
        Model021903b4_Draw(self->model);
        self->model->trans = sv;
        self->model->scale = sa;
    }
    if (!self->m28.b0) {
        return;
    }
    if (!self->m28.b2) {
        return;
    }
    Model021903b4_Draw(self->m28.model);
}

void Ov011Chr_StartMode1(Ov011Chr *self) {
    if (self->b0) {
        self->unk_08 = 0;
        self->unk_24 = 0;
        self->mode = 1;
    }
}

void Ov011Chr_StartMode3(Ov011Chr *self, u16 v) {
    if (self->b0) {
        self->unk_24 = 0;
        self->mode = 3;
        self->unk_08 = v;
    }
}

void Ov011Chr_StartMode5(Ov011Chr *self, u16 v) {
    if (self->b0 && v != 0) {
        self->unk_24 = 0;
        self->mode = 5;
        self->unk_08 = v;
    }
}


VecFx32 Ov011Chr_GetPos(const Ov011Chr *self) {
    VecFx32 v = data_ov011_02207438;
    if (self->b0) {
        Model0218fe1c *m = self->model;
        v.x = m->trans.x;
        v.y = m->trans.y;
        v.z = m->trans.z;
    }
    return v;
}

}
}  // namespace m_02201c18

// ---- merged from ov011_02202538.cpp
namespace m_02202538 {
struct Ov011Chr {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_01;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    u16 id;
    s32 mode;
    VecFx32 off;
    Ov011Anim *anim;
    Model0218fe1c *model;
    EffectObj *unk_24;
    Ov011Model2 m28;
    u8 s88[0xc];
    u8 s94[3][0xc];
};

extern "C" {

extern VecFx32 data_ov011_02207474;
extern const VecFx32 data_ov011_02207480;
extern u8 data_ov011_0220748c[];

// unk_06 is read through a const view; a plain read schedules differently.
static inline s32 Ov011_Progress(Ov011Chr *c, s32 n) {
    return FX_Div(n << 12, ((const Ov011Chr *)c)->unk_06 << 12);
}

void Ov011Chr_UpdateMode1(Ov011Chr *self) {
    switch (self->mode) {
    case 1: {
        VecFx32 s;
        VecFx32 pos;
        VecFx32 c;
        VecFx32 t;
        s32 r = Ov011_Progress(self, self->unk_06);
        s32 lo = self->unk_04;
        s32 hi = self->unk_02;
        s32 v = lo + FX_Mul(hi - lo, r);
        v = v > hi ? hi : (v < lo ? lo : v);
        OV011_BLKCPY(&t, &data_ov011_02207474);
        t.x = v;
        t.y = v;
        OV011_BLKCPY(&s, &t);
        self->model->scale = s;
        self->model->visible = 1;
        pos = self->model->trans;
        OV011_BLKCPY(&c, &data_ov011_02207480);
        self->unk_24 = Effect_SpawnId(0x38a, &pos);
        self->unk_24->SetScale(&c);
        self->unk_24->AddPosXYZ(0, -0x14cd, 0);
        self->mode = 2;
        break;
    }
    case 2:
        if (!EffectMgr_Contains(gEffectMgr, self->unk_24)) {
            self->mode = 0;
            self->unk_24 = NULL;
        }
        break;
    }
}


static inline BOOL Ov011Model2_Idle(Ov011Model2 *m) {
    BOOL r = FALSE;
    if (m->b0) {
        if (!m->b2) {
            r = TRUE;
        }
    }
    return r;
}

void Ov011Chr_UpdateMode3(Ov011Chr *self) {
    switch (self->mode) {
    case 3: {
        VecFx32 s;
        VecFx32 pos;
        VecFx32 t;
        s16 a;
        s16 b;
        s32 r = FX_Div(self->unk_08 << 12, ((const Ov011Chr *)self)->unk_06 << 12);
        s32 lo = self->unk_04;
        s32 hi = self->unk_02;
        s32 v = lo + FX_Mul(hi - lo, r);
        v = v > hi ? hi : (v < lo ? lo : v);
        OV011_BLKCPY(&t, &data_ov011_02207474);
        t.x = v;
        t.y = v;
        OV011_BLKCPY(&s, &t);
        self->model->scale = s;
        self->model->visible = 1;
        pos = self->model->trans;
        self->unk_24 = Effect_SpawnId(0x648, &pos);
        self->unk_24->SetScaleXYZ(0x2000, 0x2000, 0x2000);
        b = s.x + 0x1500;
        a = s.x;
        if (self->m28.b0) {
            self->m28.b1 = 1;
            self->m28.b2 = 0;
            MI_Copy36B(data_ov011_0220748c, &self->m28.model->rot);
            self->m28.model->trans = pos;
            self->m28.unk_02 = a;
            self->m28.unk_04 = b;
        }
        self->mode = 4;
        break;
    }
    case 4: {
        BOOL done = EffectMgr_Contains(gEffectMgr, self->unk_24) ? FALSE : TRUE;
        if (done) {
            done = Ov011Model2_Idle(&self->m28);
        }
        if (done) {
            self->mode = 0;
            self->unk_24 = NULL;
        }
        break;
    }
    }
}

void Ov011Chr_UpdateMode5(Ov011Chr *self) {
    switch (self->mode) {
    case 5: {
        VecFx32 s;
        VecFx32 c;
        VecFx32 pos;
        VecFx32 t;
        s32 r;
        s32 lo;
        s32 hi;
        s32 v;
        if (self->unk_08 <= 1) {
            self->model->visible = 0;
            self->mode = 0;
            return;
        }
        self->model->visible = 1;
        r = FX_Div((s16)(self->unk_08 - 1) << 12, self->unk_06 << 12);
        lo = self->unk_04;
        hi = self->unk_02;
        v = lo + FX_Mul(hi - lo, r);
        v = v > hi ? hi : (v < lo ? lo : v);
        OV011_BLKCPY(&t, &data_ov011_02207474);
        t.x = v;
        t.y = v;
        OV011_BLKCPY(&s, &t);
        self->model->scale = s;
        OV011_BLKCPY(&c, &data_ov011_0220742c);
        pos = self->model->trans;
        self->unk_24 = Effect_SpawnId(0x579, &pos);
        self->unk_24->SetScale(&c);
        self->mode = 6;
        break;
    }
    case 6:
        if (!EffectMgr_Contains(gEffectMgr, self->unk_24)) {
            self->mode = 0;
            self->unk_24 = NULL;
        }
        break;
    }
}

}
}  // namespace m_02202538

// ---- merged from ov011_02202a38.cpp
namespace m_02202a38 {
struct Ov011TwA {
    Ov011V *vt;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_05;
    s16 speed;
    s32 t;
    VecFx32 from;
    VecFx32 to;
    VecFx32 cur;
};

struct Ov011TwB {
    Ov011V *vt;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk_05;
    s16 speed;
    s32 dist;
    VecFx32 cur;
    VecFx32 to;
};


extern "C" {

extern u16 data_ov011_02207f00;
extern u8 Ov011Vt_022079d0_vtbl[];
extern u8 Ov011Vt_022079b0_vtbl[];
extern u8 data_ov011_022074f8[];
s32 func_0203db40(void *p);
void Model0218fe1c_UpdateAnim(void *a, s32 b);
BOOL Stage_UseScaledStats(void);

void func_ov011_02202a38(void) {
    data_ov011_02207f00 += 0x51e;
}

Ov011TwA *Ov011Vt_022079d0_Ctor(Ov011TwA *self) {
    self->vt = (Ov011V *)Ov011Vt_022079d0_vtbl;
    self->b0 = 0;
    return self;
}

Ov011TwA *Ov011Vt_022079d0_Dtor(Ov011TwA *self) {
    self->vt = (Ov011V *)Ov011Vt_022079d0_vtbl;
    ((Ov011V *)self)->v08();
    return self;
}

Ov011TwA *Ov011Vt_022079d0_DtorDelete(Ov011TwA *self) {
    self->vt = (Ov011V *)Ov011Vt_022079d0_vtbl;
    ((Ov011V *)self)->v08();
    Heap_Free(self);
    return self;
}

BOOL Ov011TwA_Start(Ov011TwA *self, const VecFx32 *to, const VecFx32 *from, s32 speed, u8 loop) {
    self->b0 = 1;
    self->b1 = loop;
    self->t = 0;
    self->from = *from;
    self->to = *to;
    self->cur = *from;
    self->speed = FX_Div(speed, VEC_Distance(to, from));
    return TRUE;
}

void Ov011TwA_Stop(Ov011TwA *self) {
    if (self->b0) {
        self->b0 = 0;
    }
}

static inline void Ov011_Lerp(s32 t, const VecFx32 *a, const VecFx32 *b, VecFx32 *out) {
    VecFx32 d;
    d.x = b->x - a->x;
    d.y = b->y - a->y;
    d.z = b->z - a->z;
    VEC_MultAdd(t, &d, a, out);
}

void Ov011TwA_Update(Ov011TwA *self) {
    if (!self->b0) {
        return;
    }
    self->t += self->speed;
    if (!self->b1 && self->t >= 0x1000) {
        self->t = 0x1000;
        return;
    }
    Ov011_Lerp(self->t, &self->from, &self->to, &self->cur);
}

VecFx32 *Ov011Vt_022079d0_GetCur(Ov011TwA *self) {
    VecFx32 *r = NULL;
    if (self->b0) {
        r = &self->cur;
    }
    return r;
}

BOOL Ov011Vt_022079d0_IsDone(Ov011TwA *self) {
    if (self->b0 && self->t >= 0x1000) {
        return TRUE;
    }
    return FALSE;
}

static inline void Ov011TwB_SetBoth(Ov011TwB *t, const VecFx32 *src) {
    s32 x;
    s32 y;
    s32 z;
    x = src->x;
    t->cur.x = x;
    y = src->y;
    t->cur.y = y;
    z = src->z;
    t->cur.z = z;
    t->to.x = x;
    t->to.y = y;
    t->to.z = z;
}

Ov011TwB *Ov011Vt_022079b0_Ctor(Ov011TwB *self) {
    self->vt = (Ov011V *)Ov011Vt_022079b0_vtbl;
    self->b0 = 0;
    self->b1 = 0;
    self->speed = 0;
    Ov011TwB_SetBoth(self, &data_ov011_02207438);
    return self;
}

Ov011TwB *Ov011Vt_022079b0_Dtor(Ov011TwB *self) {
    self->vt = (Ov011V *)Ov011Vt_022079b0_vtbl;
    ((Ov011V *)self)->v08();
    return self;
}

Ov011TwB *Ov011Vt_022079b0_DtorDelete(Ov011TwB *self) {
    self->vt = (Ov011V *)Ov011Vt_022079b0_vtbl;
    ((Ov011V *)self)->v08();
    Heap_Free(self);
    return self;
}

BOOL Ov011TwB_Start(Ov011TwB *self, const VecFx32 *to, const VecFx32 *from, s16 speed) {
    self->b0 = 1;
    self->cur = *from;
    self->to = *to;
    self->speed = speed;
    self->dist = FX_Mul(VEC_Distance(&self->to, &self->cur), 0x14);
    return TRUE;
}

void Ov011TwB_Stop(Ov011TwB *self) {
    if (!self->b0) {
        return;
    }
    self->b0 = 0;
    self->b1 = 0;
    self->speed = 0;
    Ov011TwB_SetBoth(self, &data_ov011_02207438);
}

void Ov011TwB_Update(Ov011TwB *self) {
    VecFx32 d;
    s32 len;
    if (!self->b0) {
        return;
    }
    if (self->b1) {
        return;
    }
    d.x = self->to.x - self->cur.x;
    d.y = self->to.y - self->cur.y;
    d.z = self->to.z - self->cur.z;
    len = VEC_Mag(&d);
    if (len < 0) {
        len = -len;
    }
    if (len <= self->dist) {
        self->cur = self->to;
        self->b1 = 1;
    } else {
        VEC_MultAdd(self->speed, &d, &self->cur, &self->cur);
    }
}

VecFx32 *Ov011Vt_022079b0_GetCur(Ov011TwB *self) {
    return self->b0 ? &self->cur : NULL;
}

u32 Ov011TwB_IsArrived(Ov011TwB *self) {
    return self->b1;
}

u32 Ov011TwB_IsActive(Ov011TwB *self) {
    return self->b0;
}

void Ov011Mov_Init(Ov011Mov *self) {
    self->active = 0;
    self->accel = 0;
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = 0;
    self->vel.x = 0;
    self->vel.y = 0;
    self->vel.z = 0;
}

void Ov011Mov_Stop(Ov011Mov *self) {
    if (!self->active) {
        return;
    }
    self->active = 0;
    self->accel = 0;
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = 0;
    self->vel.x = 0;
    self->vel.y = 0;
    self->vel.z = 0;
}

BOOL Ov011Mov_Start(Ov011Mov *self, const VecFx32 *pos, const VecFx32 *vel, s32 scale, s32 accel) {
    self->active = 1;
    self->pos = *pos;
    self->vel.x = FX_Mul(vel->x, scale);
    self->vel.y = FX_Mul(vel->y, scale);
    self->vel.z = FX_Mul(vel->z, scale);
    self->accel = accel;
    return TRUE;
}

void Ov011Mov_Stop_02202fbc(Ov011Mov *self) {
    if (!self->active) {
        return;
    }
    self->active = 0;
    self->accel = 0;
    self->pos.x = 0;
    self->pos.y = 0;
    self->pos.z = 0;
    self->vel.x = 0;
    self->vel.y = 0;
    self->vel.z = 0;
}

void Ov011Mov_Update(Ov011Mov *self) {
    if (!self->active) {
        return;
    }
    self->vel.y += self->accel;
    VEC_Add(&self->pos, &self->vel, &self->pos);
}

VecFx32 *Ov011Mov_GetPos(Ov011Mov *self) {
    VecFx32 *r = NULL;
    if (self->active) {
        r = &self->pos;
    }
    return r;
}

void Ov011Npc_Animate(Actor *self) {
    if (self->model == NULL) {
        return;
    }
    Model0218fe1c_UpdateAnim(self->model, func_0203db40(&self->pause));
}

void Ov011Npc_State23(Ov003Actor *self) {
}

void Ov011Npc_State22(Ov003Actor *self) {
}

void Ov011Npc_State21(Ov003Actor *self) {
}

void Ov011Npc_State20(Ov003Actor *self) {
}

void Ov011Npc_StateHurt(Ov003Actor *self) {
}

void Ov011Npc_State0e(Ov003Actor *self) {
}

void Ov011Npc_StateMove(Ov003Actor *self) {
}

void Ov011ActVt_02207b34_Start(Ov003Actor *self) {
    Ov003Actor_Start(self);
    if (Stage_UseScaledStats()) {
        Ov003Actor_ScaleStats(self, data_ov011_022074f8);
    }
}

}
}  // namespace m_02202a38
