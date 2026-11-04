#include "ov000/LoCommon.h"
#include "ov000/ActorMgr.h"
#include "ov000/MessageQueue.h"
#include "Main/Sys/FieldState.h"
#include "ov000/Vec.h"
#include "ov000/ObjLayouts.h"
#include "ov000/FieldMgr.h"
#include "ov000/ActorMarker.h"

typedef struct {
    u8 pad[0x258];
    VecFx32 camPos;
} Glb0219cbf8;

extern "C" {
extern Glb0219cbf8 NNS_G3dGlb;
void Body_SetPos(void *body, VecFx32 *pos, u32 angle);

void Robo021ca458_SetPosRot(Robo021ca458 *self, VecFx32 *pos, u16 *rot) {
    self->pos.x = pos->x;
    self->pos.y = pos->y;
    self->pos.z = pos->z;
    if (self->unk_b22_6 != 5) {
        self->unk_af0.x = pos->x;
        self->unk_af0.y = pos->y;
        self->unk_af0.z = pos->z;
    } else {
        self->unk_af0.x = self->pos.x - NNS_G3dGlb.camPos.x;
        self->unk_af0.y = self->pos.y - NNS_G3dGlb.camPos.y;
        self->unk_af0.z = self->pos.z - NNS_G3dGlb.camPos.z;
    }
    self->unk_afc.x = self->unk_af0.x;
    self->unk_afc.y = self->unk_af0.y;
    self->unk_afc.z = self->unk_af0.z;
    {
        u16 ry;
        self->rot_x = rot[0];
        self->rot_y = ry = rot[1];
        self->rot_z = rot[2];
        self->moveYaw = ry;
    }
    if (self->unk_b24_1) {
        self->unk_75c.x = self->pos.x;
        self->unk_75c.y = self->pos.y;
        self->unk_75c.z = self->pos.z;
        self->unk_76c = self->rot_x;
        self->unk_76e = self->rot_y;
        self->unk_770 = self->rot_z;
    }
    if (self->unk_5c != NULL) {
        func_ov000_021bd300(self->unk_5c);
        ActorMarker_SetPos(self->unk_5c, &self->pos, 0);
    }
    if (self->unk_9b0 != NULL) {
        func_ov000_021bd300(self->unk_9b0);
        ActorMarker_SetPos(self->unk_9b0, &self->unk_75c, 0);
    }
    Body_SetPos(&self->hit0, &self->pos, self->rot_y);
    self->hit0.unk_50 = 0;
    self->hit0.unk_54 = 0;
    self->hit0.unk_58 = 0;
    Body_SetPos(&self->hit1, &self->unk_75c, self->unk_76e);
    self->hit1.unk_50 = 0;
    self->hit1.unk_54 = 0;
    self->hit1.unk_58 = 0;
    self->vfunc_44();
    self->unk_b24_20_f = 0;
    if (gFieldMgr->curExit == 0xff) {
        self->unk_b22_13 = 1;
    }
}
}

typedef struct {
    u16 b0 : 1;
    u16 rest : 15;
} H1_0219cdb8;

