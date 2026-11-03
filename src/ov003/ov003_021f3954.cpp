#include "types.h"
#include "nitro/fx.h"
#include "nnsys/g3d.h"
#include "ov003/Prop.h"

extern "C" {

extern char data_ov003_021fa662[];
extern char data_ov003_021fa668[];
extern BOOL ResSet_UpdateLoad(ActorRes *p);
extern BOOL Model0218fe1c_SetRes(Model0218fe1c *anim, ActorRes *res, s32 a, s32 b);
extern BOOL Model0218fe1c_SetAnim(void *anim, const char *name, s32 a, s32 b);
extern void Obj02190758_SetRot(Model0218fe1c *anim, void *p, s32 a);
extern void *Model0218fe1c_SetAnimFrame(Model0218fe1c *anim, s32 a);
extern void *func_0203db40(void *p);
extern void Model0218fe1c_UpdateAnim(void *a, void *b);
extern BOOL Model021903b4_Draw(Model0218fe1c *anim);
extern void Vec_RotateY(VecFx32 *src, VecFx32 *dst, u16 angle);
extern void Shadow_Draw(ActorShadow *shadow, VecFx32 *pos);

BOOL Ov003ActVt_021fa5a0_IsReady(Ov003Prop021fa5a0 *self) {
    BOOL r = Actor_IsReady(self);
    if (self->res.unk_00 >= 0) {
        if (!ResSet_UpdateLoad(&self->res)) {
            r = FALSE;
        }
    }
    return r;
}

void Ov003ActVt_021fa5a0_Start(Ov003Prop021fa5a0 *self) {
    void *a;
    VecFx32 v;
    Ov000ActVt_021cc7cc_Start(self);
    Model0218fe1c_SetAnim(self->model, data_ov003_021fa662, 0x1000, 0);
    Model0218fe1c_SetRes(&self->mdl, &self->res, 0, 1);
    a = self->model->tex;
    NNS_G3dBindMdlSet(NNS_G3dGetMdlSet((NNSG3dResFileHeader *)(self->mdl.res->mdl_handle != NULL ? self->mdl.res->mdl_handle->unk_00 : NULL)), (NNSG3dResTex *)a);
    Model0218fe1c_SetAnim(&self->mdl, data_ov003_021fa668, 0x1000, 0);
    Model0218fe1c_SetAnimFrame(&self->mdl, -1);
    Obj02190758_SetRot(&self->mdl, &self->rot, 0);
    v.x = 0x199a;
    v.y = 0;
    v.z = 0;
    Vec_RotateY(&v, &v, self->rot_y);
    VEC_Add(&v, &self->pos, &v);
    self->mdl.trans.x = v.x;
    self->mdl.trans.y = v.y;
    self->mdl.trans.z = v.z;
    self->unk_3c->unk_14 = self->radius;
    self->unk_2d0 = 0;
}

} // extern "C"
