#include "ov000/VObj.h"
#include "ov000/Vec.h"

typedef struct {
    u32 flags;
    u8 unk_04[0x64];
    s32 unk_68;
    VecFx32 unk_6c;
} Obj021bd438;

extern "C" {

void func_ov000_021bd438(Obj021bd438 *self, VecFx32 *v, s32 dy) {
    if (self->unk_68 == 10) {
        return;
    }
    self->flags |= 4;
    self->unk_6c.x = v->x;
    self->unk_6c.y = v->y;
    self->unk_6c.z = v->z;
    self->unk_6c.y += dy;
}

}