extern "C" {
extern MessageQueue021cb980 *gMessageQueue;
extern void *gSndMgr;
Actor *ActorMgr_GetActor(ActorMgr *mgr, u16 id);
void Model0218fe1c_StopAnim(void *p);
void SndMgr_StopSeqArc(void *mgr, s32 id);
void func_ov000_021697dc(Lo021cb798 *self, u16 a, u16 b);
void ResSet_SetName0(void *p, s32 a, s32 b, s32 c, s32 d);
void ResSet_SetName1(void *p, s32 a, s32 b, s32 c, s32 d);
void ResSet_SetName3(void *p, s32 a, s32 b, s32 c, s32 d);
void *NNS_G3dGetMdlSet(void *file);
void NNS_G3dReleaseMdlSet(void *mdl);

static inline Actor *GetObj0219cdb8(u16 id) {
    if (gActorMgr == NULL) {
        return NULL;
    }
    return ActorMgr_GetActor(gActorMgr, id);
}

static inline void Reset0219cdb8(Robo021ca458 *self) {
    self->unk_b1c = 0xffff;
    self->unk_b1e = 0xffff;
    self->unk_b24_5 = 0;
    self->unk_b24_7 = self->unk_b24_9;
}

void Robo021ca458_Destroy(Robo021ca458 *self) {
    if (self->unk_b24_12 == 3) {
        Actor *o = GetObj0219cdb8(self->unk_b20);
        if (o != NULL) {
            o->flags_0 = 1;
        }
        self->unk_b20 = 0xffff;
        self->rot_x = 0;
        self->unk_b24_12 = 0;
    }
    if (self->unk_b24_5 != 0) {
        Actor *o = GetObj0219cdb8(self->unk_b1c);
        ActorSub4c *p = NULL;
        if (o != NULL) {
            p = o->targetObj;
        }
        if (p == NULL || p->target != self->id) {
            if (p != NULL) {
                p->target = 0xffff;
            }
            Reset0219cdb8(self);
        }
    }
    self->target = 0xffff;
    self->unk_b2f = 0;
    self->unk_b24_2 = 0;
    if (self->unk_b22_0 != 0) {
        if (self->unk_998 != NULL) {
            Model0218fe1c_StopAnim(self->unk_998);
        }
        if (self->seSlot >= 0) {
            SndMgr_StopSeqArc(gSndMgr, self->seSlot);
            self->seSlot = -1;
        }
        if (self->unk_b22_0 > 1) {
            self->unk_b22_0 = 1;
            self->rot_x = 0;
            self->rot_z = 0;
            self->unk_9a6 = 0;
            self->unk_9a8 = 0;
            self->unk_9aa = 0;
            self->unk_9a0 = 0;
            self->unk_9a2 = 0;
            self->unk_9a4 = 0;
        }
    }
    self->unk_b32 = 0;
    self->unk_bac = 0xffff;
    self->unk_93_0 = 0;
    self->unk_b36 = 0;
    self->unk_b38 = 0;
    self->unk_b2c_4 = 0;
    {
        u16 *v = ((u16 *)self->unk_54);
        v[0] = 0;
        v[1] = 0;
        v[2] = 0;
    }
    if (gSceneCmd->unk_c9 != 0) {
        u16 *w = self->hp;
        ListBuffer021cb940 *a;
        u16 v;
        w[0] = v = w[1];
        a = gMessageQueue->unk_11c;
        if (a != NULL && a->unk_58 != NULL) {
            func_ov000_021697dc(a->unk_58, v, v);
            a->unk_58->unk_0c |= 0x80;
        }
        self->hpObj->unk_0a = 0;
        Reset0219cdb8(self);
    }
    {
        ListBuffer021cb940 *a = gMessageQueue->unk_11c;
        Lo021cb798 *m = a != NULL ? a->unk_58 : NULL;
        if (m != NULL) {
            m->unk_5c = m->unk_64;
            m->unk_68 = m->unk_64;
        }
    }
    if (self->unk_b22_12) {
        FieldState *c = gSceneCmd;
        if (((u8 *)c)[0xca] != ((u8 *)c)[0xd0] || ((u8 *)c)[0xcb] != ((u8 *)c)[0xd1]) {
            s32 *t;
            void **res;
            self->unk_b22_12 = 0;
            self->mdl1.visible = 0;
            t = ((s32 *)self->unk_ba0);
            Model0218fe1c_StopAnim(&self->mdl1);
            if ((u8 *)self->unk_998 != NULL) {
                LFLD(H1_0219cdb8, self->unk_998, 0xc2).b0 = 0;
            }
            self->mdl0.visible = 0;
            res = (void **)self->mdl0.res->mdl_handle;
            NNS_G3dReleaseMdlSet(NNS_G3dGetMdlSet(res != NULL ? *res : NULL));
            ResSet_SetName0(&self->res1, t[0], t[1], 1, 1);
            ResSet_SetName1(&self->res1, t[2], t[3], 1, 1);
            ResSet_SetName3(&self->res1, t[4], t[5], 1, 1);
            if (LFLD(u8, t, 0x18) != 0) {
                ResSet_SetName1(&self->res2, t[0], t[1], 1, 1);
            }
            self->unk_b22_11 = 1;
        }
    }
    if (gFieldMgr->exit == 0xff) {
        self->unk_b22_13 = 1;
    }
}
}
