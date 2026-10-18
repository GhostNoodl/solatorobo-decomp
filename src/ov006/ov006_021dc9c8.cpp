#include "ov006/ov006.h"
#include "nitro/fx.h"

typedef struct ov006_Unk021dc9c8 {
    void *vtbl;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 6;
    u8 unk5[3];
    VecFx32 target;
    VecFx32 cur;
    u8 unk20[0xc];
    void *unk2C;
} ov006_Unk021dc9c8;

extern "C" {

BOOL func_02054f10(void *a, int b);

void func_ov006_021dc9c8(ov006_Unk021dc9c8 *self) {
    VecFx32 d;
    if (!self->b0) {
        if (self->unk2C == NULL) {
            return;
        }
        if (!func_02054f10(self->unk2C, 0xffff)) {
            return;
        }
        self->b0 = 1;
    }
    if (self->b1) {
        d.x = self->target.x - self->cur.x;
        d.y = self->target.y - self->cur.y;
        d.z = self->target.z - self->cur.z;
        VEC_MultAdd(0x466, &d, &self->cur, &self->cur);
    } else {
        self->cur.x = self->target.x;
        self->cur.y = self->target.y;
        self->cur.z = self->target.z;
    }
}

}
