#include "ov009/ov009.h"

extern "C" {

struct Ov009Rot {
    u16 x;
    u16 y;
    u16 z;
};

extern void *data_02097e4c;
extern Ov003Actor *Actor_SpawnKind(u16 kind, const VecFx32 *pos, const void *rot, u16 id, u16 parent);
extern void *SndMgr_PlayAt(void *mgr, s32 id, const VecFx32 *pos, s32 a);
extern Ov003Actor *Actor_GetTarget(Ov003Actor *self);
extern BOOL Hit_DiffInCylinder(VecFx32 *a, VecFx32 *b, fx32 r, fx32 h);

void Ov009ActVt_02216750_StateShoot(Ov009ActVt_02216750 *self) {
    VecFx32 p;
    Ov003Actor *o;
    Ov003Actor *t;
    u16 kind = 0x483f;
    p = self->pos;
    if (self->kind == 0x5012) {
        p.y += 0xccd;
    } else {
        p.y -= 0x2800;
        kind = 0x482d;
    }
    o = Actor_SpawnKind(kind, &p, &self->rot_x, self->id, self->target);
    if (self->unk_18 == 1) {
        SndMgr_PlayAt(data_02097e4c, 0xd02, &self->pos, 0);
        t = Actor_GetTarget(self);
        if (t != NULL) {
            VecFx32 tp;
            tp = t->pos;
            if (Hit_DiffInCylinder(&p, &tp, 0x6800, 0x7000)) {
                Ov009Rot r;
                r.x = 0xf000;
                r.y = o->rot_y;
                r.z = o->rot_z;
                *(Ov009Rot *)&o->rot_x = r;
            }
        }
    }
    History_SetState(self->fsm, 1, 0);
}

extern void ActorMgr_BroadcastKind(void *mgr, u16 id, s32 msg);
extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern void NNSi_G3dModifyPolygonAttrMask(void *p, s32 a, s32 b);
extern void Field_ShakeCamera(u8 a, u8 b);
extern void *SndMgr_PlayVolume(void *mgr, s32 id, s32 a, s32 b, s32 c);
extern void *Spawn_ScatterEffect(VecFx32 *pos, VecFx32 *v, s32 a, s32 b, s32 c, s32 d);

static inline void Ov009_VecSet(VecFx32 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void Ov009_ReleaseFx(Ov009ActVt_02216750 *self) {
    u16 id;
    switch (self->kind) {
    case 0x5012:
        id = 0x5013;
        break;
    case 0x5038:
    case 0x5044:
        id = 0x5045;
        break;
    }
    ActorMgr_BroadcastKind(data_ov000_021ccd68, id, 0x15);
    ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x483f, 0x15);
    ActorMgr_BroadcastKind(data_ov000_021ccd68, 0x482d, 0x15);
}

void Ov009ActVt_02216750_StateDie(Ov009ActVt_02216750 *self) {
    ActorSub48 *s48;
    ActorSub44 *s44;
    Model0218fe1c *m;
    EffectObj *e;
    s32 spd;
    ActorSub40 *st = self->fsm;
    switch (st->st) {
    case 0:
        *self->hp = 0;
        s48 = self->hit;
        s48->unk_9a_0 = 0;
        s48->unk_9a_3 = 0;
        HitSphere_Unlink_0203f364(s48);
        s44 = self->unk_44;
        s44->unk_22_0 = 0;
        s44->unk_22_1 = 0;
        self->targetObj->target = 0xffff;
        if (data_ov000_021ccd54->unk_ca.c[0] == 0x11) {
            Ov009_VecSet((VecFx32 *)&self->speed, 0, 0, 0);
        } else {
            Ov009_VecSet((VecFx32 *)&self->speed, Rand_PlusMinus(0x29), -0x71, Rand_PlusMinus(0x29));
        }
        Ov009_ReleaseFx(self);
        m = self->model;
        m->cull = 2;
        NNSi_G3dModifyPolygonAttrMask(m->mdl, 0, 0xc0);
        self->fsm->st++;
    case 1:
        if (self->fsm->timer > 0x78) {
            Field_ShakeCamera(10, 0x28);
            SndMgr_PlayVolume(data_02097e4c, 0x56, -1, -1, -1);
            e = Effect_SpawnId(5, &self->pos);
            spd = 0x6000;
            if (self->kind != 0x5012) {
                spd = 0x4800;
            }
            e->SetScaleAll(spd);
            self->fsm->timer = 0x29;
            self->fsm->st++;
            return;
        }
        if ((self->fsm->timer & 0xf) == 0) {
            VecFx32 v;
            s32 a = -1;
            s32 b = 100;
            switch (self->fsm->timer & 0x3f) {
            case 0:
                a = 3;
                break;
            case 0x10:
                a = 3;
                b = 0x19;
                break;
            case 0x20:
                break;
            case 0x30:
                a = 3;
                b = 0x32;
                break;
            }
            v.x = 0x3000;
            v.y = 0x2800;
            v.z = 0x1800;
            Spawn_ScatterEffect(&self->pos, &v, 0xc00, 0x1400, a, b);
            Field_ShakeCamera(6, 10);
        }
        self->fsm->timer++;
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        break;
    case 2:
        if (st->timer != 0) {
            st->timer--;
        }
        if (st->timer == 0) {
            Ov009_ReleaseFx(self);
            Ov003Actor_Defeat(self, 1, 1, 1);
            return;
        }
        if ((u8)self->fsm->timer < 0x1f) {
            Ov003Actor_SetAlpha(self, self->fsm->timer);
        }
        VEC_Add(&self->pos, (VecFx32 *)&self->speed, &self->pos);
        break;
    }
}

}
