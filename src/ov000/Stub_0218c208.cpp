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

}
