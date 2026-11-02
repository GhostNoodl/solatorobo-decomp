#include "types.h"
#include "nitro/fx.h"
#include "nnsys/g3d.h"
#include "ov003/Prop.h"

extern "C" {

extern char data_ov003_021fa662[];
extern char data_ov003_021fa668[];
extern BOOL func_ov000_0218f110(ActorRes *p);
extern BOOL func_ov000_0218ffdc(Model0218fe1c *anim, ActorRes *res, s32 a, s32 b);
extern BOOL func_ov000_02190cb0(void *anim, const char *name, s32 a, s32 b);
extern void func_ov000_02190758(Model0218fe1c *anim, void *p, s32 a);
extern void *func_ov000_02191318(Model0218fe1c *anim, s32 a);
extern void *func_0203db40(void *p);
extern void func_ov000_02190a80(void *a, void *b);
extern BOOL func_ov000_021903b4(Model0218fe1c *anim);
extern void func_01ffc9fc(VecFx32 *src, VecFx32 *dst, u16 angle);
extern void func_ov000_02191c24(ActorShadow *shadow, VecFx32 *pos);

BOOL Ov003ActVt_021fa5a0_IsReady(Ov003Prop021fa5a0 *self) {
    BOOL r = func_ov000_0218cf5c(self);
    if (self->res.unk_00 >= 0) {
        if (!func_ov000_0218f110(&self->res)) {
            r = FALSE;
        }
    }
    return r;
}

void Ov003ActVt_021fa5a0_Start(Ov003Prop021fa5a0 *self) {
    s32 *res;
    void *a;
    VecFx32 v;
    Ov000ActVt_021cc7cc_Start(self);
    func_ov000_02190cb0(self->model, data_ov003_021fa662, 0x1000, 0);
    func_ov000_0218ffdc(&self->mdl, &self->res, 0, 1);
    a = self->model->tex;
    NNS_G3dBindMdlSet(NNS_G3dGetMdlSet((NNSG3dResFileHeader *)(self->mdl.res->mdl_handle != NULL ? self->mdl.res->mdl_handle->unk_00 : NULL)), (NNSG3dResTex *)a);
    func_ov000_02190cb0(&self->mdl, data_ov003_021fa668, 0x1000, 0);
    func_ov000_02191318(&self->mdl, -1);
    func_ov000_02190758(&self->mdl, &self->rot, 0);
    v.x = 0x199a;
    v.y = 0;
    v.z = 0;
    func_01ffc9fc(&v, &v, self->rot_y);
    VEC_Add(&v, &self->pos, &v);
    self->mdl.trans.x = v.x;
    self->mdl.trans.y = v.y;
    self->mdl.trans.z = v.z;
    self->unk_3c->unk_14 = self->radius;
    self->unk_2d0 = 0;
}

} // extern "C"
