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

void Ov003ActVt_021fa5a0_Animate(Ov003Prop021fa5a0 *self) {
    if (self->model != NULL) {
        Model0218fe1c_UpdateAnim(self->model, func_0203db40(&self->pause));
    }
    Model0218fe1c_UpdateAnim(&self->mdl, func_0203db40(&self->pause));
}

BOOL Ov003ActVt_021fa5a0_Draw(Ov003Prop021fa5a0 *self) {
    VecFx32 pos;
    BOOL r;
    self->unk_3c->unk_14 = self->radius << 1;
    r = Actor_Draw(self);
    Model021903b4_Draw(&self->mdl);
    pos.x = self->mdl.trans.x;
    pos.y = self->mdl.trans.y;
    pos.z = self->mdl.trans.z;
    Shadow_Draw(self->unk_3c, &pos);
    return r;
}

} // extern "C"
