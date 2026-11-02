#include "ov000/VObj.h"

extern "C" {

void HitMesh_Init(void *ptr);
void HitMesh_Detach(void *ptr);

void *func_ov000_02193e34(void *self) {
    HitMesh_Init(self);
    return self;
}

void *func_ov000_02193e48(void *self) {
    HitMesh_Detach(self);
    return self;
}

}
