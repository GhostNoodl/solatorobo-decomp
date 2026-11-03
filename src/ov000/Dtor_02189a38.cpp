#include "ov000/VObj.h"
#include "ov000/Vec.h"
#include "ov000/FieldCam.h"

extern "C" {

extern u8 ResHandle_vtbl[];
extern u8 StageRes_vtbl[];
void StageRes_CancelSlots(void *ptr);
Camera *Camera_CtorBase(Camera *cam);
extern u8 data_ov000_021cc3a0[];
extern const VecFx32 data_ov000_021c9d4c; // added to the look-at point when no offset is set

VObj *Ov000Vt_021cc158_Dtor(VObj *self) {
    VOBJ_SET_VTABLE(self, StageRes_vtbl);
    StageRes_CancelSlots(self);
    VOBJ_SET_VTABLE(self, ResHandle_vtbl);
    self->vfunc_0c();
    return self;
}

FieldCam *Ov000Vt_021cc3a0_Ctor(FieldCam *self) {
    VecFx32 v;
    Camera_CtorBase(&self->base);
    self->base.vtable = data_ov000_021cc3a0;
    v = self->base.at;
    VEC_Add(&v, &data_ov000_021c9d4c, &v);
    self->base.at = v;
    self->unk_bc.x = 0;
    self->unk_bc.y = 0;
    self->unk_bc.z = 0;
    self->zones = NULL;
    self->zone = NULL;
    self->zoneIdx = 0;
    self->zoneCount = 0;
    self->unk_d8 = 0;
    self->unk_da = 0;
    self->base.smooth = 0;
    return self;
}

}
