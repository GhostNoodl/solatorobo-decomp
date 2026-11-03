#include "ov006/ov006.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"

extern "C" {

BOOL Hit_DiffInSphere(VecFx32 *a, VecFx32 *b, s32 r);
void Obj02190758_SetRot(Model0218fe1c *a, Rot16 *b, int c);
int Model021903b4_Draw(Model0218fe1c *a);

int Ov006ActVt_021ec5e4_Draw(ActorEx *self) {
    Model0218fe1c *m = self->model;
    VecFx32 target;
    int r;
    target.x = gSceneCmd->cam.base.eye.x;
    target.y = gSceneCmd->cam.base.eye.y;
    target.z = gSceneCmd->cam.base.eye.z;
    r = 0;
    if (Hit_DiffInSphere(&self->pos, &target, 0x190000)) {
        m->trans = self->pos;
        Obj02190758_SetRot(m, &self->rot, 1);
        r = Model021903b4_Draw(m);
    }
    return r;
}

}
