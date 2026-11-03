#include "ov009/ov009.h"

extern "C" {

extern char data_ov009_0221729c[];
extern char data_ov009_022172a7[];
extern BOOL Actor_IsReady(Ov003Actor *self);
extern BOOL ResSet_UpdateLoad(void *p);

static inline void Ov009Names_Set(Ov009Names *n, const char *a, const char *b) {
    STD_CopyString(n->mdlDir, a);
    STD_CopyString(n->mdlName, b);
    n->ownMdl = 1;
    STD_CopyString(n->anmDir, a);
    STD_CopyString(n->anmName, b);
    n->ownAnm = 1;
    n->unk_00 = 0;
}

BOOL Ov009ActVt_02217844_IsReady(Ov009ActVt_02217844 *self) {
    BOOL r = Actor_IsReady(self);
    if (self->anim.unk_00 >= 0 && !ResSet_UpdateLoad(&self->anim)) {
        r = FALSE;
    }
    return r;
}

extern void HitSphere_Unlink_0203f2b8(void *p);
extern void NNSi_G3dModifyPolygonAttrMask(void *p, s32 a, s32 b);
extern void NNSi_G3dModifyMatFlag(void *p, s32 a, s32 b);
extern BOOL Model0218fe1c_SetRes(void *a, void *b, s32 c, s32 d);
extern void Obj02190758_SetRot(void *a, const void *b, s32 c);
void Ov009ActVt_02217844_Start(Ov009ActVt_02217844 *self) {
    void *saved;
    Ov003Actor_Start(self);
    Model0218fe1c_SetRes(&self->modelObj, &self->anim, 0, 1);
    self->modelObj.actor_id = self->id;
    if (self->unk_1a == 0) {
        self->modelObj.trans = self->pos;
        self->modelObj.scale.x = 0xccd;
        self->modelObj.scale.y = 0xccd;
        self->modelObj.scale.z = 0xccd;
    } else {
        s32 y = self->pos.y;
        s32 x = self->pos.x;
        s32 z = self->pos.z;
        self->modelObj.trans.x = x + 0x6000;
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
    saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (self->hit != NULL) {
        ActorSub48 *p = self->hit;
        if (p != NULL) {
            HitSphere_Unlink_0203f2b8(p);
            Heap_Free(p);
        }
        self->hit = NULL;
    }
    gSysState->cur = saved;
    saved = gSysState->cur;
    gSysState->cur = gSysState->heapHi;
    if (self->unk_44 != NULL) {
        Heap_Free(self->unk_44);
        self->unk_44 = NULL;
    }
    gSysState->cur = saved;
}

}
