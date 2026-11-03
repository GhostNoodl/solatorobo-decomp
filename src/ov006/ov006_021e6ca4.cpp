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

BOOL Hit_PointInBox(VecFx32 *p, VecFx32 *min, VecFx32 *max);
void Obj02190758_SetRot(Model0218fe1c *a, Rot16 *b, int c);
BOOL Model021903b4_Draw(Model0218fe1c *a);

BOOL Ov006ActVt_021ec4f4_Draw(Ov006Racer *self) {
    VecFx32 d;
    BOOL ret;
    BOOL done;
    const Camera *cam;
    self->unk_19c_0 = 0;
    ret = FALSE;
    cam = &gSceneCmd->cam.base;
    {
        fx32 cx = cam->eye.x;
        fx32 cy = cam->eye.y;
        fx32 cz = cam->eye.z;
        d.x = self->pos.x - cx;
        d.y = self->pos.y - cy;
        d.z = self->pos.z - cz;
    }
    done = FALSE;
    if (Hit_PointInBox(&d, &data_ov006_021eb8ec, &data_ov006_021eb8d4) && HitMagSq(&d) <= data_ov006_021ec484[0]) {
        self->model->trans = self->pos;
        Obj02190758_SetRot(self->model, &self->rot, 1);
        ret = Model021903b4_Draw(self->model);
        if (ret) {
            self->unk_19c_0 |= 1;
        }
        done = TRUE;
    }
    if (!done && Hit_PointInBox(&d, &data_ov006_021eb8e0, &data_ov006_021eb8bc) && HitMagSq(&d) <= data_ov006_021ec484[1]) {
        self->mdl.trans = self->pos;
        Obj02190758_SetRot(&self->mdl, &self->rot, 1);
        ret = Model021903b4_Draw(&self->mdl);
        if (ret) {
            self->unk_19c_0 |= 2;
        }
    }
    if (ret && self->unk_19c_13) {
        Ov006Marker_Draw(self->marker);
    }
    return ret;
}

}
