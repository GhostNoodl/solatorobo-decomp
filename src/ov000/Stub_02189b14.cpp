#include "ov000/VObj.h"

extern "C" {

void Camera_DtorBase(void *ptr);
void Heap_Free(void *ptr);

void *FieldCam_Dtor(void *self) {
    Camera_DtorBase(self);
    return self;
}

void *FieldCam_DtorDelete(void *self) {
    Camera_DtorBase(self);
    Heap_Free(self);
    return self;
}

}
