#include "ov014/ov014.h"
#include "Main/Gfx/GfxMgr.h"

extern "C" {

extern u8 data_ov014_02217aac[];
extern char data_ov014_02217c6c[];
extern Ov003Actor *Target_Get(void *p);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern s32 Actor_FindInRadius(Actor *self, u16 mask, VecFx32 *pos, s32 r, s32 a, Ov003Actor **list);
extern Ov003Actor *Obj021984c8_GetActor(Ov003Actor *p);
extern AnimCtrl *Model0218fe1c_GetAnimCtrl(Model0218fe1c *self, u32 i);
extern s32 Model0218fe1c_SetAnimFrame(void *a, s32 b);
extern s32 AnimEvent_Exec(void *a, void *b);
extern s32 func_ov014_0220ec18(s16 *a, Model0218fe1c *b);
extern u8 Gfx3DState_NextPolyId(void *p);
extern void Model0218fe1c_SetAnim3(Model0218fe1c *a, s32 b, s16 c, u8 d);
extern void Model0218fe1c_ClearLoop(Model0218fe1c *p);
extern void Model0218fe1c_ResumeAnim(Model0218fe1c *p);

extern BOOL func_ov014_0220eb14(Actor *self);
extern BOOL Hit_ApplyInArea(void *a, void *b, u16 c, u8 d, s32 e, VecFx32 *v, s32 f, s32 g, s32 h, s32 i, s32 j);

#define OV014Y_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014Y_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014Y_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline s32 Ov014y_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void Ov014ActEx_0220dcf4_StateThrown(Ov014ActEx_0220dcf4 *self) {
    switch (self->fsm->st) {
    case 0: {
        VecFx32 *p;
        {
            ActorSub4c *m = self->targetObj;
            m->unk_50 = 0x1000;
            m->unk_54 = 0x29;
            m->unk_58 = 0;
        }
        self->hit->unk_30 = 0;
        p = Actor_GetTargetSub44(self);
        if (p != NULL) {
            VecFx32 d;
            s32 r;
            s32 dx;
            s32 dz;
            d = *p;
            d.y = d.y - self->pos.y;
            {
                s64 sq;
                dx = self->pos.x - d.x;
                dz = self->pos.z - d.z;
                sq = (s64)dx * dx;
                sq += (s64)dz * dz;
                OV014Y_SQRTCNT = 1;
                OV014Y_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV014Y_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014Y_SQRT_RESULT + 1) >> 1;
            d.x = FX_Mul(r, OV014_SIN(self->rot_y));
            d.z = FX_Mul(r, OV014_COS(self->rot_y));
            VEC_Normalize(&d, &d);
            self->speed = Ov014y_FxMul64(d.x, 0x800);
            self->velY = Ov014y_FxMul64(d.y, 0x800);
            self->friction = Ov014y_FxMul64(d.z, 0x800);
        } else {
            self->speed = OV014_SIN(self->rot_y);
            self->friction = OV014_COS(self->rot_y);
            self->speed = Ov014y_FxMul64(self->speed, 0x800);
            self->velY = Ov014y_FxMul64(self->velY, 0x800);
            self->friction = Ov014y_FxMul64(self->friction, 0x800);
        }
        {
            ActorSub48 *m = self->hit;
            m->unk_50 = 0;
            m->unk_54 = 0;
            m->unk_58 = 0;
        }
        EffectMgr_StopLoop(data_0214a420, self->unk_d0);
        self->unk_d0 = NULL;
        self->fsm->st++;
        break;
    }
    case 1: {
        void *a;
        VecFx32 v;
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        if (!(self->hit->unk_50 & 0xe0000000) && !func_ov014_0220eb14(self)) {
            return;
        }
        a = Target_Get(self->targetObj);
        v.x = self->pos.x - FLD(s32, self, 0x70);
        v.y = self->pos.y - FLD(s32, self, 0x74);
        v.z = self->pos.z - FLD(s32, self, 0x78);
        Hit_ApplyInArea(self, a, self->targetObj->unk_08, self->targetObj->unk_0a, 0x20, &v, 0,
                            0x4000, 0, 3, 0x1000);
        SndMgr_PlayAt(data_02097e4c, 0x82, &self->pos, 0);
        self->targetObj->unk_02 = 0;
        History_SetState(self->fsm, 0x15, 0);
        break;
    }
    }
}

void Ov014ActEx_0220dcf4_StateHeld(Ov014ActEx_0220dcf4 *self) {
    if (self->fsm->st == 0) {
        EffectMgr_StopLoop(data_0214a420, self->unk_d0);
        self->unk_d0 = NULL;
    }
    ActorEx_StateHeld(self);
}

void Ov014ActEx_0220dcf4_StateDie(Ov014ActEx_0220dcf4 *self) {
    if (self->fsm->st == 0) {
        EffectMgr_StopLoop(data_0214a420, self->unk_d0);
        self->unk_d0 = NULL;
    }
    ActorEx_StateDie(self);
}

BOOL func_ov014_0220eb14(Actor *self) {
    Ov003Actor *list[0x20];
    BOOL r = FALSE;
    Ov003Actor *o;
    Ov003Actor *p;
    u16 k;
    s32 i;
    u16 mask;
    s32 rad;
    s32 n;
    o = Target_Get(self->targetObj);
    p = ActorMgr_FindPlayer();
    if (o == NULL || p == NULL) {
        return FALSE;
    }
    k = o->id & 0xf000;
    mask = ~(1 << (k >> 12));
    rad = self->radius;
    if (o->kind == 0x1000) {
        rad = rad + 0x4cd;
    } else if (((Robo021ca458 *)p)->unk_b1e == self->id) {
        rad >>= 1;
    }
    n = Actor_FindInRadius(self, mask, &self->pos, rad, 0, list);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            Ov003Actor *q;
            if (list[i] != NULL && (q = Obj021984c8_GetActor(list[i])) != NULL) {
                ActorSub4c *s = q->targetObj;
                if (s == NULL || k != (u16)(s->target & 0xf000)) {
                    r = TRUE;
                    break;
                }
            }
        }
    }
    return r;
}


// The result is kept in the parameter slot: the original reuses a's register
// for the return value.
s32 func_ov014_0220ec18(s16 *a, Model0218fe1c *b) {
    AnimCtrl *q;
    s32 prev;
    if (a[0] == 5) {
        prev = 0;
        q = Model0218fe1c_GetAnimCtrl(b, 0);
        if (q != NULL && q->cur != NULL) {
            prev = q->cur->frame;
        }
        a = (s16 *)Model0218fe1c_SetAnimFrame(b, ((u16 *)a)[1] << 12);
        if (q != NULL) {
            s32 cur = (q->cur != NULL) ? q->cur->frame : 0;
            if (prev >= cur) {
                b->unk_e4 |= 0x20000000;
            }
        }
    } else {
        a = (s16 *)AnimEvent_Exec(a, b);
    }
    return (s32)a;
}

}
