#include "ov000/VObj.h"
extern "C" {
#include "types.h"

typedef struct Ov003BmVec { s32 x, y, z; } Ov003BmVec;
typedef struct Ov003Bomb {
    void *vt;
    u8 unk_04[0xa];
    u16 unk_0e;
    u8 unk_10[0x30];
    u16 *work;
    u8 unk_44[0x2c];
    Ov003BmVec pos;
} Ov003Bomb;

VObj *func_ov000_0219b71c(Ov003BmVec *pos, Ov003BmVec *sc, s32 a, s32 b, s32 c, s32 d);
s32 func_02040498(s32 max);

/* Bomb fuse tick: every 128 frames spawn a spark and give it a random spin.
   The 0x325 argument is a variable with a second, never-taken definition so it
   is coloured after the scale vector constants (see docs/MATCHING.md, ovhi20). */
void func_ov003_021de6b4(Ov003Bomb *self) {
    Ov003BmVec sc;
    VObj *e;
    u16 *w;
    s32 kind;
    if (self->unk_0e != 0x4032) {
        return;
    }
    w = self->work;
    w[1]++;
    if ((w[1] & 0x7f) != 0) {
        return;
    }
    kind = 0x325;
    if ((u32)self & 3) {
        kind = 0x325;
    }
    sc.x = 0x5000;
    sc.y = 0x3000;
    sc.z = 0x3800;
    e = func_ov000_0219b71c(&self->pos, &sc, 0x1800, 0x2000, kind, 100);
    if (e == NULL) {
        return;
    }
    e->vfunc_34((u16)(0xb800 - func_02040498(0x400)), 0, 0);
}

}
