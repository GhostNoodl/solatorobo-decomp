#include "ov012/ov012.h"
#include "Main/Math/Rot16.h"

extern "C" {

extern char data_ov012_0220b34d[];
extern char data_ov012_0220b341[];
extern char data_ov012_0220b335[];
extern u8 data_ov012_0220a88c[];
extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *p, s16 a);
extern s16 *Model0218fe1c_SetAnimFrame(Model0218fe1c *a, s32 b);


#define OV012T_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV012T_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV012T_SQRT_PARAM (*(volatile u64 *)0x40002b8)

}

struct Ov012Query {
    VecFx32 pos;
    u16 unk_0c;
    u16 mask;
    u16 kind;
    u16 unk_12;
    u16 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    u16 exclude;
    union {
        u8 flags;
        struct {
            u8 b0 : 1;
            u8 b1 : 1;
            u8 b2 : 1;
            u8 b3 : 5;
        } bits;
    };
};

static inline void Ov012_Query_Init(Ov012Query *q) {
    q->mask = 0;
    q->kind = 0xffff;
    q->unk_12 = 0;
    q->unk_14 = 0;
    q->unk_18 = 0;
    q->unk_1c = 0;
    q->unk_20 = 0;
    q->unk_24 = 0;
    q->exclude = 0xffff;
    q->flags = 0;
}

static inline void Ov012_Query_SetPosRot(Ov012Query *q, const VecFx32 *pos, u16 rot) {
    q->pos = *pos;
    q->unk_0c = rot;
}

