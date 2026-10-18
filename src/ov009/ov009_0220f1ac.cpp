#include "ov009/ov009.h"

extern "C" {

extern void *data_ov000_021ccd64;
extern void func_ov000_0218bed8(void *mgr, s32 a, Ov009Actor *actor);
extern void VEC_Add(const Ov009Vec *a, const Ov009Vec *b, Ov009Vec *out);

void func_ov009_0220f1ac(Ov009Actor *self) {
    Ov009Vec d;
    Ov009Sub40 *st;
    d.x = 0x266 - self->unk_9c;
    d.y = -0x15c - self->unk_a0;
    d.z = -self->unk_a4;
    VEC_MultAdd(0x66, &d, (Ov009Vec *)&self->unk_9c, (Ov009Vec *)&self->unk_9c);
    VEC_Add(&self->pos, (Ov009Vec *)&self->unk_9c, &self->pos);
    st = self->unk_40;
    st->timer++;
    if (st->timer > 0x1e0) {
        func_ov000_0218bed8(data_ov000_021ccd64, 0, self);
        self->v08();
    }
}

extern void *data_02097e4c;
extern Ov009Actor *func_ov000_0219bf90(void);
extern BOOL func_ov000_021b4738(Ov009Actor *a);
extern void func_02049bb4(void *mgr, s32 h);

void func_ov009_0220f260(Ov009Actor *self) {
    Ov009Actor *a;
    u16 pct;
    s32 n;
    if (!Ov009_GameIdle()) {
        return;
    }
    self->unk_90 = 0xffff;
    a = func_ov000_0219bf90();
    if (a != NULL) {
        self->unk_90 = a->id;
        if (func_ov000_021b4738(a) && FLD(s32, self, 0x10c) >= 0) {
            func_02049bb4(data_02097e4c, FLD(s32, self, 0x10c));
            FLD(s32, self, 0x10c) = -1;
        }
    }
    if (self->unk_18 != 0) {
        self->unk_ea_6 = 1;
        return;
    }
    self->unk_ea_6 = 0;
    if (self->unk_40->unk_13 != 1) {
        return;
    }
    if (self->unk_b6 != 0) {
        self->unk_b6--;
    }
    self->unk_93_4 = 1;
    if (self->unk_b6 != 0) {
        return;
    }
    self->unk_40->flags |= 0x4000;
    pct = (self->unk_50[0] * 100) / self->unk_50[1];
    if (pct > 0x46) {
        n = 5;
    } else {
        n = 8;
        if (pct <= 0x28) {
            n = 10;
        }
    }
    FLD(u8, self, 0x108)++;
    if (FLD(u8, self, 0x108) == n) {
        self->unk_b6 = 200;
        FLD(u8, self, 0x108) = 0;
    } else {
        self->unk_b6 = 0x28;
    }
}

}
