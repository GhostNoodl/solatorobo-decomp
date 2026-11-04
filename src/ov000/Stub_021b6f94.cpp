#include "ov000/VObj.h"
#include "Main/Gfx/PlttRes.h"
#include "ov000/FieldMgr.h"

extern "C" {

void MTX_Identity33_(MtxFx33 *mtx);

#define FREE_FIELD(f)          \
    if ((f) != 0) {            \
        Heap_FreeHi((void *)(f)); \
        (f) = 0;               \
    }

FieldPropModel *FieldPropModel_Ctor(FieldPropModel *self) {
    self->res = NULL;
    self->anm[0] = NULL;
    self->anm[1] = NULL;
    self->anm[2] = NULL;
    self->anm[3] = NULL;
    self->anm[4] = NULL;
    self->matBuf = NULL;
    self->jntBuf = NULL;
    self->rob = NULL;
    self->sub[0] = NULL;
    self->trans.x = 0;
    self->trans.y = 0;
    self->trans.z = 0;
    MTX_Identity33_(&self->rot);
    self->scale.x = 0x1000;
    self->scale.y = 0x1000;
    self->scale.z = 0x1000;
    self->speed = 0x1000;
    self->nsub = 0;
    self->cur = 0;
    self->alpha = 0x1f;
    self->flags = 0;
    return self;
}
FieldPropModel *FieldPropModel_Dtor(FieldPropModel *self) {
    FREE_FIELD(self->anm[0]);
    FREE_FIELD(self->anm[1]);
    FREE_FIELD(self->anm[2]);
    FREE_FIELD(self->anm[3]);
    FREE_FIELD(self->anm[4]);
    FREE_FIELD(self->matBuf);
    FREE_FIELD(self->jntBuf);
    FREE_FIELD(self->sub[0]);
    return self;
}

}
