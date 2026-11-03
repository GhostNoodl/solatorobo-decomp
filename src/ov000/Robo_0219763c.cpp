#include "nitro/fx.h"
#include "Main/Sys/FieldState.h"
#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"
#include "Main/Effect/Effect.h"
#include "nitro/mi.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    u8 unk_00[0x158];
    u32 flags[1][4];
} Save0219763c;

typedef struct {
    s16 snd;
    s16 fx0;
    s16 scale0;
    s16 fx1;
    s16 scale1;
    u8 a;
    u8 b;
} Ent0219763c;

extern "C" {
extern void *gGroup;
extern Save0219763c *gStageFlags;
extern Ent0219763c data_ov000_021c9ecc[];
extern void *gSndMgr;
void HitSphere_Unlink_0203f364(void *a);
void Group_UpdateActor(void *a, s32 b, void *c);
void Shared_SetEventActor(u16 kind, u16 id);
void func_020627dc(u16 sfx);
void func_020627c8(void);
void func_ov000_02182590(u8 *p);
u16 LangData_GetIndex(u32 a, u32 b);
Robo021ca458 *ActorMgr_FindPlayer(void);
BOOL Actor_IsDead(void);
void *SndMgr_PlayAt(void *mgr, s32 id, void *pos, s32 a);
void Field_ShakeCamera(u8 a, u8 b);
u8 *Tbl_Elem_020704b4(u16 id);
void Drop_SpawnWeighted(u16 *ids, u8 *rates, s32 n, void *pos, void *rot, u8 check);
void Body_SetOwner(void *p, u16 id);

static inline void SetNibble0219763c(s32 row, s32 idx, u32 value) {
    s32 sh = idx % 8;
    u32 *p;

    sh *= 4;
    p = &gStageFlags->flags[row][idx / 8];
    *p = (*p & ~(0xf << sh)) | ((value & 0xf) << sh);
}

static inline int GetNibble0219763c(s32 row, s32 idx) {
    u32 v = gStageFlags->flags[row][idx / 8];
    return (v >> ((idx % 8) * 4)) & 0xf;
}

struct Die0219763cSelf {
    u8 unk_00[0xc];
    u16 unk_0c;
    u16 unk_0e;
    u8 unk_10[0x7];
    u8 unk_17;
    u8 unk_18[0x94];
    u8 unk_ac;
    u8 unk_ad;
};

static inline void Die0219763c(VObj *obj) {
    Die0219763cSelf *self = (Die0219763cSelf *)obj;
    {
        u8 idx = self->unk_17;
        s32 row;
        if (idx != 0xff) {
            row = LangData_GetIndex(self->unk_ac, self->unk_ad);
            if (row != 0xffff) {
                u8 val = 0xf;
                val |= GetNibble0219763c(row, idx) & 8;
                SetNibble0219763c(row, idx, val);
            }
        }
    }
    if (ActorMgr_FindPlayer() != NULL && !Actor_IsDead()) {
        Shared_SetEventActor(self->unk_0e, self->unk_0c);
        func_020627dc(0x63);
        {
            FieldState *pl = gSceneCmd;
            ((u8 *)pl)[0xac] = 1;
            func_ov000_02182590((u8 *)pl + 0xac);
        }
    }
    func_020627c8();
    Group_UpdateActor(gGroup, 0, self);
    obj->vfunc_08();
}

static inline void Spawn0219763c(ActorEx *self, s16 id, const s16 *scale, VecFx32 *p) {
    EffectObj *fx = Effect_SpawnId(id, p);
    s32 s = *scale << 4;
    if (s == 0) {
        s = self->radius + (self->radius >> 3);
    }
    fx->SetScaleAll(s);
    if (!self->unk_cc_5) {
        MIi_CpuClear32(-1, (u8 *)fx + 0x84, 0x40);
    }
}

void ActorEx_StateDie(VObj *obj) {
    ActorEx *self = (ActorEx *)obj;
    s32 zero = 0;
    ActorSub40 *s = self->fsm;
    switch (s->st) {
    case 0: {
        u8 *t = ((u8 *)self->targetObj);
        Ent0219763c *e = (Ent0219763c *)zero;
        VecFx32 p;
        if (t != NULL) {
            if (t[2] != 1 && t[2] != 2) {
                Die0219763c(obj);
                return;
            }
            {
                u16 id = LFLD(u16, t, 6);
                if (id >= 0x14) {
                    id = 0;
                }
                e = &data_ov000_021c9ecc[id];
            }
        }
        p = *(VecFx32 *)((u8 *)self + 0x70);
        p.y += self->centerY + (self->centerY >> 1);
        if (e != NULL) {
            if (e->fx0 != -1) {
                Spawn0219763c(self, e->fx0, &e->scale0, &p);
            }
            if (e->fx1 != -1) {
                Spawn0219763c(self, e->fx1, &e->scale1, &p);
            }
            if (e->snd >= 0 && self->unk_cc_5) {
                SndMgr_PlayAt(gSndMgr, e->snd, &self->pos, 0);
            }
            if (e->a != 0 && e->b != 0) {
                Field_ShakeCamera(e->a, e->b);
            }
        }
        {
            u8 *r = Tbl_Elem_020704b4(self->kind);
            Drop_SpawnWeighted((u16 *)(r + 0x20), r + 0x24, 2, &p, (u8 *)self + 0x7c, zero);
        }
        if (self->unk_44 != NULL) {
            ActorSub44 *q = self->unk_44;
            q->unk_22_0 = 0;
            q->unk_22_1 = 0;
        }
        if (self->hit != NULL) {
            ActorSub48 *q;
            Body_SetOwner(self->hit, 0xffff);
            q = self->hit;
            q->unk_9a_0 = 0;
            q->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(q);
            q = self->hit;
            q->unk_9a_1 = 0;
            q->unk_9a_4 = 0;
        }
        if (self->hitMesh != NULL) {
            self->unk_cc_0 = 0;
        }
        self->fsm->st++;
        return;
    }
    case 1:
        s->timer++;
        if (s->timer > 5) {
            Die0219763c(obj);
            return;
        }
        if (self->model != NULL) {
            self->model->alpha = 0x1f - (self->fsm->timer << 2);
        }
        return;
    }
}

}
