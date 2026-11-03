#include "ov006/ov006.h"
#include "nitro/fx.h"
#include "Main/Effect/Effect.h"
#include "ov000/ObjLayouts.h"
#include "ov000/ActorMgr.h"

typedef struct ov006_Msg021ead6c {
    u16 a;
    u8 b;
    u16 c;
} ov006_Msg021ead6c;

#define SC(r) FX_SinCosTable_[((r) >> 4) * 2], FX_SinCosTable_[((r) >> 4) * 2 + 1]

extern "C" {

extern void *data_02097e4c;
extern void *data_ov000_021ccd64;
void *SndMgr_PlayAt(void *a, s32 b, VecFx32 *c, s32 d);
BOOL Hit_ApplyInArea(Actor *a, Actor *b, u16 c, u8 d, u16 mask, const VecFx32 *ofs, Rot16 *rot,
                         s32 r, s32 rr, s16 h, s32 i);
void Group_UpdateActor(void *a, s32 b, Actor *actor);
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
BOOL Hit_DiffInSphere(VecFx32 *a, VecFx32 *b, s32 r);
void Actor_SendMsg(Actor *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);

static inline Actor *GetTgt(u16 id) {
    if (data_ov000_021ccd68 == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(data_ov000_021ccd68, id);
}

static inline void RotYXZ(MtxFx33 *m, const ActorRot *rot) {
    MtxFx33 t;
    u16 rx;
    u16 ry;
    u16 rz;
    BOOL any = FALSE;
    ry = rot->y;
    rz = rot->z;
    rx = rot->x;
    MTX_Identity33_(m);
    if (ry != 0) {
        MTX_RotY33_(m, SC(ry));
        any = TRUE;
    }
    if (rx != 0) {
        if (any) {
            MTX_RotX33_(&t, SC(rx));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotX33_(m, SC(rx));
            any = TRUE;
        }
    }
    if (rz != 0) {
        if (any) {
            MTX_RotZ33_(&t, SC(rz));
            MTX_Concat33(&t, m, m);
        } else {
            MTX_RotZ33_(m, SC(rz));
        }
    }
}

#define MUL(a, b) ((s32)(((s64)(a) * (b) + 0x800) >> 12))

void Ov006ActVt_021ec67c_StateIdle(ActorEx *self) {
    VecFx32 d;
    MtxFx33 m;
    ov006_Msg021ead6c msg;
    EffectObj *p;
    BOOL done;
    Actor *tgt;
    ActorSub40 *st;
    switch (self->fsm->st) {
    case 0:
        p = Effect_SpawnId(0x324, &self->pos);
        if (p != NULL) {
            self->unk_bc = p->id;
            p->SetScaleAll(0x2000);
        }
        self->fsm->st++;
    case 1:
        st = self->fsm;
        st->timer++;
        if (st->timer < 150) {
            done = FALSE;
            if (self->target != 0xffff && (tgt = GetTgt(self->target)) != NULL) {
                d = tgt->pos;
                if (Hit_DiffInSphere(&d, &self->pos, 0x2800)) {
                    msg.b = 0x11;
                    msg.a = 1;
                    msg.c = self->id;
                    Actor_SendMsg(tgt, self->id, 9, 0, 6, &msg);
                    self->fsm->st++;
                }
                d.x -= self->pos.x;
                d.y -= self->pos.y;
                d.z -= self->pos.z;
                VEC_Normalize(&d, &d);
                self->vel.x = MUL(d.x, 0x4c00);
                self->vel.y = MUL(d.y, 0x4c00);
                self->vel.z = MUL(d.z, 0x4c00);
                self->rot_x = FX_AsinIdx(-d.y);
                self->rot_y = FX_Atan2(d.x, d.z);
                self->rot_z = 0;
                done = TRUE;
            }
            if (!done) {
                RotYXZ(&m, &self->rot);
                self->vel.x = 0;
                self->vel.y = 0;
                self->vel.z = 0x4c00;
                MTX_MultVec33(&self->vel, &m, &self->vel);
            }
            VEC_Add(&self->pos, &self->vel, &self->pos);
            self->fxOffset.x = MUL(self->vel.x, -0x266);
            self->fxOffset.y = MUL(self->vel.y, -0x266);
            self->fxOffset.z = MUL(self->vel.z, -0x266);
        } else {
            self->fsm->st++;
        }
        break;
    case 2:
        p = Effect_SpawnId(5, &self->pos);
        if (p != NULL) {
            p->SetScaleAll(0x5000);
        }
        SndMgr_PlayAt(data_02097e4c, 0x56, &self->pos, 0);
        Hit_ApplyInArea(self, self, 1, 0x11, 0x80, NULL, NULL, 0x7800, 0, -1, 0x1000);
        Group_UpdateActor(data_ov000_021ccd64, 0, self);
        self->vfunc_08();
        break;
    }
}

}
