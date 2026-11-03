#include "types.h"
#include "Main/Effect/Effect.h"
#include "ov003/Shot.h"

extern "C" {

extern Ov003ShotStep data_ov003_021f49ba[];
extern const VecFx32 data_02092a50;
extern Robo021ca458 *ActorMgr_FindPlayer(void);
extern Actor *Target_Get(ActorSub4c *t);
extern VecFx32 *Actor_GetTargetSub44(Actor *self);
extern void Vec_RotateY(VecFx32 *dst, VecFx32 *src, u16 ry);
extern void HitSphere_Link(ActorSub48 *a);
extern void Body_Update(ActorSub48 *a, s32 b, s32 c, s32 d);

#define OV003PJ_SIN(a) (FX_SinCosTable_[((a) >> 4) * 2])
#define OV003PJ_COS(a) (FX_SinCosTable_[((a) >> 4) * 2 + 1])
#define OV003PJ_MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

static inline u8 Ov003Pj_Kind(Robo021ca458 *pl) {
    if (pl->fsm != NULL) {
        return pl->fsm->current;
    }
    return 0;
}

static inline s32 Ov003Pj_Sqrt(s64 v) {
    *(vu16 *)0x40002b0 = 1;
    *(volatile s64 *)0x40002b8 = v;
    while (*(vu16 *)0x40002b0 & 0x8000) {
    }
    return *(volatile s32 *)0x40002b4;
}

static inline void Ov003Pj_Show(ActorSub48 *a) {
    a->unk_9a_0 = 1;
    a->unk_9a |= 8;
    HitSphere_Link(a);
}

static inline void Ov003Pj_SetMtx(Model0218fe1c *o, MtxFx43 *m) {
    MI_Copy36B(m, &o->rot);
    o->trans = *(VecFx32 *)m->m[3]; // the translation row, copied as one struct
}

void Ov003Shot_StateThrown(Ov003Shot *self) {
    MtxFx33 m33;
    VecFx32 d2;
    VecFx32 o;
    VecFx32 v;
    VecFx32 d;
    MtxFx43 m;
    MtxFx33 t33;
    MtxFx43 t;
    Ov003ShotDef *cfg;
    Ov003ShotStep *ent;
    BOOL changed;
    s32 spd;
    Robo021ca458 *pl;
    Actor *part;
    u16 mode;
    VecFx32 *tgt;
    pl = ActorMgr_FindPlayer();
    part = Target_Get(self->targetObj);
    switch (self->fsm->st) {
    case 0: {
        cfg = self->def;
        self->age = 0;
        self->trailTimer = 0;
        self->stepTimer = 0;
        self->step = 0;
        self->lockTimer = 0;
        self->vel.x = 0;
        self->vel.y = 0;
        self->vel.z = 0;
        mode = cfg->mode;
        tgt = Actor_GetTargetSub44(self);
        if (part->kind == 0x1000 && !self->def->noAim) {
            s32 a;
            mode = 2;
            self->steps = data_ov003_021f49ba;
            if (tgt == NULL) {
                mode = 1;
            }
            a = self->def->life;
            if (a < 0) {
                a = -a;
            }
            if (a > 0x96) {
                self->age = a - 0x96;
            }
        }
        switch (mode) {
        case 1:
            self->vel.x = OV003PJ_MUL(self->steps->speed, OV003PJ_SIN(self->rot_y));
            {
                s32 z = OV003PJ_MUL(self->steps->speed, OV003PJ_COS(self->rot_y));
                self->vel.y = 0;
                self->vel.z = z;
            }
            break;
        case 2: {
            s32 h;
            s32 dx;
            s32 dz;
            s64 sq;
            if (tgt != NULL) {
                d2 = *tgt;
            } else {
                d2 = self->unk_84;
            }
            d2.y -= self->pos.y;
            dz = self->pos.z - d2.z;
            dx = self->pos.x - d2.x;
            sq = (s64)dx * dx;
            sq += (s64)dz * dz;
            h = (Ov003Pj_Sqrt(sq << 2) + 1) >> 1;
            d2.x = OV003PJ_MUL(h, OV003PJ_SIN(self->rot_y));
            d2.z = OV003PJ_MUL(h, OV003PJ_COS(self->rot_y));
            VEC_Normalize(&d2, &d2);
            {
                s32 s = self->steps->speed;
                self->vel.x = OV003PJ_MUL(d2.x, s);
                self->vel.y = OV003PJ_MUL(d2.y, s);
                self->vel.z = OV003PJ_MUL(d2.z, s);
            }
            break;
        }
        default: {
            BOOL set;
            u16 ry;
            u16 rz;
            u16 rx;
            ry = self->rot_y;
            rz = self->rot_z;
            rx = self->rot_x;
            set = FALSE;
            MTX_Identity33_(&m33);
            if (ry != 0) {
                MTX_RotY33_(&m33, OV003PJ_SIN(ry), OV003PJ_COS(ry));
                set = TRUE;
            }
            if (rx != 0) {
                if (set) {
                    MTX_RotX33_(&t33, OV003PJ_SIN(rx), OV003PJ_COS(rx));
                    MTX_Concat33(&t33, &m33, &m33);
                } else {
                    MTX_RotX33_(&m33, OV003PJ_SIN(rx), OV003PJ_COS(rx));
                    set = TRUE;
                }
            }
            if (rz != 0) {
                if (set) {
                    MTX_RotZ33_(&t33, OV003PJ_SIN(rz), OV003PJ_COS(rz));
                    MTX_Concat33(&t33, &m33, &m33);
                } else {
                    MTX_RotZ33_(&m33, OV003PJ_SIN(rz), OV003PJ_COS(rz));
                    set = TRUE;
                }
            }
            {
                s32 sp = self->steps->speed;
                self->vel.x = 0;
                self->vel.y = 0;
                self->vel.z = sp;
            }
            MTX_MultVec33(&self->vel, &m33, &self->vel);
            break;
        }
        }
        self->curSpeed = self->steps->speed;
        if (self->def->fly.id != -1 && self->unk_bc == NULL) {
            EffectObj *e = Effect_SpawnId(self->def->fly.id, &self->pos);
            s32 s = self->def->fly.scale << 4;
            e->SetScaleXYZ(s, s, s);
            e->SetRot(&self->rot);
            self->unk_bc = e->id;
            o.x = self->def->fly.x << 4;
            o.y = self->def->fly.y << 4;
            o.z = self->def->fly.z << 4;
            if (mode == 1 || mode == 2) {
                Vec_RotateY(&self->fxOffset, &o, self->rot_y);
            } else {
                MTX_MultVec33(&o, &m33, &self->fxOffset);
            }
        }
        if (self->hit != NULL) {
            Ov003Pj_Show(self->hit);
            self->hit->unk_9a |= 0x12;
            if ((self->def->flags & 2) && tgt == NULL) {
                self->hit->unk_30 = 0xe0000000;
            }
        }
        {
            ActorSub44 *q = self->unk_44;
            if (q != NULL) {
                q->unk_22_0 = 1;
                q->unk_22 |= 2;
            }
        }
        self->fsm->st++;
    }
    case 1: {
        if (Ov003Shot_CheckHits(self)) {
            return;
        }
        cfg = self->def;
        if (cfg->trail.id != -1) {
            self->trailTimer++;
            if (self->trailTimer > cfg->trailInterval) {
                EffectObj *e;
                s32 s;
                self->trailTimer = 0;
                e = Effect_SpawnId(cfg->trail.id, &self->pos);
                cfg = self->def;
                v.x = cfg->trail.x << 4;
                v.y = cfg->trail.y << 4;
                v.z = cfg->trail.z << 4;
                Vec_RotateY(&v, &v, self->rot_y);
                e->AddPos(&v);
                s = self->def->trail.scale << 4;
                e->SetScaleXYZ(s, s, s);
                e->SetRot(&self->rot);
            }
        }
        ent = &self->steps[self->step];
        changed = FALSE;
        if (ent->dur != 0 && ent->next >= 0) {
            self->stepTimer++;
            if (self->stepTimer >= ent->dur) {
                self->stepTimer = 0;
                changed = TRUE;
                {
                    s16 n = ent->next;
                    ent = &self->steps[n];
                    self->step = n;
                }
            }
        }
        if (ent->accel != 0) {
            changed = TRUE;
            self->curSpeed += OV003PJ_MUL(ent->accel, ent->speed - self->curSpeed);
        }
        spd = self->curSpeed;
        if (self->def->slowOnLock) {
            if (pl != NULL && (pl->unk_b1e == self->id || (Ov003Pj_Kind(pl) == 0x18 && pl->target == self->id))) {
                self->lockTimer++;
                if (self->lockTimer >= 0x5a) {
                    self->lockTimer = 0x5a;
                } else {
                    spd = (s32)(((s64)spd * 0xcd + 0x800) >> 12);
                    changed = TRUE;
                }
            } else {
                self->lockTimer = 0;
            }
        }
        if (changed) {
            VEC_Normalize(&self->vel, &self->vel);
            self->vel.x = OV003PJ_MUL(self->vel.x, spd);
            self->vel.y = OV003PJ_MUL(self->vel.y, spd);
            self->vel.z = OV003PJ_MUL(self->vel.z, spd);
        }
        if (ent->homing != 0) {
            tgt = Actor_GetTargetSub44(self);
            if (tgt != NULL) {
                d = *tgt;
            } else {
                d = self->unk_84;
            }
            d.x -= self->pos.x;
            d.y -= self->pos.y;
            d.z -= self->pos.z;
            VEC_Normalize(&d, &d);
            VEC_MultSubtract(spd, &d, &self->vel, &d);
            VEC_MultAdd(ent->homing, &d, &self->vel, &self->vel);
        }
        if (self->def->viewSpace) {
            const MtxFx43 *iv;
            s32 x;
            s32 y;
            s32 z;
            VEC_Add(&self->viewPos, &self->vel, &self->viewPos);
            iv = NNS_G3dGlbGetInvV();
            y = self->viewPos.y;
            x = self->viewPos.x;
            z = self->viewPos.z;
            self->pos.x = (s32)(((s64)x * iv->a[0] + (s64)y * iv->a[3] + (s64)z * iv->a[6]) >> 12);
            self->pos.y = (s32)(((s64)x * iv->a[1] + (s64)y * iv->a[4] + (s64)z * iv->a[7]) >> 12);
            self->pos.z = (s32)(((s64)x * iv->a[2] + (s64)y * iv->a[5] + (s64)z * iv->a[8]) >> 12);
            VEC_Add(&self->pos, &data_02092a50, &self->pos);
            {
                BOOL set;
                u16 rz;
                u16 ry;
                u16 rx;
                rz = self->rot_z;
                ry = self->rot_y;
                rx = self->rot_x;
                set = FALSE;
                MTX_Identity43_(&m);
                if (rz != 0) {
                    MTX_RotZ43_(&m, OV003PJ_SIN(rz), OV003PJ_COS(rz));
                    set = TRUE;
                }
                if (ry != 0) {
                    if (set) {
                        MTX_RotY43_(&t, OV003PJ_SIN(ry), OV003PJ_COS(ry));
                        MTX_Concat43(&t, &m, &m);
                    } else {
                        MTX_RotY43_(&m, OV003PJ_SIN(ry), OV003PJ_COS(ry));
                        set = TRUE;
                    }
                }
                if (rx != 0) {
                    if (set) {
                        MTX_RotX43_(&t, OV003PJ_SIN(rx), OV003PJ_COS(rx));
                        MTX_Concat43(&t, &m, &m);
                    } else {
                        MTX_RotX43_(&m, OV003PJ_SIN(rx), OV003PJ_COS(rx));
                        set = TRUE;
                    }
                }
            }
            MTX_Concat43(&m, NNS_G3dGlbGetInvV(), &m);
            *(VecFx32 *)m.m[3] = self->pos; // translation row, one struct copy
            Ov003Pj_SetMtx(self->model, &m);
            self->unk_93_0 = 1;
        } else {
            VEC_Add(&self->pos, &self->vel, &self->pos);
        }
        if (self->hit == NULL) {
            return;
        }
        if (!(self->param->type & 2)) {
            Ov003Pj_Show(self->hit);
        }
        Body_Update(self->hit, 0, 0, 0);
        break;
    }
    }
}

}
