#include "nitro/fx.h"
#include "ov000/Model0218fe1c.h"
#include "nitro/std.h"
#include "ov000/ActorParts.h"
#include "ov000/Obj0216c954.h"


extern "C" {

extern char *data_ov000_021cc8a0[2];
extern char data_ov000_021cc92d[];
void *Heap_Alloc(u32 size);
ActorRes *ResSet_Init(void *p);
Model0218fe1c *Model0218fe1c_Init(void *p);
BOOL ResSet_UpdateLoad(ActorRes *o);
BOOL Model0218fe1c_SetRes(Model0218fe1c *m, ActorRes *o, s32 a, s32 b);
BOOL Model0218fe1c_SetAnim(void *a, void *b, s32 c, s32 d);
void Model0218fe1c_SetLoop(void *a);
void Model0218fe1c_UpdateAnim(void *a, s32 b);
void Math_DirToAngles(u16 *out, VecFx32 *dir);
u16 Angle_Approach(u16 target, u16 cur, s32 step, s32 a, s32 b);

static inline void SetNamesA021c194c(ActorRes *o) {
    char **names = data_ov000_021cc8a0;
    char *n0 = names[0];
    char *n1 = names[1];
    STD_CopyString(o->unk_10, n0);
    STD_CopyString(o->unk_30, n1);
    o->unk_03_1 = 1;
}

static inline void SetNamesB021c194c(ActorRes *o) {
    char **names = data_ov000_021cc8a0;
    char *n0 = names[0];
    char *n1 = names[1];
    STD_CopyString(o->unk_4c, n0);
    STD_CopyString(o->unk_6c, n1);
    o->unk_03_2 = 1;
}

static inline ActorRes *GetObj021c194c(Obj021c2114 *s) {
    return s->res;
}

static inline BOOL Ready021c194c(ActorRes *o) {
    BOOL r = TRUE;
    if (o != NULL && o->unk_00 >= 0) {
        if (!ResSet_UpdateLoad(o)) {
            r = FALSE;
        }
    }
    return r;
}

#define SIN021c194c(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define COS021c194c(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])

void func_ov000_021c194c(Obj021c2114 *self);

#ifdef NONMATCHING
// Status (round auA): demoted in the honesty audit. The match declared the locals flag and p as two unused trailing
// parameters (callers pass only self); as locals at every position the registers differ. This file is the function's
// whole .text, so it has no delinks entry. The score is in docs/UNMATCHED.md;
// the default build takes this function from the dsd gap. History: docs/MATCHING.md round auA.
void func_ov000_021c194c(Obj021c2114 *self) {
    BOOL flag;
    ActorRes *p;
    MtxFx33 m_0;
    VecFx32 d4;
    VecFx32 d;
    MtxFx33 tmp;
    u16 a4[3];
    u16 ang[3];
    switch (self->state) {
    case 0:
    case 2:
    case 3:
    case 5:
    case 6:
    case 8:
    case 9:
        break;
    case 1: {
        p = (ActorRes *)Heap_Alloc(sizeof(ActorRes));
        if (p != NULL) {
            p = ResSet_Init(p);
        }
        self->res = p;
        SetNamesA021c194c(p);
        SetNamesB021c194c(GetObj021c194c(self));
        self->res->unk_00 = 0;
        self->state = 7;
    }
    case 7: {
        Model0218fe1c *m_1;
        if (!Ready021c194c(self->res)) {
            return;
        }
        m_1 = (Model0218fe1c *)Heap_Alloc(sizeof(Model0218fe1c));
        if (m_1 != NULL) {
            m_1 = Model0218fe1c_Init(m_1);
        }
        self->model = m_1;
        Model0218fe1c_SetRes(m_1, GetObj021c194c(self), 0, 1);
        Model0218fe1c_SetAnim(self->model, data_ov000_021cc92d, 0, 1);
        self->model->actor_id = 0;
        Model0218fe1c_SetLoop(self->model);
        m_1 = self->model;
        m_1->scale.x = 0xb33;
        m_1->scale.y = 0xb33;
        m_1->scale.z = 0xb33;
        self->state = 4;
    }
    case 4: {
        self->fadeFrame = 0;
        self->fade = 0;
        self->pulseFrame = 0xf000;
        self->pulse = 0x1000;
        if (!self->active) {
            return;
        }
        self->pulseUp = 1;
        d4.x = self->target.x - self->pos.x;
        d4.y = self->target.y - self->pos.y;
        d4.z = self->target.z - self->pos.z;
        VEC_Normalize(&d4, &d4);
        Math_DirToAngles(a4, &d4);
        self->rx = a4[0];
        self->ry = -a4[1];
        self->state = 10;
    }
    case 10: {
        BOOL set;
        u16 rz;
        s32 t;
        u16 ry;
        u16 rx;
        if (self->model == NULL) {
            return;
        }
        flag = FALSE;
        if (!self->active) {
            self->fadeFrame -= 0x1000;
        } else {
            self->fadeFrame += 0x1000;
        }
        t = FX_Div(self->fadeFrame, 0xf000);
        if (t >= 0x1000) {
            self->fadeFrame = 0xf000;
            t = 0x1000;
        } else if (t <= 0) {
            self->fadeFrame = 0;
            self->fade = 0;
            self->state = 4;
            return;
        } else if (self->active) {
            flag = TRUE;
        }
        self->fade = FX_SinCosTable_[((t << 14) >> 16) * 2];
        if (!flag) {
            if (!self->pulseUp) {
                self->pulseFrame -= 0x1000;
            } else {
                self->pulseFrame += 0x1000;
            }
            t = FX_Div(self->pulseFrame, 0xf000);
            if (t >= 0x1000) {
                if (self->pulseFrame > 0x78000) {
                    self->pulseUp = 0;
                }
                t = 0x1000;
            } else if (t <= 0) {
                if (self->pulseFrame < -0x78000) {
                    self->pulseUp = 1;
                }
                t = 0;
            }
            self->pulse = FX_SinCosTable_[((t << 14) >> 16) * 2];
        }
        d.x = self->target.x - self->pos.x;
        d.y = self->target.y - self->pos.y;
        d.z = self->target.z - self->pos.z;
        VEC_Normalize(&d, &d);
        Math_DirToAngles(ang, &d);
        self->rx = Angle_Approach(ang[0], self->rx, 0x266, 1, 0x8000);
        self->ry = Angle_Approach(-ang[1], self->ry, 0x266, 1, 0x8000);
        ry = self->ry;
        rz = self->rz;
        rx = self->rx;
        set = FALSE;
        MTX_Identity33_(&m_0);
        if (ry != 0) {
            MTX_RotY33_(&m_0, SIN021c194c(ry), COS021c194c(ry));
            set = TRUE;
        }
        if (rx != 0) {
            if (set) {
                MTX_RotX33_(&tmp, SIN021c194c(rx), COS021c194c(rx));
                MTX_Concat33(&tmp, &m_0, &m_0);
            } else {
                MTX_RotX33_(&m_0, SIN021c194c(rx), COS021c194c(rx));
                set = TRUE;
            }
        }
        if (rz != 0) {
            if (set) {
                MTX_RotZ33_(&tmp, SIN021c194c(rz), COS021c194c(rz));
                MTX_Concat33(&tmp, &m_0, &m_0);
            } else {
                MTX_RotZ33_(&m_0, SIN021c194c(rz), COS021c194c(rz));
            }
        }
        MI_Copy36B(&m_0, &self->model->rot);
        {
            Model0218fe1c *md = self->model;
            md->trans.x = self->pos.x;
            md->trans.y = self->pos.y;
            md->trans.z = self->pos.z;
        }
        Model0218fe1c_UpdateAnim(self->model, 0x1000);
        break;
    }
    }
}
#endif

}
