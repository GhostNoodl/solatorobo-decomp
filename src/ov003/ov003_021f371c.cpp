#include "types.h"
#include "nitro/fx.h"
#include "ov003/Prop.h"

extern "C" {


typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Ov003SVec;

extern char data_ov003_021fa652[];
extern u32 data_ov003_021fa658;
extern void ResSet_SetFile(ActorRes *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern void *data_02097e4c;
extern const Ov003SVec data_ov003_021f7694[];
extern BOOL ResSet_UpdateLoad(ActorRes *p);
extern BOOL Model0218fe1c_SetRes(void *anim, ActorRes *res, s32 a, s32 b);
extern BOOL Model0218fe1c_SetAnim(void *anim, const char *name, s32 a, s32 b);
extern void Model0218fe1c_SetLoop(void *anim);
extern void Obj02190758_SetRot(void *anim, void *p, s32 a);
extern void *func_0203db40(void *p);
extern void Model0218fe1c_UpdateAnim(void *a, void *b);
extern s32 **Model0218fe1c_GetAnimCtrl(void *a, s32 b);
extern void *SndMgr_PlayAtPitch(void *mgr, s32 id, VecFx32 *pos, s32 a);
extern BOOL Model021903b4_Draw(void *anim);

BOOL Ov003ActVt_021fa5f8_IsReady(Ov003PropResMdl *self) {
    BOOL r = Actor_IsReady(self);
    if (self->kind != 0x6a01 && self->res.unk_00 >= 0) {
        if (!ResSet_UpdateLoad(&self->res)) {
            r = FALSE;
        }
    }
    return r;
}

void Ov003ActVt_021fa5f8_Start(Ov003PropResMdl *self) {
    Ov000ActVt_021cc7cc_Start(self);
    if (self->kind == 0x6a01) {
        return;
    }
    Model0218fe1c_SetRes(&self->mdl, &self->res, 0, 1);
    Model0218fe1c_SetAnim(&self->mdl, data_ov003_021fa652, 0x1000, 0);
    Model0218fe1c_SetLoop(&self->mdl);
    Obj02190758_SetRot(&self->mdl, &self->rot, 0);
}

void Ov003ActVt_021fa5f8_Animate(Ov003PropResMdl *self) {
    s32 v;
    s32 *p;
    VecFx32 pos;
    if (self->model != NULL) {
        Model0218fe1c_UpdateAnim(self->model, func_0203db40(&self->pause));
    }
    v = 0;
    p = *Model0218fe1c_GetAnimCtrl(self->model, 0);
    if (p != NULL) {
        v = *p;
    }
    if (v < 0x1000) {
        pos.x = self->pos.x;
        pos.y = self->pos.y;
        pos.z = self->pos.z + 0xc000;
        SndMgr_PlayAtPitch(data_02097e4c, 0x39, &pos, -5);
    }
    if (self->kind == 0x6a01) {
        return;
    }
    Model0218fe1c_UpdateAnim(&self->mdl, func_0203db40(&self->pause));
}

BOOL Ov003ActVt_021fa5f8_Draw(Ov003PropResMdl *self) {
    BOOL r = Actor_Draw(self);
    int i;
    if (r && self->kind != 0x6a01) {
        for (i = 0; i < 5; i++) {
            s32 y = self->pos.y + (data_ov003_021f7694[i].y << 4);
            s32 z = self->pos.z + (data_ov003_021f7694[i].z << 4);
            s32 x = self->pos.x + (data_ov003_021f7694[i].x << 4);
            self->mdl.trans.x = x;
            self->mdl.trans.y = y;
            self->mdl.trans.z = z;
            Model021903b4_Draw(&self->mdl);
        }
    }
    return r;
}

void Ov003ActVt_021fa5a0_Init(Ov003Prop021fa5a0 *self) {
    Ov000ActVt_021cc7cc_Init(self);
    ResSet_SetFile(&self->res, &data_ov003_021fa658, 1, 1, 0, 0);
    self->res.unk_00 = 0;
}

} // extern "C"
