#include "ov014/ov014.h"

extern "C" {

extern Ov003Actor *Target_Get(void *p);
extern Ov003Actor *ActorMgr_FindPlayer(void);
extern s32 Actor_FindInRadius(Actor *self, u16 mask, VecFx32 *pos, s32 r, s32 a, Ov003Actor **list);
extern Ov003Actor *Obj021984c8_GetActor(Ov003Actor *p);

extern void Model0218fe1c_SetAnimSpeed(Model0218fe1c *a, s16 b);
extern void Ov003Pickup_Update(Actor *self, s32 a);
extern BOOL func_ov014_02216324(Actor *self);

#define OV014Z_SQRTCNT (*(volatile u16 *)0x40002b0)
#define OV014Z_SQRT_RESULT (*(volatile u32 *)0x40002b4)
#define OV014Z_SQRT_PARAM (*(volatile u64 *)0x40002b8)

static inline s32 Ov014z_FxMul64(s32 a, s64 b) {
    return (s32)((a * b + 0x800) >> 12);
}

void func_ov014_02215ffc(Ov014ActEx_022152e8 *self) {
    Target_Get(self->targetObj);
    switch (self->fsm->st) {
    case 0: {
        VecFx32 *p;
        Model0218fe1c_SetAnimSpeed(self->model, 0x1000);
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
                OV014Z_SQRTCNT = 1;
                OV014Z_SQRT_PARAM = (u64)(sq * 4);
            }
            while (OV014Z_SQRTCNT & 0x8000) {
            }
            r = (s32)(OV014Z_SQRT_RESULT + 1) >> 1;
            d.x = FX_Mul(r, OV014_SIN(self->rot_y));
            d.z = FX_Mul(r, OV014_COS(self->rot_y));
            VEC_Normalize(&d, &d);
            self->speed = Ov014z_FxMul64(d.x, 0x39a);
            self->velY = Ov014z_FxMul64(d.y, 0x39a);
            self->friction = Ov014z_FxMul64(d.z, 0x39a);
        } else {
            self->speed = OV014_SIN(self->rot_y);
            self->friction = OV014_COS(self->rot_y);
            self->speed = Ov014z_FxMul64(self->speed, 0x39a);
            self->velY = Ov014z_FxMul64(self->velY, 0x39a);
            self->friction = Ov014z_FxMul64(self->friction, 0x39a);
        }
        {
            ActorSub48 *m = self->hit;
            m->unk_50 = 0;
            m->unk_54 = 0;
            m->unk_58 = 0;
        }
        self->unk_ec = 0;
        self->fsm->st++;
        break;
    }
    case 1:
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        self->unk_f4++;
        if ((self->hit->unk_50 & 0xe0000000) || func_ov014_02216324(self) || self->unk_f4 >= 0xf0) {
            Ov003Pickup_Update(self, 0);
            History_SetState(self->fsm, 0x15, 0);
        }
        break;
    }
    self->unk_3c->unk_14 = 0x2000;
}

void Ov014ActEx_022152e8_StateHeld(Ov014ActEx_022152e8 *self) {
    ActorEx_StateHeld(self);
}

void Ov014ActEx_022152e8_State0a(Ov014ActEx_022152e8 *self) {
    History_SetState(self->fsm, 0x15, 0);
}

BOOL func_ov014_02216324(Actor *self) {
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
    k = o->id & 0xf000;
    mask = ~(1 << (k >> 12));
    rad = self->radius;
    if (o->kind == 0x1000) {
        rad = rad + 0x4cd;
    } else if (p != NULL && ((Robo021ca458 *)p)->unk_b1e == self->id) {
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

void Ov014ActEx_022142fc_State0a(Ov014ActEx_022142fc *self) {
    self->vfunc_74();
}

}
