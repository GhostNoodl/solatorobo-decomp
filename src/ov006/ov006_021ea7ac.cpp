#include "ov006/SlotManager.h"
#include "Main/Sys/FieldState.h"
#include "ov000/ObjLayouts.h"

extern "C" {

BOOL Hit_DiffInSphere(VecFx32 *a, VecFx32 *b, s32 r);
void func_ov000_02190758(Model0218fe1c *a, Rot16 *b, int c);
int func_ov000_021903b4(Model0218fe1c *a);

int Ov006ActVt_021ec7ac_Draw(ActorEx *self) {
    Model0218fe1c *m;
    VecFx32 target;
    int r = 0;
    if (data_ov006_021ec884->unk13D == 0) {
        m = self->model;
        target.x = data_ov000_021ccd54->cam.base.eye.x;
        target.y = data_ov000_021ccd54->cam.base.eye.y;
        target.z = data_ov000_021ccd54->cam.base.eye.z;
        if (Hit_DiffInSphere(&self->unk_84, &target, 0x190000)) {
            m->trans = self->unk_84;
            func_ov000_02190758(m, &self->rot, 1);
            r = func_ov000_021903b4(m);
        }
    }
    return r;
}

}
