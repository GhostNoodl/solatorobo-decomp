#include "ov000/VObj.h"
#include "ov000/Vec.h"

typedef struct {
    u8 unk_00[0xd];
    u8 count;
    u8 unk_0e[2];
    VecFx32 vecs[4];
    u16 ids[4];
} Obj0218c208;

extern "C" {

void func_ov000_0218c208(Obj0218c208 *self, const VecFx32 *v, u16 id) {
    if (self->count >= 4) {
        return;
    }
    self->vecs[self->count] = *v;
    self->ids[self->count] = id;
    self->count++;
}

extern u8 *data_ov000_021ccd54;
u16 func_0204bfa8(void *cam);

static inline u16 CamYaw0218c25c(u8 *cam) {
    if (*(u16 *)(cam + 0x40) != 0) {
        return *(u16 *)(cam + 0x44);
    }
    return func_0204bfa8(cam);
}

void func_ov000_0218c25c(Obj0218c208 *self) {
    u8 *cam = data_ov000_021ccd54 + 0xf4;
    VecFx32 v;
    u16 id;
    if (cam == NULL) {
        return;
    }
    v = *(VecFx32 *)(cam + 4);
    id = CamYaw0218c25c(cam);
    if (self->count >= 4) {
        return;
    }
    self->vecs[self->count] = v;
    self->ids[self->count] = id;
    self->count++;
}

}
