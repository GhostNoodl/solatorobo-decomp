#include "ov006/Tasks.h"
#include "Main/Math/MathItcm.h"
#include "Main/Sys/FieldState.h"
#include "ov006/Racer.h"


extern "C" {

extern VecFx32 data_ov006_021eb8ec;
extern VecFx32 data_ov006_021eb8d4;
extern VecFx32 data_ov006_021eb8e0;
extern VecFx32 data_ov006_021eb8bc;
extern fx32 data_ov006_021ec484[2];

BOOL func_01ffc23c(VecFx32 *p, VecFx32 *min, VecFx32 *max);
void func_ov000_02190758(Model0218fe1c *a, Rot16 *b, int c);
BOOL func_ov000_021903b4(Model0218fe1c *a);

BOOL Ov006ActVt_021ec4f4_Draw(Ov006Racer *self) {
    VecFx32 d;
    BOOL ret;
    BOOL done;
    const Camera *cam;
    self->unk_19c_0 = 0;
    ret = FALSE;
    cam = &data_ov000_021ccd54->cam.base;
    {
        fx32 cx = cam->eye.x;
        fx32 cy = cam->eye.y;
        fx32 cz = cam->eye.z;
        d.x = self->pos.x - cx;
        d.y = self->pos.y - cy;
        d.z = self->pos.z - cz;
    }
    done = FALSE;
    if (func_01ffc23c(&d, &data_ov006_021eb8ec, &data_ov006_021eb8d4) && HitMagSq(&d) <= data_ov006_021ec484[0]) {
        self->model->trans = self->pos;
        func_ov000_02190758(self->model, &self->rot, 1);
        ret = func_ov000_021903b4(self->model);
        if (ret) {
            self->unk_19c_0 |= 1;
        }
        done = TRUE;
    }
    if (!done && func_01ffc23c(&d, &data_ov006_021eb8e0, &data_ov006_021eb8bc) && HitMagSq(&d) <= data_ov006_021ec484[1]) {
        self->mdl.trans = self->pos;
        func_ov000_02190758(&self->mdl, &self->rot, 1);
        ret = func_ov000_021903b4(&self->mdl);
        if (ret) {
            self->unk_19c_0 |= 2;
        }
    }
    if (ret && self->unk_19c_13) {
        func_ov006_021dca94(self->marker);
    }
    return ret;
}

}
