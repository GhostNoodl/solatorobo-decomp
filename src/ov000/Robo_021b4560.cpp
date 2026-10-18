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
void func_ov000_0218d398(Actor *self, u16 id, u8 type, BOOL notify, u32 size, const void *data);

void func_ov000_021b4560(Actor *self, Actor *t) {
    VecFx32 p;
    Msg021b4560 msg;

    if (t == NULL) {
        return;
    }
    if (LFLD(VecFx32 *, t, 0x48) != NULL) {
        p = *LFLD(VecFx32 *, t, 0x48);
    } else {
        p = LFLD(VecFx32, t, 0x70);
    }
    if (func_01ffbd6c(&LFLD(VecFx32, self, 0x70), &p, -1, 0, 0, -1) == -0x1000) {
        return;
    }
    VEC_Subtract(&p, &LFLD(VecFx32, self, 0x70), &p);
    VEC_MultAdd(0xc00, &p, &LFLD(VecFx32, self, 0x70), &p);
    msg.pos = p;
    msg.rot[0] = LFLD(u16, t, 0x7c);
    msg.rot[1] = LFLD(u16, t, 0x7e);
    msg.rot[2] = LFLD(u16, t, 0x80);
    msg.unk_1c = 0;
    func_ov000_0218d398(t, LFLD(u16, self, 0xc), 7, TRUE, 0x18, &msg);
}
}
