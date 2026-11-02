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

void Ov003ActVt_021fa5a0_Animate(Ov003Prop021fa5a0 *self) {
    if (self->model != NULL) {
        func_ov000_02190a80(self->model, func_0203db40(&self->pause));
    }
    func_ov000_02190a80(&self->mdl, func_0203db40(&self->pause));
}

BOOL Ov003ActVt_021fa5a0_Draw(Ov003Prop021fa5a0 *self) {
    VecFx32 pos;
    BOOL r;
    self->unk_3c->unk_14 = self->radius << 1;
    r = func_ov000_0218cea4(self);
    func_ov000_021903b4(&self->mdl);
    pos.x = self->mdl.trans.x;
    pos.y = self->mdl.trans.y;
    pos.z = self->mdl.trans.z;
    func_ov000_02191c24(self->unk_3c, &pos);
    return r;
}

} // extern "C"
