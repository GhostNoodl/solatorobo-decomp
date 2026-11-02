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
extern void func_ov000_0218f074(ActorRes *p, void *res, s32 a, s32 b, s32 c, s32 d);
extern void *data_02097e4c;
extern const Ov003SVec data_ov003_021f7694[];
extern BOOL func_ov000_0218f110(ActorRes *p);
extern BOOL func_ov000_0218ffdc(void *anim, ActorRes *res, s32 a, s32 b);
extern BOOL func_ov000_02190cb0(void *anim, const char *name, s32 a, s32 b);
extern void func_ov000_021915a0(void *anim);
extern void func_ov000_02190758(void *anim, void *p, s32 a);
extern void *func_0203db40(void *p);
extern void func_ov000_02190a80(void *a, void *b);
extern s32 **func_ov000_02190a30(void *a, s32 b);
extern void *func_0204a028(void *mgr, s32 id, VecFx32 *pos, s32 a);
extern BOOL func_ov000_021903b4(void *anim);

BOOL Ov003ActVt_021fa5f8_IsReady(Ov003PropResMdl *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (self->kind != 0x6a01 && self->res.unk_00 >= 0) {
        if (!func_ov000_0218f110(&self->res)) {
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
    func_ov000_0218ffdc(&self->mdl, &self->res, 0, 1);
    func_ov000_02190cb0(&self->mdl, data_ov003_021fa652, 0x1000, 0);
    func_ov000_021915a0(&self->mdl);
    func_ov000_02190758(&self->mdl, &self->rot, 0);
}

void func_ov003_021f37d0(Ov003PropResMdl *self) {
    s32 v;
    s32 *p;
    VecFx32 pos;
    if (self->model != NULL) {
        func_ov000_02190a80(self->model, func_0203db40(&self->pause));
    }
    v = 0;
    p = *func_ov000_02190a30(self->model, 0);
    if (p != NULL) {
        v = *p;
    }
    if (v < 0x1000) {
        pos.x = self->pos.x;
        pos.y = self->pos.y;
        pos.z = self->pos.z + 0xc000;
        func_0204a028(data_02097e4c, 0x39, &pos, -5);
    }
    if (self->kind == 0x6a01) {
        return;
    }
    func_ov000_02190a80(&self->mdl, func_0203db40(&self->pause));
}

BOOL Ov003ActVt_021fa5f8_Draw(Ov003PropResMdl *self) {
    BOOL r = func_ov000_0218cea4(self);
    int i;
    if (r && self->kind != 0x6a01) {
        for (i = 0; i < 5; i++) {
            s32 y = self->pos.y + (data_ov003_021f7694[i].y << 4);
            s32 z = self->pos.z + (data_ov003_021f7694[i].z << 4);
            s32 x = self->pos.x + (data_ov003_021f7694[i].x << 4);
            self->mdl.trans.x = x;
            self->mdl.trans.y = y;
            self->mdl.trans.z = z;
            func_ov000_021903b4(&self->mdl);
        }
    }
    return r;
}

void Ov003ActVt_021fa5a0_Init(Ov003Prop021fa5a0 *self) {
    func_ov000_021b4adc(self);
    func_ov000_0218f074(&self->res, &data_ov003_021fa658, 1, 1, 0, 0);
    self->res.unk_00 = 0;
}

} // extern "C"