extern "C" {

extern char data_ov012_0220b347[];
extern s32 Finder_CollectActors(s32 *out, Ov012Query *q, void **list, s32 max);

#define OV012Q_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV012Q_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV012Q_SQRT_PARAM (*(volatile u64 *)0x40002b8)

void Ov012ActVt_0220b280_StateAttack3(Ov012ActVt_0220b280 *self) {
    switch (self->fsm->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov012_0220b347, 0x1000, 0);
        Model0218fe1c_SetAnimSpeed(self->model, 0xccd);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
        if (self->unk_1a == 0) {
            SndMgr_PlayAt(data_02097e4c, 0x600, &self->pos, 0);
        }
    case 1: {
        Ov003Actor *list[0x20];
        ActorSub48 *p48;
        self->unk_44->unk_22_1 = 0;
        p48 = self->hit;
        p48->unk_9a_3 = 0;
        HitSphere_Unlink_0203f364(p48);
        Ov012Query q;
        VecFx32 v;
        s32 out;
        Rot16 r;
        Ov003Actor *tgt;
        s32 n;
        s32 i;
        u16 ang;
        Ov012_Query_Init(&q);
        Ov012_Query_SetPosRot(&q, &self->pos, self->rot_y);
        q.mask = 0x10;
        q.kind = 0x480e;
        q.unk_18 = 0;
        q.unk_1c = 0x3000;
        q.bits.b1 = 1;
        q.bits.b2 = 0;
        out = 0;
        n = Finder_CollectActors(&out, &q, (void **)list, 0x20);
        if (n != 0) {
            tgt = Ov012_FindActor(self->target);
            if ((tgt == NULL || tgt == self) != 0) {
                ang = self->rot_y;
            } else {
                ang = FX_Atan2(tgt->pos.x - self->pos.x, tgt->pos.z - self->pos.z);
            }
            for (i = 0; i < n; i++) {
                Ov003Actor *a = list[i];
                if (a != NULL && a->targetObj != NULL && a->targetObj->target != 0xffff &&
                    a->targetObj->target != self->id) {
                    Actor *o;
                    a->vfunc_08();
                    r.x = 0;
                    r.y = ang;
                    r.z = 0;
                    v = list[i]->pos;
                    if (tgt != NULL) {
                        s32 sq_r;
                        {
                            s64 sq;
                            s32 dx = tgt->pos.x - v.x;
                            s32 dz = tgt->pos.z - v.z;
                            sq = (s64)dx * dx;
                            sq += (s64)dz * dz;
                            OV012Q_SQRTCNT = 1;
                            OV012Q_SQRT_PARAM = (u64)(sq * 4);
                        }
                        while (OV012Q_SQRTCNT & 0x8000) {
                        }
                        sq_r = (s32)(OV012Q_SQRT_RESULT + 1) >> 1;
                        r.x = FX_Atan2(v.y, sq_r);
                    }
                    o = Ov003Actor_SpawnChild(self, 0x480e, &v, &r, tgt);
                    if (o != NULL) {
                        o->unk_60 = data_ov012_0220a88c;
                        if (Stage_UseScaledStats()) {
                            func_ov000_0219bebc(o, 0x1800);
                        }
                    }
                    Effect_SpawnId(0x69, &v)->SetScaleAll(0xccd);
                    SndMgr_PlayAt(data_02097e4c, 0x2c, &self->pos, 0);
                }
            }
        }
        Model0218fe1c_SetAnimDelay(self->model, 0, 1);
        if (!Model0218fe1c_IsAnimDone(self->model)) {
            break;
        }
        Model0218fe1c_SetAnim(self->model, data_ov012_0220b341, 0x19a, 0);
        Model0218fe1c_SetLoop(self->model);
        self->fsm->st++;
        break;
    }
    case 2: {
        ActorSub40 *s = self->fsm;
        s->timer++;
        if (s->timer > 0x5a) {
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
    }
}

}

extern "C" {

static inline u16 Ov012_HpPct(Ov003Actor *self) {
    return self->hp[0] * 100 / self->hp[1];
}

void Ov012ActVt_0220b280_StateShoot(Ov012ActVt_0220b280 *self) {
    VecFx32 v;
    Rot16 r;
    Ov003Actor *pl;
    BOOL on;
    u16 add;
    ActorSub40 *s;
    pl = Actor_GetTarget(self);
    s = self->fsm;
    switch (s->st) {
    case 0:
        Model0218fe1c_SetAnim(self->model, data_ov012_0220b34d, 0x333, 0);
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->fsm->st++;
        break;
    case 1:
        s->timer++;
        if (s->timer > 10) {
            self->fsm->timer = 0;
            self->fsm->st++;
        }
        Actor_TurnToActor(self, pl, 0x59a);
        break;
    case 2: {
        s16 c4 = self->model->anim_state;
        on = FALSE;
        add = 0;
        if (c4 == 1) {
            if (Ov012_HpPct(self) <= 0x32) {
                on = TRUE;
                add = 0xd800;
            }
        } else if (c4 == 2) {
            if (Ov012_HpPct(self) <= 0x50) {
                on = TRUE;
                add = 0xec00;
            }
        } else if (c4 == 3) {
            on = TRUE;
        } else if (c4 == 4) {
            if (Ov012_HpPct(self) <= 0x50) {
                on = TRUE;
                add = 0x1400;
            }
        } else if (c4 == 5) {
            if (Ov012_HpPct(self) <= 0x32) {
                on = TRUE;
                add = 0x2800;
            }
            s->st++;
        }
        if (!on) {
            break;
        }
        r = *(Rot16 *)&self->rot_x;
        r.y += add;
        {
        s32 y = self->centerY;
        v.x = 0;
        v.y = y;
        v.z = 0x1000;
        }
        Vec_RotateY(&v, &v, r.y);
        VEC_Add(&v, &self->pos, &v);
        if (pl != NULL) {
            s32 sq_r;
            {
                s64 sq;
                s32 dx = pl->pos.x - v.x;
                s32 dz = pl->pos.z - v.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                OV012T_SQRTCNT = 1;
                OV012T_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV012T_SQRTCNT & 0x8000) {
            }
            sq_r = (s32)(OV012T_SQRT_RESULT + 1) >> 1;
            r.x = FX_Atan2(v.y, sq_r);
        }
        {
            Actor *o = Ov003Actor_SpawnChild(self, 0x480e, &v, &r, pl);
            if (o != NULL) {
                o->unk_60 = data_ov012_0220a88c;
                if (Stage_UseScaledStats()) {
                    func_ov000_0219bebc(o, 0x1800);
                }
            }
        }
        break;
    }
    case 3:
        if (Model0218fe1c_IsAnimDone(self->model)) {
            Model0218fe1c_SetAnim(self->model, data_ov012_0220b341, 0x19a, 0);
            Model0218fe1c_SetLoop(self->model);
            self->fsm->st++;
        }
        break;
    case 4:
        if (self->hit->unk_50 & 0x20000000) {
            Model0218fe1c_SetAnim(self->model, data_ov012_0220b335, 0x800, 0);
            Model0218fe1c_SetAnimFrame(self->model, 0x8000);
            self->fsm->st++;
        }
        break;
    case 5:
        s->timer++;
        if (s->timer > 10) {
            History_SetState(self->fsm, 1, 0);
        }
        break;
    }
    Actor_Move(self, 0);
    Body_Update(self->hit, 0, 0, 0);
    if (self->hit->unk_50 & 0x20000000) {
        self->velY = 0;
    }
}

}


extern "C" {
void Ov012ActVt_0220b280_StateDown(Ov012ActVt_0220b280 *self) {
    if (self->fsm->st == 0) {
        if (*self->hp == 0) {
            if (self->unk_1a == 0) {
                SndMgr_PlayAt(data_02097e4c, 0x603, &self->pos, 0);
            }
        } else {
            if (self->unk_1a == 0) {
                SndMgr_PlayAt(data_02097e4c, 0x602, &self->pos, 0);
            }
        }
    }
    Ov003Actor_StateDown(self);
}
}

extern "C" {
void Ov012ActVt_0220b280_StateHurt(Ov012ActVt_0220b280 *self) {
    if (self->fsm->st == 0 && self->unk_1a == 0) {
        SndMgr_PlayAt(data_02097e4c, 0x602, &self->pos, 0);
    }
    Ov003Actor_StateHurt(self);
}
}

extern "C" {
void Ov012ActVt_0220b280_StateKnockBack(Ov012ActVt_0220b280 *self) {
    if (self->fsm->st == 0 && self->unk_1a == 0) {
        SndMgr_PlayAt(data_02097e4c, 0x603, &self->pos, 0);
    }
    Ov003Actor_StateKnockBack(self);
}
}

extern "C" {
void Ov012ActVt_0220b280_StateDie(Ov012ActVt_0220b280 *self) {
    if (self->fsm->st == 0) {
        EffectObj *e;
        ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x480e, 0x15);
        e = Effect_SpawnId(0x69, &self->pos);
        if (e != NULL) {
            e->SetScaleAll(0x2400);
            e->AddPosXYZ(0, self->centerY, 0);
        }
    }
    Ov003Actor_StateDie(self);
}
}

