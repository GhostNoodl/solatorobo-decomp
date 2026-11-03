#include "nitro/fx.h"
#include "Main/Sys/FieldState.h"
#include "ov000/VObj.h"
#include "ov000/ObjLayouts.h"

#define SC(r) FX_SinCosTable_[((r) >> 4) * 2], FX_SinCosTable_[((r) >> 4) * 2 + 1]

extern "C" {
extern void *data_ov000_021ccd64;
extern u8 data_ov000_021cc456[];
BOOL Model0218fe1c_SetAnim(void *a, void *b, s32 c, s32 d);
void Model0218fe1c_SetLoop(void *a);
void *Ov003_FindPlayerInRange(void *a, s32 r, s32 h);
void Target_Set(void *body, void *p);
BOOL History_SetState(void *p, s32 a, s32 b);
void Group_UpdateActor(void *a, s32 b, void *c);
void HitSphere_Link(void *p);
void HitSphere_Unlink_0203f364(void *p);
void Body_Update(void *p, s32 a, s32 b, s32 c);
void HitMesh_SetMtx(void *p, MtxFx43 *m);

static inline BOOL PlayerIdle02195848(void) {
    FieldState *pl = data_ov000_021ccd54;
    if (pl != NULL) {
        if (pl->head != pl->tail ? TRUE : FALSE) {
            return FALSE;
        }
        if (pl->state != 3) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline void RotZYX02195848(MtxFx43 *m, MtxFx43 *tp, u16 rx, u16 ry, u16 rz) {
    BOOL any = FALSE;
    MTX_Identity43_(m);
    if (rz != 0) {
        MTX_RotZ43_(m, SC(rz));
        any = TRUE;
    }
    if (ry != 0) {
        if (any) {
            MTX_RotY43_(tp, SC(ry));
            MTX_Concat43(tp, m, m);
        } else {
            MTX_RotY43_(m, SC(ry));
            any = TRUE;
        }
    }
    if (rx != 0) {
        if (any) {
            MTX_RotX43_(tp, SC(rx));
            MTX_Concat43(tp, m, m);
        } else {
            MTX_RotX43_(m, SC(rx));
        }
    }
}

void ActorEx_StateIdle(VObj *obj) {
    ActorEx *self = (ActorEx *)obj;
    MtxFx43 t;
    MtxFx43 m;
    ActorSub48 *h;

    h = self->hit;
    if (h != NULL) {
        h->unk_9a_6 = 0;
    }
    switch (self->fsm->st) {
    case 0:
        if ((void *)self->model != NULL) {
            Model0218fe1c_SetAnim(((u8 *)self->model), data_ov000_021cc456, 0x1000, 0);
            Model0218fe1c_SetLoop(((u8 *)self->model));
        }
        self->fsm->st++;
        self->speed = 0;
        self->velY = 0;
        self->friction = 0;
        self->gravity = 0;
        self->unk_cc |= 2;
        break;
    case 1:
        if (self->targetObj != NULL && self->targetObj->type == 2) {
            void *r = Ov003_FindPlayerInRange((u8 *)self + 0x70, self->radius, self->height);
            if (r != NULL) {
                Target_Set(((u8 *)self->targetObj), r);
                History_SetState(((u8 *)self->fsm), 0xd, 0);
                break;
            }
        }
        if (self->unk_20 == 0xffff && self->unk_cc_4) {
            if (PlayerIdle02195848()) {
                ActorSub40 *st = self->fsm;
                st->timer++;
                if ((s32)st->timer > 0x1fe) {
                    if ((s32)st->timer > 0x258) {
                        Group_UpdateActor(data_ov000_021ccd64, 0, self);
                        obj->vfunc_08();
                        break;
                    }
                    if (self->model != NULL) {
                        if ((st->timer & 7) > 2) {
                            self->model->alpha = 10;
                        } else {
                            self->model->alpha = 0x1f;
                        }
                    }
                }
            } else if (self->model != NULL) {
                self->model->alpha = 0x1f;
            }
        }
        if ((self->msg_flags & 0x80) && (h = self->hit) != NULL) {
            h->unk_9a_0 = 1;
            h->unk_9a |= 8;
            HitSphere_Link(h);
            Body_Update(self->hit, 0, 0, 0);
        }
        break;
    }
    if (self->hitMesh != NULL && (self->unk_cc_1 || (self->msg_flags & 0x80))) {
        void *p;
        u16 rx;
        u16 ry;
        u16 rz;
        self->unk_cc_0 = 1;
        rz = self->rot_z;
        p = self->hitMesh;
        ry = self->rot_y;
        rx = self->rot_x;
        RotZYX02195848(&m, &t, rx, ry, rz);
        m._30 = self->pos.x;
        m._31 = self->pos.y;
        m._32 = self->pos.z;
        HitMesh_SetMtx(p, &m);
    }
    h = self->hit;
    if (h == NULL) {
        return;
    }
    {
        s32 k = self->param->type;
        if (k == 3) {
            return;
        }
        if (self->hitMesh != NULL && self->unk_cc_0 && k != 1) {
            h->unk_9a_3 = 0;
            HitSphere_Unlink_0203f364(h);
        }
    }
    if (!self->unk_cc_1) {
        self->hit->unk_9a_4 = 0;
        self->unk_93_0 = 1;
        return;
    }
    self->hit->unk_9a |= 0x20;
    if (!(self->hit->unk_50 & 0x20000000)) {
        if (PlayerIdle02195848()) {
            History_SetState(((u8 *)self->fsm), 4, 0);
        }
        return;
    }
    if (self->hit->unk_50 & 0x40000) {
        return;
    }
    if (!PlayerIdle02195848()) {
        return;
    }
    self->unk_cc_1 = 0;
    self->hit->unk_9a_4 = 0;
}
}
