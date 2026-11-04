#include "nitro/fx.h"
#include "ov000/ActorMgr.h"
#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"
#include "ov000/ActorMarker.h"

#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))
#define SC(r) FX_SinCosTable_[((r) >> 4) * 2], FX_SinCosTable_[((r) >> 4) * 2 + 1]

extern "C" {
Actor *Obj021984c8_GetActor(ActorSub44 *hit);
void Geom_AddRotatedOffset(VecFx32 *pos, const VecFx32 *ofs, s32 angle);
BOOL func_ov000_0219b3b4(void *p);
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);

static inline void RotYXZ_021b3738(MtxFx33 *m, const ActorRot *rot) {
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

static inline s32 State_021b3738(Actor *a) {
    ActorSub40 *s = a->fsm;
    return s != NULL ? s->current : 0;
}

static inline BOOL Shown_021b3738(ActorMarker *p) {
    return p->show == 1 ? TRUE : FALSE;
}

static inline BOOL IsShown_021b3738(ActorMarker *p) {
    return Shown_021b3738(p) ? TRUE : FALSE;
}

void Robo021ca458_UpdateTargetMarker(Robo021ca458 *self, ActorSub44 *hit) {
    VecFx32 pos;
    VecFx32 ofs;
    MtxFx33 m;
    s32 r;
    if (hit != NULL && (self->fsm->current != 0x18 || self->unk_b1e == 0xffff)) {
        Actor *a = Obj021984c8_GetActor(hit);
        BOOL flag;
        ActorSub4c *e;
        pos = hit->pos;
        if (hit->unk_22_4) {
            ofs.z = hit->unk_1c;
            ofs.x = 0;
            ofs.y = 0;
            Geom_AddRotatedOffset(&pos, &ofs, a->rot_y);
        }
        r = hit->unk_0c.y;
        if (r == 0) {
            r = hit->unk_1c;
        }
        r += 0x400;
        if (State_021b3738(a) == 0x13 || State_021b3738(a) == 0x14 || a->unk_94_0) {
            r >>= 2;
        }
        e = a->targetObj;
        flag = TRUE;
        if (e != NULL) {
            u8 k = e->type;
            if ((u8)(k + 0xfa) <= 5) {
                flag = FALSE;
            } else if (!self->unk_b24_1) {
                if (k == 2 || k == 3 || k == 4 || k == 5 || ((u8)(k + 0xf2) <= 1 && e->unk_02 == 1) || func_ov000_0219b3b4(e) || (u16)(a->kind & 0xf000) == 0x5000) {
                    flag = FALSE;
                }
            }
        }
        ActorMarker_SetKind(self->unk_5c, 0);
        if (self->unk_5c->kind == 0) {
            LFLD(s32, self->unk_5c, 0x98) = flag;
        } else {
            self->unk_5c->unk_28[0] = flag;
        }
        self->unk_5c->show = 1;
    } else if (self->unk_b24_12 == 3) {
        u16 id = self->unk_b20;
        Actor *o = gActorMgr == NULL ? NULL : ActorMgr_GetActor(gActorMgr, id);
        if (o == NULL) {
            goto end;
        }
        if (o->targetObj->unk_1e == 0) {
            ActorMarker_SetKind(self->unk_5c, 5);
            pos = self->pos;
            r = self->height;
        } else {
            s32 h = o->unk_1e;
            s32 d = 0x14000;
            if (h != 0) {
                d = h << 4;
            }
            r = 0;
            RotYXZ_021b3738(&m, &self->rot);
            pos.x = 0;
            pos.y = 0x1000;
            pos.z = d;
            MTX_MultVec33(&pos, &m, &pos);
            VEC_Add(&pos, &self->pos, &pos);
            ActorMarker_SetKind(self->unk_5c, 2);
        }
        self->unk_5c->show = 1;
    } else {
        pos = self->pos;
        r = self->centerY;
        self->unk_5c->show = 0;
        ActorMarker_SetPos(self->unk_5c, &self->pos, 0);
    }
end:
    self->unk_5c->height = r;
    self->unk_5c->unk_50 = pos;
    ActorMarker_Update(self->unk_5c);
    if (self->unk_b24_4 && !IsShown_021b3738(self->unk_5c) && (gActorMgr->frame & 0x3f) < 0x2c) {
        self->unk_9b0->show = 1;
    } else {
        self->unk_9b0->show = 0;
    }
    self->unk_9b0->unk_50 = self->unk_75c;
    ActorMarker_Update(self->unk_9b0);
}
}