extern "C" {
Ov012ActVt_0220b280 *Ov012ActVt_0220b280_Dtor(Ov012ActVt_0220b280 *self) {
    ResSet_ReleaseAll(&self->unk_f0);
    Ov003Actor_DtorBase(self);
    return self;
}
}

extern "C" {
Ov012ActVt_0220b280 *Ov012ActVt_0220b280_DtorDelete(Ov012ActVt_0220b280 *self) {
    ResSet_ReleaseAll(&self->unk_f0);
    Ov003Actor_DtorBase(self);
    Heap_Free(self);
    return self;
}
}

extern "C" {
void Ov012ActVt_0220b35c_Init(Ov003Actor *self) {
    Ov003Actor_Init(self);
    SndMgr_LoadHeapState(data_02097e4c, 1, 1);
    SndMgr_RequestLoad_02049678(data_02097e4c, 4, 7, -1);
}
}

extern "C" {
BOOL Ov012ActVt_0220b35c_IsReady(Ov003Actor *self) {
    BOOL r = Actor_IsReady(self);
    if (r && !SndMgr_IsLoadDone(data_02097e4c)) {
        r = FALSE;
    }
    return r;
}
}

extern "C" {
extern const u8 data_ov012_0220a8d0[];
extern const u8 data_ov012_0220a8c8[];
void Ov012ActVt_0220b35c_Start(Ov003Actor *self) {
    Ov003Actor_Start(self);
    if (Stage_UseScaledStats()) {
        Ov003Actor_ScaleStats(self, data_ov012_0220a8d0);
        return;
    }
    if (self->kind == 0x5036) {
        Ov003Actor_ScaleStats(self, data_ov012_0220a8c8);
    }
}
}
