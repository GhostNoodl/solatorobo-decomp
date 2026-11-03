#include "ov000/VObj.h"
#include "ov000/FieldCam.h"
#include "ov000/Vec.h"
#include "ov000/Group.h"

extern "C" {

void Obj0218c208_AddPoint(Group *self, const VecFx32 *v, u16 id) {
    if (self->viewCount >= 4) {
        return;
    }
    self->viewPos[self->viewCount] = *v;
    self->viewYaw[self->viewCount] = id;
    self->viewCount++;
}

// Registers the field camera as this frame's view.
void Group_AddCamView(Group *self) {
    FieldCam *cam = &data_ov000_021ccd54->cam;
    VecFx32 v;
    u16 id;
    if (cam == NULL) {
        return;
    }
    v = cam->base.eye;
    id = FieldCam_GetYaw(cam);
    if (self->viewCount >= 4) {
        return;
    }
    self->viewPos[self->viewCount] = v;
    self->viewYaw[self->viewCount] = id;
    self->viewCount++;
}

}
