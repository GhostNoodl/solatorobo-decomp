#include "ov009/ov009.h"

extern "C" {

extern BOOL Actor_IsReady(Ov003Actor *self);
extern BOOL ResSet_UpdateLoad(void *p);

BOOL Ov009ActVt_02217594_IsReady(Ov009ActVt_02217594 *self) {
    BOOL r = Actor_IsReady(self);
    if (self->anim.unk_00 >= 0 && !ResSet_UpdateLoad(&self->anim)) {
        r = FALSE;
    }
    return r;
}

extern void HitSphere_Unlink_0203f364(ActorSub48 *p);
extern void NNSi_G3dModifyPolygonAttrMask(void *p, s32 a, s32 b);
extern void NNSi_G3dModifyMatFlag(void *p, s32 a, s32 b);
extern BOOL Model0218fe1c_SetRes(void *a, void *b, s32 c, s32 d);
extern void Obj02190758_SetRot(void *a, const void *b, s32 c);
extern Ov003Actor *ActorMgr_FindPlayer(void);
void Ov009ActVt_02217594_Start(Ov009ActVt_02217594 *self) {
    void *saved;
    ActorSub48 *s48;
    ActorSub44 *s44;
    Ov003Actor *t;
    Ov003Actor_Start(self);
    Model0218fe1c_SetRes(&self->modelObj, &self->anim, 0, 1);
    self->modelObj.actor_id = self->id;
    switch (self->unk_1a) {
    case 0:
    case 1: {
        s32 y = self->pos.y;
        s32 x = self->pos.x;
        s32 z = self->pos.z;
        if (self->unk_1a == 0) {
            x += 0x6000;
        } else {
            x -= 0x6000;
            self->rot_y = 0x8000;
        }
        self->modelObj.trans.x = x;
        self->modelObj.trans.y = y - 0x800;
        self->modelObj.trans.z = z;
        self->modelObj.scale.x = 0x99a;
        self->modelObj.scale.y = 0x99a;
        self->modelObj.scale.z = 0x99a;
        {
            VecFx32 *s = &self->model->scale;
            s->x = 0xccd;
            s->y = 0xccd;
            s->z = 0xccd;
        }
        break;
    }
    case 2:
        self->hit->offset.y = 0x5000;
        self->unk_44->unk_0c.y = 0x5000;
        break;
    }
    Obj02190758_SetRot(&self->modelObj, &self->rot_x, 0);
    NNSi_G3dModifyPolygonAttrMask(self->modelObj.mdl, 1, 0x3f000000);
    NNSi_G3dModifyMatFlag(self->modelObj.mdl, 1, 0x40);
    NNSi_G3dModifyMatFlag(self->modelObj.mdl, 1, 0x80);
    NNSi_G3dModifyMatFlag(self->modelObj.mdl, 1, 0x200);
    NNSi_G3dModifyMatFlag(self->modelObj.mdl, 1, 0x400);
    self->modelObj.unk_c2 |= 0x80;
    NNSi_G3dModifyPolygonAttrMask(self->modelObj.mdl, 1, 0x1f0000);
    saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (self->unk_3c != NULL) {
        if (self->unk_3c != NULL) {
            self->unk_3c->vfunc_04();
        }
        self->unk_3c = NULL;
    }
    gSysState->cur = saved;
    s48 = self->hit;
    s48->unk_9a_0 = 0;
    s48->unk_9a_3 = 0;
    HitSphere_Unlink_0203f364(s48);
    s48 = self->hit;
    s48->unk_9a_1 = 0;
    s48->unk_9a_4 = 0;
    s48 = self->hit;
    s48->unk_9a_2 = 0;
    s48->unk_9a_5 = 0;
    s44 = self->unk_44;
    s44->unk_22_0 = 0;
    s44->unk_22_1 = 0;
    self->unk_44->unk_22_2 = 2;
    self->target = 0xffff;
    t = ActorMgr_FindPlayer();
    if (t != NULL) {
        self->target = t->id;
    }
    self->step = 0;
    self->unk_314 = 0;
}

}
