#include "ov000/VObj.h"
#include "ov000/Vec.h"

typedef struct {
    u8 unk_00[0x70];
    VecFx32 pos;
} Obj0219bf90;

typedef struct {
    u8 unk_00[0x4];
    s32 unk_04;
    u8 unk_08;
    s32 unk_0c;
    u8 unk_10[0x4];
    VecFx32 pos;
} Obj021bb2b0;

extern "C" {

Obj0219bf90 *func_ov000_0219bf90(void);

void func_ov000_021bb2b0(Obj021bb2b0 *self, s32 a, s16 *v, u8 c) {
    self->unk_04 = 4;
    self->unk_0c = a;
    self->unk_08 = c;
    if (v == NULL) {
        Obj0219bf90 *p = func_ov000_0219bf90();
        if (p != NULL) {
            self->pos.x = p->pos.x;
            self->pos.y = p->pos.y;
            self->pos.z = p->pos.z;
        }
        if (a == 0x2717) {
            self->pos.y += 0x8000;
        }
        return;
    }
    self->pos.x = v[0] << 4;
    self->pos.y = v[1] << 4;
    self->pos.z = v[2] << 4;
}

}
