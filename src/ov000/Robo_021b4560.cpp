#include "ov000/Actor.h"


#define LFLD(type, obj, off) (*(type *)((u8 *)(obj) + (off)))

typedef struct {
    VecFx32 pos;
    u16 rot[3];
    s32 unk_1c;
} Msg021b4560;

extern "C" {
void VEC_MultAdd(s32 a, const VecFx32 *v1, const VecFx32 *v2, VecFx32 *out);
s32 func_01ffbd6c(VecFx32 *a, VecFx32 *b, u32 mask, s32 c, s32 d, s32 e);
void Actor_SendMsg(Actor *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);

void func_ov000_021b4560(Actor *self, Actor *t) {
    VecFx32 p;
    Msg021b4560 msg;

    if (t == NULL) {
        return;
    }
    if (((VecFx32 *)t->unk_48) != NULL) {
        p = *((VecFx32 *)t->unk_48);
    } else {
        p = t->pos;
    }
    if (func_01ffbd6c(&self->pos, &p, -1, 0, 0, -1) == -0x1000) {
        return;
    }
    VEC_Subtract(&p, &self->pos, &p);
    VEC_MultAdd(0xc00, &p, &self->pos, &p);
    msg.pos = p;
    msg.rot[0] = t->rot_x;
    msg.rot[1] = t->rot_y;
    msg.rot[2] = t->rot_z;
    msg.unk_1c = 0;
    Actor_SendMsg(t, self->id, 7, TRUE, 0x18, &msg);
}
}
