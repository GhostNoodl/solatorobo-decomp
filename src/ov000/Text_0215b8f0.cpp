#include "ov000/LoCommon.h"
#include "ov000/Vec.h"

typedef struct {
    u32 lo : 13;
    u32 alpha : 8;
    u32 hi : 11;
} Flags0215b8f0;

extern "C" {
extern u8 *data_02097d48;
s32 func_02043d48(void *p);
void func_ov000_02153c48(void *node, void *a, s32 b, s32 c, s32 d);

void func_ov000_0215b8f0(VObj *self, s32 unused, VecFx32 *pos) {
    u8 *g;
    u8 *node;
    s32 i;
    s32 a;
    s32 x0;
    s32 y0;
    s32 lh;
    g = data_02097d48;
    node = LFLD(u8 *, self, 0x94);
    i = 0;
    lh = self->vfunc_40();
    a = func_02043d48(g + 0x8b0);
    x0 = self->vfunc_30() + (LFLD(s32, self, 0x24) >> 1);
    y0 = self->vfunc_34();
    if (node == NULL) {
        return;
    }
    do {
        VObj *o;
        if (LFLD(VObj *, node, 0x1c) == NULL) {
            func_ov000_02153c48(node, LFLD(void *, self, 0x1c), 0, 0, 0);
        }
        LFLD(VObj *, node, 0x1c)->vfunc_14();
        LFLD(s32, LFLD(VObj *, node, 0x1c), 0x70) = LFLD(s16, self, 0x68) - 0x100;
        LFLD(u32, LFLD(VObj *, node, 0x1c), 0x4) |= 0x200000;
        LFLD(Flags0215b8f0, LFLD(VObj *, node, 0x1c), 0x4).alpha = (u8)a;
        o = LFLD(VObj *, node, 0x1c);
        o->vfunc_20(x0 + (pos->x >> 12) - (LFLD(s32, o, 0x44) >> 1), y0 + (pos->y >> 12) + lh * i);
        LFLD(VObj *, node, 0x1c)->vfunc_90();
        node = LFLD(u8 *, node, 0x2c);
        i++;
    } while (node != NULL);
}
}
